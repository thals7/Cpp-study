- 디폴트 매개변수 default parameter

ex)
// Callee
void Testfunc(int a, int b = 10)
{
    pritnf("a : %d, b : %d\n", a, b);
}
// Caller
int main()
{
    TestFunc(3);
    return 0;
}
/*
실행 결과
a : 3, b : 10
*/
호출자의 실인수 기술 순서는 L->R
이 때 b의 값을 명시하지 않을 경우 b의 값을 디폴트 값인 10으로 규정

But! TestFunc(3,4); 라고 입력하면
실행 결과는 a: 3, b : 4 로 b의 디폴트 값인 10을 무시함
디폴트 파라미터는 반드시 함수의 선언 부분에 써야함

주의사항
(1) 매개변수의 디폴트 값은 반드시 오른쪽 매개변수부터 기술
(2) 왼쪽 첫 번째 매개변수의 디폴트 값을 기술하려면 나머지 오른쪽 모든 매개변수에 대한 디폴트 값을 기술해야함

디폴트 파라미터는 모호성을 불러오므로 가급적 사용을 자제하는 것이 좋음

- 함수 다중 정의
다중 정의 Overloading: 하나(함수 이름, 변수 이름 등)가 여러 의미를 동시에 갖는 것

디폴트 매개변수와 다중 정의가 조합되면 매우 강력한 모호성 발생 가능
ex)
void TestFunc(int a, int b = 4)
{
}
void TestFunc(int nParam)
{
}
int main()
{
    TestFunc(3);
    return 0;
}
/*
실행시 에러 발생 : 'TestFunc' 오버로드된 함수에 대한 호출이 모호함
*/

- Name mangling
// int __cdecl Add(int,int) (?Add@@YAHHH@Z)
Add 라는 함수가 있을 때 이 함수의 진짜 이름은 맨 오른쪽 괄호 안에 ?Add~ 부분
C++에서는 컴파일을 할 때 함수의 이름을 다른 형식으로 바꿈(Name mangling)
이 때 mangled name은 절대 중복되지 않음

Name mangling은 C++에서 다중 정의, 재정의 등을 가능케하는 내부 매커니즘 중 하나

어떤 특수한 상황에서 함수를 Call 해야 하는데 이름이 찾아지지 않을 때가 있음 -> Name mangling이 되어있기 때문
이런 경우 함수 선언 앞에 extern "C"(symbol export 할 때 mangling name이 아닌 C언어 형식으로 한다는 뜻) 라고 써주면 name mangling을 피할 수 있음
extern "C" int Add(int a, int b);

- 네임스페이스
C언어 : 변수 이름, 함수 이름의 중복 불가능
But 여러 사람이 동시에 프로그램을 개발하다 보면 변수 이름, 함수 이름의 중복 가능성이 높음
C++ -> 네임스페이스(소속)
       스코프 {} 범위 자체에 대해 이름을 부여
       네임스페이스의 블록 내부에 선언하는 변수나 함수들은 모두 명시한 '이름'에 속하게 됨

ex)
namespace ~~
{
    // 네임스페이스의 시작
    int a;
    ...
    //네임 스페이스의 끝
}

{} 안에서 선언된 변수 a는 ~~::a (~~에 속한 a)
이 때 ::를 범위지정 연산자라고 부름

using 선언
using namespace ~~; 를 선언하게 되면
cout 등을 사용시 ~~::를 생략할 수 있음

사용자 정의 함수에 대해서는 소속이 무소속인지 아닌지 기술해주는 것이 좋음
무소속일 경우 ::Add(3,4) 이런 식

- 식별자 검색 순서
식별자가 선언된 위치를 검색하는 순서

전역 함수인 경우
1. 현재 블록 범위
2. 현재 블록 범위를 포함하고 있는 상위 블록 범위(최대 적용 범위는 함수 몸체까지)
3. 가장 최근에 선언된 전역 변수나 함수
4. using 선언된 네임스페이스 혹은 전역 네임스페이스. 단 두 곳에 동일한 식별자가 존재할 경우 컴파일 오류 발생

클래스 메서드인 경우
1. 현재 블록 범위
2. 현재 블록 범위를 포함하고 있는 상위 블록 범위(최대 적용 범위는 함수 몸체까지)
3. 클래스의 멤버
4. 부모 클래스의 멤버
5. 가장 최근에 선언된 전역 변수나 함수
6. 호출자 코드가 속한 네임스페이스의 상위 네임스페이스
7. using 선언된 네임스페이스 혹은 전역 네임스페이스. 단 두 곳에 동일한 식별자가 존재할 경우 컴파일 오류 발생