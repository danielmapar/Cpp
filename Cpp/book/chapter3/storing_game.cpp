#include "storing_game.hpp"

using std::cout;
using std::endl;

string GameEntry::getName() const {return name;}
int GameEntry::getScore() const {return score;}

Scores::Scores(int maxEnt) {
  maxEntries = maxEnt;
  entries = new GameEntry[maxEntries];
  numEntries = 0;
}

Scores::~Scores() {
  delete [] entries;
}

void Scores::add(const GameEntry& e) {
  int newScore = e.getScore();
  if(numEntries == maxEntries) {
    if(newScore <= entries[maxEntries-1].getScore()) {
      return;
    }
  }
  else numEntries++;

  int i = numEntries - 2;
  while(i >= 0 && newScore > entries[i].getScore()) {
    entries[i+1] = entries[i];
    i--;
  }
  entries[i + 1] = e;
}

GameEntry Scores::remove(int i) throw(IndexOutOfBounds) {
  if((i < 0) || (i >= numEntries)){
    throw IndexOutOfBounds("Invalid index");
  }
  GameEntry e = entries[i];
  for (int j = i+1; j < numEntries; j++) {
    entries[j - 1] = entries[j];
  }
  numEntries--;
  return e;
}

void printMemory(Scores& scores) {
  for (int i = 0; i < scores.maxEntries; i++) {
    cout << i << ": " << scores.entries[i].getName() << " " << scores.entries[i].getScore() << endl;
  }
}

void Scores::print() {
  for(int i = 0; i < numEntries; i++) {
    cout << entries[i].getName() << ' ' << entries[i].getScore() << endl;
  }
}

void Scores::sort() {
  GameEntry* tempEntries = new GameEntry[maxEntries];
  for(int i = 0; i < numEntries; i++) {
    tempEntries[i] = entries[i];
  }

  for(int i = 1; i < numEntries; i++) {
    GameEntry cur = tempEntries[i];
    int j = i - 1;
    while((j >= 0) && (tempEntries[j].getScore() > cur.getScore())) {
      tempEntries[j + 1] = tempEntries[j];
      j--;
    }
    tempEntries[j + 1] = cur;
  }
  for(int i = 0; i < numEntries; i++) {
    cout << tempEntries[i].getName() << ' ' << tempEntries[i].getScore() << endl;
  }
}

int main(void) {

  Scores scores(10);
  GameEntry ge1("Daniel", 40);
  GameEntry ge2("Pedro", 30);
  GameEntry ge3("John", 50);
  GameEntry ge4("Rodrigo", 90);

  cout << "--->Start adding" << endl;

  scores.add(ge1);
  scores.add(ge2);
  scores.add(ge3);
  scores.add(ge4);
  scores.add(GameEntry("Yuri", 9000));

  scores.print();

  cout << "--->Start removing" << endl;

  scores.remove(2);
  scores.print();

  // Remove invalid index
  try {
    scores.remove(10);
  } catch(IndexOutOfBounds e) {
    cout << e.getMessage() << endl;
  }

  // Print raw memory
  printMemory(scores);

  cout << "Start insertion sort!" << endl;
  scores.sort();

  return 0;
}
