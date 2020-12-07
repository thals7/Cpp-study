Infix Expression into Postfix Expression
(1) 괄호가 필요 없음
(2) 연산자는 등장 순서대로 계산됨
(3) 피연산자의 순서는 Infix와 Postfix 모두 동일
(4) 무조건 연산자가 뒤로 감

후위표기식으로 변환
(1) 괄호가 없는 경우

- 중위 표기식을 처음부터 순서대로 읽으면서
- 피연산자는 즉시 출력
- 모든 연산자는 일단 스택에 push
- 단, 이때 스택 내에 우선순위가 자신보다 더 높은 연산자가 있으면 pop하여 출력한 후에 push
- 수식이 종료되면 스택에 있는 모든 연산자를 pop하여 출력
- 연산자 stack과 피연산자 stack 두 개가 필요

ex)
#include "stackADT.h"

static char OPERATORS[] = "+-*/";
static int PRECEDENCE[] = {1, 1, 2, 2}; // 연산자 +,-,*,/ 의 우선순위를 순서대로 1,1,2,2 로 정의. 큰 값이 더 높은 우선순위를 의미함

Stack operator_stack; // 연산자들을 저장할 스택

char *convert(char *infix)
{
    operator_stack = create();

    char *postfix = (char *)malloc(strlen(infix)+1); // 변형된 postfix expression이 저장될 문자배열 (+1 을 하는 이유? -> )
    char *pos = postfix; // postfix는 동적으로 할당된 메모리의 시작 주소를 계속 가지고 있어야 하고 후위표기식으로 변환하면서 현재 어디까지 써졌는지 위치를 표시할 포인터가 하나 더 필요함 (pos 앞칸까지는 변환을 완료한 후위표기식이 써져있고 그 뒤부터 쓰면 된다는 뜻) 맨 처음에는 pos와 postfix가 같은 주소를 가짐

    char *token = strtok(infix, " "); // 연산자와 피연산자 사이에 하나의 공백이 존재한다고 가정
    while (token != NULL)
    {
        if (token[0] >= '0' && token[0] <= 9) // token이 피연산자인 경우
        {
            sprintf(pos, "%s", token); // 현재 pos가 가리키고 있는 위치에 token을 써줌
            pos += (strlen(token) + 1); // token을 쓴 뒤 공백 하나를 추가
        }
        else if (is_operator(token[0] < -1)) //token이 연산자인 경우
            pos = process_op(token[0], pos); // process_op 함수는 연산자를 append한 후 전진된 문자열의 끝 주소를 반환 (pos가 항상 맨 마지막 위치를 가리킬 수 있도록)
        else // Error
            handle_exception("Syntax ErrorL invalid character encountered.");
        token = strtok(NULL, " ");
    }
    while (!is_empty(operator_stack))
    {
        char op = (char)pop(operator_stack);
        sprintf(pos, "%c", op);
        pos += 2;
    }
    *pos = '\0' // 마지막에 '\0'를 추가해서 문자열의 끝을 표시
    return postfix;
}

char *process_op(char op, char *pos)
{
    if (is_empty(operator_stack))
        push(operator_stack,op);
    else
    {
        char top_op = peek(operator_stack);
        if (precedence(op) > precedence(top_op))
            push(operator_stack,op);
        else
        {   
            while (!is_empty(operator_stack) && precedence(op) <= precedence(top_op))
            {
                pop(operator_stack); // 앞에서 이미 peek를 했기 때문에 pop이 return하는 값은 top_op와 같음 (굳이 pop하지 않아도 됨) 
                sprintf(pos, "%c", top_op);
                pos += 2;
                if (!is_empty(operator_stack))
                    top_op = (char)peek(operator_stack);
            }
            push(operator_stack, op)
        }
    }
    return pos;
}

int precedence(char op)
{
    return PRECEDENCE[is_operator(op)]; // op는 연산자(만약 op가 +라면 PRECEDENCE[0]이므로 1이 return됨)
}

int is_operator(char ch) // 문자 ch가 연산자인지 검사함. 아니면 -1
{
    for (int i=0; i<strlen(OPERATORS); i++)
    {
        if (OPERATORS[i] == ch)
            return i;
    }
    return -1;
}

void handle_exception(const char *err_msg)
{
    printf("%s\n", err_msg);
    exit(1);
}