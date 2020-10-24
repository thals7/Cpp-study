- 컴퓨터의 구성요소
기저에 하드웨어가 존재
그 위에서 Kernel(OS)이 작동
Kernel 레이어를 넘어가면 그 위에 User 모드가 존재
거기에 Process들이 있고, 여러 Process 안에 여러 Thread들이 존재

User모드 (Thread Thread)Process (Thread Thread)Process
---------------------------------------------- Layer
Kernel(OS)모드
---------------------------------------------- Layer
Hardware

하나의 OS를 기반으로 여러 Process들이 돌아감 (Multi tasking)
한 Process 안에 여러 Thread가 작동함 (Multi thread)

Process는 각자의 고유한 영역을 가짐
But! 다른 Process 의 영역을 침범할 수 있는 권한을 가진 것이 존재 -> "디버거"
즉 소프트웨어의 어떤 결함, 문제를 해결하는 도구가 바로 디버거

- 입/출력을 하는 주체는 누구인가?
"Kernel"
절대로 User 또는 소프트웨어가 하는 것이 아님

- putchar() / getchar()
putchar 함수를 통해 어떤 글자를 입력해달라고 interface(File)에 write하면 그 정보는 Layer밑에 Kernel로 전달됨
결국 실질적으로 입출력을 하는 low-level 행위는 Kernel이 담당
putchar는 입출력을 "요구"하는 함수

User모드에서 추상화된 interface는 File이라는 형태를 가짐
File은 두 가지(I/O) Buffer(메모리)를 가짐
putchar('A'): Input용 버퍼 속에 'A'라는 문자가 들어가는 것 / 버퍼링(버퍼를 채우는 것) 없이 바로 밑으로 전달함
getchar('A'): Output용 버퍼에서 'A'라는 문자를 꺼내오는 것 / 만약 버퍼 안에 10글자가 들어있다면? 오로지 'A' 한 글자만 가져옴 -> 버퍼 속에 아직 9글자가 남아있음 -> 따라서 버퍼에 남아있는 글자를 다 비울 때까지 입력을 추가로 받지 않음

- getchar()가 int를 반환하는 이유?
char 의 본질은 부호가 있는 정수형(1 byte)
대문자 A에 1을 더하면 B가 됨 -> 이 때 char + int = int
따라서 getchar()의 반환 형식은 int가 됨

- Buffer / Buffering
Buffer = Memory
사전적 정의 : 완충기
ex) 유튜브의 동영상 재생
    버퍼가 하나 존재: 버퍼 안의 정보를 꺼내서 재생 / 네트워크가 유튜브로부터 자료를 다운받아 버퍼에 집어넣음 -> 이 두가지 일이 동시에 일어나고 있음
    네트워크가 불안정해져서 끊겨버리는(충격) 경우? 이를 완충해주는 것이 Buffer
    즉 버퍼링은 밑빠진 독에 물붓기와 같음

* getchar(), scanf(), gets() 함수는 Buffered I/O를 함
콘솔이라는 장치를 추상화한 File이 있을 때 키보드(하드웨어)에서 사람이 타자를 치면 그 정보는 File의 Buffer에 쌓임
거기서 한 글자씩 꺼내오면 getchar()
한 줄씩 꺼내오면 gets() (심각한 보안결함으로 현재 사용은 불가능)
형식 문자를 주고 그 규칙에 맞게 끊어오면 scanf()
-> 결국 이 함수들은 모두 Buffer로부터 정보를 꺼내온다는 점에서 동일
   그 모습과 형태나 규칙이 조금씩만 다를 뿐임

- scanf()
scanf() 함수는 값을 입력하고 난 뒤 친 엔터 \n까지 입력 버퍼에 저장하게 됨
따라서 그 뒤에 또 다른 입력 함수를 실행하면 입력 버퍼에 남아있던 \n을 받아왔기 때문에 추가적인 입력 없이 그냥 넘어가게 됨

*이 문제를 해결하는 방법?
getchar(); 함수로 입력 버퍼에 남아있던 \n을 사용해 버퍼 비우기
fflush(stdin); 출력(입력X) 버퍼를 완전히 비워주는 함수로 gcc에서 안돌아감