#include <iostream>
#include <initializer_list>
#include <algorithm>
#include <stdexcept>

class Container {
public:
  virtual double& operator[](int) = 0; // pure virtual function
  virtual long unsigned int size() const = 0; // const member function (S3.2.1.1)
  virtual ~Container() {} // destructor (S3.2.1.2)
};

class Vector {
  double* elem;
  long unsigned int sz;
public:
  Vector(std::initializer_list<double> lst)
    : elem { new double[lst.size()] }, sz { lst.size() }
  {
    std::copy(lst.begin(), lst.end(), elem); // copy from lst into elem
  }
  double& operator[](int i) { return elem[i]; }
  long unsigned int size() const { return sz; }
};

class Vector_container : public Container { // Vector_container implements Container
  Vector v;
public:
  Vector_container(std::initializer_list<double> lst) : v(lst) { } // Vector of s elements
  ~Vector_container() {}
  double& operator[](int i) { return v[i]; }
  long unsigned int size() const { return v.size(); }
};

void use(Container& c) {
  const int sz = c.size();
  for (int i=0; i!=sz; ++i)
    std::cout << c[i] << '\n';
}

void g()
{
  Vector_container vc {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
  use(vc);
}

#include <list>

class List_container : public Container { // List_container implements Container
  std::list<double> ld; // (standard-library) list of doubles (S4.4.2)
public:
  List_container() { } // empty List
  List_container(std::initializer_list<double> il) : ld{il} { }
  ~List_container() {}
  double& operator[](int i);
  long unsigned int size() const { return ld.size(); }
};

double& List_container::operator[](int i)
{
  for (auto& x : ld) {
    if (i==0) return x;
    --i;
  }
  throw std::out_of_range("List container");
}

void h()
{
  List_container lc = { 1,2,3,4,5,6,7,8,0 };
  use(lc);
}

int main() {
  g();
  h();
}
