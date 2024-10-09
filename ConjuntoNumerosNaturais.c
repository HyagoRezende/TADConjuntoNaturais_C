//Arquivo .h
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>

typedef struct naturais Naturais;
Naturais *naturais();
//Funçao para criar conjunto vazio
Naturais *criaConjunto();
//Funcao para verificar se o conjunto e vazio
int conjuntoVazio(Naturais *c);
//Incluir elemento no conjunto
int insereElementoConjunto(int x,Naturais *c);
//Excluir elemento do conjunto
int excluirElementoConjunto(int x,Naturais *c);
//Calcular a cardinalidade
int tamanhoConjunto(Naturais *c);
//Quantidade de elementos maiores que x
int maior(int x,Naturais *c);
//Quantidade de elementos menores que x
int menor(int x,Naturais *c);
//Verificar se o elemento x pertence ao conjunto
int pertenceConjunto(int x,Naturais *c);
//Comparar se dois conjuntos sao identicos
int conjuntosIdenticos(Naturais *c1,Naturais *c2);
//Identificar se o conjunto c1 e subconjunto de c2
int subconjunto(Naturais *c1,Naturais *c2);
//Complemento de c1 em relacao a c2
Naturais *complemento(Naturais *c1,Naturais *c2);
//Gerar a uniao de c1 com c2
Naturais *uniao(Naturais *c1,Naturais *c2);
//Interseccao de c1 com c2
Naturais *interseccao(Naturais *c1,Naturais *c2);
//Diferenca de c1 com c2
Naturais *diferenca(Naturais *c1,Naturais *c2);
//Mostrar elementos presentes no conjunto em ordem crescente ou decrescente
void mostraConjunto(Naturais *c,int ordem);
//Copiar conjunto c1 para c2
int copiarConjunto(Naturais *c1,Naturais *c2);
//Destruir o conjunto c
int destroiConjunto(Naturais *c);
//Mostrar Menu para o usuario
void menu();

//
//Arquivo .c
//

struct naturais{
    int conjuntoNaturais[1000000];
    int contador;
};

//cria Conjunto vazio
Naturais *criaConjunto(){
    int i;
    Naturais *c = (Naturais*) malloc(sizeof(Naturais));
    if(c != NULL){
        for(i=0; i<1000000 ; i++){
            c -> conjuntoNaturais[i] = 0;
        }
        c -> contador = 0;
        return (c);
    }
    else{
        return (0);
    }
}

//verificar se o conjunto e vazio
int conjuntoVazio(Naturais *c){
    int i;
    for(i=0;i<1000000;i++){
        if(c->conjuntoNaturais[i] != 0){
            return(0);
            exit(1);
        }
        else{
            return (1);
        }
    }
}

//incluir elemento no conjunto
int insereElementoConjunto(int x,Naturais *c){
    int i;
    if(conjuntoVazio(c)){
        c -> conjuntoNaturais[0] = x;
        c -> contador++;
        return (1);
    }
    else{
        //descobrir se existe algum elemento igual a x
        for(i=0;i < c -> contador;i++){
            if(c->conjuntoNaturais[i] == x){
                return (0);
                exit(1);
            }
        }
        c -> conjuntoNaturais[c -> contador] = x;
        c -> contador++;
        return(1);
    }
}
//excluir elemento do conjunto
int excluirElementoConjunto(int x, Naturais *c){
    int i,j;
    for(i=0;i < c->contador;i++){
        if(c -> conjuntoNaturais[i] == x){
            for(j = i; j < c->contador-1; j++){
                c -> conjuntoNaturais[j] = c->conjuntoNaturais[j+1];
            }
            c -> contador -= 1;
            return(1);
            exit(1);
        }
    }
    return(0);
}


//calcular a cardinalidade do conjunto
int tamanhoConjunto(Naturais *c){
    if(c -> contador == 0){
        return (0);
    }
    else{
        return (c -> contador);
    }
}

//quantidade de elementos maiores
int maior(int x, Naturais *c){
    int i, maiores = 0;
    for(i=0; i < c->contador;i++){
         if(c -> conjuntoNaturais[i] > x){
            maiores++;
         }
    }
    if(c->contador == maiores){
        return(0);
    }
    else{
        return(maiores);
    }
}

