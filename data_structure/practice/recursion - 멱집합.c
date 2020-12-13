멱집합 powerset
- 주어진 모든 부분 집합들로 구성된 집합

{a,b,c,d,e,f}의 모든 부분집합을 나열하려면
  - a를 제외한 {b,c,d,e,f}의 모든 부분집합들을 나열하고
  - {b,c,d,e,f}의 모든 부분집합에 {a}를 추가한 집합들을 나열함
{b,c,d,e,f}의 모든 부분집합에 {a}를 추가한 집합들을 나열하려면
  - {c,d,e,f}의 모든 부분집합들에 {a}를 추가한 집합들을 나열하고
  - {c,d,e,f}의 모든 부분집합에 {a,b}를 추가한 집합들을 나열
{c,d,e,f}의 모든 부분집합에 {a}를 추가한 집합들을 나열하려면
  - {d,e,f}의 모든 부분집합들에 {a}를 추가한 집합들을 나열하고
  - {d,e,f}의 모든 부분집합에 {a,c}를 추가한 집합들을 나열


powerSet(s)
if s is an empty set
    print nothing;
else
    let t be the first element of s;
    find all subsets of s-{t} by calling powerSet(s-{t});
    print the subsets;
    print the subsets with adding t;
// 이러한 경우 함수는 여러개의 집합들을 return해야함

powerSet(p,s) // s의 멱집합을 구한 후 각각에 집합 p를 합집합하여 출력
if s is an empty set;
    print p;
else
    let t be the first element of s;
    powerSet(p, s-{t}); // s의 부분집합들 중 t를 포함하지 않는 부분집합
    powerSet(p U {t}, s-{t}); // s의 부분집합들 중 t를 반드시 포함하는 부분집합

#include <stdio.h>
#include <stdbool.h>

#define SIZE 6

char data[SIZE] = {'a','b','c','d','e','f'};
bool include[SIZE];

powerSet(int k)
{
    if (k==SIZE)
    {
        for (int i=0; i<SIZE; i++)
        {
            if (include[i])
                printf("%d ", data[i]);
        }
        printf("\n");
        return;
    }
    else
    {
        include[k] = false;
        powerSet(k+1);
        include[k] = true;
        powerSet(k+1);
    }
    
}


상태공간트리 state space tree
- 해를 찾기 위해 탐색할 필요가 있는 모든 후보들을 포함하는 트리
- 트리의 모든 노드들을 방문하면 해를 찾을 수 있음
- 루트에서 출발하여 체계적으로 모든 노드를 방문하는 절차를 기술