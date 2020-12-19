정렬된 리스트(ordered list)에 삽입하기
: 배열의 경우

// 이진 검색을 제외하고 가장 좋은 방법은 뒤에서부터 검사하는 것
void insert_to_ordered_array(int n, int data[], int item)
{
    int i = n-1;
    for (; i>0 && data[i]>item); i--)
        data[i+1] = data[i];
    data[i+1] = item;
}
// 최악의 경우 시간복잡도는 O(n)


: 연결리스트의 경우
void *insert_to_ordered_linked_list(Node *head, int item)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = item;
    new_node->next = NULL;

    Node *p = head, *q = NULL;

    while (p != NULL && p->data < item;)
    {
        q = p;
        p = p->next;
    }
    if ( q == NULL )
    {
        new_node->next = head;
        head = new_node;
    }
    else
    {
        new_node->next = p;
        q->next = new_node;
    }
    return head; // 연결리스트의 첫번째 노드의 주소를 저장하는 변수가 전역변수가 아니라고 가정 -> 이러한 경우 첫번째 노드의 주소를 변경할 가능성이 있는 함수들은 항상 첫번째 노드의 주소를 반환하도록 구현하는 것이 일반적
}
// 최악의 경우 시간복잡도는 O(n)


정렬된 두 배열 합치기
: 정렬된 두 배열 A와 B에 저장된 m개와 n개의 데이터를 배열 C에 정렬된 상태로 저장하기

void merge_sorted_array(int m, int a[], int n, int b[], int c[])
{
    for (int i=0; i<m; i++) // 먼저 배열 a의 데이터를 그대로 배열 c로 복사
        c[i] = a[i];
    for (int j=0; j<n; j++) // 그 다음 배열 b의 데이터 각각을 배열 c에 insert
        insert_to_ordered_array(n+j, c, b[j]);
}
// 최악의 경우 시간복잡도는 O(mn)

void merge_sorted_arrays_linear(int m, int a[], int n, int b[], int c[])
{
    int i=0; j=0; k=0;
    while (i<m && j<n)
    {
        if (a[i] <= b[j])
            c[k++] = a[i++];
        else
            c[k++] -= b[j++];
    }
    while(i<m) c[k++] = a[i++];
    while(j<n) c[k++] = b[j++];
}
// 최악의 경우 시간복잡도는 O(m+n)


정렬된 두 연결리스트 합치기
ver.1

Node *merge_two_ordered_lists(Node *first, Node *second)
{
    /* insert nodes of the second list into the first list */
    Node *p = second;
    Node *q = first;

    while ( p!= NULL)
    {
        Node *the_node = p;
        p = p->next;
        
        first = insert_to_ordered_list(first);
    }
    return first;
}
// 최악의 경우 시간복잡도는 O(mn)

ver.2
Node *merge_two_ordered_lists2(Node *first, Node *second)
{
    Node *head = NULL, *tail = NULL;
    Node *tmp;

    while ( first != NULL && second != NULL)
    {
        if ( first->data <= second->data )
        {
            tmp = first;
            first = first->next;
        }
        else
        {
            tmp = second;
            second = second->next;
        }
        tmp->next = NULL;

        if ( tail == NULL )
            head = tail = tmp;
        else
        {
            tail->next = tmp;
            tail = tmp;
        }        
    }
    if ( first != NULL )
        tail->next = first;
    else if ( second != NULL )
        tail->next = second;

    return head;
}
// 최악의 경우 시간복잡도는 O(m+n)

ver.3
Node *merge_two_ordered_lists2(Node *first, Node *second)
{
    /* insert nodes of second into first */
    Node *p = second;
    Node *q = first, *pre_q = NULL;
    while ( p != NULL )
    {
        Node *the_node = p;
        p = p->next;

        while ( q != NULL && q->data < the_node->data )
        {
            pre_q = q;
            q = q->next;
        }
        if ( pre_q == NULL ) // add p at the front
        {
            the_node->next = first;
            first = the_node;
        }
        else // add after pre_q
        {
            the_node->next = q;
            pre_q->next = the_node;
        }
        pre_q = the_node;
    }
    return first;
}
// 최악의 경우 시간복잡도는 O(m+n)

반복문이 하나일때 대부분의 경우 시간복잡도가 O(n)
반복문이 중첩될 때(for(){ for()... }) 시간복잡도는 O(n^2)가 되는 경우가 많음
-> But! 항상 그런 것은 아님


연결리스트에서 특정 조건을 만족하는 모든 노드 삭제하기
ex)
Node *remove_all_divisable(Node *head, int divisor)
{
    Node *p = head;
    Node *q = NULL, *deleted = NULL;
    while ( p != NULL )
    {
        if (p->data%divisor == 0)
        {
            if ( q == NULL)
                head = p->next;
            else
                q->next = p->next;
            deleted = p;
            p = p->next;
            free(deleted);
        }
        else
        {
            q = p;
            p = p->next;
        }
    }
    return head;
}
// 시간복잡도는 O(n)