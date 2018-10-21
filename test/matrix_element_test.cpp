#include "matrix_element.hpp"
#include "gtest/gtest.h"

TEST(MatrixElement, ComparisonWorks) {
  MatrixElement<int> a = MatrixElement<int>(1, 5);
  MatrixElement<int> b = MatrixElement<int>(2, 4);
  MatrixElement<int> c = MatrixElement<int>(3, 3);
  MatrixElement<int> d = MatrixElement<int>(1, 2);
  ASSERT_EQ(a, d);
  ASSERT_LT(a, b);
  ASSERT_LT(b, c);
  ASSERT_GT(c, a);
  ASSERT_GT(b, a);
}

TEST(MatrixElement, SetInfoWorks) {
  MatrixElement<int> a = MatrixElement<int>(1, 5);
  a.setInfo(30);
  ASSERT_EQ(30, *a.getInfo());
}