Dynamic Set
- 일종의 집합 -> 이 때 데이터들이 고정되어 있지 않고 새로운 데이터가 추가되거나 기존의 데이터를 삭제하는 등 집합의 내용물이 계속해서 변함
- 여러 개의 키(key)를 저장
- 다음과 같은 연산들을 지원하는 자료구조
  - INSERT : 새로운 키의 삽입
  - SEARCH : 키 탐색
  - DELETE : 키 삭제
- Dynamic Set, Dictionary 또는 Search Structure라고 부름

                Search      Insert      Delete
배열      정렬O  O(logn)       O(n)        O(n)
         정렬X    O(n)      O(1),O(n)     O(1)
연결리스트 정렬O    O(n)        O(n)        O(1)
         정렬X    O(n)        O(1)        O(1)
- 정렬된 혹은 정렬되지 않은 배열 혹은 연결 리스트를 사용할 경우 INSERT, SEARCH, DELETE 중 적어도 하나는 O(n)

세가지 연산 모두 O(n)보다 효율적인 알고리즘은 없는가?
- 이진탐색트리(Binary Search Tree), 레드-블랙 트리, AVL-트리 등의 트리에 기반한 구조들
- Direct Address Table, 해쉬 테이블 등


검색트리
- Dynamic Set을 트리의 형태로 구현
- 일반적으로 SEARCH, INSERT, DELETE 연산이 트리의 높이(height)에 비례하는 시간복잡도를 가짐
- 이진탐색트리(Binary Search Tree), 레드-블랙(red-black tree), B-트리 등

이진탐색트리(BST)
- 이진트리이면서
- 각 노드에 하나의 키를 저장
- 각 노드 v에 대해서 그 노드의 왼쪽 부트리(subtree)에 있는 키들은 key[v](v에 저장된 key)보다 작거나 같고, 오른쪽 부트리에 있는 값은 크거나 같음


TREE-SEARCH(x, k) // x:루트 노드 k:찾는 값
1 if x = NIL or k = key[x] // key[x]:노드 x에 저장된 값
2     then return x
3 if k < key[x]
4     then return TREE-SEARCH(left[x], k)
5     else return TREE-SEARCH(right[x], k)
시간복잡도 : O(h), 여기서 h는 트리의 높이

TREE-SEARCH(x, k) // Iterative ver.
1 while x != NIL and k != key[x]
2     do if k < key[x]
3         then x <- left[x]
4         else x <- right[x]
5 return x

최소값 찾기
TREE-MINIMUM(x)
1 while left[x] != NIL
2     do x <- left[x]
3 return x
최소값은 항상 가장 왼쪽 노드에 존재 // 반대로 최대값은 항상 가장 오른쪽 노드에 존재
시간복잡도 : O(h)

Successor
- 노드 x의 successor란 key[x]보다 크면서 가장 작은 키를 가진 노드 (노드에 저장된 데이터를 크기순으로 정렬했을때 자신의 바로 다음 값)
- 모든 키들이 서로 다르다고 가정
- 3가지 경우가 존재
  (1) 노드 x의 오른쪽 부트리가 존재할 경우, 오른쪽 부트리의 최소값
  (2) 오른쪽 부트리가 없는 경우, 어떤 노드 y의 왼쪽 부트리의 최대값이 x가 되는 그런 노드 y가 x의 successor
    - 부모를 따라 루트까지 올라가면서 처음으로 누군가의 왼쪽 자식이 되는 노드 (쭉 오른쪽 링크를 타고 올라가다가 처음으로 왼쪽 링크를 타고 위로 올라가 만난 노드)
  (3) 그런 노드 y가 존재하지 않을 경우 successor가 존재하지 않음 (즉, x가 최대값)

TREE-SUCCESSOR(x)
1 if right[x] != NIL // 노드 x의 오른쪽 자식이 존재한다면
2     then return TREE-MINIMUM(right[x]) // 오른쪽 자식을 루트로 하는 서브트리에서 최소값을 찾음
3 y <- p[x] // p[x]: x의 부모노드
4 while y != NIL and x = right[y] // y!=NULL이고 x가 y의 오른쪽 자식인 동안
5     do x <- y
6        y <- p[y]
7 return y
시간복잡도 : O(h)

Predecessor
- 노드 x의 predecessor란 key[x]보다 작으면서 가장 큰 키를 가진 노드
- Successor와 반대
시간복잡도 : O(h)


TREE-INSERT(T, z) // T: binary search tree z: insert할 노드
1 y <- NIL
2 x <- root[T]
3 while x != NIL
4     do y <- x // y는 x의 바로 직전 노드
5        if key[z] < key[x]
6           then x <- left[x]
7           else x <- right[x]
8 p[z] <- y // x가 NULL이 되는 순간 y가 가리키는 노드의 자식으로 새로운 노드를 insert
9 if y = NIL // Tree T가 empty인 경우
10   then root[T] <- z
11   else if key[z] < key[y]
12           then left[y] <- z
13           else rught[y] <- z
시간복잡도 : O(h)


DELETE
- Case 1 자식노드가 없는 경우 : 리프노드인 경우 그냥 삭제
- Case 2 자식노드가 1개인 경우 : 자신의 자식노드를 원래 자신의 위치로
- Case 3 자식노드가 2개인 경우 : 삭제하려는 노드와 가장 가까운 값(Successor or Predecessor)을 이용
  - 삭제하려는 노드의 Successor(또는 predecessor)의 값을 삭제할 노드로 copy하고 Successor 노드를 삭제
  - 자식 노드가 2개인 노드의 Successor는 왼쪽 자식이 존재하지 않음. 즉, 자식노드의 개수는 무조건 0개 또는 1개. 따라서 Successor의 삭제는 Case 1 또는 2의 방법을 이용하면 됨


TREE-DELETE(T, z) // T: binary search tree z: delete할 노드
1   if left[z] = NIL or right[z] = NIL // 자식노드가 0개 또는 1개인 경우
2     then y <- z // y: 실제로 트리에서 삭제할 노드
3   else y <- TREE-SUCCESSOR(z) // 자식노드가 2개인 경우 삭제할 노드 y는 z의 successor
4   if left[y] != NIL // y의 자식은 0개 또는 1개인 상태에서 y의 왼쪽 자식이 존재한다면
5     then x <- left[y]
6   else x <- right[y]
7   if x != NIL
8     then p[x] <- p[y] // 현재 y의 부모를 x의 부모로 설정
9   if p[y] = NIL // y가 루트노드일때
10    then root[T] <- x
11  else if y = left[p[y]]
12    then left[p[y]] <- x
13  else right[p[y]] <- x
14  if y != z // Case 3의 경우(y가 애초에 삭제하려는 노드가 아닌 그 노드의 successor인 경우)
15    then key[z] <- key[y] // y에 저장되어있는 데이터를 z의 자리로 옮김
16      copy y satellite data into z
17  return y
시간복잡도 : O(h)


BST
- 각종 연산의 시간복잡도 O(h)
- 최악의 경우 트리의 높이 h=O(n)
  - But 이것은 실제 최악의 경우에 해당함. BST에 데이터들이 random하게 구성된다고 가정했을때, 평균 트리의 높이는 O(logn). 즉 Search, Insert, Delete의 시간복잡도는 O(logn)이 됨
- 균형 잡힌(balanced) 트리 (최악의 경우에도 높이가 O(logn)을 넘지 않게 수정된 이진검색트리)
  - 레드-블랙 트리 등
  - 키의 삽입이나 삭제시 추가로 트리의 균형을 잡아줌으로써 높이를 O(logn)으로 유지