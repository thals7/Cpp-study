재귀적 알고리즘 설계
- 적어도 하나의 base case, 즉 순환되지 않고 종료되는 case가 있어야 함
- 모든 case는 결국 base case로 수렴해야 함
- 암시적(implicit) 매개변수를 명시적(explicit) 매개변수로 바꾸기


순차 탐색
ex)
// data[0]에서 data[n-1] 사이에서 target을 검색. 하지만 검색 구간의 시작 인덱스 0은 보통 생략함. 즉 암시적 매개변수
int search(int data[], int n, int target) // Iterative
{
	for (int i=0; i<n; i++)
		if (data[i]==target)
			return i;
	return -1;
}
// data[begin]에서 data[end] 사이에서 target을 검색. 즉, 검색구간의 시작점을 명시적으로 지정
int search(int data[], int begin, int end, int target) // Recursive
{
	if (begin>end)
		return -1;
	else if (target==items[begin])
		return begin;
	else
		return search(data, begin+1, end, target);
} // = return search(data, begin, end-1, target)
-> 이 함수를 search(data, 0, n-1, target)으로 호출한다면 위의 함수와 완전히 동일한 일을 함

최대값 찾기
ex)
// data[begin]에서 data[end] 사이에서 최대값을 찾아 반환. 단, begin<=end
int findMax(int data[], int begin, int end)
{
	if (begin==end)
		return data[begin];
	else
		return max(data[begin], findMax(data, begin+, end))
}

이진 탐색
ex)
int binarySearch(int data[], int n, int target) // Iterative
{
	int begin = 0; end = n-1;
	while begin<=end
	{
		int middle = (begin+end)/2;
		if (data[middle] == target)
			return middle;
		else if (data[middle] > target)
			end = middle-1;
		else
			begin = middle+1;
	}
	return -1;
}

int binarySearch(int data[], int target, int begin, int end) // Recursive
{
	if (begin>end)
		return -1;
	else
	{
		int middle = (begin+end)/2
		if (data[middle] == target)
			return middle;
		else if (data[middle] > target)
			return binarySearch(data, target, begin, middle-1);
		else
			return binarySearch(data, target, middle+1, end);
	}
}


미로찾기

Recursive Thinking
현재 위치에서 이미 가본 곳을 다시 지나지 않고 출구까지 가는 경로가 있으려면
  1) 현재 위치가 출구이거나 혹은
  2) 이웃한 셀들 중 하나에서 이미 가본 곳을 다시 지나지 않고 출구까지 가는 경로가 있거나

bool findnpath(x,y)
	if (x,y) is either on the wall or a visited cell
		return false;
	else if (x,y) is the exit
		return true;
	else
		mark (x,y) as a visited cell;
		for each neighbouring cell (x',y') of (x,y) do
			if (x',y') is a pathway cell and not visited
				if findpath(x',y')
					return true;
		return false;