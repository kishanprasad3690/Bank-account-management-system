#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <string>
#include <ctime>
#include <iomanip>
#include <limits>

using namespace std;

// --- Helper Functions ---
string getCurrentTimestamp() {
    time_t now = time(0);
    tm* ltm = localtime(&now);
    stringstream ss;
    ss << 1900 + ltm->tm_year << "-" << setfill('0') << setw(2) << 1 + ltm->tm_mon << "-"
       << setfill('0') << setw(2) << ltm->tm_mday << " "
       << setfill('0') << setw(2) << ltm->tm_hour << ":"
       << setfill('0') << setw(2) << ltm->tm_min << ":"
       << setfill('0') << setw(2) << ltm->tm_sec;
    return ss.str();
}

// 🧹 Input clearing helpers to prevent infinite loops
void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void waitForKey() {
    cout << "\nPress any key to continue...";
    cin.get();
}

// --- Data Structures ---
struct Transaction {
    int accountId;
    string type;
    double amount;
    string timestamp;
};

class Account {
public:
    int id;
    string password; // Added Password Field
    string name;
    string type; // Savings/Current
    double balance;

    Account() {}
    Account(int id, string password, string name, string type, double balance)
        : id(id), password(password), name(name), type(type), balance(balance) {}
};

// --- Banking System Class ---
class BankSystem {
private:
    map<int, Account> accounts;
    vector<Transaction> transactions;
    const string ACCOUNTS_FILE = "accounts.csv";
    const string TRANSACTIONS_FILE = "transactions.csv";

    // 📜 Record Transaction
    void recordTransaction(int id, const string& type, double amount) {
        Transaction t = {id, type, amount, getCurrentTimestamp()};
        transactions.push_back(t);
        saveTransactions();
    }

    // 💾 Persistence: Save Data
    void saveAccounts() {
        ofstream out(ACCOUNTS_FILE);
        for (const auto& pair : accounts) {
            // Save password in the CSV
            out << pair.second.id << "," << pair.second.password << "," 
                << pair.second.name << "," << pair.second.type << "," 
                << pair.second.balance << "\n";
        }
    }

    void saveTransactions() {
        ofstream out(TRANSACTIONS_FILE);
        for (const auto& t : transactions) {
            out << t.accountId << "," << t.type << "," << t.amount << "," << t.timestamp << "\n";
        }
    }

    // 💾 Persistence: Load Data
    void loadData() {
        ifstream accFile(ACCOUNTS_FILE);
        string line, token;
        if (accFile.is_open()) {
            while (getline(accFile, line)) {
                stringstream ss(line);
                Account acc;
                getline(ss, token, ','); acc.id = stoi(token);
                getline(ss, acc.password, ','); // Load password
                getline(ss, acc.name, ',');
                getline(ss, acc.type, ',');
                getline(ss, token, ','); acc.balance = stod(token);
                accounts[acc.id] = acc;
            }
        }

        ifstream txnFile(TRANSACTIONS_FILE);
        if (txnFile.is_open()) {
            while (getline(txnFile, line)) {
                stringstream ss(line);
                Transaction t;
                getline(ss, token, ','); t.accountId = stoi(token);
                getline(ss, t.type, ',');
                getline(ss, token, ','); t.amount = stod(token);
                getline(ss, t.timestamp, ',');
                transactions.push_back(t);
            }
        }
    }

public:
    BankSystem() {
        loadData();
    }

    // 1. Create Account
    void createAccount() {
        string name, type, password;
        double deposit;
        
        int id = accounts.empty() ? 1 : accounts.rbegin()->first + 1; // Start IDs at 1 

        cout << "\nEnter Account Holder Name: ";
        getline(cin, name);

        // Added Password Prompt
        cout << "Enter Account Password/PIN: ";
        getline(cin, password);
        
        cout << "Enter Account Type (Savings/Current): ";
        getline(cin, type);
        
        cout << "Enter Initial Deposit: ";
        if (!(cin >> deposit)) { 
            clearInputBuffer(); 
            cout << "Invalid input. Defaulting to 0.\n"; 
            deposit = 0; 
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear trailing newline
        }

        accounts[id] = Account(id, password, name, type, deposit);
        if (deposit > 0) recordTransaction(id, "INITIAL DEPOSIT", deposit);
        saveAccounts();
        
        cout << "\nAccount Created Successfully! (Account ID: " << id << ")\n";
        waitForKey();
    }

    // 2. View Account
    void viewAccount() {
        int id;
        cout << "\nEnter Account ID to view: ";
        if (!(cin >> id)) { clearInputBuffer(); return; }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (accounts.find(id) != accounts.end()) {
            cout << "\n--- Account Details ---\n";
            cout << "Account ID    : " << accounts[id].id << "\n";
            cout << "Holder Name   : " << accounts[id].name << "\n";
            cout << "Account Type  : " << accounts[id].type << "\n";
            cout << "Password      : " << accounts[id].password << "\n"; // Optional: Show password or hide it
            cout << "Total Balance : $" << fixed << setprecision(2) << accounts[id].balance << "\n";
        } else {
            cout << "Account not found!\n";
        }
        waitForKey();
    }

