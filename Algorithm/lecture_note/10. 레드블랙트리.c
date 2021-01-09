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
  (2) 루트노드는 black
    - z가 루트 노드인 경우 위반
    - 루트를 black으로 바꿔주면 됨
  (4) red노드의 자식노드들은 전부 black
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

DELETE
- 보통의 BST에서처럼 DELETE
- 실제로 삭제된 노드 y가 red였으면 종료
- y가 black이었을 경우 RB-DELETE-FIXUP을 호출

RB-DELETE(T, z) // z: delete할 노드
1  if left[z] = nil[T] or right[z] = nil[T] // z의 자식이 없거나 하나인 경우
2    then y <- z // y: 실제로 삭제할 노드
3  else y <- TREE-SUCCESSOR(z) // z의 자식이 2개라면 실제로 삭제되는 노드는 z가 아닌 z의 successor
4  if left[y] != nil[T]
5    then x <- left[y] // x: y의 자식 노드
6  else x <- right[y]
7  p[x] <- p[y]
8  if p[y] = nil[T] // y가 트리의 루트 노드인 경우
9    then root[T] <- x
10 else if y = left[p[y]]
11   then left[p[y]] <- x
12 else right[p[y]] <- x
13 if y != z
14   then key[z] <- key[y]
15     copy y satellite data into z  
16 if color[y] = BLACK // 삭제된 노드 y가 black인 경우 black height 문제나 red-red 문제 발생 가능
17   then RB-DELETE-FIXUP(T, x) // x: y의 자식 노드 (y가 자식이 없었을 경우 NIL 노드) 두 경우 모두 p[x]는 원래 p[y]였던 노드
18 return y

RB-DELETE-FIXUP(T, x)
- 위반될 가능성이 있는 조건들
  (2) 루트노드는 black
    - y가 루트였고 x가 red인 경우 위반
    - 루트를 black으로 바꿔주면 됨
  (4) red노드의 자식노드들은 전부 black
    - p[y]와 x가 모두 red인 경우 위반
    - x를 black으로 바꿔주면 됨
  (5) 모든 노드에 대해서 그 노드로 부터 자손인 리프노드에 이르는 모든 경로에는 동일한 개수의 black노드가 존재
    - 원래 y를 포함했던 모든 경로는 이제 black 노드가 하나 부족한 상태
      1) 노드 x에 "extra black"을 부여해서 일단 (5)를 만족
      2) 노드 x는 "double black" 혹은 "red & black"

- 아이디어
  - extra black을 트리의 위쪽으로 올려보냄
  - x가 red & black 상태가 되면 그냥 black 노드로 만들고 끝냄
  - x가 루트가 되면 그냥 extra black을 제거

- Loop Invariant (루프를 도는 동안 변하지 않고 유지되는 조건)
 - x는 루트가 아니면서 double-black인 노드
 - w는 x의 형제노드
 - w는 NIL노드가 될 수 없음 (아니면 x의 부모에 대해 조건 5가 위반)

1. x가 p[x]의 왼쪽 자식인 경우
Case 1: w가 red인 경우
- w의 자식들은 black
- w를 black으로, p[x]를 red로
- p[x]에 대해서 left-rotation 적용
- x의 새로운 형제노드는 원래 w의 자식노드, 따라서 새로운 w 노드(원래 w의 자식노드였던)는 black 노드
- Case 2,3,4(w가 black인 경우)로 넘어감

Case 2: w는 black, w의 자식들도 black
- x와 w가 모두 black이므로 부모는 red일수도, black일수도 있음
- x의 extra-black과 w의 black을 뺏어서 x는 black으로, w는 red로 만듦
- p[x]에게 x와 w로부터 뺏은 black을 줌 // 트리의 위에서부터 내려올때의 black노드의 개수는 유지됨
- p[x]가 red였다면 red & black을 가지고 있는 노드를 black노드로 만들고 끝내고, p[x]가 black이었다면 p[x]를 새로운 x로 해서 반복
- 만약 Case 1에서 2로 넘어온 경우라면 p[x]는 red였고, 따라서 새로운 x는 red & black이 되어서 종료
- 처음부터 Case 2인 경우 p[x]가 black이었다면, p[x]가 double black이 되므로 반복해서 문제를 해결해야함

Case 3: w는 black, w의 왼쪽자식이 red
- w를 red로, w의 왼자식을 black으로
- w에 대해서 right-rotation 적용
- x의 새로운 형제 w는 오른자식이 red (Case 4에 해당)

Case 4: w는 black, w의 오른쪽 자식이 red
- w의 색을 현재 p[x]의 색으로 (unknown color)
- p[x]를 black으로, w의 오른자식을 black으로
- p[x]에 대해서 left-rotation 적용
- x의 extra-black을 제거하고 종료
- 결과적으로 double black 노드가 없어졌음에도 불구하고 black height가 동일하게 유지됨

2. x가 p[x]의 오른쪽 자식인 경우
- Case 1,2,3,4와 대칭적이므로 생략

RB-DELETE-FIXUP(T, x) // 실제로 삭제한 노드인 y의 자식인 x를 넘겨주면서 Delete Fixup 수행
1  while x != root[T] and color[x] = BLACK
2    do if x = left[p[x]] // Case 1~4의 경우
3         then w <- right[p[x]] // w: x의 형제노드
4           if color[w] = RED // Case 1
5             then color[w] <- BLACK
6                  color[p[x]] <- RED
7                  LEFT-ROTATE(T, p[x])
8                  w <- right[p[x]] // 새로운 w는 BLACK이므로 다시 while문의 처음으로 돌아가 Case 2~4로 가게 됨
9           if color[left[w]] = BLACK and color[right[w]] = BLACK // Case 2
10            then color[w] <- RED
11                 x <- p[x]
12          else if color[right[w]] = BLACK // Case 3
13            then color[left[w]] <- BLACK
14                 color[w] <- RED
15                 RIGHT-ROTATE(T, p[x])
16                 w <- right[p[x]]
17          color[w] <- color[p[x]] // Case 4
18          color[p[x]] <- BLACK
19          color[right[w]] <- BLACK
20          LEFT-ROTATE(T, p[x])
21          x <- root[T] // x라는 포인터 변수를 루트 노드로 변경하여 Case 4가 끝나면 while문을 탈출하도록 함 (실제 트리에는 변화가 없고 트리의 루트가 변한 것도 아님)
22      else (same as then clause with "right" and "left" exchanged) // Case 5~8의 경우
23 color[x] <- BLACK

DELETE의 시간복잡도
- BST에서의 INSERT: O(log₂n)
- RB-DELETE-FIXUP: O(log₂n)
  - Case 2나 6이 반복되는 최악의 경우에도 시간복잡도는 트리의 높이에 비례
- 결과적으로 DELETE + FIXUP의 시간복잡도는 O(log₂n)