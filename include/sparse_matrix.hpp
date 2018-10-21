#ifndef SPARSEMATRIX_H
#define SPARSEMATRIX_H

#include <iostream>
#include <stdexcept>

#include "matrix_element.hpp"
#include "AvlTree.hpp"

using namespace std;

template <typename T>
class SparseMatrix
{
  public:
    SparseMatrix(const T &defValue)
    {
      this->def = defValue;
      this->elements = new AvlTree<MatrixElement<AvlTree<MatrixElement<T> > > >();
    }

    T get (int l, int c)
    {
      if (l < 0 || c < 0) {
        throw std::invalid_argument("Line and column must be greater than zero");
      }
      MatrixElement<AvlTree<MatrixElement<T> > >* line = this->elements->get(MatrixElement<AvlTree<MatrixElement<T> > >(l));
      if (line == nullptr) {
        return this->def;
      } else {
        MatrixElement<T>* column = line->getInfo()->get(MatrixElement<T>(c));
        if (column == nullptr) {
          return this->def;
        } else {
          return *column->getInfo();
        }
      }
    }

    void put (int l, int c, const T &v)
    {
      if (l < 0 || c < 0) {
        throw std::invalid_argument("Line and column must be greater than zero");
      }
      MatrixElement<AvlTree<MatrixElement<T> > >* line = this->elements->get(MatrixElement<AvlTree<MatrixElement<T> > >(l));
      if (line == nullptr) {
        line = new MatrixElement<AvlTree<MatrixElement<T> > >(l, AvlTree<MatrixElement<T> >());
        this->elements->add(*line);
      }

      MatrixElement<T>* column = line->getInfo()->get(MatrixElement<T> (c));
      if (column == nullptr) {
        column = new MatrixElement<T> (c, v);
      } else {
        line->getInfo()->remove(MatrixElement<T> (c));
      }

      line->getInfo()->add(MatrixElement<T> (c, v));
    }

  private:
    T def;
    AvlTree<MatrixElement<AvlTree<MatrixElement<T> > > >* elements;

};

#endif
