#include <iostream>

struct Vector {
  int sz; // number of elements
  double* elem; // pointer to elements
};

void f(Vector v, Vector& rv, Vector* pv) {
  int i1 = v.sz; // access through name
  int i2 = rv.sz; // access through reference
  int i4 = pv->sz; //access through pointer
}

int main() {
  Vector v;
  f(v, v, &v);
}
