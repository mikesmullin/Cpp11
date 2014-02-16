#include <iostream>

class Vector {
public:
  Vector (int s) :elem{new double[s]}, sz{s} { } // construct a Vector
  double& operator[](int i) { return elem[i]; } // element access: subscripting
  int size() { return sz; }
private:
  double* elem; // pointer to the elements
  int sz; // the number of elements
};

double read_and_sum(int s) {
  Vector v(s); // make a vector of s elements
  for (int i=0; i!=v.size(); ++i)
    std::cin >> v[i]; // read into elements
  double sum = 0;
  for (int i=0; i!=v.size(); ++i)
    sum+=v[i]; // take the sum of the elements
  return sum;
}

int main() {
  std::cout << read_and_sum(3);
}
