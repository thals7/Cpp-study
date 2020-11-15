// 연결 리스트 도입하여 입력 학생수 제한 없애기

#include <stdio.h>
#include <malloc.h> // malloc, free 함수 사용
#include <string.h> // strlen, memcpy 함수 사용

#define NAME_LENGTH 32

typedef struct _student
{
    int num;
    char *p_name;
    int kor, eng, math;
    int sum;
    float avg;

    struct _student *next; // 다음 학생의 정보가 저장된 메모리를 가리킬 포인터
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

void List(std *ap_data)
{
    printf("순번\t이름\t국어\t영어\t수학\t총점\t평균\n");

    while( NULL != ap_data )
    {
        printf("%d\t%s\t%d\t%d\t%d\t%d\t%f\n", ap_data->num, ap_data->p_name, ap_data->kor, ap_data->eng, ap_data->math, ap_data->sum, ap_data->avg);
        ap_data = ap_data->next; // 다음 학생 정보로 이동
    }
    
}

void Delete(std *ap_data) // 학생 이름을 저장하기 위해 할당한 메모리를 해제하는 함수
{
    // 다음 학생 정보로 이동하면 이전 학생의 주소를 알 수 있는 방법이 없어지고 이동 전에 삭제하면 다음 학생 정보로 이동이 불가
    // 따라서 구조체 포인터 변수를 하나 더 선언해서 삭제할 학생 정보의 주소를 기억하고 ap_data는 다음 학생 정보로 이동하게 함
    std *p_delete; // 학생 정보가 저장된 마지막 위치의 다음 위치에 대한 주소 구함
    while ( NULL != ap_data )
    {
        p_delete = ap_data; // 지워야할 메모리 주소 기억
        ap_data = ap_data->next; // 다음 학생의 정보로 이동

        free(p_delete->p_name); // 이름 저장하기 위해 할당한 메모리 해제
        free(p_delete); // 학생 정보를 저장하기 위해 할당한 메모리 해제        
    }
}

int main()
{
    std *head = NULL, *tail = NULL;
    int menu = 0;

    while (1)
    {
        printf("[ 메뉴 ]\n");
        printf("1 학생 추가\n2.목록 보기\n3.종료\n기능 선택 : ");
        scanf_s("%d", &menu);

        if (menu==1)
        {
            if (NULL != head) // 첫 학생이 아닌 경우
            {   // 새로운 학생 정보를 저장하기 위해 메모리 할당 후 할당된 주소를 마지막 학생의 next에 저장
                tail->next = (std *)malloc(sizeof(std));
                // 새 학생 정보를 저장할 메모리 주소를 tail에 저장 (tail은 새로 추가된 학생(마지막 위치)의 메모리를 가리킴)
                tail = tail->next;
            }
            else
            {
                // 첫 학생을 저장하기 위해 메모리 할당
                head = malloc(sizeof(std));
                // 학생이 한 명인 경우 그 학생이 시작이자 끝이 됨
                tail = head;
            }
            tail->next = NULL;
            
            Input(tail);
            
        }
        else if (menu==2)
        {
            List(head);
        }
       
        else if (menu==3) break;
    }
    Delete(head);
    return 0;

}