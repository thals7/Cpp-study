스택
- 일종의 리스트
- 데이터의 삽입과 삭제가 한쪽 끝에서만 이루어짐
- LIFO (Last-In, First-Out)
- 삽입/삭제가 일어나는 쪽을 스택의 top이라 부름

스택이 지원하는 연산
- push : 스택에 새로운 원소를 삽입하는 연산
- pop : 스택의 top에 있는 원소를 스택에서 제거하고 반환
- peek : 스택 top의 원소를 제거하지 않고 반환
- empty : 스택이 비었는지 검사

스택 응용 예 : 괄호 검사 문제
- 입력 수식의 괄호가 올바른지 검사
  ex) [ a + b * { c / ( d - e )}] + ( d / e )
- 단순히 여는 괄호와 닫는 괄호의 개수 비교 만으로는 부족
- 스택을 이용하여 검사
  - 여는 괄호는 스택에 push
  - 닫는 괄호가 나오면 스택에서 pop한 후, 두 괄호가 같은 유형이어야 함
  - 마지막에 스택에 남는 괄호가 없어야 함


배열을 이용한 스택의 구현
ex)
#include "stack.h" // main 함수에서 사용할 push, pop 등의 함수의 prototype만 모아놓은 헤더파일
#define MAX_CAPACITY 100

char stack[MAX_CAPACITY]; // 스택에 저장되는 데이터의 타입을 문자라고 가정
int top = -1; // index of the top element 

void push(char ch)
{
    if (is_full()) // 스택이 가득차면 더이상 push할 수 없음
        return;
    top++;
    stack[top] = ch;
}

char pop() // pop을 호출하기 전에 먼저 empty인지 검사해야 함
{
    char tmp = stack[top];
    top--;
    return tmp;
}

char peek() // peek을 호출하기 전에 먼저 empty인지 검사해야 함
{
    return stack[top];
}

int is_empty()
{
    return top == -1;
}

int is_full()
{
    return top == MAX_CAPACITY-1;
}


연결리스트를 이용한 스택의 구현
- 연결리스트의 맨 앞이 노드를 삽입/삭제하기 편함
- 따라서 연결리스트의 첫번째 노드를 stack의 top으로 함
ex)
struct node
{
    char *data;
    struct node *next;
};
typedef struct node Node;

Node *top = NULL;

void push(char *item)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = item;
    p->next = top;
    top = p;
}

char *pop()
{
    if (is_empty())
        return NULL;
    char *result = top->data;
    top = top->next;
    return result;
}

char *peek()
{
    if (is_empty())
        return NULL;
    return top->data;
}

int is_empty()
{
    return top == NULL;
}

문제점
- 만약 스택이 동시에 2개 이상 필요하다면?
  스택 역할을 할 배열을 2개 만들고 + push, pop 등의 함수도 각각의 스택에 맞게 2개씩 만들어야 함 -> 매우 비효율적
- 서로 다른 타입의 데이터를 저장할 스택이 필요하다면?


첫번째 문제점을 보완할 스택의 구현
(1) 배열을 통한 구현
// 하나의 함수를 여러개의 스택에서 사용할 수 있도록 함
ex)
//stackADT.h
typedef int Item; // 만약 int가 아닌 다른 타입을 저장하는 스택을 만들고 싶으면 int를 다른 것으로 바꿔주기만 하면 됨 -> 코드의 재사용 (But 동시에 사용은 불가능)
typedef struct stack_type *Stack;

Stack create();
void destroy(Stack s);
void make_empty(Stack s);
bool is_empty(Stack s);
void push(Stack s, Item i);
Item pop(Stack s);
Item peek(Stack s);


//stackADT.c
#include "stackADT.h"

#define INIT_CAPACITY 100

struct stack_type
{
    Item *contents; // 배열
    int top;
    int size; // 배열의 크기
};

static void terminate(const char *message)
{
    printf("%s\n", message);
    exit(1); // 프로그램 종료
}

