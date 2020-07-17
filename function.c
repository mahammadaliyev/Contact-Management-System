#include "function.h"

void addContact(FILE *fp) {

    Contact *newContact = NULL;
    int choice;

    fp = fopen(FILENAME, "ab");

    if (fp == NULL) {

        fprintf(stderr, "\nError opening file\n");

        exit (1);

    }

    printf("=======================\n");
    printf("=     ADD CONTACT     =\n");
    printf("=======================\n");

    do {

        newContact = (Contact *)malloc(sizeof(Contact));

        printf("Enter the name     : ");      scanf("%s", newContact->name.name);
        printf("Enter the surname  : ");      scanf("%s", newContact->name.surname);
        printf("Enter the number   : +994");  scanInt(&newContact->number);
        printf("Enter the country  : ");      scanf("%s", newContact->address.country);
        printf("Enter the city     : ");      scanf("%s", newContact->address.city);
        printf("Enter the street   : ");      scanf("%s", newContact->address.street);
        printf("Enter the zip      : ");      scanf("%s", newContact->address.zip);
        printf("Enter the email    : ");      scanf("%s", newContact->email);

        while(!validEmail(newContact->email)) {

            printf("Wrong input, please enter again\n");
            printf("Enter the email    : ");
            scanf("%s", newContact->email);

        }

        printf("Enter the birthday(DDMMYYYY) : ");
        scanInt(&newContact->birthday);

        while(!validBirth(newContact->birthday)) {

            printf("Wrong input, please enter again\n");
            printf("Enter the birthday(DDMMYYYY)    : ");
            scanInt(&newContact->birthday);

        }

//        newContact->id = rand();
//        newContact->deleted = 0;

        fwrite(newContact, sizeof(Contact), 1, fp);
        printf("Contact was successfully added!\n");

        free(newContact);

        printf("Enter 1, if you want to add more, otherwise 0: ");
        scanInt(&choice);

    } while(choice == 1);

    fclose(fp);

}

void showContact(FILE *fp) {

    Contact scontact;

    fp = fopen (FILENAME, "r");

    if (fp == NULL) {

        fprintf(stderr, "\nError opening file\n");

        exit (1);

    }

    int count = 1;

    printf("=======================\n");
    printf("=   LIST OF CONTACTS  =\n");
    printf("=======================\n");

    while(fread(&scontact, sizeof(Contact), 1, fp)) {

        printf("=======================\n");
        printf("=      CONTACT %d      =\n", count);
        printf("=======================\n");

        printContact(scontact);

        puts("");

        count++;

    }

    fclose (fp);

}



size_t numberOfContacts(FILE *fp) {

    fp = fopen(FILENAME, "rb");

    if (fp == NULL) {

        fprintf(stderr, "\nError opening file\n");

        exit (1);

    }

    fseek(fp, 0, SEEK_END);

    long size = ftell(fp);

    printf("Number of Contacts: %ld\n", size / sizeof(Contact));

    fclose(fp);

    return 0;
}

const char * to_Lower(char *str) {

    for(int i = 0; str[i]; i++) {

        str[i] = (char) tolower(str[i]);

    }

    return str;
}

