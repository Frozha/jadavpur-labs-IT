#include"Array.h"
#include<iostream>
#include<cstring>

using std::string;

class Book{
  protected:
    string isbn, title;
    Array<string> authors;
    float price;

  public:
    bool isBook(string isbn)const{return isbn==this->isbn?true:false;}
   
    Book(string isbn, string title, Array<string> &authors, float price):isbn(isbn), title(title),authors(authors),price(price){}
    
    string ISBN()const{return isbn;}

};

class BookStore{
  Array<Book> booklist;
  Array<int> bookcount;
  public:
    void addbook(Book &bookobj){
      int i;
      int len = booklist.length();
      for(i=0;i<len;i++){
        if(booklist[i].isBook(bookobj.ISBN()))break;
      }
      if(i==len){
        booklist.push_back(bookobj);
        bookcount.push_back(1);
      }
      else{
        bookcount[i]++;
      }
    }
    void books(){
      std::cout<<"ISBN\t\tQty";
      int len = booklist.length();
      for(int i =0;i<len;i++){
        std::cout<<booklist[i].ISBN()<<" "<<bookcount[i];
      }
    }
};

int main(){
  Array<string> authors(2);
  authors.push_back("auth1");
  authors.push_back("auth2");
  string isbn="1011";
  string title = "title 1";
  Book b1(isbn,title,authors,(float)50);
  Book b2(isbn,title ,authors,(float)50);
  isbn = "1012";
  title = "title 2";
  Book b3(isbn,title,authors,(float)150);
  BookStore store;
  store.addbook(b1);
  store.addbook(b2);
  store.addbook(b3);
  store.books();

}


