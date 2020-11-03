// 나머지 연산자 (%) 를 쓰지 않고 짝수 홀수를 알아내는 방법?

#include <stdio.h>

int main()
{
    unsigned int num;

    printf("Input Number : ");
    scanf_s("%u", &num);
    
    // 비트 AND 연산자 사용
    if (num & 0x01) printf("Odd Number\n");
    else printf("Even Number\n");
}