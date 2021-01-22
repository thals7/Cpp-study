Floyd-Warshall 알고리즘
- Dynamic Programming 동적계획법
  : 복잡한 문제를 간단한 여러개의 문제로 나누어 푸는 방법
- 가중치 방향 그래프 G(V,E), V = {1,2,...,n} (모든 노드들이 1~n 사이의 정수)
- 모든 노드 쌍들간의 최단경로의 길이를 구함 (all-to-all)

- dk[i,j]
  - 중간에 노드집합 {1,2,...,k}에 속한 노드들만 거쳐서 노드i에서 j까지 가는 최단경로의 길이
  ex)
    - d0[i,j] = 노드 i에서 j까지 가는데 중간에 어떤 노드도 지나지 않으므로 edge(i,j)가 존재한다면 weight는 w(i,j)가 됨. 만약 edge(i,j)가 존재하지 않으면 그 경로는 ∞
    - dn[i,j] = 중간에 어떤 노드를 지나도 상관이 없음. 즉 i에서 j까지의 최단 경로(δ(s,v)) -> 구해야하는 최종 목표
    - dk[i,j] = 노드 k를 지나는 경우 : dk[i,j] = d(k-1)[i,k]+d(k-1)[k,j]
                k를 지나지 않는 경우 : dk[i,j] = d(k-1)[i,j]
                최단 경로는 둘 중 더 짧은 경로가 됨

pseudo code
Floydwarshall(G)
1  for i <- 1 to n
2    for j <- 1 to n
3      d[i,j] <- w(i,j); // 1~3 초기화
4  for k <- 1 to n // 중간정점 집합
5    for i <- 1 to n
6      for j <- 1 to n
7        d[i,j] <- min{d[i,j], d[i,k]+d[k,j]};

- dk[i,k] 와 d(k-1)[i,k]는 항상 동일: i에서 k까지 가는데 중간에 i~k의 정점을 지날수 있다는 뜻은 실제로 k가 끝점이므로 중간에 k를 지날 수 없음
- 따라서 서로 다른 k값에 대해 d값을 유지하지 않고 덮어쓰더라도 아무 문제가 없음
- 시간복잡도: O(n^3)

경로 찾기
Floydwarshall(G)
1  for i <- 1 to n
2    for j <- 1 to n
3      d[i,j] <- w(i,j);
4      π[i,j] <- NIL; // i에서 j까지 가는 최단경로가 중간에 지나는 어떤 정점의 번호를 π에 기록하는 것임
5  for k <- 1 to n
6    for i <- 1 to n
7      for j <- 1 to n
8        if d[i,j] > d[i,k]+d[k,j] then
9           d[i,j] = d[i,k]+d[k,j];
10          π[i,j] = k; // i에서 j까지 가는 최단 경로는 먼저 i에서 k까지 간 다음 k에서 j까지 최단 경로로 가는 것

경로 출력
Print-PATH(s,t,π)
1  if π[s,t] = NIL then // 중간에 어떤 노드도 지나지 않음
2    return
3  print-PATH(s,π[s,t])
4  print(π[s,t]);
5  print-PATH(π[s,t],t)
- s에서 t까지 가는 경로가 존재한다는 가정하에 최단경로상의 중간노드들(s와 t 자신은 제외)을 출력