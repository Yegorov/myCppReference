#include <iostream>
 // инициализация массива в классе
class Test 
{
public:
    unsigned char arr[12];
    Test() : arr{ 0xfd, 0xe3, 0xef, 0xe3, 0xec, 0xe2, 0xeb, 0xfc, 0xa0, 0xfc, 0xfb, 0x00 } {}
};
 
int main()
{
    Test t;
    std::cout << t.arr;
    return 0;
}