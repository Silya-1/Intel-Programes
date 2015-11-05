#include<stdio.h>
#define maxsize 10
typedef struct {
    int mas[maxsize];
    int size;
}steck_t;
void push(steck_t *steck, int element){
    if (steck -> size == maxsize)
        exit(-1);
    steck -> mas[steck -> size] = element;
    steck -> size++;
}
int pop(steck_t *steck){
    if (steck -> size == 0)
        exit(-1);
    steck -> size--;
    return steck -> mas[steck -> size];
}
void add(steck_t *steck){
    int e1, e2;
    e1 = pop(steck);
    e2 = pop(steck);
    e1 = e1 + e2;
    push(steck, e1);
}
void sub(steck_t *steck){
    int e1, e2;
    e1 = pop(steck);
    e2 = pop(steck);
    e1 = e2 - e1;
    push(steck, e1);
}
void mul(steck_t *steck){
    int e1, e2;
    e1 = pop(steck);
    e2 = pop(steck);
    e1 = e1 * e2;
    push(steck, e1);
}
void div(steck_t *steck){
    int e1, e2;
    e1 = pop(steck);
    e2 = pop(steck);
    e1 = e2 / e1;
    push(steck, e1);
}
void printsteck(steck_t *steck){
    int i;
    for (i = 0; i < steck -> size; i++)
        printf("%d", steck -> mas[i]);
}
int main(){
    steck_t steck;
    steck.size = 0;
    FILE *mf;
    mf =  fopen("steck.txt", "w");
    printsteck(&steck);
    return 0;
}
