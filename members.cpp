#include <iostream>
#include <ctime>
#include <vector>
#include <fstream>
using namespace std;

class Member
{
private:
    int member_id;
    string name;
    string email;
    string phone;
    time_t nextpayment_duedate;
    bool paid_status;

public:
    Member(void) {}

    Member(int member_id, string name, string email, string phone, time_t nextpayment_duedate, bool paid_status) : member_id(), name(""), email(""), phone(""), paid_status(false) {}

    void addMemberDetails()
    {
        cout << "Enter member id: ";
        cin >> member_id;
        cout << "Enter member name: ";
        cin >> name;
        cout << "Enter member email: ";
        cin >> email;
        cout << "Enter member phone: ";
        cin >> phone;
    }

    void displayMemberDetails()
    {
        cout << "Member id: " << member_id << endl;
        cout << "Member name: " << name << endl;
        cout << "Email: " << email << endl;
        cout << "Phone no.: " << phone << endl;
        cout << "Paid status: " << paid_status << endl;
    }

    // Getters
    int getMemberId()
    {
        return this->member_id;
    }

    string getMemberName()
    {
        return this->name;
    }

    string getMemberEmail()
    {
        return this->email;
    }

    string getMemberPhone()
    {
        return this->phone;
    }

    bool getPaidStatus()
    {
        return this->paid_status;
    }

    // Setters
    void changePaidStatus()
    {
        if (this->paid_status != true)
        {
            this->paid_status = true;
        }
        else
        {
            this->paid_status = false;
        }
    }
};

int memberMenuList()
{
    int choice;
    cout << "1. Add new member" << endl;
    cout << "2. Display member details" << endl;
    cin >> choice;
    return choice;
}

int main()
{
    vector<Member> mems;

    Member m;

    int choice;
    while ((choice = memberMenuList()) != 0)
    {
        switch (choice)
        {

        case 1:
        {
            m.addMemberDetails();
            mems.push_back(m);
            break;
        }

        case 2:
        {
            // cout<<"Enter member id: "
            if(mems.size() > 0){
                for(int i = 0; i < mems.size(); i++){
                    mems[i].displayMemberDetails();
                }
            }
            else {
                cout << "No members currently! "<<endl;
            } 
            break;
        }
        }
    }

    // File I/O operations
    
    // fstream member_file("members.txt", ios::app);

    // if (member_file.is_open()) {
    //     member_file <<"\n"<< m.getMemberId() << " " << m.getMemberName() << " "<< m.getMemberEmail() << " " << m.getMemberPhone() << " "<< m.getPaidStatus();
    //     member_file.close();
    // }
}