#include <stdio.h>

typedef struct _FRUITS // 노드를 구성하는 구조체 선언
{
    char Fruit[16];
    char Price[16]; // 데이터를 저장할 멤버
    struct _FRUITS *pNext; // 다음 노드의 주소를 저장할 포인터
} FRUITS; // typedef를 사용하여 구조체 별칭을 FRUITS로 정의

int main()
{
    FRUITS FruitList[3] = {
        {"사과", "1000", NULL},
        {"딸기", "3000", NULL},
        {"수박", "5000", NULL} }; // FRUITS 구조체의 배열을 선언하고 초기화
    FRUITS *curr = NULL;

    FruitList[0].pNext = &FruitList[1];
    FruitList[1].pNext = &FruitList[2];
    FruitList[2].pNext = NULL;

    curr = &FruitList[0];
    while (curr != NULL)
    {
        printf("%s, %s\n", curr->Fruit, curr->Price);
        curr = curr->pNext;
    }
    
    return 0;
}