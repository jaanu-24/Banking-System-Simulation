#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Account *head = NULL;

Transaction* create_transaction(const char *type, int amount)
{
    Transaction *t = malloc(sizeof(Transaction));
    strcpy(t->type, type);
    t->amount = amount;
    t->link = NULL;
    return t;
}

Account* find_account(int acc_no)
{
    Account *temp = head;
    while (temp) {
        if (temp->acc_no == acc_no)
            return temp;
        temp = temp->link;
    }
    return NULL;
}

void add_transaction(Account *acc, const char *type, int amount)
{
    Transaction *new_t = create_transaction(type, amount);
    new_t->link = acc->history;
    acc->history = new_t;
}

void create_account()
{
    Account *new_acc = malloc(sizeof(Account));
    printf("Enter Account Number: ");
    scanf("%d", &new_acc->acc_no);
    printf("Enter Name: ");
    scanf("%s", new_acc->name);

    new_acc->balance = 0;
    new_acc->history = NULL;
    new_acc->link = head;
    head = new_acc;

    printf("Account created successfully!\n");
}

void deposit()
{
    int acc_no, amount;
    printf("Enter Account Number: ");
    scanf("%d", &acc_no);
    Account *acc = find_account(acc_no);
    if (!acc) {
        printf("Account not found!\n");
        return;
    }
    printf("Enter amount to deposit: ");
    scanf("%d", &amount);
    acc->balance += amount;
    add_transaction(acc, "Deposit", amount);
    printf("Deposit successful. New Balance: %d\n", acc->balance);
}

void withdraw()
{
    int acc_no, amount;
    printf("Enter Account Number: ");
    scanf("%d", &acc_no);
    Account *acc = find_account(acc_no);
    if (!acc) {
        printf("Account not found!\n");
        return;
    }
    printf("Enter amount to withdraw: ");
    scanf("%d", &amount);
    if (amount > acc->balance) {
        printf("Insufficient Balance!\n");
        return;
    }
    acc->balance -= amount;
    add_transaction(acc, "Withdraw", amount);
    printf("Withdrawal successful. New Balance: %d\n", acc->balance);
}

void display_account()
{
    int acc_no;
    printf("Enter Account Number: ");
    scanf("%d", &acc_no);
    Account *acc = find_account(acc_no);
    if (!acc) {
        printf("Account not found!\n");
        return;
    }
    printf("\nAccount Number: %d\n", acc->acc_no);
    printf("Name: %s\n", acc->name);
    printf("Balance: %d\n", acc->balance);
}

void display_transaction_history()
{
    int acc_no;
    printf("Enter Account Number: ");
    scanf("%d", &acc_no);
    Account *acc = find_account(acc_no);
    if (!acc) {
        printf("Account not found!\n");
        return;
    }

    Transaction *temp = acc->history;
    printf("Transaction History:\n");
    while (temp) {
        printf("%s: %d\n", temp->type, temp->amount);
        temp = temp->link;
    }
}
