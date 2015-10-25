#include <stdio.h>
#include <locale.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

// OOP in C

typedef struct _person {
    char* name;
    int age;
} person, *ptr_person;

ptr_person create_person(ptr_person *p, char* name, int age) 
{
    (*p) = (ptr_person)malloc(sizeof(person));

    (*p)->name = (char*)malloc((strlen(name) + 1) * sizeof(char));
    strcpy((*p)->name, name);
    
    (*p)->age = age;
    
    printf("Person:\nName: %s\nAge: %d\n", (*p)->name, (*p)->age);
    
    return *p;
}

void print_person(ptr_person p)
{
    printf("Person:\nName: %s\nAge: %d\n", p->name, p->age);
}

void delete_person(ptr_person p)
{
    free(p->name);
    free(p);
}

int main(int argc, char* argv[])
{

    ptr_person a;
    
    create_person(&a, "Artem", 21);
    
    print_person(a);

    delete_person(a);
    
    return 0;
}