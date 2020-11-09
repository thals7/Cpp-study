// 이름의 최대 길이 늘리고 malloc() 함수 추가

#include <stdio.h>
#include <malloc.h> // malloc, free 함수 사용
#include <string.h> // strlen, memcpy 함수 사용

#define MAX_COUNT   30
#define NAME_LENGTH 32

typedef struct _student
{
    int num;
    char *p_name;
    int kor, eng, math;
    int sum;
    float avg;
} std;

void Input(std *ap_data)
{
    char temp[NAME_LENGTH]; // 이름을 저장할 임시 메모리

    printf("학생 정보를 입력하세요.\n");
    printf("학번 : ");
    scanf_s("%d", &ap_data->num);

    printf("이름 : ");
    scanf("%s", temp, NAME_LENGTH); // 이름을 임시 메모리에 입력받음
    int len = strlen(temp) + 1; // 입력받은 이름의 길이 구함 (NULL문자 포함)
    ap_data->p_name = (char *)malloc(len); // 이름의 길이만큼 Heap에 메모리 할당
    memcpy(ap_data->p_name, temp, len); // 할당된 메모리에 문자열 복사

    printf("국어 성적 : ");
    scanf_s("%d", &ap_data->kor);
    printf("영어 성적 : ");
    scanf_s("%d", &ap_data->eng);
    printf("수학 성적 : ");
    scanf_s("%d", &ap_data->math);

    ap_data->sum = ap_data->kor + ap_data->eng + ap_data->math;
    ap_data->avg = (float) ap_data->sum/3;
}

void List(std *ap_data, int cnt)
{
    printf("순번\t이름\t국어\t영어\t수학\t총점\t평균\n");

    std *p_end_data = ap_data + cnt;
    while( ap_data < p_end_data )
    {
        printf("%d\t%s\t%d\t%d\t%d\t%d\t%f\n", ap_data->num, ap_data->p_name, ap_data->kor, ap_data->eng, ap_data->math, ap_data->sum, ap_data->avg);
        ap_data++; // 다음 학생 정보로 이동
    }
    
}

void Delete(std *ap_data, int cnt) // 학생 이름을 저장하기 위해 할당한 메모리를 해제하는 함수
{
    std *p_end_data = ap_data + cnt;
    while ( ap_data < p_end_data )
    {
        free(ap_data->p_name); // 메모리 해제
        ap_data++;
    }
}

int main()
{
    std data[MAX_COUNT];
    int menu, cnt = 0;

    while (1)
    {
        printf("[ 메뉴 ]\n");
        printf("1 학생 추가\n2.목록 보기\n3.종료\n기능 선택 : ");
        scanf_s("%d", &menu);

        if (menu==1)
        {
            if (cnt<MAX_COUNT)
            {
                Input(data + cnt);
                cnt++;
            }
        }
        else if (menu==2)
        {
            List(data, cnt);
        }
       
        else if (menu==3) break;
    }
    Delete(data, cnt);
    return 0;

}