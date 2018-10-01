#ifndef SPARSEMATRIX_H
#define SPARSEMATRIX_H

#include <iostream>

using namespace std;

template <typename T>
class SparseMatrix
{
  public:
    SparseMatrix(const T &defValue)
    {
      this->def = defValue;
    }

    T get (int l, int c)
    {

    }

    T put (int l, int c, const T &v)
    {

    }

  private:
    T def;
}

#endif
