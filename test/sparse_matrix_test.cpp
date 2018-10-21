#include <iostream>
#include "sparse_matrix.hpp"
#include "gtest/gtest.h"

TEST(SparseMatrixTest, Get) {
  SparseMatrix<int>* matrix = new SparseMatrix<int>(0);
  ASSERT_THROW(matrix->get(-1, -1), std::invalid_argument);
}

TEST(SparseMatrixTest, DefaultValue) {
  SparseMatrix<int>* matrix = new SparseMatrix<int>(10);
  ASSERT_EQ(10, matrix->get(0, 0));
  matrix = new SparseMatrix<float>(0.61f);
  ASSERT_EQ(0.61f, matrix->get(0, 0));
}

TEST(SparseMatrixTest, Put) {
  SparseMatrix<int>* matrix = new SparseMatrix<int>(0);
  matrix->put(0, 1, 1);
  ASSERT_EQ(1, matrix->get(0, 1);
  matrix->put(0, 2, 2);
  ASSERT_EQ(2, matrix->get(0, 2);
  matrix->put(0, 3, 3);
  ASSERT_EQ(3, matrix->get(0, 3);
  matrix->put(0, 4, 4);
  ASSERT_EQ(4, matrix->get(0, 4);
  matrix->put(4, 4, 5);
  ASSERT_EQ(5, matrix->get(4, 4);
  matrix->put(3, 4, 6);
  ASSERT_EQ(6, matrix->get(3, 4);
  matrix->put(2, 4, 7);
  ASSERT_EQ(7, matrix->get(2, 4);
  matrix->put(1, 4, 8);
  ASSERT_EQ(8, matrix->get(1, 4);
  matrix->put(4, 4, 9);
  ASSERT_EQ(9, matrix->get(4, 4);
  matrix->put(4, 4, 10);
  ASSERT_EQ(10, matrix->get(4, 4);
  matrix->put(3, 4, 11);
  ASSERT_EQ(11, matrix->get(3, 4);
  matrix->put(24, 4445, 12);
  ASSERT_EQ(12, matrix->get(24, 4445);
  matrix->put(24, 4445, 13);
  ASSERT_EQ(13, matrix->get(24, 4445);
  matrix->put(0, 0, 14);
  ASSERT_EQ(14, matrix->get(0, 0);
  matrix->put(8, 8, 15);
  ASSERT_EQ(15, matrix->get(8, 8);

  ASSERT_THROW(matrix->put(20, -1, -1), std::invalid_argument);
}