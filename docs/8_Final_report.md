# Final Project Report

# Bank Account Management System

**Project Type:** C++ Console-Based Application
**Programming Language:** C++
**Development Environment:** Visual Studio Code
**Operating Systems:** Windows / Linux
**Storage:** File-Based Storage

---

## 1. Abstract

The **Bank Account Management System** is a C++-based application developed to simulate basic banking operations in a simple and efficient manner.

The system allows users to perform common banking activities such as creating an account, viewing account details, depositing money, withdrawing money, and checking account balances.

The project demonstrates practical implementation of **C++ programming, Object-Oriented Programming, file handling, data validation, and modular software design**.

The system uses local file storage to maintain account information so that data can be accessed even after the application is closed and restarted.

This project is intended primarily for educational purposes and demonstrates how programming concepts can be applied to a real-world banking scenario.

---

# 2. Introduction

Managing bank account information manually can be time-consuming and may result in errors when maintaining customer records and transactions.

The Bank Account Management System provides a computerized approach to managing basic account information and banking operations.

The application uses a simple menu-driven console interface that allows users to select different banking operations.

### Main Objectives

* Create and manage bank accounts.
* Perform basic banking transactions.
* Store account information persistently.
* Demonstrate Object-Oriented Programming.
* Demonstrate C++ file handling.
* Validate user input.
* Provide a simple and user-friendly banking interface.
* Create a foundation for future banking system development.

---

# 3. Problem Statement

Traditional manual methods of maintaining banking records can involve significant effort and may be prone to human errors.

A basic computerized system can simplify account management by allowing users to:

* Create accounts.
* Store account information.
* Search account records.
* Deposit money.
* Withdraw money.
* Check account balances.
* Maintain account data using persistent storage.

The project addresses these requirements through a simple C++ application.

---

# 4. Project Scope

The current system focuses on fundamental banking operations.

### Current Scope

* Account creation
* Account information management
* Account searching
* Deposit operations
* Withdrawal operations
* Balance checking
* File-based data storage
* Input validation
* Error handling

### Future Scope

The system can be expanded with:

* User authentication
* PIN/password protection
* Fund transfers
* Transaction history
* Bank statements
* Multiple account types
* Interest calculation
* Admin dashboard
* Database integration
* Graphical User Interface
* Encryption
* Network-based banking services

---

# 5. Technologies Used

| Technology                  | Purpose                        |
| --------------------------- | ------------------------------ |
| C++                         | Application development        |
| Object-Oriented Programming | Program structure              |
| File Handling               | Persistent data storage        |
| STL                         | Data management where required |
| Visual Studio Code          | Development environment        |
| GCC / MinGW                 | C++ compilation                |
| Windows / Linux             | Operating environment          |

---

# 6. System Requirements

## Hardware Requirements

The project does not require specialized hardware.

Minimum requirements:

* Processor: Dual-core processor or better
* RAM: 2 GB or more
* Storage: 100 MB available space
* Keyboard and display

## Software Requirements

* Windows or Linux
* C++ compiler
* Visual Studio Code or another C++ IDE
* Standard C++ libraries

---

# 7. System Architecture

The system follows a simple modular architecture.

```text
+--------------------------------+
|         User Interface         |
|       Console / Menu           |
+---------------+----------------+
                |
                v
+--------------------------------+
|       Application Logic        |
|    Account & Transactions      |
+---------------+----------------+
                |
                v
+--------------------------------+
|        Data Management         |
|     File Handling / I/O        |
+---------------+----------------+
                |
                v
+--------------------------------+
|       Persistent Storage       |
|         Account Files          |
+--------------------------------+
```

### Architecture Layers

#### User Interface

Handles:

* Menu display
* User input
* Output messages
* Navigation

#### Application Logic

Handles:

* Account creation
* Account search
* Deposits
* Withdrawals
* Balance checking

#### Data Management

Handles:

* Reading account data
* Writing account data
* Updating records
* File operations

#### Storage

Maintains account information using local files.

---

# 8. System Modules

## 8.1 Account Management

The account management module handles the creation and management of accounts.

Typical information includes:

```text
Account Number
Account Holder Name
Account Type
Account Balance
```

---

## 8.2 Deposit Module

The deposit module allows users to add money to an existing account.

Process:

```text
Enter Account Number
        |
        v
Find Account
        |
        v
Enter Deposit Amount
        |
        v
Validate Amount
        |
        v
Update Balance
        |
        v
Save Data
```

---

## 8.3 Withdrawal Module

The withdrawal module allows users to withdraw money from an account.

