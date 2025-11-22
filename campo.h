#ifndef ARQUIVO_CAMPO

#include "io.h"

#define LINHAS 17
#define COLUNAS 80

void preencherCampo (char campo[LINHAS][COLUNAS]);
void inserirPersonagens (char campo[LINHAS][COLUNAS], char icone [7]);
void desenharCampo (char campo[LINHAS][COLUNAS]);

void movimento(char campos[LINHAS][COLUNAS],
               int velocidadeX[7], int velocidadeY[7],
               int personagem[2], char icone[7]);

#endif // ARQUIVO_CAMPO
