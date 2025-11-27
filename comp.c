#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <Windows.h>
#define LINHAS 17
#define COLUNAS 81
#define TEMPO_MAXIMO 100 // quantidade em segundos

void preencherCampo(char campo1[LINHAS][COLUNAS]){

    for(int i = 0; i < COLUNAS; i++){
        campo1[0][i] = '=';
        campo1[LINHAS-1][i] = '=';
    }
    for(int i = 1; i < LINHAS-1; i++){
        if((LINHAS-2)/3 < i && (2*(LINHAS-2))/3 >= i){
            campo1[i][0] = '-';
            campo1[i][COLUNAS-1] = '-';
        }else{
        campo1[i][0] = '#';
        campo1[i][COLUNAS-1] = '#';
        }
        for(int j = 1; j < COLUNAS-1; j++){
            campo1[i][j] = ' ';
        }
    }
}

void mudanca1Campo(char campo1[LINHAS][COLUNAS]){
    preencherCampo(campo1);
    campo1[14][55] = '#';
    campo1[3][12] = '#';
    campo1[7][40] = '#';
    campo1[1][1] = '#';
    campo1[10][73] = '#';
    campo1[15][10] = '#';
    campo1[4][50] = '#';
    campo1[15][33] = '#';
    campo1[2][18] = '#';
    campo1[9][41] = '#';
    campo1[1][79] = '#';
    campo1[9][67] = '#';
    campo1[15][4] = '#';
    campo1[4][29] = '#';
    campo1[13][59] = '#';
    campo1[6][3] = '#';
    campo1[12][71] = '#';
    campo1[3][5] = '#';
    campo1[14][22] = '#';
    campo1[1][35] = '#';
    campo1[6][6] = '#';
    campo1[12][12] = '#';
    campo1[2][2] = '#';
    campo1[15][16] = '#';
    campo1[1][1] = '#';
    campo1[9][13] = '#';
    campo1[10][7] = '#';
    campo1[15][9] = '#';

}

void mudanca2Campo(char campo1[LINHAS][COLUNAS]){
    preencherCampo(campo1);
    campo1[2][55] = '#';
    campo1[15][12] = '#';
    campo1[7][40] = '#';
    campo1[10][1] = '#';
    campo1[1][73] = '#';
    campo1[2][10] = '#';
    campo1[5][50] = '#';
    campo1[9][33] = '#';
    campo1[9][18] = '#';
    campo1[14][41] = '#';
}

void printMenu(){
    system("cls");
    printf("Menu: \n");
    printf("1) Rank de melhores pontuacoes\n");
    printf("2) Novo jogo\n");
    printf("3) Carregar jogo\n");
    printf("4) Controles\n");
    printf("5) Sair\n");
}

void printControles(){
    system("cls");
    printf("Movimentacao:\n");
    printf("cima: 'w' ou '5'\n");
    printf("baixo: 's' ou '2'\n");
    printf("esquerda: 'a' ou '1'\n");
    printf("direita: 'd' ou '3'\n");
    printf("trocar personagem: 'e' ou '6'\n");
    printf("chute: 'q'+ 'direcao desejeda' ou '4'+ 'direcao desejeda'\n");
    printf("Nota: os jogadores nao podem jogar a bola na direcao de seu lado do campo.\n");
    printf("Precione e segure 'p' durante a partida para sair e salvar\n");
    printf("\nprecione 'p' para voltar");
}

void desenharCampo(char campos[LINHAS][COLUNAS]){

    for(int i = 0; i < LINHAS; i++){
        for(int j = 0; j < COLUNAS; j++){  
            printf("%c",campos[i][j]);
        }
        printf("\n");
    }
}

void iniciarIcones(char campos[LINHAS][COLUNAS], char icone[7]){
    //coloca os personagens do jogador 1 nos locais inicias 
    campos[11][20] = icone[0];
    campos[5][20] = icone[1];
    campos[8][3] = icone[2];

    //coloca os personagens do jogador 2 nos locais inicias 
    campos[11][60] = icone[3];
    campos[5][60] = icone[4];
    campos[8][77] = icone[5];

    //coloca a bola no centro do campo
    campos[LINHAS/2][COLUNAS/2] = '0';
}

