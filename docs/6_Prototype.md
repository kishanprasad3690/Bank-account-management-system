# Prototype

## Bank Account Management System

The prototype of the **Bank Account Management System** represents the basic working model of the application. It demonstrates the user interface, navigation flow, account management operations, and transaction workflow before further development or integration of advanced features.

The prototype is designed as a **console-based C++ application** with a simple menu-driven interface.

---

# 1. Prototype Objectives

The main objectives of the prototype are:

* Demonstrate the basic working of the banking system.
* Provide a simple and understandable user interface.
* Test the navigation between different banking operations.
* Demonstrate account creation and management.
* Demonstrate deposit and withdrawal operations.
* Display account balance and account information.
* Demonstrate file-based data storage.
* Provide a foundation for future improvements.

---

# 2. Prototype User Interface

The initial screen of the application provides a main menu.

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

The user selects an option by entering the corresponding number.

---

# 3. Create Account Prototype

When the user selects **Create Account**, the system asks for the required account information.

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

========================================
```

### Expected Functionality

The system should:

1. Accept account information.
2. Validate the entered data.
3. Create a new account.
4. Store the account information.
5. Display a confirmation message.

---

# 4. View Account Prototype

The user can search for and view account information.

```text
========================================
             VIEW ACCOUNT
========================================

Enter Account Number: 1001

Account Found!

----------------------------------------
Account Number : 1001
Account Holder : Kishan
Account Type   : Savings
Balance        : ₹5000
----------------------------------------
```

If the account does not exist:

```text
Enter Account Number: 9999

Account not found.
```

---

# 5. Deposit Money Prototype

The deposit operation allows the user to add money to an existing account.

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

### Prototype Flow

```text
Enter Account Number
        |
        v
Search Account
        |
        v
Account Found?
    /       \
  No         Yes
  |           |
 Error     Enter Amount
              |
              v
        Validate Amount
              |
              v
        Update Balance
              |
              v
        Save Account
              |
              v
      Display New Balance
```

---

# 6. Withdraw Money Prototype

The withdrawal operation allows the user to withdraw money from an account.

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

### Insufficient Balance

If the user tries to withdraw more than the available balance:

```text
Enter Withdrawal Amount: ₹10000

Transaction failed!

Reason:
Insufficient balance.
```

The system should not modify the account balance when the transaction fails.

---

# 7. Balance Checking Prototype

The user can check the current balance of an account.

```text
========================================
            CHECK BALANCE
========================================

Enter Account Number: 1001

Account Holder : Kishan
Account Number : 1001
Available Balance : ₹5500
```

---

# 8. File Storage Prototype

Account information is stored locally using C++ file handling.

```text
             C++ Application
                    |
                    v
             Account Object
                    |
                    v
             File Handling
                    |
                    v
             Account File
                    |
                    v
        Persistent Account Data
```

The purpose of file storage is to ensure that account information is available even after the application is closed and restarted.

---

# 9. Complete Prototype Flow

The complete prototype workflow is:

```text
                    START
                      |
                      v
              Display Main Menu
                      |
        +-------------+-------------+
        |             |             |
        v             v             v
   Create Account   View Account   Transactions
        |             |             |
        |             |       +-----+-----+
        |             |       |           |
        |             |       v           v
        |             |    Deposit     Withdraw
        |             |       |           |
        +-------------+-------+-----------+
                      |
                      v
                Check Balance
                      |
                      v
                 Save Data
                      |
                      v
                Return Menu
                      |
               +------+------+
               |             |
             Exit          Continue
               |             |
               v             |
              END <----------+
```

---

# 10. Prototype Data Model

A basic account record can contain:

```text
+--------------------------------+
|          Account               |
+--------------------------------+
| Account Number                 |
| Account Holder Name            |
| Account Type                   |
| Account Balance                |
+--------------------------------+
```

Example:

```text
Account Number : 1001
Account Holder : Kishan
Account Type   : Savings
Balance        : ₹5500
```

---

# 11. Prototype Navigation

The application follows a simple menu-based navigation structure.

```text
Main Menu
   |
   +-- Create Account
   |
   +-- View Account
   |
   +-- Deposit Money
   |
   +-- Withdraw Money
   |
   +-- Check Balance
   |
   +-- Exit
```

After completing an operation, the user can return to the main menu and select another operation.

---

# 12. Prototype Validation

The prototype includes basic validation to prevent incorrect transactions.

### Valid Inputs

```text
Account Number → Existing account
Deposit Amount → Greater than ₹0
Withdrawal Amount → Greater than ₹0
Withdrawal Amount → Less than or equal to balance
Menu Choice → Available option
```

### Invalid Inputs

```text
Negative deposit
Zero deposit
Negative withdrawal
Zero withdrawal
Withdrawal greater than balance
Non-existing account
Invalid menu option
```

---

# 13. Prototype Advantages

The prototype provides:

* Simple console-based interaction.
* Easy navigation.
* Basic account management.
* Basic transaction management.
* Persistent account data.
* Input validation.
* Easy testing and debugging.
* Simple architecture suitable for future expansion.

---

# 14. Future Prototype Enhancements

The prototype can be upgraded into a more advanced banking application by adding:

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

### Additional Banking Features

* Fund transfer
* Transaction history
* Account statement
* Multiple account types
* Interest calculation
* Admin panel
* Customer management
* Database connectivity
* GUI interface
* Encryption
* Online banking simulation

---

# 15. Prototype Conclusion

The **Bank Account Management System prototype** provides a basic but functional representation of a banking application using C++. It demonstrates the core workflow from account creation to banking transactions and data storage.

The prototype serves as the foundation for developing a more advanced system with improved security, database integration, graphical interfaces, and additional banking services.
