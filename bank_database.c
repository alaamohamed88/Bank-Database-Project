#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "bank_database.h"
#define NO_CUSTOMERS 3
extern char arr_counter;
extern customer arr_customers[NO_CUSTOMERS];    //declaring an array of structures and making the array visible for this file
char loop_counter;       //a counter for loops

void create_new()
{
    //creating a flag to indicate if the ID is unique or not, its default value is 0
    unsigned char ID_is_unique = 0;

    customer new_customer; //creating a temporary struct to hold all the new data in it
    printf("enter the name of the customer no.%i: ",arr_counter+1);
    fflush(stdin);      //clearing the input buffer
    gets(new_customer.name);   //storing the name of new customer

    printf("enter the ID of the customer no.%i: ",arr_counter+1);
    scanf("%d",&(new_customer.id));     //storing the ID of new customer

    //checking if the ID is a valid value, the loop will end in case of ID is a valid
    while (new_customer.id <= 0)
    {
        printf("ID cannot be a negative number or equal to zero, Please enter a valid ID: ");
        scanf("%d",&(new_customer.id));
    }

    //checking if the ID is a unique value
    loop_counter=0;
    while (ID_is_unique == 0 || loop_counter<NO_CUSTOMERS)
    {
        if (new_customer.id == arr_customers[loop_counter].id)

            {
                printf("This ID is not a unique one, Please enter a valid ID: ");
                scanf("%d",&(new_customer.id));
                continue;
            }
        else
        {
         ID_is_unique=1;
         loop_counter++;
        }
    }
    //storing the type of account "Debit or Credit"
    char account_t;
    printf("enter the type of account for customer no.%u:\n<Press 1 for debit> or <Press 2 for credit>: ",arr_counter+1);
    scanf("%i",&(account_t));

label:if(account_t==1)
    {
        strcpy(new_customer.account_type,"debit");
    }
    else if(account_t==2)
    {
        strcpy(new_customer.account_type,"credit");
    }
    else
    {
        // checking if the entered choice is valid or not
        while ( (account_t != 1) && (account_t != 2) )
        {
            printf("Please enter a valid choice for account type\n");
            printf("<Press 1 for debit> or <Press 2 for credit>: ");
            scanf("%i",&(account_t));
        }
        goto label;
    }

    //storing the amount of cash
    printf("enter the amount of cash for the customer no.%u: ",arr_counter+1);
    scanf("%lf",&(new_customer.cash));
    //checking if the amount of cash is valid
    while (new_customer.cash <0)
    {
        printf("Amount of cash cannot be a negative number, Please enter a valid number: ");
        scanf("%lf",&(new_customer.cash));
    }
    arr_customers[arr_counter]=new_customer; //copying all the data from temporary struct to array of structs
    arr_counter++;      //increment the counter of customers by one
    printf("\n\n");
}

void edit_customer()
{
    char index;             //stores the index of edited account in array of structs
    signed int ID_edit;     //the ID of the account required to be edited
ID_label: printf("Please enter the ID of the account you want to edit: ");
    scanf("%i",&ID_edit);
    index = 0;
    //check if the ID is valid
    while (ID_edit <= 0)
    {
        printf("ID cannot be a negative number or equal to zero, please enter a valid ID: ");
        scanf("%i",&ID_edit);
    }

    //check if the ID exists in the database
    char ID_is_found=0; //a flag to determine whether ID is found or not, its default value is 0
    for (index;index<NO_CUSTOMERS;index++)
    {
        if (ID_edit == arr_customers[index].id)
            {
                printf("\n\nID is found in the database!\n");
                ID_is_found = 1;
                break;
            }
    }
    //if the ID is not found, ask to enter it again
    if (ID_is_found == 0)
        {
            printf("Please enter an existing ID\n");
            goto ID_label;
        }

    //storing the new name of customer
    printf("Please enter the new name of customer no.%i: ",index+1);
    fflush(stdin);
    gets(arr_customers[index].name);

    //storing the new type of account "Debit or Credit"
    char account_t;
    printf("enter the new type of account for customer no.%i:\n<Press 1 for debit> or <Press 2 for credit> : ",index+1);
    scanf("%i",&(account_t));

account_l: if(account_t==1)
    {
        strcpy(arr_customers[index].account_type,"debit");
    }
    else if(account_t==2)
    {
        strcpy(arr_customers[index].account_type,"credit");
    }
    else
    {
        // checking if the entered choice is valid or not
        while ( (account_t != 1) && (account_t != 2) )
        {
            printf("Please enter a valid choice for account type\n");
            printf("<Press 1 for debit> or <Press 2 for credit> :");
            scanf("%i",&(account_t));
        }
        goto account_l;
    }

    //storing the new amount of cash
    printf("enter the new amount of cash for the customer no.%i:",index+1);
    scanf("%lf",&(arr_customers[index].cash));
    //checking if the amount of cash is valid
    while (arr_customers[index].cash <0)
    {
        printf("Amount of cash cannot be a negative number, Please enter a valid number: ");
        scanf("%lf",&(arr_customers[index].cash));
    }
    printf("\n\n");
}

