Dijkstra 알고리즘
- 초기화: d[s]=0, d[v]=∞
- 음수 가중치가 없다고 가정
- s로부터의 최단 경로의 길이를 이미 알아낸 노드들의 집합 S를 유지. 맨 처음엔 S={s}
- Loop invariant
  - u∉S인 각 노드 u에 대해서 d(u)는 이미 S에 속한 노드들만 거쳐서 s로부터 u까지 가는 최단경로의 길이

정리 : S에 속하지 않는 노드들 중 d(u)=min d(v)인 노드 u에 대해서, d(u)는 s에서 u까지의 최단경로의 길이
증명: d(u)가 s에서 u까지의 최단경로의 길이가 아니라고 가정 -> s에서 u까지의 다른 최단 경로가 존재함 -> 그 최단 경로는 S에 속하지 않는 노드 v를 무조건 거쳐야 함 -> u는 d값이 최소인 노드이므로 d(v)>=d(u)여야 하는데 이는 모순

- d(u)가 최소인 노드 u∉S를 찾고, S에 u를 추가
- S가 변경되었으므로 다른 노드들의 d(v)값을 갱신

- d(v) = min{d(v),d(u)+w(u,v)}
- 즉, 에지 (u,v)에 대해서 relaxation하면 Loop Invariant가 계속 유지됨

Dijkstra(G,w,s)
1  for each u∈V do
2    d[u] <- ∞
3    π[u] <- NIL
4  end.
5  S <- ∅
6  d[s] <- 0 // 1~6 초기화 O(n)
7  while |S|<n do // 집합 S에 모든 노드들이 포함될 때까지 n-1번 반복
8    find u∉S with the minimum d[u] value; // 최소값 찾기 O(n)
9    S <- S ∪ {u}
10   for each u∉S with the adjacent to u do // degree(u) = O(n)
11     if d[v] > d[u]+w(u,v) then
12       d[v] <- d[u]+w(u,v)
13       π[v] <- u // 11~13 RELAX
14     end.
15   end.
16 end.

시간복잡도
- Prim 알고리즘과 동일
- 우선순위 큐를 사용하지 않고 단순하게 구현할 경우 O(n^2)
- 이진힙을 우선순위 큐로 사용할 경우 O(nlog₂n+mlog₂n)
- Fibonacci Heap 사용하면 O(nlog₂n+m)에 구현 가능