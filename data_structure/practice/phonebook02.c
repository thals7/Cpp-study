/*
기능 추가
- read : 파일로부터 데이터를 읽어옴
- status : 항상 알파벳 순으로 정렬된 상태를 유지
- save : 파일에 데이터를 저장
*/

#include <stdio.h>
#include <string.h>

#define CAPACITY 100
#define BUFFER_SIZE 50

char *names[CAPACITY];
char *numbers[CAPACITY];
int n = 0;

void load(); // 파일 로드 함수 추가
void add();
void find();
void delete();
void status();
void save(); // 파일 저장 함수 추가


int main()
{
    char command[BUFFER_SIZE];
    while(1)
    {
        printf("$ ");
        scanf("%s", command);

        if (strcmp("read", command) == 0) // read 명령 추가
            load();
        else if (strcmp("add", command) == 0)
            add();
        else if (strcmp("find", command) == 0)
            find();
        else if (strcmp("delete", command) == 0)
            delete();
        else if (strcmp("status", command) == 0)
            status();
        else if (strcmp("save", command) == 0) // save 명령 추가
            save();
        else if (strcmp("exit", command) == 0)
            break;
    }
    return 0; 
}


void load()
{
    char file_name[BUFFER_SIZE];
    char name[BUFFER_SIZE];
    char number[BUFFER_SIZE];

    scanf("%s", file_name);
    FILE *fp = fopen(file_name, "r");
    if (fp == NULL)
    {
        printf("Open failed.\n");
        return;
    }
    while ((fscanf(fp, "%s", name) != EOF)) // 파일의 끝에 도달할 때까지 반복해서 이름과 전화번호를 읽어서 배열에 저장 (파일에 있는 데이터를 배열로 들고오는 작업)
    {
        fscanf(fp, "%s", number);
        names[n] = strdup(name);
        numbers[n] = strdup(number);
        n++;
    }
    fclose(fp);
}

void add()
{
    char name[BUFFER_SIZE];
    char number[BUFFER_SIZE];

    scanf("%s %s", name, number);
    int i = n-1;
    while (i >= 0 && strcmp(names[i], name) > 0) // 전화번호부 맨 끝부터 비교하여 추가할 사람보다 사전식 순서가 크면 한 칸씩 뒤로 이동시킴
    {
        names[i+1] = names[i];
        numbers[i+1] = numbers[i];
        i--;
    } // 추가할 사람보다 사전식 순서가 작은 사람이 나오는 순간 while문 탈출
    names[i+1] = strdup(name); // i번째 사람이 처음으로 나보다 이름이 작은 사람이므로 그 바로 뒤에 이름과 번호를 삽입
    numbers[i+1] = strdup(number);
    n++;

    printf("%s was added successfully.\n", name);
}

void find()
{
    char name[BUFFER_SIZE];

    scanf("%s", name);
    for (int i = 0; i < n; i++)
    {
        if (strcmp(names[i],name) == 0 )
        {   printf("%s\n", numbers[i]);
            return;
        }
    }
    printf("No person named '%s' exists.\n", name);
}

void delete()
{
    char name[BUFFER_SIZE];

    scanf("%s", name);
    for (int i = 0; i < n; i++)
    {
        if (strcmp(names[i],name) == 0 ) // 삭제하려는 사람의 이름을 i번째에서 찾았으면
        {
            while ( i < n-1 ) // i부터 맨 끝까지 뒤에서 한 칸씩 앞으로 옮김
            {
                names[i] = names[i+1];
                numbers[i] = numbers[i+1];
                i++;
            }
            n--;
            printf("%s was deleted successfully.\n");
            return;
        }
    }
    printf("No person named '%s' exists.\n", name);
}

void status()
{
    for (int i = 0; i < n; i++)
        printf("%s %s\n", names[i], numbers[i]);
    printf("Total %d person.\n", n);
}

void save()
{
    char file_name[BUFFER_SIZE];

    scanf("%s", file_name);
    FILE *fp = fopen(file_name, "w");
    if (fp == NULL)
    {
        printf("Open failed.\n");
        return;
    }
    for (int i = 0; i < n; i++) // 파일에 배열의 값 저장
    {
        fprintf(fp, "%s %s\n", names[i], numbers[i]);
    }
    fclose(fp);
}