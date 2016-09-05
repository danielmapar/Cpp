#include <iostream>

class TestDad {
  public:
    int dad;
    TestDad(int dad);
    ~TestDad();
};

TestDad::TestDad(int dad) {
  this->dad = dad;
  std::cout << "Counstruct TestDad" << std::endl;
}

TestDad::~TestDad() {
  std::cout << "Destroy TestDad" << std::endl;
}

class TestChild : public TestDad {
  // default encapsulation is private
public:
  int a;
  TestChild(int dad);
  // Classes are destroyed in the reverse order from their construction,
  // with derived classes destroyed before base classes

  // If we were to destroy our student object, the Student
  // destructor would be called first, followed by the Person
  // destructor. Unlike constructors, the Student destructor
  // does not need to (and is not allowed to) call the Person
  // destructor. This happens automatically.
  ~TestChild();
  void functionOne(int a);
};

void TestChild::functionOne(int a) {
  std::cout << a << std::endl;
}

TestChild::~TestChild() {
  std::cout << "Destroy Test" << std::endl;
}

TestChild::TestChild(int dad) : TestDad(dad){
  std::cout << "Construct Test" << std::endl;
}

class A
{
public:
    int x;
    A(int _x, int _y, int _z) : x(_x), y(_y), z(_z) {}
protected:
    int y;
private:
    int z;
};

class B : public A
{
    // x is public
    // y is protected
    // z is not accessible from B
  public:
    B() : A(10, 20, 30) { }
    int getY() const { return y; }
};

class C : protected A
{

    // x is protected
    // y is protected
    // z is not accessible from C
};

class D : private A    // 'private' is default for classes
{
    // x is private
    // y is private
    // z is not accessible from D
};

int main(void) {
  B b; // B b = B();
  std::cout << b.getY() << std::endl;
  TestChild test(10);
  test.functionOne(10);
  return 0;
}
