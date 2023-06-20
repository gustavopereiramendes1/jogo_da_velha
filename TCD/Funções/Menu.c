#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sair();
void sobre(char lista[4][40]);
void menu(int linha1, int coluna1, int qnt, char lista[4][40]);

int main(){
    char lista[4][40] = {"Jogar" , "Ranking", "Sobre" , "Sair"};
    menu(10, 10, 4, lista);
    return 0;
}

void menu(int linha1, int coluna1, int qnt, char lista[4][40]){
    char opcao;
    int linha2, coluna2, linha, i, tamanhoMax, tecla;

    fflush(stdin);
    tamanhoMax = strlen(lista[0]);

    for(i = 1; i < qnt; i++){
        if(strlen(lista[i]) > tamanhoMax){
            tamanhoMax = strlen(lista[i]);
        }
    }

    linha2 = linha1+(qnt*2+2);
    coluna2 = coluna1+(tamanhoMax+4);

    printf("Menu\n\n1 - %s\n2 - %s\n3 - %s\n4 - %s\n" , lista[0] , lista[1], lista[2], lista[3]);

    while (1)
    {
        scanf ("%c", &opcao);

        if ( opcao == '1' || opcao == '2' || opcao == '3' || opcao == '4' )
        {
            break;
        }
        else
        {
            printf ("Opcao invalida. Digite novamente:\n");
        }
    }
    switch (opcao)
    {
        case '1':
        {
            printf("A opcao Jogar foi selecionada!\n");
            break;
        }
        case '2':
        {
            printf("A opcao Ranking foi selecionada!\n");
            break;
        }
        case '3':
        {
            sobre(lista);
            break;
        }
        case '4':
        {
            sair();
            break;
        }
    }
}
void sair()
{
    printf("Obrigado por jogar!");
    exit(0);
}
void sobre(char lista[4][40])
{
    printf("Sobre\n\nNome do programa: Elder's Game\nVersso: 2.30160304\nAutores: Enzo Faria, Bernardo Tibaldi, Gustavo Pereira, Caio Henrique");
    menu(10, 10, 4, lista);
}