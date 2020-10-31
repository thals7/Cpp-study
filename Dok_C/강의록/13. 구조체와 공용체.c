- 구조체
서로 같거나 다른 형식들의 연속된 집합체
다양한 기본 자료형을 가진 요소들을 모아 새로운 자료형으로 만든 것

자료형 : 일정 길이의 메모리에 저장된 정보의 해석 방법
배열 :동일 형식(자료형)의 연속된 '집합체'

ex)
typedef struct USERDATA
{
    unsigned int nHeight;
    char szName[12];
    char szPhone[12];
    unsigned char sex;
} USERDATA; // 자료구조 설계

int main()
{
    USERDATA a;
    a.nHeight = 180;
    strcpy_s(a.szName, sizeof(a.szName), "Gil-dong");
    strcpy_s(a.szPhone, sizeof(a.szPhone), "123-4567");
    a.sex = "M"; //기본 문법

    char buffer[sizeof(USERDATA)]
    USERDATA *pData = (USERDATA*)buffer;
    pData->nHeight = 180;
    strcpy_s(pData->szName, sizeof(pData->szName), "Min-soo");
    strcpy_s(pData->szphone, sizeof(pData->szPhone), "123-4567");
    pData->sex = "M" // 포인터를 사용한 응용 문법

    a.pNext = pData;
    printf("%s", a.pNext->szName);
    //Min-soo가 출력됨

    return 0;
}

덩치가 큰 구조체를 주소로 넘기지 않고 일반 변수처럼 Call by value 형식으로 처리하면 스택을 많이 사용하는 코드가 되어버림
따라서 구조체를 함수의 인수로 전달할 때는 주소를 사용하는 Call by reference 방식을 사용하는 것이 좋음

- 연결 리스트 (Linked List)
자료를 가진 부분과 순서상 다음에 위치하는 자료가 저장된 메모리에 대한 포인터로 이루어진 노드(Node)를 마치 사슬처럼 묶은 자료구조
선형 구조를 구현하는 가장 대표적인 방법

단순 연결 리스트(Single Linked List) : 포인터 정보가 한 쪽 방향만 존재할 경우
이중 연결 리스트 : 포인터 정보가 양방향으로 존재

- 구조체 멤버 맞춤
배열은 각 요소가 연접하여 붙어있으나 구조체는 연접할 수도 있고 그렇지 않을 수도 있음
즉 두 멤버 사이에 일정 크기의 공백이 껴들어 갈 수 있음

#pragma pack(push,1) -> 멤버를 1바이트 단위로 정렬
but IO 속도는 떨어지게 됨 (잘 안씀)

- 비트필드
구조체 멤버가 바이트 단위가 아닌 비트 단위 데이터를 다루는 멤버로 선언되는 구조체

- 공용체
한 형식(같은 크기)에 여러 자료형(해석방법)을 부여하는 문법