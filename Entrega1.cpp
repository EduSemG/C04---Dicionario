#include <iostream> 
using namespace std;

void limparEntrada(){
    cin.clear();
    char lixo; 

    while(cin.get(lixo) && lixo != '\n');
}

void cadastrarPalavra(){
    cout << "Funcionalidade em Construcao" << endl; 
}

void listarSignificado(){
    cout << "Funcionalidade em Construcao" << endl; 
}

void listarSinonimos(){
    cout << "Funcionalidade em Construcao" << endl; 
}

void listarOrdemAlfabetica(){
    cout << "Funcionalidade em Construcao" << endl; 
}

void listarOrdemTamanho(){
    cout << "Funcionalidade em Construcao" << endl; 
}

void removerPalavra(){
    cout << "Funcionalidade em Construcao" << endl; 
}

void CalcularSimiliridade(){
    cout << "Funcionalidade em Construcao" << endl; 
}

void menu(){
    cout << "\n======Dicionario de Palavras======" << endl;
    cout << "1 - Cadastrar Palavra" << endl;
    cout << "2 - Listar siginificados de uma Palavra" << endl;
    cout << "3 - Listar Sinonimos de uma Palavra" << endl;
    cout << "4 - Listar Palavras em Ordem Alfabetica" << endl;
    cout << "5 - Listar Palavras em Ordem de Tamanho" << endl;
    cout << "6 - Remover Palavra" << endl;
    cout << "7 - Calcular Similiridade entre duas Palavras" << endl;
    cout << "0 - Sair" << endl;
    cout << "====================================" << endl;
    cout << "Escolha uma opcao: ";
}

int main(){
    int opcao; 

    do{
        menu();

        if (!(cin >> opcao)) {
            cout << "Erro: digite apenas um numero!" << endl;
            limparEntrada();
            continue;
        }

        if (opcao < 0 || opcao > 7) {
            cout << "Erro: opcao invalida. Digite um numero entre 0 e 7" << endl;
            continue;
        }

        switch(opcao){
            case 1:
                cadastrarPalavra();
                break;
            case 2:
                listarSignificado();
                break;
            case 3:
                listarSinonimos();
                break;
            case 4:
                listarOrdemAlfabetica();
                break;
            case 5:
                listarOrdemTamanho();
                break;
            case 6:
                removerPalavra();
                break;
            case 7:
                CalcularSimiliridade();
                break;
            case 0:
                cout << "Saindo do programa..." << endl;
                break;
            default:
                cout << "Opcao invalida. Tente novamente." << endl;
        }

    } while(opcao != 0);

    return 0;
}
