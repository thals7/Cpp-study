/*
1~10까지의 총합(55)을 출력하는 프로그램을 작성합니다.
반드시 while문을 이용하여 1~10까지(계수)의 합을 모두 '누적'(반복대상)하는 방식으로 구현해야 합니다.
*/

#include <stdio.h>

int main()
{
    int num = 0;
    int sum = 0;
    while (num <= 10)
    {
        sum += num;
        num++;
    }
    printf("%d", sum);
}