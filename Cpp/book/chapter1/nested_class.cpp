//
//  nested_class.cpp
//
//
//  Created by Daniel Marchena on 2015-09-22.
//
//

#include <iostream>

using std::string;
using std::cout;
using std::endl;

class Book {
    public:
        class Bookmark {
            public:
                string getPosition() const { return position; }
                Bookmark(string _position) : position(_position) {};
                Bookmark() {};
            private:
                string position;
        };
        // Initializer Lists only works for constructors
        Book(string _name, string _bookmarkNumber) : name(_name), bookmark(_bookmarkNumber) {
          //cout << "TESTE" << endl;
        }
        /*Book(string _name, string _bookmarkNumber) {
          name = _name;
          bookmark = Bookmark(_bookmarkNumber);
        }*/
        string getName() const { return name; }
        string getBookmark() const { return bookmark.getPosition(); }
    private:
      string name;
      Bookmark bookmark;
};

int main(void) {

    Book book1("Livro", "DOIS");

    Book book = Book("Livro", "DOIS");

    cout << book.getName() <<  "--" << book.getBookmark() << endl;

    return 0;
}
