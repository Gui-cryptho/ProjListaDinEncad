#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaDinEncad.h"

int main()
{
    typedef struct elemento Elemento;

    struct aluno al, a[4] = {
        {2,"Andre",9.5,7.8,8.5},
        {4,"Ricardo",7.5,8.7,6.8},
        {1,"Bianca",9.7,6.7,8.4},
        {3,"Ana",5.7,6.1,7.4}
    };

    struct aluno a2[4] = {
        {5, "Lucas", 8.2, 7.9, 9.0},
        {7, "Fernanda", 6.8, 8.1, 7.5},
        {6, "Joao", 9.1, 8.3, 8.7},
        {8, "Mariana", 7.4, 6.9, 8.0}
    };

    Lista* li = cria_lista();
    Lista* li_2 = cria_lista();
    Lista* li_ex8 = cria_lista();
    printf("Tamanho: %d\n\n\n\n", tamanho_lista(li));

    for(int i=0; i < 4; i++)
        insere_lista_ordenada(li_ex8,a2[i]);

    for(int i=0; i < 4; i++)
        insere_lista_ordenada(li,a[i]);

    imprime_lista(li);
    printf("\n\n\n\n Tamanho: %d\n", tamanho_lista(li));

    // Ex1
    printf("\n=========== EXERCICIO 1 ===========\n");
    consulta_matricula(li, 4);
    consulta_indice(li, 3);

    // Ex2
    printf("\n=========== EXERCICIO 2 ===========\n");
    printf("\nLista antes da remocao:\n");
    imprime_lista(li);
    remocao_recurssiva(li, 3);
    printf("\nLista apos a remocao:\n");
    imprime_lista(li);

    insere_lista_ordenada(li, a[3]);
    printf("\n\n\n");
    if(double_verificacao_recur(li, li_2) == 1)
        printf("As listas SAO IGUAIS\n");
    else
        printf("As listas SAO DIFERENTES\n");

    // Ex3
    printf("\n=========== EXERCICIO 3 ===========\n");
    printf("Lista antes da adicao:\n");
    imprime_lista(li);
    posicao_qualquer(li, a2[0], 3);
    printf("Lista apos adicao:\n");
    imprime_lista(li);

    // Ex4
    printf("\n=========== EXERCICIO 4 ===========\n");
    float v[] = {5.5, 8, 9.1, 25};
    int n = sizeof(v)/sizeof(v[0]);
    ListaNotas lista = cria_lista_notas(v, n);
    printf("Lista encadeada criada usando v:\n");
    imprime_lista_notas(lista);

    // Ex5
    printf("\n=========== EXERCICIO 5 ===========\n");
    printf("Lista antes da remocao:\n");
    insere_lista_inicio(li, a[0]);
    insere_lista_inicio(li, a[0]);
    insere_lista_inicio(li, a[0]);
    imprime_lista(li);
    printf("Lista apos a remocao:\n");
    remove_todos(li, 2);
    imprime_lista(li);
    insere_lista_ordenada(li, a[0]);

    // Ex6
    printf("\n=========== EXERCICIO 6 ===========\n");
    insere_lista_ordenada(li_2, a[0]);
    printf("Antes da concatenacao:\nli:\n");
    imprime_lista(li);
    printf("li_2:\n");
    imprime_lista(li_2);
    concatena_listas(li, li_2);
    printf("Depois da concatenacao:\nli:\n");
    imprime_lista(li);
    printf("li_2:\n");
    imprime_lista(li_2);

    // Ex7
    printf("\n=========== EXERCICIO 7 ===========\n");
    printf("Antes da remocao:\nli:\n");
    imprime_lista(li);
    remove_repetidos(li);
    printf("Depois da remocao:\nli:\n");
    imprime_lista(li);

    // Ex8
    printf("\n=========== EXERCICIO 8 ===========\n");
    printf("li:\n");
    imprime_lista(li);
    printf("li_ex8:\n");
    imprime_lista(li_ex8);
    Lista *li_3 = funde_listas(li, li_ex8);
    printf("Depois da fusao (li_3):\n");
    imprime_lista(li_3);

    // Ex9
    printf("\n=========== EXERCICIO 9 ===========\n");
    Lista *li_ex9 = cria_lista();
    for(int i=0; i < 4; i++)
        insere_lista_ordenada(li_ex9,a2[i]);
    printf("Antes da troca:\n");
    imprime_lista(li_ex9);
    troca(li_ex9, *li_ex9);
    printf("Depois da troca:\n");
    imprime_lista(li_ex9);

    libera_lista(li);
    libera_lista(li_2);
    libera_lista(li_3);
    libera_lista(li_ex9);
    libera_lista_notas(lista);

    system("pause");
    return 0;
}
