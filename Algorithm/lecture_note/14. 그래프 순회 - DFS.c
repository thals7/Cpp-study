깊이우선순회 DFS
1. 출발점 s에서 시작
2. 현재 노드를 visited로 mark하고 인접한 노드들 중 unvisited 노드가 존재하면 그 노드로 이동
3. 2번을 계속 반복
4. unvisited인 이웃 노드가 존재하지 않는 동안 계속해서 직전 노드로 되돌아감
5. 다시 2번 반복
6. 시작노드 s로 돌아오고 더이상 갈 곳이 없으면 종료

pseudo code
DFS(G,v)
  visited[v] <- YES;
  for each node adjacent to v do // v에 인접한 노드 u에 대해서
    if visited[u] = NO then // 방문하지 않은 노드 u가 존재한다면
      DFS(G,u);
  end.
end.

- 그래프가 disconnected이거나 혹은 방향 그래프라면 DFS에 의해서 모든 노드가 방문되지 않을 수도 있음
- DFS를 반복하여 모든 노드 방문

DFS-ALL(G)
{
  for each v ∈ V
    visited[v] ← NO;
  for each v ∈ V
    if (visited[v] = NO) then 
      DFS(G, v);
}

시간복잡도 : O(n+m)
에지 하나당 recursion이 한 번 이상 호출되지 않음