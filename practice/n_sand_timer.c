#include <stdio.h>

int main()
{
    int step, i, j;
    while (1)
    {
        printf("Input Step : ");
        scanf_s("%d", &step);

        for (i=0; i<step; i++)
        {
            for (j=0; j<i; j++) printf(" ");
            for (j=i+1; j<step; j++) printf("%d", j);
            for (j=step; j>=i+1; j--) printf("%d", j);
            printf("\n");
        }
        for (i=1; i<step; i++)
        {
            for (j=step; j>i+1; j--) printf(" ");
            for (j=step-i; j<step; j++) printf("%d", j);
            for (j=step; j>step-i-1; j--) printf("%d", j);
            printf("\n");
        }
    }
    return 0;
}