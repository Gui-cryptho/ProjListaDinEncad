#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaDinEncad.h" //inclui os Protótipos

//Definição do tipo lista

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
    if(li == NULL || posicao < 0)
        return;


    Elemento *no = *li;
    int i = 0;

    while(no != NULL && i < posicao)
    {
        no = no->prox;
        i++;
    }

    if(no != NULL)
    {
        printf("Fulano tal: %s\n", no->dados.nome);
    }
    else
    {
        printf("Fulano de tal desaparecido\n");
    }

}


/*
2) Faça duas funções recursivas. A primeira deve remover um nó da lista
encadeada a partir do seu valor armazenado (ex: int info). A segunda
deve receber duas listas encadeadas e verificar se elas são iguais.
*/


int remocao_recurssiva(Lista *li, int matricula)
{
    Elemento *no = *li;
    if(no->dados.matricula == matricula)
    {
        *li = no->prox;
        free(no);
        return 1;
    }

    return remocao_recurssiva(&(no->prox), matricula);
}

int double_verificacao_recur(Lista *li_1, Lista *li_2)
{

    if(li_1 == NULL && li_2 == NULL)
        return 1;

    if(li_1 == NULL || li_2 == NULL)
        return 0;

    Elemento *no_1 = *li_1;
    Elemento *no_2 = *li_2;


    if(no_1 == NULL && no_2 == NULL)
        return 1;


    if(no_1 == NULL || no_2 == NULL)
        return 0;

    if(no_1->dados.matricula != no_2->dados.matricula)
        return 0;

    return double_verificacao_recur(no_1->prox, no_2->prox);
}

/*
3) Crie uma função que insere um valor em uma posição qualquer da lista
encadeada.
*/

void posicao_qualquer(Lista *li, struct aluno al, int posicao)
{
    if(li == NULL || posicao < 0)
        return;

    Elemento *no = (Elemento*)malloc(sizeof(Elemento));
    if(no == NULL)
        return;

    no->dados = al;

    if(posicao == 0)
    {
        no->prox = *li;
        *li = no;
        return;
    }

    Elemento *aux = *li;
    Elemento *ant = NULL;
    int contador = 0;

    while(aux != NULL && contador < posicao)
    {
        ant = aux;
        aux = aux->prox;
        contador++;
    }

    if(contador < posicao)
    {
        printf("Posicao %d nao existe na lista (lista tem %d elementos)\n",
               posicao, contador);
        free(no);
        return;
    }

    no->prox = aux;

    if(ant != NULL)
        ant->prox = no;
    else
        *li = no;
}
/*
4) Recebendo como parâmetro um vetor de float, por exemplo v[n] = “5.5,
8, 9.1, 25”, crie uma função que construa lista encadeada com esses
valores, seguindo a mesma ordem em que os números estão no vetor
recebido.
*/

ListaNotas cria_lista_notas(float v[], int n) {
    ListaNotas li = NULL;
    ListaNotas *ultimo = &li;

    for (int i = 0; i < n; i++) {
        struct elemento_nota* no = (struct elemento_nota*) malloc(sizeof(struct elemento_nota));
        if (no == NULL) return li;

        no->dados.valor = v[i];
        no->prox = NULL;

        *ultimo = no;
        ultimo = &no->prox;
    }
    return li;
}

void imprime_lista_notas(ListaNotas li) {
    while (li != NULL) {
        printf("%.2f -> ", li->dados.valor);
        li = li->prox;
    }
    printf("NULL\n");
}

void libera_lista_notas(ListaNotas li) {
    struct elemento_nota *no;
    while (li != NULL) {
        no = li;
        li = li->prox;
        free(no);
    }
}


/*
5) Receba um número inteiro não negativo e faça uma função que percorra
a lista e remova todos os nós que contiverem esse número inteiro
armazenado neles. Faça todas as condições de controle necessárias
para as remoções sejam corretas.
*/

