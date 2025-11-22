/*
    Trabalho de Computação 2 - 2025/2
    Autores:
        Gabriel --- ---
        Nicolas Lima Joaquim (ajudande)
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "campo.h"

// Windows ou Linux
#include "io-windows.h"
#include "io-linux.h"

// Definir o tempo máximo de jogo em segundos
#define TEMPO_MAXIMO 5 // quantidade em segundos

/* Início do jogo */
int main()
{
    /* Variáveis */
    int tempo_jogo = 0;

    int tempo_inicial = time(0);

    char campo [LINHAS][COLUNAS];
    preencherCampo(campo);

    char velocidade = '\0';

    /* Loop do jogo */
    while (tempo_jogo < TEMPO_MAXIMO) // && deve_continuar
    {
        /* Atualização de variáveis */

        // Limitador de FPS
        system(SLEEP);

        // Tempo decorrido
        tempo_jogo = time(0) - tempo_inicial;

        /* Desenho no terminal */
        system(CLEAR);
        desenharCampo(campo);
        printf("\nTempo: %d:%02d\n", (TEMPO_MAXIMO-tempo_jogo)/60, (TEMPO_MAXIMO-tempo_jogo)%60);
        printf("Pontuacao: %d x %d\t%c\n", 0, 0, velocidade);
    }

    return 0;
}
