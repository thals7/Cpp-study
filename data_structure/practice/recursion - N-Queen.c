N-Queen Problem
- 크기가 N*N인 체스판 위에 N개의 퀸을 놓음
- 이 때 어떤 2개의 퀸도 동일한 행이나 열, 대각선에 위치해선 안됨

상태공간트리
- 찾는 해를 포함하는 트리
- 즉 해가 존재한다면 그것은 반드시 이 트리의 어떤 한 노드에 해당함
- 따라서 이 트리를 체계적으로 탐색하면 해를 구할 수 있음
- 상태공간트리의 모든 노드를 탐색해야 하는 것은 아님

Backtracking 되추적 기법
- 상태공간트리를 깊이 우선 방식DFS으로 탐색하여 해를 찾는 알고리즘

Design Recursion

int cols[N+1]; // 1번에서 level번째 말이 어디에 놓였는지 표현하는 배열 (cols[i] = j는 i번 말이 (i행,j열)에 놓였음을 의미)
bool queens(int level) // 현재 노드의 레벨
{
	if (!promising(level))
		return false;
	else if (level == N) // promising 테스트를 통과했다는 가정 하에 level==N이면 모든 말이 놓였다는 의미
		return true;
		// for (int i=1; i<=N; i++) printf("(%d, %d)", i, cols[i]);
	for (int i=1; i<=N; i++)
	{
		cols[level+1] = i; // level+1 행의 1번열부터 N번열까지 순서대로 놓아봄
		if (queens(level+1))
			return true;
	}
	return false;
}

promising test
- 함수를 한 번 실행할때마다 promising test를 하므로 앞의 말들 간에는 충돌이 없음이 보장되어있음
- 따라서 마지막에 놓인 말이 이전에 놓인 다른 말들과 충돌하는지 검사하는 것으로 충분
- 1~level-1의 행에 놓여있는 말들이 각각 level번째 행에 놓여있는 말과 충돌하는지 검사

bool promising(int level)
{
	for (i=1; i<level; i++)
	{
		if (cols[i] == cols[level]) // 같은 열에 놓였는지 검사
			return false;
		else if (level-i == Math.abs(cols[level]-cols[i]) // 같은 대각선에 놓였는지 검사 (마지막에 놓인 말로부터 떨어진 가로, 세로 거리가 같으면 같은 대각선에 놓인 것임)
			return false;
	}
	return true;
}