미로찾기
- 이미 방문한 위치에는 표시를 해서 무한루프를 방지
- 현재 위치에서 일정한 규칙으로 다음 위치로 이동
  - 북, 동, 남, 서의 순서로 검사하여,
  - 그 방향으로 갈 수 있으면, 즉 아직 안 가본 위치면서 벽이 아니면 그 방향으로 감
- 아무 방향으로도 갈 수 없으면 그 위치에 오기 직전 위치로 되돌아 감

1. 현재 위치는 출발점(0,0)
2. 다음을 반복
  1) 현재 위치에 방문했다는 표시를 함
  2) 현재 위치가 출구라면 종료
  3) 현재 위치에서 북, 동, 남, 서 4방향에 대해서 순서대로
    - 그 방향으로 이동할 수 있는지 (즉 벽이 아니고, 미로의 외부도 아니고, 이미 방문한 위치도 아닌지) 검사
    - 만약 갈 수 있으면 현재 위치를 스택에 push하고 그 방향으로 이동
  4) 만약 3번에서 4방향 중 어느 쪽으로도 갈 수 없었다면 스택에서 pop한 후 그 위치로 돌아감 (만약 돌아갈 위치가 없다면 원래 길이 없는 미로)

ex)
//maze.c

#include <stdio.h>
#include "stack.h"
#include "pos.h"

#define MAX 100
#define PATH 0 // 지나갈 수 있는 위치
#define WALL 1 // 지나갈 수 없는 위치
#define VISITED 2 // 이미 방문한 위치
#define BACKTRACKED 3 // 방문했다가 되돌아 나온 위치

int maze[MAX][MAX]; // 미로에 대한 정보를 2차원 배열로 표현
int n; // 미로의 크기

void read_maze();
void print_maze();
bool movable(POS pos, int dir);

int main()
{
  read_maze(); // maze.txt파일로부터 미로의 모양을 배열 maze로 입력받음

  Stack s = create(); // 위치를 저장할 스택
  Position cur; // 미로 내 현재 위치를 표현하는 구조체
  cur.x = 0;
  cur.y = 0;

  while(1)
  {
    maze[cur.x][cur.y] = VISITED; // 현재 위치를 방문했다고 표시
    if (cur.x == n-1 && cur.y == n-1) // 현재 위치가 출구일 때
    {
      printf("Found the path.\n");
      break;
    }
    bool forwarded = false; // 4방향 중 한 곳으로 전진하는데 성공했는지를 표시
    for (int dir = 0; dir<4; dir++) // 0:N, 1:E, 2:S, 3:W
    {
      if (movable(cur, dir)) // dir 방향으로 이동할 수 있는지 검사
      {
        push(s, cur); // 현재 위치를 stack에 push한 뒤
        cur = move_to(cur, dir); // dir 방향으로 한 칸 이동한 위치가 새로운 cur이 됨
        forwarded = true;
        break;
      }
    }
    if (!forwarded) // 4방향 중 어느 곳으로도 가지 못했다면
    {
      maze[cur.x][cur.y] = BACKTRACKED; // 왔다가 되돌아간 위치임을 표시
      if (is_empty(s)) // 되돌아갈 위치가 없다면 원래 출구까지 가는 길이 없는 미로
      {
        printf("No path exists.\n");
        break;
      }
      cur = pop(s); // 스택에서 pop한 위치가 새로운 현재위치 cur이 됨
    }
  }

  print_maze();
}

bool movable(POS pos, int dir);
{
  int nX = pos.x + offset[dir][0];
  int nY = pos.y + offset[dir][1];
  if (nX < 0 || nY < 0 || nX > n-1 || nY > n-1)
    return false;
  else if (maze[nX][nY] == 0) return true;
  else false;
}


//pos.h
#ifndef POS_H
#define POS_H

typedef struct pos
{
  int x, y;
} Position;

Position move_to(Position pos, int dir);

#endif POS_H

//pos.c
#include "pos.h"

int offset[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} }; // 북, 동, 남, 서 방향으로 한 칸 이동할 때 x좌표와 y좌표의 변화량

Position move_to(Position pos, int dir)
{
  Position next;
  next.x = pos.x + offset[dir][0];
  next.y = pos.y + offset[dir][1];
  return next; 
}


보완해야 할 점
- 왔다가 되돌아왔을 때 다시 북쪽부터 검사할 필요 없이 되돌아온 방향 다음부터 검사하는게 나음
- stack에 위치를 저장하는 것이 아니라 내가 이동한 방향을 저장하는 것은? -> 얼마든지 가능


알고리즘의 개선
ex)
int main()
{
  read_maze();

  Stack s = create(); // position 대신 정수들을 저장하는 스택
  Position cur;
  cur.x = 0;
  cur.y = 0;

  int init_dir = 0; // 어떤 위치에 도착했을 대 처음을 ㅗ시도해 볼 이동 방향 (0:N, 1:E, 2:S, 3:W)

  while(1)
  {
    maze[cur.x][cur.y] = VISITED;
    if (cur.x == n-1 && cur.y == n-1) 
    {
      printf("Found the path.\n");
      break;
    }
    bool forwarded = false; // 4방향 중 한 곳으로 전진하는데 성공했는지를 표시
    for (int dir = init_dir; dir<4; dir++) // 0:N, 1:E, 2:S, 3:W
    {
      if (movable(cur, dir))
      {
        push(s, dir); // 스택에 현재 위치 대신 이동하는 방향을 push
        cur = move_to(cur, dir);
        forwarded = true;
        init_dir = 0; // 처음 방ㅂ문하는 위치에서는 0번 방향부터 시도
        break;
      }
    }
    if (!forwarded)
    {
      maze[cur.x][cur.y] = BACKTRACKED; // 왔다가 되돌아간 위치임을 표시
      if (is_empty(s)) // 되돌아갈 위치가 없다면 원래 출구까지 가는 길이 없는 미로
      {
        printf("No path exists.\n");
        break;
      }
      int d = pop(s);
      cur = move_to(cur, (d+2)%4); // 이전 위치에서 지금 위치에 올 때 d 방향으로 이동했었다면 되돌아 가려면 (d+2)%4번 방향으로 이동하면 됨
      init_dir = d+1; // 되돌아간 위치에서는 d+1번 방향부터 시도해보면 됨
    }
  }  
  print_maze();
}