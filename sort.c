#include "sort.h"

int cmp_by_name(const void *a, const void *b) {

    Contact *ap = (Contact *)a;
    Contact *bp = (Contact *)b;
    return strcmp(ap->name.name, bp->name.name);

}

int cmp_by_surname(const void *a, const void *b) {

    Contact *ap = (Contact *)a;
    Contact *bp = (Contact *)b;
    return strcmp(ap->name.surname, bp->name.surname);

}

int cmp_by_country(const void *a, const void *b) {

    Contact *ap = (Contact *)a;
    Contact *bp = (Contact *)b;
    return strcmp(ap->address.country, bp->address.country);

}

int cmp_by_city(const void *a, const void *b) {

    Contact *ap = (Contact *)a;
    Contact *bp = (Contact *)b;
    return strcmp(ap->address.city, bp->address.city);

}

int cmp_by_street(const void *a, const void *b) {

    Contact *ap = (Contact *)a;
    Contact *bp = (Contact *)b;
    return strcmp(ap->address.street, bp->address.street);

}


void sort(FILE *fp) {

    fp = fopen(FILENAME, "rb");

    if (fp == NULL) {

        fprintf(stderr, "\nError opening file\n");

        exit (1);

    }

    fseek(fp, 0, SEEK_END);

    long size = ftell(fp);

    size_t numofC = size / sizeof(Contact); // - numberOFDeleted(fp)
    Contact *ArrayC = (Contact *)malloc(numofC * sizeof(Contact));
    Contact *cont = (Contact *)malloc(sizeof(Contact));

    int i = 0, option;

    rewind(fp);

    while(fread(cont, sizeof(Contact), 1, fp)) {

        ArrayC[i] = *cont;

        i++;

    }

    fclose(fp);

    printf("By which attribute do you want to sort?\n");
    printf("[1] Name\n");
    printf("[2] Surname\n");
    printf("[3] Country\n");
    printf("[4] City\n");
    printf("[5] Street\n");

    scanInt(&option);

    switch(option) {

        case 1:
            qsort(ArrayC, numofC, sizeof(Contact), cmp_by_name);
            break;

        case 2:
            qsort(ArrayC, numofC, sizeof(Contact), cmp_by_surname);
            break;

        case 3:
            qsort(ArrayC, numofC, sizeof(Contact), cmp_by_country);
            break;

        case 4:
            qsort(ArrayC, numofC, sizeof(Contact), cmp_by_city);
            break;

        case 5:
            qsort(ArrayC, numofC, sizeof(Contact), cmp_by_street);
            break;

        default:
            printf("Wrong input, try again");
            scanInt(&option);

    }

    int count = 1;

    for(int j = 0; j < numofC; j++) {

        printf("=======================\n");
        printf("=      CONTACT %d      =\n", count);
        printf("=======================\n");

        count++;

        printContact(ArrayC[j]);

    }

    free(ArrayC);
    free(cont);

}
