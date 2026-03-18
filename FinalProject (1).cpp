#include <iostream>
#include <queue>
using namespace std;

class BankAccount {
public:
    int accNo;
    string name;
    float balance;
    string history[20];
    int transCount = 0; 

    void create() {
        cout << "Enter Account Number: ";
        cin >> accNo;
        cout << "Enter Name: ";
        cin >> name;
        balance = 0;
        transCount = 0;
        cout << "Account Created!" << endl;
    }

    void deposit() {
        float amt;
        cout << "Enter Amount to Deposit: ";
        cin >> amt;
        balance += amt;
        history[transCount] = "Deposit: " + to_string(amt);
        transCount++;
        cout << "Deposit Done!" << endl;
    }

    void withdraw() {
        float amt;
        cout << "Enter Amount to Withdraw: ";
        cin >> amt;
        if(amt > balance)
            cout << "Not Enough Balance!" << endl;
        else {
            balance -= amt;
            history[transCount] = "Withdraw: " + to_string(amt);
            transCount++;
            cout << "Withdraw Done!" << endl;
        }
    }

    void showHistory() {
        if(transCount == 0) {
            cout << "No Transactions Yet!" << endl;
            return;
        }
        cout << "Transaction History:" << endl;
        for(int i = transCount-1; i >=0; i--) { 
            cout << history[i] << endl;
        }
    }

    void zakat() {
        cout << "Zakat (2.5%) = " << balance * 2.5 / 100 << endl;
    }

    void showBalance() {
        cout << "Current Balance = " << balance << endl;
    }
};

int main() {
    BankAccount accounts[10];
    int totalAccounts = 0;
    queue<string> customerQueue;
    int choice;

    cout << "Welcome to Simple Bank System!" << endl;
    cout << "Create Your First Account:" << endl;
    accounts[totalAccounts].create();
    totalAccounts++;

    do {
        cout << "\nMAIN MENU\n";
        cout << "1. Create New Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Show Transaction History\n";
        cout << "5. Calculate Zakat\n";
        cout << "6. Show Balance\n";
        cout << "7. Add Customer to Queue\n";
        cout << "8. Serve Customer\n";
        cout << "0. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        if(choice == 1) {
            if(totalAccounts < 10) {
                accounts[totalAccounts].create();
                totalAccounts++;
            } else {
                cout << "Max Accounts Reached!" << endl;
            }
        } else if(choice == 2) {
            int num;
            cout << "Enter Account Number: ";
            cin >> num;
            bool found = false;
            for(int i=0; i<totalAccounts; i++) {
                if(accounts[i].accNo == num) {
                    accounts[i].deposit();
                    found = true;
                    break;
                }
            }
            if(!found) cout << "Account Not Found!" << endl;
        } else if(choice == 3) {
            int num;
            cout << "Enter Account Number: ";
            cin >> num;
            bool found = false;
            for(int i=0; i<totalAccounts; i++) {
                if(accounts[i].accNo == num) {
                    accounts[i].withdraw();
                    found = true;
                    break;
                }
            }
            if(!found) cout << "Account Not Found!" << endl;
        } else if(choice == 4) {
            int num;
            cout << "Enter Account Number: ";
            cin >> num;
            bool found = false;
            for(int i=0; i<totalAccounts; i++) {
                if(accounts[i].accNo == num) {
                    accounts[i].showHistory();
                    found = true;
                    break;
                }
            }
            if(!found) cout << "Account Not Found!" << endl;
        } else if(choice == 5) {
            int num;
            cout << "Enter Account Number: ";
            cin >> num;
            bool found = false;
            for(int i=0; i<totalAccounts; i++) {
                if(accounts[i].accNo == num) {
                    accounts[i].zakat();
                    found = true;
                    break;
                }
            }
            if(!found) cout << "Account Not Found!" << endl;
        } else if(choice == 6) {
            int num;
            cout << "Enter Account Number: ";
            cin >> num;
            bool found = false;
            for(int i=0; i<totalAccounts; i++) {
                if(accounts[i].accNo == num) {
                    accounts[i].showBalance();
                    found = true;
                    break;
                }
            }
            if(!found) cout << "Account Not Found!" << endl;
        } else if(choice == 7) {
            string cname;
            cout << "Enter Customer Name: ";
            cin >> cname;
            customerQueue.push(cname);
            cout << "Customer Added to Queue!" << endl;
        } else if(choice == 8) {
            if(customerQueue.empty()) cout << "No Customers in Queue!" << endl;
            else {
                cout << "Serving Customer: " << customerQueue.front() << endl;
                customerQueue.pop();
            }
        } else if(choice == 0) {
            cout << "Thanks for Using Simple Bank System. Goodbye!" << endl;
        } else {
            cout << "Invalid Choice! Try Again." << endl;
        }

    } while(choice != 0);

    return 0;
}