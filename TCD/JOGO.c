#include <stdio.h>
#include<windows.h>

void imprimir_tabu(char tabuleiro[][3]);
void gotoxy(int x, int y);
void jogada(char tabuleiro[][3]);

int main(){
    char tabuleiro[3][3];
    

    for(int i = 0; i < 3;i++){
        for(int j = 0; j < 3;j++){
            tabuleiro[i][j] = ' ';
        }
    }

    imprimir_tabu(tabuleiro);

    

    

    jogada(tabuleiro);
    return 0;
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

void jogada(char tabuleiro[][3]){
    int x, y, px, py;
    printf("\n\nDigite o valor de x e y: ");
    scanf("%d%d" , &py, &px);
    //função que escreve no tabuleiro de acordo com a posicao digitada
               
    //variaveis que armazenaram as posições de acordo com a tela do console
    for(x = 1; px > 1; x+=4, px--);               
    for(y = 0; py > 1; y+=2, py--);
    //progressão aritmetica usando "for" para atribuir a posição no console de acordo com o tabuleiro           
    gotoxy(x, y);                                   
    //chamando a função gotoxy, para mover o cursor no console
    printf("X");                                    
    tabuleiro[px][py] = 'X';                        
    //armazena a mudança na matriz
    Sleep(5000);
    //dorme
}
