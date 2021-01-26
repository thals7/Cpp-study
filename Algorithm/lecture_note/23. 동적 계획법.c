Fibonacci Numbers
- 피보나치 수열을 단순히 recursion으로 구현할 경우 많은 계산이 중복됨
- Memoization: 이전에 계산한 값(중간 계산 결과)을 메모리에 저장함으로써 동일한 계산의 반복 수행 제거
- Dynamic Programming: f(10)을 계산하기 위하여 f(1)부터 순서대로 게산해서 쭉 올라옴(bottom-up 방식)

Memoization vs. Dynamic Programming
- 순환식의 값을 계산하는 기법
- 둘 다 동적계획법의 일종을 보기도 함
- Memoization : top-down 방식. 실제로 필요한 subproblem만을 해결
- 동적계획법 : bottom-up 방식. recursion에 수반되는 overhead 없음


동적계획법
1. 일반적으로 최적화문제(optimisation problem) 혹은 카운팅(counting) 문제에 적용됨
2. 주어진 문제에 대한 순환식(recurrence equation)을 정의
3. 순환식을 memoization 혹은 bottom-up 방식으로 해결

- 복잡한 문제를 작은 subproblem들로 나누어 풀어서 원래 문제를 해결하는 방식
- 분할정복법에서는 분할된 문제들이 서로 중복되지 않지만 동적계획법에서는 그렇지 않음
- 즉 서로 overlapping하는 subproblem들의 해를 적절히 조합하여 original problem을 푸는 과정

분할정복법 vs. 동적계획법
- quicksort의 경우(분할정복법) : pivot을 기준으로 분할된 두 subproblem은 서로 disjoint (pivot의 왼쪽 부분을 정렬하는 것과 오른쪽 부분을 정렬하는 것은 완전히 다른 문제)

Optimal Substructure
- 어떤 문제의 최적해가 그것의 subproblem들의 최적해로부터 효율적으로 구해질 수 있을때 그 문제는 optimal substructure를 가진다고 말함
- 분할정복법, 그리디 알고리즘, 동적계획법 모두 이러한 문제의 특성을 이용

- 동적계획법으로 문제를 문다는 것은 그 문제의 핵심을 표현하는 순환식을 세운다는 것이고 순환식은 결국 그 문제가 가지고 있는 optimal substructure를 formal하게 표현하는 것
- "최적해의 일부분이 그 부분에 대한 최적해인가?"
  ex) 최단경로 문제: s-v-u 를 잇는 어떤 경로가 s-u까지의 최단경로라면 이는 s-v의 최단경로
      d[u] = min (d[v] + w(v,u))
  ex) 최장경로 문제: 노드를 중복 방문하지 않고 가는 가장 긴 경로
      s-v-u 를 잇는 어떤 경로가 s-u까지의 최장경로라 하더라도 그것이 반드시 s-v의 최장경로라고는 할 수 없음
      d[u] != max (d[v] + w(v,u))
      하지만 최단경로와는 다른 형태의 optimal structure를 가지는 것일 뿐 optimal structure를 가지지 않는다고 말할 수는 없음