#include <iostream>
#include <ctime>
#include <vector>
using namespace std;

class Book
{
public:
    int book_id{};
    string title;
    string author;
    string subject;
    string isbn;
    double price{};

    void addBookDetails()
    {
        cout << "Enter book id: ";
        cin >> book_id;

        cin.ignore();

        cout << "Enter book title: ";
        getline(cin, title);

        cout << "Enter author: ";
        getline(cin, author);

        cout << "Enter subject: ";
        getline(cin, subject);

        cout << "Enter ISBN number: ";
        cin >> isbn;

        cout << "Enter price: ";
        cin >> price;
    }

    void showBookDetails() const
    {
        cout << "\n----- Book Details -----\n";
        cout << "Book ID   : " << book_id << endl;
        cout << "Title     : " << title << endl;
        cout << "Author    : " << author << endl;
        cout << "Subject   : " << subject << endl;
        cout << "ISBN      : " << isbn << endl;
        cout << "Price     : " << price << endl;
        cout << "------------------------\n";
    }

    int getBookId() const
    {
        return book_id;
    }

    string getBookName() const
    {
        return title;
    }
};

class Copy
{
public:
    int copy_id{};
    int book_id{};
    int rack{};
    string status{"available"};

    Copy() = default;
};

class Member
{
public:
    int member_id{};
    string name;
    string email;
    string phone;
    bool paid_status{false};
    vector<int> assigned_copy_ids;

    Member() = default;

    Member(int member_id, string name, string email, string phone, bool paid_status)
        : member_id(member_id),
          name(name),
          email(email),
          phone(phone),
          paid_status(paid_status) {}

    void addMemberDetails()
    {
        cout << "Enter member id: ";
        cin >> member_id;

        cin.ignore();

        cout << "Enter member name: ";
        getline(cin, name);

        cout << "Enter member email: ";
        getline(cin, email);

        cout << "Enter member phone: ";
        getline(cin, phone);

        paid_status = false;
    }

    void displayMemberDetails() const
    {
        cout << "\n----- Member Details -----\n";
        cout << "Member ID   : " << member_id << endl;
        cout << "Name        : " << name << endl;
        cout << "Email       : " << email << endl;
        cout << "Phone       : " << phone << endl;
        cout << "Paid Status : " << (paid_status ? "Paid" : "Not Paid") << endl;

        if (assigned_copy_ids.empty())
        {
            cout << "No books assigned\n";
        }
        else
        {
            cout << "Assigned Copy IDs:\n";
            for (const auto &id : assigned_copy_ids)
            {
                cout << id << endl;
            }
        }

        cout << "--------------------------\n";
    }

    // Getters
    int getMemberId() const { return member_id; }
    string getMemberName() const { return name; }
    string getMemberEmail() const { return email; }
    string getMemberPhone() const { return phone; }
    bool getPaidStatus() const { return paid_status; }

    // Setter
    void changePaidStatus()
    {
        paid_status = !paid_status;
    }
};

class IssueRecord
{
public:
    int id;
    int copy_id;
    int member_id;
    time_t issue_date;
    time_t due_date;
    time_t return_date;
    double fine;
};

class Payment
{
public:
    int id;
    int member_id;
    double amount;
    string type;
};

class Library
{
public:
    vector<Book> books;
    vector<Copy> copies;
    vector<Member> members;
    vector<IssueRecord> issues;
    vector<Payment> payments;

    void issueBook();
    void returnBook();
    void makePayment();
};

void Library::issueBook()
{
    int memberid, bookid;
    cout << "Enter member id: ";
    cin >> memberid;

    cout << "Enter book id: ";
    cin >> bookid;

    int memberIndex = -1;

    for (int i = 0; i < members.size(); i++)
    {
        if (members[i].getMemberId() == memberid)
        {
            memberIndex = i;
            break;
        }
    }

    if (memberIndex == -1)
    {
        cout << "Member not found\n";
        return;
    }

    if (!members[memberIndex].paid_status)
    {
        cout << "Membership not paid\n";
        return;
    }

    for (int i = 0; i < copies.size(); i++)
    {
        if (copies[i].book_id == bookid && copies[i].status == "available")
        {
            copies[i].status = "issued";

            IssueRecord issue;
            issue.id = issues.size() + 1;
            issue.copy_id = copies[i].copy_id;
            issue.member_id = memberid;

            issue.issue_date = time(0);
            issue.due_date = issue.issue_date + (7 * 24 * 60 * 60);
            issue.return_date = 0;
            issue.fine = 0;

            issues.push_back(issue);

            members[memberIndex].assigned_copy_ids.push_back(copies[i].copy_id);

            cout << "Book issued successfully\n";
            return;
        }
    }

    cout << "No available copy\n";
}