void editContact(Contact *contactToEdit, int optionToChange, FILE *fp) {

    FILE *fp_temp;
    Contact *contact_s = (Contact *)malloc(sizeof(Contact));
    Contact *editedContact = (Contact *)malloc(sizeof(Contact));

    fp = fopen(FILENAME, "rb");

    if (fp == NULL) {

        fprintf(stderr, "\nError opening file\n");

        exit (1);

    }

    fp_temp = fopen("temp.bin", "wb");

    if (fp_temp == NULL) {

        fprintf(stderr, "\nError opening file\n");

        exit (1);

    }

    while(fread(contact_s, sizeof(Contact), 1, fp)) {

        if((strncmp(contactToEdit->name.name, contact_s->name.name, strlen(contactToEdit->name.name))) == 0 &&
           (strncmp(contactToEdit->name.surname, contact_s->name.surname, strlen(contactToEdit->name.surname))) == 0 &&
           (contactToEdit->number == contact_s->number)) {

            switch(optionToChange) {

                case 1:
                    strcpy(editedContact->name.surname, contactToEdit->name.surname);
                    strcpy(editedContact->address.country, contactToEdit->address.country);
                    strcpy(editedContact->address.city, contactToEdit->address.city);
                    strcpy(editedContact->address.street, contactToEdit->address.street);
                    strcpy(editedContact->address.zip, contactToEdit->address.zip);
                    strcpy(editedContact->email, contactToEdit->email);
                    editedContact->birthday = contactToEdit->birthday;
                    editedContact->number = contactToEdit->number;
                    printf("Enter new name: ");
                    scanf("%s", editedContact->name.name);
                    break;

                case 2:
                    strcpy(editedContact->name.name, contactToEdit->name.name);
                    strcpy(editedContact->address.country, contactToEdit->address.country);
                    strcpy(editedContact->address.city, contactToEdit->address.city);
                    strcpy(editedContact->address.street, contactToEdit->address.street);
                    strcpy(editedContact->address.zip, contactToEdit->address.zip);
                    strcpy(editedContact->email, contactToEdit->email);
                    editedContact->birthday = contactToEdit->birthday;
                    editedContact->number = contactToEdit->number;
                    printf("Enter new surname: ");
                    scanf("%s", editedContact->name.surname);
                    break;

                case 3:
                    strcpy(editedContact->name.name, contactToEdit->name.name);
                    strcpy(editedContact->name.surname, contactToEdit->name.surname);
                    strcpy(editedContact->address.country, contactToEdit->address.country);
                    strcpy(editedContact->address.city, contactToEdit->address.city);
                    strcpy(editedContact->address.street, contactToEdit->address.street);
                    strcpy(editedContact->address.zip, contactToEdit->address.zip);
                    strcpy(editedContact->email, contactToEdit->email);
                    editedContact->birthday = contactToEdit->birthday;
                    printf("Enter new number: +994");
                    scanf("%d", &editedContact->number);
                    break;

                case 4:
                    strcpy(editedContact->name.name, contactToEdit->name.name);
                    strcpy(editedContact->name.surname, contactToEdit->name.surname);
                    strcpy(editedContact->address.city, contactToEdit->address.city);
                    strcpy(editedContact->address.street, contactToEdit->address.street);
                    strcpy(editedContact->address.zip, contactToEdit->address.zip);
                    strcpy(editedContact->email, contactToEdit->email);
                    editedContact->birthday = contactToEdit->birthday;
                    editedContact->number = contactToEdit->number;
                    printf("Enter new country: ");
                    scanf("%s", editedContact->address.country);
                    break;

                case 5:
                    strcpy(editedContact->name.name, contactToEdit->name.name);
                    strcpy(editedContact->name.surname, contactToEdit->name.surname);
                    strcpy(editedContact->address.country, contactToEdit->address.country);
                    strcpy(editedContact->address.street, contactToEdit->address.street);
                    strcpy(editedContact->address.zip, contactToEdit->address.zip);
                    strcpy(editedContact->email, contactToEdit->email);
                    editedContact->birthday = contactToEdit->birthday;
                    editedContact->number = contactToEdit->number;
                    printf("Enter new city: ");
                    scanf("%s", editedContact->address.city);
                    break;

                case 6:
                    strcpy(editedContact->name.name, contactToEdit->name.name);
                    strcpy(editedContact->name.surname, contactToEdit->name.surname);
                    strcpy(editedContact->address.country, contactToEdit->address.country);
                    strcpy(editedContact->address.city, contactToEdit->address.city);
                    strcpy(editedContact->address.zip, contactToEdit->address.zip);
                    strcpy(editedContact->email, contactToEdit->email);
                    editedContact->birthday = contactToEdit->birthday;
                    editedContact->number = contactToEdit->number;
                    printf("Enter new street: ");
                    scanf("%s", editedContact->address.street);
                    break;

                case 7:
                    strcpy(editedContact->name.name, contactToEdit->name.name);
                    strcpy(editedContact->name.surname, contactToEdit->name.surname);
                    strcpy(editedContact->address.country, contactToEdit->address.country);
                    strcpy(editedContact->address.city, contactToEdit->address.city);
                    strcpy(editedContact->address.street, contactToEdit->address.street);
                    strcpy(editedContact->email, contactToEdit->email);
                    editedContact->birthday = contactToEdit->birthday;
                    editedContact->number = contactToEdit->number;
                    printf("Enter new ZIP: ");
                    scanf("%s", editedContact->address.zip);
                    break;

                case 8:
                    strcpy(editedContact->name.name, contactToEdit->name.name);
                    strcpy(editedContact->name.surname, contactToEdit->name.surname);
                    strcpy(editedContact->address.country, contactToEdit->address.country);
                    strcpy(editedContact->address.city, contactToEdit->address.city);
                    strcpy(editedContact->address.street, contactToEdit->address.street);
                    strcpy(editedContact->address.zip, contactToEdit->address.zip);
                    editedContact->birthday = contactToEdit->birthday;
                    editedContact->number = contactToEdit->number;
                    printf("Enter new email: ");
                    scanf("%s", editedContact->email);
                    break;

                case 9:
                    strcpy(editedContact->name.name, contactToEdit->name.name);
                    strcpy(editedContact->name.surname, contactToEdit->name.surname);
                    strcpy(editedContact->address.country, contactToEdit->address.country);
                    strcpy(editedContact->address.city, contactToEdit->address.city);
                    strcpy(editedContact->address.street, contactToEdit->address.street);
                    strcpy(editedContact->address.zip, contactToEdit->address.zip);
                    strcpy(editedContact->email, contactToEdit->email);
                    editedContact->number = contactToEdit->number;
                    printf("Enter new birtyday (DDMMYYYY): ");
                    scanf("%d", &editedContact->birthday);
                    break;

            }

            fwrite(editedContact, sizeof(Contact), 1, fp_temp);

        } else {

            fwrite(contact_s, sizeof(Contact), 1, fp_temp);

        }

    }

    fclose(fp);
    fclose(fp_temp);

    remove("contacts.bin");
    rename("temp.bin", FILENAME);

}

