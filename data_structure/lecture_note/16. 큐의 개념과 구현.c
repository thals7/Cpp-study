큐
- 스택과 마찬가지로 일종의 리스트
- 단 데이터의 삽입은 한쪽 끝에서, 삭제는 반대쪽 끝에서만 일어남
- 삽입이 일어나는 쪽을 rear, 삭제가 일어나는 쪽을 front라고 부름
- FIFO (First-In, First-Out)라고 부름
- 예 : 프린터 큐, 등

큐가 지원하는 연산
- insert, enqueue, offer, push : 큐의 rear에 새로운 원소를 삽입하는 연산
- remove, dequeue, poll, pop : 큐의 front에 있는 원소를 큐로부터 삭제하는 연산
- peek, element, front : 큐의 front에 있는 원소를 제거하지 않고 반환하는 연산
- is_empty : 큐가 비었는지 검사

큐의 응용
- CPU 스케쥴링 : multitasking 환경에서 프로세스들은 큐에서 CPU가 할당되기를 기다림
- 데이터 버퍼 : 네트워크를 통해 전송되는 패킷(packet)들은 도착한 순서대로 버퍼에 저장되어 처리되기를 기다림
- 그 외에도 자원을 공유하는 대부분의 경우에 큐가 사용됨


큐의 구현
(1) 연결리스트로 구현
- 큐의 rear에서는 삽입, front에서는 삭제가 일어남. 따라서 연결리스트의 앞쪽을 front, 뒤쪽을 rear로 하는 것이 유리함
- 삽입을 하기 위해서는 마지막 노드의 주소를 항상 기억해야 함

(2) 환형 배열을 이용한 구현