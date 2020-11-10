- 복사 생성자
int a(10); -> 변수(인스턴스) a가 생성되었고 초기값(상수)은 10
int b(a); -> a는 원본, b는 사본 (복사 생성)

CMyString 이라는 Class 가 있을때
CMyString strData; 생성자(디폴트)
CMyString strNew(strData); 복사 생성자
클래스를 작성할 때 복사 생성자를 생략하면 디폴트 생성자처럼 컴파일러가 자동으로 만들어줌

생성자의 종류
1. 기본(디폴트) 생성자 (매개변수 X)
2. 다중 정의된 생성자 (매개변수 O)
   - 변환 생성자 (매개변수 1개) : 형변환자와 관련 있음
3. 복사 생성자
4. 이동 생성자 (r-value 참조를 받음)

복사 생성자 정의가 필요한 경우?
Deep copy : 대상체(원본)을 여러개 만드는 경우
Shallow copy : 대상체 하나에 접근할 수 있는 수단(참조)을 여러개 만드는 경우
ex)
int main()
{
    int *pA, *pB;
    pA = new int;
    *pA = 10;

    pb = new int;
    pB = pA; // shallow copy (메모리 자체를 복사하는 것이 아닌 메모리 주소만 복사)

    delete pA;
    delete pB;
    return 0;
}
위의 코드를 실행할 경우 프로그램이 죽어버림
마지막 메모리를 해제하는 과정에서 a가 먼저 사라진 상태에서 b 삭제를 시도하게 되면 이미 없는 공간을 또 삭제할 수 없기 때문에 오류가 나게 됨

클래스를 작성할 때 복사 생성자를 생략하면 디폴트 생성자처럼 컴파일러가 자동으로 만들어줌
But! 디폴트 복사 생성자는 Shallow copy를 하기 때문에 Deep Copy가 필요할 경우(클래스 내부에서 메모리를 동적 할당 및 해제하고 이를 멤버 포인터 변수로 관리하고 있는 경우) 별도로 복사 생성자 정의를 해주어야함

복사 생성자 정의
클래스이름(const 클래스이름 &참조변수이름);
{
    /*
    여기서 Deep copy가 필요한 부분은 new로 새로 메모리를 할당하고
    단순 주소가 아닌 포인터가 가리키는 값을 복사해줌
    */
    m_pnData = new int;
    *m_pnData = *참조변수이름.m_pnData;
}

- 대입 연산자
연산자 Overloading

단순 대입 연산자 : l-value = r-value
ex)
int main()
{
    CMyData a(10);
    CMyData b(20);
    a = b; // shallow copy
}
이 코드 또한 shallow copy로 인한 실행 오류 발생
이를 해결하기 위해서 단순 대입 연산자의 동작 방식을 수정해야함
// 단순 대입 연산자 함수 정의
CMyData& operator=(const CMyData &rhs)
{
    *m_pnData = *rhs.m_pnData;
    return *this; // 객체 자신에 대한 참조를 반환
}

CMyData& : 반환형
operator= : 함수의 이름 operator+ 나 operator+= 등도 가능
(const CMyData &rhs) : 매개변수로 단순 대입 연산자의 r-value에 대한 참조자

위의 함수를 정의할 경우
b = a;가 b.operator=(a); 와 똑같이 작동함
