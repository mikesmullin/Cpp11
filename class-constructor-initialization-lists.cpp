#include <iostream>

class Foo {
public:
  Foo(int x) {
    std::cout << "Foo's constructor "
              << "called with "
              << x
              << std::endl;
  }
};

class Bar : public Foo {
public:
  Bar() : Foo( 10 ) // construct the Foo part of Bar
  {
    std::cout << "Bar's constructor" << std::endl;
  }
};

int main() {
  Bar stool;
}
