#include "library.h"
#include "string_tools.h"

#define NUM_CHARS 256
#define BUFFER_LENGTH 200
#define SIZE_INDEX_TABLE 100

Artist *artist_directory[NUM_CHARS];
SNode index_directory[SIZE_INDEX_TABLE];

int num_index = 0;

void insert_node(Artist *ptr_artist, SNode *ptr_snode);
void print_artist(Artist *p);
void print_song(Song *ptr_song);
Artist *find_artist(char *name);
SNode *find_snode(Artist *ptr_artist, char *title);



void initialize() // 아티스트 배열 초기화 함수
{
    for ( int i = 0; i < NUM_CHARS; i++)
        artist_directory[i] = NULL;

    for ( int i = 0; i < SIZE_INDEX_TABLE; i++)
        index_directory[i] = NULL;
}

void load(FILE *fp)
{
    char buffer[BUFFER_LENGTH];
    char *name, *title, *path;

    while(1)
    {
        if (read_line(fp, buffer, BUFFER_LENGTH) <= 0) // 데이터 파일의 끝에 도달
            break;
        
        name = strtok(buffer, "#");
        if (strcmp(name, " ") == 0)
            name == NULL;
        else
            name = strdup(name);
        
        title = strtok(NULL, "#");
        if (strcmp(title, " ") == 0)
            title == NULL;
        else
            title = strdup(title);
        
        path = strtok(NULL, "#");
        if (strcmp(path, " ") == 0)
            path == NULL;
        else
            path = strdup(path);
    }
}

void search_song(char *artist, char *title)
{
    Artist *ptr_artist = find_artist(artist);
    if ( ptr_artist == NULL )
    {
        printf("No such artist exists.\n");
        return;
    }

    SNode *ptr_snode = find_snode(ptr_artist, title);

    if ( ptr_snode != NULL )
    {
        printf("Found:\n");
        print_song(ptr_snode->song);
    }
    else
    {
        printf("No such song exists.\n");
        return;
    }
}

void search_song(char *artist)
{
    Artist *ptr_artist = find_artist(artist);
    if ( ptr_artist == NULL )
    {
        printf("No such artist exists.\n");
        return;
    }
    
    printf("Found:\n");
    print_artist(ptr_artist);
}

SNode *find_snode(Artist *ptr_artist, char *title)
{
    SNode *ptr_snode = ptr_artist->head;
    while (ptr_snode != NULL && strcmp(ptr_snode->song->title, title) < 0)
        ptr_snode = ptr_snode->next;

    if (ptr_snode != NULL && strcmp(ptr_snode->song->title, title) == 0) // 노래 제목이 같은 곡을 찾았을 때
        return ptr_snode;  
    else // 제목이 같은 노래를 찾지 못했을 때
        return NULL;
}

Song *create_song_instance(Artist *ptr_artist, char *title, char *path)
{
    Song *ptr_song = (Song *)malloc(sizeof(Song));
    ptr_song->artist = ptr_artist;
    ptr_song->title = title;
    ptr_song->path = path;
    ptr_song->index = num_index;
    num_index++;

    return ptr_song;
}

void add_song(char *artist,char *title, char *path)
{
    // find if the artist already exists
    // return NULL if not
    Artist *ptr_artist = find_artist(artist);
    if ( ptr_artist == NULL ) 
        ptr_artist = add_artist(artist);
    
    // add the song to the artist pointed by ptr_artist
    Song *ptr_song = create_song_instance(ptr_artist, title, path);
    SNode *ptr_snode = (SNode *)malloc(sizeof(SNode));
    ptr_snode->song = ptr_song;
    ptr_snode->next = NULL;
    ptr_snode->prev = NULL;

    //insert node
    insert_node(ptr_artist, ptr_snode);
    insert_to_index_directory(ptr_song);
}

