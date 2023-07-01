#include <iostream>
#include <windows.h>
#include <time.h>

using namespace std;

int main()
{
    setlocale(LC_ALL,"Portuguese");
    /// Declaração de variáveis e srand
    srand(time(NULL));
    bool fim = false, perdeu;
    char m_Jogo[9][9];
    int i,j, x_cont,gabarito_cont, linha,coluna,numero, random50,random35,random15, tipo, escolha_menu, dificuldade;
    int m_Gabarito[9][9];
    int m_Original[9][9]={5,3,4,6,7,8,9,1,2,
                          6,7,2,1,9,5,3,4,8,
                          1,9,8,3,4,2,5,6,7,
                          8,5,9,7,6,1,4,2,3,
                          4,2,6,8,5,3,7,9,1,
                          7,1,3,9,2,4,8,5,6,
                          9,6,1,5,3,7,2,8,4,
                          2,8,7,4,1,9,6,3,5,
                          3,4,5,2,8,6,1,7,9};
    /// Atribuição da matriz gabarito aleatoriamente
    tipo = rand()%4+1;
    switch (tipo) {
        case 1:
            for (i=0;i<9;i++) {
                for (j=0;j<9;j++) {
                    m_Gabarito[i][j] = m_Original[i][j];
                }
            }
            break;
        case 2:
            for (i=0;i<9;i++) {
                for (j=0;j<9;j++) {
                    m_Gabarito[i][j] = m_Original[j][i];
                }
            }
            break;
        case 3:
            for (i=0;i<9;i++) {
                for (j=0;j<9;j++) {
                    m_Gabarito[i][j] = m_Original[8-i][j];
                }
            }
            break;
        case 4:
            for (i=0;i<9;i++) {
                for (j=0;j<9;j++) {
                    m_Gabarito[i][j] = m_Original[i][8-j];
                }
            }
            break;
    }
    /// Jogo roda enquanto fim = false
    dificuldade = 0;
    do {
        system("cls");
        /// Menu
        switch (dificuldade) {
            case 0:
                cout<< "1 - Jogar\n\n2 - Dificuldade\n\n3 - Sobre\n\n4 - Fim\n\n";
                cin>>escolha_menu;
                break;
            case 1:
                cout<< "1 - Jogar (fácil)\n\n2 - Dificuldade\n\n3 - Sobre\n\n4 - Fim\n\n";
                cin>>escolha_menu;
                break;
            case 2:
                cout<< "1 - Jogar (médio)\n\n2 - Dificuldade\n\n3 - Sobre\n\n4 - Fim\n\n";
                cin>>escolha_menu;
                break;
            case 3:
                cout<< "1 - Jogar (difícil)\n\n2 - Dificuldade\n\n3 - Sobre\n\n4 - Fim\n\n";
                cin>>escolha_menu;
                break;
        }
        switch (escolha_menu) {
            /// Fim
            case 4:
                fim = true;
                break;
            /// Sobre
            case 3:
                system("cls");
                cout<<"Levyzão\njunho/2023\nCristina Ono\nAlgorítmo e Programação 1\n\n";
                system("pause");
                break;
            case 2:
            /// Dificuldade
                system("cls");
                cout<<"1 - Fácil\n\n2 - Médio\n\n3 - Difícil\n\n";
                cin>>dificuldade;
                /// Atribuição da matriz jogo dependendo da dificuldade e porcentagem - 50% fácil, 35% médio, 15% difícil
                switch (dificuldade) {
                    case 1:
                        /// Fácil
                        gabarito_cont = 0;
                        x_cont = 0;
                        for (i=0;i<9;i++) {
                            for (j=0;j<9;j++) {
                                if (x_cont < 42 && gabarito_cont < 42) {
                                    random50 = rand()%2;
                                    if (random50 == 0) {
                                        m_Jogo[i][j] = '#';
                                        x_cont++;
                                    }
                                    else {
                                        m_Jogo[i][j] = m_Gabarito[i][j] + '0';
                                        gabarito_cont++;
                                    }
                                }
                                else {
                                    if (x_cont < 42) {
                                        m_Jogo[i][j] = '#';
                                        x_cont++;
                                    }
                                    else {
                                        m_Jogo[i][j] = m_Gabarito[i][j] + '0';
                                        gabarito_cont++;
                                    }
                                }
                            }
                        }
                        break;
                    case 2:
                        /// Médio
                        gabarito_cont = 0;
                        x_cont = 0;
                        for (i=0;i<9;i++) {
                            for (j=0;j<9;j++) {
                                if (x_cont < 54 && gabarito_cont < 30) {
                                    random35 = rand()%3;
                                    if (random35 < 2) {
                                        m_Jogo[i][j] = '#';
                                        x_cont++;
                                    }
                                    else {
                                        m_Jogo[i][j] = m_Gabarito[i][j] + '0';
                                        gabarito_cont++;
                                    }
                                }
                                else {
                                    if (x_cont < 54) {
                                        m_Jogo[i][j] = '#';
                                        x_cont++;
                                    }
                                    else {
                                        m_Jogo[i][j] = m_Gabarito[i][j] + '0';
                                        gabarito_cont++;
                                    }
                                }
                            }
                        }
                        break;
                    case 3:
                        /// Difícil
                        gabarito_cont = 0;
                        x_cont = 0;
                        for (i=0;i<9;i++) {
                            for (j=0;j<9;j++) {
                                if (x_cont < 66 && gabarito_cont < 14) {
                                    random15 = rand()%7;
                                    if (random15 < 6) {
                                        m_Jogo[i][j] = '#';
                                        x_cont++;
                                    }
                                    else {
                                        m_Jogo[i][j] = m_Gabarito[i][j] + '0';
                                        gabarito_cont++;
                                    }
                                }
                                else {
                                    if (x_cont < 66) {
                                        m_Jogo[i][j] = '#';
                                        x_cont++;
                                    }
                                    else {
                                        m_Jogo[i][j] = m_Gabarito[i][j] + '0';
                                        gabarito_cont++;
                                    }
                                }
                            }
                        }
                        break;
                    default:
                        cout<<"Valor inválido. Digite um número de 1 a 3.\n";
                }
                break;
            case 1:
            /// Jogar
                system("cls");
                if (dificuldade < 1) {
                    cout<<"Escolha uma dificuldade para poder jogar.\n\n";
                    system("pause");
                    break;
                }
                while (fim == false) {
                    system("cls");
                    for (i=0;i<9;i++) {
                        for (j=0;j<9;j++) {
                            if (j%3-2 != 0) {
                                cout<<m_Jogo[i][j]<<"   ";
                            }
                            else cout<<m_Jogo[i][j]<<"  |  ";
                        }
                        if (i%3-2 != 0) {
                            cout<<"\n\n";
                        }
                        else cout<<"\n----------------------------------------\n";
                    }
                    cout<<"\nEscolha uma coordenada (Linha x Coluna)\n";
                    cin>>linha>>coluna;
                    cout<<"\nEscolha o número dentro da coordenada ("<<linha<<"x"<<coluna<<")\n";
                    cin>>numero;
                    linha--;
                    coluna--;
                    system("cls");
                    for (i=0;i<9;i++) {
                        for (j=0;j<9;j++) {
                            if (i == linha && j == coluna) {
                                m_Jogo[i][j] = numero + '0';
                            }
                            if (j%3-2 != 0) {
                                cout<<m_Jogo[i][j]<<"   ";
                            }
                            else cout<<m_Jogo[i][j]<<"  |  ";
                        }
                        if (i%3-2 != 0) {
                            cout<<"\n\n";
                        }
                        else cout<<"\n----------------------------------------\n";
                    }
                    /// Expressão lógica que verifica se o jogo acabou ou não
                    fim = true;
                    for (i=0;i<9;i++) {
                        for (j=0;j<9;j++) {
                            if (m_Jogo[i][j] != m_Gabarito[i][j] + '0') {
                                fim = false;
                                break;
                            }
                        }
                    }
                    /// Expressão lógica que avisa se o jogador preencheu o sudoku incorretamente
                    for (i=0;i<9;i++) {
                        for (j=0;j<9;j++) {
                            if (m_Jogo[i][j] == '#' || fim == true) {
                                perdeu = false;
                                break;
                            }
                            else perdeu = true;
                        }
                    }
                    if (perdeu) {
                        cout<<"Você pisou na bola hein. Preencheste o sudoku incorretamente. Reinicie o jogo ou se vire aí.\n";
                        system("pause");
                    }
                }
                break;
        }
    }
    while (fim == false);
    return 0;
}
