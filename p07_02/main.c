/*
 ============================================================================
 Name        : 07_02.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Passing variables to functions, Ansi-style
 	 	 	   This is an example of functional programming, in which the
 	 	 	   user interacts with an ATM to debit or credit an account.
 	 	 	   The program performs 3 transactions. The last two transactions
 	 	 	   also include adding a monetary gift to the account.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "account.h"



int main(void) {
	initializeAccount();
	getBalance();
	//Perform first transaction
	askCustomer();
	updateAccount(amount);
	getBalance();
	//Perform second transaction
	askCustomer();
	updateAccount(amount);
	addGift(5.0);
	getBalance();
	//Perform third transaction
	askCustomer();
	updateAccount(amount);
	addGift(2.0);
	getBalance();
	thankYou();
	return EXIT_SUCCESS;
}




