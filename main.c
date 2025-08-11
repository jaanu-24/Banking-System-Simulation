/*                                                        main.c                                                            */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

int main()
{
	int choice;
	while (1)
	{
		printf("\n--- BANKING SYSTEM MENU ---\n");
		printf("1. Create Account\n");
		printf("2. Deposit\n");
		printf("3. Withdraw\n");
		printf("4. Display Account Info\n");
		printf("5. View Transaction History\n");
		printf("6. Exit\n");
		printf("Enter your choice : ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			create_account();
			break;
		case 2:
			deposit();
			break;
		case 3:
			withdraw();
			break;
		case 4:
			display_account();
			break;
		case 5:
			display_transaction_history();
			break;
		case 6:
			exit(0);
		default:
			printf("Invalid choice. Try again.\n");
		}
	}
	return 0;
}