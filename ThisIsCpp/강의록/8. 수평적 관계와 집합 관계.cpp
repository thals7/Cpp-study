- 수평적 관계
friend
접근제어 문법을 무력화
클래스 또는 구조체 안에서 사용 가능

friend class;
클래스에 friend 예약어를 선언하면 해당 클래스 통째로 접근 제어 지시자의 영향을 받지 않게 되므로 모든 메서드에 접근이 허용
자료 구조에서 관리 체계가 있고 그 체계로 관리할 대상이 있을 때 그 둘은 반드시 구별해야 함
대표적인 friend 클래스로 구조체로 구현된 노드와 연결리스트가 있음

- 집합 관계
Composition : 여럿이 모여서 다시 하나가 됨
구성 요소들이 모여 이룬 하나의 인스턴스가 소멸하면 구성 요소들도 모두 함께 소멸
대부분 멤버로 들어가있음

ex)
class CMyList {...};
class CMyUI 
{
    ...;
private:
    CMyList m_list;
};
int main()
{
    CMyUI ui;
    return 0;
}
CMyUI 클래스가 CMyList 클래스의 인스턴스를 멤버 데이터로 가지고 있을 때 CMyUI 클래스의 인스턴스가 생성되면 CMyList 클래스의 인스턴스도 함께 생성됨
반대로 CMyUI 클래스의 인스턴스가 소멸하면 CMyList 클래스의 인스턴스도 소멸

Aggregation : 단순 모임(집합체)
각각의 부분들이 하나로 이루어지지 않고 분리가 가능
인스턴스가 소멸되어도 구성 요소들이 소멸되지 않음
대부분 멤버가 포인터(*) 또는 참조자(&)

ex) 
class CMyUI
{
    ...;
private:
    CMyList &m_list;
};
int main()
{
    CMyList list;
    CMyUI ui(list);
    return 0;
}
CMyUI 클래스가 인스턴스 선언시 CMyList 클래스의 인스턴스가 참조로 전달되도록 함

-> 둘의 기능적 차이는 없지만 Aggregation 관계가 Composition 관계보다 좋을 때가 많음