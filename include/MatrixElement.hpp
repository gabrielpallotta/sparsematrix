#ifndef MATRIXELEMENT_H
#define MATRIXELEMENT_H

#include <iostream>
#include "AvlTree.h"

using namespace std;

template <typename T>
class MatrixElement
{
  public:
    MatrixElement()
    {

    }

  private:
    AvlTree tree;
    int key;
}

#endif
