후위표기식
- 일반적으로 사용하는 수식의 표기법을 중위(infix) 표기식이라고 부름
  - 연산자가 피연산자의 사이에 들어감
- 후위표기식(postfix expression)
  - 연산자가 피연산자 뒤에 나옴

ex)
postfix expression / infix expression / value
4 7 *                4 * 7              28
4 7 2 + *            4 * ( 7 + 2 )      36
4 7 * 20 -           (4 * 7) - 20       8
3 4 7 * 2 / +        3 + ((4 * 7) / 2)  17


후위표기식을 Stack으로 구현
// 모든 피연산자가 양의 정수라 가정
// 모든 연산자와 피연산자 사이에는 하나의 공백 문자가 존재한다고 가정

static char OPERATORS[] = "+-*/"; // 이 프로그램이 지원하는 연산자들을 하나의 string에 모아둠

Stack operand_stack; // 피연산자들을 저장할 스택

void handle_exception(const char *err_msg)
{
    printf("%s\n", err_msg);
    exit(1);
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

int eval(char *expr)
{
    operand_stack = create();
    char *token = strtok(expr, " "); // 모든 연산자와 피연산자가 공백문자로 구분되어 있다고 가정
    while (token != NULL)
    {
        if (token[0] >= '0' && token <= '9')
        {
            int value = atoi(token);
            push(operand_stack, value);
        }
        else if (is_operator(token[0] < -1))
        {
            int result = eval_op(token[0]);
            push(operand_stack, result);
        }
        else handle_exception("Syntax ErrorL invalid character encountered.");
        token = strtok(NULL, " ");
    }
    if (is_empty(operand_stack))
        handle_exception("Syntax Error: Stack empty in eval_op.");
    int answer = pop(operand_stack);
    if (is_empty(operand_stack))
        return answer;
    else
    {
        handle_exception("Syntax Error: Stack should be empty.");
        return -1;
    }
}

int eval_op(char op)
{
    if (is_empty(operand_stack))
        handle_exception("Syntax Error: Stack empty in eval_op.");
    int rhs = pop(operand_stack);
    if (is_empty(operand_stack))
        handle_exception("Syntax Error: Stack empty in eval_op.");
    int lhs = pop(operand_stack);
    int result = 0;
    switch (op)
    {
        case '+': result = lhs + rhs; break;
        case '-': result = lhs - rhs; break;
        case '*': result = lhs * rhs; break;
        case '/': result = lhs / rhs; break;
    }
    return result;
}