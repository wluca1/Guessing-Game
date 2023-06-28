#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void menu(){
    printf("Escolha uma opção:\n");
    printf("1 - Novo Jogo\n");
    printf("2 - Ver Ranking\n");
    printf("3 - Limpar Ranking\n");
    printf("4 - Sair\n");
}

void novoJogo(){
    int numeroSecreto, numeroChutado, tentativas = 0;
    char nome[20];
    printf("Digite seu nome: ");
    scanf("%s", nome);
    printf("Escolha uma valor entre 1 e 100: ");
    scanf("%d", &numeroChutado);
    srand(time(NULL));
    numeroSecreto = rand() % 100 + 1;
    while(numeroChutado != numeroSecreto){
        if(numeroChutado > numeroSecreto){
            printf("Errado! Tente um valor mais baixo: ");
            scanf("%d", &numeroChutado);
        }else{
            printf("Errado! Tente um valor mais alto: ");
            scanf("%d", &numeroChutado);
        }
        tentativas++;
    }
    printf("Parabéns! Você acertou depois de %d tentativas!\n", tentativas);
    FILE *arq;
    arq = fopen("ranking.txt", "a");
    fprintf(arq, "%s %d\n", nome, tentativas);
    fclose(arq);
}

void verRanking(){
    char nome[20];
    int tentativas;
    int ranking[3] = {9999, 9999, 9999};
    char nomes[3][20];
    FILE *arq;
    arq = fopen("ranking.txt", "r");
    int posicao = 1;
    while(fscanf(arq, "%s %d", nome, &tentativas) != EOF){

        if (tentativas < ranking[0]) {
            strcpy(nomes[2], nomes[1]);
            strcpy(nomes[1], nomes[0]);
            strcpy(nomes[0], nome);
            ranking[2] = ranking[1];
            ranking[1] = ranking[0];
            ranking[0] = tentativas;
        } else if (tentativas < ranking[1]) {
            strcpy(nomes[2], nomes[1]);
            strcpy(nomes[1], nome);
            ranking[2] = ranking[1];
            ranking[1] = tentativas;
        } else if (tentativas < ranking[2]) {
            strcpy(nomes[2], nome);
            ranking[2] = tentativas;
        }
        posicao++;
    }
    fclose(arq);
    printf("Melhores Rankings:\n");
    for (int i = 0; i < 3; i++) {
        if (ranking[i] != 9999) {
            printf("%dº - %s %d\n", i+1, nomes[i], ranking[i]);
        }
    }
}


void limparRanking(){
    FILE *arq;
    arq = fopen("ranking.txt", "w");
    fclose(arq);
}

int main(){
    int opcao;
    do{
        menu();
        scanf("%d", &opcao);
        switch(opcao){
            case 1:
                novoJogo();
                break;
            case 2:
                verRanking();
                break;
            case 3:
                limparRanking();
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
                break;
        }
    }while(opcao != 4);
    return 0;
}
