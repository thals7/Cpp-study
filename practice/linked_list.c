#include <stdio.h>

typedef struct NODE
{
    int data;
    struct NODE *next; // 자기 참조 구조체 / NODE 구조체로 만든 다른 노드의 주소를 저장할 포인터변수(자기 자신이 아닌 다른 노드의 메모리 주소 저장)
} node;

int main()
{
    node *head = malloc(sizeof(node)); // node 구조체의 크기만큼 할당받고 이 할당받은 메모리의 시작 주소 값을 *head에 저장하는 것
    head->next = NULL; // 구조체 포인터가 안에 있는 next 포인터 변수는 값이 없음 (아무것도 가리키지 않음) -> 머리 노드가 가리키는 다음 노드가 없음
    
    node *node1 = malloc(sizeof(node)); // 새로운 노드 구조체 포인터 생성
    node1->next = head->next; // node1이 가리키는 다음 주소는 머리 노드가 가리키던 다음 주소(NULL)
    node1->data = 10; // node1이 가리키는 메모리가 있는 곳의 구조체의 data 변수에는 10 저장
    head->next = node1; // 머리 노드의 next 포인터 변수에 node1의 값(node1이 동적할당 받은 메모리가 있는 곳의 주소)를 저장하여 머리 노드가 가리키는 구조체 안의 *next가 가리키는 값이 *node1이 가리키는 값이 됨
    
    node *node2 = malloc(sizeof(node)); // 두번째 노드 구조체 포인터 생성
    node2->next = node1->next; // node2가 가리키는 다음 주소는 node1이 가리키는 다음 주소(NULL)
    node2->data = 20;
    node1->next = node2;

    free(head);
    free(node1);
    free(node2);
    return 0;
}