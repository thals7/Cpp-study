Heapsort
- 최악의 경우 시간복잡도 O(nlog₂n)
- Sorts in place : 추가 배열 불필요
- 이진 힙(binary heap) 자료구조를 사용

Heap의 정의
(1) Complete Binary Tree 이면서
    - binary tree (이진 트리) : 각각의 노드가 최대 두 명의 자식을 가질 수 있음 (한 명인 경우도 가능)
    - full binary tree : 모든 레벨에 노드들이 꽉 차있는 상태
    - complete binary tree : 마지막 레벨을 제외하면 완전히 꽉 차있고, 마지막 레벨에는 오른쪽부터 연속된 몇 개의 노드가 비어있을 수 있음

(2) heap property를 만족
    - max heap property : 부모는 자식보다 크거나 같음
    - min heap property : 부모는 자식보다 작거나 같음

Heaps
- 동일한 데이터를 가진 서로 다른 힙이 존재할 수 있음 (힙은 유일하지 않음)

Heap의 표현
- 힙은 일차원 배열로 표현 가능 : A[1...n]
    - 루트 노드 A[1]
    - A[i]의 부모 = A[i/2]
    - A[i]의 왼쪽 자식 = A[2i]
    - A[i]의 오른쪽 자식 = A[2i+1]


기본 연산 : MAX-HEAPIFY
: 전체를 힙으로 만들기
- 트리의 전체 모양은 complete binary tree
  왼쪽, 오른쪽 부트리(subtree)는 그 자체로 heap일 때
  유일하게 루트만이 heap property를 만족하지 않는 경우 (루트의 값이 자식 노드의 값보다 작은 경우)
- 루트에 저장된 값을 아래로 내려 보내고 빈 루트에 다른 값을 채움
  (1) 루트의 자식 노드 중 큰 값과 루트값의 자리를 바꿈
  (2) 루트값의 자리를 바꾼 결과 부트리가 heap property를 만족하지 않는다면 (1)과 같은 방법으로 전체가 heap property를 만족할 때까지 자리를 exchange

MAX-HEAPIFY : recursive version
MAX-HEAPIFY(A, i) // 노드 i를 루트로 하는 서브트리를 heapify
{
  if there is no child of A[i] // base case
    return;
  k <- index of the biggest child of i;
  if A[i] >= A[k]
    return;
  exchange A[i] and A[k];
  MAX-HEAPIFY(A, k);
}
// root 노드에 대한 heapify는 MAX-HEAPIFY(1)을 호출하면 됨

MAX-HEAPIFY : iterative version
MAX-HEAPIFY(A, i)
{
  while A[i] has a child do
    k <- index of the biggest child of i;
    if A[i] >= A[k]
      return;
    exchange A[i] and A[k];
    i = k;
  end.
}

Heapify의 시간복잡도
- 트리의 높이를 h라고 했을 때 시간복잡도는 O(h)
- heap은 complete binary tree이므로 노드의 수가 n일때 h=Θ(logn)


정렬할 배열을 힙으로 만들기
- heap-size[A] <- length[A] : 정렬할 데이터의 개수
- for i <- [length[A]/2] down to 1
  리프노드의 부모노드, 즉 처음으로 자식 노드를 가지는 부모노드부터 heapify 가능 여부를 판단
    do MAX-HEAPIFY(A, i)
- 시간복잡도 : O(n)
  Heapify에 걸리는 시간은 logn, for문은 n/2번 수행되므로 시간복잡도는 2/n*logn = O(nlogn) -> But! 항상 루트 노드에 대해서 heapify를 하는 것이 아니라 마지막 리프노드의 부모노드부터 heapify를 수행하므로 2/n*logn은 실제 시간보다 과도하게 계산된 시간임
  따라서 이를 좀 더 정확하게 분석해보면 O(n)이 됨
- Heap sort에서 실제로 힙을 정렬하는 과정에서 필요한 시간복잡도가 O(nlogn)이므로 힙을 만드는 단계의 시간복잡도가 n이든 nlogn이든 상관 없이 Heap sort의 시간복잡도는 O(nlogn)

Heapsort
(1) 주어진 데이터로 힙을 생성
(2) 힙에서 최대값(루트)을 가장 마지막 값과 교환
(3) 힙의 크기가 1 줄어든 것으로 간주함. 즉, 가장 마지막 값은 힙의 일부가 아닌 것으로 간주
(4) 루트노드에 대해서 HEAPIFY(1) 실행
(5) 2~4번 반복

Heapsort와 시간복잡도
HEAPSORT(A)
1. BUILD-MAX-HEAP(A)                 : O(n)
2. for i <- heap_size downto 2 do    : n-1 times
3.   exchange A[1] <-> A[i]          : O(1)
4.   heap_size <- heap_size - 1      : O(1)
5.   MAX-HEAPIFY(A, 1)               : O(log₂n)
// Total time : O(nlog₂n)