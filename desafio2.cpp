#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct no{
    string frase;
    struct no * prox;
    struct no * ant;
};
void inserir(no **inicio, no **fim) {
    struct no * p = new no;
    cout << "Insira uma letra de música!\n";
    cin >> p->frase;
    p->prox = NULL;
    
    if (*inicio == NULL) {
        p->ant = NULL;
        *inicio = p;
        *fim = p;
    } else {
        p->ant = *fim;
        (*fim)->prox = p;
        *fim = p;
    }
    cout << "Inserido com sucesso!\n";
}

void listar(no **fim) {
    struct no *aux = *fim;
    
    if (aux == NULL) {
        cout << "Lista vazia!" << endl;
        return;
    }

    while (aux != NULL) {
        cout << aux->frase << "\n";
        aux = aux->ant;
    }
}
void remover(no **inicio, no **fim) {
    struct no *aux = *inicio;
    int desejo;
    cout << "Qual linha deseja remover? ";
    cin >> desejo;
    int contador = 1;
    
    while (contador < desejo && aux != NULL) {
        aux = aux->prox;
        contador++;
    }
    
    if (aux == NULL) {
        cout << "Nó não encontrado!" << endl;
        return;
    }

    if (aux == *inicio && aux == *fim) {
        *inicio = NULL;
        *fim = NULL;
    } else if (aux == *inicio) {
        *inicio = aux->prox;
        (*inicio)->ant = NULL;
    } else if (aux == *fim) {
        *fim = aux->ant;
        (*fim)->prox = NULL;
    } else {
        aux->ant->prox = aux->prox;
        aux->prox->ant = aux->ant;
    }

    delete aux;
    cout << "Nó removido com sucesso!" << endl;
}




int main(){
    struct no * topo = NULL;
    struct no * fim = NULL;
    int op;
    do{
        cout<<"1 - Inserir letra\n2 - Remover linha\n3 - Listar ao contrário \n4 - Mover linha\n0 - Sair\n";
        cin>>op;
        switch(op){
            case 0: break;
            case 1: inserir(&topo,&fim);break;
            case 2: remover(&topo,&fim);break;
            case 3: listar(&fim);break;
        }   
    }while(op!=0);
    return 0;
}