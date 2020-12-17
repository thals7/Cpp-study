이진검색 Binary Search
- 배열(중간에 있는 데이터를 한번에 꺼낼 수 있는 구조)에 데이터들이 오름차순으로(또는 내림차순으로) 정렬되어 저장

int binarySearch(int n, char *data[], char *target)
{
    int begin = 0; end = n-1;
    while (begin <= end)
    {
        int middle = (begin + end) / 2;
        int result = strcmp(data[middle], target);
        if (result == 0)
            return middle;
        else if (result < 0)
            begin = middle + 1;
        else
            end = middle - 1;
    }
    return -1;
}
// 한 번 비교할 때마다 남아있는 데이터가 절반으로 줄어듦
// 시간복잡도는 O(log2n)

-데이터가 연결리스트에 오름차순으로 정렬되어 있다면?
  - 연결리스트에서는 가운데(middle) 데이터를 O(1)시간에 읽을 수 없음
  - 따라서 이진검색을 할 수 없음
-순차검색의 시간복잡도는 O(n)이고 이진검색은 O(log2n)
  - 이 둘의 차이는 매우 큼


버블 정렬 bubble sort
- 두 인접한 원소를 검사하여 정렬

void bubbleSort(int data[], int n)
{
    for (int i=n-1; i>0; i--)
    {
        for (int j=0; j<i; j++)
        {
            if (data[j] > data[j+1])
            {
                int tmp = data[j];
                data[j] = data[j+1];
                data[j+1] = tmp;
            }
        }
    }
}
// 시간복잡도는 O(n^2)
// 최악, 최선, 평균의 시간복잡도가 모두 같음


삽입 정렬 Insertion sort
- 어떤 하나의 배열에 이미 데이터가 정렬되어 있을때 새로운 데이터를 정렬된 배열의 자기 자리를 찾아가게 하는 삽입 연산을 반복적으로 수행함으로써 데이터를 정렬
void insertion_sort(int n, int data[])
{
    for (int i=1; i<n; i++)
    {
        int tmp = data[i];
        int j = i-1;
        while (j>=0 && data[j]>data[i])
        {
            data[j+1] = data[j];
            j--;
        }
        data[j+1] = tmp;
    }
}
// 시간복잡도는? 최선: O(n) 최악: O(n^2)
// 일반적인 상황이라면 버블 정렬보다 삽입 정렬이 대략 2배정도 빠름


다른 정렬 알고리즘
- 퀵소트(quicksort) 알고리즘
  - 최악의 경우 O(n^2), 하지만 평균 시간복잡도는 O(nlog2n)
- 최악의 경우 O(nlog2n)의 시간복잡도를 가지는 정렬 알고리즘
  - 합병 정렬(merge sort)
  - 힙 정렬(heap sort) 등
- 데이터가 배열이 아닌 연결리스트에 저장되어 있다면?
  - O(n^2)의 시간복잡도를 벗어나기 어려움