#include <iostream>
#include <string>
#include <vector>

using namespace std;

//struct para representar os nós e as adjacências do grafo
struct Palavra {
    string nome;
    int x, y, z;

    //vetor de significados funciona como a lista de adjacência do grafo (arestas)
    vector<string> significados;
};

//o dicionario, que armazena os vértices do grafo
vector<Palavra> dicionario;

void limparEntrada(){
    cin.clear();
    char lixo; 

    while(cin.get(lixo) && lixo != '\n');
}

//inserir palavras, coordenadas e grafo (arestas para os significados)
void cadastrarPalavra(){
    Palavra p;
    cout << "\n--- Cadastrar Palavra ---" << endl;
    cout << "Digite a palavra ficticia: ";
    cin >> p.nome;

    cout << "Digite as coordenadas x, y, z separadas por espaco: ";
    cin >> p.x >> p.y >> p.z;

    int qtdSignificados;
    cout << "Quantos significados essa palavra tem em portugues? ";
    cin >> qtdSignificados;

    for (int i = 0; i < qtdSignificados; i++) {
        string sig;
        cout << "Digite o significado " << i + 1 << ": ";
        cin >> sig;
        //adicionando a aresta no grafo
        p.significados.push_back(sig); 
    }

    dicionario.push_back(p);
    cout << "Palavra cadastrada com sucesso!" << endl;
}

//listar significados com base nas adjacências do grafo
void listarSignificado(){
    string busca;
    cout << "\n--- Listar Significados ---" << endl;
    cout << "Digite a palavra ficticia para ver os significados: ";
    cin >> busca;

    bool encontrou = false;
    for (int i = 0; i < dicionario.size(); i++) {
        if (dicionario[i].nome == busca) {
            encontrou = true;
            cout << "Significados (adjacencias no grafo):" << endl;
            for (int j = 0; j < dicionario[i].significados.size(); j++) {
                cout << "- " << dicionario[i].significados[j] << endl;
            }
            break;
        }
    }

    if (!encontrou) {
        cout << "Palavra nao encontrada no dicionario." << endl;
    }
}

//listar sinônimos de uma palavra (tem mesmo significado)
void listarSinonimos(){
    string busca;
    cout << "\n--- Listar Sinonimos ---" << endl;
    cout << "Digite a palavra ficticia para buscar os sinonimos: ";
    cin >> busca;

    int indice = -1;
    // Primeiro achamos a palavra no dicionario
    for (int i = 0; i < dicionario.size(); i++) {
        if (dicionario[i].nome == busca) {
            indice = i;
            break;
        }
    }

    if (indice == -1) {
        cout << "Palavra nao encontrada no dicionario." << endl;
        return;
    }

    cout << "Sinonimos encontrados (palavras com significados em comum):" << endl;
    bool achouSinonimo = false;
    
    //procura outras palavras que tenham pelo menos um significado igual
    for (int i = 0; i < dicionario.size(); i++) {
        if (i == indice) continue; //pula a propria palavra
        
        bool temComum = false;
        for (int j = 0; j < dicionario[indice].significados.size(); j++) {
            for (int k = 0; k < dicionario[i].significados.size(); k++) {
                if (dicionario[indice].significados[j] == dicionario[i].significados[k]) {
                    temComum = true;
                    break;
                }
            }
            if (temComum) break; //se achou um significado igual é sinonimo
        }
        
        if (temComum) {
            cout << "- " << dicionario[i].nome << endl;
            achouSinonimo = true;
        }
    }

    if (!achouSinonimo) {
        cout << "Nenhum sinonimo encontrado para esta palavra." << endl;
    }
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
    cout << "\n====== Dicionario de Palavras ======" << endl;
    cout << "1 - Cadastrar Palavra" << endl;
    cout << "2 - Listar significados de uma Palavra" << endl;
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
