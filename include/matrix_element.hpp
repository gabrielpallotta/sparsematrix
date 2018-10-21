#ifndef MATRIXELEMENT_H
#define MATRIXELEMENT_H

#include <iostream>
#include "AvlTree.hpp"

using namespace std;

template <typename T>
class MatrixElement
{
  public:
    MatrixElement(int key)
    {
      this->key = key;
    }

    MatrixElement(int key, T info)
    {
      this->key = key;
      this->info = new T(info);
    }

    bool operator==(const MatrixElement& el) const
    {
      return this->key == el.key;
    }

    bool operator>(const MatrixElement& el) const
    {
      return this->key > el.key;
    }

    bool operator<(const MatrixElement& el) const
    {
      return this->key < el.key;
    }

    T* getInfo()
    {
      return this->info;
    }

    void setInfo(T info)
    {
      this->info = new T(info);
    }

  private:
    int key;
    T* info;
};

#endif
