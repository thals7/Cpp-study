Q. O(nlogn)보다 시간복잡도가 낮은 comparison 정렬 알고리즘이 존재할 수 있는가?

Comparison Sort
- 데이터들간의 상대적 크기관계만을 이용해서 정렬하는 알고리즘
- 따라서 데이터들간의 크기 관계가 정의되어 있으면 어떤 데이터에든 적용 가능 (문자열, 알파벳, 사용자 정의 객체 등)
- 버블소트, 삽입정렬, 합병정렬, 퀵소트, 힙정렬 등

Non-comparison sort
- 정렬할 데이터에 대한 사전지식을 이용 (적용에 제한)
- Bucket sort
- Radix sort


A. 어떤 comparison sort도 시간복잡도가 O(nlogn)보다 낮을 수 없음

- 정렬문제의 하한 (Lower bound)
  - 입력된 데이터를 한번씩 다 보기 위해서 최소 Θ(n)의 시간복잡도 필요
  - 합병정렬과 힙정렬 알고리즘들의 시간복잡도는 Θ(nlog₂n)
  - 어떤 comparison sort 알고리즘도 Θ(nlog₂n)보다 나을 수 없음

Decision Tree
- 임의의 comparison sort가 존재한다고 가정 (ex. insertion sort)
- 정렬을 하기 위해 값들을 하나씩 비교하는 전체 과정을 하나의 트리로 나타낼 수 있음
    - 3개의 값을 정렬하는 삽입정렬알고리즘에 대한 decision tree
- 정렬의 결과인 Leaf 노드의 개수는 n!개 -> 모든 순열에 해당하기 때문
- 최악의 경우 시간복잡도는 트리의 높이
- 트리의 높이 height >= log₂n! = Θ(nlog₂n)

즉, comparison sort를 decision tree로 표현하게 되면 n!개의 leaf node를 가짐
이 때 이진 트리의 lead node가 n!개를 가지려면 그 트리의 높이는 log n!Θ(nlog₂n)보다 낮을 수 없음
=> 따라서 O(nlogn)보다 낮은 시간복잡도를 가지는 comparison sort는 존재하지 않음