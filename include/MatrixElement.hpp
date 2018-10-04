#ifndef MATRIXELEMENT_H
#define MATRIXELEMENT_H

#include <iostream>
#include "AvlTree.h"

using namespace std;

template <typename T>
class MatrixElement
{
  public:
    MatrixElement(int key, T info)
    {
      this->key = key;
      this->info = info;
    }
    
  private:
    int key;
    T info;
}

#endif
