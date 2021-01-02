트리
- 계층적인 구조를 표현
  - 조직도
  - 디렉토리와 서브디렉토리 구조
  - 가계도

용어
- 루트
  - 트리는 노드(node)들과 노드들을 연결하는 링크(link)들로 구성됨
  - 맨 위의 노드를 루트(root)라고 부름
- 부모-자식 관계
  - 두 노드 중 위에 있는 노드를 부모, 아래에 있는 노드를 자식이라고 함
- 형제관계
  - 부모가 동일한 노드들을 형제 관계라고 부름
  - 루트노드를 제외한 트리의 모든 노드들은 유일한 부모 노드를 가짐
- 리프(leaf) 노드
  - 자식이 없는 노드들을 leaf 노드라고 부름
  - 리프노드가 아닌 노드들을 내부(internal) 노드라고 부름
- 조상-자손 관계
  - 부모-자식 관계를 확장
- 부트리
  - 트리에서 어떤 한 노드와 그 노드의 자손들로 이루어진 트리를 부트리(subtree)라고 부름
- 레벨
  - 루트 노드를 level 1이라고 하면 그 아래의 자식 노드들은 level 2, 그 아래는 level 3...
- 높이
  - 서로 다른 레벨의 개수

트리의 기본적인 성질
- 노드가 N개인 트리는 항상 N-1개의 링크(link)를 가짐
- 트리에서 루트에서 어떤 노드로 가는 경로는 유일. 또한 임의의 두 노드간의 경로도 유일 (같은 노드를 두 번 이상 방문하지 않는다는 조건 하에)


이진 트리 binary tree
- 각각의 노드가 최대 2개의 자식을 가지는 트리
- 각각의 자식 노드는 자신이 부모의 왼쪽 자식인지 오른쪽 자식인지가 지정됨 (자식이 하나인 경우에도)

Full and Complete Binary Trees
- 높이가 h인 full binary tree는 2^h-1개의 노드를 가짐
- 노드가 N개인 full 혹은 complete 이진 트리의 높이는 O(logN) (노드가 N개인 이진트리의 높이는 최악의 경우 N이 될 수도 있음)

이진 트리의 표현
- 연결구조 (linked Structure) 표현
  - 각 노드에 하나의 데이터 필드와 왼쪽자식(left), 오른쪽 자식(right), 그리고 부모노드(p)의 주소를 저장 (부모노드의 주소는 반디시 필요한 경우가 아니면 보통 생략)
  - 루트노드의 주소는 따로 보관

이진 트리의 순회 (traversal)
- 순회 : 이진 트리의 모든 노드를 방문하는 일
- 중위(inorder) 순회
- 전위(preorder) 순회
- 후위(postorder) 순회
- 레벨오더(level-order) 순회

이진 트리의 Inorder 순회 (중위 순회)
- 이진 트리를 루트노드 r, 왼쪽 부트리 TL, 오른쪽 부트리 TR로 나누어 생각
1. 먼저 TL을 inorder로 순회
2. r을 순회
3. TR을 inorder로 순회
-> 근본적으로 전위/중위/후위 순회는 recursive

Inorder-Tree-Walk(x) // x를 루트로 하는 트리를 inorder 순회
1 if x != NIL // x != NULL
2     then Inorder-Tree-Walk(left(x))
3          print key[x]
4          Inorder-Tree-Walk(right(x))
시간복잡도 O(n)

Preorder-Tree-Walk(x)
1 if x != NIL // x != NULL
2     then print key[x]
3          Inorder-Tree-Walk(left(x))       
4          Inorder-Tree-Walk(right(x))

Postorder-Tree-Walk(x)
1 if x != NIL // x != NULL
2     then Inorder-Tree-Walk(left(x))
3          Inorder-Tree-Walk(right(x))
4          print key[x]

In/Pre/Postorder는 노드를 방문하는 순서를 제외하곤 모두 동일

Level-Order 순회
- 레벨 순으로 방문, 동일 레벨에서는 왼쪽에서 오른쪽 순서로
- 큐(queue)를 이용하여 구현

Level-Order-Tree-Traversal()
  visit the root;
  Q <- root; // Q is a queue
  while Q is not empty do
      v <- dequeue(Q);
      visit children of v;
      enqueue children of v into Q;
  end
end