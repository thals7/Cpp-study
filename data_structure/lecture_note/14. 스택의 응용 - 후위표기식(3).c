후위표기식으로 변환
(2) 괄호가 있는 경우 - 다음의 세가지 조건을 추가

- 여는 괄호는 무조건 스택에 push -> 이 때 스택 내의 어떤 연산자도 pop하지 않음
- 어떤 연산자를 스택에 push할 때 스택의 top에 여는 괄호가 있으면 아무도 pop하지 않고 그냥 push
- 입력에 닫는 괄호가 나오면 스택에서 여는 괄호가 나올 때까지 pop하여 출력 (닫는 괄호는 스택에 push X)

ex)
static char OPERATORS[] = "+-*/()"; // 괄호()도 스택 안에 들어가야하므로 연산자 배열에 추가 
static int PRECEDENCE[] = {1, 1, 2, 2, -1, -1}; // 괄호의 우선순위를 -1로 처리함으로써 op와 top_op를 비교할 때 top_op가 여는 괄호인지 아닌지 따로 계산하는 처리를 하지 않아도 됨

Stack operator_stack;

char *convert(char *infix)
{
    operator_stack = create(100);
    char *postfix = (char *)malloc(strlen(infix)+1); // 
    char *pos = postfix;

    char *token = strtok(infix, " ");
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
        if (op == '(') // 스택에 여는 괄호가 남아있어서는 안됨
            handle_exception("Unmatched parenthesis");
        sprintf(pos, "%c", op);
        pos += 2;
    }
    *pos = '\0'; // 마지막에 '\0'를 추가해서 문자열의 끝을 표시
    return postfix;
}

char *process_op(char op, char *pos)
{
    if (is_empty(operator_stack) || op == '(') // 여는 괄호는 그냥 스택에 push
        push(operator_stack,op);
    else
    {
        char top_op = peek(operator_stack);
        if (precedence(op) > precedence(top_op)) // 여는 괄호를 -1로 처리했기 때문에 precedence(top_op)가 여는 괄호일때는 우선 순위가 -1이기 때문에 그냥 op를 push하면 됨
            push(operator_stack, op);
        else
        {   
            while (!is_empty(operator_stack) && precedence(op) <= precedence(top_op))
            {
                pop(operator_stack);
                if (top_op == '(')
                    break; // op의 우선순위가 top_op보다 낮거나 같은데 top_op가 여는 괄호이면 op는 닫는 괄호
                sprintf(pos, "%c", top_op);
                pos += 2;
                if (!is_empty(operator_stack))
                    top_op = (char)peek(operator_stack);
            }
            if (op != ')') // 닫는 괄호는 스택에 push 하지 않음
                push(operator_stack, op)
        }
    }
    return pos;
}


보완해야할 부분
- 피연산자는 양의 정수만 허용 : 음수나 실수로 확장
- 모든 토큰들이 공백문자로 구분되어 있어야 함
- 일진(unary) 연산자의 처리: -(-2)
- right associativity를 가지는 연산자의 처리: 2^3^4
- 후위표기식으로 변환하는 일과 후위표기식을 계산하는 일을 하나로 합치기