#define UNICODE

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <wchar.h>
#include <windows.h>

// Тестирование locale
int main(int argc, char** argv)
{
    char buf[100] = { 0 };
    wchar_t wbuf[100] = { 0 };
    
    char* locale = setlocale(LC_ALL, "en_US.utf8");
    //printf(locale);
    
    printf("page cp %d\n", GetConsoleCP());
    printf("page out cp %d\n", GetConsoleOutputCP());
    
    char* utf8 = "test utf8 строка";
    printf("string: %s, count bytes: %d, length: %d", utf8, strlen(utf8), 
                                                      mblen(utf8, MB_CUR_MAX));
    
    printf("\nВведите строку: ");
    
    FILE* f = fopen("test.txt", "r");
    
    //fgets(buf, 99, f);
    //fgets(buf, 99, stdin);
    
    //fgetws(wbuf, 99, stdin); 
    //wprintf(L"string: %s, length: %d", wbuf, wcslen(wbuf));
    
    //fread(buf, sizeof(buf[1]), 99, stdin);
    //printf("string: %s", buf);
    
    char* line = readline("");
    printf("%s", line);
    
    return 0;
}