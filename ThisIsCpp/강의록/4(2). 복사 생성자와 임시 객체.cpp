- 묵시적 변환

변환 생성자
매개변수가 한개인 생성자
불필요한 임시 객체를 만들어냄으로써 프로그램의 효율을 갉아먹는 원인이 됨
ex)
/// 제작자 코드
class CTest
{
public:
    CTest() // 디폴트 생성자
    {
        m_nData = new int(5);
    }
    CTest(int nParam) // 변환 생성자
    {
        m_nData = new int(nParam)
    }
}
/// 사용자 코드
void TestFunc(const CTest &Param)
{
    cout << param.GetData() << endl;
}
int main()
{
    CTest a; // 디폴트 생성자
    CTest b(5); // 변환 생성자

    TestFunc(5); 
    return 0;
}
위의 코드에서 TestFunc(5); 는 const CTest &param = 5; 와 같음
문제는 왼쪽의 자료형은 CTest 에 대한 참조 형식인데 오른쪽은 int형임 -> 자료형이 맞지 않음 But! 오류 발생 X
Why? CTest가 int 자료형에 대한 변환 생성자를 제공하기 때문에 컴파일러가 자동으로 임시 객체를 생성한후 이 임시 객체에 대한 참조가 TestFunc() 함수로 전달되도록 한 것임
즉 TestFunc(5); 는 TestFunc( CTest(5) ); 와 동일

묵시적 변환 생성자 호출 차단
변환 생성자 앞에 explicit 를 붙이면 묵시적으로 생성되는 객체를 막을 수 있음

허용되는 변환
형변환 연산자를 만들어 넣으면 CTest 형식을 int 자료형으로 변환 가능
ex)
class CTest 안에
operator int(void)
{
    return m_nData;
}
를 넣고
int main()
{
    CTest a(5);
    cout << a << endl;
}
실행해보면 5가 정상적으로 출력됨