#include <iostream>

using std::string;
using std::cout;
using std::endl;

template <typename T>
class BasicVector {
public:
  BasicVector(int capac = 10);
  T& operator[](int i);
  virtual ~BasicVector();
private:
  T* a;
  int capacity;
};

template <typename T>
BasicVector<T>::~BasicVector() {
  cout << "Clear memory" << endl;
  delete [] a;
}

template <typename T>
BasicVector<T>::BasicVector(int capac) {
  capacity = capac;
  a = new T[capacity];
}

template <typename T>
T& BasicVector<T>::operator[](int i) {
  return a[i];
}

int main(void) {

  BasicVector<int> obj = BasicVector<int>(12);
  BasicVector<double> obj2(14);

  // Create an array of BasicVector of time double

  BasicVector<BasicVector<double> > matrix(20);

  BasicVector<double>* ptr = new BasicVector<double>[10];
  ptr[0][1] = 10;

  cout << "ptr " << ptr[0][1] << endl;

  matrix[0][9] = 10;
  matrix[0][1] = 20;

  cout << "Class templates" << endl;
  obj2[0] = 10.10;
  obj[0] = 10;
  cout << obj[0] << " -- " << obj2[0] << endl;
  cout << matrix[0][1] << " -- " << matrix[0][9] << endl;

  return 0;
}
