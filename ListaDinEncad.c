#include <stdio.h>
#include <stdlib.h>
#include "ListaDinEncad.h" //inclui os Protótipos

//Definição do tipo lista
struct elemento
{
    struct aluno dados;
    struct elemento *prox;
};
typedef struct elemento Elemento;

Lista* cria_lista()
{
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL)
        *li = NULL;
    return li;
}

void libera_lista(Lista* li)
{
    if(li != NULL)
    {
        Elemento* no;
        while((*li) != NULL)
        {
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}

int insere_lista_final(Lista* li, struct aluno al)
{
    if(li == NULL)
        return 0;
    Elemento *no;
    no = (Elemento*) malloc(sizeof(Elemento));
    if(no == NULL)
        return 0;
    no->dados = al;
    no->prox = NULL;
    if((*li) == NULL) //lista vazia: insere início
    {
        *li = no;
    }
    else
    {
        Elemento *aux;
        aux = *li;
        while(aux->prox != NULL)
        {
            aux = aux->prox;
        }
        aux->prox = no;
    }
    return 1;
}

int insere_lista_inicio(Lista* li, struct aluno al)
{
    if(li == NULL)
        return 0;
    Elemento* no;
    no = (Elemento*) malloc(sizeof(Elemento));
    if(no == NULL)
        return 0;
    no->dados = al;
    no->prox = (*li);
    *li = no;
    return 1;
}

int insere_lista_ordenada(Lista* li, struct aluno al)
{
    if(li == NULL)
        return 0;
    Elemento *no = (Elemento*) malloc(sizeof(Elemento));
    if(no == NULL)
        return 0;
    no->dados = al;
    if((*li) == NULL) //lista vazia: insere início
    {
        no->prox = NULL;
        *li = no;
        return 1;
    }
    else
    {
        Elemento *ant, *atual = *li;
        while(atual != NULL && atual->dados.matricula < al.matricula)
        {
            ant = atual;
            atual = atual->prox;
        }
        if(atual == *li) //insere início
        {
            no->prox = (*li);
            *li = no;
        }
        else
        {
            no->prox = atual;
            ant->prox = no;
        }
        return 1;
    }
}

int remove_lista(Lista* li, int mat)
{
    if(li == NULL)
        return 0;
    if((*li) == NULL)//lista vazia
        return 0;
    Elemento *ant, *no = *li;
    while(no != NULL && no->dados.matricula != mat)
    {
        ant = no;
        no = no->prox;
    }
    if(no == NULL)//não encontrado
        return 0;

    if(no == *li)//remover o primeiro?
        *li = no->prox;
    else
        ant->prox = no->prox;
    free(no);
    return 1;
}

int remove_lista_inicio(Lista* li)
{
    if(li == NULL)
        return 0;
    if((*li) == NULL)//lista vazia
        return 0;

    Elemento *no = *li;
    *li = no->prox;
    free(no);
    return 1;
}

int remove_lista_final(Lista* li)
{
    if(li == NULL)
        return 0;
    if((*li) == NULL)//lista vazia
        return 0;

    Elemento *ant, *no = *li;
    while(no->prox != NULL)
    {
        ant = no;
        no = no->prox;
    }

    if(no == (*li))//remover o primeiro?
        *li = no->prox;
    else
        ant->prox = no->prox;
    free(no);
    return 1;
}

int tamanho_lista(Lista* li)
{
    if(li == NULL)
        return 0;
    int cont = 0;
    Elemento* no = *li;
    while(no != NULL)
    {
        cont++;
        no = no->prox;
    }
    return cont;
}

int lista_cheia(Lista* li)
{
    return 0;
}

int lista_vazia(Lista* li)
{
    if(li == NULL)
        return 1;
    if(*li == NULL)
        return 1;
    return 0;
}

void imprime_lista(Lista* li)
{
    if(li == NULL)
        return;
    Elemento* no = *li;
    while(no != NULL)
    {
        printf("Matricula: %d\n",no->dados.matricula);
        printf("Nome: %s\n",no->dados.nome);
        printf("Notas: %.2f %.2f %.2f\n",no->dados.n1,
               no->dados.n2,
               no->dados.n3);
        printf("-------------------------------\n");

        no = no->prox;
    }
}

/*
1) Utilizando o código de listas que está disponível junto com a aula no
arquivo “ProjListaDinEncad”, faça o que se pede:
a. Crie uma nova função que consulta a lista e retorna um aluno
pela sua matricula
b. Crie uma nova função que consulta a lista e retorna um aluno
pela sua posição na lista
*/

//a
void consulta_matricula(Lista *li, int matricula)
{
    Elemento *no = *li;

    while(no != NULL)
    {
        if(no->dados.matricula == matricula)
        {
            printf("\nFulano tal: %s\n", no->dados.nome);
            return;
        }

        no = no->prox;
    }
    printf("Fulano de tal desaparecido");

}

//b
void consulta_indice(Lista *li, int posicao)
{
    Elemento *no = *li;

    for(int i = 0; i < posicao; i++)
    {
        if(i == posicao)
        {
            printf("Fulano: %s", no->dados.nome);
            return;
        }

        no = no->prox;
    }
     printf("Fulano de tal desaparecido");

}

/*
2) Faça duas funções recursivas. A primeira deve remover um nó da lista
encadeada a partir do seu valor armazenado (ex: int info). A segunda
deve receber duas listas encadeadas e verificar se elas são iguais.
*/