int remove_todos(Lista* li, int mat)
{
    if (li == NULL || *li == NULL)
        return 0;

    Elemento *ant = NULL, *no = *li;
    int removidos = 0;

    while (no != NULL)
    {
        if (no->dados.matricula == mat)
        {
            Elemento *aux = no;
            if (ant == NULL)
                *li = no->prox;
            else
                ant->prox = no->prox;

            no = no->prox;
            free(aux);
            removidos++;
        }
        else
        {
            ant = no;
            no = no->prox;
        }
    }
    return removidos;
}


/*
6) Escrever uma função para concatenar duas listas encadeadas L1 e L2.
*/

int concatena_listas(Lista* l1, Lista* l2)
{
    if (l1 == NULL || l2 == NULL)
        return 0;

    if (*l2 == NULL)
        return 1;

    if (*l1 == NULL)
    {
        *l1 = *l2;
    }
    else
    {
        Elemento* no = *l1;
        while (no->prox != NULL)
            no = no->prox;

        no->prox = *l2;
    }

    *l2 = NULL;
    return 1;
}


/*
7) Escrever uma função para remover elementos repetidos de uma lista
encadeada.
*/

int remove_repetidos(Lista* li)
{
    if (li == NULL || *li == NULL)
        return 0;

    Elemento *atual = *li;
    int removidos = 0;

    while (atual != NULL)
    {
        Elemento *ant = atual;
        Elemento *prox = atual->prox;

        while (prox != NULL)
        {
            if (prox->dados.matricula == atual->dados.matricula)
            {

                ant->prox = prox->prox;
                free(prox);
                prox = ant->prox;
                removidos++;
            }
            else
            {
                ant = prox;
                prox = prox->prox;
            }
        }
        atual = atual->prox;
    }

    return removidos;
}


/*
8) Escrever um procedimento para fazer a fusão de duas listas encadeadas
ordenadas, mantendo-a ordenada. Não devem ser alocados (criados)
nós extras. Os nós serão religados para compor a nova lista ordenada.
*/

Lista* funde_listas(Lista* L1, Lista* L2)
{
    if (L1 == NULL) return L2;
    if (L2 == NULL) return L1;

    Lista* nova = cria_lista();
    if (nova == NULL) return NULL;

    Elemento *p1 = *L1;
    Elemento *p2 = *L2;
    Elemento *ultimo = NULL;

    if (p1 != NULL && (p2 == NULL || p1->dados.matricula <= p2->dados.matricula))
    {
        *nova = p1;
        p1 = p1->prox;
    }
    else
    {
        *nova = p2;
        p2 = p2->prox;
    }

    ultimo = *nova;

    while (p1 != NULL && p2 != NULL)
    {
        if (p1->dados.matricula <= p2->dados.matricula)
        {
            ultimo->prox = p1;
            p1 = p1->prox;
        }
        else
        {
            ultimo->prox = p2;
            p2 = p2->prox;
        }
        ultimo = ultimo->prox;
    }

    if (p1 != NULL)
        ultimo->prox = p1;
    else
        ultimo->prox = p2;

    *L1 = NULL;
    *L2 = NULL;

    return nova;
}


/*
9) Considere a implementação de listas encadeadas. Escreva um
procedimento Troca(TipoLista* pLista, TipoCelula* p) que, dado um
apontador para uma célula qualquer (p), troca de posição essa célula
com a sua célula seguinte da lista, como mostrado na figura abaixo.
(Obs. Não vale trocar apenas o campo item! Você deverá fazer a
manipulação dos apontadores para trocar as duas células de posição).
Não esqueça de tratar os casos especiais.
*/

void troca(Lista* li, Elemento* p)
{
    if (li == NULL || *li == NULL || p == NULL || p->prox == NULL)
        return;

    Elemento* q = p->prox;
    Elemento* ant = NULL;
    Elemento* aux = *li;

    while (aux != NULL && aux != p)
    {
        ant = aux;
        aux = aux->prox;
    }


    if (ant == NULL)
    {
        *li = q;
    }
    else
    {
        ant->prox = q;
    }

    p->prox = q->prox;
    q->prox = p;
}
