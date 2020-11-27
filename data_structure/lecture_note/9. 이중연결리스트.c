단방향 연결 리스트의 한계
- 어떤 노드의 앞에 새로운 노드를 삽입하기 어려움
- 삭제의 경우에 항상 삭제할 노드의 앞 노드가 필요
- 단방향의 순회만이 가능

이중연결리스트
- 각각의 노드가 다음 노드와 이전 노드의 주소를 가지는 연결 리스트
- 양방향의 순회(traverse)가 가능

ex)
struct node
{
    char *data;
    struct node next;
    struct node prev;
};

typedef struct node Node;

Node *head;
Node *tail;
int size = 0;

// 노드 삽입 (포인터 변수 p가 가리키는 노드 앞에 새로운 노드를 삽입하는 경우)
Node *new_node = (Node *)malloc(sizeof(Node));
new_node->data = "data";
new_node->next = p;
new_node->prev = p->prev;
p->prev->next = new_node;
p->prev = new_node;

// 노드 삭제 (p가 가리키는 노드를 삭제하는 경우)
p->prev->next = p->next;
p->next->prev = p->prev;

// 삽입 함수 구현
void add_after(Node *pre, char *item)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = item;
    new_node->prev = NULL;
    new_node->next = NULL;

    if ( pre == NULL && head == null ) // 빈 리스트에 삽입
    {
        head = node_node;
        tail = node_node;
    }
    else if ( pre == NULL ) // 헤드 부분에 삽입 (연결리스트에 적어도 하나의 노드가 존재)
    {
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }
    else if ( pre == tail ) // 꼬리 부분에 삽입
    {
        new_node->prev = tail;
        tail->next = new_node;
        tail = new_node;
    }
    else // 맨 앞도 뒤도 아닌 중간에 삽입
    {
        new_node->prev = pre;
        new_node->next = pre->next;
        pre->next->prev = new_node;
        pre->next = new_node;
    }
    size++;
}

// 삭제 함수 구현
4가지 경우로 나누어서 처리
1. p가 유일한 노드인 경우
2. p가 head인 경우
3. p가 tail인 경우
4. 그 밖의 일반적인 경우

void remove(Node *p)
{
    if ( p->prev == NULL && p->next == NULL )
    {
        head = NULL;
        tail = NULL;
        free(p);
    }
    else if ( p->prev == NULL )
    {
        p->next->prev = NULL;
        head = p->next;
        free(p);
    }
    else if ( p->next == NULL )
    {
        p->prev->next = NULL;
        tail = p->prev;
        free(p);
    }
    else
    {
        p->prev->next = p->next;
        p->next->prev = p->prev;
        free(p);
    }
}

void add_ordered_list(char *item)
{
    Node *p = tail;
    while ( p != NULL && strcmp(item, p->data) < 0 )
        p = p->prev;
    add_after(p, item);
}

원형리스트
- 원형 연결리스트 : 마지막 노드의 다음 노드가 첫번째 노드가 되는 단순 연결리스트
- 원형 이중연결 리스트 : 마지막 노드의 다음 노드가 첫번째 노드가 되고 첫 노드의 이전 노드가 마지막 노드가 됨