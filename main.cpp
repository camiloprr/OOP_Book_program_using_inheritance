#include <iostream>
#include <string>

using namespace std;

class Book {
  private:
  string title;
  string author;
  public:
  Book (string t, string a) : title(t), author(a) {}

  void display () {
      cout << "Title: " << title << ", " << "Author: " << author << ", ";
  }
};
class PrintedBook: public Book {
    protected:
    int numPages;
    public:
    PrintedBook (string t, string a, int p) : Book(t, a), numPages(p) {}

    void display () {
        Book::display();
        cout << "Pages: " << numPages;
    }
};
class EBook: public PrintedBook {
    protected:
    float size;
    public:
    EBook (string t, string a, int p, float s) : PrintedBook(t, a, p), size(s) {}
    void display () {
        PrintedBook::display();
        cout << "Size: " << size << "MB";
    }
};

int main()
{
    cout << "Printed Book Details: " << endl;
    PrintedBook b1 = PrintedBook("Software Engineering", "Dr. Connors", 250);
    b1.display();
    cout << endl;
    cout << "E-Book Details: " << endl;
    EBook e1 = EBook("Python testing", "Dr. Doom", 200, 2.5);
    e1.display();

    return 0;
}
