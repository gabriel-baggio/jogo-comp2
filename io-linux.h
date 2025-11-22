/*
    Cabeçalho das funções de
    input e output para Linux
*/
#ifdef __unix__

#include <ncurses.h>

#define CLEAR "clear"

// Taxa de atualização
//  15 fps ≃ 0,066667 s
//  30 fps ≃ 0,033333 s
//  60 fps ≃ 0,016667 s
#define SLEEP "sleep 0.033333"

char pegarInput ();

#endif
