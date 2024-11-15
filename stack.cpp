#include <iostream>
using namespace std;

struct no {
    int data;
    struct no* prox;
};

struct no* topoPtr = NULL;

void push() {
    struct no* p;
    int valor;
    p = new no;
    cout << "Digite o valor: ";
    cin >> valor;
    p->data = valor;
    p->prox = topoPtr;
    topoPtr = p;
}

void pop() {
    struct no* p = topoPtr;
    if (topoPtr == NULL) {
        cout << "Lista vazia\n";
    } else {
        topoPtr = p->prox;
        delete (p);
        cout << "Elemento removido\n";
    }
}

void exibir() {
    struct no* p = topoPtr;
    if (p == NULL) {
        cout << "Lista vazia\n";
    } else {
        cout << "Elementos na lista: ";
        while (p != NULL) {
            cout << p->data << " ";
            p = p->prox;
        }
        cout << endl;
    }
}

int main() {
    int op;
    do {
        cout << "Escolha uma opcao:\n1 - Push\n2 - Pop\n3 - Exibir\n0 - Sair\n";
        cin >> op;
        switch (op) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: exibir(); break;
            default: break;
        }
    } while (op != 0);

    return 0;
}
