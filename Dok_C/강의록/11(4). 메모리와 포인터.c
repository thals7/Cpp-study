- 다중 포인터
간접 지정 연산을 두 번 이상 해야 해당 자료를 찾을 수 있는 포인터

int *plist = aList; 의 해석 순서
1. *pList : pList는 포인터
2. int : 포인터가 가리키는 대상체는 int

int** *ppList = 0; 의 경우
1. *ppList : ppList는 포인터
2. int** : 포인터가 가리키는 대상의 형식은 int 포인터 포인터

- 포인터의 문제점
int *pnData가 가리키는 것은 int 하나의 주소일 수도 있고(&int) int가 여러개 들어있는 배열(ex.int[3])에서 첫번째 int의 주소일 수도 있음
대상(ex.int)을 포인팅하는데 개수의 개념이 없고 그 대상의 유효성 확인 자체가 어려움

- 포인터 배열
int* apList[5]; -> 인티저에 대한 포인터가 5개 있음
int* (*변수이름) = apList; -> *변수이름이 가리키는 대상인 int 포인터
즉 가리키는 대상(apList 부분)에 배열이 올 경우 맨 왼쪽(int*부분) 배열 요소 형식이 옴

char *apList[3] = {...}
여기서 *과 []중 무엇이 더 중요한가? [](배열) 우선
즉 apList는 요소가 3개인 배열이고 배열을 이루고 있는 요소 형식은 char*임 (캐릭터에 대한 포인터(char*)가 3개 있음)

char *astrList[3]이 선언되었고, &astrList[1]이라는 연산이 수행되었다면 이 연산결과의 자료형은 char**
&astrList[1]을 풀어서 쓰면 &*(astrList + 1)과 같음
이 때 '&*'는 서로 상쇄됨 -> 따라서 그냥 astrList + 1이라고 한 것과 같음
astrList의 자료형은 char* [3] 혹은 char**이므로 &astrList[1]의 자료형은 char**


ex)
void main()
{
    char *apszData[] = {"String", "Data", "Test"};
    int i = 0;

    for (i = 0; i < 3; ++i;)
    {
        puts(apszData[i]);
    }
}
/*
실행 결과 :
String
Data
Test
*/
-> 즉 char형 포인터 배열인 *apszData[3]의 각각의 요소는 문자열 상수의 주소를 가리키는 포인터임

- 메모리 주소 자체를 변수 자리에 집어넣게 되면?
//int nData = 10;
//*(int*)0x0018FF28이 주어진 Stack 영역이 맞다면
*(int*)0x0018FF28(nData주소) = 10;
printf("%d\n", *(int*)0x0018FF28);
-> 10이 정상적으로 출력됨

