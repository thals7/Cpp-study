레드-블랙 트리
- 이진탐색트리의 일종
- 균형잡힌 트리 : 높이가 O(log₂n)
- SEARCH, INSERT, DELETE 연산을 최악의 경우에도 O(log₂n) 시간
에 지원 (트리의 높이에 비례)

- 각 노드는 하나의 키(key), 왼쪽자식(left), 오른쪽 자식(right), 그리고 부모노드(p)의 주소를 저장
- 자식노드가 존재하지 않을 경우 NIL 노드라고 부르는 특수한 노드가 있다고 가정
- 따라서 모든 리프노드는 NIL노드
- 루트의 부모도 NIL노드라고 가정
- 노드들은 내부노드와 NIL노드로 분류
- But NIL 노드는 설명을 편하게 하기 위한 용도일 뿐 실제로 트리를 구현할 때 NIL 노드를 구현하는 것은 아님

레드-블랙 트리 : 정의
다음의 조건을 만족하는 이진탐색트리
(1) 각 노드는 red 혹은 black
(2) 루트노드는 black
(3) 모든 리프노드(NIL 노드)는 black
(4) red노드의 자식노드들은 전부 black (즉, red노드는 연속되어 등장하지 않음)
(5) 모든 노드에 대해서 그 노드로 부터 자손인 리프노드에 이르는 모든 경로에는 동일한 개수의 black노드가 존재

레드-블랙 트리 : 높이
- 노드 x의 높이 h(x)는 자신으로부터 리프노드까지의 가장 긴 경로에 포함된 에지의 개수
- 노드 x의 블랙-높이 bh(x)는 x로부터 리프노드까지의 경로상의 블랙노드의 개수 (노드 x 자신은 불포함)
- 높이가 h인 노드의 블랙-높이는 bh ≥ (h/2)
  - 조건 (4)에 의해 레드노드는 연속될 수 없기 때문
- 노드 x를 루트로하는 임의의 부트리는 적어도 2bh(x)-1개의 내부노드를 포함 (수학적 귀납법)
- n개의 내부노드를 가지는 레드블랙트리의 높이는 2log₂(n+1) 이하
  - n ≥ (2^bh)-1 ≥ (2^h/2)-1 이기 때문
-> 정의에서 설명한 5가지 조건을 만족한다면 트리의 높이는 자동으로 O(log₂n)이 됨


SEARCH
- 레드-블랙 트리는 기본적으로 BST이기 때문에 search는 BST와 동일

Left and Right Rotation : Insert와 Delete에서 공통적으로 필요한 기본 연산
- BST에서 한 노드를 중심으로 부분적으로 트리의 모양을 수정하는 연산
- 시간복잡도 O(1)
- 이진탐색트리의 특성을 유지

Left Rotation
- y = right[x] ≠ NIL이라고 가정
- 루트노드의 부모도 NIL이라고 가정

LEFT-ROTATE(T, x)
1   y <- right[x] // y는 x의 오른쪽 자식
2   right[x] <- left[y] // y의 왼쪽 자식을 x의 오른쪽 자식으로 바꿈
3   p[left[y]] <- x
4   p[y] <- p[x]
5   if p[x] = NIL[T] // x가 루트노드인 경우
6     then root[T] <- y
7     else if x = left[p[x]] // x의 부모 노드가 존재하는 경우
8       then left[p[x]] <- y // x가 부모 노드의 왼쪽 자식이었을 경우
9       else right[p[x]] <- y // x가 부모 노드의 오른쪽 자식이었을 경우
10  left[y] <- x
11  p[x] <- y

INSERT
- 보통의 BST에서처럼 노드를 INSERT
- 새로운 노드 z를 red노드로 함
- RB-INSERT-FIXUP 호출

RB-INSERT(T, z) // z : insert할 노드
1  y <- nil[T] // y는 x의 한 칸 뒤를 쫓아내려오는 포인터 
2  x <- root[T]
3  while x != nil[T]
4    do y <- x
5      if key[z] < key[x]
6        then x <- left[x]
7        else x <- right[x]
8  p[z] <- y
9  if y = nil[T] // T가 empty인 경우
10   then root[T] <- z
11   else if key[z] < key[y]
12          then left[y] <- z
13          else right[y] <- z
14 left[z] <- nil[T]
15 right[z] <- nil[T]
16 color[z] <- RED
17 RB-INSERT-FIXUP(T, z) // z의 부모노드가 red라면 red가 연속해서 두 번 나오게 되므로 조정이 필요