    // 3. Search Account
    void searchAccount() {
        string query;
        cout << "\nEnter Account Holder Name to search: ";
        getline(cin, query);

        cout << "\n--- Search Results ---\n";
        bool found = false;
        for (const auto& pair : accounts) {
            if (pair.second.name.find(query) != string::npos) {
                cout << "ID: " << pair.second.id << " | Name: " << pair.second.name 
                     << " | Type: " << pair.second.type << " | Balance: $" << pair.second.balance << "\n";
                found = true;
            }
        }
        if (!found) cout << "No accounts matched your search.\n";
        waitForKey();
    }

    // 4. Update Account
    void updateAccount() {
        int id;
        cout << "\nEnter Account ID to update: ";
        if (!(cin >> id)) { clearInputBuffer(); return; }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        if (accounts.find(id) != accounts.end()) {
            cout << "Enter New Account Holder Name: ";
            getline(cin, accounts[id].name);
            
            cout << "Enter New Password/PIN: "; // Added update password
            getline(cin, accounts[id].password);

            cout << "Enter New Account Type (Savings/Current): ";
            getline(cin, accounts[id].type);
            
            saveAccounts();
            cout << "Account updated successfully!\n";
        } else {
            cout << "Account not found!\n";
        }
        waitForKey();
    }

    // 5. Delete Account
    void deleteAccount() {
        int id;
        cout << "\nEnter Account ID to delete: ";
        if (!(cin >> id)) { clearInputBuffer(); return; }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (accounts.find(id) != accounts.end()) {
            if (accounts[id].balance > 0) {
                cout << "Cannot delete account. Balance is not zero ($" << accounts[id].balance << ").\n";
            } else {
                accounts.erase(id);
                saveAccounts();
                cout << "Account deleted successfully!\n";
            }
        } else {
            cout << "Account not found!\n";
        }
        waitForKey();
    }

    // 6. Check Balance
    void checkBalance() {
        int id;
        cout << "\nEnter Account ID to check balance: ";
        if (!(cin >> id)) { clearInputBuffer(); return; }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (accounts.find(id) != accounts.end()) {
            cout << "Current Balance: $" << fixed << setprecision(2) << accounts[id].balance << "\n";
        } else {
            cout << "Account not found!\n";
        }
        waitForKey();
    }

    // 7. Transaction History
    void transactionHistory() {
        int id;
        cout << "\nEnter Account ID to view history: ";
        if (!(cin >> id)) { clearInputBuffer(); return; }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (accounts.find(id) != accounts.end()) {
            cout << "\n--- Transaction History for ID " << id << " ---\n";
            bool found = false;
            for (const auto& t : transactions) {
                if (t.accountId == id) {
                    cout << "[" << t.timestamp << "] " << t.type << ": $" << t.amount << "\n";
                    found = true;
                }
            }
            if (!found) cout << "No transactions found.\n";
        } else {
            cout << "Account not found!\n";
        }
        waitForKey();
    }

    // 8. Low Balance Alert
    void lowBalanceAlert() {
        double threshold = 500.0; // Low balance limit
        cout << "\n--- Accounts with Balance Below $" << threshold << " ---\n";
        bool found = false;
        for (const auto& pair : accounts) {
            if (pair.second.balance < threshold) {
                cout << "ID: " << pair.second.id << " | Name: " << pair.second.name 
                     << " | Balance: $" << pair.second.balance << "\n";
                found = true;
            }
        }
        if (!found) cout << "All accounts have sufficient balance.\n";
        waitForKey();
    }

    // 9. Reports
    void reports() {
        double totalFunds = 0;
        int totalAccounts = accounts.size();
        for (const auto& pair : accounts) {
            totalFunds += pair.second.balance;
        }

        cout << "\n=== SYSTEM REPORTS ===\n";
        cout << "Total Active Accounts : " << totalAccounts << "\n";
        cout << "Total Bank Funds      : $" << fixed << setprecision(2) << totalFunds << "\n";
        waitForKey();
    }

    void start() {
        int choice;
        while (true) {
            cout << "\n===== BANK ACCOUNT MANAGEMENT SYSTEM =====\n\n";
            cout << "1. Create Account\n";
            cout << "2. View Account\n";
            cout << "3. Search Account\n";
            cout << "4. Update Account\n"; 
            cout << "5. Delete Account\n";
            cout << "6. Check Balance\n";
            cout << "7. Transaction History\n";
            cout << "8. Low Balance Alert\n";
            cout << "9. Reports\n";
            cout << "0. Exit\n\n";
            cout << "Enter your choice: ";
            
            if (!(cin >> choice)) {
                clearInputBuffer();
                cout << "Invalid choice. Please enter a number.\n";
                continue;
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear trailing newline

            switch (choice) {
                case 1: createAccount(); break;
                case 2: viewAccount(); break;
                case 3: searchAccount(); break;
                case 4: updateAccount(); break;
                case 5: deleteAccount(); break;
                case 6: checkBalance(); break;
                case 7: transactionHistory(); break;
                case 8: lowBalanceAlert(); break;
                case 9: reports(); break;
                case 0: cout << "Exiting System...\n"; return;
                default:
                    cout << "Invalid Option. Please try again.\n";
                    waitForKey();
            }
        }
    }
};

int main() {
    BankSystem bank;
    bank.start();
    return 0;
}