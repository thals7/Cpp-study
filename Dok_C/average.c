/*
제한시간 : 15분 이내

사용자로부터 두 정수를 입력받아 두 수의 평균을 계산하여 출력하는 예제 작성
사용자 입력은 scanf() 함수를 통해 받고 출력은 printf() 이용
단, 반드시 소수점 둘째 자리까지만 표시해야 하며, 변수는 2개만 선언

입력 예:
    두 정수를 입력하세요.: 10 20
출력 예:
    AVG : 15.00
*/
#include <stdio.h>

int main(void)
{
    double a;
    double b;
    printf("두 정수를 입력하세요.: ");
    scanf("%lf %lf", &a, &b);
    printf("AVG : %.2f", (a+b)/2);
}