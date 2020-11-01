- 최적화
변수의 본질 : 메모리
상수의 본질 : 메모리에 저장되는 정보 그 자체

'컴파일러'의 코드 최적화
최적화 -> 의존성의 문제

1 a = b + 3;
2 c = a * 2;
1과 2번 구문은 반드시 순서대로 일어나야함
a는 b의 값이 정해져야만 정해질 수 있음 (a는 b에 대해 의존적)
c는 a의 값이 정해져야만 정해질 수 있음 (c는 a에 대해 의존적)

3 x = 10 + y;
4 z = x * y
3과 4번 구문은 순차적으로 일어나야함

하지만 1,2 와 3,4 사이에는 의존성이 존재하지 않음
즉 둘은 동시에 진행 가능 (개연성, 의존성이 없고 동시성을 가짐)

최적화를 한다는 것은 코드에서 군살(논리적으로 매우 당연한, 효율성이 없는 것들)을 제거하는 것
즉 최적화를 제대로 이해하기 위해서는 특정 변수(자료)에 대해 의존성이 존재하는 연산들을 구별해야 함

변수가 많을수록 경우의 수는 증가 -> 논리적 구조가 복잡해짐 (최적화 어려움)
컴파일러가 최적화하기 좋게 코드를 작성해야함

- 최적화 방해 요소
1. 변수가 많은 경우
   : 최대한 변수의 개수를 줄여야함
2. 포인터 사용 주의
   : 포인터는 임의의 주소를 가리킬 수 있다는 모호성을 가지므로 포인터를 사용할 경우 의존성 파악이 어려움

- const 심볼릭 상수
변수의 '상수화'
변수 선언시 const라는 형한정어를 추가하면 변수가 r-value는 될 수 있지만 l-value가 될 수 없음
어떤 메모리(변수)를 '읽기 전용' 메모리로 만들어 주는 것

- 상수형 포인터

ex)
void GetName(char *pszName, int nSize) // Write
{
    printf("Input your name : ");

    char szBuffer[32];
    gets_s(szBuffer, sizeof(szBuffer));
    strcpy_s(pszname, nSize, szBuffer);
}

void PrintName(const char *pszName) // Read만 하므로 const 붙여줌
{
    printf("Your name is %s. \n", pszName);
}

int main()
{
    char szName[32] = { 0 };
    GetName(szName, sizeof(szName));
    PrintName(szName);
    return 0;
}

- volatile
컴파일러의 최적화 과정에서의 코드 생략 방지
volatile을 적용해 변수를 선언하면 그 변수와 관련된(의존성이 존재하는) 모든 연산에 대해 컴파일러가 최적화 규칙을 적용하지 않음
불필요하든 말든 무조건 코드를 기계어로 바꿈

const 와는 정반대의 역할