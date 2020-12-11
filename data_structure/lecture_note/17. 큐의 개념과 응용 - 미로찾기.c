그래프 탐색
- 하나의 정점으로부터 시작하여 차례때로 모든 정점들을 방문하는 것

DFS (Depth Frist Search) : 깊이 우선 탐색
- 갈 수 있는 곳까지 끝까지 탐색

BFS (Breadth First Search) : 너비 우선 탐색
- 거리가 가까운 곳부터 탐색
- 출발점에서 먼저 한 칸 떨어진 지점들을 모두 검사한 뒤 그 한 칸 떨어진 지점들 중 출구가 있다면 종료. 출구가 없다면 출발점에서 두 칸 떨어진 지점을 모두 검사. 이후 세 칸, 네 칸... 쭉 검사하며 출구를 찾음
- 일종의 동심원 형태로 찾아보는 방법

BFS 미로찾기
- 다음과 같은 순서로 셀(cell)들을 방문
  L0 = {s}, 여기서 s는 출발 지점
  L1 = L0에서 1번에 갈 수 있는 모든 셀들
  L2 = L1에서 1번에 갈 수 있는 셀들 중에서 L0에 속하지 않는 셀들
  ...
  Li = Li-1에서 1번에 갈 수 있는 셀들 중에서 Li-2에 속하지 않는 셀들
  이 때 출발점에서 Li까지의 거리는 i
- 단순히 입구에서 출구까지 가는 경로를 찾을 뿐만이 아니라 입구에서 출구까지 가는 가장 짧은 경로를 찾을 수 있음

1. 하나의 큐를 생성
2. 위치 (0,0)는 이미 방문한 위치임을 표시하고, 큐에 위치(0,0)을 넣음
3. 큐가 빌 때 까지 다음을 반복
  (1) 큐에서 하나의 위치 p를 꺼냄
  (2) p에서 한 칸 떨어진 위치들 중에서 이동 가능하면서 아직 방문하지 않은 모든 위치들을 방문된 위치임을 표시하고 큐에 넣음
  (3) 만약 그 위치가 출구라면 종료


큐를 통한 BFS 미로찾기 구현
ex)

Queue queue = create_queue();
Position cur;
cur.x = 0;
cur.y = 0;

enqueue(queue, cur);

maze[0][0] = -1; // 방문 표시를 음수로 표현 -1, -2, -3 ...
bool found = false;

while (!is_empty(queue))
{
    Position cur = dequeue(queue);
    for (int dir=0; dir<4; dir++)
    {
        if (movable(cur,dir))
        {
            Position p = move_to(cur,dir);
            maze[p.x][p.y] = maze[cur.x][cur.y] -1; // 방문 표시를 음수로 표현하기 때문에 현재 칸에서 1 떨어진 위치를 +1 증가가 아닌 -1 감소로 표현
            if (p.x == n-1 && p.y == n-1)
            {    
                printf("Found the path.\n");
                found = true;
                break;
            }
            enqueue(queue, p);
        }
    }
}


큐의 변형
- Deque (Double Ended queue)
  양 쪽 끝에서 삽입과 삭제가 허용되는 큐
  "덱" 혹은 "디큐"라고 읽음
- 우선순위 큐 (priority queue)
  큐에 들어온 순서와 무관하게 큐에 저장된 값들 중에서 가장 큰 값이 (혹은 가장 작은 값이) 가장 먼저 꺼내지는 큐
  배열이나 연결리스트 등의 일차원적인 자료 구조로는 표현의 한계가 있음
  대표적인 구현 방법으로는 이진 힙(binary heap)이 있음