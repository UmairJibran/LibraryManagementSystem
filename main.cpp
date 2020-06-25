#include <iostream>
using namespace std;

class Book{
  private:
    int bookID;
    string bookName;
    string bookAuthor;
    int borrowerID;
    int days;
    int edition;
  public:
    Book(){
      bookID = 0;
      borrowerID = 0;
      days = 0;
      edition = 0;
      bookName = "";
      bookAuthor = "";
    }
    void setBook(int bookID,string bookName,string bookAuthor, int borrowerID, int days, int edition){

    }
};

class Library{
  private:
    Book english;
  public:
    Library(){

    }
};

int main() {
}