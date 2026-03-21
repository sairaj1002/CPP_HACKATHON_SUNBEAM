#include<iostream> 
using namespace std; 
class Book
{
    private: 
    int bookId;
    string title; 
    double price; 
    public: 

    int getBookId( void ){
        return bookId;
    }
    string getBookTitle( void ){
        return title;
    }
    double getBookPrice( void ){
        return price;
    }

    void setEmployeeName( void ){
        cout<<" Enter Book Title : ";
        cin>>title;
    }
    void setEmployeeId( void ){
        cout<<" Enter employeeID : ";
        cin>>;
    }
    virtual void acceptRecord( void )
    {
        cout<<"Title : "; 
        cin>>title; 
        cout<<"Price : "; 
        cin>>price; 
    }
    virtual void printRecord( void )
    {
        cout<<"Title : "<<title<<endl; 
        cout<<"Price :" <<price<<endl; 
    }
}; 
class Member : public Book
{
    private: 
    int pageCount;
    public: 
    Book( void ) : pageCount(0)
    {   }
    virtual void acceptRecord( void )
    {
        Product::acceptRecord( ); 
        cout<<"PageCount : "; 
        cin>>pageCount; 
    } 
    virtual void printRecord( void )
    {
        Product::printRecord( ); 
        cout<<"PageCount : "<<pageCount<<endl; 

    }
}; 
class Tape : public Product
{
    private: 
    int playTime; 
    public: 
    Tape( void ) : playTime(0) 
    {   }
    virtual void acceptRecord( void )
    {
        Product::acceptRecord( ); 
        cout<<"PlayTime : "; 
        cin>>playTime;  
    }
    virtual void printRecord( void )
    {
        Product::printRecord( ); 
        cout<<"PlayTime : "<<playTime<<endl; 
    }
}; 
int menuList( void )
{
    int choice; 
    cout<<"0.Exit"<<endl; 
    cout<<"1.Book"<<endl; 
    cout<<"2.Tape"<<endl;
    cout<<"Enter the choice : "; 
    cin>>choice; 
    return choice;  
}

int main()
{
    int choice; 
    while((choice = ::menuList())!=0)
    {
        Product *ptr = NULL; 
        switch (choice)
        {
        case 1: 
            ptr = new Book( ); 
            break;
        case 2: 
            ptr = new Tape( ); 
            break; 
        }
        if(ptr!=NULL)
        {
            ptr->acceptRecord( ); 
            ptr->printRecord( ); 
        }
        delete ptr; 
    }
    return 0;
}
