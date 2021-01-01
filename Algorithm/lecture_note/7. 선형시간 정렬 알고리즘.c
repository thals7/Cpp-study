Sorting in Linear Time

(1) Counting Sort
  - n개의 정수를 정렬하라. 단 모든 정수는 0에서 k사이의 정수이다.
  - ex) n명의 학생들의 시험정수를 정렬하라. 단 모든 점수는 100 이하의 양의 정수이다.

- k=5인 경우
  - 길이 k인 배열에 각 정수의 개수를 count
int A[n]; // 정렬할 데이터
int C[k] = {0, }; // counter배열
for (int i = 1; i <= n; i++)
  C[A[i]]++;
for (int s = 1, i = 0; i <= k; i++) {
  for (int j = 0; j < C[i]; j++) {
    A[s++] = i;
  }
}
-> 대부분의 경우 정렬할 key값들은 레코드의 일부분이기 때문에 위의 코드는 제대로 된 정렬 알고리즘이라고 할 수 없음

countingSort[A, B, k]
for i <- 0 to k
    do C[i] <- 0 // counter C를 0으로 초기화
for j <- 1 to length[A]
    do C[A[j]] <- C[A[j]] + 1 // A에 존재하는 값에 대해 C배열에 카운팅
// C[i] now contains the number of elements equal to i
for i <- 1 to k
    do C[i] <- C[i] + C[i-1] // 누적합 구하기
// C[i] now contains the number of elements less than or equal to i
for j <- length[A] down to 1 // 배열 A에 저장된 데이터를 역으로 살펴보면서
    do B[C[A[j]]] <- A[j] // A[j]에 들어갈 값을 C의 인덱스를 참조하여 B 배열에 저장
       C[A[j]] <- C[A[j]] - 1 // C배열의 값 1 감소시킴

시간복잡도
- Θ(n+k), 또는 Θ(n) if k=O(n) // 일반적으로 n>k인 경우
- k가 클 경우 비실용적
- Stable 정렬 알고리즘
  - "입력에 동일한 값이 있을 때 입력에 먼저 나오는 값이 출력에서도 먼저 나온다"
  - Counting 정렬은 stable


(2) Radix Sort
  - n개의 d자리 정수 (길이가 d인 영문자도 가능)
  - 가장 낮은 자리수부터 정렬
  - 매 단계에서 사용되는 정렬 알고리즘은 반드시 stable해야함
    - Stable sort : 정렬을 할 때 동일한 데이터가 두 개 이상 있을 경우 입력에서 들어온 순서가 출력에서 그대로 유지됨
    - 즉, 첫번째 단계를 거치면 데이터들은 일의 자리를 기준으로 정렬됨. 두번째 단계를 거치면 단순히 십의 자리만으로 정렬이 되는 것이 아니라 일의 자리를 포함한 두 자리를 기준으로 봤을 때에도 정렬된 상태가 됨.

radixSort[A, d] // A는 d자리 정수가 저장된 배열
for i <- i to d
    do use a stable sort to sort array A on digit i

시간복잡도
- O(d(n+k))


정렬 알고리즘 정리
- Bubble sort / Insertion sort / Selection sort
  : worst, average 모두 시간복잡도가 Θ(n^2)
- Quick sort
  : worst Θ(n^2) average Θ(nlog₂n)
- Merge sort
  : Θ(nlog₂n)
- Heap sort
  : Θ(nlog₂n)
- Counting sort / Radix sort
  : Θ(n+k) / Θ(d(n+k))