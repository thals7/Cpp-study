Matrix-Chain Multiplication
- pxq 행렬 A와 qxr 행렬 B 곱하기
  곱셈연산의 횟수 = pqr

Matrix-Chain 곱하기
- 행렬 A는 10x100, B는 100x5, C는 5x50
- 세 행렬의 곱 ABC는 두 가지 방법으로 계산 가능 (결합법칙 성립)
  - (AB)C : 7,500번의 곱셈 필요 (10x100x5 + 10x5x50)
  - A(BC) : 75,000번의 곱셈 필요 (100x5x50 + 10x100x50)
- 즉 곱하는 순서에 따라 연산량이 다름
- n개의 행렬의 곱 A1A2A3...An을 계산하는 최적의 순서는?
- 여기서 Ai는 p(k-1) x p(k) 크기의 행렬로 가정

Optimal Structure
- A1A2...Ak A(k+1)A(k+2)...An
- A1~Ak 까지의 곱을 X, A(k+1)~An까지의 곱을 Y라고 했을 때 최종 결과 Z는 직전의 두 행렬 X와 Y의 곱

순환식
- m[i,j] : Ai...Aj를 곱하는 최소곱셈 횟수
- if i<j; m[i,j] = min(i<=k<=j-1)(m[i,k]+m[k+1,j]+p(i-1)pkpj)

- Bottom-up : 수식을 계산할 때 순환식의 오른쪽 항들이 왼쪽 항들보다 먼저 계산되어지는 순서
- 시간복잡도 : Θ(n^3)


Longest Common Subsequence
- <bcdb>는 문자열 <abcbdab>의 subsequence (중간에 건너뛰어도 상관 업음)
- <bca>는 문자열 <abcbdab>와 <bdcaba>의 common subsequence
- Longest common subsequence(LCS)
  - common subsequence들 중 가장 긴 것
  - <bcba>는 <abcbdab>와 <bdcaba>의 LCS

- 입력으로 두 문자열이 주어졌을때 두 문자열의 common subsequence중에서 가장 큰 것을 찾는 문제

순환식
- L(i,j) : 문자열 X = <x1x2x...xi>와 Y<y1y2...yj>의 LCS의 길이
- 경우 1: xi = yi
         L[i,j] = L[i-1,j-=1] + 1
- 경우 2: xi != yi
         L[i,j] = max(L[i-1,j],L[i,j-1])


Knapsack Problem
- n개의 아이템과 배낭
- 각각의 아이템은 무게 wi와 가격 vi를 가짐
- 배낭의 용량 W
- 목적 : 배낭의 용량을 초과하지 않으면서 가격이 최대가 되는 부분집합

Greedy
- 가격이 높은 것부터 선택
- 무게가 가벼운 것부터 선택
- 단위 무게당 가격이 높은 것부터 선택

순환식
- OPT(i) : 아이템 1,2,...i로 얻을 수 있는 최대 이득
(1) 아이템 i를 선택하지 않는 경우 : OPT(i) = OPT(i-1)
(2) 아이템 i를 선택하는 경우 : OPT(i) = ?

- OPT(i,w) : 배낭 용량이 w일때 아이템 1,2,...i로 얻을 수 있는 최대 이득
(1) 아이템 i를 선택하지 않는 경우: OPT(i,w) = OPT(i-1,w)
(2) 아이템 i를 선택하는 경우 : OPT(i) = OPT(i-1,w-wi) + vi

시간복잡도
- O(nW)
- 다항시간인가? No. 
- 시간복잡도가 다항시간이라는 것은 입력 크기(사이즈)에 대한 다항함수를 뜻함
- W는 입력으로 주어지는 어떤 값일 뿐 값의 개수가 아님