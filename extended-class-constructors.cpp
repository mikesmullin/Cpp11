#include <iostream>

class Foo {
public:
  Foo() { std::cout << "Foo's constructor" << std::endl; }
};

class Bar : public Foo {
public:
  Bar() { std::cout << "Bar's constructor" << std::endl; }
};

int main() {
  // a lovely elephant ;)
  Bar bar;
}
