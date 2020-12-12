 Recursion
: 자기 자신을 호출하는 함수

recursion이 무한루프에 빠지지 않으려면?
ex)
int func(int n) // 0~n까지의 합을 구하는 함수
{
	if (n==0) // Base case: 적어도 하나의 recursion에 빠지지 않는 경우가 존재해야 함
		return 0; // n이 0이라면 합은 0
	else // Recursive case: recursion을 반복하다보면 결국 base case로 수렴해야 함
		return n + func(n-1); // n이 0보다 크다면 0에서 n까지의 합은 0에서 n-1까지의 합에 n을 더한 것
}

Factorial : n!
ex)
int factorial(int n)
{
	if (n==0)
		return 1; // 0! = 1
	else
		return n*factorial(n-1);
}

X^n
ex)
double power(double x, int n)
{
	if (n==0)
		return 1;
	else
		return x*power(x, n-1);
}

Fibonacci Number
ex)
int fibonacci(int n)
{
	if (n<2)
		return n; // f0 = 0, f1 = 1
	else
		return fibonacci(n-1)+fibonacci(n-2);
}

최대공약수 : Euclic Method
ex)
double gcd(int m, int n) // m>-n인 두 양의 정수 m과 n에 대해서
{
	if (m<n)
	{
		int tmp = m;
		m = n;
		n = tmp; // swap m and n
	}
	if (m%n==0) // m이 n의 배수이면
		return n; // gdc(m,n)=n
	else
		return gcd(n, m%n);
}


Recursive Thinking 순환적으로 사고하기
수학함수뿐만 아니라 다른 많은 문제들을 recursion으로 해결 가능

문자열의 길이 계산
ex)
int length(char *str)
{
	if (*str == '\0') // if the string is empty
		return 0;
	else
		return 1+length(str+1); // return  + the length of the string that excludes the first character
}

문자열의 프린트
void printChars(char *str)
{
	if (*str == '\0')
		return;
	else
	{
		printf("%c", *str);
		printChars(str+1);
	}
}

문자열을 뒤집어 프린트
void printChrsReverse(char *str)
{
	if (*str == '\0')
		return;
	else
	{
		printChrarsReverse(str+1); // 먼저 이 문자열을 뒤집어 프린트 한 후
		printf("%c", *str); // 마지막으로 첫 글자를 프린트
	}
}

2진수로 변환하여 출력
ex) // 음이 아닌 정수 n을 이진수로 변환하여 인쇄
void printInBinary(int n)
{
	if (n<2)
		printf("%d", n);
	else
		printInBinary(n/2); // n을 2로 나눈 몫을 먼저 2진수로 변환하여 인쇄한 후
		printf("%d", n%2) // n을 2로 나눈 나머지를 인쇄

}

Disjoint Sets
ex) // 배열 A의 A[0],...A[m-1]과 배열 B의 B[0],...B[n-1]에 정수들이 정렬되어 저장되어 있을 때 두 배열의 정수들이 disjoint한지 검사
bool isDisjoint(int m, int A[], int n, int B[])
{
	if (m<0 || n<0)
		return true;
	else if (A[m-1]==B[n-1])
		return false;
	else if (A[m-1]>B[n-1])
		return isDisjoint(m-1, A, n, B);
	else
		return isDisjoint(m, A, n-1, B)
}


Recursion vs Iteration
- 모든 재귀함수는 반복문(iteration)으로 변경 가능
- 그 역도 성립. 즉 모든 반복문은 recursion으로 표현 가능
- 재귀함수는 복잡한 알고리즘을 단순하고 알기 쉽게 표현하는 것을 가능하게 함
- 하지만 함수 호출에 따른 오버헤드 존재 (매개변수 전달, 액티베이션 프레임 생성 등)