//quantidade de elementos menores
int menor(int x, Naturais *c){
    int i, menores = 0;
    for(i=0; i < c->contador;i++){
         if(c -> conjuntoNaturais[i] < x){
            menores++;
         }
    }
    if(c->contador == menores){
        return(0);
    }
    else{
        return(menores);
    }
}

//verificar se o elemento pertence ao conjunto
int pertenceConjunto(int x, Naturais*c){
    int i;
    for(i=0;i<c->contador;i++){
        if(c -> conjuntoNaturais[i] == x){
            return(1);
            exit(1);
        }
    }
    return(0);
}

//comparar se dois conjuntos sao identicos
int conjuntosIdenticos(Naturais *c1,Naturais *c2){
    int i,j,iguais=0;
    if(c1 -> contador != c2 -> contador){
        return (0);
        exit(1);
    }
    else{
        for(i=0; i < c1 -> contador; i++){
            for(j=0; j < c2 -> contador; j++){
                if(c1->conjuntoNaturais[i] == c2->conjuntoNaturais[j]){
                    iguais++;
                    break;
                }
            }
        }
        if(iguais == c1 -> contador){
            return(1);
            exit(1);
        }
        else{
            return(0);
            exit(1);
        }
    }
}

//identificar se c1 e subconjunto de c2
int subconjunto(Naturais *c1,Naturais *c2){
    int i,j,iguais=0;
    for(i=0; i < c1 -> contador; i++){
            for(j=0; j < c2 -> contador; j++){
                if(c1->conjuntoNaturais[i] == c2->conjuntoNaturais[j]){
                    iguais++;
                    break;
                }
            }
     }
     if(iguais == c1 -> contador){
        return(1);
        exit(1);
     }
     else{
        return(0);
        exit(1);
     }
}

//complemento
Naturais *complemento(Naturais *c1,Naturais *c2){
    int i,j,iguais=0;
    Naturais *x;
//Se o conjunto for identico nao existe complemento
//logo, retorna um conjunto vazio
    if(conjuntosIdenticos(c1,c2)){
        x = criaConjunto();
        return (x);
    }
//Se c2 for subconjunto de c1 nao existe complemento
//logo, retorna um conjunto vazio
        if(subconjunto(c2,c1)){
            x = criaConjunto();
            return (x);
        }
            else{
                x = criaConjunto();
                for(i=0; i < c2 -> contador;i++){
                    iguais = 0;
                    for(j=0; j < c1 -> contador;j++){
                        if(c2 -> conjuntoNaturais[i] == c1 -> conjuntoNaturais[j]){
                            iguais++;
                        }
                    }
                    if(iguais == 0){
                        insereElementoConjunto((c2 -> conjuntoNaturais[i]),x);
                    }
                }
                return (x);
            }
}

//Funcao para retornar o conjunto uniao
//gerar elementos que estao em c1 ou em c2
Naturais *uniao(Naturais *c1, Naturais *c2){
    int i;
    Naturais *x;

    x = criaConjunto();
    for(i=0;i < c1 -> conjuntoNaturais[i];i++){
        insereElementoConjunto((c1->conjuntoNaturais[i]),x);
    }
         for(i=0;i < c2 -> conjuntoNaturais[i];i++){
            insereElementoConjunto((c2->conjuntoNaturais[i]),x);
         }

         for(i=0;i<x->contador;i++){
            printf("- %d ", x->conjuntoNaturais[i]);
         }
    return(x);
}

//Funcao para gerar a intersecao entre os conjuntos
//gerar elementos que estao em c1 e em c2
Naturais *interseccao(Naturais *c1, Naturais *c2){
    int i,j;
    Naturais *x;

    x = criaConjunto();
    for(i=0;i < c1 -> contador;i++){
        for(j=0;j < c2 -> contador;j++){
            if(c1->conjuntoNaturais[i]==c2->conjuntoNaturais[j]){
                insereElementoConjunto((c1->conjuntoNaturais[i]),x);
            }
        }
    }
    return(x);    
}

//Funcao para gerar a diferenca entre os conjuntos
//retorna conjunto com elementos de c1 que nao pertencem a c2
Naturais *diferenca(Naturais *c1, Naturais *c2){
    int i,j,igual;
    Naturais *x;

    x = criaConjunto();
    for(i=0;i < c1->contador;i++){
        igual=0;
        for(j=0;j < c2->contador;j++){
            if(c1->conjuntoNaturais[i]==c2->conjuntoNaturais[j]){
                igual++;
            }
        }
        if(igual == 0){
            insereElementoConjunto(c1->conjuntoNaturais[i],x);
        }
    }
    return(x);
}

