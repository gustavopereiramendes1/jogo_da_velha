#include <stdio.h>
#include <stdlib.h>

void sair();
void sobre();
void menu();

int main(){
    menu();
    return 0;
}

void menu()
{
    fflush(stdin);
    char opcao;

    printf("Menu\n\n1 - Jogar\n2 - Ranking\n3 - Sobre\n4 - Sair\n");

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
            sobre();
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
void sobre()
{
    printf("Sobre\n\nNome do programa: Elder's Game\nVersso: 2.30160304\nAutores: Enzo Faria, Bernardo Tibaldi, Gustavo Pereira, Caio Henrique");
    menu();
}