Stack create()
{
    Stack s = (Stack)malloc(sizeof(struct stack_type)); // Stack 자체를 struct stack_type의 포인터로 정의했기 때문에 따로 *를 붙이지 않음
    if (s == NULL)
        terminate("Error in create: stack could not be created.");
        s->contents = (Item *)malloc(INIT_CAPACITY * sizeof(Item));
    if (s->contents == NULL)
    {
        free(s);
        terminate("Error in create: stack could not be created.");
    }
    s->top = -1;
    s->size = INIT_CAPACITY;
    return s;
}

void destroy(Stack s) // 스택 자체를 없앰
{
    free(s->contents);
    free(s);
}

void make_empty(Stack s) // 스택의 내용만 비움
{
    s->top = -1;
}

bool is_empty(Stack s)
{
    return s->top == -1;
}

void push(Stack s, Item i)
{
    if (is_full(s))
        reallocate(s); // 스택에 저장된 데이터의 개수를 n이라고 하면 reallocate함수의 시간복잡도는 O(n) -> 물론 처음부터 배열의 크기를 크게 만들어 reallocate를 피할수도 있음
    s->top++;
    s->contents[s->top] = i; // reallocate함수를 제외한 나머지 부분의 시간복잡도는 O(1)
}

Item pop(Stack S)
{
    if (is_empty(s))
        terminate("Error in pop: stack is empty.");
    s->top--;
    return s->contents[s->top+1]; //pop() 함수의 시간복잡도는 O(1)
}

Item peek(Stack s)
{
    if (is_empty(s))
        terminate("Error in peek: stack is empty.");
    
}

void reallocate(Stack s)
{
    Item *tmp = (Item *)malloc(2 * s->size * sizeof(Item));
    if (tmp == NULL)
        terminate("Error in create: stack could not be created.");
    for (int i=0; i<s->size; i++)
        tmp[i] = s->contents[i];
    free(s->contents);
    s->contents = tmp;
    s->size *= 2;
}

// 사용 예
#include "stackADT.h"

int main()
{
    Stack s1 = create();
    Stack s2 = create();

    push(s1, 12);
    push(s2, 9);
}


(2) 연결리스트를 통한 구현
// stackADT.c
#include "stackADT.h" // 배열과 동일한 헤더파일 사용

struct node
{
    Item data;
    struct node *next;
};

struct stack_type
{
    struct node *top;
};

static void terminate(const char *message)
{
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

Stack create()
{
    Stack s = malloc(sizeof(struct stack_type));
    if (s == NULL)
        terminate("Error in create: stack could not be created.");
    s->top = NULL;
    return s;
}

void destroy(Stack s)
{
    make_empty(s);
    free(s);
}

void make_empty(Stack s)
{
    while (!is_empty(s))
        pop(s);
}

bool is_empty(Stack s)
{
    return s->top == NULL;
}

void push(Stack s, Item i)
{
    struct node *new_node = malloc(sizeof(struct node));
    if (new_node == NULL)
        terminate("Error in push: stack is full.");
    new_node->data = i;
    new_node->next = s->top;
    s->top = new_node;
}

Item pop(Stack S)
{
    struct node *old_top;
    Item i;

    if (is_empty(s))
        terminate("Error in pop: stack is empty.");
    old_top = s->top;
    i = old_top->data;
    s->top = old_top->next;
    free(old_top);
    return i;
}
// 스택을 연결리스트로 구현한 경우 push와 pop의 시간복잡도는 O(1)

Item peek(Stack s)
{
    if (is_empty(s))
        terminate("Error in peek: stack is empty.");
    return s->top->data;
}


두번째 문제점을 보완하는 방법?
Generic ADTs
- 1가지 타입의 데이터만을 저장할 수 있음
  - 데이터 타입이 다라지면 Item 타입 정의를 수정해야 함
  - 서로 다른 타입의 데이터를 저장하는 2개의 스택을 만들 수 없음
- void * 타입을 이용하여 generic한 스택을 구현할 수는 있으나 단점들 존재
- 객체지향 프로그래밍 언어를 사용해 구현하는 것이 나음