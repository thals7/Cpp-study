- 외부 변수
다른 외부 소스 파일에 선언된 변수를 현재 파일에서 참조하여 사용하는 변수 (전역변수로 제한)

선언 + 정의
별도로 이루어지는 경우 : int a;(선언) ... a = 5;(정의)
동시에 이루어지는 경우 : int a = 0;(선언 및 정의)

선언 : 일종의 정치 공약 (컨셉, 개념 -> 추상적) 컴파일 타임에 이루어짐
정의 : 그 정치 공약을 이행하는 것 (추상적인 개념을 구현) 링크 타임에 이루어짐

ex)
extern int g_nData; //'이미' 외부 Test.c에 정의되어있는 g_nData 변수에 대한 '선언'(만)

void TestFunc(int); // Test.c라는 파일 안에 정의되어있는 함수

int main()
{
    TestFunc(10);
    printf("g_nData : %d\n", g_nData);
    return 0;
}

- typedef 형 재선언(형 재정의)
typedef 예약어를 통해 기존 자료형을 단순하게 표현할 수 있게 새로운 자료형(사용자 정의 형식)으로 만듦

형식 재선언이 필요한 이유?
가장 큰 이유는 생산성을 높이기 위해서
보통은 구조체, 열거형 상수 등과 연계해서 형 재선언을 사용함
but 기본 형식을 재선언하는 경우 주의해야함 (가급적 사용 자제)

ex)
UINT uData; 에서
UINT 가 unsigned int 라는 느낌이 단번에 오더라도 진짜로 맞는지 무조건 확인이 필요함
타자를 덜 치게 됨으로써 생산성이 올라갈 순 있으나 이것을 처음 본 사람들은 확인 과정을 거쳐야 함
결과적으로 코드의 가독성을 떨어트림 (읽기 좋은 코드가 X)

#define vs typedef
효과는 같으나 내부적으로는 큰 차이가 있음
#define : unsigned int를 UINT로 단순히 문자열을 치환하는 것
typedef : UINT가 명백히 자료형이라고 문법상 분류가 되어버림

- 열거형 상수
숫자(상수)에 이름을 붙인 상수
여러 개의 심볼릭 상수를 한꺼번에 정의하고 구조체처럼 새로운 사용자 정의 자료형으로 활용 가능

ex)
enum ACTION {MOVE, JUMP, ATTACK}; // ACTION 이라는 열거형 상수 선언
typedef enum COLOR {RED = 100, GREEN, BLUE} COLOR; // COLOR 라는 열거형 상수를 선언하고 사용자 정의 자료형으로 선언

void main()
{
    enum ACTION action = MOVE; // ACTION형 변수 action을 선언하고 초기화
    COLOR color = GREEN; // COLOR형 변수 color을 선언하고 초기화

    pritnf("action : %d, color : %d\n, action, color");
}
/*
실행 결과
action : 0, color : 101
*/