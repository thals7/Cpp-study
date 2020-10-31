#include <stdio.h>

int main()
{
    int aList[5] = { 40, 20, 50, 30, 10 };
    int *paList = aList;

    printf("%d\n", &aList);
    printf("%d\n", paList);
    printf("%d\n\n", &(*paList)); // 결과값이 6422280으로 동일

    printf("%d\n", *paList +1);
    printf("%d\n\n", aList[0]+1); // 결과값이 41로 동일

    printf("%d\n", &*(aList + 1));
    printf("%d\n", paList +1);
    printf("%d\n\n", aList +1); // 6422284로 동일

    printf("%d\n\n", &aList +1); //aList 전체에 +1을 한 것이므로 4*5=20 만큼 옮겨간 6422300이 됨
}