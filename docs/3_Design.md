# System Design

## Bank Account Management System

The **Bank Account Management System** is designed as a modular C++ application that manages basic banking operations such as account creation, account search, deposits, withdrawals, balance checking, and account data storage.

The system follows an object-oriented and modular design approach to keep the application simple, maintainable, and easy to extend.

---

## 1. System Architecture

The system follows a simple layered architecture:

```text
+-----------------------------+
|        User Interface       |
|     Menu / Console Input    |
+-------------+---------------+
              |
              v
+-----------------------------+
|      Application Logic      |
| Account & Banking Operations|
+-------------+---------------+
              |
              v
+-----------------------------+
|       Data Management       |
| File Handling / Validation  |
+-------------+---------------+
              |
              v
+-----------------------------+
|       Persistent Storage    |
|      Account Data Files     |
+-----------------------------+
```

### Architecture Components

#### 1. User Interface Layer

Handles interaction between the user and the system through a console-based menu.

Responsibilities:

* Display available banking operations
* Accept user input
* Display results and messages
* Handle basic input validation

#### 2. Application Logic Layer

Contains the main banking operations.

Responsibilities:

* Create accounts
* Search accounts
* Deposit money
* Withdraw money
* Check account balance
* Update account information

#### 3. Data Management Layer

Responsible for reading and writing account information.

Responsibilities:

* Open and close files
* Read account records
* Write new records
* Update existing records
* Maintain persistent data

#### 4. Storage Layer

Stores account information using files so that data can be retained after the program terminates.

---

# 2. System Flow

The overall system flow can be represented as:

```text
              START
                |
                v
       Initialize System
                |
                v
         Display Main Menu
                |
        +-------+-------+
        |       |       |
        v       v       v
     Create   Search   Banking
     Account  Account  Operations
        |       |       |
        +-------+-------+
                |
                v
       Perform Selected
          Operation
                |
                v
       Read / Update Data
                |
                v
        Display Result
                |
                v
        Return to Menu
                |
          +-----+-----+
          |           |
        Exit       Continue
          |           |
          v           |
         END <--------+
```

---

# 3. Main Modules

The system is divided into several logical modules.

## 3.1 Account Management

This module handles the creation and management of bank accounts.

Main operations:

* Create Account
* View Account
* Search Account
* Update Account
* Delete Account (if implemented)

Example account information:

```text
Account Number
Account Holder Name
Account Type
Balance
Contact Information
```

---

## 3.2 Deposit Module

The deposit module allows a user to add money to an existing account.

### Process

```text
Enter Account Number
        |
        v
Search Account
        |
        v
Account Found?
   /          \
 No            Yes
 |              |
Error       Enter Amount
Message         |
                v
        Validate Amount
                |
                v
        Update Balance
                |
                v
        Save Account Data
```

---

## 3.3 Withdrawal Module

The withdrawal module allows a user to withdraw money from an account.

### Validation

Before completing a withdrawal, the system checks:

* Whether the account exists
* Whether the entered amount is valid
* Whether sufficient balance is available

```text
Enter Account Number
        |
        v
Search Account
        |
        v
Account Found?
   /          \
 No            Yes
 |              |
Error       Enter Amount
Message         |
                v
       Check Available Balance
                |
        +-------+-------+
        |               |
   Insufficient       Sufficient
      Balance           Balance
        |               |
        v               v
      Error         Deduct Amount
                       |
                       v
                  Save Data
```

---

# 4. Class Design

The system uses Object-Oriented Programming principles.

A simplified class structure can be represented as:

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

### Account Class

The `Account` class represents a bank account.

#### Data Members

* `accountNumber`
* `accountHolderName`
* `accountType`
* `balance`

#### Member Functions

* Create account
* Display account information
* Deposit money
* Withdraw money
* Check balance

---

# 5. Data Flow

The basic data flow of the application is:

```text
User
 |
 | Input
 v
Console Interface
 |
 v
Banking Operations
 |
 v
Account Object
 |
 v
File Handling
 |
 v
Account Data File
```

When information needs to be retrieved:

```text
Account Data File
       |
       v
 File Handling
       |
       v
 Account Object
       |
       v
 Banking Operation
       |
       v
 Console Output
```

---

# 6. File Handling Design

The system uses C++ file handling to store account information.

Typical file operations include:

```text
ofstream  → Write account information
ifstream  → Read account information
fstream   → Read and update information
```

The general process is:

```text
Open File
   |
   v
Read / Write Data
   |
   v
Process Data
   |
   v
Close File
```

Using file storage allows account information to remain available even after the program is closed.

---

# 7. Input Validation

The system should validate user input before performing banking operations.

Examples:

### Account Number

```text
Check whether account exists
        |
        v
   Valid Account?
    /          \
  No            Yes
  |              |
 Error          Continue
```

### Amount

The system should ensure that:

* Deposit amount is greater than zero.
* Withdrawal amount is greater than zero.
* Withdrawal amount does not exceed the available balance.
* Invalid input is handled properly.

---

# 8. Security Considerations

Since this is an educational banking simulation, basic security principles can be demonstrated.

Possible security improvements include:

* Account authentication
* PIN/password protection
* Input validation
* Preventing unauthorized account access
* Protecting sensitive account information
* Encrypting stored data in future versions

---

# 9. Error Handling

The system should provide appropriate messages for invalid operations.

Examples:

```text
Account not found.
Invalid amount.
Insufficient balance.
Invalid menu option.
Invalid account number.
File could not be opened.
```

This prevents the program from terminating unexpectedly and provides a better user experience.

---

# 10. Future Design Improvements

The current design can be extended to support:

```text
                    Bank System
                         |
        +----------------+----------------+
        |                |                |
     Customer           Admin          Database
        |                |                |
    Accounts         Management       Storage
        |
   Transactions
        |
 +------+------+------+
 |      |      |      |
Deposit Withdraw Transfer History
```

Future versions may include:

* GUI-based interface
* SQL/MySQL database
* Online banking functionality
* Account authentication
* Fund transfer
* Transaction history
* Multiple branches
* Admin dashboard
* ATM simulation
* Encryption
* Network-based banking services

---

# 11. Design Goals

The system is designed with the following goals:

1. **Simplicity** – Easy to understand and operate.
2. **Modularity** – Banking functions are logically separated.
3. **Maintainability** – Code can be modified or extended easily.
4. **Reliability** – Input and transaction validation are included.
5. **Persistence** – Account information is stored using files.
6. **Scalability** – The design can be extended with databases and additional banking features.
7. **Educational Value** – Demonstrates C++, OOP, file handling, and system design concepts.

---

## Conclusion

The design of the **Bank Account Management System** provides a structured approach for implementing common banking operations using C++. The modular architecture separates user interaction, application logic, data management, and storage.

This design makes the project suitable for demonstrating **C++ programming, Object-Oriented Programming, file handling, data validation, and basic software architecture**.
