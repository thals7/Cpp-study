- 메모리 복사
포인터는 '변수'임 (l-value)
memcpy() : 특정 주소의 메모리에 저장된 값을 다른 메모리로 똑같이 복사

**중요!
단순히 주소만 복사(Shallow copy) vs 내용을 복사(Deep copy)
ex)
char szSrcBuf[12] = { "Hello" };
char szDstBuf[12] = { 0 };
char *pszData = NULL;

szSrcBuf = szDstBuf; // 오류 발생
// szSrcBuf는 상수임 (r-value)
// 즉 위의 식은 3 = 4;와 같은 오류를 범하고 있는 것 

// Deep copy -> 내용 복사
memcpy(szDstBuf, szSrcBuf, sizeof(szDszBuf));

// Shallow copy -> 주소만 복사
pszData = szSrcBuf;

**주의!
char *pszData = malloc( sizeof(char) * 12); //메모리 동적 할당을 하고 난 뒤
pszData = szSrcBuf; // Shallow copy를 하게 되면
puts(pszData) // 출력시 정상적으로 "Hello"가 나오기는 함
free(pszData) //But! 메모리를 해제하려고 하면 오류가 나게 됨
-> 원래 pszData가 가리켜야 할 부분인 동적 할당 받은 주소가 사라져버려(szSrcBuf의 주소로 Overwrite되어버림) 메모리 해제시 그 주소를 반환할 수 없기 때문
이런 경우 메모리 누수가 발생하게 됨
따라서 메모리 동적 할당을 받은 경우 Shallow copy가 아닌 Deep copy를 해야함

memcpy(szDstBuf, szSrcBuf, sizeof(szDszBuf)); // 메모리 복사 후
if (szSrcBuf == szDstBuf) 
if ( memcmp(szSrcBuf, szDstBuf, sizeof(szSrcBuf)) == 0) // 이 두가지 경우에 대해
    puts("Same");
else
    puts("Diff");
위의 결과를 출력해보면 첫번째껀 Diff, 두번째껀 Same이 나옴
첫번째껀 단순히 메모리의 주소가 같은지를 비교한거고
두번째껀 메모리의 주소가 가리키는 내용이 같은지를 비교한 것
memcpy()는 주소가 아닌 내용을 복사하는 함수기 때문에 당연히 단순 주소가 아닌 내용이 같은 것임

- 메모리 주소의 연산
char szBuffer[12] = { "I am a boy."};
char *pszFound = strstr(szBuffer, "am");
int nIndex = pszFound - szBuffer;
를 해보면 결과값으로 2가 나옴
즉 인덱스값이 나옴

- realloc()
이미 할당된 메모리를 재할당하는 함수
이미 할당된 메모리 영역에서 크기를 조정할 수 없다면 기존의 메모리를 해제하고 새로운 영역에 다시 할당한 후, 새로 할당된 메모리의 주소를 반환함