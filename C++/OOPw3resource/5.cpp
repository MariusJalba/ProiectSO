#include <iostream>
using namespace std;
class BankAccount
{
private:
    int acc_number;
    int balance;

public:
    BankAccount(const int &a_n, const int &b) : acc_number(a_n), balance(b){};
    void withdraw(int n)
    {
        if (n <= balance)
        {
            balance -= n;
        }
        else{
            cout<<"Insufficient amount"<<endl;
        }
    }
    void deposit(int n)
    {
        balance += n;
    }
    void set_acc_n(int a_n)
    {
        acc_number = a_n;
    }
    void set_bal(int b)
    {
        balance = b;
    }
    int get_acc_n()
    {
        return acc_number;
    }
    int get_bal()
    {
        return balance;
    }
};
int main()
{
    BankAccount acc(2012321, 0);
    acc.withdraw(5);
    acc.deposit(10000);
    cout << "Account number:" << acc.get_acc_n() << endl;
    cout << "Balance:" << acc.get_bal() << endl;
    return 0;
}