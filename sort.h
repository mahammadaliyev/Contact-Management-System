#ifndef CONTACTMANAGEMENTSYS_SORT_H
#define CONTACTMANAGEMENTSYS_SORT_H

#include "function.h"

int cmp_by_name(const void *a, const void *b);
int cmp_by_surname(const void *a, const void *b);
int cmp_by_country(const void *a, const void *b);
int cmp_by_city(const void *a, const void *b);
int cmp_by_street(const void *a, const void *b);
void sort(FILE *fp);


#endif //CONTACTMANAGEMENTSYS_SORT_H
