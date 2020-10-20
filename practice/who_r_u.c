#include <stdio.h>
#include <string.h>

int main() {
  char *name;
  char *myname = "정소민";
  int age;
  printf("이름과 나이를 입력하세요.\n");
  scanf("%s %d", &*name, &age);
  if (strcmp(name,myname) == 0) {
    if (age == 24) {
      printf("%s은(는) 성인이군요.", name);} else {
        printf("%s은(는) 거짓말쟁이입니다.", name);
      }
  } else {
    printf("%s은(는) 누구인가요?", name);
    }
  }