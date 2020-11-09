- 클래스

자료구조 : 자료 자체가 존재하고, 그 자료를 사용하는 (함수로 구현된)코드가 있을 때 코드는 자료에 대한 '의존성'을 가짐
          자료가 없어지거나 변경되면 코드 또한 사라지거나 수정됨

어떤 대상에 대해 제작자는 사용자의 실수, 오류 가능성을 줄이기 위해 쉬운 사용 방법을 제시해야함
ex)
//// 제작자 코드
typedef struct USERDATA
{
    int nAge;
    char szName[32];
} USERDATA;

void PrintUserData(USERDATA *pUser)
{
    printf("%d, %s\n", pUser->nAge, pUSer->szName);
}
//// 사용자 코드
int main()
{
    USERDATA a = {20, "Jung"};
    // Step# 1
    printf("%d, %s\n", a.nAge, a.szName); // 출력이라는 행위를 하기 위해 사용자가 알아야 할 것이 많음
    // Step# 2
    PrintUserData(&a); // 1번에 비해 배우고 이해해야할 것들이 훨씬 적음
    return 0;
}

But! 위의 코드에서는 자료구조(struct USERDATA)와 함수(PrintUserData) 전혀 관련성이 없어보임

따라서 struct USERDATA 안에
void(*Print)(struct USERDATA*); 를 집어넣고
main() 안에 USERDATA a = {20, "Jung", PrintUserData}; 출력 함수를 추가하면
// Step# 3
a.Print(&a);
이렇게 하면 Print라는 함수가 구조체 자료 속에 들어있는 함수처럼 보임
사용자는 USERDATA 자료 자체가 출력 기능을 제공하는 것으로 이해 (자료와 함수의 관계를 명확하게 보여줌)
// Step# 4
a.Print();
괄호 안이 비어있지만 C++ 에서는 &a 가 들어있는 것처럼 작동함
이 때 USERDATA 안에 들어있는 멤버 함수 Print를 메소드라고 부름

/* 함수 포인터를 구조체 멤버로 사용하기
ex)
struct Calc
{
    int (*fp)(int,int); // 반환값자료형 (*함수포인터이름)(매개변수자료형1,매개변수자료형2);
}
int add(int a, int b) // int형 반환값, int형 매개변수 두개
{
    return a+b;
}
int main()
{
    struct Calc c;
    c.fp = add; // add함수의 메모리 주소를 구조체 c의 멤버에 저장
    printf("%d\n", c.fp(10,20)); // 구조체 멤버로 add함수 호출
    return 0;
}
*/