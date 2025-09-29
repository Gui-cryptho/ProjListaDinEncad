//Arquivo ListaDinEncad.h

struct aluno
{
    int matricula;
    char nome[30];
    float n1,n2,n3;
};

typedef struct elemento* Lista;

struct elemento
{
    struct aluno dados;
    struct elemento *prox;
};

typedef struct elemento Elemento;
Lista* cria_lista();
void libera_lista(Lista* li);
int insere_lista_final(Lista* li, struct aluno al);
int insere_lista_inicio(Lista* li, struct aluno al);
int insere_lista_ordenada(Lista* li, struct aluno al);
int remove_lista(Lista* li, int mat);
int remove_lista_inicio(Lista* li);
int remove_lista_final(Lista* li);
int tamanho_lista(Lista* li);
int lista_vazia(Lista* li);
int lista_cheia(Lista* li);
void imprime_lista(Lista* li);

//ex1
//a
void consulta_matricula(Lista *li, int matricula);

//b
void consulta_indice(Lista *li, int posicao);

//ex2
int remocao_recurssiva(Lista *li, int matricula);
int double_verificacao_recur(Lista *li_1,Lista *li_2);

//ex3
void posicao_qualquer(Lista *li, struct aluno al, int posicao);

//ex4
struct nota {
    float valor;  // Armazena apenas a nota
};

struct elemento_nota {
    struct nota dados;
    struct elemento_nota *prox;
};

typedef struct elemento_nota* ListaNotas;



//ex5
int remove_todos(Lista* li, int mat);

//ex6
int concatena_listas(Lista* l1, Lista* l2);

//ex7
int remove_repetidos(Lista* li);

//ex8
Lista* funde_listas(Lista* L1, Lista* L2);

//ex9
void troca(Lista* li, Elemento* p);
