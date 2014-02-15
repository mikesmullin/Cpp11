typedef int T;
typedef int A;

int main() {
  const int n = 1;
  T x = 1; // T: T called x
  T a[n]; // T[n]: array of n Ts called a (S7.3)
  T* p; // T*: pointer to T called p (S7.2)
  T& r = x; // T&: reference to T called r (S7.7)
  T f(A); // T(A): function taking an argument of type A returning a result of type T (S2.2.1)
}
