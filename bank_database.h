#ifndef bank_database
#define bank_database
typedef struct customer_data
{
    double cash;
    signed int id;
    char name[50];
    char account_type[7];
}customer;
void create_new();
void edit_customer();
void print_data();
void transfer();
void delete_data();
#endif
