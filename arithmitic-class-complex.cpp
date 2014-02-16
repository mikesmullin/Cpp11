#include <iostream> // std::cout
#include <complex>  // std::complex, std::imag

using namespace std;

int main() {
  complex<double> z1 (1.0, 3.0);
  complex<double> z2 (1.0, 4.0);

  printf("Working with complex numbers:\n\v");

  printf("Starting values: Z1 = %.2f + %.2fi\tZ2 = %.2f %+.2fi\n", z1.real(), z1.imag(), z2.real(), z2.imag());

  complex<double> sum = z1 + z2;
  printf("The sum: Z1 + Z2 = %.2f %+.2fi\n", real(sum), imag(sum));

  complex<double> difference = z1 - z2;
  printf("The difference: Z1 - Z2 = %.2f %+.2fi\n", real(difference), imag(difference));

  complex<double> product = z1 * z2;
  printf("The product: Z1 x Z2 = %.2f %+.2fi\n", real(product), imag(product));

  complex<double> quotient = z1 / z2;
  printf("The quotient: Z1 / Z2 = %.2f %+.2fi\n", real(quotient), imag(quotient));

  complex<double> conjugate = conj(z1);
  printf("The conjugate of Z1 = %.2f %+.2fi\n", real(conjugate), imag(conjugate));

  return 0;
}
