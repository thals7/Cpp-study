분할정복법
- 분할: 해결하고자 하는 문제를 작은 크기의 동일한 문제들로 분할
- 정복 : 각각의 작은 문제를 순환적으로 해결
- 합병 : 작은 문제의 해를 합하여(merge) 원래 문제에 대한 해를 구함
-> 본질적으로 recursion을 사용하여 문제를 해결


합병정렬 merge sort
- 데이터가 저장된 배열을 절반으로 나눔
- 각각을 순환적으로 정렬
- 정렬된 두 개의 배열을 합쳐 전체를 정렬


mergeSort(A[], p, r) // A[p...r]을 정렬
{
    if (p <= r)
    {
        q <- (p+r)/2; // p,r의 중간 지점 계산
        mergeSort(A, p, q); // 전반부 정렬
        mergeSort(A, q+1, r); // 후반부 정렬
        merge(A, p, q, r); // 합병
    }
}

merge(A[], p, q, r)
{
    정렬되어 있는 두 배열 A[p...q]와 A[q+1, r]을 합하여
    정렬된 하나의 배열 A[p...r]을 만든다
}

void merge(int data[], int p, int q, int r) // data[p...q]와 data[q+1...r] 은 이미 정렬되어있다고 가정
{
    int i=p, j=q+1, k=p; // k는 합병중인 tmp 배열의 차례를 나타냄
    int tmp[data.length()]; // 두 배열을 합병 정렬한 것을 저장해둘 임시 배열

    while (i <= q && j <= r)
    {
        if (data[i] <= data[j])
            tmp[k++] = tmp[i++];
        else tmp[k++] = tmp[j++];
    }
    while (i <= q) // data[q+1...r]에 있던 숫자가 모두 정렬되었고 data[p...q]에는 남은 숫자가 존재할 때
        tmp[k++] = tmp[i++];
    while (j <= r) // data[p...q]에 있던 숫자가 모두 정렬되었을때 data[q+1...r]에는 남은 숫자가 존재할 때
        tmp[k++] = tmp[j++];
    for (int i=p; i<=r; i++)
        data[i] = tmp[i]; 
}

시간복잡도 T(n)
데이터가 n개일 때 merge sort로 데이터를 정렬하는데 걸리는 시간
if n=1 : 0
   otherwise : T([n/2]) + T([n/2]) + n
= O(nlog₂n)