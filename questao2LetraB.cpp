#include <iostream>
using namespace std;

struct funcionario
{
    int matricula;
    int salario;
};

void somarSalario(funcionario f[15])
{
    int soma = 0;
    for (int i = 0; i < 15; i++)
    {
        soma += f[i].salario;
    };
    cout << "A soma eh" << soma;
}

int main()
{
    funcionario f[15];
    for (int i = 0; i < 15; i++)
    {
        cout << "Valor do salario do funcionario " << i + 1 << "?";
        cin >> f[i].salario;
        cout << "Qual a matricula do funcionario " << i + 1 << "?";
        cin >> f[i].matricula;
    }
    for (int j = 0; j < 15; j++)
    {
        for (int k = j + 1; k < 15; k++)
        {
            if (f[j].salario > f[k].salario)
            {
                funcionario aux = f[j];
                f[j] = f[k];
                f[k] = aux;
            }
        }
    }
    somarSalario(f);

    return 0;
}