#include "campo.h"

void movimento(char campos[LINHAS][COLUNAS], int vx[7], int vy[7], int personagem[2], char icone[7]){

    char tecla = pegarInput();

    switch (tecla){
        //nada pressionado
    case '\0':
        break;

        //movimentaçao jogador 1
    case 's':
        vy[personagem[0]] = 1;
        vx[personagem[0]] = 0;
        break;

    case 'w':
        vy[personagem[0]] = -1;
        vx[personagem[0]] = 0;
        break;

    case 'a':
        vx[personagem[0]] = -1;
        vy[personagem[0]] = 0;
        break;

    case 'd':
        vx[personagem[0]] = 1;
        vy[personagem[0]] = 0;
        break;

        //mudança de controle entre personagens
    case 'e':
        personagem[0]++;
        if (personagem[0] == 3){
            personagem[0] = 0;
        }
        vx[personagem[0]] = 0;
        vy[personagem[0]] = 0;
        break;

        //movimento jogador 2
    case '2':
        vy[personagem[1]] = 1;
        vx[personagem[1]] = 0;
        break;

    case '5':
        vy[personagem[1]] = -1;
        vx[personagem[1]] = 0;
        break;

    case '1':
        vx[personagem[1]] = -1;
        vy[personagem[1]] = 0;
        break;

    case '3':
        vx[personagem[1]] = 1;
        vy[personagem[1]] = 0;
        break;

        //mudança de controle entre personagens
    case '6':
        personagem[1]++;
        if (personagem[1] == 7){
            personagem[1] = 3;
        }
        vx[personagem[1]] = 0;
        vy[personagem[1]] = 0;
        break;

    default:
        break;
    }

    for(int i = 0; i < LINHAS-1; i++){
        for(int j = 0; j < COLUNAS-1; j++){
            if(campos[i][j] == icone[personagem[0]] && campos[i+vy[personagem[0]]][j+vx[personagem[0]]] == ' '
               && i+vy[personagem[0]] > 0 && i+vy[personagem[0]] < LINHAS-1
               && j+vx[personagem[0]] > 0 && j+vx[personagem[0]] < COLUNAS-1){
                campos[i][j] = ' ';
                campos[i+vy[personagem[0]]][j+vx[personagem[0]]] = icone[personagem[0]];
                i = LINHAS;
                j = COLUNAS;
            }
        }
    }

    for(int i = 0; i < LINHAS-1; i++){
        for(int j = 0; j < COLUNAS-1; j++){
            if(campos[i][j] == icone[personagem[1]] && campos[i+vy[personagem[1]]][j+vx[personagem[1]]] == ' '
               && i+vy[personagem[1]] > 0 && i+vy[personagem[1]] < LINHAS-1
               && j+vx[personagem[1]] > 0 && j+vx[personagem[1]] < COLUNAS-1){
                campos[i][j] = ' ';
                campos[i+vy[personagem[1]]][j+vx[personagem[1]]] = icone[personagem[1]];
                return;
            }
        }
    }

}

void inserirPersonagens(char campo[LINHAS][COLUNAS], char icone[7])
{
    // Jogador 1
    campo[LINHAS/2][1] = icone [0];
    campo[LINHAS/2-3][10] = icone [1];
    campo[LINHAS/2+3][10] = icone [2];
    // Jogador 2
    campo[LINHAS/2][COLUNAS-2] = icone [3];
    campo[LINHAS/2-3][COLUNAS-11] = icone [4];
    campo[LINHAS/2+3][COLUNAS-11] = icone [5];
    // Bola
    campo[LINHAS/2][COLUNAS/2] = icone [6];
}

void preencherCampo(char campo1[LINHAS][COLUNAS]){

    for(int i = 0; i < COLUNAS; i++){
        campo1[0][i] = '=';
        campo1[LINHAS-1][i] = '=';
    }
    for(int i = 1; i < LINHAS-1; i++){
        if((LINHAS-2)/3 < i && (2*(LINHAS-2))/3 >= i){
            campo1[i][0] = ' ';
            campo1[i][COLUNAS-1] = ' ';
        }else{
        campo1[i][0] = '|';
        campo1[i][COLUNAS-1] = '|';
        }
        for(int j = 1; j < COLUNAS-1; j++){
            campo1[i][j] = ' ';
        }
    }
}

void desenharCampo(char campos[LINHAS][COLUNAS]){

    for(int i = 0; i < LINHAS; i++){
        for(int j = 0; j < COLUNAS; j++){
            printf("%c",campos[i][j]);
        }
        printf("\n\r");
    }
}
