#include <iostream>
#include <vector>
#include <stack>
#include <cstdlib>
using namespace std;

class ATM {
private:
     unsigned long long int acc_no;
    string name;
    string mob_no;
    int pin;
    double bal;
    stack<int> mini_statement;

public:
    // Default constructor
    ATM() : acc_no(0), name(""), mob_no(""), pin(0), bal(0.0) {}

    // Parameterized constructor
    ATM( unsigned long long  int set_accno, const string& set_name, const string& set_mobno, int set_pin, double set_balance)
        : acc_no(set_accno), name(set_name), mob_no(set_mobno), pin(set_pin), bal(set_balance) {}

     unsigned long long int get_accno() {
        return acc_no;
    }

    string get_name() {
        return name;
    }

    string get_mob_no() {
        return mob_no;
    }

    int get_pin() {
        return pin;
    }

    double get_bal() {
        return bal;
    }

    void set_mob_no(string new_mob_no) {
        mob_no = new_mob_no;
    }

    void cashwithdraw(int amount) {
        if (bal >= amount) {
            bal -= amount;
            mini_statement.push(amount);
            cout << "Please collect your cash" << endl;
            cout << "Your Available balance is: " << bal << endl;
        } else {
            cout << "Insufficient Balance" << endl;
        }
    }

    void display_statement() {
        if (mini_statement.empty()) {
            cout << "No withdrawal history available." << endl;
        } else {
            cout << "Mini Statement:" << endl;
            while (!mini_statement.empty()) {
                cout << mini_statement.top() << " ";
                mini_statement.pop();
            }
            cout << endl;
        }
    }
};

int main() {
    int enterPIN;
     unsigned long long  int enterACCNO;
    string mob_prev, mob_new;
    vector<ATM> users;

    users.push_back(ATM(126615500017131, "Ana", "9345668003", 8525, 200000));
    users.push_back(ATM(1266155000017132, "Anu", "7010409957", 1209, 100000));
    users.push_back(ATM(1266155000017133, "Harshini", "9487155233", 8903, 400000));
    users.push_back(ATM(1266155000017134, "Nimoshini", "9486790590", 2703, 250000));

    bool continueATM = true;

    do {
        cout << "*****************WELCOME TO ATM EXPRESS***************" << endl;
        cout << "Enter Your Account Number:";
        cin >> enterACCNO;
        cout << "Enter Your ATM Pin:";
        cin >> enterPIN;

        bool UserAuthenticated = false;

        for (size_t i = 0; i < users.size(); i++) {
            if ((enterACCNO == users[i].get_accno()) && (enterPIN == users[i].get_pin())) {
                UserAuthenticated = true;

                int choice;
                do {
                    cout << "*****************WELCOME TO ATM EXPRESS***************" << endl;
                    cout << "Options" << endl;
                    cout << "1. Check Balance" << endl;
                    cout << "2. Cash Withdraw" << endl;
                    cout << "3. Show Account Information" << endl;
                    cout << "4. Change Mobile no" << endl;
                    cout << "5. Mini Statement" << endl;
                    cout << "6. Exit" << endl;

                    cout << "Enter your choice: ";
                    cin >> choice;

                    switch (choice) {
                        case 1:
                            cout << "Your Account Balance is:" << users[i].get_bal() << endl;
                            break;
                        case 2:
                            int amount;
                            cout << "Enter the Amount:";
                            cin >> amount;
                            users[i].cashwithdraw(amount);
                            break;
                        case 3:
                            cout << "Account Information:" << endl;
                            cout << "Account Number:" << users[i].get_accno() << endl;
                            cout << "Name:" << users[i].get_name() << endl;
                            cout << "Balance:" << users[i].get_bal() << endl;
                            cout << "Mobile Number:" << users[i].get_mob_no() << endl;
                            break;
                        case 4:
                            cout << "Enter Old Mobile number:";
                            cin >> mob_prev;
                            cout << "Enter New Mobile number:";
                            cin >> mob_new;
                            users[i].set_mob_no(mob_new);
                            break;
                        case 5:
                            users[i].display_statement();
                            break;
                        case 6:
                            continueATM = false; // Exit the ATM service
                            break;
                        default:
                            cout << "Enter Valid data!!" << endl;
                    }
                } while (UserAuthenticated);
            }
        }

        if (!UserAuthenticated) {
            cout << "User details invalid!!" << endl;
            cin.ignore();
        }

    } while (continueATM);

    return 0;
}
