/*
    Trabalho de Computação 2 - 2025/2
    Autores:
        Gabriel --- ---
        Nicolas Lima Joaquim (ajudante)
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// Cabeçalhos de funções para o jogo
#include "campo.h"
#include "io.h"

// Definir o tempo máximo de jogo em segundos
#define TEMPO_MAXIMO 30

/* Início do jogo */
int main()
{
    iniciar();

    /* Variáveis */
    int tempo_jogo = 0;

    int tempo_inicial = time(0);

    char campo [LINHAS][COLUNAS];
    preencherCampo(campo);

    int vx [7] = {0, 0}, vy [7] = {0, 0};
    int personagem [2] = {0, 0};
    char icone [7] = {'(', '{', '[', ')', '}', ']', 'O'};
    inserirPersonagens(campo, icone);

    /* Loop do jogo */
    while (tempo_jogo < TEMPO_MAXIMO) // && deve_continuar
    {
        /* Atualização de variáveis */

        // Limitar FPS
        system(SLEEP);

        movimento(campo, vx, vy, personagem, icone);

        // Medir tempo decorrido
        tempo_jogo = time(0) - tempo_inicial;


        /* Desenho no terminal */
        system(CLEAR);
        desenharCampo(campo);
        printf("\n\rTempo: %d:%02d\n\r", (TEMPO_MAXIMO-tempo_jogo)/60, (TEMPO_MAXIMO-tempo_jogo)%60);
        printf("Pontuacao: %d x %d\t%c\n\r", 0, 0, icone[tempo_jogo%7]);
    }

    finalizar();

    return 0;
}