void print_data()
{
    char index;              //stores the index of the account required to be printed in array of structs
    signed int ID_print;     //the ID of the account required to be printed
ID_label: printf("Please enter the ID of the account you want to print: ");
    scanf("%i",&ID_print);
    index = 0;

    //check if the ID is valid
    while (ID_print <= 0)
    {
        printf("ID cannot be a negative number or equal to zero, please enter a valid ID: ");
        scanf("%i",&ID_print);
    }

    //check if the ID exists in the database
    char ID_is_found=0; //a flag to determine whether ID is found or not, its default value is 0
    for (index;index<NO_CUSTOMERS;index++)
    {
        if (ID_print == arr_customers[index].id)
            {
                printf("\n\nID is found in the database!\n");
                ID_is_found = 1;
                break;
            }
    }
    //if the ID is not found, ask to enter it again
    if (ID_is_found == 0)
        {
            printf("Please enter an existing ID\n");
            goto ID_label;
        }
    //Printing the data of the account
    printf("Name of customer no.%i :%s\n",index+1,arr_customers[index].name);
    printf("ID of customer no.%i :%i\n",index+1,arr_customers[index].id);
    printf("Account type of customer no.%i :%s\n",index+1,arr_customers[index].account_type);
    printf("Amount of cash for customer no.%i :%lf\n",index+1,arr_customers[index].cash);
    printf("\n\n");
}

void transfer()
{
    char index_s,index_d;             //stores the indeces of source and destination accounts in array of structs
    signed int ID_source,ID_dest;     //the IDs of source and destination accounts

    //Storing the ID of source account and checking its validity:
IDsource_label: printf("Please enter the ID of the account you want to transfer money from: ");
    scanf("%i",&ID_source);
    index_s = 0;
    //check if the ID of the source account is valid
    while (ID_source <= 0)
    {
        printf("ID cannot be a negative number or equal to zero, please enter a valid ID: ");
        scanf("%i",&ID_source);
    }

    //check if the ID of source account exists in the database
    char IDsource_is_found=0; //a flag to determine whether source ID is found or not, its default value is 0
    for (index_s;index_s<NO_CUSTOMERS;index_s++)
    {
        if (ID_source == arr_customers[index_s].id)
            {
                printf("\n\nID is found in the database!\n");
                IDsource_is_found = 1;
                break;
            }
    }
    //if the source ID is not found, ask to enter it again
    if (IDsource_is_found == 0)
        {
            printf("\nPlease enter an existing ID\n");
            goto IDsource_label;
        }

    //Storing the ID of destination account and checking its validity:
IDdest_label: printf("Please enter the ID of the account you want to transfer money to it: ");
    scanf("%i",&ID_dest);
    index_d = 0;
    //check if the ID of the destination account is valid
    while (ID_dest <= 0)
    {
        printf("ID cannot be a negative number or equal to zero, please enter a valid ID: ");
        scanf("%i",&ID_dest);
    }

    //check if the ID of destination account exists in the database
    char IDdest_is_found=0; //a flag to determine whether destination ID is found or not, its default value is 0
    for (index_d;index_d<NO_CUSTOMERS;index_d++)
    {
        if (ID_dest == arr_customers[index_d].id)
            {
                printf("\n\nID is found in the database!\n");
                IDdest_is_found = 1;
                break;
            }
    }
    //if the destination ID is not found, ask to enter it again
    if (IDdest_is_found == 0)
        {
            printf("\nPlease enter an existing ID\n");
            goto IDdest_label;
        }

    //transfering money:
    double transferred_money=0;     //a variable to store the required amount of money to be transfered, initially equals zero
    printf("Enter the value of the money required to be transfered: ");
    scanf("%lf",&transferred_money);

    //checking if the transfered money is a valid value
    while(transferred_money<0)
    {
        printf("\nTransfered money cannot be a negative value or equal to zero, Try again\n");
        printf("Enter the value of the money required to be transfered: ");
        scanf("%lf",&transferred_money);
    }

    //checking if the source account have enough balance to transfer the required amount of cash
    while(arr_customers[index_s].cash<transferred_money)
    {
        printf("You don't have enough balance, Try again\n\n");
        printf("Enter the value of the money required to be transfered: ");
        scanf("%lf",&transferred_money);
    }

    //Successful transfer of money
    arr_customers[index_s].cash -= transferred_money;
    arr_customers[index_d].cash += transferred_money;
    printf("\nSuccessful transfer!\n\n");
}
