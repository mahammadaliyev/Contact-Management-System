#ifndef CONTACTMANAGEMENTSYS_AF1_H
#define CONTACTMANAGEMENTSYS_AF1_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
void addContact(FILE *fp);
void showContact(FILE *fp);
size_t numberOfContacts(FILE *fp);
int searchContact(char a[], FILE *fp);
void scanInt (int *a);
int validEmail(char test[]);
int validBirth(int birth);
const char *to_Lower(char str[]);
#define FILENAME "contacts.bin"
#define INITIAL_SIZE_FOR_ARRAY 10

typedef struct contactname {

    char name[15];
    char surname[15];

} ContactName;

typedef struct address {

    char zip[10];
    char country[15];
    char city[15];
    char street[15];

} Address;

typedef struct contact {

    ContactName name;
    Address address;
    int number;
    char email[50];
    int birthday;
    char contactAdded[64];
//    int deleted;
//    int id;

} Contact;



typedef enum month {

    January = 1,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December

} Month;

void printContact(Contact c);


#endif //CONTACTMANAGEMENTSYS_AF1_H