void movimentos(char campos[LINHAS][COLUNAS], int velocidadeX[7], int velocidadeY[7], int personagem[2], char icone[7], int velocidadeBola[0], int gol[2], int chute[2], int mapa){

    if(kbhit()){
        switch (getch()){
            //movimentaçao jogador 1
        case 's':
            velocidadeY[personagem[0]] = 1;
            velocidadeX[personagem[0]] = 0;
            break;

        case 'w':
            velocidadeY[personagem[0]] = -1;
            velocidadeX[personagem[0]] = 0;
            break;

        case 'a':
            velocidadeX[personagem[0]] = -1;
            velocidadeY[personagem[0]] = 0;
            break;

        case 'd':
            velocidadeX[personagem[0]] = 1;
            velocidadeY[personagem[0]] = 0;
            break;

            //mudança de controle entre personagens do jogador 1
        case 'e':
            personagem[0]++;
            if (personagem[0] == 3){
                personagem[0] = 0;
            }
            velocidadeX[personagem[0]] = 0;
            velocidadeY[personagem[0]] = 0;
            break;
            
            // chute da bola jogador 1
        case 'q':
            for(int i = 0; i < LINHAS-1; i++){
                for(int j = 0; j < COLUNAS-1; j++){
                    if(campos[i][j] == '0' && campos[i][j-1] == icone[personagem[0]]){
                        chute[0] = 1;
                        break;
                    }
                }
            }
            break;

            //movimento jogador 2
        case '2':
            velocidadeY[personagem[1]] = 1;
            velocidadeX[personagem[1]] = 0;
            break;

        case '5':
            velocidadeY[personagem[1]] = -1;
            velocidadeX[personagem[1]] = 0;
            break;

        case '1':
            velocidadeX[personagem[1]] = -1;
            velocidadeY[personagem[1]] = 0;
            break;

        case '3':
            velocidadeX[personagem[1]] = 1;
            velocidadeY[personagem[1]] = 0;
            break;

            //mudança de controle entre personagens do jogador 2
        case '6':
            personagem[1]++;
            if (personagem[1] == 6){
                personagem[1] = 3;
            }
            velocidadeX[personagem[1]] = 0;
            velocidadeY[personagem[1]] = 0;
            break;

            // chute da bola jogador 2
        case '4':
            for(int i = 0; i < LINHAS-1; i++){
                for(int j = 0; j < COLUNAS-1; j++){
                    if(campos[i][j] == '0' && campos[i][j+1] == icone[personagem[1]]){
                        chute[1] = 1;
                        break;
                    }
                }
            }
            break;

        case'p':
            return;
            break;
            
        default:
            break;
        }
    }
    // seleciona a direçao que a bola vai ser chutada
    if(kbhit()){
        if(chute[0] == 1){
            switch (getch()){
            case 'w':
                velocidadeBola[1] = -1;
                chute[0] = 0;
                break;
                    
            case 's':
                velocidadeBola[1] = 1;
                chute[0] = 0;
                break;

            case 'd':
                velocidadeBola[0] = 3;
                chute[0] = 0;
                break;

            default:
                break;
            }
        }
        if(chute[1] == 1){
            switch (getch()){
            case '5':
                velocidadeBola[1] = -1;
                chute[1] = 0;
                break;
                
            case '2':
                velocidadeBola[1] = 1;
                chute[1] = 0;
                break;

            case '1':
                velocidadeBola[0] = -3;
                chute[1] = 0;
                break;
            
            default:
                break;
            }
        }
    }
    //Movimentção dos personagens do jogador 1
    for(int i = 0; i < LINHAS-1; i++){
        for(int j = 0; j < COLUNAS-1; j++){
            if(campos[i][j] == icone[personagem[0]] && campos[i+velocidadeY[personagem[0]]][j+velocidadeX[personagem[0]]] == ' '){
                //personagem 1 para quando esta com a bola
                if(campos[i][j+1] == '0'){
                    velocidadeX[personagem[0]] = 0;
                    velocidadeY[personagem[0]] = 0;   
                }else{
                //se movimenta quando nao esta com a bola 
                    campos[i+velocidadeY[personagem[0]]][j+velocidadeX[personagem[0]]] = icone[personagem[0]];
                    campos[i][j] = ' ';
                }
                i = LINHAS;
                j = COLUNAS;
            }   
        }
    }

    //Movimentção dos personagens do jogador 2
    for(int i = 0; i < LINHAS-1; i++){
        for(int j = 0; j < COLUNAS-1; j++){
            if(campos[i][j] == icone[personagem[1]] && campos[i+velocidadeY[personagem[1]]][j+velocidadeX[personagem[1]]] == ' '){
                //personagem 2 para quando esta com a bola
                if(campos[i][j-1] == '0'){
                    velocidadeX[personagem[1]] = 0;
                    velocidadeY[personagem[1]] = 0;
                }else{
                //se movimenta quando nao esta com a bola    
                    campos[i+velocidadeY[personagem[1]]][j+velocidadeX[personagem[1]]] = icone[personagem[1]];
                    campos[i][j] = ' ';
                }
                return;
            } 
        }
    }

    // chute da bola 
    for(int i = 0; i < LINHAS-1; i++){
        for(int j = 0; j < COLUNAS-1; j++){
            //evita que a bola saia do campo
            if(campos[i][j] == '0'){
                //esquerda e direita
                if(j == 2 && velocidadeBola[0] < -2){
                    velocidadeBola[0] = -2;
                }else if(j == 1 && velocidadeBola[0] < -1){
                    velocidadeBola[0] = -1;
                }else if(i == 2 && velocidadeBola[1] < -2){
                    velocidadeBola[1] = -2;
                }else if(i == 1 && velocidadeBola[1] < -2){
                    velocidadeBola[1] = 0;
                }
                //cima e baixo
               if(j == COLUNAS-3 && velocidadeBola[0] < 2){
                    velocidadeBola[0] = 2;
                }else if(j == COLUNAS-2 && velocidadeBola[0] < 1){
                    velocidadeBola[0] = 1;
                }else if(i == LINHAS-4 && velocidadeBola[1] < 2){
                    velocidadeBola[1] = 2;
                }else if(i == LINHAS-3 && velocidadeBola[1] < 2){
                    velocidadeBola[1] = 0;
                }
            }

            if(campos[i][j] == '0'){
                
            }

            //confirma em que parte do campo a bola bateu
            if(campos[i][j] == '0' && campos[i+velocidadeBola[1]][j+velocidadeBola[0]] == ' ' && (velocidadeBola[0] != 0 || velocidadeBola[1] != 0)){
                if(i+velocidadeBola[1] != 0 || i+velocidadeBola[1] != LINHAS-1){
                    campos[i][j] = ' ';
                    campos[i+velocidadeBola[1]][j+velocidadeBola[0]] = '0';
                }
                velocidadeBola[1] = 0;
                velocidadeBola[0] = 0;
            }else if(campos[i][j] == '0' && campos[i+velocidadeBola[1]][j+velocidadeBola[0]] != ' ' && (velocidadeBola[0] != 0 || velocidadeBola[1] != 0)){
                campos[i][j] = ' ';
                // caso a bola tenha ido para as laterais 
                if((j+velocidadeBola[0] == 0 || j+velocidadeBola[0] == COLUNAS-1)&& campos[i][j+velocidadeBola[0]] == '#'){
                    if(j+velocidadeBola[0] == 0){
                        //limpa o campo
                        if(mapa == 1){
                            preencherCampo(campos);
                        }else if(mapa == 2){
                            mudanca1Campo(campos);
                        }else if(mapa == 3){
                            mudanca2Campo(campos);
                        }
                        //coloca os personagens do jogador 1 nos locais inicias 
                        campos[11][20] = icone[0];
                        campos[5][20] = icone[1];
                        campos[8][3] = icone[2];

                        //coloca os personagens do jogador 2 nos locais inicias 
                        campos[11][60] = icone[3];
                        campos[5][60] = icone[4];
                        campos[8][77] = icone[5];

                        campos[LINHAS/2][COLUNAS/4] = '0';
                        velocidadeBola[0] = 0;
                    }
                    if(j+velocidadeBola[0] == COLUNAS-1){
                        //limpa o campo
                        if(mapa == 1){
                            preencherCampo(campos);
                        }else if(mapa == 2){
                            mudanca1Campo(campos);
                        }else if(mapa == 3){
                            mudanca2Campo(campos);
                        }
                        //coloca os personagens do jogador 1 nos locais inicias 
                        campos[11][20] = icone[0];
                        campos[5][20] = icone[1];
                        campos[8][3] = icone[2];

                        //coloca os personagens do jogador 2 nos locais inicias 
                        campos[11][60] = icone[3];
                        campos[5][60] = icone[4];
                        campos[8][77] = icone[5];

                        campos[LINHAS/2][3*COLUNAS/4] = '0';
                        velocidadeBola[0] = 0;
                    }
                    
                }
                if(campos[i][j+velocidadeBola[0]] == '-'){
                    if(j+velocidadeBola[0] == 0){
                        gol[1]++;
                    }
                    if(j+velocidadeBola[0] >= COLUNAS-1){
                        gol[0]++;
                    }
                }
            }   
        }
    }
}

