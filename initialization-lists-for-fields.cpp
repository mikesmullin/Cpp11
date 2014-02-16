#include <string>
#include <iostream>

class Qux {
public:
  Qux()
  : _foo("initialize foo to this!")
  {
  }
  // This is nearly equivalent to
  // Qux() { _foo = "initialize foo to this!"; }
  // but without the extra call to construct an empty string
  std::string getFoo(void) {
    return _foo;
  }
private:
  std::string _foo;
};

class Baz {
public:
  Baz() : _foo( "initialize foo first" ), _bar( " then bar" ) {}
private:
  std::string _foo;
  std::string _bar;
};

class Mike {
public:
  Mike(int d)
  // these are supposed to be in same order
  // as declared, but they don't have to be to compile
  // so i guess that's a readability thing?
  : b{2}, c{3}, a(4)
  // also, you can use {} or () for assignment but not =
  // and here () is more portable in case the variable is
  // later changed between a class and a primitive
  {
    std::cout << "\na " << a
              << " b " << b
              << " c " << c
              << " d " << d
              << std::endl;
  }
  int b;
private:
  int a;
  int c;
};

int main() {
  Qux q;
  std::cout << q.getFoo();
  Baz b;
  Mike m(1);
}
