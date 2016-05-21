#include <stdio.h>

typedef struct {
    int a;
    char c;
    int b;
    
} Test;

typedef struct {
    Test t;
    int z;
    
} ExTest;

void print_test(Test* t)
{
    printf("a=%d, c=%c, b = %d",  t->a, t->c, t->b);
}

int main()
{
    ExTest et;
    et.a = 42;
    et.t.a = 777;
    Test* t = (Test*)&et;

    print_test(t);
    printf("Test");
    return 0;
}