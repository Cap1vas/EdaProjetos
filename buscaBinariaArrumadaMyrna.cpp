#include <iostream>
#define T 7
using namespace std;

void binaria(int A[], int x, int inicio, int fim)
{
    if (inicio >= fim)
    {
        cout << x << " nao esta na lista";
        return;
    }

    int meio = (inicio + fim) / 2;
    if (x == A[meio])
    {
        cout << x << " esta na posicao: " << meio + 1;
    }
    else if (x < A[meio])
    {
        binaria(A, x, inicio, meio);
    }
    else
    {
        binaria(A, x, meio + 1, fim);
    }
}

int main()
{
    int num, A[T] = {9, 15, 25, 32, 44, 50, 90};
    cout << "Numero a ser buscado: ";
    cin >> num;
    binaria(A, num, 0, T);
}
