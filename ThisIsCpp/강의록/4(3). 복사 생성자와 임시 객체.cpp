- 임시 객체
int a;
a = 3+4; 라는 식이 있을 때 먼저 3+4=7이라는 임시 결과가 나온 뒤 그 임시 결과가 a에 대입됨
a = 3+4; 안에 들어있는 int 인스턴스의 개수? 코드 수준에서 봤을땐 3(a,3,4)개 but 연산을 하고 난 뒤에는 4(a,3,4,7,)개
코드 수준에서 3개라 생각하고 설계했는데 실제로는 임시객체로 인해 설계보다 훨씬 많은 메모리를 써버리는 상황이 발생

l-value : 변수만 가능
r-value : 상수와 변수 가능 -> 연산의 임시 결과는 기본적으로 상수(즉, r-value)

r-value의 생명 주기 (언제 생성되고 언제 사라지는지)
프로그램이 판단할 때 계속 보관해야하는 상수는 보관, 아닌 것들은 삭제

- r-value 참조
연산의 임시 결과를 보관하기 위한 것
int &&식별자

z = a + 3 + b; 라고 했을 때 a+3의 임시 결과 T1이 생겨나고 T1+b를 해서 임시 결과 T2가 생겨남
이 때 T2가 결국은 연산의 최종 결과인 z이므로 T2라고 만들지 말고 원래 있던 z를 치환시켜 넣어버리자는 것

**함수의 반환 형식이 클래스인 경우? 반환될 때마다 복사 생성자가 호출됨
CTest a;
a = TestFunc2();
-> 이 때 TestFunc() 함수를 반환하면서 임시 객체가 생성되고 대입 연산이 끝나면서 소멸함

- 이동 생성자
ex)
class CData()
{
private:
    int *NumList;
    int Size;
public:
    explicit CData(int iSize) // 변환 생성자
    {
        size = iSize;
        NumList = new int[Size];
        cout << "변환 생성자 호출" << endl;
    }
    CData(const CData& rData) // 복사 생성자
    {
        NumList = new int[rData.size];
        cout << "복사 생성자 호출" << endl;
    }
    CData(CData&& rData) // 이동 생성자 (매개변수가 임시 객체)
    {
        NumList = rData.NumList;
        rData.NumList = nullptr;
        cout << "이동 생성자 호출" << endl;
    }
}

CData CreateData(int iSize)
{
    CData NewData(iSize);
    if (iSize > 10) return NewData;
    return NewData;
}

int main()
{
    CreateData(100);
    return 0;
}
/* 실행 결과
변환 생성자 호출
이동 생성자 호출
*/

NewData를 반환할때 임시 객체가 생성됨
이 임시 객체는 r-value이고 곧 사라질 예정 -> 이 임시 객체를 참조하면 r-value 참조가 되고 이동생성자가 호출됨
이미 CData NewData()에서 동적 할당을 받았으므로 이 주소값을 그대로 사용 (new 연산이 없는 shallow copy를 함)