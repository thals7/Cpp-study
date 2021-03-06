리스트
- 기본적인 연산 : 삽입, 삭제, 검색 등
- 리스트를 구현하는 대표적인 두 가지 방법 : 배열, 연결리스트
cf) 리스트 : 순서가 존재 / 집합(set) : 순서가 없음

배열
- 메모리의 연속된 공간을 사용
- 데이터의 저장 및 순서 관계까지 유지

배열의 장점
- random access가 가능한 구조
- 배열의 첫번째 주소에서 간단한 덧셈과 곱셈으로 배열의 다른 칸에 자유롭게 접근할 수 있으므로 몇 번째 칸을 쓰느냐와 상관없이 데이터를 쓰고 읽는 시간이 동일

배열의 단점
- 크기가 고정 -> reallocation 필요
- 리스트의 중간에 원소를 삽입하거나 삭제할 경우 다수의 데이터를 옮겨야 함


연결리스트
- 노드들이 링크로 연결되어있는 자료구조
- 데이터의 순서관계를 유지하기 위해서 반드시 연속적으로 저장할 필요가 없음 (데이터가 저장되는 주소에 큰 의미 X)
- 다른 데이터의 이동없이 중간에 삽입이나 삭제가 가능
- 길이의 제한이 없음
- 랜덤 엑세스가 불가능

노드
- 각각의 노드는 필요한 데이터 필드와 하나 혹은 그 이상의 링크 필드로 구성
- 링크 필드는 다음 노드의 주소를 저장
- 첫 번째 노드의 주소는 따로 저장해야 함 (절대 잊어버려서는 안됨)
- 마지막 노드의 링크(next) 필드에는 NULL을 저장하여 연결리스트의 끝임을 표시함

ex)
struct node 
{
    char *data;
    struct node *next; // 다음 노드의 주소를 저장할 필드로, 자신과 동일한 구조체에 대한 포인터를 멤버로 가진다는 의미에서 '자기참조형 구조체'라고 부르기도 함
};

typedef struct node Node;
Node *head = NULL; // 연결리스트의 첫 번째 노드의 주소를 저장할 포인터

노드를 미리 만들어 놓는 것이 아니라 노드가 필요할 때마다 만들어서 연결 리스트에 추가

Node *p = head;
while (p != NULL)
{
    printf("%s\n", p->data);
    p = p->next;
}
여기서  p라는 추가적인 변수를 사용한 이유?
while (head != NULL) {...} 이라고 하게 될 경우 실행은 위의 코드와 같으나 마지막에 head의 값이 NULL이 되어버림 (노드의 첫번째 주소를 저장해야하는 head의 임무를 저버림)


연결리스트의 맨 앞에 새로운 노드 추가하기
(1)새로운 노드를 만들고 추가할 데이터를 저장
Node *tmp = (Node *)malloc(sizeof(Node)); 
tmp->data = item;
(2) 새로운 노드의 next 필드가 현재의 head노드를 가리키도록 함
tmp->next = head;
(3) 새로운 노드를 새로운 head 노드로 함
head = tmp;

특수한 상황의 고려 : 연결리스트를 다루는 프로그램에서 가장 주의할 점은 내가 작성한 코드가 일반적인 경우만이 아니라 특수한 경우에도 문제 없이 작동하는지 확인하는 것임
위와 같은 맨 앞에 새로운 노드를 추가하는 상황에서는 기존의 연결 리스트의 길이가 0인 경우, 즉 head가 NULL인 경우에도 문제가 없는지 확인해야함

보통 head는 전역변수로 선언됨
but! 전역변수로 선언되지 않은 경우
함수 작성시 포인터 변수 head의 주소를 매개변수로 받아야 함
void add_first(Node **ptr_head, char *item)
{
    Node *tmp = (Node *)malloc(sizeof(Node));
    temp->data = item;
    temp->next = *ptr_head
    *ptr_head = temp;
}
이렇게 구현할 경우 함수는 다음과 같이 호출해야함
add_first(&head, item_to_store);


어떤 노드 뒤에 새로운 노드 삽입하기
(1) 새로운 노드를 만들고 데이터를 저장
Node *tmp = (Node *)malloc(sizeof(Node));
tmp->data = item;
(2) 새로운 노드의 next 필드가 prev의 다음 노드를 가리키도록 함
(전: [prev] -> [next] 후: [prev] -> [새로운 노드] -> [next] )
tmp->next = prev->next;
(3) 새로운 노드를 prev의 다음 노드로 만듦
prev->next = tmp;

연결리스트에 새로운 노드를 삽입할 때 삽입할 위치의 바로 앞 노드의 주소가 필요함
즉 어떤 노드의 뒤에 삽입하는 것은 간단하지만, 반대로 어떤 노드의 앞에 삽입하는 것은 간단하지 않음