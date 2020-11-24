// 인프런 - C로 배우는 자료구조 및 여러가지 예제 실습
// 연결리스트 - 다항식을 참조

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_POLYS
#define BUFFER_LENGTH

typedef struct term // 오른쪽 다항식의 각 항 부분
{
    int coef; // 계수
    int expo; // 지수
    struct term *next;
} Term;

typedef struct polynomial // f(x) 부분
{
    char name;
    Term *first; // 첫번째 항의 주소를 가짐
    int size = 0; // 항의 개수
} Polynomial;

Polynomial *polys[MAX_POLYS]; // polys는 다항식들에 대한 포인터의 배열
int n = 0; // 저장된 다항식의 개수

Term *create_term_instance()
{
    Term *t = (Term *)malloc(sizeof(Term));
    t->coef = 0;
    t->expo = 0;
    return t;
}

Polynomial *create_polynomial_instance(char name) // 다항식 객체 생성시 이름을 지정
{
    Polynomial *ptr_poly = (Polynomial *)malloc(sizeof(Polynomial));
    ptr_poly->name = name;
    ptr_poly->first = NULL;
    ptr_poly->size = 0;
    return ptr_poly;
} // 객체를 생성하고 기본값으로 초기화해주는 함수

void add_term(int c, int e, Polynomial *poly) // 다항식에 항을 추가하는 함수
{
    if (c == 0) return;
    Term *p = poly->first, *q = NULL;
    while ( p != NULL && p->expo > e )
    {
        q = p;
        p = p->next;
    }
    if ( p != NULL && p->expo == e ) // 동일 차수의 항이 존재하는 경우
    {
        p->coef += c;
        if ( p->coef == 0 ) // 더했더니 계수가 0이 되는 경우
        {
            if ( q == NULL ) poly->first = p->next; // q가 NULL이면 (e가 다항식 첫번째 항의 지수와 같으면) 첫번째 노드를 삭제
            else q->next = p->next; // 그 외에는 q의 다음 노드를 삭제 
            poly->size--;
            free(p); // 불필요해진 노드 p를 free시킴
        }
        return;
    }
    Term *term = create_term_instance();
    term->coef = c;
    term->expo = e;
    if ( q == NULL ) // 다항식의 맨 앞에 삽입하는 경우
    {
        term->next = poly->first;
        poly->first = term;
    }
    else // q의 뒤, p의 앞에 삽입 (p는 null일 수도 있음)
    {   
        term->next = p;
        q->next = term;
    }
    poly->size++;
}

int eval(Polynomial *poly, int x) // 다항식의 값을 계산하는 함수
{
    int result = 0;
    Term *t = poly->first;
    while ( t != NULL )
    {
        result += eval(t, x); // 각각의 항의 값을 계산하여 더함
        t = t->next;
    }
    return result;
}

int eval(Term *term, int x) // 하나의 항의 값을 계산하는 함수
{
    int result = term->coef;
    for ( int i=0; i<term->expo; i++)
        result *= x;
    return result;
}

void print_poly(Polynomial *p)
{
    printf("%c=", p->name);
    Term *t = p->first;
    while ( t != NULL )
    {
        print_term(t);
        printf("+");
        t = t->next;
    }
}

void print_term(Term *pTerm)
{
    printf("%dx^%d", pTerm->coef, pTerm->expo);
} // 미완성 함수. 만약 coef가 음수라면? coef나 expo가 1일때 굳이 표현해야 하는지? 등등.

int read_line(char str[], int limit)
{
    int ch, i = 0;
    while ((ch = getchar()) != '\n')
        if ( i < limit-1 )
            str[i++] = ch;
    str[i] = '\0';
    return i;
}

void process_command()
{
    char command_line[BUFFER_LENGTH];
    char copied[BUFFER_LENGTH];
    char *command, *name, *x;

    while (1)
    {
        printf("$ ");
        if (read_line(command_line, BUFFER_LENGTH) <= 0) continue;
        strcpy(copied, command_line); // 입력 라인을 복사해둠
        command = strtok(command_line, " ");
        if (strcmp(command, "print") == 0 )
        {
            name = strtok(NULL, " ");
            if (name == NULL)
            {   
                printf("Invalid arguments.\n");
                continue;
            }
            handle_print(name[0]);
        }
        else if (strcmp(command, "calc") == 0 )
        {
            name = strtok(NULL, " ");
            if (name == NULL)
            {   
                printf("Invalid arguments.\n");
                continue;
            }
            x = strtok(NULL, " ");
            if (x == NULL)
            {   
                printf("Invalid arguments.\n");
                continue;
            }
            handle_calc(name[0], x);
        }
        else if (strcmp(command, "exit") == 0 ) break;
        else handle_definition(copied); // 다항식을 입력받아 정의하는 함수
    }
}

void handle_print(char name)
{
    for (int i =0; i<=n; i++)
    {
        if (strcmp(polys[i], name) == 0)
            print_poly(name);
    }
    printf("There is no %s.\n", name);
}

void handle_calc(char name, char *x_str)
{
    for (int i =0; i<=n; i++)
    {
        if (strcmp(polys[i], name) == 0)
            eval(name, atoi(x_str));
    }
    printf("There is no %s.\n", name);
}

void handle_definition(char *expression) // 새로운 다항식을 정의하는 함수. expression은 사용자가 입력한 문자열 전체
{
    erase_blanks(expression); // 문자열에서 공백 제거
    char *f_name = strtok(expression, "="); // 다항식의 이름(좌변)
    if (f_name == NULL || strlen(f_name) != 1)
    {
        printf("Unsupported command.");
        return;
    }
    char *exp_body = strtok(NULL, "="); //다항식(우변)
    if (exp_body == NULL || strlen(exp_body) <= 0)
    {
        printf("Invalid expression format.--");
        return;
    }
    if (exp_body[0]>= 'a' && exp_body[0] <= 'z' && exp_body[0] != 'x')
    {
        char *former = strtok(exp_body, "+");
        if (former == NULL || strlen(former) != 1)
        {
            printf("Invalid expression format.");
            return;
        }
        char *later = strtok(NULL, "+");
        if (later == NULL || strlen(later) != 1)
        {
            printf("Invalid expression format.");
            return;
        }
        Polynomial *pol = create_by_add_two_polynomials(f_name[0], former[0], later[0]);      
        if (pol == NULL)
        {
            printf("Invalid expression format.");
            return;
        }
        insert_polynomial(pol);
    }
    else // 새로 정의
    {
        Polynomial *pol = create_by_parse_polynomial(f_name[0], exp_body);
        if (pol == NULL)
        {
            printf("Invalid expression format.");
            return;
        }
    }
    
}

void erase_blanks(char expression[])
{
    char prev = '\0'; // 직전에 복사한 문자를 기억
    int i = 0, j = 0;
    char compressed[MAX];
    while (expression[i] == ' ') i++;
    while (expression[i] != '\0')
    {
        if (expression[i] != ' ' || prev != ' ')
            compressed[j++] = expression[i];
        prev = expression[i];
        i++;
    }
    if (prev == ' ') compressed[--j] = '\0';
    else compressed[j] = '\0';
    strcpy(expression, compressed);
    return expression;
}