# Testing

## Bank Account Management System

Testing is an important part of the **Bank Account Management System** to ensure that all banking operations work correctly and that invalid inputs are handled properly.

The system is tested using different valid, invalid, and boundary-value inputs.

---

## 1. Testing Objectives

The main objectives of testing are:

* Verify that all major banking operations work correctly.
* Ensure account information is stored and retrieved correctly.
* Verify deposit and withdrawal calculations.
* Check that invalid inputs are handled properly.
* Ensure insufficient-balance withdrawals are rejected.
* Verify that account data remains available after restarting the program.
* Identify and fix runtime and logical errors.

---

# 2. Testing Approach

The project uses the following testing approaches:

### Functional Testing

Checks whether each feature performs the expected operation.

Examples:

* Account creation
* Account search
* Deposit
* Withdrawal
* Balance checking
* Account data storage

### Input Validation Testing

Checks how the system responds to invalid user input.

Examples:

* Negative amount
* Zero amount
* Invalid account number
* Invalid menu option
* Withdrawal greater than balance

### Boundary Testing

Tests values at the limits of acceptable input.

Examples:

* Deposit of ₹0
* Deposit of ₹1
* Withdrawal equal to the available balance
* Withdrawal slightly greater than the available balance

### File Handling Testing

Checks whether account information can be correctly written to and read from files.

---

# 3. Test Cases

## 3.1 Account Creation Testing

| Test ID | Test Case                                 | Input                     | Expected Result                      | Status |
| ------- | ----------------------------------------- | ------------------------- | ------------------------------------ | ------ |
| TC-01   | Create valid account                      | Valid account details     | Account created successfully         | Pass   |
| TC-02   | Create account with valid initial balance | Balance > 0               | Account created with correct balance | Pass   |
| TC-03   | Enter invalid account information         | Invalid input             | Appropriate error message            | Pass   |
| TC-04   | Create multiple accounts                  | Different account details | Accounts stored separately           | Pass   |

---

## 3.2 Account Search Testing

| Test ID | Test Case                   | Input                         | Expected Result                   | Status |
| ------- | --------------------------- | ----------------------------- | --------------------------------- | ------ |
| TC-05   | Search existing account     | Valid account number          | Correct account details displayed | Pass   |
| TC-06   | Search non-existing account | Invalid account number        | "Account not found" message       | Pass   |
| TC-07   | Search using invalid input  | Invalid account number format | Input handled correctly           | Pass   |

---

# 4. Deposit Testing

| Test ID | Test Case                         | Input                  | Expected Result             | Status |
| ------- | --------------------------------- | ---------------------- | --------------------------- | ------ |
| TC-08   | Deposit valid amount              | ₹1,000                 | Balance increases by ₹1,000 | Pass   |
| TC-09   | Deposit zero                      | ₹0                     | Deposit rejected            | Pass   |
| TC-10   | Deposit negative amount           | -₹500                  | Deposit rejected            | Pass   |
| TC-11   | Deposit into non-existing account | Invalid account number | Operation rejected          | Pass   |

### Example

Initial balance:

```text
₹5,000
```

Deposit:

```text
₹2,000
```

Expected balance:

```text
₹7,000
```

---

# 5. Withdrawal Testing

| Test ID | Test Case                          | Input                  | Expected Result                             | Status |
| ------- | ---------------------------------- | ---------------------- | ------------------------------------------- | ------ |
| TC-12   | Withdraw valid amount              | ₹1,000                 | Balance decreases by ₹1,000                 | Pass   |
| TC-13   | Withdraw zero                      | ₹0                     | Withdrawal rejected                         | Pass   |
| TC-14   | Withdraw negative amount           | -₹500                  | Withdrawal rejected                         | Pass   |
| TC-15   | Withdraw amount equal to balance   | Full balance           | Transaction accepted and balance becomes ₹0 | Pass   |
| TC-16   | Withdraw more than balance         | Amount > balance       | Withdrawal rejected                         | Pass   |
| TC-17   | Withdraw from non-existing account | Invalid account number | Operation rejected                          | Pass   |

### Example

Initial balance:

```text
₹10,000
```

Withdrawal:

```text
₹3,000
```

Expected balance:

```text
₹7,000
```

---

# 6. Balance Checking Testing

| Test ID | Test Case                      | Input                  | Expected Result                | Status |
| ------- | ------------------------------ | ---------------------- | ------------------------------ | ------ |
| TC-18   | Check existing account balance | Valid account number   | Correct balance displayed      | Pass   |
| TC-19   | Check non-existing account     | Invalid account number | Account not found message      | Pass   |
| TC-20   | Check zero balance account     | Valid account          | ₹0 balance displayed correctly | Pass   |

---

# 7. File Handling Testing

File handling is tested to ensure that account information is properly stored and retrieved.

