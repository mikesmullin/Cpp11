#include "Vector.h"
#include <stdexcept>
#include <iostream>
using namespace std;

Vector::Vector(int s)
{
  if (s<0) throw length_error{"Vector::Vector(int s)"};
  elem = new double[s];
  sz = s;
}

double& Vector::operator[](int i)
{
  if (i<0 || size()<=i) throw out_of_range{"Vector::operator[]"};
  return elem[i];
}

int Vector::size()
{
  return sz;
}

void f(Vector& v)
{
  //...
  try { // exceptions here are handled by the handler defined below
    v[v.size()] = 7; // try to access beyond the end of v
  }
  catch (out_of_range) { // oops: out_of_range error
    // ... handle range error ...
    std::cerr << "range error caught!" << endl;
  }
  // ...
}

void test()
{
  try {
    Vector v(-27);
  }
  catch (const std::length_error& e) {
    cerr << "Length error: " << e.what() << endl;
    // handle negative size
  }
  catch (std::bad_alloc) {
    cerr << "caught bad_alloc" << endl;
    // handle memory exhaustion
  }
}

int main() {
  Vector v(3);
  f(v);
  test();
}
