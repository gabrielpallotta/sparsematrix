#include <iostream>
#include <stdlib.h>

#ifdef _WIN32
  #define CLEAR_CMD "cls"
#elif _WIN64
  #define CLEAR_CMD "cls"
#elif __linux__
  #define CLEAR_CMD "clear"
#endif

#include "sparse_matrix.hpp"

using namespace std;

int main()
{
  cout << "Digite o valor padrao da matriz: ";

  int def_value;
  cin >> def_value;
  
  SparseMatrix<int> matrix(def_value);

  while (true) {
    system(CLEAR_CMD);
    cout << "Matriz esparsa:" << endl;
    matrix.print(cout, 20, 20);

    cout << "1 - Inserir" << endl;
    cout << "2 - Consultar" << endl << endl;
    cout << "Digite uma opcao: ";

    int option;
    cin >> option;

    int line;
    int column;
    int value;
    switch (option) {
      case 1:
        cout << "Digite a linha: ";
        cin >> line;
        cout << "Digite a coluna: ";
        cin >> column;
        cout << "Digite o valor: ";
        cin >> value;
        cout << endl;
        matrix.put(line, column, value);
        cout << "Valor inserido com sucesso" ;
        break;
      case 2:
        cout << "Digite a linha: ";
        cin >> line;
        cout << "Digite a coluna: ";
        cin >> column;
        cout << endl;
        cout << "Valor nessa posicao: " << matrix.get(line, column);
    }
    cout << endl << endl;
    cout << "Pressione qualquer tecla para continuar...";
    cin.sync();
    cin.ignore();
  }
}