| Test ID | Test Case                | Expected Result                         | Status |
| ------- | ------------------------ | --------------------------------------- | ------ |
| TC-21   | Save account information | Account data stored successfully        | Pass   |
| TC-22   | Read account information | Stored data retrieved correctly         | Pass   |
| TC-23   | Restart application      | Previous account data remains available | Pass   |
| TC-24   | Update account balance   | Updated balance saved correctly         | Pass   |
| TC-25   | File unavailable         | Appropriate error handled               | Pass   |

---

# 8. Menu Testing

The main menu is tested to verify that each option performs the correct operation.

Example menu:

```text
================================
      BANK ACCOUNT SYSTEM
================================

1. Create Account
2. View Account
3. Deposit Money
4. Withdraw Money
5. Check Balance
6. Exit

Enter your choice:
```

| Test ID | Input          | Expected Result                | Status |
| ------- | -------------- | ------------------------------ | ------ |
| TC-26   | 1              | Create Account operation opens | Pass   |
| TC-27   | 2              | View Account operation opens   | Pass   |
| TC-28   | 3              | Deposit operation opens        | Pass   |
| TC-29   | 4              | Withdrawal operation opens     | Pass   |
| TC-30   | 5              | Balance operation opens        | Pass   |
| TC-31   | 6              | Program exits safely           | Pass   |
| TC-32   | Invalid option | Error message displayed        | Pass   |

---

# 9. Boundary Value Testing

Boundary values are tested to verify that the system handles limits correctly.

| Test ID | Boundary Condition          | Expected Result                 | Status |
| ------- | --------------------------- | ------------------------------- | ------ |
| TC-33   | Deposit ₹0                  | Reject transaction              | Pass   |
| TC-34   | Deposit ₹1                  | Accept transaction              | Pass   |
| TC-35   | Withdrawal ₹0               | Reject transaction              | Pass   |
| TC-36   | Withdrawal ₹1               | Accept if balance is sufficient | Pass   |
| TC-37   | Withdrawal equal to balance | Accept transaction              | Pass   |
| TC-38   | Withdrawal balance + ₹1     | Reject transaction              | Pass   |

---

# 10. Integration Testing

Integration testing verifies that different modules work correctly together.

### Example: Account + Deposit + File Storage

```text
Create Account
      |
      v
Account Stored
      |
      v
Deposit Money
      |
      v
Balance Updated
      |
      v
Updated Data Saved
      |
      v
Restart Program
      |
      v
Updated Balance Retrieved
```

The expected result is that the updated balance remains available after restarting the application.

---

# 11. System Testing

The complete application is tested as a single system.

A typical test scenario:

```text
1. Start application
        ↓
2. Create account
        ↓
3. Save account
        ↓
4. Search account
        ↓
5. Deposit money
        ↓
6. Check balance
        ↓
7. Withdraw money
        ↓
8. Check updated balance
        ↓
9. Exit application
        ↓
10. Restart application
        ↓
11. Verify stored account data
```

The system should complete the complete workflow without errors.

---

# 12. Error Handling Testing

The following errors are tested:

```text
Invalid account number
Invalid menu option
Negative deposit amount
Negative withdrawal amount
Zero deposit
Zero withdrawal
Insufficient balance
Missing account
Invalid input
File access error
```

The system should display a meaningful message instead of terminating unexpectedly.

---

# 13. Performance Testing

Since this is a lightweight console-based application, performance requirements are relatively low.

The following areas can be checked:

* Time required to search for an account
* Time required to read account records
* Time required to save updated information
* Application startup time
* Application response time after user input

For a small number of accounts, the system should respond almost immediately.

---

# 14. Security Testing

Basic security checks can include:

* Preventing unauthorized account access
* Validating account numbers
* Validating transaction amounts
* Preventing invalid withdrawals
* Protecting sensitive account information

For future versions, authentication, password/PIN protection, encryption, and database security can be added.

---

# 15. Test Environment

| Component            | Details                     |
| -------------------- | --------------------------- |
| Programming Language | C++                         |
| Compiler             | GCC / MinGW / G++           |
| IDE                  | Visual Studio Code          |
| Operating System     | Windows / Linux             |
| Storage              | Local File System           |
| Testing Type         | Manual + Functional Testing |

---

# 16. Testing Result

The testing process verifies that the major functions of the **Bank Account Management System** operate as expected.

The following areas are successfully tested:

* Account creation
* Account searching
* Account information display
* Deposit operations
* Withdrawal operations
* Balance checking
* File storage
* Data retrieval
* Input validation
* Error handling
* Menu navigation

The application is suitable as an educational banking simulation and can be further tested after adding advanced features such as authentication, fund transfer, transaction history, and database integration.

---

# 17. Conclusion

Testing helps ensure that the **Bank Account Management System** is reliable, functional, and easy to use. Different test cases covering normal operations, invalid inputs, boundary conditions, file handling, and complete system workflows help identify potential errors.

The current testing approach provides a foundation for improving the application and maintaining its reliability as additional features are introduced.
