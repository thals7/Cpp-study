#include <stdio.h>

int main()
{
    int kor, eng, math, sum;
    float avg;

    printf("국어, 영어, 수학 성적을 입력하세요 : ");
    scanf_s("%d %d %d", &kor, &eng, &math);

    sum = kor + eng + math;
    avg = sum/3.0f; // 실수 형식으로 연산하기 위해

    printf("국어 : %d, 영어 : %d, 수학 : %d\n", kor, eng, math);
    printf("총점 : %d, 평균 : %f\n", sum, avg);

    return 0;
}