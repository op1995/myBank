#include "myBank.h"
#include <stdio.h>

double arr[arrayLength][arrayWidth] = {0};
int full = 0;
int nextAvilableAccount = 0;


void Open(){
	if(full==1){
		printf("Can't open an account as all 50 slots are occupied.\n");
		return;
	}

	double deposit = 0;
	printf("Initial deposit?: ");
	if(scanf("%lf",&deposit)==1){

		if(deposit<0){
			printf("A negative value was entered, which can not be used to open an account. A new account will not be opened.\n");
			return;
		}
		int temp = (deposit * 100);
		deposit = (double)temp/100;
		arr[0][nextAvilableAccount] = 1; //mark account as open
		arr[1][nextAvilableAccount] = deposit;
		printf("Your new account number is %d.\n", (nextAvilableAccount+NineHunderedAndOne));
		changeNextAccount();
	}
	else{printf("Illegal value entered for initial deposit! A new account was not opened!\n");}
} //end Open

void Biror(){
	int AN = 0; //Account Number
	printf("Account number?: ");
	if(scanf("%d",&AN)==1){
		AN = AN - NineHunderedAndOne;
		if(AN<firstArraySlot||AN>lastArraySlot){
			printf("Illegal account number! Will not check for remaining money in bank!\n");
			return;
		}
		if(arr[0][AN]==1){
			printf("The remaining amount in bank account %d is - %.2lf\n", AN+NineHunderedAndOne, arr[1][AN]);
		}
		else{
			printf("The requested account number is curently not active.\n");
		}
	}
	else{
		printf("Illegal value entered! Not checking for amount in bank account!\n");
		return;
	}
} //end Biror

void Deposit(){
	int AN = 0; //Account Number
	printf("Account number?: ");
	if(scanf("%d", &AN)==1){
		AN = AN - NineHunderedAndOne;
		if(AN<firstArraySlot||AN>lastArraySlot){
			printf("Illegal account number! Will not check for remaining money in bank!\n");
			return;
		}
		if(arr[0][AN]==0){
			printf("The requested account number is curently not active. Not depositing.\n");
			return;
		}

		double depoist_ammount = 0;
		printf("Amount?: ");
		if(scanf("%lf",&depoist_ammount)==1){
			if(depoist_ammount<0){
				printf("A negative value was entered as an amount to deposit. Such a value can't be deposited. Quiting the deposit process.\n");
				return;
			}

			int temp = (depoist_ammount * 100);
			depoist_ammount = (double)temp/100;
			arr[1][AN] = arr[1][AN] + depoist_ammount;
			printf("The new amount in the bank account %d is now: %.2lf\n", AN+NineHunderedAndOne, arr[1][AN]);
		}

		else{
			printf("Illegal value entered for amount to deposit! Not depositing.\n");
			return;
		}
	}
	else{
		printf("Illegal value entered for account number! Exiting deposit procedure.\n");
		return;
	}

}//end deposit

void Withdrawal(){
	int AN = 0; //Account Number
	printf("Account number?: ");
	if(scanf("%d", &AN)==1){
	AN = AN - NineHunderedAndOne;
	if(AN<firstArraySlot||AN>lastArraySlot){
		printf("Illegal account number!\n");
		return;
	}
	if(arr[0][AN]==0){
		printf("The requested account number is curently not active. Not continuing witht the withdrawl process.\n");
		return;
	}
	double withdrawlAmount = 0;
	printf("Amount?: ");
	if(scanf("%lf",&withdrawlAmount)==1){
		if(withdrawlAmount<0){
			printf("A negative value is illegal for this process. Not continuing witht the withdrawl process.\n");
			return;
		}
		if(arr[1][AN]>=withdrawlAmount){
			int temp = (withdrawlAmount * 100);
			withdrawlAmount = (double)temp/100;
			arr[1][AN] = arr[1][AN] - withdrawlAmount;
			printf("As you requested, from bank account %d, %.2lf was withdrawn.\nNew balance in the account is %.2lf\n", AN+NineHunderedAndOne, withdrawlAmount, arr[1][AN]);
		}
		else{
			printf("The ammount you asked to withdraw from the account is greater than the current balance in the requested account. Not withdrawing.\n");
			return;
		}
	}
	else{
		printf("Illegal value entered for withdrawl amount. Not continuing witht the withdrawl process.\n");
		return;
	}
	}
}//end withdrawl


void Close(){
	int AN = 0; //Account Number
	printf("Account number?: ");
	if(scanf("%d", &AN)==1){
	AN = AN - NineHunderedAndOne;
	if(AN<firstArraySlot||AN>lastArraySlot){
		printf("Illegal account number!\n");
		return;
	}
	if(arr[0][AN]==0){
		printf("The requested account number wasn't active. No changes were made.\n");
		return;
	}
	arr[0][AN] = 0;
	arr[1][AN] = 0;
	printf("As requested, account number %d was closed.\n", AN+NineHunderedAndOne);
	full = 0; //An account was removed. Therefore there is an avilable account, for sure.
	}

	else{
		printf("Illegal value entered for account number. Not continuing witht the account closing process.\n");
		return;
	}
}//end Close

void Interest(){
	double IR = 0; // Interest Rate
	printf("Interest rate?: ");
	if(scanf("%lf",&IR)==1){
		if(IR<0){
			printf("Can't add a negative interest.\n");
			return;
		}
		IR = IR/100;
		double multiply = 1+IR;
		int temp = 0;
		for(int i = 0; i<=49; i++){
			if(arr[0][i]==1){
				temp = ((arr[1][i] * multiply)*100);
				arr[1][i] = (double)temp/100;
			}
		}
	}
	else{
		printf("Illegal value entered for interset rate. Quitting the interest process.\n");
		return;
	}

}//end Interest

void Printing(){
	int somethingWasPrinted = 0;
	for(int i = 0; i<=49; i++){
		if(arr[0][i]==1){
			somethingWasPrinted=1;
			printf("The current balance in account number %d is - %.2lf.\n", i+NineHunderedAndOne, arr[1][i]);
		}
	}
	if(somethingWasPrinted){printf("Those were all the currently active accounts.\n");}
	else{printf("No accounts are currently active.\n");}
}//end Print

void Exiting(){
	for(int i = 0; i<=49; i++){
		if(arr[0][i]==1){
			arr[0][i]=0;
			arr[1][i]=0;
		}
	}
}//end Exit

void changeNextAccount(){
	int previousNextAccount = nextAvilableAccount;
	nextAvilableAccount+=1;
	if (nextAvilableAccount==50){nextAvilableAccount=0;}
	for(int i = nextAvilableAccount; i<50 ; i++){
		if(arr[0][i]==0){
			nextAvilableAccount = i;
			return;
		}

		if (i==previousNextAccount){ //made a full circle - no free acounts were found.
			full = 1;
			return;
		}

		if (i==49){i=0;}
	}
}