void iniciarVetores(int personagem[2], int gol[2], int velocidadeBola[2], int velocidadeX[7], int velocidadeY[7], char icone[7], int chute[2]){
    personagem[0] = 0;
    gol[0] = 0;
    gol[1] = 0;
    velocidadeBola[0] = 0;
    velocidadeBola[1] = 0;
    personagem[1] = 3;
    for(int i = 0; i < 7; i++){
        velocidadeX[i] = 0;
        velocidadeY[i] = 0;
    }
    icone[0] = '(';
    icone[1] = '{';
    icone[2] = '[';
    icone[3] = ')';
    icone[4] = '}';
    icone[5] = ']';
    chute[0] = 0;
    chute[1] = 0;
}

void menuPausa(int mapa, int tempo, int gol[2]){
    
    FILE *arquivo3;
    //arbrindo o arquivo
    arquivo3 = fopen("salvar.txt", "w");
     //gravando dados no arquivo
        fprintf(arquivo3, "%d\n", mapa);
        fprintf(arquivo3, "%d\n", tempo);
        fprintf(arquivo3, "%d\n", gol[0]);
        fprintf(arquivo3, "%d\n", gol[1]);
    //fechando o arquivo
    fclose(arquivo3);

}

void jogoSalvo(int *mapa, int *tempo, int gol[2]){

    FILE *arquivo4;
    //arbrindo o arquivo
    arquivo4 = fopen("salvar.txt", "r");
    //lendo dados no arquivo
        fscanf(arquivo4, "%d%d%d%d", mapa, tempo, &gol[0], &gol[1]);
    //fechando o arquivo
    fclose(arquivo4);
}

