#include<stdio.h>
#include<assert.h>
#include<stdbool.h>
struct vector_t
{
    double x,y;
};
void vector_ctor(struct vector_t *this,double x,double y){
    assert(this);
    this->x=x;
    this->y=y;
}
bool vectorok(struct vector_t *vector)
{
    if((vector->x=='NULL')||(vector->x=='NULL'))
        return 0;
    else
        return 1;
}
void vector_sum(struct vector_t *vector1,struct vector_t *vector2,struct vector_t *vectorsum){
    assert(vector1);
    assert(vector2);
    assert(vectorsum);
    vectorsum->x=vector1->x+vector2->x;
    vectorsum->y=vector1->y+vector2->y;
}
void vector_mul(struct vector_t *vector1,struct vector_t *vector2,struct vector_t *vectormul){
    assert(vector1);
    assert(vector2);
    assert(vectormul);
    vectormul->x=vector1->x*vector2->x;
    vectormul->y=vector1->y*vector2->y;
}
void vector_dump(struct vector_t *vectorsum){
    if (vectorok(&vectorsum)==1){
        printf("%f\n%f",vectorsum->x,vectorsum->y);
    }
}
void vector_dtor(struct vector_t *this){
    assert(this);
    this->x=0;
    this->y=0;
}
int main(){
     struct vector_t vector1={};
     struct vector_t vector2={};
     struct vector_t vectorres={};
     int x1,y1,x2,y2;
     scanf("%d%d",&x1,&y1);
     vector_ctor(&vector1,x1,y1);
     scanf("%d%d",&x2,&y2);
     vector_ctor(&vector2,x2,y2);
     vector_sum(&vector1,&vector2,&vectorres);
     vector_mul(&vector1,&vector2,&vectorres)
     vector_dump(&vectorres);
     vector_dtor(&vector1);
     vector_dtor(&vector2);
     return 0;
    }