//Funcao para mostrar os elementos do conjunto em ordem
// 1 - Crescente
// 0 - Decrescente
void mostraConjunto(Naturais *c1, int ordem){
    int i,j,cont,menor,maior;
    Naturais *x;
    x = criaConjunto();
    cont = c1->contador;
    for(i=0; i < c1->contador;i++){
        insereElementoConjunto(c1->conjuntoNaturais[i],x);
    }

    if(ordem == 1){
        for(i=0;i<cont-1;i++){
            menor = x->conjuntoNaturais[i];
            for(j=i+1;j<cont;j++){
                if(x->conjuntoNaturais[j]<menor){
                    x->conjuntoNaturais[i] = x->conjuntoNaturais[j];
                    x->conjuntoNaturais[j] = menor;
                    menor = x->conjuntoNaturais[i];
                }
            }
        }
        for(i=0;i<cont;i++){
            if((i%10) == 0){
                printf("\n");
            }
            printf("%d - ", x->conjuntoNaturais[i]);
        }
        printf("\n");
    }

    if(ordem == 0){
        for(i=0;i<cont-1;i++){
            maior = x->conjuntoNaturais[i];
            for(j=i+1;j<cont;j++){
                if(x->conjuntoNaturais[j]>maior){
                    x->conjuntoNaturais[i] = x->conjuntoNaturais[j];
                    x->conjuntoNaturais[j] = maior;
                    maior = x->conjuntoNaturais[i];
                }
            }
        }
        for(i=0;i<cont;i++){
            if((i%10) == 0){
                printf("\n");
            }
            printf("%d - ", x->conjuntoNaturais[i]);
        }
        printf("\n");
    } 
}

//Copiar o conjunto c1 para o conjunto c2
int copiarConjunto(Naturais *c1,Naturais *c2){
    Naturais *x;
    x = criaConjunto();

    if(conjuntoVazio(c2)){
        x = uniao(c1,c2);
        return (1);
    }
    else{
        x = uniao(c1,c2);
        if(tamanhoConjunto(x)>1000000){
            return(0);
            exit(1);
        }
        else{
            return(1);
        }
    }
}

//Destruir o conjunto
int destroiConjunto(Naturais *c){
    if(c==NULL){
        return(0);
    }
    free(c);
    c = NULL;
    return(1);
}

//Menu
void menu(){
    printf("\n-------Manipulador de Conjuntos-------\n");
    printf(" (1) -> Cria Conjunto Vazio\n");
    printf(" (2) -> Verifica Conjunto Vazio\n");
    printf(" (3) -> Incluir Novo Elemento ao Conjunto\n");
    printf(" (4) -> Excluir Elemento do Conjunto\n");
    printf(" (5) -> Calcular Cardinaldade do Conjunto\n");
    printf(" (6) -> Quantidade de Elementos maiores que x\n");
    printf(" (7) -> Quantidade de Elementos menores que x\n");
    printf(" (8) -> Verificar se x pertence ao Conjunto\n");
    printf(" (9) -> Conjuntos identicos\n");
    printf("(10) -> C1 subconjunto de C2\n");
    printf("(11) -> Gerar conjunto complemento C1 de C2\n");
    printf("(12) -> Gerar a uniao do conjunto C1 com C2\n");
    printf("(13) -> Gerar a interseccao do conjunto C1 com C2\n");
    printf("(14) -> Gerar a diferenca do conjunto C1 com C2\n");
    printf("(15) -> Mostra conjunto ordenado\n");
    printf("(16) -> Copia conjunto C1 para C2\n");
    printf("(17) -> Destroi conjunto\n\n");
    printf(" (0) -> Fechar programa\n");
    printf("----------------------------------------\n\n");
}

