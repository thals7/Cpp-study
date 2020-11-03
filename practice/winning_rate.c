#include <stdio.h>

int main()
{
    int win, lose;
    double winning_rate;

    printf("승수 입력 : ");
    scanf_s("%d", &win);

    printf("패전수 입력 : ");
    scanf_s("%d", &lose);

    winning_rate = ((double)win / (double)(win + lose));
    printf("승률 = %.3lf\n", winning_rate);

    return 0;
}