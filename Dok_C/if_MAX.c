/*
사용자로부터 세 정수를 입력받아 그중 가장 큰 수를 출력하는 프로그램을 작성합니다.
단, 삼항 연산자를 사용하지 말고 반드시 if문을 이용하여 작성하고, 앞서 삼항 조건 연산자에 대해 배울 때 서바이벌 방식으로 설명한 논리를 적용하여 프로그램을 완성합니다.
**서바이벌 방식: 변수를 하나 만들고 그 곳에 하나씩 집어넣으면서 비교하는 방식

입력 예:
    10
    30
    -10
출력 예:
MAX : 30
*/

#include <stdio.h>

int main(void)
{
    int max = 0;
    int a, b, c;

    scanf("%d %d %d", &a,&b,&c);
    
    if (max <= a)
        max = a;
    if (max <= b)
        max = b;
    if (max <= c)
        max = c;

    printf("MAX : %d", max);
}