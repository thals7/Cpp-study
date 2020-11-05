#include <stdio.h>

#define MAX_COUNT   5
#define NAME_LENGTH 12

int main()
{
    char name[MAX_COUNT][NAME_LENGTH];
    int kor[MAX_COUNT], eng[MAX_COUNT], math[MAX_COUNT], sum[MAX_COUNT];    
    float avg[MAX_COUNT];
    int i;

    printf("학생 정보를 입력하세요.\n");
    
    for (i = 0; i < MAX_COUNT; i++)
    {
        printf("%d번째 학생의 이름 : ", i+1);
        scanf_s("%s", name[i], NAME_LENGTH);
        printf("%s의 국어 성적 : ", name[i]);
        scanf_s("%d", &kor[i]);
        printf("%s의 영어 성적 : ", name[i]);
        scanf_s("%d", &eng[i]);
        printf("%s의 수학 성적 : ", name[i]);
        scanf_s("%d", &math[i]);
    }

    printf("\n순번\t이름\t국어\t영어\t수학\t총점\t평균\n");
    for (i = 0; i < MAX_COUNT; i++)
    {
        sum[i] = kor[i] + eng[i] + math[i];
        avg[i] = (float) sum[i]/3;

        printf("%d\t%s\t%d\t%d\t%d\t%d\t%f\n", i+1, name[i], kor[i], eng[i], math[i], sum[i], avg[i]);
    }
    return 0;
}