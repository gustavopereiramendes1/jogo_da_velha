#include <stdio.h>
#include <windows.h>
void gotoxy(int x, int y);
void jogada(int px, int py, char tabuleiro[][3]);
void imprimir_tabu(char tabuleiro[][3]);
void verifica_vez(char tabuleiro[][3], int i);

int main(){
    char tabuleiro[3][3];

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            tabuleiro[i][j] = ' ';
        }
    }

    imprimir_tabu(tabuleiro);

    for (int i = 0; i < 9; i++){
        verifica_vez(tabuleiro, i);
        gotoxy(0, 7);

    }

    return 0;
}

void jogada(int px, int py, char tabuleiro[][3]){
    //função que escreve no tabuleiro de acordo com a posicao digitada
    int x, y;
    //variaveis que armazenaram as posições de acordo com a tela do console
    for(x = 1; px > 1; x+=4, px--);
    for(y = 0; py > 1; y+=2, py--);
    //progressão aritmetica usando "for" para atribuir a posição no console de acordo com o tabuleiro
    gotoxy(x, y);
    //chamando a função gotoxy, para mover o cursor no console


    //armazena a mudança na matriz

    //dorme
}

void imprimir_tabu(char tabuleiro[][3]){
    for(int linha = 0; linha < 3; linha++){
        for(int coluna = 0; coluna < 3; coluna++){

            switch (coluna)
            {
            case 0:
                printf(" %c ", tabuleiro[linha][coluna]);
                break;
            case 1:
                printf("| %c |" , tabuleiro[linha][coluna]);
                break;
            case 2:
                printf(" %c ", tabuleiro[linha][coluna]);
                printf("\n");
                printf((linha!=2)?"___|___|___\n": "   |   |   \n");
            default:
                break;
            }
        }
    }
}

void gotoxy(int x, int y)
{
    HANDLE stdOutput;
    COORD pos;

    stdOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(stdOutput, pos);
}

void verifica_vez(char tabuleiro[][3], int i){
    int px, py;

        if (!(i % 2)){
            scanf("%d%d", &py, &px);
            printf("\b\b\b");
            jogada(px, py, tabuleiro);
            printf("X");
            //Sleep(2000);
            tabuleiro[px][py] = 'X';
        }
        else{
            scanf("%d%d", &py, &px);
            jogada(px, py, tabuleiro);
            printf("O");
            //Sleep(2000);
            tabuleiro[px][py] = 'O';
        }



}