void ranking(int rank[6], int gol[2]){
    int ordem[2];
    //lendo o arquivo dos ranks 
    // Ponteiro para o arquivo
    FILE *arquivo;
    //arbrindo o arquivo
    arquivo = fopen("ranking.txt", "r");
    //lendo dados no arquivo
    for (int i = 0; i < 6; i++) {
        if (fscanf(arquivo, "%d", &rank[i]) != 1) {
        }
    }
    //fechando o arquivo
    fclose(arquivo);

    for(int i = 0; i < 3; i++){
        if(rank[i]+rank[i+3] < gol[0]+gol[1]){
            ordem[0] = rank[i];
            ordem[1] = rank[i+3];
            rank[i] = gol[0];
            rank[i+3] = gol[1];
            gol[0] = ordem[0];
            gol[1] = ordem[1];
        }
    }


    //salvando os ranks em arquivos
    // Ponteiro para o arquivo
    FILE *arquivo2;
    //arbrindo o arquivo
    arquivo2 = fopen("ranking.txt", "w");
    //gravando dados no arquivo
    for (int i = 0; i < 6; i++) {
        fprintf(arquivo2, "%d\n", rank[i]);
    }
    //fechando o arquivo
    fclose(arquivo2);
}

int main(){

    char campos[LINHAS][COLUNAS], icone[7];
    int velocidadeX[7], velocidadeY[7], personagem[2], velocidadeBola[2];
    int gol[2], reset = 0, totalGol = 0, chute[2], rank[6];
    int tempo_jogo = 0, mapa = 0;
    int tempo_inicial = time(0);
    
    ranking(rank, gol);
    printMenu();
    
    while (1){
        switch (getch()){
        case '1':
            system("cls");
            for(int i = 0; i < 3; i++){
                    printf("%d X %d\n",rank[i], rank[i+3]);
                }
                printf("\nprecione 'p' para voltar");
            break;

        case'2':
        //escolha do mapa
            system("cls");
            printf("Escolha o mapa:\n");
            printf("Mapa: 1\n");
            printf("Mapa: 2\n");
            printf("Mapa: 3\n");
            switch (getch()){
            case '1':
            mapa = 1;
                break;
            case '2':
                mapa = 2;
                break;
            case '3':
                mapa = 3;
                break;
            }
            //inicia o jogo
            
            system("cls");
            iniciarVetores(personagem, gol, velocidadeBola, velocidadeX, velocidadeY, icone, chute);
            if(mapa == 1){
                    preencherCampo(campos);
            }else if(mapa == 2){
                    mudanca1Campo(campos);
            }else if(mapa == 3){
                    mudanca2Campo(campos);                    
            }

            tempo_inicial = time(0);
            tempo_jogo = 0;
            iniciarIcones(campos, icone);
            while (tempo_jogo < TEMPO_MAXIMO){   
                        Sleep(0033);
                        //coloca tudo no local inicial caso um gol tenha sido feito
                        if(totalGol != gol[0] + gol[1]){
                            reset++;
                            totalGol = gol[0] + gol[1];
                        }
                        //coloca uma nova bola em campo caso nao tenha nehuma em campo
                        for(int i = 0; i < LINHAS; i++){
                            for(int j = 0; j < COLUNAS; j++){  
                                if(campos[i][j] == '0'){
                                    j = 100;
                                    i = 30;
                                }else if(i == LINHAS-1 && j == COLUNAS-1){
                                    campos[LINHAS/2][COLUNAS/2] = '0';
                                }
                            }   
                        }

                        system("cls");
                        movimentos(campos, velocidadeX, velocidadeY, personagem, icone, velocidadeBola, gol, chute, mapa);
                        desenharCampo(campos);
                        printf("\nTempo: %d:%02d\n", (TEMPO_MAXIMO-tempo_jogo)/60, (TEMPO_MAXIMO-tempo_jogo)%60);
                        printf("Pontuacao: %d x %d\n", gol[0], gol[1]);
                        if(reset == 1){
                            if(mapa == 1){
                                preencherCampo(campos);
                            }else if(mapa == 2){
                                    mudanca1Campo(campos);
                            }else if(mapa == 3){
                                    mudanca2Campo(campos);                    
                            }
                            iniciarIcones(campos, icone);
                            reset = 0;
                        }
                        //tempo decorrido
                        tempo_jogo = time(0) - tempo_inicial;
                        if(kbhit()){
                            if(getch() == 'p'){
                                system("cls");
                                printMenu();
                                menuPausa(mapa, tempo_jogo, gol); 
                                tempo_jogo = TEMPO_MAXIMO;
                            }
                        }
                        
                }
            system("cls");
            printMenu();
            //zera o mapa
            mapa = 0;
        break;

        case'3':
            iniciarVetores(personagem, gol, velocidadeBola, velocidadeX, velocidadeY, icone, chute);
            //retoma o jogo de onde parou
            jogoSalvo(&mapa, &tempo_jogo, gol);
            if(mapa == 1){
                    preencherCampo(campos);
            }else if(mapa == 2){
                    mudanca1Campo(campos);
            }else if(mapa == 3){
                    mudanca2Campo(campos);                    
            }
            iniciarIcones(campos, icone);
            
            while (tempo_jogo < TEMPO_MAXIMO){
                        Sleep(0033);
                        //coloca tudo no local inicial caso um gol tenha sido feito
                        if(totalGol != gol[0] + gol[1]){
                            reset++;
                            totalGol = gol[0] + gol[1];
                        }
                        //coloca uma nova bola em campo caso nao tenha nehuma em campo
                        for(int i = 0; i < LINHAS; i++){
                            for(int j = 0; j < COLUNAS; j++){  
                                if(campos[i][j] == '0'){
                                    j = 100;
                                    i = 30;
                                }else if(i == LINHAS-1 && j == COLUNAS-1){
                                    campos[LINHAS/2][COLUNAS/2] = '0';
                                }
                            }   
                        }

                        system("cls");
                        movimentos(campos, velocidadeX, velocidadeY, personagem, icone, velocidadeBola, gol, chute, mapa);
                        desenharCampo(campos);
                        printf("\nTempo: %d:%02d\n", (TEMPO_MAXIMO-tempo_jogo)/60, (TEMPO_MAXIMO-tempo_jogo)%60);
                        printf("Pontuacao: %d x %d\n", gol[0], gol[1]);
                        if(reset == 1){
                            if(mapa == 1){
                                preencherCampo(campos);
                            }else if(mapa == 2){
                                    mudanca1Campo(campos);
                            }else if(mapa == 3){
                                    mudanca2Campo(campos);                    
                            }
                            iniciarIcones(campos, icone);
                            reset = 0;
                        }
                        //tempo decorrido
                        tempo_jogo = time(0) - tempo_inicial;
                        /*if(kbhit()){
                            if(getch() == 'p'){
                                system("cls");
                                printMenu();
                                menuPausa(mapa, tempo_jogo, gol); 
                                tempo_jogo = TEMPO_MAXIMO;
                            }
                        }*/
                        
                }
            system("cls");
            printMenu();
            //zera o mapa
            mapa = 0;
            break;

        case'p':
            printMenu();
            break;

        case'4':
            printControles();
            break;

        case'5':
            system("cls");
            printf("Obrigado por jogar!!!!");
            return 0;
            break;    
        
        default:
            break;
        }

        ranking(rank, gol);
        
        }
            
    
    
    
}
