- 정적 라이브러리
함수를 모아놓은 파일 (.lib 형식)

Hello.c --(Compile)-> Hello.obj --(Link)-> Hello.exe
소스 파일              오브젝트 파일          실행 파일
다른 소스 파일에서 TestFunc() 함수를 콜하고 싶다면 그 파일과 TestFunc() 함수가 들어있는 소스 파일을 결합하여 오브젝트 파일을 만들고 링크해야함
만약 TestFunc()가 들어있는 파일을 lib형식으로 만들어둔다면? 다른 오브젝트 파일과 손쉽게 결합하여 실행 파일을 만들 수 있음
코드의 재사용성, 생산성 증가

~~.lib 와 ~~.obj 는 매우 비슷함

ex)
#include <stdio.h>

// 코드에 main() 함수 존재하지 않음!
void PrintValue(int nPram)
{
    printf("PrintValue() : %d\n", nParam); 
}

void PrintString(const char *pszParam)
{
    printf("PrintString() : %s\n, pszParam");
}

위의 파일을 컴파일하면 ~~.lib 파일이 만들어짐
만들어진 라이브러리 파일의 경로는 ...\프로젝트이름\Debug\~~.lib 

#include <stdio.h>

void PrintValue(int);
#pragma coment(lib, "..\\Debug\\~~.lib")

int main()
{
    PrintValue(10);
    PrintString("Static Library Test");
    return 0;
}
/* 실행 결과
PrintValue() : 10
PrintString() : Static Library Test
*/

모듈화 프로그래밍 : 함수의 원형과 기능을 미리 정해두고(설계) 라이브러리 파일과 실행 파일을 따로 제작한 뒤 하나로 합체

헤더 파일의 작성
ex)
#pragma once

void PrintValue(int);
#Pragma comment(lib, "..\\debug\\~~.lib")

이렇게 라이브러리에 대한 정보를 헤더 파일에 넣어두고
실행 파일에
#include "..\프로젝트이름\~~.h"
를 적게 되면 실행 파일에서 void Print~~(~~.lib) 부분을 삭제해도 정상적으로 프로그램이 실행됨

- 동적 라이브러리
완성된 exe 파일을 실행할 때 포함시키는 라이브러리 (.dll 형식)

각 파일들이 요구되는 시점
~~.c : 소스 코드 제작
~~.h : 컴파일
~~.lib : 링크
~~.dll : 런타임