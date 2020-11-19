전화번호부.v3
: 배열 재할당, 라인 단위 입력과 문자열 tokenizing

기능
- 저장된 사람의 수가 배열의 용량 초과시 동적 메모리 할당으로 배열의 크기를 키움
- 잘못된 명령어에 대해 적절한 반응 추가
- 사용자의 입력을 단어가 아닌 라인 단위로 받아옴

문자열 tokenizing
- 구분 문자(delimeter)를 이용하여 하나의 긴 문자열을 작은 문자열들로 자르는 일
- 잘라진 작은 문자열들을 보통 token이라고 부름

strtok을 이용한 문자열 자르기
ex)
int main()
{
    char str[] = "now # is the time 3 to start preparing ### for the exam#";
    char delim[] = "#";
    char *token;

    token = strtok(str, delim);

    while (token != NULL )
    {
        printf("next token is : %s:%d\n", token, strlen(token));
        token = strtok(NULL, delim);
    }
    return 0;
}
/* 실행 결과
next token is: now :4
next token is:  is the time :13
next token is:  to start preparing :20
next token is:  for the exam:13
*/
- strtok은 원본 문자열을 변화시킴 (delimeter 자리에 '\0'을 삽입)
- 만약 원본 문자열이 보존되어야 한다면 복사한 후 strtok을 해야함
- strtok은 새로운 배열을 생성하지 않음 (strdup과 다름)

만약 str을 배열이 아닌 포인터로 선언하게 되면?
strtok() 작동하지 않음 -> str을 포인터로 선언하게 되면 string literal (문자열 상수)가 되어 원본 문자열을 변화시킬 수 없는 상태가 됨
따라서 배열로 선언하면 char array가 되고 문자열을 변화시켜 strtok이 정상적으로 작동 가능


전화번호부.v4
: 더 많은 항목, 구조체

기능
- 각 사람에 대해서 이름, 전화번호, 이메일 주소, 그룹 지정 가능 (단, 이름을 제외한 다른 항목은 비워둘 수 있음)
- 구조체를 만들어 한 사람에 대한 여러 데이터들을 모아서 저장