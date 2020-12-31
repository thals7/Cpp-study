힙의 응용 : 우선순위 큐

- 최대 우선순위 큐 : 다음의 두 가지 연산을 지원하는 자료구조
  - INSERT(x) : 새로운 원소 x를 삽입
  - EXTRACT_MAX() : 최대값을 삭제하고 반환
- MAX HEAP을 이용하여 최대 우선순위 큐를 구현

- 최소 우선순위 큐 : EXTRACT_MAX 대신 EXTRACT_MIN을 지원하는 자료구조


MAX_HEAP_INSERT(A, key) // A는 heap, key는 삽입하려는 값
{
    heap_size = heap_size + 1;
    A[heap_size] = key; // key값을 배열의 마지막 노드에 삽입
    i = heap_size;
    while ( i>1 and A[PARENT(i)] < A[i] ) // key값이 든 노드가 루트 노드가 아니고 부모 노드의 값보다 클 때
    {
        exchange A[i] and A[PARENT(i)]; // 부모 노드의 값과 key값 교환
        i = PARENT(i);
    }
}
// 시간복잡도 : O(log₂n) complete binary tree의 높이

EXTRACT_MAX(A) // max heap에서 최대값은 항상 루트 노드에 존재
1 if heap_size[A] < 1
2     then error "heap underflow"
3 max <- A[1] // max에 루트 노드(A[1])의 값 저장
4 A[1] <- A[heap_size[A]] // A의 가장 마지막 노드의 값을 루트 노드로 옮겨옴
5 heap_size[A] <- heap_size[A] - 1 // 힙 사이즈를 1 줄임
6 MAX_HEAPIFY(A,1) // 루트 노드에 있는 값(사이즈를 줄이기 전 마지막 노드에서 옮겨온)에 대해 heapify
7 return max
// 시간복잡도 : O(log₂n)