#include <iostream>
using namespace std;


int main(){
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