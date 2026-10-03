# Bank Account Management System

A robust, console-based banking application built in C++. This system allows users to create, view, update, and delete bank accounts, as well as perform balance checks and view transaction histories. It features persistent data storage using CSV files, ensuring that all account information and transaction records are saved securely across sessions.

## 🚀 Features

* **Account Creation:** Open new Savings or Current accounts with an initial deposit, account holder name, and secure password/PIN.
* **Account Management:** Update existing account details or delete accounts (only if the balance is zero).
* **Search & View:** Search for accounts by name or view full account details using a unique Account ID.
* **Balance Tracking:** Check current account balances in real-time.
* **Transaction History:** Automatically records and timestamps all initial deposits (and future transactions).
* **System Reports:** View total active accounts and the total capital held within the bank.
* **Low Balance Alerts:** Quickly identify accounts with a balance below $500.
* **Data Persistence:** Automatically saves and loads data using `accounts.csv` and `transactions.csv`.
* **Robust Input Validation:** Built-in safeguards prevent the application from crashing or infinitely looping when invalid inputs (like letters instead of numbers) are entered.

## 🛠️ Technical Highlights

* **Language:** C++ (Standard Library only, no external dependencies)
* **Architecture:** Object-Oriented Programming (OOP)
* **Data Structures:** Utilizes `std::map` for lightning-fast ID-based account retrieval and `std::vector` for sequential transaction history.
* **File I/O:** Uses C++ `fstream` for persistent flat-file database management.

## 📂 File Structure

Once the program runs for the first time, it will automatically generate the following files in the same directory as the executable:
* `bank.cpp`: The main C++ source code file.
* `accounts.csv`: Stores Account ID, Password, Name, Account Type, and Balance.
* `transactions.csv`: Stores Account ID, Transaction Type, Amount, and Timestamp.

## 💻 How to Build and Run

### Prerequisites
You need a C++ compiler installed on your system (e.g., GCC/G++, Clang, or MSVC).

### Compilation
1. Open your terminal or command prompt.
2. Navigate to the folder containing the source code.
3. Compile the code using the following command:
   ```bash
   g++ bank.cpp -o bank
   ./bank
## 📊 System Flowchart
```text
                               ┌─────────────────────────┐
                               │    Start Application    │
                               └────────────┬────────────┘
                                            ▼
                               ┌─────────────────────────┐
                               │  Initialize BankSystem  │
                               └────────────┬────────────┘
                                            ▼
                               ┌─────────────────────────┐
                               │   Load accounts.csv &   │
                               │  transactions.csv into  │
                               │         Memory          │
                               └────────────┬────────────┘
                                            ▼
               ┌───────────────────────────────────────────────────────────┐
               │                                                           │
               ▼                                                           │
        ┌──────────────┐                                                   │
        │Main Menu Loop│◄─────────────────────────────────────────┐        │
        └──────┬───────┘                                          │        │
               │                                                  │        │
               ├─▶ [Choice 1] ──▶┌────────────────┐              │        │
               │                  │ Create Account │              │        │
               │                  └───────┬────────┘              │        │
               │                          │                       │        │
               │            ┌─────────────┴────────────┐          │        │
               │            ▼                          ▼          │        │
               │   ┌──────────────────┐      ┌──────────────────┐ │        │
               │   │If Initial Deposit│      │Update Memory Maps│ │        │
               │   │       > 0        │      └─────────┬────────┘ │        │
               │   └────────┬─────────┘                │          │        │
               │            ▼                          ▼          │        │
               │   ┌──────────────────┐      ┌──────────────────┐ │        │
               │   │Record Transaction│      │Save accounts.csv │ │        │
               │   └────────┬─────────┘      └─────────┬────────┘ │        │
               │            ▼                          │          │        │
               │   ┌──────────────────┐                │          │        │
               │   │ Save transactions│                │          │        │
               │   │       .csv       │                │          │        │
               │   └────────┬─────────┘                │          │        │
               │            │                          │          │        │
               │            └──────────────┬───────────┘          │        │
               │                           │                      │        │
               ├─▶ [Choice 4] ──▶┌────────────────┐              │        │
               │                  │ Update Account │──────┐       │        │
               │                  └────────────────┘      │       │        │
               │                                          ▼       │        │
               ├─▶ [Choice 5] ──▶┌────────────────┐ ┌──────────────────┐ │
               │                  │ Delete Account │─▶│Update Memory Maps│ │
               │                  └────────────────┘ └────────┬─────────┘  │
               │                                          ▼          │     │
               │                                     ┌──────────────────┐  │
               │                                     │Save accounts.csv │  │
               │                                     └────────┬─────────┘  │
               │                                              │            │
               ├─▶ [Choice 2] ──▶ [View Account] ───────┐     │           │
               ├─▶ [Choice 3] ──▶ [Search Account] ─────┤     │           │
               ├─▶ [Choice 6] ──▶ [Check Balance] ──────┤     │           │
               ├─▶ [Choice 7] ──▶ [Transaction History] ┤     │           │
               ├─▶ [Choice 8] ──▶ [Low Balance Alert] ──┤     │           │
               ├─▶ [Choice 9] ──▶ [Reports] ────────────┤     │           │
               │                                        ▼      │           │
               │                               ┌──────────────────┐        │
               │                               │ Read Memory Maps │        │
               │                               │    & Display     │        │
               │                               └────────┬─────────┘        │
               │                                        │                  │
               │                                        └─────────┐        │
               │                                                  ▼        │
               │                                        ┌──────────────────┐
               │                                        │Wait for Key Press│
               │                                        └──────────────────┘
               │
               └─▶ [Choice 0] ──▶┌────────────────┐
                                  │Exit Application│
                                  └────────────────┘
```