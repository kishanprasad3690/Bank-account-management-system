# System Design & Architecture

## 1. System Architecture Flow
The application follows a clean, modular architecture separating the user interface, business logic, and data persistence:
* **User (Console):** Interacts with the application via the Main Menu.
* **OOP Classes (`BankSystem`, `BankAccount`):** Processes business logic and banking operations (Create, View, Deposit, Withdraw, etc.).
* **STL Containers:** Holds the state of the application in memory during runtime using `vector`, `map`, and `set`.
* **File Handling:** The `FileManager` handles writing to and reading from `accounts.txt` and `transactions.txt` to ensure data persistence on the local disk.

```text
  ┌───────────┐         ┌───────────────────────┐        ┌──────────────────────────────┐
  │   User    │───────▶│    Main Menu / UI     │───────▶│       Bank Operations        │
  │ (Console) │         │   (C++ Application)   │        │  (Create / View / Search /   │
  └───────────┘         └───────────┬───────────┘        │ Deposit / Withdraw / Reports)│
                                    │                    └──────────────────────────────┘
                                    ▼
                       ┌───────────────────────┐
                       │      OOP Classes      │
                       │     (BankAccount,     │
                       │      BankSystem)      │
                       └─────┬───────────┬─────┘
                             │           │
               ┌─────────────┘           └─────────────┐
               ▼                                       ▼
 ┌───────────────────────────┐           ┌───────────────────────────┐
 │      STL Containers       │           │       File Handling       │
 │(vector, map, set,         │           │      (accounts.txt,       │
 │         algorithm)        │           │     transactions.txt)     │
 └─────────────┬─────────────┘           └─────────────┬─────────────┘
               │                                       │
               └─────────────┐           ┌─────────────┘
                             ▼           ▼
                       ┌───────────────────────┐
                       │      Data Files       │
                       │   (Stored on Disk)    │
                       └───────────────────────┘
```

## 2. Major OOP Components (Class Entities)
The system is divided into four primary C++ classes:

### `BankSystem` (Main Controller)
* **Responsibility:** Acts as the central system manager. Renders the main menu, captures user inputs, and orchestrates banking operations.
* **Relationships:** Manages `BankAccount` and `Transaction` objects and delegates file I/O tasks to the `FileManager`.

### `BankAccount`
* **Responsibility:** An entity class representing a single bank account. 
* **Attributes:** `accountNumber` (string), `customerName` (string), `accountType` (string), and `balance` (double).
* **Methods:** Encapsulates localized logic such as `deposit()`, `withdraw()`, and `checkBalance()`.

### `Transaction`
* **Responsibility:** An entity class that records the details of a single financial movement.
* **Attributes:** `id` (string), `type` (string), `amount` (double), and `date` (string).

### `FileManager`
* **Responsibility:** A dedicated utility class strictly for handling `<fstream>` operations to enforce the Single Responsibility Principle.
* **Methods:** `saveAccounts()`, `loadAccounts()`, `saveTransactions()`, and `loadTransactions()`.

## 3. STL (Standard Template Library) Containers
The system heavily utilizes the C++ STL to manage memory and logic efficiently:
* **`std::vector`**: The primary container used to store arrays of `BankAccount` and `Transaction` objects.
* **`std::map`**: Used to map unique `accountNumber` strings to `balance` doubles for rapid balance lookups without iterating through the entire vector.
* **`std::set`**: Used to store unique `accountType` strings (e.g., ensuring "Savings" and "Current" are only listed once) for system reports.
* **`<algorithm>`**: Utilizes functions like `std::find_if` to search and filter accounts efficiently by Account Number.

## 4. File Format & Persistence
Data is saved persistently to flat text files in a comma-separated format.

* **`accounts.txt` format:** 
  `accountNumber,customerName,accountType,balance,creationDate`
  *(Example: `1001,JohnDoe,savings,5000.00,2025-06-01`)

