/*
    Cabeçalho das funções de
    input e output para o Windows
*/
#ifdef _WIN32

#include <conio.h>

#define CLEAR "cls"

// Taxa de atualização
//  15 fps ≃ 0,066667 s
//  30 fps ≃ 0,033333 s
//  60 fps ≃ 0,016667 s
#define SLEEP "Sleep(0033)"

char pegarInput ();

#endif
