// 기존 score_menu(2)에서 포인터 문법을 사용하여 input, list 함수의 코드 단순하게 만들기

#include <stdio.h>

#define MAX_COUNT   30
#define NAME_LENGTH 12

typedef struct _student
{
    char name[NAME_LENGTH];
    int kor, eng, math;
    int sum;
    float avg;
} std; // struct student = std (struct student 자료형을 std 자료형으로 치환)

void Input(std *ap_data, int i)
{
    printf("학생 정보를 입력하세요\n");
    printf("%d번째 학생의 이름 : ", i+1);
    scanf_s("%s", ap_data->name, NAME_LENGTH); // '->' 연산자는 *와 .를 하나로 합친 것 (ap_data->name = &ap_data->name[0])
    printf("%s의 국어 성적 : ", ap_data->name);
    scanf_s("%d", &ap_data->kor);
    printf("%s의 영어 성적 : ", ap_data->name);
    scanf_s("%d", &ap_data->eng);
    printf("%s의 수학 성적 : ", ap_data->name);
    scanf_s("%d", &ap_data->math);

    ap_data->sum = ap_data->kor + ap_data->eng + ap_data->math;
    ap_data->avg = (float) ap_data->sum/3;
}

void List(std *ap_data, int cnt)
{
    printf("순번\t이름\t국어\t영어\t수학\t총점\t평균\n");
    for(int i=0; i<cnt; i++)
    {
        printf("%d\t%s\t%d\t%d\t%d\t%d\t%f\n", i+1, ap_data->name, ap_data->kor, ap_data->eng, ap_data->math, ap_data->sum, ap_data->avg);
        ap_data++; //주소 연산이 줄어듦
    }
    
}

int main()
{
    std data[MAX_COUNT];
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
                Input(data + cnt, cnt);
                cnt++;
            }
        }
        else if (menu==2)
        {
            List(data, cnt);
        }
       
        else if (menu==3) return 0;
    }
}