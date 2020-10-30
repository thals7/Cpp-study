- 함수 고급 이론
Binding : 두 함수가 호출자-피호출자 관계로 묶이는 것

- 참조 호출 (Call by reference)
ex)
void TestFunc(int *pnParam)
{
    *pnParam = 10;
}

int main()
{
    int nData = 0;
    TestFunc(&nData);

    printf("%d\n", nData);
    return 0;
}
/*
실행 결과 :
10
*/
함수로 매개 변수를 전달할 때 메모리의 값이 아닌 주소를 전달

- Stack
매개변수는 오른쪽부터 스택에 그리며 새 스코프는 기존 스택 위에 그림
만일 main() 함수가 다른 사용자 정의 함수를 호출할 경우 매개변수도 스택에 그려야 하는데 반드시 오른쪽 매개변수부터 먼저 Push하는 것으로 그려야함
ex)
int nResult;
nResult = *TestFunc();
printf("%d\n", nResult);

            | 10 | nData
            ------
            | .. |
            | .. |
            ------
 TestFunc() |    | nParam
            ------
     main() |    | nResult
            ------
TestFunc() 함수를 반환하는 경우?
stack 안에 쌓이는 정보는 그대로 남아있으나 개념상 main() 위에 쌓여있던 모든 것들이 없어짐

scope가 닫히는 순간 스택에 쌓아뒀던게 사라짐

- 재귀 호출
"반복문 + Stack" 을 합한 것

- 문자열 처리 함수
Buffer overflow의 문제
고정길이 메모리에 가변길이 문자열을 담는 방법
이름을 입력 받는 경우 사용자가 입력하는 문자열의 길이를 어떻게 알 것인가? 만약 가변길이가 고정길이를 over 한다면?
-> Overrun 문제가 일어날 경우 원격코드실행 등의 결함이 일어날 수 있으므로 반드시 가변길이 Data를 고정길이 메모리에 담기 전 길이를 검사해야함

MBCS vs UNICODE
MBCS : Multi-Bytes Character Sets
       영문 한 글자가 1바이트
       한글 한자가 2바이트
       문자열은 NULL(0)로 끝남
       필요 메모리가 영문은 (문자열의 길이 + 1) 한글 한자는 (문자열의 길이*2 + 1)로 다름 -> 프로그램 유지보수 측면에서 비효율적
UNICODE : 영문, 한글, 한자 관계없이 모두 한 글자당 2바이트
          문자열의 끝은 NULL 2개
          메모리를 일부 낭비하더라도 문자열 처리에 대하여 일관성을 유지 ((문자열의 길이 + 1)*2)
          자료형으로 char 대신 wchar_t를 사용
          문자열 상수의 경우 " 앞에 L 붙여서 사용 (ex. L"String", L"%s\n")