void deleteContact(Contact *contactToDelete, FILE *fp) {

    FILE *fp_temp;
    Contact *contact_s = (Contact *)malloc(sizeof(Contact));

    fp = fopen(FILENAME, "rb");

    if (fp == NULL) {

        fprintf(stderr, "\nError opening file\n");

        exit (1);

    }

    fp_temp = fopen("temp.bin", "wb");

    if (fp_temp == NULL) {

        fprintf(stderr, "\nError opening file\n");

        exit (1);

    }

    while(fread(contact_s, sizeof(Contact), 1, fp)) {

        if((strncmp(contactToDelete->name.name, contact_s->name.name, strlen(contactToDelete->name.name))) == 0 &&
           (strncmp(contactToDelete->name.surname, contact_s->name.surname, strlen(contactToDelete->name.surname))) == 0 &&
           (contactToDelete->number == contact_s->number)) {

            printf("Contact %s %s is deleted\n", contactToDelete->name.name, contactToDelete->name.surname);

        } else {

            fwrite(contact_s, sizeof(Contact), 1, fp_temp);

        }

    }

    fclose(fp);
    fclose(fp_temp);

    remove("contacts.bin");
    rename("temp.bin", FILENAME);

}

int searchContact(char searchitem[], FILE *fp) {

    fp = fopen(FILENAME, "rb");

    if (fp == NULL) {

        fprintf(stderr, "\nError opening file\n");

        exit (1);

    }
    fp = fopen(FILENAME, "rb");
    int is_equal = 0, st = 0, count = 1;
    Contact *contact_s = (Contact *)malloc(sizeof(Contact));
    Contact contactArr[INITIAL_SIZE_FOR_ARRAY];
    int optionToContact, optionToInteract, optionToChange;
    int isDeleted = 0;

    char name[15], surname[15], country[15], city[15], street[15], email[50];

    while(fread(contact_s, sizeof(Contact), 1, fp)) {

        sprintf(name, "%s", contact_s->name.name);
        sprintf(surname, "%s", contact_s->name.surname);
        sprintf(country, "%s", contact_s->address.country);
        sprintf(city, "%s", contact_s->address.city);
        sprintf(street, "%s", contact_s->address.street);
        sprintf(email, "%s", contact_s->email);

        if((!strncmp(to_Lower(name), to_Lower(searchitem), strlen(searchitem))) ||
           (!strncmp(to_Lower(surname), to_Lower(searchitem), strlen(searchitem))) ||
           (!strncmp(to_Lower(country), to_Lower(searchitem), strlen(searchitem))) ||
           (!strncmp(to_Lower(city), to_Lower(searchitem), strlen(searchitem))) ||
           (!strncmp(to_Lower(street), to_Lower(searchitem), strlen(searchitem))) ||
           (!strncmp(to_Lower(email), to_Lower(searchitem), strlen(searchitem))) ) {

            is_equal = 1;

            st = 1;

        }

        if(is_equal) {

            contactArr[count] = *contact_s;

            printf("=======================\n");
            printf("=      CONTACT %d      =\n", count++);
            printf("=======================\n");

            printContact(*contact_s);

        }

        is_equal = 0;



    }

    fclose(fp);

    if(!st) {

        printf("%s was not found, try again\n", searchitem);
        free(contact_s);

    }

    if(st) {

        do {

            printf("Enter number of contact you want to continue with: ");
            scanf("%d", &optionToContact);

        } while (optionToContact >= count || optionToContact < 1);

        printf("=======================\n");
        printf("=      CONTACT        =\n");
        printf("=======================\n");
        printContact(contactArr[optionToContact]);

        do {
            printf("[1] Edit a Contact\n");
            printf("[2] Delete a Contact\n");
            printf("[3] Back to Main Menu\n");

            printf("Enter the choice: ");

            while(!scanf("%d", &optionToInteract)) {

                while(getchar() != '\n');

                printf("Invalid data, enter again: ");

            }

            switch(optionToInteract) {

                case 1:
                    do {
                        printf("Which attribute do you want to edit?\n");
                        printf("[1] Name\n");
                        printf("[2] Surname\n");
                        printf("[3] Number\n");
                        printf("[4] Country\n");
                        printf("[5] City\n");
                        printf("[6] Street\n");
                        printf("[7] ZIP\n");
                        printf("[8] Email\n");
                        printf("[9] Birthday\n");
                        printf("[0] Go back\n");

                        while(!scanf("%d", &optionToChange)) {

                            while(getchar() != '\n');

                            printf("Invalid data, enter again: ");

                        }

                        } while(optionToChange != 0 && (optionToChange < 1 || optionToChange > 9));
                    editContact(&contactArr[optionToContact], optionToChange, fp);
                    break;

                case 2:
                    deleteContact(&contactArr[optionToContact], fp);
                    isDeleted = 1;
                    break;

                case 3:
                    break;

                default:
                    printf("You have entered wrong choice!\n");
                    continue;

            }

        } while ((optionToInteract != 3) && (isDeleted != 1));

    }

}


