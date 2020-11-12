- 상속
클래스의 모든 내용을 물려받아서 만드는 새로운 클래스
1. 코드를 재사용(기능적 확장이나 개선)하는 방법
2. 규모 확장
3. 관계(class간)의 한 유형 cf)설계 : 객체(요소) 규정 + 관계 정의

CMyData; 와 CMyDataEx; 라는 클래스가 있을 때
CMyData : 부모(기본) 클래스
CMyDataEx : 자식(파생) 클래스

CMyDataEx a;를 선언하게 되면 a의 크기는 CMyData + CMyDataEx
그렇다면 a는 CMyData라고 할 수 있는가? Yes
CMyData를 사람이라고 봤을 때 CMyDataEx는 의사(사람의 일종) -> 결국 본질은 다 사람

시점의 등장 : 자식 클래스를 현재(구현중인 것)라고 봤을 때 부모 클래스는 과거(이미 되어있는 것)
상속은 이미 존재하는 것을 없애지는 못함(접근 차단만 가능)
즉 상속은 점점 덩치가 커지는 구조로 되어있음

** C++의 설계 원칙 (SOLID)
의존 관계의 파악이 우선적
SW설계시 3가지로 나누어야할 부분
: UI(사용자 부분) + Data(프로그램 자체) + 소프트웨어 자체(프로세서, 시스템 인터페이스 처리 문제 등)
UI는 무조건 Data에 대한 의존성을 가짐 -> UI와 Data의 분리는 필수적

- 기본 문법
ex)
class CMyData // 부모(기본) 클래스
{
};
class CMyDataEx : public CMyData // 자식(파생) 클래스
{
};
접근제어지시자 부분의 경우 대부분 public (private 이나 protected인 경우 거의 X)

파생 형식은 기본 형식을 pointing 가능
예를 들어 기본 형식이 사람(추상), 파생 형식이 학생(구현)이라고 했을 때 학생을 가리켜 사람이라고 말할 수 있다는 것

ex)
CTest; 기본 클래스와 CTestEx; 파생 클래스가 존재할 때
int main()
{
    CTestEx a;
    CTest &b = a;
    b.TestFunc();
    return 0;
}
이 때 b.TestFunc에서 불리는 함수는 CTest의 TestFunc()인가 Ex의 TestFunc()인가? 함수가 일반 메서드인 경우 접근 형식에 따름(a는 실 형식 b는 접근 형식) -> CTest의 TestFunc() 함수가 호출됨

메서드 : (1) 일반 : 접근 형식을 따름
        (2) virtual : 실 형식을 따름
        (3) static

생성자 함수는 오로지 객체 자신을 초기화만 해야함
파생 형식 생성자에서 부모 클래스의 멤버를 초기화 -> **절대 해서는 안됨**
ex)
class CTest
{
public:
    CTest()
    {
        m_nData = 10; // 부모 클래스의 생성자 함수에서 멤버의 초기값으로 10을 줌
    }
    int GetData() { return m_nData; }
protected:
    int m_nData;
};
class CTestEx : public CTest
{
public:
    CTestEx()
    {
        m_nData = 20; // 부모 클래스의 멤버인 m_nData를 20으로 초기화
    }
};

int main()
{
    CTestEx a;
    cout << a.GetData() << endl;
}
/*실행 결과
 10이 아닌 20이 출력됨
 */
protected는 외부에서는 접근할 수 없지만 상속받은 클래스들은 접근 가능 but 위와 같은 문제가 생길 수 있음
따라서 m_nData와 같은 멤버 데이터들은 protected가 아닌 private으로 설정해 파생 형식에서 접근하지 못하도록 하는 것이 좋음

- 생성자 선택
생성자를 다중 정의할 경우 기본 클래스의 생성자 중에서 어느 것을 호출할 지 파생 클래스에서 선택할 수 있음