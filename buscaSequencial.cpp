#include <iostream>
#define n 5
using namespace std;

void sequencial(int a[], int num)
{
    bool found = false;
    int i = 0;
    while (!found && i < n)
    {
        if (a[i] == num)
        {
            found = true;
            cout << "Achei na pos " << i;
        }
        else
        {
            i++;
        }
    }
    if (!found)
    {
        cout << "Nao tem isso aqui";
    }
}

int main()
{
    int num;
    cout << "Entre com um valor ";
    cin >> num;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Insira o valor da pos" << i + 1 << " ";
        cin >> a[i];
    }
    sequencial(a, num);
    return 0;
}