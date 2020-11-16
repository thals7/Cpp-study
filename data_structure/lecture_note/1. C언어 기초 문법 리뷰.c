컴퓨터 메모리
- 데이터를 보관하는 장소
- 바이트(8 bits) 단위로 주소가 지정됨
- 모든 변수는 주소를 가짐

포인터
- 메모리 주소를 값으로 가지는 변수
- type-name * variable-name;
- 연산자 &는 변수로부터 그 변수의 주소를 추출하는 연산자

포인터와 배열
- int a[10]; 이라는 배열 a 가 있을 때 배열의 이름(a)은 배열의 시작(a[0]) 주소를 저장하는 포인터 변수 -> 단, 그 값을 변경할 수 없음 / 여기에 10개의 정수를 수용할 수 있는 메모리(40바이트)가 할당됨

포인터 arithmetic
- *a와 a[0]은 동일한 의미
- a[i] = *(a+i)
  int a[10];에서 a = 1000 이라고 했을 때 a+1은 1001이 아닌 1004 a가 정수형 포인터 변수이기 때문에 C언어에서 자동적으로 i번째 칸의 주소를 넘겨줌

동적메모리 할당
- 변수 선언 대신 프로그램의 요청으로 메모리를 할당
- malloc 함수를 호출하여 동적메모리 할당을 요청하면 요구하는 크기의 메모리를 할당하고 그 시작 주소를 반환
- 할당된 메모리 주소를 담기 위해서는 저장할 타입의 포인터 변수를 선언해야함
- malloc으로 할당받은 메모리는 보통의 배열처럼 사용

배열 키우기
- 동적으로 할당된 배열은 공간이 부족할 경우?
  ex)
  int *array = (int*)malloc(4*sizeof(int));
  // 배열 array의 크기가 부족
  int *tmp = (int*)malloc(8*sizeof(int));
  int i;
  for (i=0; i<4; i++)
      tmp[i] = array[i];
  array = tmp;

** array를 배열로 선언하는 것과 포인터로 동적 할당을 받는 것의 차이?
포인터로 동적 할당을 받은 경우 array는 포인터일뿐이므로 array=tmp; 가능
but! 배열의 이름으로 선언을 하게 되면 array의 값을 수정할 수 없기 때문에 array=tmp;가 불가능 (배열의 크기를 키우거나 할 수 없음)