# Banking System Simulation

## 📌 Overview
The **Banking System Simulation** is a C-based console application that models basic banking operations including account creation, deposits, withdrawals, and transaction history maintained via linked lists. The program is a lightweight simulation intended for learning data structures and transaction flow in a banking context.

---

## 🎯 Motivation
This project simulates real-world banking workflows to reinforce concepts of **data structures, memory management, and transaction integrity**. It provides a testbed to practice persistent data handling and structured programming.

---

## ⚙️ Features
- Create, view, and delete customer accounts
- Deposit and withdrawal transactions with balance validation
- Transaction history per account (timestamped entries)
- Account lookup by account number
- Persistent storage using file-based serialization

---

## 🛠️ Technologies Used
- **Programming Language:** C
- **Tools:** GCC Compiler, Makefile
- **Concepts:** Single Linked List, Stack (for undo/history), File I/O, Structured Programming

---

## 📐 System Architecture
[ CLI Input ] --> [ Account Manager ] --> [ Transaction Module ] --> [ File Storage ]
↑ ↓
[ Linked List (Accounts) ] [ Transaction History Files ]

---

## 🚀 How It Works
1. **Account Creation:** User provides name and initial deposit; system assigns a unique account number and appends account node to linked list.  
2. **Transactions:** Deposits and withdrawals update the account node and append an entry to that account’s transaction log.  
3. **Persistence:** On exit or after operations, account list and transaction logs are written to files for later retrieval.  
4. **History & Reporting:** Users can view transaction history for an account, which reads the corresponding log file.

---

## 📊 Example CLI Session
==== Banking System ====

Create Account

Deposit

Withdraw

Show Account

Transaction History

Exit

Enter choice: 1
Enter customer name: Priya Sharma
Initial deposit: 5000
Account created successfully. Account No: 1003

Enter choice: 2
Enter account no: 1003
Enter amount to deposit: 1500
Deposit successful. New Balance: 6500

---
