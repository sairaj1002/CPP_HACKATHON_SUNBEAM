#include<iostream> 
#include<vector>
sairaj
using namespace std; 
int PASSWORD = 00;

class Book
{
    private: 
        int bookId;
        string author;
        string subject;
        string isbn;
        string title; 
        double price; 
        vector<Book *>Book_list;

    public: 
        Book(int bookId , string author ,string subject,string isbn, string title ,double price )
        {   }
        int getBookId( void ){ return bookId; }
        string getBookauthor( void ){ return author; }
        string getBooksubject( void ){ return subject; }
        string getBookisbn( void ){ return isbn; }
        string getBookTitle( void ){ return title; }
        double getBookPrice( void ){ return price;  }
       
        void setBookId( void ){
            cout<<" Enter Book ID : ";
            cin>>bookId;
        }
        void setBookAuthor( void ){
            cout<<" Enter Book Author : ";
            cin>>author;
        }
        void setBooksubject( void ){
            cout<<" Enter Book Subject : ";
            cin>>subject;
        }
        void setBookisbn( void ){
            cout<<" Enter Book Isbn : ";
            cin>>isbn;
        }
        void setBookTitle( void ){
            cout<<" Enter Book Title : ";
            cin>>title;
        }
        void setBookprice( void ){
            cout<<" Enter Book Price : ";
            cin>>price;
        }


        void acceptBook( void )
        {
                cout<<" Enter Book ID : ";
                cin>>bookId;
                cout<<" Enter Book Author : ";
                cin>>author;
                cout<<" Enter Book Subject : ";
                cin>>subject;
                cout<<" Enter Book Isbn : ";
                cin>>isbn;
                cout<<" Enter Book Title : ";
                cin>>title;
                cout<<" Enter Book Price : ";
                cin>>price;
        }
        void displayBook( void )
        {
            cout<<"Book ID : "<<bookId<<endl;
            cout<<"Author : "<<author<<endl;
            cout<<"Subject : "<<subject<<endl;
            cout<<"Isbn : "<<isbn<<endl;
            cout<<"Title : "<<title<<endl;
            cout<<"Price : "<<price<<endl;
            cout<<"________________________________________"<<endl;
        }

        void addBooks(Book *book)
        {
            Book_list.push_back(book);
        }

    ~Book(){
        cout<<"Book Distructor called"<<endl;
    }
}; 

// class Member {
//     private : 
//     vector<Book*> Book_taken;

//     public : 
//     void getBookTaken(){};
//     void addCourse(Book *book)
//     {
//         Book_taken.push_back(book);
//     }
//     vector<Book*> &getBookTaken()
//     {
//         return Book_taken;
//     }

// };


class Copy : public Book 
{
    private:
        int copyId;
        string rack;
        string status;

    public:
        Copy( );
        int getBookcopies( void ){ return copyId;  }
        string getBookRack( void ){ return rack; }
        string getBookStatus( void ){ return status; }
        void setBookCopyId( void ){
            cout<<" Enter Book Copy Id : ";
            cin>>copyId;
        }
        void setBookRack( void ){
            cout<<" Enter Book Rack : ";
            cin>>rack;
        }
        void setBookStatus( void ){
            cout<<" Enter Book Status : ";
            cin>>status;
        }
        void acceptRecord( void )
        {
                cout<<" Enter Book copyId : ";
                cin>>copyId;
                cout<<" Enter Book rack : ";
                cin>>rack;
                cout<<" Enter Book status : ";
                cin>>status;
        }
        void printRecord( void )
        {
            cout<<"Copy Id : "<<copyId<<endl;
            cout<<"Rack : "<<rack<<endl;
            cout<<"Status : "<<status<<endl;
        }
        ~Copy();
};


void addDummyBooks(vector<Book *> &Book_list)
{
    Book_list.push_back(new Book(1, "C++", 5000));
    Book_list.push_back(new Book(2, "Java", 7000));
    Book_list.push_back(new Book(3, "Python", 7000));
    Book_list.push_back(new Book(4, "DSA", 6000));
}

// void addDummyMembers(vector<Member *> &member_list)
// {
//     member_list.push_back(new Member(1, "Anil"));
//     member_list.push_back(new Member(2, "Nilesh"));
//     member_list.push_back(new Member(3, "Aditya"));
//     member_list.push_back(new Member(4, "Rahul"));
//     member_list.push_back(new Member(5, "Amar"));
//     member_list.push_back(new Member(6, "Pratik"));
// }


// void displayAllCourses(vector<Book *> &Book_list)
// {
//     for (int i = 0; i < Book_list.size(); i++)
//     {
//         Book_list[i]->displayBook();
//     }
// }


void IssueCopy(vector<Copy*> &Copy_list, vector<Member *> &Member_list)
{
    bool found = false; 
    int Member_id; 
    cout<<"Enter the Member Id :"; 
    cin>>Member_id; 
    for(int i = 0 ; i < Member_list.size( ) ; i++)
    {
        if(Member_id == Member_list[i]->getmemberId( ))
        {
            found = true; 
            displayAllBooks(Book_list);
            int copy_id; 
            cout<<"Enter the Copy Id: "; 
            cin>>copy_id; 
            for(int j = 0 ; j < copy_list.size( ) ; j++)
            {
                if(copy_id == copy_list[j]->getCopyId( ))
                {
                    Member_list[i]->addBook(book_list[j]);
                    break;  
                }
            } 
            break;  
        }
    }
    if(!found)
      cout<<"Member not found"<<endl; 
}

int menuList( void )
{
    int choice; 
    cout<<"0.Exit"<<endl; 
    cout<<"1.Book Menu"<<endl; 
    cout<<"2.Member "<<endl;
    cout<<"3.Issue Menu "<<endl;
    cout<<"4.Return Menu "<<endl;
    cout<<"5.Payment "<<endl;
    cout<<"6.Reports "<<endl;
    cout<<"Enter the choice : "; 
    cin>>choice; 
    return choice;  
}



int main()
{   
    int password;
    cout<<"LIBRARIAN LOGIN "<<endl ; 
    cout<<"ENTER THE PASSWORD "; 
    cin>>password;
    if( ::PASSWORD == password ){
        cout<<"____________________________WELCOME____________________"<<endl; 
        cout<<"ENTER THE PASSWORD ";
        cout<<endl;
        int choice;

        while ((choice = ::menuList()) != 0)
            switch (choice)
            {
            case 1:
                cout << " Book Menu " << endl;
                int num2;
                cin>>num2;
                switch (num2) {
                    cout << " 1.Add book" << endl;
                    cout << " 2.Edit book" << endl;
                    case 1:
                        cout << " Add book succesfully" << endl;

                        break;
                    case 2:
                        cout << " Edit book succesfully" << endl;
                        break;
                }
                break;
            case 2:
                cout<<"Member  "<<endl;
                break;
            case 3:
                cout<<"Issue Member "<<endl;
                break;
            case 4:
                cout<<"Return book "<<endl;
                break;
            case 5:
                cout<<" payment "<<endl;
                break;
            case 6: 
                break;
            case 7: 
            default:
                break;
            }
        }
    else{
        cout<<"Password is INCORRECT ";
    }
}
