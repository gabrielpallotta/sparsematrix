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
      return this->elements->find(l)->find(c);
    }

    T put (int l, int c, const T &v)
    {

    }

  private:
    T def;
    MatrixElement<MatrixElement<AvlTree<T> > > elements;
    
}

#endif
