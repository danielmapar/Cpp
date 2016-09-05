#include <iostream>

using std::cout;
using std::endl;
using std::string;

class MathException {
public:
  MathException(const string& err);
  string getError() { return errMsg; }
private:
  string errMsg;
};

MathException::MathException(const string& err) : errMsg(err) {};

class ZeroDivide : public MathException {
public:
  ZeroDivide(const string& err) : MathException(err) {}
};

class NegativeRoot : public MathException {
public:
  NegativeRoot(const string& err) : MathException(err) {}
};

void calculator() throw(ZeroDivide, MathException) {
  
}

int main(void) {

  int divide = 1;

  try {
    if (divide == 0) {
      throw ZeroDivide("divise by zero");
    } else {
      throw NegativeRoot("negative value");
    }
  } catch(ZeroDivide& zde) {
    cout << zde.getError() << endl;
  } catch(MathException& mte) {
    cout << mte.getError() << endl;
  }

  return 0;
}