RB-INSERT-FIXUP
- 위반될 가능성이 있는 조건들
  - (2) 루트노드는 black
    - z가 루트 노드인 경우 위반
    - 루트를 black으로 바꿔주면 됨
  - (4) red노드의 자식노드들은 전부 black
    - z의 부모 p[z]가 red인 경우 위반

- Loop Invariant (루프를 도는 동안 변하지 않고 유지되는 조건)
  - z는 red 노드
  - 오직 하나의 위반만이 존재
    - (2): z가 루트노드이면서 red
    - (4): z와 그 부모 p[z]가 둘 다 red
- 종료 조건
  - 부모노드 p[z]가 black이되면 종료
  - 조건 (2)가 위반일 경우 z를 black으로 바꿔주고 종료

1. p[z]가 p[p[z]]의 왼쪽 자식인 경우
Case 1: z의 삼촌(p[p[z]]의 오른쪽 자식)이 red
: 부모 노드와 삼촌을 black으로 바꾸고 할아버지 노드를 red로 변경
  But 할아버지 노드를 red로 변경했을 때 위쪽에서 다시 red-red 위반이 나타날 수 있음

Case 2: z의 삼촌이 black이고 z가 오른쪽 자식인 경우
: p[z]에 대해서 left-rotation 한 후 원래 p[z]를 z로 바꿈
  Case 3의 상황으로 만듦
   
Case 3: z의 삼촌이 black이고 z가 왼쪽 자식인 경우
: p[z]를 black, p[p[z]]를 red로 바꿈
  p[p[z]]에 대해서 right-rotation

- Case 1의 경우 1의 문제가 해결되었다 하더라도 또 다시 Case 1의 문제가 반복해서 발생하거나 Case 2,3(또는 4,5,6)의 문제가 발생할 수 있음. 최악의 경우 루트 노드에 다다를때까지 2칸씩 올라가면서 Case 1이 반복해서 발생하게 되고 이 때는 루트 노드를 black으로 바꿔줌으로써 종료

2. p[z]가 p[p[z]]의 오른쪽 자식인 경우
- Case 1,2,3과 대칭적이므로 생략

RB-INSERT-FIXUP(T, z) // z : insert할 노드 (red)
1  while color[p[z]] = RED // z의 부모가 red인 동안 (red-red violation이 존재하는 동안) 반복 (실제 구현에서는 color[p[z]]=RED && p[z]!=null)
2    do if p[z] = left[p[p[z]]] // p[z]가 왼쪽 자식인 경우 (Case 1,2,3)
3        then y <- right[p[p[z]]] // y : p[p[z]]의 오른쪽 자식 (z의 삼촌)
4          if color[y] = RED // Case 1
5            then color[p[z]] <- BLACK
6                 color[y] <- BLACK
7                 color[p[p[z]]] <- RED
8                 z <- p[p[z]]
9          else if z = right[p[z]] // Case 2
10                then z <- p[z]
11                     LEFT-ROTATE(T, z) // left-rotate를 통해 Case 3로 이동
12              color[p[z]] <- BLACK // Case 3
13              color[p[p[z]]] <- RED
14              RIGHT-ROTATE(T, p[p[z]])
15      else(same as then clause with "right" and "left" exchanged) // Case 4,5,6
16 color[root[T]] <- BLACK // Case 1,4 최악의 경우로 루트 노드까지 올라가 루트가 red인 상태로 while문이 종료될 수도 있기 때문에 black으로 바꿔줌

INSERT의 시간복잡도
- BST에서의 INSERT: O(log₂n)
- RB-INSERT-FIXUP
  - Case 1에 해당할 경우 z가 2레벨 상승
  - Case 2,3에 해당할 경우 O(1)
  - 따라서 트리의 높이(logn)에 비례하는 시간
- 즉, INSERT의 시간복잡도는 O(log₂n)