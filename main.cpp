#include <iostream>
#include "SparseMatrix.hpp"

using namespace std;

int main()
{
  SparseMatrix<int>* matrix = new SparseMatrix<int>(0);
  matrix->put(0, 0, 53);
  matrix->put(0, 1, 54);
  cout << matrix->get(0, 0) << endl;
  cout << matrix->get(0, 1) << endl;
  matrix->put(0, 1, 57);
  cout << matrix->get(0, 1) << endl;

  return 0;
}
