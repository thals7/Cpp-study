분할정복법
- 분할 : 배열을 다음과 같은 조건이 만족되도록 두 부분으로 나눔
        elements in lower parts <= elements in upper parts
- 정복 : 각 부분을 순환적으로 정렬
- 합병 : nothing to do

실행 단계
1. 정렬한 배열이 주어졌을 때, 마지막 수를 기준(pivot)으로 삼음
2. 기준보다 작은 수는 기준의 왼쪽, 나머지는 기준의 오른쪽에 오도록 재배치(분할)
3. 기준의 왼쪽과 오른쪽을 각각 순환적으로 정렬


quickSort(A[], p, r) // A[p...r]을 정렬
{
    if (p < r)
    {
        q = partition(A, p, r); // 분할 (q는 pivot의 위치)
        quicksort(A, p, q-1); // 왼쪽 부분배열 정렬
        quicksort(A, q+1, r) // 오른쪽 부분배열 정렬
    }
}

partition(A[], p, r)
{
    배열 A[p...r]의 원소들을 A[r]을 기준으로 양쪽으로 재배치하고
    A[r]이 자리한 위치를 return;
}

partition
: A[p...r]에서 A[r]을 pivot으로 설정한 뒤 A[p]부터 A[r-1]까지 비교 
  pivot보다 작은 값들 중 마지막 값을 i, 지금 검사하려는 값의 위치를 j로 설정
  A[r]보다 작은 값들은 A[p...i]에 두고 큰 값들은 A[i+1,j-1]에 둠
  만약 A[j]<A[r]이라면 A[j]의 값을 A[i+1]의 값과 바꾼 뒤 i를 뒤로 한 칸 전진(또는 i를 먼저 1 증가시킨 뒤 A[j]의 값과 A[i]의 값 교환)

if A[j] >= A[r]
    j <- j+1;
else
    i <- i+1; // i값을 1 증가시킴
    exchange A[i] and A[j];
    j <- j+1;


int partition(int data[], int p, int r)
{
    int pivot = data[r], i = p-1;
    int tmp;
    for (int j=p; j<=r; j++)
    {
        if (A[j] >= pivot)
            j++;
        else
        {    
            i++;
            tmp = A[i];
            A[i] = A[j];
            A[j] = tmp;
            j++;
        }
    }
    tmp = A[i+1];
    A[i+1] = A[r];
    A[r] = tmp; // 맨 마지막에 pivot은 작은 배열과 큰 배열 사이인 data[i+1]위치로 옮겨줌
    return i+1;
}
// partition의 수행시간은 O(n) (데이터가 n개일 때 n-1번 비교연산 수행... 평균 n번의 비교가 이루어짐)

quick sort의 시간복잡도
: 최악의 경우
- 항상 한 쪽은 0개, 다른 쪽은 n-1개로 분할되는 경우
- 이미 정렬된 입력 데이터 (피봇을 최솟값이나 최댓값으로 선택한 경우)
T(n) = n(n-1)/2 = O(n^2)

: 최선의 경우
- 항상 절반으로 분할되는 경우 (merge sort와 같은 시간복잡도를 가짐)
T(n) = O(nlog₂n)

: Balanced Partition
- 항상 한쪽이 적어도 1/9 이상이 되도록 분할된다면?
  항상 1:9로 분할되면 맨 오른쪽 트리가 1이 될 때까지 트리가 그려짐
  이 때 깊이는 logn이고 n번의 비교연산을 수행하므로 O(nlogn)

Pivot의 선택
- 첫번째 값이나 마지막 값을 피봇으로 선택
  - 이미 정렬된 데이터 혹은 거꾸로 정렬된 데이터가 최악의 경우
  - 현실의 데이터는 랜덤하지 않으므로 (거꾸로) 정렬된 데이터가 입력으로 들어올 가능성은 매우 높음
  - 따라서 좋은 방법이라고 할 수 없음
- "Median of Three"
  - 첫번째 값과 마지막 값, 그리고 가운데 값 중에서 중간값(median)을 피봇으로 선택
  - 최악의 경우 시간복잡도가 달라지지는 않음
- Randomized Quicksort
  - 피봇을 랜덤하게 선택
  - no worst case instance, but worst case execution -> 다른 방법의 경우 어떤 입력이 최악의 경우인지가 정해지지만 피봇을 랜덤하게 선택하면 어떤 데이터가 들어오더라도 랜덤값에 의해 결정되므로 worst case 실행이 존재함
  - 평균 시간복잡도 O(nlogn)