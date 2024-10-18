#include <iostream>
using namespace std;

void troca(int *x, int *y) {
    int aux;
    aux = *x;
    *x = *y;
    *y = aux;
}

void quickSort(int A[], int inicio, int fim) {
    int i, j, chave;
    if (fim - inicio < 2) {
        if (fim - inicio == 1) {
            if (A[inicio] > A[fim]) {
                troca(&A[inicio], &A[fim]);
            }
        }
    } else {
        i = inicio;
        j = fim;
        chave = A[inicio];
        while (j > i) {
            i++;
            while (i <= fim && A[i] < chave) {
                i++;
            }
            while (j >= inicio && A[j] > chave) {
                j--;
            }
            if (j > i) {
                troca(&A[i], &A[j]);
            }
        }
        troca(&A[inicio], &A[j]);
        quickSort(A, inicio, j - 1);
        quickSort(A, j + 1, fim);
    }
}

int main() {
    int A[5];
    for (int i = 0; i < 5; i++) {
        cout << "Entre com o " << i + 1 << "o numero: ";
        cin >> A[i];
    }
    quickSort(A, 0, 4);
    for (int j = 0; j < 5; j++) {
        cout << A[j] << "\t";
    }
    cout << endl;
}
