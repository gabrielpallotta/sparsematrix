#ifndef SPARSEMATRIX_H
#define SPARSEMATRIX_H

#include <iostream>
#include <stdexcept>

#include "matrix_element.hpp"
#include "avl_tree.hpp"

using namespace std;

template <typename T>
class SparseMatrix
{
  public:
    SparseMatrix() {}

    SparseMatrix(const T &def_value)
    {
      def = def_value;
      elements = new AvlTree<MatrixElement<AvlTree<MatrixElement<T> > > >();
    }

    T get (int l, int c) const
    {
      if (l < 0 || c < 0) {
        throw std::invalid_argument("Line and column must be greater than zero");
      }
      MatrixElement<AvlTree<MatrixElement<T> > >* line = elements->get(MatrixElement<AvlTree<MatrixElement<T> > >(l));
      if (line == nullptr) {
        return def;
      } else {
        MatrixElement<T>* column = line->getInfo()->get(MatrixElement<T>(c));
        if (column == nullptr) {
          return def;
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
      MatrixElement<AvlTree<MatrixElement<T> > >* line = elements->get(MatrixElement<AvlTree<MatrixElement<T> > >(l));
      if (line == nullptr) {
        line = new MatrixElement<AvlTree<MatrixElement<T> > >(l, AvlTree<MatrixElement<T> >());
        elements->add(*line);
      }

      MatrixElement<T>* column = line->getInfo()->get(MatrixElement<T> (c));
      if (column == nullptr) {
        column = new MatrixElement<T> (c, v);
      } else {
        line->getInfo()->remove(MatrixElement<T> (c));
      }

      if (v != def) {
        line->getInfo()->add(MatrixElement<T> (c, v));
      } else {
        if (l > max_line) {
          max_line = l + 1;
        }
        
        if (c > max_column) {
          max_column = c + 1;
        }
      }

    }

    template <typename U> friend ostream& operator<<(ostream& os, const SparseMatrix<U>& matrix);
  private:
    T def;
    int max_line = 0;
    int max_column = 0;
    AvlTree<MatrixElement<AvlTree<MatrixElement<T> > > >* elements;

};

template <typename T>
ostream& operator<<(ostream& os, const SparseMatrix<T>& matrix)
{
  for (int i = 0; i < matrix.max_line; i++) {
    for (int j = 0; j < matrix.max_column; j++) {
      os << matrix.get(i, j) << " ";
    }
    os << std::endl;
  }

  return os;
}


#endif
