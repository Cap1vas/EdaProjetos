#include <iostream>
#define n 5
using namespace std;
int binaria(int a[], int num)
{
    int inicio = 0;
    int fim = n - 1;

    while (inicio <= fim)
    {
        int meio = inicio + (fim - inicio) / 2;

        if (a[meio] == num)
        {
            return meio;
        }

        if (a[meio] < num)
        {
            inicio = meio + 1;
        }
        else
        {
            fim = meio - 1;
        }
    }

    return -1;
}

int main()
{
    int a[n];
    int num;
    cout << "Insira o valor que quer achar";
    cin >> num;
    for (int i = 0; i < n; i++)
    {
        cout << "Insira valor array ";
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    // int media = ((n - 1) / 2);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << "\t";
    }
    cout << "\npos" << binaria(a, num);

    return 0;
}