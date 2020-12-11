// 연결리스트를 이용한 큐의 구현

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int Item; // 큐에 저장되는 데이터의 타입은 int

typedef struct node
{
    Item data;
    struct node *next;
} Node;

typedef struct queue_type
{
    struct node *front; // 연결리스트의 첫번째 노드의 주소를 저장
    struct node *rear; // 연결리스트의 마지막 노드의 주소를 저장
    int size;
} *Queue;

void terminate(const char *message)
{
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

int get_size(Queue q) // 현재 큐 안에 저장된 데이터가 몇 개인지 알아야하는 상황이 잦으므로 get_size 함수를 따로 만들어둠
{
    return q->size;
}

Queue create()
{
    Queue q = (Queue)malloc(sizeof(struct queue_type));
    if (q = NULL)
        terminate("Error in create: queue could not be created.");
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
    return q;
}

void destroy(Queue q)
{
    make_empty(q);
    free(q);
}

void make_empyty(Queue q)
{
    while (!is_empty(q))
        dequeue(q);
    q->size = 0;
}

bool is_empty(Queue q)
{
    return q->front = NULL; // or return q->size == 0;
}

void enqueue(Queue q, Item i)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL;)
        terminate("Error in push: queue is full.");
    
    new_node->data = i;
    new_node->next = NULL;
    if (is_empty(q)) // 현재 연결리스트가 empty인 경우
    {
        q->front = new_node;
        q->rear = new_node;
    }
    else // 적어도 하나 이상의 노드가 존재할 경우
    {
        q->rear->next = new_node;
        q->rear = new_node;
    }
    q->size++;
}

void dequeue(Queue q) // remove first
{
    Node *old_front; // 삭제할 노드를 가리키는 포인터
    Item i;
    if (is_empty(q))
        terminate("Error in dequeue: queue is empty.");
    
    old_front = q->front;
    i = old_front->data;
    q->front = old_front->next;
    if (q->front == NULL) // 원래 노드가 하나밖에 없었을 경우
        q->rear = NULL; // q를 empty 상태로 만듦
    free(old_front);
    q->size--;
    return i;
}

Item peek(Queue q)
{
    if (is_empty)
        terminate("Error in peek: queue is empty");
    return q->front->data;
}