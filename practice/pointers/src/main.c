#include <stdio.h>
#include <stdlib.h>

typedef struct teste{

    struct teste* next;
    int info;

}teste;

int main()
{
    teste* one = (teste*)malloc(sizeof(teste));
    one->next = (teste*)malloc(sizeof(teste));

    teste* current = one->next;
    current->info = 3;

    printf("%d", one->next->info);

    return 0;
}
