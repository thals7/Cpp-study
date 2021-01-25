Case Study: Huffman Coding
- 무손실 압축 방식
- 데이터 문자의 등장 빈도에 따라서 다른 길이의 부호를 사용하는 알고리즘
ex) 빈도수가 높은 문자일수록 짧은 부호를 쓰고 낮은 문자일수록 긴 부호를 부여

Prefix Code
- 어떤 codeword도 다른 codeword의 prefix(접두어)가 되지 않는 코드 (여기서 codeword란 하나의 문자에 부여된 이진코드를 말함)
- 모호함이 없이 decode가 가능
- prefix code는 하나의 이진트리로 표현 가능
  - prefix code라면 이진트리로 표현했을 때 인코딩의 대상이 되는 문자 노드들이 모두 트리의 리프노드가 됨 -> 리프노드가 아닌, 즉 자식 노드가 존재한다는 것은 다른 codeword의 prefix가 된다는 뜻이기 때문


Run-Length Encoding
- 런(run)은 동일한 문자가 하나 혹은 그 이상 연속해서 나오는 것을 의미
ex) "aaabba"는 다음과 같은 3개의 run으로 구성: "aaa", "bb", "a"
- 각각의 run을 그 'run을 구성하는 문자'와 'run의 길이'의 순서쌍 (n, ch)로 인코딩 (n: 길이, ch: 문자)
ex) "aaabba" -> 3a2b1a
- 길이가 긴 run들이 많은 경우에 효과적


Huffman Method with Run-Length Encoding
- 파일을 구성하는 각각의 run들을 하나의 super-symbol로 보고, 이들에 대해 Huffman coding을 적용
- 예를 들어 문자열 AAABAACCAABA는 5개의 super-symbol(AAA, B, AA, CC, A)로 구성되며, 각 super-symbol의 등장횟수는 다음과 같음

symbol        A   C   A   B   A
run length    3   2   1   1   2
frequency     1   1   1   2   2

AAA:110 AA:10 A:00 B:01 CC:111
AAABAACCAABA -> 1100110111100100

1. 압축할 파일을 처음부터 끝까지 읽어서 파일을 구성하는 run들과 각 run들의 등장횟수를 구함
2. Huffman coding algorithm: 트리들의 집합을 유지하면서 매 단계에서 가장 frequency가 작은 두 트리를 찾아서 하나로 합침
   이 연산에 가장 적합한 자료구조는 최소 힙 (이 때 힙에 저장된 각각의 원소들은 하나의 노드가 아닌 트리)
3. Codeword 부여: 만약 prefix를 하나의 32비트 정수로 표현한다고 했을 때 32비트 중 하위 몇 비트만이 실제 부여된 codeword. 따라서 codeword의 길이를 따로 유지해야함
4. 인코딩: 데이터 파일을 다시 시작부터 읽으면서 run을 하나씩 인식한 후 해당 run에 부여된 codeword 검색