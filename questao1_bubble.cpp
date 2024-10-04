#include <iostream>
using namespace std;
#define n 50

/*O bubble foi mais facil por ser mais intuitivo e por ser um raciocinio "mais bruto", já que a troca é feita
a todo momento que é encontrada uma diferença.No caso do select, é uma forma de fazer um pouco mais "refinada", já que a troca é executada somente quando as comparações são feitas.
Acho essa forma mais dificil de pensar e entender que somente o bubble*/

void selectionSort(int lista[n])
{
    for (int i = 0; i < n - 1; i++)
    {
        int menor = i;
        for (int j = i + 1; j < n; j++)
        {
            if (lista[menor] > lista[j])
                menor = j;
        }
        int aux = lista[i];
        lista[i] = lista[menor];
        lista[menor] = aux;
    }
    for (int k = 0; k < n; k++)
    {
        cout << "Valor da pos(Selection) " << k + 1 << ":" << lista[k] << "\n";
    }
}

void bubbleSort(int lista[n])
{
    int temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (lista[i] > lista[j])
            {
                temp = lista[i];
                lista[i] = lista[j];
                lista[j] = temp;
            }
        }
    }
    for (int k = 0; k < n; k++)
    {
        cout << "O valor em ordem crescente eh(bubble): " << lista[k] << "\n";
    }
}

int main()
{
    // int n =5;
    int lista[n];

    for (int z = 0; z < n; z++)
    {
        cout << "Insira um valor na pos" << z + 1 << ":";
        cin >> lista[z];
    }

    cout << "Selection\n";
    selectionSort(lista);
    cout << "Bubble\n";
    bubbleSort(lista);

    return 0;
}