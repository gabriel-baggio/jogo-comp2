/*
    Cabeçalho das funções
    de input e output
*/
#ifndef ARQUIVO_IO
#define ARQUIVO_IO

#include <stdio.h>
#include <stdlib.h>

//===========================
// Para Windows
#ifdef _WIN32

#include <conio.h>

#define CLEAR "cls"

// Taxa de atualização
//  33 ms ~ 30 fps
#define SLEEP "Sleep(0033)"

void iniciar ();
void finalizar ();

char pegarInput ();

#endif


//===========================
// Para Linux
#ifdef __unix__

#include <ncurses.h>

#define CLEAR "clear"

// Taxa de atualização
//  30 fps ~ 0,033333 s
#define SLEEP "sleep 0.033333"

void iniciar ();
void finalizar ();

char pegarInput ();

#endif


#endif // ARQUIVO_IO
