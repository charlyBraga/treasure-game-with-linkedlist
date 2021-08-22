#include <stdio.h>

int const TAM=20;


struct No{
    char Info;
    struct No *Lig;
}; typedef struct No *NoPtr;


struct Adj{
    NoPtr Begin;
}; typedef struct Adj *AdjPtr;



void imprime(AdjPtr Adj, int n){
    if(Adj==NULL){
         printf("Mapa vazio!\n");
    }else{
        for(int i=0; i<n; i++){
            NoPtr Temp = Adj[i].Begin;
            while(Temp!=NULL){
                printf("%c ",Temp->Info);
                Temp=Temp->Lig;
            }
            printf("\n");
        }
    }
}

void busca_largura(AdjPtr Adj){
//...
}

void busca_profundidade(AdjPtr Adj){
//...
}


int main(){
    int n, m;
    AdjPtr Adj;
    printf("Digite N (qttd linhas): ");
    scanf("%d",&n);
    printf("Digite M (qttd colunas): ");
    scanf("%d",&m);

    Adj = malloc(n * sizeof(AdjPtr));
    NoPtr L = NULL;
    NoPtr Temp1;
    NoPtr Temp2;

    for(int i=0; i<n;i++){ //cria primeira coluna
        char info;
        L = malloc(sizeof(NoPtr));
        printf("\nDigite o tipo de local (linha %d e coluna 0): ",i);
        scanf(" %c", &L->Info);
        L->Lig = NULL;
        Adj[i].Begin = L;
        Temp1 = L;
        for(int j=1;j<m;j++){//crio linhas (horizontal)
            Temp2 = malloc(sizeof(NoPtr));
            printf("\nDigite o tipo de local (linha %d e coluna %d): ",i,j);
            scanf(" %c", &Temp2->Info);
            Temp2->Lig = NULL;
            Temp1->Lig = Temp2;
            Temp1 = Temp1->Lig;

        }
        printf("\n");
    }
   imprime(Adj,n);
   busca_largura(Adj);
   busca_profundidade(Adj);
   free(L);
   free(Temp1);
   return 0;
}
