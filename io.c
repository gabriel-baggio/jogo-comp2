/*
    Implementações das funções
    de input e output
*/
#include "io.h"

//===========================
// Para Windows
#ifdef _WIN32

void iniciar ()
{
    system(CLEAR);
}

void finalizar ()
{
    system("Sleep(1000)");
    system(CLEAR);
    printf("Jogador da %s ganhou!\n", "esquerda");
}

char pegarInput ()
{
    if (kbhit())
        return getch();
    else
        return '\0';
}

#endif


//===========================
// Para Linux
#ifdef __unix__

void iniciar ()
{
    //WINDOW * win = initscr();
    //nodelay(win, TRUE);
    nodelay(initscr(), TRUE);

    curs_set(FALSE);
    noecho();
    //clear();
    //cbreak();
}

void finalizar ()
{
    endwin();
    printf("Jogador da %s ganhou!\n", "esquerda");
}

char pegarInput ()
{
    char tecla = getch();

    if (tecla == ERR)
        return '\0';
    else
        return tecla;
}

#endif
