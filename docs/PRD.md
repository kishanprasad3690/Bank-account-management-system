# Project Requirements Document (PRD)

## 1. Project Objective & Scope
The objective of this project is to build a locally hosted, console-based **Bank Account Management System** using Standard C++. The system serves as the foundational application software layer that demonstrates Object-Oriented Programming (OOP), File Handling, and Standard Template Library (STL) utilization. 

**Scope:** The system manages the complete lifecycle of customer bank accounts, processes financial transactions, logs historical data, and generates administrative reports. All data must persist across application restarts using local flat-file storage.

---

## 2. System Modules & Features
The project is divided into the following core functional modules:

* **Account Management Module:** Create, View, Search, Update, and Delete customer accounts.
* **Banking Operations Module:** Perform Deposits, Withdrawals, and Check Balances.
* **Transaction History Module:** View a timestamped chronological log of all account transactions.
* **Reporting & Alerts Module:** Notify users of low balances and generate system-wide financial summaries.
* **Data Persistence Module:** Save and load data seamlessly using text files (`accounts.txt` and `transactions.txt`).

---

## 3. Functional Requirements (FR)
Functional requirements define the specific behaviors and actions the system must support.

* **FR1 - Account Creation:** The system must allow users to create an account by providing a Holder Name, Account Type (Savings/Current), and an Initial Deposit. The system must auto-generate a unique Account ID.
* **FR2 - Account Retrieval:** Users must be able to view specific account details using their Account ID, or search for accounts using a substring of the Account Holder's name.
* **FR3 - Account Modification:** Users must be able to update the Holder Name and Account Type. 
* **FR4 - Account Deletion:** Users can delete an account. The system must reject the deletion if the account balance is greater than $0.00.
* **FR5 - Financial Transactions:** The system must process deposits and withdrawals. Withdrawals must be blocked if the requested amount exceeds the current balance.
* **FR6 - Transaction Logging:** Every successful deposit or withdrawal must generate a timestamped transaction record containing a unique Transaction ID, the Account ID, Transaction Type, and Amount.
* **FR7 - Low Balance Alert:** The system must identify and display a list of all accounts with a balance falling below the $500.00 threshold.
* **FR8 - System Reports:** The system must calculate and display the total number of active accounts, the total capital (funds) held within the bank, and a unique list of active account types.

---

## 4. Non-Functional Requirements (NFR)
Non-functional requirements define system attributes such as architecture, performance, and reliability.

* **NFR1 - Strict OOP Architecture:** The system must be strictly divided into specific entity and control classes: `BankAccount`, `Transaction`, `FileManager`, and `BankSystem`.
* **NFR2 - STL Integration:** The system must efficiently manage memory using Standard Template Library containers:
  * `std::vector` for storing accounts and transactions.
  * `std::map` for linking account numbers to balances for rapid lookup.
  * `std::set` for storing unique account types.
  * `<algorithm>` for searching and filtering.
* **NFR3 - Data Persistence (File I/O):** Data must be saved to `accounts.txt` and `transactions.txt` immediately following any state change (Create, Update, Delete, Deposit, Withdraw) to prevent data loss on unexpected shutdown.
* **NFR4 - Input Fault Tolerance:** The application must intercept standard input (`std::cin`) failures (e.g., entering text when a number is expected) and clear the input buffer to prevent infinite loop crashes.

---

## 5. Project Deliverables
To satisfy the multi-stage academic requirements, the following deliverables will be provided:

1. **Source Code:** A fully compiled, well-commented C++ source file (`bank_system.cpp`).
2. **UML Diagrams:** Class diagrams, sequence diagrams, and flowcharts outlining system architecture.
3. **Project Documentation:** `README.md`, `Architecture.md`, `Development_Plan.md`, and this `Project_Requirements.md`.
4. **Version Control:** A Git repository demonstrating continuous commit history and branching logic.
5. **Final Project Report/Demo:** A comprehensive presentation covering achievements, limitations, test cases, and a live console demonstration.