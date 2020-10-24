#include <stdio.h>
#include <windows.h>

int main(void)
{
    system("chcp 65001"); //gcc 한글 깨짐 방지

    int nAge = 0;
    printf("나이를 입력하세요: ");
    scanf("%d", &nAge);
    getchar(); //scanf 함수는 값을 입력하고 난 뒤 친 엔터 \n까지 입력 버퍼에 저장하기 때문에 그 뒤에 또다른 입력 함수를 실행하면 버퍼에 남아있는 \n을 받아오고 그냥 넘어가게 됨. 따라서 getchar(); 함수로 버퍼에 남아있던 \n을 비워야 함. 그렇게 함으로써 다음에 실행될 fgets()에서 정상적으로 값을 입력할 수 있음.

    char szName[12] = {0};
    printf("이름을 입력하세요: ");
    fgets(szName, sizeof(szName), stdin);


    printf("%d, %s\n", nAge, szName);
    return 0;
}