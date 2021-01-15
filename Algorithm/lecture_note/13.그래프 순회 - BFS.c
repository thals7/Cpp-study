그래프 순회
- 순회 : 그래프의 모든 노드들을 방문하는 일
- 대표적 두 가지 방법
  - BFS (Breadth-First Search, 너비우선탐색)
  - DFS (Depth-First Search, 깊이우선탐색)


너비우선순회 BFS
- 그래프에서 노드들을 동심원의 형태로 탐색하는 알고리즘
- 다음의 순서대로 노드들을 방문
  L0 = {s}, s는 출발 노드
  L1 = L0의 모든 이웃 노드들
  L2 = L1의 이웃들 중 L0에 속하지 않는 노드들
  ...
  Li = Li-1의 이웃들 중 Li-2 에 속하지 않는 노드들

큐를 이용한 BFS
1. check the srart node; (체크는 이미 방문된 노드라는 표시)
2. insert the start node into the queue;

while the queue is not empty do
    remove a node v from queue;
    for each unchecked neighbour w of v do
        check and insert w into the queue

pseudo code
BFS(G,s) // 그래프 G와 출발 노드 s
  Q <- ∅; // Q는 empty 상태
  Enqueue(Q,s); // 출발 노드 s를 Q에 삽입
  while Q != ∅ do
    u <- Dequeue(Q) // Q로부터 노드를 하나 꺼냄
    for each v adjacent to u do
      if v is unvisited then
        mark v as visited;
        Enqueue(Q,v); // 삭제된 노드 u의 이웃 노드 중 방문한 적 없는 노드 v를 Q에 삽입
      end.
    end.
  end.

BFS와 최단경로
- s에서 Li에 속한 노드까지의 최단 경로의 길이는 i (여기서 경로의 길이는 경로에 속한 에지의 개수)
- BFS를 하면서 각 노드에 대해서 최단 경로의 길이를 구할 수 있음

- 입력: 방향 혹은 무방향 그래프 G=(V,E), 그리고 출발노드 s∈V
- 출력: 모든 노드 v에 대해서
  - d[v] = s로부터 v까지의 최단 경로의 길이 (에지의 개수)
  - π[v] = s로부터 v까지의 최단 경로상에서 v의 직전 노드 (predecessor)

pseudo code (최단경로 추가)
BFS(G,s)
  Q <- ∅;
  for each node u do
    d[u] <- -1  // 보통 모든 노드들에 대해서 d[v]를 -1로 초기화해두고, -1이면 unvisited, 아니면 visited로 판단
    π[s] <- null;
  end.
  d[s] <- 0; // distance from s to s is 0
  π[s] <- null; // no predecessor of s
  Enqueue(Q,s);
  while Q != ∅ do // while문을 한 번 돌 때마다 큐에서 하나를 꺼내므로 while문은 최대 n번 반복
    u <- Dequeue(Q)
    for each v adjacent to u do // 인접리스트로 구현할 경우 for문은 각 노드 v에 대해서 degree(v)(연결리스트의 길이)번 반복
      if (d[v] == -1) then // if v is unvisited
        d[v] <- d[u]+1; // distance to v
        π[v] <- u; // u is predecessor of v
        Enqueue(Q,v); // unvisited 노드만 queueu에 들어갈 수 있으므로 어떤 노드도 큐에 두 번 들어가지 않음
      end.
    end.
  end.

while 내부의 중첩 for문
인접리스트로 구현할 경우 시간복잡도 : O(n+m)
인접행렬로 구현할 경우 시간복잡도 : O(n^2)

BFS 트리
- 각 노드 v와 π[v]를 연결하는 에지들로 구성된 트리
  - BFS 트리에서 s에서 v까지의 경로는 s에서 v까지 가는 최단경로
  - 어떤 에지도 2개의 layer를 건너가지 않음 (동일 레이어의 노드를 연결하거나, 혹은 1개의 layer를 건너감)

BFS : 최단 경로 출력하기
PRINT-PATH(G,s,v) // 출발점 s에서 노드 v까지의 경로 출력하기
  if v=s then
    print s;
  else if π[v]=null then // 그래프 자체가 disconnected인 경우
    print "no path from s to v exists";
  else
    PRINT-PATH(G,s,π[v]);
    print v;
end.

- 그래프가 disconnected이거나 혹은 방향 그래프라면 BFS에 의해서 모든 노드가 방문되지 않을 수도 있음
- BFS를 반복하여 모든 노드 방문
  - BFS-ALL(G)
    {
      while there exists unvisited node v
        BFS(G,v)
    }