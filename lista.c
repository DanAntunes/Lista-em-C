#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no* proximo;
} No;

// Incluir no início
void incluirI(No** lista, int num) {
    No* novo = malloc(sizeof(No));

    if (novo) {
        novo->valor = num;
        novo->proximo = *lista;
        *lista = novo;
    } else {
        printf("Erro ao alocar memoria!\n");
    }
}

// Incluir no fim
void incluirF(No** lista, int num) {
    No* aux, *novo = malloc(sizeof(No));

    if (novo) {
        novo->valor = num;
        novo->proximo = NULL;
        if (*lista == NULL)
            *lista = novo;
        else {
            aux = *lista;
            while (aux->proximo)
                aux = aux->proximo;
            aux->proximo = novo;
        }
    } else {
        printf("Erro ao alocar memoria!\n");
    }
}

// Incluir no meio
void incluirM(No **lista, int num, int ant) {
    No *ref, *novo = malloc(sizeof(No));
    
    if(novo){
        novo->valor = num;
        if(*lista == NULL){
            novo->proximo = NULL;
            *lista = novo;
        }
        else{
            ref = *lista;
            while(ref->valor != ant && ref->proximo)
                ref = ref->proximo;
            novo->proximo =  ref->proximo;
            ref->proximo = novo;
        }
    }
    else
        printf("Erro ao alocar memoria!\n");
}

// Alterar valor na lista
void alterar(No* lista, int antigo, int novo) {
    while (lista != NULL) {
        if (lista->valor == antigo) {
            lista->valor = novo;
            return;
        }
        lista = lista->proximo;
    }
    printf("Elemento nao encontrado na lista!\n");
}

// Remover elemento da lista
void remover(No** lista, int valor) {
    No* atual = *lista;
    No* anterior = NULL;

    while (atual != NULL) {
        if (atual->valor == valor) {
            if (anterior == NULL) {
                *lista = atual->proximo;
            } else {
                anterior->proximo = atual->proximo;
            }
            free(atual);
            return;
        }
        anterior = atual;
        atual = atual->proximo;
    }

    printf("Elemento nao encontrado na lista!\n");
}

// Função para consultar a lista
void Consultar(No *no) {
    printf("\n\tLista: ");
    while (no) {
        printf("%d ", no->valor);
        no = no->proximo;
    }
    printf("\n\n");
}

int main() {
    int opcao, valor, antigo, novo, anterior;
    No* lista = NULL;

    do {
        printf("\n\t0 - Sair\n\t1 - Incluir no Inicio\n\t2 - Incluir no Fim\n\t3 - Incluir no Meio\n\t4 - Alterar\n\t5 - Remover\n\t6 - Consultar\n");
        scanf("%d", &opcao);

        switch (opcao) {
        case 1:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            incluirI(&lista, valor);
            break;
        case 2:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            incluirF(&lista, valor);
            break;
        case 3:
            printf("Digite um valor e o valor de referencia: ");
            scanf("%d %d", &valor, &anterior);
            incluirM(&lista, valor, anterior);
            break;
        case 4:
            printf("Digite o valor a ser alterado e o novo valor: ");
            scanf("%d %d", &antigo, &novo);
            alterar(lista, antigo, novo);
            break;
        case 5:
            printf("Digite o valor a ser removido: ");
            scanf("%d", &valor);
            remover(&lista, valor);
            break;
        case 6:
            Consultar(lista);
            break;
        default:
            if (opcao != 0)
                printf("Opcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}

