#include <iostream>
#include<windows.h>
#include<conio.h>
#include <cstdlib>
#include "funcoesprograma.hpp"

using namespace std;
#define BLACK        0
#define BLUE         1
#define GREEN        2
#define AQUA         3
#define RED          4
#define PURPLE       5
#define YELLOW       6
#define WHITE        7
#define GRAY         8
#define LIGHTBLUE    9
#define LIGHTGREEN   10
#define LIGHTAQUA    11
#define LIGHTRED     12
#define LIGHTPURPLE  13
#define LIGHTYELLOW  14
#define BRIGHTWHITE  15


int main() {
int mapa[10][10] = {0,0,0,0,0,0,0,0,0,0,
                   0,0,0,0,0,0,0,0,0,0,
                   0,0,0,0,0,0,0,0,0,0,
                   0,0,0,0,0,0,0,0,0,0,
                   0,0,0,0,0,0,0,0,0,0,
                   0,0,0,0,0,0,0,0,0,0,
                   0,0,0,0,0,0,0,0,0,0,
                   0,0,0,0,0,0,0,0,0,0};
int x = 3, y = 3; //posição inicial;
int opcao;
bool jogoEmAndamento = false;


do {
      cor_texto(7,0); exibirMenu();
        cout << "Escolha uma opcao: ";
        cin >> opcao;
system("cls");
        switch (opcao) {
            case 1:
                system("cls");
                exibirEquipe();
                exibirRegras();
                break;
            case 2:
                if (jogoEmAndamento) {
                    cout << "Continuando o jogo..." << endl;
                opcao = 4;
                } else {
                    cout << "Nenhum jogo em andamento." << endl;
                }
                break;
           case 3:
    cout << "Deseja jogar em um mapa especifico? (1 = sim/0 = nao): ";
    cin >> opcao;
    if(opcao == 1) {
        cout << "Digite 1, 2 ou 3 para o mapa especifico:" << endl;
        cin >> opcao;
        posicaoboneco(opcao, x, y);
        system("cls");
        escolher_mapa(mapa, opcao);
        opcao = 4;
    } else if (opcao == 0) {
        system("cls");
        opcao = rand() % 3 + 1; // escolhe aleatoriamente entre 1, 2 ou 3
         posicaoboneco(opcao, x, y);
        escolher_mapa(mapa, opcao);
        opcao = 4;
    }
                jogoEmAndamento = true; // definir que o jogo está em andamento
                break;
            case 4:
                cout << "Encerrando o programa..." << endl;
                return 0;
                break;
            default:
                cout << "Opcao invalida. Tente novamente." << endl;

        }


while (jogoEmAndamento && !verifica_vitoria(mapa)) {
    int dx = 0, dy = 0;
    char tecla = getch();
    switch (tecla) {
        case 'w': dx = -1; break;
        case 'a': dy = -1; break;
        case 's': dx = 1; break;
        case 'd': dy = 1; break;
        case 'q': jogoEmAndamento = false; opcao = 1; break;

            break;
    }

    if (verifica_movimento(mapa, x, y, dx, dy)) {
        // Move o jogador e a caixa (se houver)
        if (mapa[x+dx][y+dy] == 2) {
            move_caixa(mapa, x+dx, y+dy, dx, dy);
        }
        x += dx;
        y += dy;
    }
    imprime_mapa(mapa, x, y);


}

if(jogoEmAndamento && verifica_vitoria(mapa)) {
cout << "Parabens ganhou!" << endl;
opcao = 1;
jogoEmAndamento = 0;
}
} while (opcao != 4);

return 0;
}
