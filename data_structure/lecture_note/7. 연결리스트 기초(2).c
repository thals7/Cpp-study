첫번째 노드의 삭제
head가 현재 head 노드의 다음 노드를 가리키게 만듦
head = head->next;

** 연결리스트의 모든 노드들은 동적 할당을 받은 것들이기 때문에 free를 통해 반환해주어야 함

어떤 노드의 다음 노드 삭제하기 :prev가 가리키는 노드의 다음 노드를 삭제
prev의 다음 노드가 NULL이 아니라면 prev의 next필드가 현재 next노드의 다음 노드를 가리키게 만듦
(전: [prev] -> [삭제할 노드] -> [next] 후 : [prev] -> [next])
if (prev->next != NULL)
    prev->next = prev->next->next;


연결리스트 순회하기
연결리스트의 노드들을 처음부터 순서대로 방문하는 것을 순회(reverse)한다고 말함
ex)
Node *find(char *word)
{
    Node *p = head;
    while ( p != NULL )
    {
        if (strcmp(p->data, word) == 0)
            return p;
        p = p->next; // 만약 p에 저장된 데이터와 단어가 같지 않으면 다음 노드로 넘어감
    }
    return NULL; // 연결리스트의 끝까지 돌았지만 동일한 단어를 찾지 못한 경우
}
위의 함수는 입력된 문자열 word와 동일한 단어를 저장한 노드를 찾아서 그 노드의 주소를 반환해주는 함수
이를 위해서 연결리스트를 순회함


단순연결리스트에서 어떤 노드를 삭제할 때는 삭제할 노드의 바로 앞 노드의 주소가 필요함 (삭제할 노드의 주소만으로는 삭제할 수 없음)
따라서 어떤 노드를 삭제하기 위해 두 개의 포인터를 쓰는 방식을 사용
ex)
Node *remove(char * item)
{
    Node *p = head;
    Node *q = NULL;
    while ( p != NULL && strcmp(p->data, item) != 0 )
    {
        q = p; //q는 항상 p의 직전 노드를 가리킴
        p = p->next;
    }
    if ( p == NULL)
        return NULL
    if ( q == NULL)
        return remove_first() // p가 첫번째 노드를 가리킬 경우 q는 NULL
    else return remove_after(q); // 삭제할 노드의 직전 노드 주소인 q가 매개변수가 됨
}