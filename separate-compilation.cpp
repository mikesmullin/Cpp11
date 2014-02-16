// user.cpp

#include "Vector.h" // get Vector's interface
#include <cmath> // get the standard-library math function interface including sqrt()
#include <iostream>
using namespace std; // make std members visible (S2.4.2)

double sqrt_sum(Vector& v) {
  double sum = 0;
  for (int i=0; i!=v.size(); ++i)
    sum+=sqrt(v[i]); // sum of square roots
  return sum;
}

int main() {
  std::cout << "Yo yo yo!";
}
