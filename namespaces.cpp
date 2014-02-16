#include <iostream>

using namespace std;

namespace My_code {
  class complex {
  public:
    complex(int, int);
    int real();
    int imag();
  };
  complex sqrt(complex);
  // ...
  int main();
}

int My_code::main()
{
  complex z {1,2};
  auto z2 = sqrt(z);
  cout << '{' << z2.real() << ',' << z2.imag() << "}\n";
}

My_code::complex::complex(int a, int b) {}
int My_code::complex::real() { return 0; }
int My_code::complex::imag() { return 1; }
My_code::complex My_code::sqrt(My_code::complex c) { return c; }

int main()
{
  return My_code::main();
}
