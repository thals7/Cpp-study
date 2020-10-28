/*
출력 예와 같이 '*'를 출력하는 프로그램을 작성합니다.

출력 예:
                *

            *   *   *

        *   *   *   *   *

    *   *   *   *   *   *   *

*   *   *   *   *   *   *   *   *

*/

// 처음 생각했던 코드
// 변수끼리 더하기나 빼기로 식을 조립해서 쓸 생각을 못했더니 변수가 너무 많고 복잡한 느낌

#include <stdio.h>

int main()
{
    int cnt = 0;
    int i = 4;
    int j = 1;
    int k,l;

    while (cnt < 5)
    {   
        k = i;
        l = j;
        while (k > 0)
        {
            printf("\t");
            k--;
        }
        while (l > 0)
        {
            printf("*\t");
            l--;
        }
        printf("\n");
        cnt++;
        i--;
        j += 2;
    }
}

// for 문 + 식을 만들어서 풀어보기

#include <stdio.h>

int main()
{
    int i,j;

    for (i=0; i<5; i++)
    {
        for (j=0; i+j<4; j++)
            printf("\t");
        for (j=0; j<2*i+1; j++)
            printf("*\t");
        printf("\n");
    }
}