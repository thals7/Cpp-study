#include <stdio.h>

int main()
{
    int step, i, j;
    
    while (1)
    {
        printf("Input Step (0 -> Exit): ");
        scanf_s("%d", &step);
        
        if (step == 0) break;

        for (i=0; i<step; i++)
        {
            for (j=0; j<i; j++) printf(" ");
            for (j=0; j<step*2-i*2-1; j++) printf("*");
            printf("\n");
        }
        for (i=1; i<step; i++)
        {
            for (j=0; j<step-i-1; j++) printf(" ");
            for (j=0; j<2*i+1; j++) printf("*");
            printf("\n");
        }
    }
    return 0;
}