void insert_node(Artist *ptr_artist, SNode *ptr_snode)
{
    SNode *p = ptr_artist->head;
    while ( p != NULL && strcmp(p->song->title, ptr_snode->song->title) != 0 )
        p = p->next;

    // add ptr_snode before p
    // 1.empty  2.at the front  3.at the end  4.in the middle
    if ( ptr_artist->head == NULL ) // empty
    {   
        ptr_artist->head = ptr_snode;
        ptr_artist->tail = ptr_snode;
    }
    else if ( p == ptr_artist->head ) // at the front
    {
        ptr_snode->next = ptr_artist->head;
        ptr_artist->head->prev = ptr_snode;
        ptr_artist->head = ptr_snode;
    }
    else if ( p == NULL ) // at the end (while 문을 처음부터 끝까지 다 돌고 빠져나옴)
    {
        ptr_snode->prev = ptr_artist->tail;
        ptr_artist->tail->next = ptr_snode;
        ptr_artist->tail = ptr_snode;
    }
    else // in the middle (add before p)
    {
        ptr_snode->next = p;
        ptr_snode->prev = p->prev;
        p->prev->next = ptr_snode;
        p->prev = ptr_snode;
    }
}

void insert_to_index_directory(Song *ptr_song)
{
    SNode *ptr_snode = (SNode *)malloc(sizeof(SNode));
    ptr_snode->song = ptr_song;
    ptr_snode->next = NULL;
    ptr_snode->prev = NULL; // unused

    int index = ptr_song->index % SIZE_INDEX_TABLE;

    // add the snode into the single linked list at index_table[index]
    SNode *p = index_directory[index];
    SNode *q = NULL;
    while (p != NULL && strcmp(p->song->title, ptr_song->title) < 0)
    {
        q = p;
        p = p->next;
    }
    if (q==NULL) // add first
    {
        ptr_snode->next = p;
        index_directory[index] = ptr_snode;
    }
    else // add_after q
    {
        ptr_snode->next = p;
        q->next = ptr_snode;
    }
    
}

Artist *create_artist_instance(char *name) // 객체 생성을 위한 malloc 함수가 분산되어 사용되면 초기화가 필요한 때에 제대로 이루어지지 않는 등 여러 문제가 있을 수 있으므로 객체를 생성하는 함수를 따로 만들어 그 안에서 malloc 을 하도록 하는 것이 좋음
{
    Artist *ptr_artist = (Artist *)malloc(sizeof(Artist));
    ptr_artist->name = name;
    ptr_artist->next = NULL;
    ptr_artist->head = NULL;
    ptr_artist->tail = NULL;

    return ptr_artist;
}

Artist *find_artist(char *name)
{
    Artist *p = artist_directory[(unsigned char)name[0]]; // first artist with Initial name[0]
    /* name[0] = 00000000~11111111 */
    // char를 int로 변환할 때 첫 비트가 1이면 음수로 해석되어버림
    // 따라서 unsigned char 로 타입 변환을 한 다음 int로 변환하면 앞부분이 1이 아닌 0으로 채워지므로 정상적으로 0~255 사이의 정수로 변환 가능
    while ( p != NULL && strcmp(p->name, name) < 0 )
        p = p->next;

    if ( p!= NULL && strcmp(p->name, name) == 0)
        return p;
    else
        return NULL;
}

Artist *add_artist(char *name)
{
    Artist *ptr_artist = create_artist_instance(name);

    Artist *p = artist_directory[(unsigned char)name[0]]; // first node
    Artist *q = NULL; // p의 직전 주소를 저장할 포인터
    
    while ( p != NULL && strcmp(p->name,name) < 0 )
    {   
        q = p;
        p = p->next;
    }

    if ( p == NULL && q == NULL ) // empty list인 경우
        artist_directory[(unsigned char)name[0]] = ptr_artist;
    else if ( q == NULL ) // add at the front
    {   
        ptr_artist->next = artist_directory[(unsigned char)name[0]];
        artist_directory[(unsigned char)name[0]] = ptr_artist;
    }
    else // add after q
    {
        ptr_artist->next = p;
        q->next = ptr_artist;
    }

    return ptr_artist;
}

void status() // 현재 프로그램에 저장되어있는 모든 데이터를 출력해주는 함수
{
    for (int i = 0; i < NUM_CHARS; i++)
    {
        Artist *p = artist_directory[i];
        while ( p != NULL )
        {
            print_artist(p);
            p = p->next;
        }
    }
}

void print_artist(Artist *p)
{
    printf("%s\n", p->name);
    SNode *ptr_snode = p->head;
    while (ptr_snode != NULL)
    {
        print_song(ptr_snode->song);
        ptr_snode = ptr_snode->next;
    }
}

void print_song(Song *ptr_song)
{
    printf("    %d: %s, %s\n", ptr_song->index, ptr_song->title, ptr_song->path);
}