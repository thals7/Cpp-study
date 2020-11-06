#include <iostream>

int main()
{
    std::cout << "Hello, World!" << std::endl;
    std::cout << "This is my first study of "
              << "C++ !" <<std::endl;
    return 0;
}

- 프로그래밍 언어
절차 지향 언어 : 구문들이 쓰여져있는 '순서'대로 정해진 연산을 수행하는 것
               대규모 프로젝트를 진행하는데에 있어 부족함이 있음
객체 지향 언어 : [Class] -> C언어의 [함수+구조체]와 매우 유사함
               개념(추상,설계)을 실제로 구현(실체)
               객체 지향의 가장 큰 특징은 설계와 구현을 분리함에 있음

               어떤 행위를 하는 행위 주체가 있고 그것을 사용하는 이용 주체가 있음
               이용 주체는 행위 주체에게 할 일을 넘겨주기만 하면 끝

               큰 틀에서 구조를 결정해놓고 세세한 디테일은 차후에 구현해도 되는 형태로 프로그램을 개발할 수 있음

- C vs C++
C : 물건(언어)의 사용자(개발자)가 잘 써야 함
C++ : 사용자의 이해도가 상대적으로 떨어져도 됨
      물건(언어)을 잘 만들어놓는 것이 중요

int(형식) nData(변수);
에서 C++은 nData를 int 형식에 대한 '인스턴스'라고 말함

- 변수 선언 및 정의
int a = 10; // C언어 스타일
int a(10);  // C++ 스타일
int b(a); <- 복사

int (10); <- 이름이 없는 인스턴스 선언 및 정의

자료형 auto
int a(10);
auto b(a); -> b의 형식은 원본의 형식을 따라감

ex)
void TestFunc(int, char*)
{
}

int main()
{
    void(*pfTest)(int, char*) = TestFunc();
    // 위와 같이 쓸 필요 없이 아래 auto 를 이용해 간단하게 기술 가능
    auto pfTest2(TestFunc);
    return 0;
}