void scanInt (int *a) {

    while(!scanf("%d", a)) {

        while(getchar() != '\n');

        printf("Invalid data, enter again: ");

    }

}

void convertDate(int date) {
    int year = date % 10000;
    date /= 10000;
    int month = date % 100;
    date /= 100;
    int day = date;
    switch (month) {
        case January:
            printf("Birthday: %d January %d\n", day, year);
            break;
        case February:
            printf("Birthday: %d February %d\n", day, year);
            break;
        case March:
            printf("Birthday: %d March %d\n", day, year);
            break;
        case April:
            printf("Birthday: %d April %d\n", day, year);
            break;
        case May:
            printf("Birthday: %d May %d\n", day, year);
            break;
        case June:
            printf("Birthday: %d June %d\n", day, year);
            break;
        case July:
            printf("Birthday: %d July %d\n", day, year);
            break;
        case August:
            printf("Birthday: %d August %d\n", day, year);
            break;
        case September:
            printf("Birthday: %d September %d\n", day, year);
            break;
        case October:
            printf("Birthday: %d October %d\n", day, year);
            break;
        case November:
            printf("Birthday: %d November %d\n", day, year);
            break;
        case December:
            printf("Birthday: %d December %d\n", day, year);
            break;
        default:
            break;
    }
}

void printContact(Contact c) {

    printf("Name: %s\n", c.name.name);
    printf("Surname: %s\n", c.name.surname);
    printf("Number: +994%d\n", c.number);
    printf("Country: %s\n", c.address.country);
    printf("City: %s\n", c.address.city);
    printf("Street: %s\n", c.address.street);
    printf("ZIP: %s\n", c.address.zip);
    printf("Email: %s\n", c.email);
    convertDate(c.birthday);

}

int validEmail(char test[]) {
    int i;
    char *pa, *pb;
    char *ch;
    for (i = 0, ch = test; *ch; ch++) {
        if (*ch == '@') {
            pa = ch;
            i++;
        }
    }
    pb = ch;

    if (i == 1) {
        while (pa - test && ch - pa > 1) {
            if ((pb - ch) > 2 && *ch == '.') return 1;
            ch--;
        }
    }
    return 0;
}

int validBirth(int birth) {

    int day = birth / 1000000;

    int month = (birth / 10000) % 100;

    return (day <= 31 && (month >= 1 && month <= 12)) ? 1 : 0;

}