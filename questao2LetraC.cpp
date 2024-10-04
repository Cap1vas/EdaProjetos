#include <iostream>
using namespace std;

#define tamanho 5

struct funcionario
{
    int matricula;
    int salario;
};

int somarSalario(funcionario f[tamanho])
{
    int soma = 0;
    for (int i = 0; i < tamanho; i++)
    {
        soma += f[i].salario;
    }
    return soma;
}

int main()
{
    funcionario f[tamanho];

    for (int i = 0; i < tamanho; i++)
    {
        cout << "Valor do salario do funcionario " << i + 1 << "? ";
        cin >> f[i].salario;
        cout << "Qual a matricula do funcionario " << i + 1 << "? ";
        cin >> f[i].matricula;
    }

    for (int j = 0; j < tamanho; j++)
    {
        for (int k = j + 1; k < tamanho; k++)
        {
            if (f[j].salario > f[k].salario)
            {
                funcionario aux = f[j];
                f[j] = f[k];
                f[k] = aux;
            }
        }
    }

    int aux = somarSalario(f);
    double media = static_cast<double>(aux) / tamanho;
    int contador = 0;

    for (int c = 0; c < tamanho; c++)
    {
        if (f[c].salario < media)
        {
            contador++;
            cout << "Funcionario de matricula: " << f[c].matricula << " tem salario menor que a media\n";
        }
    }

    cout << "Quantidade de funcionarios com salario menor que a media: " << contador << endl;

    return 0;
}
