# Gerenciamento de Lista Encadeada em C

Este programa em linguagem C implementa uma lista encadeada com funcionalidades para adicionar, alterar, remover e consultar elementos. Ele oferece um menu interativo para que o usuário possa manipular a lista dinamicamente.

---

## Funcionalidades

1. **Adicionar elementos:**
   - **No início:** Insere um novo nó no início da lista.
   - **No fim:** Insere um novo nó no final da lista.
   - **No meio:** Insere um novo nó após um nó específico (referenciado pelo valor).
2. **Alterar valores:** Permite substituir o valor de um nó existente por outro.
3. **Remover elementos:** Remove um nó da lista com base no valor fornecido.
4. **Consultar a lista:** Exibe todos os valores armazenados na lista.
5. **Menu interativo:** Oferece uma interface de terminal para facilitar a manipulação da lista.

---

## Estrutura de Dados

A lista é baseada em uma estrutura de nó (`struct no`) definida como:

```c
typedef struct no {
    int valor;
    struct no* proximo;
} No;
```

Cada nó contém:
- `valor`: O dado armazenado no nó.
- `proximo`: Um ponteiro para o próximo nó na lista.

---

## Menu Interativo

O programa apresenta as seguintes opções para o usuário:

```plaintext
0 - Sair
1 - Incluir no Inicio
2 - Incluir no Fim
3 - Incluir no Meio
4 - Alterar
5 - Remover
6 - Consultar
```

### Exemplos de Uso

1. **Adicionar no início:**
   - Entrada: `1`
   - Valor: `10`
   - Resultado: O valor `10` é inserido no início da lista.

2. **Adicionar no fim:**
   - Entrada: `2`
   - Valor: `20`
   - Resultado: O valor `20` é inserido no final da lista.

3. **Adicionar no meio:**
   - Entrada: `3`
   - Valores: `15` (novo valor), `10` (referência)
   - Resultado: O valor `15` é inserido após o nó com valor `10`.

4. **Alterar valor:**
   - Entrada: `4`
   - Valores: `10` (valor antigo), `30` (novo valor)
   - Resultado: O valor `10` é substituído por `30`.

5. **Remover elemento:**
   - Entrada: `5`
   - Valor: `20`
   - Resultado: O nó com valor `20` é removido da lista.

6. **Consultar:**
   - Entrada: `6`
   - Resultado: Exibe todos os valores na lista.

---

## Código-Fonte

```c
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
```

---

## Requisitos para Execução

1. Um compilador de C, como GCC.
2. Um ambiente de desenvolvimento ou terminal para compilar e executar o programa.

---

## Como Compilar e Executar

1. Salve o código em um arquivo com a extensão `.c`, por exemplo, `lista_encadeada.c`.
2. Abra o terminal e navegue até o diretório onde o arquivo está salvo.
3. Compile o código com o seguinte comando:

   ```bash
   gcc lista_encadeada.c -o lista_encadeada
   ```

4. Execute o programa com o comando:

   ```bash
   ./lista_encadeada
   ```

---

## Considerações

- Certifique-se de inserir valores válidos ao interagir com o menu.
- O programa não verifica a consistência da entrada do usuário, como números inválidos ou valores fora do esperado.
- Possíveis melhorias incluem validação de entrada e tratamento de erros mais detalhado.

---

## Autor

Este programa foi criado como um exemplo prático de manipulação de listas encadeadas em C, com foco em estrutura de dados e algoritmos básicos.
