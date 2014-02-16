#include <initializer_list>
#include <algorithm>

class Vector {
public:
  Vector(std::initializer_list<double> lst) // initialize with a list
    :elem{new double[lst.size()]}, sz{lst.size()}
  {
    std::copy(lst.begin(), lst.end(), elem); // copy from lst into elem
  }
private:
  double* elem;
  long unsigned int sz;
};


int main() {
  Vector v1 = {1,2,3,4,5}; // v1 has 5 elements
  Vector v2 = {1.23, 3.45, 6.7, 8}; // v2 has 4 elements
}
