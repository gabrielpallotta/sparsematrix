#include <iostream>
#include "SparseMatrix.hpp"

using namespace std;

int main()
{
  SparseMatrix<int>* matrix = new SparseMatrix<int>(0);

  matrix->put(0, 1, 1);
  cout << matrix->get(0, 1) << endl;
  matrix->put(0, 2, 2);
  cout << matrix->get(0, 2) << endl;
  matrix->put(0, 3, 3);
  cout << matrix->get(0, 3) << endl;
  matrix->put(0, 4, 4);
  cout << matrix->get(0, 4) << endl;
  matrix->put(4, 4, 5);
  cout << matrix->get(4, 4) << endl;
  matrix->put(3, 4, 6);
  cout << matrix->get(3, 4) << endl;
  matrix->put(2, 4, 7);
  cout << matrix->get(2, 4) << endl;
  matrix->put(1, 4, 8);
  cout << matrix->get(1, 4) << endl;
  matrix->put(4, 4, 9);
  cout << matrix->get(4, 4) << endl;
  matrix->put(4, 4, 10);
  cout << matrix->get(4, 4) << endl;
  matrix->put(3, 4, 11);
  cout << matrix->get(3, 4) << endl;
  matrix->put(24, 4445, 12);
  cout << matrix->get(24, 4445) << endl;
  matrix->put(24, 4445, 13);
  cout << matrix->get(24, 4445) << endl;
  matrix->put(0, 0, 14);
  cout << matrix->get(0, 0) << endl;
  matrix->put(8, 8, 15);
  cout << matrix->get(8, 8) << endl;

  return 0;
}
