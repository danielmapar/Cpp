#include <iostream>

using std::string;

class IndexOutOfBounds {
private:
  string erroMsg;
public:
  IndexOutOfBounds(const string& err) : erroMsg(err) {};
  string getMessage() const { return erroMsg; }
};

class GameEntry {
public:
  GameEntry(const string& n="", int s=0) : name(n), score(s)
  { }
  string getName() const;
  int getScore() const;
private:
  string name;
  int score;
};


class Scores {
public:
  Scores(int maxEnt = 10);
  ~Scores();
  void print();
  void add(const GameEntry& e);
  void sort();
  GameEntry remove(int i) throw(IndexOutOfBounds);
  friend void printMemory(Scores& scores);
private:
  int maxEntries;
  int numEntries;
  GameEntry* entries;
};
