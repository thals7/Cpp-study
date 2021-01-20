Prim의 알고리즘
- 임의의 노드를 출발노드로 선택
- 출발 노드를 포함하는 트리를 점점 키워감
- 매 단계에서 이미 트리에 포함된 노드와 포함되지 않은 노드를 연결하는 에지들 중 가장 가중치가 작은 에지를 선택

왜 MST가 찾아지는가?
- Prim의 알고리즘의 임의의 한 단계에 대해서
- A를 현재가지 알고리즘이 선택한 에지의 집합이라고 하고, A를 포함하는 MST가 존재한다고 가정

- 출발 노드에 이미 연결된 노드와 그렇지 않은 노드를 연결하는 에지들 중 lightest edge는 집합 A에 대해서 안전

가중치가 최소인 에지 찾기
- VA: 이미 트리에 포함된 노드들
- VA에 아직 속하지 않은 각 노드 v에 대해서 다음과 같은 값을 유지
  - key(v): 이미 VA에 속한 노드와 자신을 연결하는 에지들 중 가중치가 최소인 에지 (u,v)의 가중치
  - π(v): 그 에지 (u,v)의 끝점 u
- 가중치가 최소인 에지를 찾는 대신 key값이 최소인 노드를 찾음

- key값이 최소인 노드 f를 찾고 에지 (f,π(f))를 선택
- 노드 d,g,e의 key값과 π값을 갱신 

pseudo code
MST-Prim(G,w,r)
1  for each u∈V do
2    key[u] <- ∞
3    π[u] <- NIL
4  end. // 모든 노드들에 대해 초기화
5  VA <- empty set;
6  key[r] <- 0
7  while |VA|<n do // while문은 n-1번 반복
8    find u∉VA with the minimum key value; // 최소값 찾기 O(n)
9    VA <- VA ∪ {u}
10   for each v∉VA adjacent to u do // degree(u) = O(n)
11     if key[V] > w(u,v) then
12       key[V] <- w(u,v)
13       π[V] <- u
14     end.
15   end.
16 end.
시간복잡도: O(n^2)

Key값이 최소인 노드 찾기
- 최소 우선순위 큐를 사용
  - V-VA에 속한 노드들을 저장
  - Extract-Min: key값이 최소인 노드를 삭제하고 반환

MST-Prim(G,w,r)
1  for each u∈V[G]
2    do key[u] <- ∞
3    π[u] <- NIL
4  key[r] <- 0
5  Q <- V[G]
6  while Q != 0
7    do u <- EXTRACT-MIN(Q) // 최소값 찾기 O(logn)
8      for each v∈Adj[u]
9        do if v∈Q and w(u,v) < key[v]
10         then π[v] <- u
11           key[v] <- w(u,v) // 우선순위큐에서 key값 decrease: O(logn)

시간복잡도
- 이진 힙(binary heap)을 사용하여 우선순위 큐를 구현한 경우
- while loop:
  - n번의 EXTRACT-Min 연산: O(nlogn)
  - m번의 Decrease-key 연산: O(mlogn)
- 따라서 시간복잡도: O(nlogn + mlogn) = O(mlogn)
- 우선순위 큐를 사용하지 않고 단순하게 구현할 경우: O(n^2)
- Fibonacci 힙을 사용하여 O(m+nlogn)에 구현 가능