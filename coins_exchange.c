#include <stdio.h>

int NUM = 5;
/*int coins[5][2] = {
    {1, 1},
    {2, 5},
    {3, 10},
    {4, 25},
    {5, 50}
};
*/

int coins[5][2] = {
    {1, 50},
    {2, 25},
    {3, 10},
    {4, 5},
    {5, 1}
};

int comb(int a, int n)
{
    if(a == 0) return 1;
    if(a < 0) return 0;
    if(n == 0) return 0;
    
    return comb(a, n - 1) + comb(a - coins[NUM - n][1], n);
}

int main()
{
    printf("k=%d", comb(100, 5));
    //int n = 0;
    //printf("%d", coins[NUM - (n)][1]);
    return 0;
}
