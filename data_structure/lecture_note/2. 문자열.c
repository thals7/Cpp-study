문자열
- char 타입의 배열의 각 칸마다 문자 하나씩 저장됨
- 마지막 칸은 null character('\0')로 문자열의 끝을 표시하는 역할
- 따라서 배열의 크기가 문자열의 길이보다 적어도 1만큼 길어야 함

- C언어는 문자열을 생성하는 편리한 방법을 제공
  char str[] = "hello";
  // 컴파일러가 자동으로 "" 안의 문자 개수를 세서 str 배열의 크기를 6으로 만들어줌
  // str [] 배열 안의 값 (hello)를 바꿀 순 있지만 str이 전혀 다른 배열을 가리키도록 할 수는 없음
  char *str = "hello";
  // 문자열의 수정이 불가능 (string literal)

string.h 라이브러리 함수
- strcpy : 문자열 복사
  strlen : 문자열 길이
  strcat : 문자열 합치기
  strcmp : 문자열 비교

문자열들의 저장
- ex)
int main()
{
    char *words[100];
    int n = 0; // number of strings
    char buffer[BUFFER_SIZE];

    while (n<4 && scanf("%s", buffer) != EOF) // 배열의 이름이 실제 배열의 주소를 저장하고 있는 포인터 변수이기 때문에 &를 붙여줄 필요가 없음
    {
        words[n] = strdup(buffer);
        // strdup : 매개변수로 하나의 문자열을 받아서 이 문자열의 복제본의 주소를 반환함
        n++;
    }

    for (int i=0; i<4; i++)
        printf("&s\n", words[i]);
    
    return 0;
}

파일로부터 읽기
int main()
{
    FILE *fp = fopen("input.txt", "r"); // 읽기
    char buffer[100];
    while (fscanf(fp, "%s", buffer) != EOF) 
        printf("%s", buffer);
    fclose(fp);

    return 0;
}

파일 읽고 쓰기
int main()
{
    FILE *in_fp = fopen("input.txt", "r"); // 읽기
    FILE *out_fp = fopen("output.txt", "w"); // 쓰기
    char buffer[100];
    while (fscanf(in_fp, "%s", buffer) != EOF)
        fprintf(out_fp, "%s", buffer);
    fclose(in_fp);
    fclose(out_fp);

    return 0;
}