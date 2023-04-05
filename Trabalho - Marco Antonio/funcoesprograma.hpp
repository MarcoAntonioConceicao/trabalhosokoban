#ifndef FUNCOESPROGRAMA_HPP_INCLUDED
#define FUNCOESPROGRAMA_HPP_INCLUDED

void cor_texto (int fonte, int fundo=0) {
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), (WORD) (fonte | fundo<<4));
}

void piscar_tela() {
    //INICIO: COMANDOS PARA QUE O CURSOR NÃO FIQUE PISCANDO NA TELA
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = false; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
    //FIM: COMANDOS PARA QUE O CURSOR NÃO FIQUE PISCANDO NA TELA
}

void posicionar_cursor() {
    short int CX=0, CY=0;
    COORD coord;
    coord.X = CX;
    coord.Y = CY;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void imprime_mapa(int m[10][10], int x, int y) {
    posicionar_cursor();
    for(int i=0; i<10; i++) {
        for(int j=0; j<10; j++) {
            if(i==x && j==y) {
                cor_texto(5,0);
                std::cout<<char(2); //personagem
                cor_texto(7,0);
            } else {
                switch(m[i][j]) {

                    case 0: cor_texto(0,0);std::cout<<" "; break; //caminho
                    case 1: cor_texto(4,0);std::cout<<char(178); break; //parede
                    case 2: cor_texto(6,0); std::cout<<char(254); break; //caixa
                    case 3: cor_texto(1,0); std::cout<<char(206); break; //ponto de destino
                    case 4: cor_texto(2,0); std::cout<<char(254); break; //caixa no destino
                    //default: cout<<"-"; //erro
                } //fim switch
            cor_texto(0,7);
            }
        }
        std::cout<<"\n";
    } //fim for mapa
}

bool verifica_movimento(int m[10][10], int x, int y, int dx, int dy) {
    // Verifica se o movimento é válido, ou seja, se o jogador não vai colidir com uma parede ou caixa
    if (m[x+dx][y+dy] == 1 || (m[x+dx][y+dy] == 2 && (m[x+dx*2][y+dy*2] == 1 || m[x+dx*2][y+dy*2] == 2))) {
        return false;
    }
    return true;
}

void move_caixa(int m[10][10], int x, int y, int dx, int dy) {
    // Move a caixa na direção dada
    if (m[x+dx][y+dy] == 3) {
        m[x+dx][y+dy] = 4; // Caixa no destino
    } else {
        m[x+dx][y+dy] = 2;
    }
    m[x][y] = m[x][y] == 4 ? 3 : 0; // Transforma o ponto de destino em parede ou a caixa no destino em ponto de destino
}

bool verifica_vitoria(int m[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (m[i][j] == 3) {
                return false;
            }
        }
    }
    return true;
}
void escolher_mapa(int mapa[10][10], int opcao) {
    int novo_mapa[10][10] = {{0,1,1,1,1,1,0,0,0,0},
                             {1,1,0,0,3,1,0,0,0,0},
                             {1,0,2,1,3,1,0,0,0,0},
                             {1,0,0,0,0,1,1,0,0,0},
                             {1,1,0,1,0,0,1,0,0,0},
                             {0,1,2,0,0,0,1,0,0,0},
                             {0,1,0,0,0,1,1,0,0,0},
                             {0,1,1,1,1,1,0,0,0,0}};
    int mapadois[10][10] =  {1,1,1,1,1,0,0,0,0,0,
                             1,0,0,0,1,0,0,0,0,0,
                             1,3,1,2,1,1,0,0,0,0,
                             1,0,0,0,0,1,0,0,0,0,
                             1,3,0,2,0,1,0,0,0,0,
                             1,1,1,0,0,1,0,0,0,0,
                             0,0,1,1,1,1,0,0,0,0,
                             0,0,0,0,0,0,0,0,0,0};


    int mapatres [10][10] = {0,0,0,0,1,1,1,1,1,0,
                            0,0,0,0,1,0,0,0,1,0,
                            1,1,1,1,1,0,1,0,1,1,
                            1,0,0,1,0,2,0,0,0,1,
                            1,0,0,0,2,0,0,1,0,1,
                            1,0,3,3,0,1,0,0,0,1,
                            1,1,1,0,0,1,1,1,1,1,
                            0,0,1,0,0,1,0,0,0,0,
                            0,0,1,1,1,1,0,0,0,0};

    if(opcao == 1) {
        for(int i=0; i<10; i++) {
            for(int j=0; j<10; j++) {
                mapa[i][j] = novo_mapa[i][j];
            }
        }
    } else if(opcao == 2) {
       for(int i=0; i<10; i++) {
            for(int j=0; j<10; j++) {
                mapa[i][j] = mapadois[i][j];
    }
}
}
else if(opcao == 3) {
       for(int i=0; i<10; i++) {
            for(int j=0; j<10; j++) {
                mapa[i][j] = mapatres[i][j];
}
}
}
}
void exibirEquipe() {
    std::cout << "Equipe de Desenvolvimento:" << std::endl;
    std::cout << "1. Marco Antonio da Conceicao" << std::endl;
    std::cout << "Desenvolvido em abril de 2023." << std::endl;
    std::cout << "Professor: Thiago Felski Pereira." << std::endl;
    std::cout << std::endl;
}
void exibirRegras() {
    std::cout << "Regras do Jogo:" << std::endl;
   std:: cout << "Sokoban e um jogo onde voce tem que empurrar todas as caixas para os pontos finais usando o seu boneco." << std::endl;
    std::cout << "Ele foi criado em 1981 por Hiroyuki Imabayashi e publicado em 1982 pela empresa Thinking Rabbit." << std::endl;
}
void exibirMenu() {
    std::cout << "MENU" << std::endl;
    std::cout << "1. Sobre" << std::endl;
    std::cout << "2. Continuar" << std::endl;
    std::cout << "3. Novo Jogo" << std::endl;
    std::cout << "4. Fim" << std::endl;
}
void posicaoboneco(int opcao, int& x, int& y) {
    if (opcao == 1) {
        x = 5, y = 4;
    }
    else if (opcao == 2) {
        x = 3, y = 3;
    }
    else if (opcao == 3) {
        x = 6, y = 3;
    }
}

#endif // FUNCOESPROGRAMA_HPP_INCLUDED
