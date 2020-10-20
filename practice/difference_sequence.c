#include <stdio.h>

int main() {
  int c=1;
  int i=1;
  while (c < 100){
    printf("%d\n", c);
    c += i;
    i += 1;
    // 또는 c += i++; 이렇게 한줄로도 가능
  }
}