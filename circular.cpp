#include <iostream>
using namespace std;

struct no {
    int valor;
    struct no *prox;
};

void criar(no **topo) {
    struct no *p = new no;
    cout << "Insira o valor do nó: ";
    cin >> p->valor;

    if (*topo == NULL) {
        p->prox = p;
        *topo = p;
    } else {
        p->prox = *topo;
        struct no *aux = *topo;
        while (aux->prox != *topo) {
            aux = aux->prox;
        }
        aux->prox = p;
        *topo = p;
    }
}

void remover(no **topo) {
    if (*topo == NULL) {
        cout << "A lista esta vazia!" << endl;
        return;
    }

    if ((*topo)->prox == *topo) {
        delete *topo;
        *topo = NULL;
        return;
    }

    struct no *aux = *topo;
    while (aux->prox != *topo) {
        aux = aux->prox;
    }

    struct no *novoTopo = (*topo)->prox;
    aux->prox = novoTopo;  
    delete *topo;          
    *topo = novoTopo;      
}

void imprimir(no *topo) {
    if (topo == NULL) {
        cout << "Lista vazia!" << endl;
        return;
    }

    struct no *aux = topo;
    do {
        cout << aux->valor << " ";
        aux = aux->prox;
    } while (aux != topo);

    cout << endl;
}

int main() {
    struct no *topo = NULL;
    int op;
    do {
        cout << "Menu:\n1 - Criar nó\n2 - Remover nó\n3 - Sair\nEscolha a opção: ";
        cin >> op;
        switch (op) {
            case 1:
                criar(&topo);
                break;
            case 2:
                remover(&topo);
                break;
            case 3:
                break;
            default:
                cout << "Opção inválida!" << endl;
        }


        cout << "Lista atual: ";
        imprimir(topo);

    } while (op != 3);

    return 0;
}
