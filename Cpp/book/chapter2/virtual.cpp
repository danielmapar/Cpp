#include <iostream>

class FatherClass {
public:
  FatherClass() { data = 10; }
  virtual void printData() const { std::cout << "FatherClass - " << data << std::endl; }
private:
  int data;
};

class SonClass : public FatherClass {
public:
  SonClass() : FatherClass() { data = 20; }
  void printData() const { std::cout << "SonClass - " << data << std::endl; }
private:
  int data;
};

class GrandSonClass : public SonClass{
public:
  GrandSonClass() : SonClass() { data = 30; }
  void printData() const { std::cout << "GrandSonClass - " << data << std::endl; }
private:
  int data;
};

int main() {
  FatherClass *objs[3];

  objs[0] = new FatherClass();
  objs[1] = new SonClass();
  objs[2] = new GrandSonClass();

  objs[0]->printData();
  objs[1]->printData();
  objs[2]->printData();

  return 0;
}
