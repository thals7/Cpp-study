/*
사용자로부터 2~9 사이의 정수를 입력받아 해당 정수의 구구단을 출력하는 프로그램을 작성합니다.
반드시 while문을 이용하여 작성해야 하며 한 행을 출력하느 코드가 9번 반복되는 형식이 되어야 합니다.
사용자가 입력한 값이 2보다 작거나 9보다 크면 "ERROR"라고 출력합니다.

입력:
    2
출력:
    2 * 1 = 2
    2 * 2 = 4
    ...
    2 * 9 = 18
*/

#include <stdio.h>

int main()
{
    int num;
    int cnt = 1;
    printf("2 ~ 9 사이의 숫자 하나를 입력하세요. : ");
    scanf("%d", &num);

    if ( num < 2 || num > 9)
        printf("ERROR");
    else
    {
        while (cnt <= 9)
        {
            printf("%d * %d = %d\n", num, cnt, num*cnt);
            cnt++;
        }
    }
    return 0;
}