* **`transactions.txt` format:**
  `accountNumber,id,type,amount,date,time`
  *(Example: `1001,1,DEPOSIT,2000.00,2025-06-02,09:30:00`)* 

## 5. UML Class Diagrams
```text
 ┌───────────────────────────┐      uses       ┌──────────────────────────────────┐
 │        BankAccount        │< - - - - - - - -│            BankSystem            │
 ├───────────────────────────┤                 ├──────────────────────────────────┤
 │ - accountNumber : string  │                 │ - accounts : vector<BankAccount> │
 │ - customerName : string   │                 │ - transactions : vector<string>  │
 │ - accountType : string    │                 ├──────────────────────────────────┤
 │ - balance : double        │                 │ + createAccount()                │
 ├───────────────────────────┤                 │ + viewAccount()                  │
 │ + deposit(amount)         │                 │ + searchAccount()                │
 │ + withdraw(amount)        │                 │ + updateAccount()                │
 │ + checkBalance()          │                 │ + deleteAccount()                │
 │ + display()               │                 │ + deposit()                      │
 └─────────────┬─────────────┘                 │ + withdraw()                     │
               │                               │ + saveToFile()                   │
               │ uses                          └────────────────┬─────────────────┘
               │                                                │
               ▼                                                ▼
 ┌───────────────────────────┐      uses       ┌──────────────────────────────────┐
 │        FileManager        │- - - - - - - - >│           Transaction            │
 ├───────────────────────────┤                 ├──────────────────────────────────┤
 │ + saveAccounts()          │                 │ - id : string                    │
 │ + loadAccounts()          │                 │ - type : string                  │
 │ + saveTransactions()      │                 │ - amount : double                │
 │ + loadTransactions()      │                 │ - date : string                  │
 └───────────────────────────┘                 └──────────────────────────────────┘
```
### Sequence Diagram (Scenario: Depositing Money)
The following sequence demonstrates how the system objects interact during a standard deposit operation:

```text
       User               BankSystem             BankAccount           FileManager
     (Console)           (Controller)             (Entity)              (Utility)
         │                     │                      │                     │
         │ 1. Select "Deposit" │                      │                     │
         │────────────────────▶│                      │                     │
         │                     │                      │                     │
         │ 2. Prompt for ID    │                      │                     │
         │◀────────────────────│                      │                     │
         │                     │                      │                     │
         │ 3. Enter ID & Amt   │                      │                     │
         │────────────────────▶│                      │                     │
         │                     │ 4. Search accounts   │                     │
         │                     │─────────────────────▶│                     │
         │                     │                      │                     │
         │                     │ 5. deposit(amount)   │                     │
         │                     │─────────────────────▶│                     │
         │                     │                      │                     │
         │                     │ 6. return success    │                     │
         │                     │◀─────────────────────│                     │
         │                     │                      │                     │
         │                     │ 7. saveAccounts()                          │
         │                     │───────────────────────────────────────────▶│
         │                     │                      │                     │
         │                     │ 8. saveTransactions()                      │
         │                     │───────────────────────────────────────────▶│
         │                     │                      │                     │
         │ 9. Display New Bal  │                      │                     │
         │◀────────────────────│                      │                     │
         │                     │                      │                     │

```
## State Machine Diagram

This diagram illustrates the states a single account goes through during its lifetime:
```text
                             ● [Start / Uninitialized]
                             │
                             │ createAccount()
                             ▼
                   ┌───────────────────┐
                   │                   │
                   │                   │◀─────── deposit() ─────────┐
                   │      ACTIVE       │                            │
                   │                   │◀─ withdraw() [Bal >= Amt] ─┤
                   │                   │                            │
                   └─────────┬─────────┘                            │
                             │   │                                  │
      deleteAccount()        │   │         withdraw() [Bal < Amt]   │
   [Condition: Bal == 0]     │   └──────────────────────────────────┘
                             ▼               (Transaction Fails,
                       ◎ [Deleted]             Stays in Active State)
```                       