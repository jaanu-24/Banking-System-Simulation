/*                                                         header.h                                                         */

#ifndef HEADER_H
#define HEADER_H

typedef struct transaction
{
	char type[10];
	int amount;
	struct transaction *link;
} Transaction;

typedef struct account
{
	int acc_no;
	char name[50];
	int balance;
	Transaction *history;
	struct account *link;
} Account;

extern Account *head;

// FUNCTIONS

Transaction* create_transaction(const char *type, int amount);

Account* find_account(int acc_no);

void add_transaction(Account *acc, const char *type, int amount);

void create_account();

void deposit();

void withdraw();

void display_account();

void display_transaction_history();

#endif