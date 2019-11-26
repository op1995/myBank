#include <stdio.h>
#include "myBank.h"

int main(){
    int keepWorking=1;
    char operator='a'; //initing to a value, doesn't matter which.
    while(keepWorking){
        printf("Transaction type?: ");
        if(scanf(" %c", &operator)==1){
            
            switch(operator)
            {
                case 'O':
                    Open();
                    break;

                case 'B':
                    Biror();
                    break;
                
                case 'D':
                    Deposit();
                    break;
                
                case 'W':
                    Withdrawal();
                    break;
                
                case 'C':
                    Close();
                    break;
                
                case 'I':
                    Interest();
                    break;
                
                case 'P':
                    Printing();
                    break;
                
                case 'E':
                    Exiting();
                    keepWorking = 0;
                    break;
                
                default:
                    printf("Invalid input, please try again.\n");
            }


        }
        else{
            printf("Invalid input, please try agian.\n");
        }

    }

    return 0;

}
