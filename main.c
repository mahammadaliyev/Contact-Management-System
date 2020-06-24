#include "function.h"
#include "sort.h"

int main(int argc, char *argv[]) {

    int option;
    FILE *fp;
    char keyword[30];
/*
 if(strcmp(argv[1], "-a") == 0) {

     addContact(fp);

 }

 if(strcmp(argv[1], "-n") == 0) {

     numberOfContacts(fp);

 }

*/

    do {

        printf("=======================\n");
        printf("=      MAIN MENU      =\n");
        printf("=======================\n");
        printf("[1] Add a new Contact\n");
        printf("[2] Show all Contacts\n");
        printf("[3] Search a Contact\n");
        printf("[4] Edit a Contact\n");
        printf("[5] Delete a Contact\n");
        printf("[6] Sort Contacts\n");
        printf("[7] Number of Contacts\n");
        printf("[0] Exit\n");
        printf("=======================\n");

        printf("Enter the choice: ");

        while(!scanf("%d", &option)) {

            while(getchar() != '\n');

            printf("Invalid data, enter again: ");

        }

        switch(option) {

            case 1:
                addContact(fp);
                break;

            case 2:
                showContact(fp);
                break;

            case 3:
                printf("Enter the Contact do you what to find: ");
                scanf("%s", keyword);
                searchContact(keyword, fp);
                break;

            case 4:
//                printf("Enter Contact to Modify: ");
//                scanf("%s", keyword);
//                modifyContact(keyword, fp);
                break;

            case 5:
//                printf("Enter Contact to delete: ");
//                scanf("%s", keyword);
//                deleteContact(keyword, fp);
                break;

            case 6:
                sort(fp);
                break;

            case 7:
                numberOfContacts(fp);
                break;

            case 0:
                printf("Thanks for using our contact management system!\n");
                break;

            default:
                printf("You have entered wrong choice!\n");
                continue;

        }

    } while (option != 0);

    return 0;

}