#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "bank_database.h"
#define NO_CUSTOMERS 3
char arr_counter=0;
customer arr_customers[NO_CUSTOMERS];
int main()
{
    char choice;
    while (1)
    {
       printf("1-Create a new account\t\t<press 1 to choose this choice>\n");
       printf("2-Edit an account\t\t<press 2 to choose this choice>\n");
       printf("3-Print details of an account\t\t<press 3 to choose this choice>\n");
       printf("4-Transfer money from an account to another\t<press 4 to choose this choice>\n");
       printf("5-Delete an account\t\t<press 5 to choose this choice>\n");
       printf("6-exit\t\t<press 6 to choose this choice>\n\n");
       printf("Please choose your operation: ");
       fflush(stdin);
       scanf("%c",&choice);
       switch (choice)
       {
            case '1':
                {
                    if (arr_counter>=NO_CUSTOMERS)
                    {
                        printf("the maximum number of customers is %i so you can't add anymore\n",arr_counter);
                        break ;
                    }
                    create_new();
                    break;
                }
            case '2':
                {
                    if (arr_counter==0)
                    {
                        printf("there are no customers in database.\n\n");
                        break ;
                    }
                    edit_customer();
                    break;
                }
            case '3':
                {
                    if (arr_counter==0)
                    {
                        printf("there are no customers in database.\n\n");
                        break ;
                    }
                    print_data();
                    break;
                }
            case '4':
                {
                    if (arr_counter<=1)
                    {
                        printf("Cannot transfer money when there is one or less customers in database.\n\n");
                        break ;
                    }
                    transfer();
                    break;
                }
            case '5':
                {
                    //delete_data();
                    break;
                }
            case '6':
                {
                   printf("\nThank you!\n");
                   return 0;
                }

            default:
                {
                    printf("\nPlease enter a valid choice\n\n");
                    break;
                }
       }
    }
}
