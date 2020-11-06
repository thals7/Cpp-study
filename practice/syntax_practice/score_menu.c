#include <stdio.h>

#define MAX_COUNT   30
#define NAME_LENGTH 12

void Input(char name[][NAME_LENGTH], int kor[], int eng[], int math[], int sum[], float avg[], int i)
{
    printf("학생 정보를 입력하세요\n");
    printf("%d번째 학생의 이름 : ", i+1);
    scanf_s("%s", name[i], NAME_LENGTH);
    printf("%s의 국어 성적 : ", name[i]);
    scanf_s("%d", &kor[i]);
    printf("%s의 영어 성적 : ", name[i]);
    scanf_s("%d", &eng[i]);
    printf("%s의 수학 성적 : ", name[i]);
    scanf_s("%d", &math[i]);

    sum[i] = kor[i] + eng[i] + math[i];
    avg[i] = (float) sum[i]/3;
}

void List(char name[][NAME_LENGTH], int kor[], int eng[], int math[], int sum[], float avg[], int cnt)
{
    printf("순번\t이름\t국어\t영어\t수학\t총점\t평균\n");
    for(int i=0; i<cnt; i++)
    {
        printf("%d\t%s\t%d\t%d\t%d\t%d\t%f\n", i+1, name[i], kor[i], eng[i], math[i], sum[i], avg[i]);
    }
    
}

int main()
{
    char name[MAX_COUNT][NAME_LENGTH];
    int kor[MAX_COUNT], eng[MAX_COUNT], math[MAX_COUNT], sum[MAX_COUNT];
    float avg[MAX_COUNT];
    int menu, cnt = 0;

    while (1)
    {
        printf("[ 메뉴 ]\n");
        printf("1.성적 입력\n2.목록 보기\n3.종료\n기능 선택 : ");
        scanf_s("%d", &menu);

        if (menu==1)
        {
            if (cnt<MAX_COUNT)
            {
                Input(name, kor, eng, math, sum, avg, cnt);
                cnt++;
            }
        }
        else if (menu==2)
        {
            List(name, kor, eng, math, sum, avg, cnt);
        }
       
        else if (menu==3) return 0;
    }
}