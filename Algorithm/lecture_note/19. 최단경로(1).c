최단경로
- 가중치(방향) 그래프 G(V,E), 즉 모든 에지에 가중치가 있음 (만약 가중치가 없는 그래프라면 BFS로 최단경로를 구할 수 있음)
- 경로 p=(v0,v1,...vk)의 길이는 경로상의 모든 에지의 가중치의 합
- 노드 u에서 v까지의 최단경로의 길이를 δ(u, v)로 표현

최단경로문제의 유형
- Single-source:
  - 하나의 출발 노드 s로부터 다른 모든 노드까지(one-to-all)의 최단 경로를 찾아라 
  - 예: Dijkstra의 알고리즘

- Single-destination:
  - 모든 노드로부터 하나의 목적지 노드까지의 최단 경로를 찾아라
  - Single-source 문제와 동일 (Undirected graph일때)

- Single-pair:
  - 주어진 하나의 출발 노드 s로부터 하나의 목적지 노드 t까지의 최단 경로를 찾아라
  - 최악의 경우 시간복잡도에서 Single-source 문제보다 나은 알고리즘이 없음

- All-pairs:
  - 모든 노드 쌍에 대해서 최단 경로를 찾아라

최단경로와 음수 가중치
- Edge의 가중치가 음수인 경우
- 알고리즘에 따라 음수 가중치가 있어도 작동하는 경우도 있고 그렇지 않은 경우도 있음
- 음수 사이클(사이클을 구성하는 edge의 weight의 총 합이 음수인 경우)이 있으면 최단 경로가 정의되지 않음

최단경로의 기본 특성
- 최단 경로의 어떤 부분경로도 역시 최단 경로임
  - 어떤 경로가 u-x-y-v를 지나는 최단 경로일 때 이 경로는 x-y까지의 최단 경로임
- 최단 경로는 사이클을 포함하지 않음 (음수 사이클이 없다는 가정하에)


Single-source 최단경로문제
- 입력: 음수 사이클이 없는 가중치 방향그래프 G=(V,E)와 출발 노드 s∈V
- 목적: 각 노드 v∈V에 대해서 다음을 계산
  - d[v] : 현재까지 찾은 s로부터 v까지 가는 가장 가까운 경로의 길이
    - 처음에는 d[s]=0, d[v]=∞로 시작
    - 알고리즘이 진행됨에 따라서 감소하지만 항상 d[v]≥δ(s,v)를 유지
    - 최종적으로 d[v]=δ(s,v)가 됨
  - π[v]: s에서 v까지의 최단경로상에서 v의 직전 노드(predecessor)
    - 그런 노드가 없는 경우 π[v]=NIL

기본 연산: Relaxation
RELAX(u,v,w) // w: weight function
1  if d[v]>d[u]+w(u,v) // 기존의 경로보다 더 나은 경로를 찾은 경우
2    then d[v] <- d[u]+w(u,v)
3      π[v] <- u

- 대부분의 single-source 최단경로 알고리즘의 기본 구조
  1. 초기화: d[s]=0, 노드 v!=s에 대해서 d[v]=∞, π[v]=NIL
  2. 에지들에 대한 반복적인 relaxation
- 알고리즘들 간의 차이는 어떤 에지에 대해서, 어떤 순서로 relaxation을 하느냐에 있음

기본 알고리즘
Generic-Single-Source(G,w,s)
1  INITIALIZE-SINGLE-SOURCE(G,s) // d[s]=0, d[v]=∞(v!=s), π[v]=NIL
2  repeat
3    for each edge (u,v)∈E // 그래프의 모든 에지들에 대해서 한번씩 RELAX를 해줌
4      RELAX(u,v,w)
5  until there is no change // 어떤 노드의 d값도 업데이트되지 않을때까지 2로 돌아가 RELAX 반복

Q1. 이렇게 계속 반복하면 최단 경로가 찾아지는가?
Q2. 2~4의 과정을 몇 번 반복해야 하는가?

A2. s-v1-v2-...-vi-v 를 s에서 v까지의 최단 경로라고 했을 때
첫번째 반복에서 d[v1] = d[s] + w(s,v1) = δ(s,v1)
두번째 반복에서 d[v2] = d[v1] + w(v1,v2) = δ(s,v2)
...
i번째 반복에서 d[vi] = δ(s,vi) 가 됨
-> 즉 n-1번의 반복으로 충분

Bellman-Ford 알고리즘
BELLMAN-FORD(G,w,s)
1  INITIALIZE-SINGLE-SOURCE(G,s)
2  for i <- 1 to |V|G|| - 1 // |V|G|| = n
3    do for each edge (u,v) ∈ E[G]
4      do RELAX(u,v,w)
5  for each edge (u,v) ∈ E[G]
6    do if d[v] > d[u] + w(u,v) // 이미 n-1번의 반복을 통해 최단 경로를 찾았음에도 여전히 RELAX가 가능하다면 이는 음수 사이클이 존재한다는 의미 (즉 최단 경로가 존재하지 않음)
7      then return FALSE
8  return TRUE

- 단순히 최단 경로를 찾을 뿐만 아니라 음수 사이클의 여부 또한 알아낼 수 있음
- 시간복잡도: O(mn) // n-1번 for문을 반복 * 에지의 개수가 m개일때 m번의 RELAX 연산을 수행

Worst Scenario
- d[v]가 한 번 업데이트 될 때마다 모든 에지들에 대해 RELAX를 실행했을때 모든 값이 바뀜