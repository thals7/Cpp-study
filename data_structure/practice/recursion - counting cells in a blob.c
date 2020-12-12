- binary 이미지
- 각 필셀은 background pixel이거나 혹은 image pixel
- 서로 연결된 image pixel들의 집합을 blob이라고 부름
- 상하좌우 및 대각방향으로도 연결된 것으로 간주

입력 :
  N*N 크기의 2차원 그리드
  하나의 좌표(x,y)
출력 :
  픽셀 (x,y)가 포함된 blob의 크기
  (x,y)가 어떤 blob에도 속하지 않는 경우에는 0

Recursive Thinking
현재 픽셀이 속한 blob의 크기를 카운트하려면
	if (x,y) outside the grid
		return 0;
	else if (x,y) != image color or already counted
		return 0;
	else
		count = 1;
		현재 픽셀의 중복 카운트 방지를 위해 다른 색으로 칠함
		현재 픽셀에 이웃한 모든 픽셀들에 대해서
			그 픽셀이 속한 blob의 크기를 카운트하여 카운터에 더함
		return count;

ex)
#include <stdio.h>

#define BACKGROUND_COLOR 0
#define IMAGE_COLOR 1
#define ALREADY_COUNTED 2

int size = 8
int grid[size][size] = {
    {1, 0, 0, 0, 0, 0, 0, 1} , 
    {0, 1, 1, 0, 0, 1, 0, 0} , 
    {1, 1, 0, 0, 1, 0, 1, 0} , 
    {0, 0, 0, 0, 0, 1, 0, 0} , 
    {0, 1, 0, 1, 0, 1, 0, 0} , 
    {0, 1, 0, 1, 0, 1, 0, 0} , 
    {1, 0, 0, 0, 1, 0, 0, 1} , 
    {0, 1, 1, 0, 0, 1, 1, 1}
};

int countCells(int x, int y)
{
	if (x<0 || x>=size || y<0 || y>=size)
		return 0;
	else if (grid[x][y] != IMAGE_COLOR)
		return 0;
	else
		grid[x][y] = ALREADY_COUNTED;
		return 1 + countCells(x,y-1) + countCells(x+1,y-1) + countCells(x+1,y) + countCells(x+1,y+1) + countCells(x,y+1) + countCells(x-1,y+1) + countCells(x-1,y) + countCells(x-1,y-1);
}

int main()
{
	int x,y;
	printf("좌표 값 입력: ");
	scanf("%d %d", &x, &y);
	printf("해당 픽셀이 포함된 Blob의 크기는 %d입니다.\n", countCells(x,y));

	return 0;
}