Before processing the transaction, the system verifies that sufficient balance is available.

```text
Enter Account Number
        |
        v
Find Account
        |
        v
Enter Withdrawal Amount
        |
        v
Check Balance
        |
   +----+----+
   |         |
Insufficient  Sufficient
   |         |
 Reject    Process
 Transaction Transaction
```

---

## 8.4 Balance Module

The balance module displays the current balance associated with an account.

---

## 8.5 File Management Module

The application uses C++ file handling to maintain persistent account records.

Common file operations include:

```text
ifstream  → Reading data
ofstream  → Writing data
fstream   → Reading and updating data
```

---

# 9. Class Design

The application follows Object-Oriented Programming principles.

A simplified account class can be represented as:

```text
+--------------------------------+
|            Account             |
+--------------------------------+
| - accountNumber                |
| - accountHolderName            |
| - accountType                  |
| - balance                      |
+--------------------------------+
| + createAccount()              |
| + displayAccount()             |
| + deposit()                    |
| + withdraw()                   |
| + checkBalance()               |
+--------------------------------+
```

### OOP Concepts Demonstrated

* Classes and objects
* Encapsulation
* Member functions
* Data abstraction
* Modular design

---

# 10. Prototype

The prototype is a console-based application with a menu-driven interface.

Example:

```text
========================================
       BANK ACCOUNT MANAGEMENT SYSTEM
========================================

1. Create Account
2. View Account
3. Deposit Money
4. Withdraw Money
5. Check Balance
6. Exit

========================================
Enter your choice:
```

The user selects an operation and provides the required information.

---

# 11. Example Workflow

A typical user workflow is:

```text
Start
  |
  v
Display Main Menu
  |
  v
Create Account
  |
  v
Save Account
  |
  v
Deposit Money
  |
  v
Check Balance
  |
  v
Withdraw Money
  |
  v
Check Updated Balance
  |
  v
Save Data
  |
  v
Exit
```

---

# 12. Sample Account Creation

Example:

```text
========================================
           CREATE ACCOUNT
========================================

Enter Account Number: 1001
Enter Account Holder Name: Kishan
Enter Account Type: Savings
Enter Initial Balance: 5000

Account created successfully!

Account Number : 1001
Account Holder : Kishan
Account Type   : Savings
Balance        : ₹5000
```

---

# 13. Sample Deposit Operation

```text
========================================
             DEPOSIT MONEY
========================================

Enter Account Number: 1001
Enter Deposit Amount: ₹2000

Deposit successful!

Previous Balance : ₹5000
Deposited Amount : ₹2000
New Balance      : ₹7000
```

---

# 14. Sample Withdrawal Operation

```text
========================================
            WITHDRAW MONEY
========================================

Enter Account Number: 1001
Enter Withdrawal Amount: ₹1500

Withdrawal successful!

Previous Balance : ₹7000
Withdrawn Amount : ₹1500
New Balance      : ₹5500
```

If the withdrawal amount is greater than the available balance:

```text
Transaction failed!

Reason:
Insufficient balance.
```

---

# 15. Input Validation

Input validation is used to prevent invalid operations.

The system checks:

* Account number validity
* Account existence
* Deposit amount
* Withdrawal amount
* Available balance
* Menu selection

Examples of invalid inputs:

```text
Negative amount
Zero amount
Invalid account number
Non-existing account
Withdrawal greater than balance
Invalid menu choice
```

---

# 16. Testing

Testing was performed to verify the correctness and reliability of the application.

### Testing Types

* Functional testing
* Input validation testing
* Boundary testing
* File handling testing
* Integration testing
* System testing
* Error handling testing

---

# 17. Test Case Summary

| Test ID | Test Description              | Expected Result           |
| ------- | ----------------------------- | ------------------------- |
| TC-01   | Create valid account          | Account created           |
| TC-02   | View existing account         | Account details displayed |
| TC-03   | Search invalid account        | Account not found         |
| TC-04   | Deposit valid amount          | Balance increased         |
| TC-05   | Deposit zero                  | Transaction rejected      |
| TC-06   | Deposit negative amount       | Transaction rejected      |
| TC-07   | Withdraw valid amount         | Balance decreased         |
| TC-08   | Withdraw greater than balance | Transaction rejected      |
| TC-09   | Check balance                 | Correct balance displayed |
| TC-10   | Save account data             | Data stored successfully  |
| TC-11   | Restart application           | Previous data available   |
| TC-12   | Invalid menu option           | Error message displayed   |

---

# 18. Testing Results

