- 템플릿
모양자(틀)
어떤 형식, 규칙, 틀이 모두 채워져있을때 빈공간만 채우면 뭔가가 완성되는 방식
생산성을 증가시킬 수 있음

- 클래스 템플릿
클래스를 찍어내는 모양자
인스턴스 선언시 반드시 typename 을 기술해야함

ex)
template<typename T>
class CTest
{
public:
    ...
private:
    T m_nData;
};

int main()
{
    CTest<int> a;
    return 0;
}

클래스 템플릿 : 클래스를 찍어내는 틀 (생성될 클래스를 일반화시킨 것)
템플릿 클래스 : 클래스 템플릿으로부터 생성된 클래스

- 템플릿 매개변수
템플릿 선언시 형식을 여러개 작성 가능
Template<typename T, typename T2>
형식을 구체적으로도 작성 가능
Template<typename T, int nsize>

- 템플릿 특수화
포인터와 같이 특수한 형식이 있어 나머지 형식들과 전혀 다른 코드를 적용해야 하는 경우 -> 템플릿 특수화를 통해서 분리해서 처리

함수 템플릿 특수화
ex)
template<typename T>
T Add(T a, T b) { return a + b; }

template<> // 템플릿 특수화시 typename을 기술하지 않음
char* Add(char *pszLeft, char *pszRight)
{
    int nLenLeft = strlen(pszLeft);
    int nLenRight = strlen(pszRight);
    char *pszResult = new char[nLenLeft + nLenRight + 1];

    strcpy_s(pszResult, nLenLeft + 1, pszLeft);
    strcpy_s(pszResult + nLenLeft, nLenRgight + 1, pszRight);
    return pszResult;
}

int main()
{
    int nResult = Add<int>(3,4);
    std::cout << nResult << std::endl;

    char *pszResult = Add<char*>("Hello","World");
    std::cout << pszResult << std::endl;
    delete[] pszResult;
}
/* 출력 결과
7
HelloWorld
*/

- 클래스 템플릿과 상속
클래스 템플릿을 상속의 기본 클래스로 쓰려면?
template<typename T>
class CMyDataEx : public CMyData<T>

- 스마트 포인터
동적 할당한 인스턴스를 '자동'으로 삭제해주는 포인터
스마트 포인터는 모두 템플릿으로 구현되어 있음