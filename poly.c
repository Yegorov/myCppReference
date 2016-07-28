#include <stdio.h>
#include <stdlib.h>

typedef struct vtbl vtbl;
typedef struct myclass myclass;
typedef struct submyclass1 submyclass1;
typedef struct submyclass2 submyclass2;

struct vtbl
{
    void (*print)(void*);
    int (*sum)(void*);
};

struct myclass
{
    vtbl v;
    int a;
    int b;
};
void print_myclass(void* pvoid)
{
    myclass* this = (myclass*)pvoid;
    printf("from myclass {a=%d, b=%d}\n\n", this->a, this->b);
}
int sum_myclass(void* pvoid)
{
    myclass* this = (myclass*)pvoid;
    return this->a + this->b;
}
myclass* myclass_constructor(int a, int b)
{
    myclass* this = (myclass*)malloc(sizeof(myclass));
    this->a = a;
    this->b = b;
    this->v.print = print_myclass;
    this->v.sum = sum_myclass;
}

struct submyclass1
{
    vtbl v;
    myclass* base;
    int c;
    int d;
};

void print_submyclass1(void* pvoid)
{
    submyclass1* this = (submyclass1*)pvoid;
    myclass* base = this->base;
    
    printf("from submyclass1 {a=%d, b=%d}\n", base->a, base->b);
    printf("from submyclass1 {c=%d, d=%d}\n\n", this->c, this->d);
}

int sum_submyclass1(void* pvoid)
{
    submyclass1* this = (submyclass1*)pvoid;
    myclass* base = this->base;
    
    return base->a + base->b + this->c + this->d;
}

submyclass1* submyclass1_constructor(int a, int b, int c, int d)
{
    submyclass1* this = (submyclass1*)malloc(sizeof(submyclass1));
    myclass* base = (myclass*)malloc(sizeof(myclass));
    base->a = a;
    base->b = b;
    this->c = c;
    this->d = d;
    this->base = base;
    
    this->v.print = print_submyclass1;
    this->v.sum = sum_submyclass1;
}

struct submyclass2
{
    vtbl vv;
    myclass base;
    int e;
};

void print_submyclass2(void* pvoid)
{
    submyclass2* this = (submyclass2*)pvoid;
    //myclass* base = this->base;
    myclass* base = &(this->base);
    
    printf("from submyclass2 {a=%d, b=%d}\n", base->a, base->b);
    printf("from submyclass2 {e=%d}\n\n", this->e);
}

int sum_submyclass2(void* pvoid)
{
    submyclass2* this = (submyclass2*)pvoid;
    //myclass* base = this->base;
    myclass* base = &(this->base);
    
    return base->a + base->b + this->e;
}

submyclass2* submyclass2_constructor(int a, int b, int e)
{
    submyclass2* this = (submyclass2*)malloc(sizeof(submyclass2));
    //myclass* base = (myclass*)malloc(sizeof(myclass));
    myclass* base = &(this->base);
    
    base->a = a;
    base->b = b;
    this->e = e;
    //this->base = base;
    
    this->vv.print = print_submyclass2;
    this->vv.sum = sum_submyclass2;
}



int main(int argc, char** argv)
{
    //myclass* test = myclass_constructor(1, 3);
    //test->v.print(test);
    //
    //submyclass1* test2 = submyclass1_constructor(1, 3, 4, 5);
    //test2->v.print(test2);
    //
    //submyclass2* test3 = submyclass2_constructor(1, 3, 7);
    //test3->v.print(test3);
    //
    myclass* test = (myclass*)submyclass2_constructor(1, 3, 7);
    test->v.print(test);

    
    return 0;
}