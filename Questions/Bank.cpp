#include <iostream>
using namespace std;

class Bank_Account
{
    private:
    int account_num, balance, temp;

    public:
    void get_Info()
    {
        cout<<"Account Number: ";
        cin>>account_num;
        cout<<"Balance: ";
        cin>>balance;
    }

    void Deposit()
    {
        cout<<"\nHow much would you like to deposit: ";
        cin>>temp;
        balance += temp;
        cout<<"\nSuccessfully Deposited: "<<temp<<" in account "<<account_num;
        cout<<"\nTotal available balance is : "<< balance;
    }

    void Withdraw()
    {
        cout<<"\nHow much would you like to Withdraw: ";
        cin>>temp;
        if (balance>temp)
        {
            balance-=temp;
            cout<<"\nSuccessfully Withdrawn: "<<temp<<" in account "<<account_num;
            cout<<"\nTotal availabe balance is : "<<balance;
        }
        else
        {
            cout<<"OOPS! Seems like you do not have enough balance.";
        }

    }
};

int main()
{
    Bank_Account a1, a2;
    char ans;
    int i;

    cout<<"Enter the details of Account 1 :\n";
    a1.get_Info();
    cout<<"\nEnter the details of Account 2 :\n";
    a2.get_Info();

    cout<<"\nDepositing in Account 1: ";
    a1.Deposit();
    cout<<"\n\nDepositing in Account 2: ";
    a2.Deposit();

    cout<<"\n\nWithdrawing from Account 1: ";
    a1.Withdraw();
    cout<<"\n\nWithdrawing from Account 2: ";
    a2.Withdraw();

    // cout<<"To Deposit (Enter d) OR To Withdraw (Enter w) OTHERWISE Press any key: ";
    // cin>>ans;


    // if (ans == 'd' || ans == 'D')
    // {
    //     cout<<"In which Account Would you like to deposit (1/2): ";
    //     cin>>i;
    //     if (i == 1)
    //     {
    //         a1.Deposit();
    //     }
    //     else
    //     {
    //         a2.Deposit();
    //     }
    // }
    // else if (ans == 'w' || ans == 'W')
    // {
    //     cout<<"In which Account Would you like to Withdraw (1/2): ";
    //     cin>>i;
    //     if (i == 1)
    //     {
    //         a1.Withdraw();
    //     }
    //     else
    //     {
    //         a2.Withdraw();
    //     }
    // }
    // else
    // {
    //     cout<<"Invalid Input!!!";
    // }
    
    return 0;
}