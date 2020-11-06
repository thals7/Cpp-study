#include <iostream>

- 메모리 동적 할당
C의 malloc()의 경우 오로지 확보할 공간의 크기에만 관심 있음
메모리의 '용도'에 대한 개념은 전혀 없음
포인터의 선언이 주관적이고 자유도가 높음
-> 초보자에게는 위험할 수도 있음(안전장치X)

가상 메모리 체계로의 변화
메모리 할당은 없는 것이 생겨나게 하는 것이 아님
이미 있는 것에서 사용 허가를 받는 것(임대)

OS가 메모리를 통제하기 시작 -> 할당의 실패 가능성 매우 적음

malloc()은 반환값을 보고 성공/실패를 나눔 -> 이러한 개념을 예외처리 하다 보니 대부분의 경우 성공으로 처리 -> 연산자의 성격을 가진 함수가 됨 -> new

new 자료형;
(1)메모리 동적 할당
(2)class의 생성자(함수)를 호출

ex)
int main()
{
    //C
    int *pnData = (int*)malloc(sizeof(int));
    free(pnData);

    //C++
    int *pnNewData = new int;
    delete pnNewData;

    return 0;
}

자료형을 선언함으로써 메모리의 크기 개념을 미리 포함함
동적 할당시 사용자가 크기 문제를 신경 쓸 필요 X

배열의 경우
C는 (int*)malloc(sizeof(int) * 5);
C++은 new int[5]; -> 지울때 delete [] pnNewData; 이렇게 배열로 지워야함

- 참조자
일종의 별명
어떤 변수에 대한 또 다른 이름이 생긴 것과 같음
ex)
int nData(10);
std::cout << nData << std::endl;

int &rData = nData; // == int &rData(nData);

rData = 5;
std::cout << nData << std::endl;
/*
실행 결과
10
5
*/
** 이미 선언된 변수의 앞에 & 연산자가 오면 주소 값의 반환을 명령하는 뜻이지만
새로 선언되는 변수의 이름 앞에 오면 참조자의 선언을 뜻함

참조자를 사용하는 이유?
포인터의 문제점 -> 포인터 자체가 '변수'(값이 변할 수 있음)
ex)
int nData = 10;
int nNewData = 20; 일 때

int *pnData = &nData;
*pnData = 5; 를 하면 nData의 값이 바뀜

pnData = &nNewData; 그러나 이렇게 선언하는 순간
*pnData = 5; 가 nData가 아닌 nNewData의 값을 바뀌게 함

But! 참조자를 사용하는 경우
int &rData = nNewData; 를 선언하는 순간
rData가 nNewData에 대한 참조라는 사실은 절대 변하지 않음
-> 변하지 않는 포인터

const int * pnData = &a; 포인터가 가리키는 대상이 상수화됨
int * const pnData = &a; pnData가 상수화됨 (==참조자)

- r-value 참조
왜 필요한가?
이름이 없는 임시 객체 -> 성능 저하나 오류 발생의 원인
r-value 참조는 임시 객체를 처리하는 문제와 직접적 관련 있음

- 범위 기반 for 문
ex)
int aList[7] = {40, 30, 10, 20, 50};
// 기존 for문
for (int i = 0; i < 5; ++i)
// 배열 요소의 개수가 변경되었을때 for문을 일일히 고쳐야하거나 index 계산을 실수할 가능성 등의 문제가 있음

// 범위 기반 for 문
for (auto n : aList)
    printf("%d\t", n);
// 알아서 변경된 배열 요소 개수만큼 loop를 돎