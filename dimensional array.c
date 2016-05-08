#include ...
#define BIG_N 10000
#define N 10

void print_matrix_error(double **m)
{
    for(int i = 0; i < SIZE_N; ++i)
    {
        for(int j = 0; j < SIZE_N; ++j)
        {
            //printf("%.2f ", *(*(m + i) + j));
            printf("%.2f ", m[i][j]);
        }
    }
}

void print_matrix_ok1(double *m)
{

}
void print_matrix_ok1(double m[][N])
{

}
int main(int argc, char** argv)
{
    //double m[BIG_N][BIG_N] = {0}; // переполнение стека, объявлять надо как внешнию или динамически (malloc)
    double matrix[N][N]; // В памяти представляется как одномерный, т. е. тип matrix double *, а не double **
    print_matrix_error(matrix);

    return 0;
}