#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int authenticateUser(char password_a[]){

    FILE *file;
    file = fopen("bank_user_data.txt","r");
    if(file == NULL){
        printf("Error while opening file.");
        return;
    }
    char password[40];
    fscanf(file,"%s",password);
    int check_authen_pass = strcmp(password_a,password);
    if(check_authen_pass == 0){
        return 1;
    }else{
        return 0;
    }
}

void deposit(float *amount, float *saved){
    *saved = *saved + *amount;

    FILE *file;
    file = fopen("saved_money.txt","w");
    if(file == NULL){
        printf("Error while opening file.");
        return;
    }

    fprintf(file,"%f",*saved);

    fclose(file);

}
void withdrawMoney(float *amount,float *saved){
    FILE *file;
    file = fopen("saved_money.txt","w");
    if(file == NULL){
        printf("Error while opening file.");
        return;
    }

    if((*saved) < (*amount)){
        printf("You have insufficient money in your account.");
    }else{
        *saved = *saved - *amount;
        fprintf(file,"%f",*saved);
        fclose(file);
        printf("\nSuccessfully Withdrawn!\n");
    }
}
float LoadAccount(){
    float saved_amount;
    FILE *file;
    file = fopen("saved_money.txt","r");
    if(file == NULL){
        printf("Error while opening file.");
        return;
    }

    fscanf(file,"%f",&saved_amount);

    fclose(file);
    return saved_amount;
}

int main(){
    int choice;
    char password[40];
    float saved_amount,amount;
    saved_amount = LoadAccount();

    printf("\n\n\t\tWELCOME TO MARSDWELLERS' BANK\n");
    printf("\t\t---------------------------------\n");
    do{
        printf("\n");
        printf("1. Diposite\n");
        printf("2. Withdraw\n");
        printf("3. Check Balance\n");
        printf("4. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter your PIN number: ");
                scanf("%s",password);
                if(authenticateUser(password)){
                    printf("Enter amount of money you want to deposit: ");
                    scanf("%f",&amount);
                    deposit(&amount,&saved_amount);
                    printf("Successfully Deposited!\n");
                }else{
                    printf("WrongPIN number.Try again!\n");
                }
                break;
            case 2:
                printf("Enter your PIN: ");
                scanf("%s",password);
                if(authenticateUser(password)){
                    printf("Enter amount of money you want to withdraw: ");
                    scanf("%f",&amount);
                    withdrawMoney(&amount,&saved_amount);
                }else{
                    printf("WrongPIN number.Try again!");
                }

                break;
            case 3:
                printf("Enter your PIN: ");
                scanf("%s",password);
                if(authenticateUser(password)){
                    printf("\nYour have $ %.3f",saved_amount);
                }else{
                    printf("WrongPIN number.Try again!");
                }

                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.Try again!");
        }
    }while(choice != 4);
    return 0 ;
}
