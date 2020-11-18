#include <stdio.h>
#include <string.h>

#define CAPACITY 100
#define BUFFER_SIZE 50

char *names[CAPACITY];
char *numbers[CAPACITY];
int n = 0; // 현재 저장되어있는 사람 수

void add();
void find();
void delete();
void status();

int main()
{
    char command[BUFFER_SIZE];
    while(1)
    {
        printf("$ ");
        scanf("%s", command);

        if (strcmp("add", command) == 0)
            add();
        else if (strcmp("find", command) == 0)
            find();
        else if (strcmp("delete", command) == 0)
            delete();
        else if (strcmp("status", command) == 0)
            status();
        else if (strcmp("exit", command) == 0)
            break;
    }
    return 0; 
}


void add()
{
    char name[BUFFER_SIZE];
    char number[BUFFER_SIZE];

    scanf("%s %s", name, number);
    names[n] = strdup(name);
    numbers[n] = strdup(number);
    n++;

    printf("%s was added successfully.\n", name);
}

void find()
{
    char name[BUFFER_SIZE];

    scanf("%s", name);
    for (int i = 0; i < n; i++)
    {
        if (strcmp(names[i],name) == 0 )
        {   printf("%s\n", numbers[i]);
            return;
        }
    }
    printf("No person named '%s' exists.\n", name);
}

void delete()
{
    char name[BUFFER_SIZE];

    scanf("%s", name);
    for (int i = 0; i < n; i++)
    {
        if (strcmp(names[i],name) == 0 )
        {
            names[i] = names[n-1];
            numbers[i] = numbers[n-1]; // 목록 가장 뒤에 있는 사람의 정보를 삭제할 사람의 인덱스로 옮김
            n--;
            printf("%s was deleted successfully.\n");
            return;
        }
    }
    printf("No person named '%s' exists.\n", name);
}

void status()
{
    for (int i = 0; i < n; i++)
        printf("%s %s\n", names[i], numbers[i]);
    printf("Total %d person.\n", n);
}