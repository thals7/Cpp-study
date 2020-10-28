#include <stdio.h>

int main()
{
    int anData[3][4] = {0}; // 각 요소가 int형인 3행 4열의 2차원 배열 선언
    int i = 0, j = 0, nCounter = 0;

    for (i = 0; i < 3; ++i)
    {
        for (j = 0; j < 4; ++j)
        {
            anData[i][j] = ++nCounter; // 배열 연산을 2회 중복하여 2차원 배열의 각 요소에 값 대입
        }
    } // 중첩된 반복문으로 2차원 배열의 전체 요소를 채움
      // 외부 반복문은 행의 인덱스를 증가시키며 내부 반복문은 열의 인덱스를 증가시킴

    for (i = 0; i < 3; ++i)
    {
        for (j = 0; j < 4; ++j)
        {
            printf("%d\t", anData[i][j]);
        } // 값이 채워진 2차원 배열을 3행 4열의 형태로 출력하는 중첩된 반복문
        
        printf("\n");
    }

}