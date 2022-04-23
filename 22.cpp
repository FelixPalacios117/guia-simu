#include <iostream>
using namespace std;

int **crearMatrix(int n, int m)
{
    int **matrix = (int **)malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++)
        *(matrix + i) = (int *)malloc(sizeof(int) * m);
    return matrix;
}

void llenarMatrix(int ***matrix, int n, int m)
{
    for (int i = 0; i < n * m; i++)
        *(*(*matrix + (i / m)) + (i % m)) = i;
}

void imprimirMatrix(int ***matrix, int n, int m)
{ /*
     for (int i = 0; i < n * m; i++)
         cout << *(*(*matrix + (i / m)) + (i % m));*/
    for (int i = 0; i < n; i++)
    {
        cout << "\n";
        for (int j = 0; j < m; j++)
        {
            cout << *(*(*matrix + i) + j);
            cout << "\t";
        }
    }
}

int **eliminarFilayCol(int ***matrix, int n, int m, int filEliminar, int colEliminar)
{
    int **matrixCopia = crearMatrix(n - 1, m - 1);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i != filEliminar - 1 && j != colEliminar - 1)
            {
                int iInser = i, jInser = j;
                if (i > filEliminar - 1)
                {
                    iInser = i - 1;
                }
                if (j > colEliminar - 1)
                {
                    jInser = j - 1;
                }
                *(*(matrixCopia + iInser) + jInser) = *(*(*matrix + i) + j);
            }
        }
    }
    return matrixCopia;
}

int main()
{
    int n = 6, m = 5;
    int **matrix = crearMatrix(n, m);
    llenarMatrix(&matrix, n, m);
    cout << "Matriz original:";
    imprimirMatrix(&matrix, n, m);

    cout << "\n\nSub matriz:";
    int **subMatrix = eliminarFilayCol(&matrix, n, m, 3, 3);
    imprimirMatrix(&subMatrix, n - 1, m - 1);

    return 0;
}