- 함수
함수형 : 반환형식 호출규칙 이름 (매개변수 목록)
함수의 이름 또한 함수의 주소에 부여한 것임

- 함수 호출 규칙
함수 호출 과정에서 매개변수를 전달하는 순서(스택에 넣는 방법) 및 매개변수가 사용한 메모리 관리방법 등에 관한 규칙

- 함수 포인터
기본 형식 : 반환 자료형 ( 호출 규칙 *변수이름) (매개변수)

ex)
int TestFunc(char *pszParam)
{
    return 0;
}

int main()
{
    TestFunc("");
    
    int nData = (int)TestFunc;
    ( (int(*)(char*))nData )("");
    return 0;
}

- 역호출 구조 Call back
함수를 호출할 때 인자로 전달한 특정 함수를 호출받은 함수에서 호출하는 구조
'함수의 주소를 등록한다' -> 내가 Call 하는게 아니라 ~~에 의해서 Call 되어진다의 개념 

qsort() : 퀵 정렬 알고리즘을 이용하여 배열에 담긴 요소를 정리하는 함수

void qsort(void *base, size_t num, size_t width, int (__cdecl *compare)(const void *, const coid *));
base : 정렬대상 배열의 기준주소
num : 배열요소의 개수
width : 배열요소의 바이트 단위 크기
compare : 각 요소를 비교하여 같을 경우 0, 그렇지 않을 경우 양수 혹은 음수를 반환하는 함수의 주소

ex)
// 각 항을 비교하는 함수
int MyCmp(const void *left, const void *right)
{
    return *(int*)left - *(int*)right;
}

int main()
{
    int aList[5] = {20, 50, 10, 30, 40};

    qsort(aList, 5, sizeof(int), MyCmp);

    for (int i = 0; i < 5; ++i)
        printf("%d\t", aList[i]);
    return 0;
}
/*
출력 결과
10  20  30  40  50
*/
main() 함수에서 MyCmp함수가 직접적으로 호출되는 코드는 나오지 않았으나 qsort()에 의해서 MyCmp는 분명히 호출됨

qsort()를 왜 Callback 구조로 만들었는가?
int, char*, double 등등 자료형식에 따라서 비교방법이 달라질 수 있음
따라서 정렬 로직은 제공하나 비교방법은 자료에 따라 사용자가 정의할 수 있도록 한 것

ex)
#include <conio.h>

void TestFunc1(int nParam)
{
    puts("TestFunc1");
}

void TestFunc2(int nParam)
{
    puts("TestFunc2");
}

void TestFunc3(int nParam)
{
    puts("TestFunc3");
}

int main()
{
    coid(*pfList[3])(int) = {
        TestFunc1,
        TestFunc2,
        TestFunc3
    };

    int nInput;
    scanf("%d", &nInput);
    pfList[nInput](10);
}
/*
실행결과
0 입력시 TestFunc1 출력
1 입력시 TestFunc2 출력
2 입력시 TestFunc3 출력
*/