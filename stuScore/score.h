#include <stdio.h>
#include <stdlib.h>

struct student
{
    int num;
    char name[20];
    double elec;
    double expe;
    double requ;
    double sum;
};

#define LEN sizeof(struct student)
struct student stu[50];

void menu();
void init();
void search();
void del();
void modify();
void insert();
void order();
void total();
void show();

