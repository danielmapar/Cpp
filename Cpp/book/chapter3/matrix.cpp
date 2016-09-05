#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main(void) {

  const int LINE = 10;
  const int COLUMN = 10;

  int** M = new int*[10];
  for (int i = 0; i < LINE; i++) {
    M[i] = new int[COLUMN];
  }

  for (int i = 0; i < LINE; i++) {
    delete[] M[i];
  }
  delete[] M;

  vector<vector<int> > J(LINE, vector<int>(COLUMN));
  cout << J[0][0] << endl;

}
