#include <iostream>
#include <stdexcept>
using namespace std;

int qtd = 0;

struct noSimples{
    int codigo;
    struct noSimples * pr;
};


struct noDuplo{
    int info;
    struct noSimples * p;
    struct noDuplo * prox;
    struct noDuplo * ant;  
};

void chegadaCliente(noDuplo **inicio, noDuplo **fim){
    struct noDuplo *auxDuplo = new noDuplo;
    qtd++;
    auxDuplo->p = NULL;
    auxDuplo->info = qtd * 100;
    if((*inicio)==NULL){
        auxDuplo->prox = (*inicio);
        auxDuplo->ant = (*fim);
        (*fim) = auxDuplo;
        (*inicio) = auxDuplo;
    }else{
        auxDuplo->prox = (*inicio);
        auxDuplo->ant = NULL;
        (*inicio)->ant=auxDuplo;
        (*inicio) = auxDuplo;
    }
    cout<<"Comanda criada com sucesso!\n";
}


void consumoCliente(noDuplo **inicio){
    struct noDuplo * aux = (*inicio);
    
    int desejo;
    cout<<"Qual cliente deseja pedir?\n";
    cin>>desejo;
    while(aux->info!=desejo){
        aux = aux->prox;
    }
    
     try {
        struct noSimples *novoPedido = new noSimples;
        if (!novoPedido) {  
            throw std::runtime_error("Falha na alocacao de memoria para o pedido");
        }
            cout << "Insira o codigo do produto: ";
            cin >> novoPedido->codigo;  
            novoPedido->pr= NULL;  
        if (aux->p == NULL) {
            aux->p = novoPedido;
        }else{
            struct noSimples * temp = aux->p;
            while(temp->pr!=NULL){
                temp = temp->pr;
            }
            temp->pr = novoPedido;
        }
    } catch (const std::exception& e) {
        cout << "Erro: " << e.what() << endl;  
    }
}
void saidaCliente(noDuplo **inicio, noDuplo **fim) {
    struct noDuplo *aux = (*inicio);
    int desejoFechar;
    cout << "Qual o codigo do cliente que deseja fechar a conta?\n";
    cin >> desejoFechar;

    while (aux != NULL && aux->info != desejoFechar) {
        aux = aux->prox;
    }

    if (aux == NULL) {
        cout << "Cliente não encontrado!\n";
        return;
    }

    while (aux->p != NULL) {
        cout << "Produto: " << aux->p->codigo << endl;
        struct noSimples* temp = aux->p;
        aux->p = aux->p->pr;
        delete temp;
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
    cout << "Conta fechada com sucesso!\n";
}

int main(){
    struct noDuplo * inicio = NULL;
    struct noDuplo * fim = NULL;
    int op;
    do{
        cout<<"1 - Abrir comanda\n2 - Fazer pedido\n3 - Fechar conta\n4 - Sair\n";
        cout<<"Escolha uma opçao\n";
        cin>>op;
        switch(op){
            case 1: chegadaCliente(&inicio,&fim);break;
            case 2: consumoCliente(&inicio);break;
            case 3: saidaCliente(&inicio,&fim);break;
            case 4: break;
        }

    }while(op!=4);


}


