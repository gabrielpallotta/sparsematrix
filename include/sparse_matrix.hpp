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
        if (v == def) {
          return;
        } else {
          line = new MatrixElement<AvlTree<MatrixElement<T> > >(l, AvlTree<MatrixElement<T> >());
          elements->add(*line);
        }
      }

      MatrixElement<T>* column = line->getInfo()->get(MatrixElement<T> (c));
      MatrixElement<T> new_column = MatrixElement<T> (c, v);

      if (column == nullptr) {
        if (v == def) {
          return;
        } else {
          line->getInfo()->add(new_column);
        }
      } else {  
        line->getInfo()->remove(*column);
        if (v != def) {
          line->getInfo()->add(new_column);
        }
        if (line->getInfo()->getHeight() == 0) {
          elements->remove(*line);
        }
      }
    }
    
    void print (ostream& os, int max_line, int max_column)
    {
      for (int i = 0; i < max_line; i++) {
        for (int j = 0; j < max_column; j++) {
          os << get(i, j) << " ";
        }
        os << std::endl;
      }
    }

  private:
    T def;
    int max_line = 0;
    int max_column = 0;
    AvlTree<MatrixElement<AvlTree<MatrixElement<T> > > >* elements;

};

#endif