void Library::returnBook()
{
    int copy_id;
    cout << "Enter copy id to return: ";
    cin >> copy_id;

    for (int i = 0; i < issues.size(); i++)
    {
        if (issues[i].copy_id == copy_id && issues[i].return_date == 0)
        {
            issues[i].return_date = time(0);

            int delay = (issues[i].return_date - issues[i].due_date) / (60 * 60 * 24);

            if (delay > 0)
            {
                issues[i].fine = delay * 5;
                cout << "Late return. Fine = ₹" << issues[i].fine << endl;
            }
            else
            {
                cout << "Returned on time. No fine.\n";
            }

            // update copy status
            for (int j = 0; j < copies.size(); j++)
            {
                if (copies[j].copy_id == copy_id)
                {
                    copies[j].status = "available";
                    break;
                }
            }

            cout << "Book returned successfully\n";
            return;
        }
    }

    cout << "No active issue found for this copy\n";
}

void Library::makePayment()
{
    int memberid;
    double amount;

    cout << "Enter member id: ";
    cin >> memberid;
    int memberIndex = -1;

    for (int i = 0; i < members.size(); i++)
    {
        if (members[i].getMemberId() == memberid)
        {
            memberIndex = i;
            break;
        }
    }

    if (memberIndex == -1)
    {
        cout << "Member not found\n";
        return;
    }

    cout << "Enter amount: ";
    cin >> amount;

    cout << "Payment type (membership/fine): ";
    string type;
    cin >> type;

    Payment p;
    p.id = payments.size() + 1;
    p.member_id = memberid;
    p.amount = amount;
    p.type = type;

    payments.push_back(p);

    // Update member status if membership payment
    if (type == "membership")
    {
        members[memberIndex].paid_status = true;
        cout << "Membership activated\n";
    }

    cout << "Payment recorded successfully\n";
}

int getAdminMenuChoice()
{
    int choice;

    cout << "\n========== Library Admin Menu ==========\n";
    cout << "1. Add Member\n";
    cout << "2. View Members\n";
    cout << "3. Add Book\n";
    cout << "4. Issue Book\n";
    cout << "5. Create Copies\n";
    cout << "6. View Copies (by Book)\n";
    cout << "7. Return Book\n";
    cout << "8. Record Payment\n";
    cout << "0. Exit\n";
    cout << "---------------------------------------\n";
    cout << "Enter your choice: ";

    cin >> choice;

    return choice;
}

void handleCreateCopies(vector<Book> &books, vector<Copy> &copies, int &global_copy_id)
{
    int book_id, total, rack;

    cout << "Enter book id: ";
    cin >> book_id;

    cout << "How many copies: ";
    cin >> total;

    cout << "Enter rack no: ";
    cin >> rack;

    if (total <= 0)
    {
        cout << "Invalid number of copies\n";
        return;
    }

    bool found = false;
    for (const auto &b : books)
    {
        if (b.getBookId() == book_id)
        {
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "Book not found\n";
        return;
    }

    for (int i = 0; i < total; i++)
    {
        Copy c;

        c.copy_id = ++global_copy_id;
        c.book_id = book_id;
        c.rack = rack;
        c.status = "available";

        copies.push_back(c);
    }
    cout << "Copies created successfully\n";
}

void displayCopiesByBook(vector<Copy> &copies, vector<Book> &books)
{
    int book_id;
    cout << "Enter book id: ";
    cin >> book_id;

    bool found = false;

    for (auto &b : books)
    {
        if (b.getBookId() == book_id)
        {
            cout << "\nBook: " << b.getBookName() << endl;
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "Book not found\n";
        return;
    }

    bool copyFound = false;

    cout << "\n----- Copies for Book ID: " << book_id << " -----\n";

    for (auto &c : copies)
    {
        if (c.book_id == book_id)
        {
            cout << "Copy ID: " << c.copy_id << endl;
            cout << "Rack: " << c.rack << endl;
            cout << "Status: " << c.status << endl;
            cout << "---------------------------\n";

            copyFound = true;
        }
    }

    if (!copyFound)
    {
        cout << "No copies found for this book\n";
    }
}

int main()
{
    int global_copy_id = 0;

    Library lib;

    int choice;
    while ((choice = getAdminMenuChoice()) != 0)
    {
        switch (choice)
        {

        case 1:
        {
            Member m;
            m.addMemberDetails();
            lib.members.push_back(m);
            break;
        }

        case 2:
        {
            if (!lib.members.empty())
            {
                for (int i = 0; i < lib.members.size(); i++)
                {
                    cout << "Member " << i + 1 << endl;
                    lib.members[i].displayMemberDetails();
                    cout << "---------------------------\n";
                }
            }
            else
            {
                cout << "No members currently!\n";
            }
            break;
        }

        case 3:
        {
            Book b;
            b.addBookDetails();
            lib.books.push_back(b);
            break;
        }

        case 4:
        {
            lib.issueBook();
            break;
        }

        case 5:
        {
            handleCreateCopies(lib.books, lib.copies, global_copy_id);
            break;
        }

        case 6:
        {
            displayCopiesByBook(lib.copies, lib.books);
            break;
        }

        case 7:
        {
            lib.returnBook();
            break;
        }

        case 8:
        {
            lib.makePayment();
            break;
        }

        default:
            cout << "Invalid choice\n";
        }
    }

    return 0;
}