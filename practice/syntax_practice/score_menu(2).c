// 기존 score_menu 파일에 학생 정보 관련 변수들이 들어있는 구조체를 추가하여 코드를 깔끔하게 정리하기

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

void Input(std data[], int i)
{
    printf("학생 정보를 입력하세요\n");
    printf("%d번째 학생의 이름 : ", i+1);
    scanf_s("%s", data[i].name, NAME_LENGTH);
    printf("%s의 국어 성적 : ", data[i].name);
    scanf_s("%d", &data[i].kor);
    printf("%s의 영어 성적 : ", data[i].name);
    scanf_s("%d", &data[i].eng);
    printf("%s의 수학 성적 : ", data[i].name);
    scanf_s("%d", &data[i].math);

    data[i].sum = data[i].kor + data[i].eng + data[i].math;
    data[i].avg = (float) data[i].sum/3;
}

void List(std data[], int cnt)
{
    printf("순번\t이름\t국어\t영어\t수학\t총점\t평균\n");
    for(int i=0; i<cnt; i++)
    {
        printf("%d\t%s\t%d\t%d\t%d\t%d\t%f\n", i+1, data[i].name, data[i].kor, data[i].eng, data[i].math, data[i].sum, data[i].avg);
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
                Input(data, cnt);
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