Kruskal의 알고리즘
- 에지들을 가중치의 오름차순으로 정렬
- 에지들을 그 순서대로 하나씩 선택. 단, 이미 선택된 에지들과 사이클(cycle)을 형성하면 선택하지 않음
- n-1개의 에지가 선택되면 종료

왜 MST가 찾아지는가?
- Kruskal 알고리즘의 임의의 한 단계를 생각해 보았을 때
- A를 현재까지 알고리즘이 선택한 에지의 집합이고, A를 포함하는 MST가 존재한다고 가정

- 남아있는 에지들 중 cycle을 만들지 않는 lightest edge(u,v)는 현재 A의 에지들에 의해서 연결되어있지 않음
- 따라서 A에 edge(u,v)를 추가하더라도 여전히 A를 포함하는 MST가 존재함

사이클 검사
- 초기 상태: 선택된 에지 없음 (모든 노드들이 각각 자기 자신을 유일한 원소로 하는 집합에 속해있음)
- 각각의 연결요소를 하나의 집합으로 표현

1. 가중치가 최소인 에지 (h,g)를 고려
2. g와 h가 서로 다른 집합에 속함
3. 에지 (g,h)를 선택하고, g와 h가 속한 집합을 합집합하여 하나의 집합으로 만듦
4. 다시 1번으로 돌아가 가중치가 최소인 다른 에지를 고려하여 2~3번 수행
5. 가중치가 최소인 에지 (g,f)를 고려 
6. {f},{g,h}가 서로 다른 집합에 속함
7. 에지 (g,f)를 선택하고 g와 f가 속한 집합을 합집합하여 {f,g,h} 하나의 집합으로 만듦 -> f,g,h는 연결된 상태
8. 가중치가 최소인 에지 (i,g)를 고려
9. i와 g가 이미 같은 집합 {c,f,g,h,i}에 속함 -> 즉 i와 g를 연결하면 사이클이 생김
10. 에지 (i,g)를 선택하지 않음
...
n-1개의 에지가 선택되면 종료

pseudo code
MST-KRUSKAL(G, w)
1  A <- ∅
2  for each vertex v∈V[G]
3    do MAKE-SET(v) // 각각의 노드들을 유일한 원소로 가지는 집합들로 만듦(초기화)
4  sort the edges of E into nondecreasing order by weight w
5  for each edge (u,v)∈E, taken in nondecreasing order by weight
6    do if FIND-SET(u) != FIND-SET(v) // u가 속해있는 집합과 v가 속해있는 집합이 다르다면
7      then A <- A∪{(u,v)} // 집합 A에 edge(u,v)를 추가
8        UNION(u,v) // u와 v가 속한 두 집합을 하나로 합침
9  return A

서로소인 집합들의 표현
- Disjoint sets 자료구조가 지원해야 하는 연산
  - find(u): 어떤 원소 u가 속해있는 집합을 탐색
  - union(u,v): 어떤 두 개의 집합을 하나로 합집합
- 각 집합을 하나의 트리로 표현
- 집합의 각 원소들이 트리의 노드가 됨. 누가 루트이고 누가 누구의 부모이든 상관 없음 (이진트리가 아니기 때문에 자식 노드를 여러개 가져도 상관 없음)
- 트리의 각 노드는 자식노드가 아닌 부모 노드의 주소를 가짐 (위에서 아래로 올라가는 일만 수행하기 때문)
- 어떤 노드의 부모가 자기 자신과 동일하면 그 노드는 루트 노드

Find-Set(v)
- 자신이 속한 트리의 루트를 찾음
1  if x != p[x] // 부모 노드와 자기 자신이 동일하지 않을 경우 (루트노드가 아닌 경우)
2    then p[x] <- FIND-SET(p[x]) // x가 속해있는 트리의 루트와  x의 부모가 속해있는 트리의 루트는 동일
3  return p[x]
- O(h), h는 트리의 높이
  h는 최악의 경우 O(n) (모든 노드들이 일렬로 연결된 트리의 맨 끝에 있는 노드에 대해서 Find-Set을 하게될 경우)
- 만약 두 원소의 루트 노드가 동일하면 두 원소는 동일한 집합에 속해있다는 뜻

union(u,v)
- 한 트리의 루트를 다른 트리의 루트의 자식 노드로 만듦
1  x <- FIND-SET(u);
2  y <- FIND-SET(v);
3  p[x] <- y;
- 루트 노드를 찾은 이후에는 O(1)
  하지만 루트를 찾는데 O(h) (FIND-SET연산과 동일)
  -> 가능한 트리의 높이를 낮게 만드는 것이 좋음
 
WEIGHTED-UNION(u,v)
- 두 집합을 union할 때 작은 트리의 루트를 큰 트리의 루트의 자식으로 만듦 (여기서 크기란 노드의 개수)
- 각 트리의 크기(노드의 개수)를 알고 있어야 함
1  x <- FIND-SET(u);
2  y <- FIND-SET(v);
3  if size[x] > size[y] then // x의 크기가 y의 크기보다 클 때
4    p[y] <- x; // x는 y의 부모 노드가 됨
5    size[x] <- size[x] + size[y];
6  else
7    p[x] <- y;
8    size[y] <- size[y] + size[x];

Path Compression
- FIND-SET에서 루트노드를 찾아 쭉 따라 올라가면서 도중에 지나치는 모든 노드들을 다 떼어서 루트의 자식으로 붙여버림
FIND-SET-PC(x)
1  while x != p[x] do
2    p[x] <- p[p[x]];
3    x <- p[x];
4  end.
5  return p[x]

Weighted Union with Path Compression (WUPC)
- M번의 union-find 연산의 총 시간복잡도는 O(N+Mlog*N). 여기서 N은 원소의 개수
- log*N: (logloglog...logN)=1을 만족시키는 log의 개수 (ex. log*1=0, log*2=1, log*4=2, log*16=3, log*65536=4, log*2^65536=5 즉 log*N은 5보다 커질 일이 없는 수) 
- 거의 선형시간 알고리즘. 즉 한 번의 Find 혹은 Union이 거의 O(1)시간

시간복잡도
Initialize A: O(1)
First for loop: |V| MAKE-SETs
Sort E: O(|E|log₂|E|)
Second for loop: O(|E|) FIND-SETs and UNIONs?

O(|E|log₂|E|) = O(mlogm)