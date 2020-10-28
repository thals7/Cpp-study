/*
다음 코드를 기반으로 '선택정렬로 알려진 버블정렬' 방식으로 오름차순 정렬합니다.
반드시 중첩된 for문 형식으로 구현해야 하며, 반복문에서 사용할 계수기 변수의 초깃값과 조건식에 유의하여 프로그램을 작성합니다.
만일 결과가 제대로 출력된다 해도 두 반복문의 계수기 초깃값(초기 수행식)과 조건식이 정답과 일치하지 않으면 틀린 것입니다.

#include <stdio.h>

int main(void)
{
    int aList[5] = {30, 40, 10, 50, 20};
    int i = 0, j = 0, nTmp = 0;
    
    //여기 코드 작성

    for(i = 0; i < 5; ++i)
        printf("%d\t", aList[i]);
    putchar('\n');
    return 0;
}
*/

#include <stdio.h>

int main(void)
{
    int aList[5] = {30, 40, 10, 50, 20};
    int i = 0, j = 0, nTmp = 0;
    
    for (i = 0; i <= 4; ++i)
    {
        for (j = i + 1; j < 5; ++j)
        {
            if (aList[i] > aList[j])
            {
                nTmp = aList[i];
                aList[i] = aList[j];
                aList[j] = nTmp;
            }
        }
    }

    for(i = 0; i < 5; ++i)
        printf("%d\t", aList[i]);
    putchar('\n');
    return 0;
}