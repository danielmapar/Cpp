#include <iostream>

using std::cout;
using std::endl;

int recursiveFactorial(int n);

int recursiveFactorial(int n) {
  if (n == 0) return 1;
  else return n * recursiveFactorial(n - 1);
}

int main(void) {
  cout << recursiveFactorial(10) << endl;
  return 0;
}
