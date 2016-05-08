#include <stdio.h>
#include <windows.h>
int hello()
{
    printf ("Hello World!\n");
    return 42;
} 

int sum(int a, int b, char* bytes)
{
    if(bytes != NULL)
    {
        short s = 771;
        bytes[0] = 20;
        bytes[1] = 30;
        bytes[2] = s;
    }
    else
        a = 0;
    return a + b;
}

char getbyte(char a)
{
    return a + 1;
}

// https://cygwin.com/cygwin-ug-net/dll.html
// http://stackoverflow.com/questions/10307762/error-expected-before-string-constant
// http://stackoverflow.com/questions/16332701/how-to-call-c-dll-in-c-sharp
// http://www.codeguru.com/csharp/csharp/cs_data/article.php/c4217/Calling-Unmanaged-Code-Part-1--simple-DLLImport.htm
// http://www.codeproject.com/Articles/66244/Marshaling-with-C-Chapter-Marshaling-Simple-Type

// https://msdn.microsoft.com/ru-ru/library/system.runtime.interopservices.dllimportattribute%28v=vs.90%29.aspx
// https://msdn.microsoft.com/ru-ru/library/system.runtime.interopservices.dllimportattribute_members%28v=vs.90%29.aspx