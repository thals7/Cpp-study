최소비용 신장 트리 Minimum Spanning Tree
- 무방향 가중치 그래프 G=(V,E)
- 각 에지 (u,v)∈E에 대해서 양의 가중치 w(u,v)
- 문제 : 다음과 같은 조건을 만족하는 에지들의 부분집합 T⊆E를 찾아라.
  1. T에 속한 에지들에 의해 그래프의 모든 정점들이 서로 연결된다.
  2. 가중치의 합이 최소가 된다.

Why Tree?
- 트리 :싸이클이 없는 연결된(connected) 무방향 그래프
- MST문제의 답은 항상 트리가 됨
  - 싸이클이 존재한다는 것은 싸이클 상의 어떤 에지 하나를 삭제해도 여전히 그래프가 연결되어 있다는 뜻이므로 불필요한 에지가 존재한다는 뜻임 -> 즉 최소비용과 모순됨
  - 노드가 n개인 트리는 항상 n-1개의 에지를 가짐

Generic MST 알고리즘
- Kruskal, Prim 알고리즘이 공통적으로 가지고 있는 본질적 접근법
- 어떤 MST의 부분집합 A에 대해서 A∪{(u,v)}도 역시 어떤 MST의 부분집합이 될 경우 에지 (u,v)는 A에 대해서 안전하다(safe)고 말함
- A가 어떤 MST의 부분집합이라는 뜻은 A를 포함하는 MST가 존재한다는 뜻 But! A가 MST에 속한다는 틀린 말 -> MST는 유일하지 않기 때문에 A를 포함하지 않는 MST가 존재할 수 있음
1. 처음은 A=∅
2. 집합 A에 대해서 안전한 에지를 하나 찾은 후 이것을 A에 더함
3. 에지의 개수가 n-1개가 될 때까지 2번을 반복

pseudo code
GENERIC-MST(G,w)
1  A <- ∅
2  while A does not form a spanning tree
3    do find an edge(u,v) that is safe for A
4      A <- A∪{(u,v)}
5  return A

안전한 에지 찾기
- 그래프의 정점들을 두 개의 집합 S와 V-S로 분할한 것을 컷(cut) (S,V-S)라고 부름
- 에지 (u,v)에 대해서 u∈S이고 v∈V-S일 때(한 쪽 집합에서 다른쪽 집합으로 건너갈 수 있을 때) 에지 (u,v)는 컷 (S,V-S)를 cross한다고 말함 
- 에지들의 부분집합 A에 속한 어떤 에지도 컷 (S,V-S)를 cross하지 않을 때 컷 (S,V-S)는 A를 존중한다(respect)고 말함


=> A가 어떤 MST의 부분집합이고, (S,V-S)는 A를 존중하는 컷이라고 했을 때, 이 컷을 cross하는 에지들 중 가장 가중치가 작은 에지 (u,v)는 A에 대해서 안전함 -> 즉 에지 (u,v)를 선택해도 된다는 뜻