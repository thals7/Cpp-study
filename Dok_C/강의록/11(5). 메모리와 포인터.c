- 다차원 배열
배열의 배열

**다차원 배열에 대한 포인터 선언
char(*)[12] : char가 12개인 배열에 대한 포인터

ex)
int main(int argc, char* argv[])
{
    char astrList[2][12] = {"Hello", "World"};
    char (*pstrList)[12] = astrList;

    puts(pstrList[0]);
    puts(pstrList[1]);
    return 0;
}
/*
실행 결과 :
Hello
World
*/
위의 코드에서 자주 범하는 오류가 char (*pstrList)[12] = astrList;를 char* *pstrList = astrList;로 쓰는 것
후자는 포인터 *pList가 가리키는 대상이 char*, 즉 char 포인터가 여러개 있는 배열이라는 뜻
그러나 astrList는 포인터 배열이 아닌 다차원 배열이므로 후자는 잘못된 식임

- 정적 변수
데이터 영역에 메모리를 할당하여 프로그램이 끝나기 전까지 메모리가 해제되지 않게 하되, 선언된 위치에 따라 변수의 접근성을 조절할 수 있음

ex)
void TestFunc()
{
    int nData = 10; // static int nData = 10; (정적 변수)
    printf("%d\n", nData++);
}

int main()
{
    TestFunc();
    TestFunc();
    TestFunc();
}
위의 코드를 실행할 경우 TestFunc 함수가 호출될 때마다 nData의 값이 10으로 초기화되므로 실행 결과는 10 10 10 이 나옴
But! int nData = 10; 앞에 static 이라고 써서 정적 변수 선언을 해버리게 되면 실행 결과는 10 11 12 가 됨
예시 코드에서 나온 정적 변수는 함수 내부 안에서만 사용 가능한 지역 변수이나 전역 변수를 선언한 것과 같은 효과를 가짐
전역 변수와 정적 변수는 내부적으로는 비슷하나 문법적으로(함수 선언 위치 등) 차이가 있음

- 레지스터 변수
RAM이 아니라 CPU의 일부인 레지스터의 메모리를 사용하는 변수
메모리의 주소는 CPU의 입장에서 관리 대상인 것들에 대한 관리 방법임
그러나 레지스터는 고유한 이름을 가짐
따라서 주소를 가지지 않고 이름으로 식별함 (주소연산자 & 사용 불가능)