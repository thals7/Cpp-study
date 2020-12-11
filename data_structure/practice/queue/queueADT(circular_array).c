// 환형 배열을 이용한 큐의 구현

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INIT_CAPACITY 100

typedef int Item;

typedef struct queue_type
{
    Item *contents; // 배열 (동적 메모리 할당을 받음)
    int front; // 배열에서의 index이므로 int형 변수
    int rear;
    int size; // 저장된 데이터의 개수
    int capacity; // 배열 contents의 크기
} *Queue;

void terminate(const char *message)
{
    printf("%s\n", message);
    exit(1);
}

int get_size(Queue q) // 현재 큐 안에 저장된 데이터가 몇 개인지 알아야하는 상황이 잦으므로 get_size 함수를 따로 만들어둠
{
    return q->size;
}

Queue create()
{
    Queue q = (Queue)malloc(sizeof(struct queue_type));
    if (q == NULL)
        terminate("Error in create: queue could not be created.");
    q->contents = (Item *)malloc(INIT_CAPACITY * sizeof(Item));
    if (q->contents == NULL)
    {
        free(q);
        terminate("Error in create: queue could not be created.");
    }
    q->front = 0;
    q->rear = -1;
    q->size = 0;
    q->capacity = INIT_CAPACITY;
    return q;
}

void destroy(Queue q)
{
    free(q->contents);
    free(q);
}

void make_empty(Queue q) // q를 초기 상태로 만드는 함수 (단순히 배열을 비우는 것이므로 free할 필요는 없음)
{
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

bool is_empty(Queue q)
{
    return q->size == 0;
}

bool is_full(Queue q)
{
    return q->size ==  q->capacity;
}

void enqueue(Queue q, Item i)
{
    if (is_full(q))
        reallocate(q);
    q->rear = (q->rear + 1)%q->capacity; // q에 새로운 데이터를 삽입하는 자리는 현재 rear의 자리에서 +1 증가된 위치. 이 때 rear+1이 배열의 범위를 벗어난다면 다시 0으로 되돌려줘야 함
    q->contents[q->rear] = i;
    q->size++;
}

void dequeue(Queue q)
{
    if (is_empty(q))
        terminate("Error in dequeue: queue is empty.");
    Item result = q->contents[q->front];
    q->front = (q->front + 1)%q->capacity;
    q->size--;
    return result;
}

Item peek(Queue q)
{
    if (is_empty(q))
        terminate("Error in peek: queue is empty.");
    return q->contents[q->front];
}

void reallocate(Queue q)
{    // 현재 배열(contents)에 front부터 rear까지는 빈 칸 없이 꽉 차있어야함
    Item *tmp = (Item *)malloc(2*q->capacity * sizeof(Item));
    if (tmp == NULL)
        terminate("Error in create: queue could not be expanded.");
    int j = q->front; // 데이터를 복사해오는 순서를 front부터 시작
    for (int i=0; i<q->size; i++)
    {
        tmp[i] = q->contents[j];
        j = (j + 1)%q->capacity; // j는 단순히 +1 증가하는 것이 아니라 배열의 끝에 도달하게 되면 다시 0으로 돌아와서 rear에서 끝나야 하므로 j는 j++;가 아닌 j+1을 capacity로 나눈 나머지가 됨
    }
    free(q->contents);

    q->front = 0;
    q->rear = q->size-1;
    q->contents = tmp;
    q->capacity *= 2;
}