The testing process verified the major functions of the application.

### Successfully Tested

* Account creation
* Account searching
* Account information display
* Deposit operations
* Withdrawal operations
* Balance checking
* Input validation
* Error handling
* File storage
* Data retrieval
* Menu navigation

The system successfully handles normal banking operations as well as common invalid-input scenarios.

---

# 19. Error Handling

The system provides appropriate responses for invalid operations.

Examples:

```text
Account not found.
Invalid amount.
Insufficient balance.
Invalid menu option.
Invalid account number.
Unable to open file.
```

Error handling prevents invalid operations from modifying account information incorrectly.

---

# 20. Security Considerations

The current project is an educational banking simulation and does not represent a production banking system.

Basic security considerations include:

* Input validation
* Account verification
* Transaction validation
* Controlled access to account information

For a production-level implementation, additional security would be required, including:

* Authentication
* PIN/password protection
* Encryption
* Secure database access
* Role-based authorization
* Audit logging

---

# 21. Performance

The application is lightweight and does not require significant system resources.

For a small number of account records, operations such as searching, reading, writing, depositing, and withdrawing should complete quickly.

Performance can be improved in future versions by using:

* Database indexing
* Efficient data structures
* SQL databases
* Optimized search algorithms

---

# 22. Advantages

The project provides several advantages:

1. Simple and easy-to-use interface.
2. Demonstrates real-world C++ application development.
3. Uses Object-Oriented Programming.
4. Uses file handling for persistent storage.
5. Provides basic transaction management.
6. Includes input validation.
7. Easy to understand and modify.
8. Can be extended with advanced banking features.
9. Does not require specialized hardware.
10. Suitable for demonstrating programming and software-design skills.

---

# 23. Limitations

The current implementation has some limitations:

* Console-based interface.
* Local file-based storage.
* No real banking network integration.
* No advanced authentication system.
* No online transactions.
* No database server.
* Limited security features.
* Designed primarily for educational purposes.

---

# 24. Future Enhancements

The system can be further developed into a more complete banking application.

### Authentication

```text
Login
  |
  +-- Account Number
  |
  +-- PIN / Password
  |
  v
Banking Dashboard
```

### Advanced Features

* Fund transfer
* Transaction history
* Account statements
* Multiple account types
* Interest calculation
* Loan management
* Admin dashboard
* Customer dashboard
* Database integration
* GUI
* Encryption
* Online banking simulation
* ATM integration

---

# 25. Learning Outcomes

Through this project, the following concepts are demonstrated:

### C++ Programming

* Variables
* Functions
* Conditional statements
* Loops
* Input/output
* Standard libraries

### Object-Oriented Programming

* Classes
* Objects
* Encapsulation
* Abstraction
* Member functions

### File Handling

* File creation
* Reading files
* Writing files
* Updating stored information

### Software Development

* Requirement analysis
* System design
* Modular development
* Testing
* Error handling
* Documentation

---

# 26. Project Development Process

The project follows a basic software development lifecycle:

```text
Requirement Analysis
        |
        v
System Design
        |
        v
Prototype
        |
        v
Implementation
        |
        v
Testing
        |
        v
Debugging
        |
        v
Final System
```

---

# 27. Conclusion

The **Bank Account Management System** successfully demonstrates the development of a practical C++ application based on a real-world banking scenario.

The project combines **Object-Oriented Programming, file handling, input validation, modular design, and software testing** to implement essential banking operations.

Although the current application is intended for educational purposes and has limitations compared with real banking systems, its modular design provides a strong foundation for future improvements such as database integration, authentication, graphical interfaces, transaction history, and secure online banking functionality.

Overall, the project provides practical experience in converting software requirements into a working application while applying fundamental C++ and software engineering concepts.

---

# 28. Project Summary

| Category         | Details                                     |
| ---------------- | ------------------------------------------- |
| Project Name     | Bank Account Management System              |
| Project Type     | Console Application                         |
| Language         | C++                                         |
| Architecture     | Modular / Layered                           |
| Interface        | Command Line                                |
| Storage          | Local Files                                 |
| Main Concept     | Banking Management                          |
| OOP              | Yes                                         |
| File Handling    | Yes                                         |
| Input Validation | Yes                                         |
| Testing          | Functional, Boundary, Integration, System   |
| Future Expansion | Database, GUI, Authentication, Transactions |

---

## Final Statement

The **Bank Account Management System** is a functional educational project that demonstrates how C++ can be used to design and implement a structured real-world application. It provides a foundation for further development into a secure and feature-rich banking management system.
