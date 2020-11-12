- 연산자 함수
연산자를 이용하듯 호출할 수 있는 메서드 (클래스 내에서 생성 가능)

- 산술 연산자
"반환형식 operator기호(매개변수)"
ex)
class CMyData
{
public:
    int GetData() const { return m_nData; }
    int SetData(int nParam) { m_nData = nParam; }
    
    operator int() { return m_nData; }
    // 허용되는 변환 -> m_nData가 int이므로 CMyData 클래스를 int처럼 해석해도 되겠다는 명시적 선언

    void operator=(int nParam)
    {
        SetData(nParam);
    }

private:
    int m_nData = 0;
}

int main()
{
    CMyData a;
    CMyData b;
    
    a = 5;
    // a.operator=(5);
    // a.SetData(5);
    // 위의 세가지는 모두 같은 식임
    b = 6;

    std::cout << a + b << std::endl;
    return 0;
}
/* 출력 결과
11
*/
** 주의할 점
a = 5; 가 기본 산술 연산자가 아닌 함수라는 것
그러나 사용자의 입장에서는 기본 연산으로 보임 -> 즉 연산에 실패가 있어서는 안됨
따라서 예외 처리를 방식을 통해 사용자가 예외 상황을 처리하기 쉽도록 구현해 놓아야 함


CMyData c = a + b; 와 같은 식에 대해서는?

CMyData operator+(const CMyData &rhs)
{
    CMyData result;
    result.m_nData = this->m_nData + rhs.m_nData;
    return result;
}

CMyData operator=(const CMyData &rhs)
{
    m_nData = rhs.m_nData;
    return *this;
}