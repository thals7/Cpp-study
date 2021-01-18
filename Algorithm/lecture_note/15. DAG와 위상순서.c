DAG (Directed Acyclic Graph)
- 방향 사이클(directed cycle)이 없는 방향 그래프
- 예: 작업들의 우선순위 : 어떤 작업들 간에 우선순위가 존재하고 이 우선순위에 따라 일을 완료할 수 있음

위상 정렬 (topological ordering)
- DAG에서 노드들을 순서화 v1, v2, ..., vn 할 때 모든 에지 (vi, vj)에 대해서 i<j가 되도록 하는 선형 정렬

어떤 노드로 들어오는(incoming) 에지의 개수를 indegree, 나가는(outgoing) 에지의 개수를 outdegree라고 부름

위상 정렬 알고리즘(1)
1. indegree가 0인 노드 A를 찾아서 출력 (A에 선행하는 작업이 없음)
2. 노드 A와 outgoing 에지를 그래프에서 제거
3. 남은 그래프에서 indegree가 0인 노드를 찾아 출력하고 그 노드와 outgoing 에지 제거
4. 위의 과정을 반복

Seudo code
topologicalSort1(G)
{
    for <- 1 to n // n개의 노드를 출력하므로 for문은 n번 돌아감
    {
        진입간선이 없는 임의의 정점 u를 선택;
        A[i] <- u;
        정점 u와 u의 진출간선 모두 제거;
    }
    ▷ 배열 A[1...n]에는 정점들이 위상 정렬되어있음
}
수행시간: Θ(n+m)

1) indegree가 0인 노드가 존재하지 않을 경우?
2) indegree가 0인 노드를 찾기 위해서 미리 각 노드들의 indegree가 0인지 아닌지 알고 있어야 함
3) 위의 seudo code를 실제로 어떻게 구현할 것인가?

위상 정렬 알고리즘(2)

toologicalSort2(G)
{
    for each v∈V
      visited[v] <- NO;
    make an empty linked list R;
    for each v∈V ▷ 정점의 순서는 상관 없음
      if (visited[v] = NO) then
        DFS-TS(v, R);
}

DFS-TS(v, R)
{
    visited[v] <- YES;
    for each x adjacent to v do
      if (visited[x] = NO) then
        DFS-TS(x, R);
    add v at the front of the linked list R;
}
알고리즘이 끝나면 연결 리스트 R에는 정점들이 위상정렬된 순서로 매달려있음
DFS를 하다가 막다른 길에 도달했다는 것은 그 노드가 outgoing 에지 자체가 없다는 뜻 -> 즉 위상 정렬의 맨 마지막 자리를 차지해도 상관이 없음
수행시간: Θ(n+m)


(1)은 위상정렬에서 맨 먼저 나와야 하는 노드를 찾는 알고리즘
(2)는 위상정렬에서 맨 마지막에 나와야 하는 노드를 먼저 찾는 알고리즘