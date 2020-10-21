//while문을 사용하여 별찍기

#include <stdio.h>

int main(void) {
  int c=0;
  int d=1;
  int n;
  char a='*';
  scanf("%d", &n);
  while (c <= n){
    c = 0;
    while (c < d){
      printf("%c", a);
      c += 1; //c++;도 가능
    }
    printf("\n");
    d += 1; //d++;
    c += 1; //c++;
  }
}