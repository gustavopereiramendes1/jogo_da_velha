#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>


void linhaColuna(int linha, int coluna);
void CorTexto(int cor_texto, int cor_fundo);
void box(int linha1, int coluna1, int linha2, int coluna2);
void menu(int linha1, int coluna1, int qnt, char lista[4][40]);

enum{
    Preto,          //0
    Azul,           //1
    Verde,          //2
    Ciano,          //3
    Vermelho,       //4
    Magenta,        //5
    Marrom,         //6
    Amarelo=14,        //14
    Branco=15,         //15

};
enum{
    _Preto,              //0
    _Azul=16,           //16
    _Verde=32,          //32
    _Ciano=48,          //32
    _Vermelho=64,       //64
    _Magenta=80,        //80
    _Marrom=96,         //96
    _Amarelo=224,       //224
    _Branco=240,        //240

};

int main(){
    char lista[4][40] = {"Jogar" , "Ranking", "Sobre" , "Sair"};
    linhaColuna(15, 30);

    CorTexto(Azul, _Vermelho);
    menu(10, 10, 4, lista);
    setlocale(LC_ALL, "");

    CorTexto(Branco, _Preto);
    return 0;
}


void linhaColuna(int linha, int coluna){
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE) , (COORD){(coluna-1), (linha-1)});
}


void CorTexto(int cor_texto, int cor_fundo){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), cor_texto+cor_fundo);
}

void box(int linha1, int coluna1, int linha2, int coluna2){
    int i, j, qnt_linha, qnt_coluna;

    qnt_linha = linha2 - linha1;
    qnt_coluna = coluna2 - coluna1;

    for(i = coluna1; (i < coluna2) || (i == coluna2); i++){
        linhaColuna(linha1, i);
        printf("%c" , 196);
        linhaColuna(linha2, i);
        printf("%c" , 196);
    }

    for(i = linha1; (i < linha2) || (i == linha2); i++){
        linhaColuna(i, coluna1);
        printf("%c" , 179);
        linhaColuna(i, coluna2);
        printf("%c" , 179);
    }
    for(i = linha1+1; i < linha2; i++){
        for(j = coluna1+1; j < coluna2; j++){
            linhaColuna(i, j);
            printf(" ");
        }
    }
    linhaColuna(linha1, coluna1);
    printf("%c" , 218);
    linhaColuna(linha1 , coluna2);
    printf("%c" , 191);
    linhaColuna(linha2, coluna1);
    printf("%c" , 192);
    linhaColuna(linha2, coluna2);
    printf("%c" , 217);

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

    CorTexto(Branco, _Azul);
    setlocale(LC_ALL, "C");
    box(linha1, coluna1, linha2, coluna2);
    setlocale(LC_ALL, "");
    linha = linha1+2;
    linhaColuna(linha, coluna1+2);
    printf("Menu");

    for(i = 0; i< qnt;i++){
        linha+=2;
        linhaColuna(linha, coluna1+2);
        printf("%d- %s", i+1,lista[i]);
    }

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