int main(){
    Naturais* vet[100];
    int i=0 ,opcao = 1,numConjunto;
    
    while(opcao != 0){

        menu();
        printf("Insira o numero correspondente a operacao desejada para manipular os conjuntos: ");
        scanf("%d",&opcao);

        switch(opcao){
            //Criar Conjunto Vazio
            case 1:{
                vet[i] = criaConjunto();
                if(vet[i] != NULL){
                    i++;
                    printf("Conjunto %d criado com SUCESSO\n",i);
                    break;
                }
                else{
                    printf("Falha\n");
                    break;
                }
            }
            //Verifica se o conjunto e vazio
            case 2:{
                printf("Informe o numero do conjunto que deseja consultar se e vazio: ");
                scanf("%d",&numConjunto);
                
                if(conjuntoVazio(vet[numConjunto-1])){
                    printf("Conjunto Vazio\n");
                }
                else{
                    printf("Conjunto com elementos\n");
                }
                break;
            }
            //Incluir novo elemento ao conjunto
            case 3:{
                int elemento;

                printf("Informe o elemento que deseja inserir:");
                scanf("%d",&elemento);
                printf("Informe o numero do conjunto que deseja inserir o elemento:");
                scanf("%d",&numConjunto);
                if(insereElementoConjunto(elemento,vet[numConjunto-1])){
                    printf("SUCESSO\n");
                }
                else{
                    printf("FALHA\n");
                }    
                break;            
            }
            //Excluir um elemento do conjunto
            case 4:{
                int elemento;

                printf("Informe o elemento que deseja excluir:");
                scanf("%d",&elemento);
                printf("Informe o numero do conjunto que deseja excluir o elemento:");
                scanf("%d",&numConjunto);
                if(excluirElementoConjunto(elemento,vet[numConjunto-1])){
                    printf("SUCESSO\n");
                }
                else{
                    printf("FALHA\n");
                }
                break;
            }
            //Calcular a cardinalidade
            case 5:{
                printf("Informe o numero do conjunto que deseja calcular a cardinalidade:");
                scanf("%d",&numConjunto);
                printf("A Cardinalidade do conjunto %d = %d",numConjunto,tamanhoConjunto(vet[numConjunto-1]));
                break;
            }
            //Quantidade de elementos maiores
            case 6:{
                int elemento;

                printf("Informe o numero que sera comparado com os elementos:");
                scanf("%d",&elemento);
                printf("Informe o numero correspomdente ao conjunto que sera comparado:");
                scanf("%d",&numConjunto);
                printf("Existem %d numeros maiores no conjunto\n",maior(elemento,vet[numConjunto-1]));
                break;
            }
            //Quantidade de elementos menores
            case 7:{
                int elemento;

                printf("Informe o numero que sera comparado com os elementos:");
                scanf("%d",&elemento);
                printf("Informe o numero correspomdente ao conjunto que sera comparado:");
                scanf("%d",&numConjunto);
                printf("Existem %d numeros menores no conjunto\n",maior(elemento,vet[numConjunto-1]));
                break;
            }
            //verificar se o elemento pertence ao conjunto
            case 8:{
                int elemento;

                printf("Informe o elemento:");
                scanf("%d",&elemento);
                printf("Informe o conjunto:");
                scanf("%d",&numConjunto);
                if(pertenceConjunto(elemento,vet[numConjunto-1])){
                    printf("TRUE\n");
                }
                else{
                    printf("FALSE\n");
                }
                break;
            }
            //Comparar se os conjuntos sao identicos
            case 9:{
                int conjunto;

                printf("Informe o numero correspondente ao conjunto:");
                scanf("%d",&numConjunto);
                printf("Informe o numero correspondente ao conjunto:");
                scanf("%d",&conjunto);
                if(conjuntosIdenticos(vet[numConjunto-1],vet[conjunto-1])){
                    printf("TRUE\n");
                }
                else{
                    printf("FALSE\n");
                }
                break;
            }
            //Comparar se existe subconjunto
            case 10:{
                int conjunto;

                printf("Informe o numero correspondente ao conjunto:");
                scanf("%d",&numConjunto);
                printf("Informe o numero correspondente ao conjunto:");
                scanf("%d",&conjunto);
                if(subconjunto(vet[numConjunto-1],vet[conjunto-1])){
                    printf("TRUE\n");
                }
                else{
                    printf("FALSE\n");
                }
                break;
            }
            //Gerar conjunto complemento
            case 11:{
                int j,conjunto;

                printf("Informe o numero correspondente ao conjunto:");
                scanf("%d",&numConjunto);
                printf("Informe o numero correspondente ao conjunto:");
                scanf("%d",&conjunto);

                vet[i] = complemento(vet[numConjunto-1],vet[conjunto-1]);

                printf("O numero correspondente ao complemento e: %d\n",i+1);
                printf("Os elementos que compoe o conjunto sao: ");
                for(j=0;j<vet[i]->contador;j++){
                    printf("- %d",vet[i]->conjuntoNaturais);
                }
                printf("\n");
                i++;
                break;
            }
            //Gerar Conjunto uniao
            case 12:{
                int conjunto,j;

                printf("Informe o numero correspondente ao conjunto:");
                scanf("%d",&numConjunto);
                printf("Informe o numero correspondente ao conjunto:");
                scanf("%d",&conjunto);
                printf("O numero correspondente ao conjunto uniao e: %d\n",i+1);
                printf("Os elementos que compoe o conjunto sao: ");
                vet[i] = uniao(vet[numConjunto-1],vet[conjunto-1]);
                
                for(j=0;j<vet[i]->contador;j++){
                    printf(" %d -",vet[j]->conjuntoNaturais);
                }
                printf("\n");
                i++;
                break;
            }
            //Gerar Conjunto interseccao
            case 13:{
                int j,conjunto;

                printf("Informe o numero correspondente ao conjunto:");
                scanf("%d",&numConjunto);
                printf("Informe o numero correspondente ao conjunto:");
                scanf("%d",&conjunto);

                vet[i] = interseccao(vet[numConjunto-1],vet[conjunto-1]);

                printf("O numero correspondente a interseccao e: %d\n",i+1);
                printf("Os elementos que compoe o conjunto sao: ");
                for(j=0;j<vet[i]->contador;j++){
                    printf("- %d",vet[i]->conjuntoNaturais);
                }
                printf("\n");
                i++;
                break;
            }
            //Gerar conjunto diferenca
            case 14:{
                int j,conjunto;

                printf("Informe o numero correspondente ao conjunto:");
                scanf("%d",&numConjunto);
                printf("Informe o numero correspondente ao conjunto:");
                scanf("%d",&conjunto);

                vet[i] = diferenca(vet[numConjunto-1],vet[conjunto-1]);

                printf("O numero correspondente a diferenca e: %d\n",i+1);
                printf("Os elementos que compoe o conjunto sao: ");
                for(j=0;j<vet[i]->contador;j++){
                    printf("- %d",vet[i]->conjuntoNaturais);
                }
                printf("\n");
                i++;
                break;
            }
            //Mostrar conjunto em ordem
            case 15:{
                int ordem;

                printf("Informe o conjunto que deseja ordenar:");
                scanf("%d",&numConjunto);
                printf("Digite 1 para Crescente e 0 para decrescente:");
                scanf("%d",&ordem);

                if(ordem==1){
                    printf("Os elementos do conjunto %d em ordem crescente:\n",numConjunto);
                    printf("{");
                    mostraConjunto(vet[numConjunto-1],ordem);
                    printf("}\n");
                }
                if(ordem==0){
                    printf("Os elementos do conjunto %d em ordem crescente:\n",numConjunto);
                    printf("{");
                    mostraConjunto(vet[numConjunto-1],ordem);
                    printf("}\n");
                }
                break;
            }
            //Copiar conjunto
            case 16:{
                int conjunto;

                printf("Informe o numero do conjunto:");
                scanf("%d",&numConjunto);
                printf("Informe o numero do conjunto:");
                scanf("%d",&conjunto);

                if(copiarConjunto(vet[numConjunto-1],vet[conjunto-1])){
                    printf("SUCESSO\n");
                }
                else{
                    printf("FALHA\n");
                }
                break;
            }
            //Destruir conjunto
            case 17:{
                printf("Informe o conjunto a ser destruido:");
                scanf("%d",&numConjunto);

                if(destroiConjunto(vet[numConjunto-1])){
                    printf("SUCESSO\n");
                }
                else{
                    printf("FALHA\n");
                }
                break;
            }
            case 0:{
                for(i=0;i<100;i++){
                    free(vet[i]);
                    vet[i] = NULL;
                }
                exit(1);
                break;
            }
        }
    }
     for(i=0;i<100;i++){
         free(vet[i]);
         vet[i] = NULL;
     }
}


