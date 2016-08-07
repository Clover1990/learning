#include <windows.h>
#include "score.h"

void menu()
{
    system("cls");
    system("title The system of students' score");
    printf("\nWelcome to the system......\n\n\n");
    printf("\t\t****************STUDENT****************\n");
    printf("\t\t*\t 0. exit                      *\n");
    printf("\t\t*\t 1. input record              *\n");
    printf("\t\t*\t 2. search record             *\n");
    printf("\t\t*\t 3. delete record             *\n");
    printf("\t\t*\t 4. modify recored            *\n");
    printf("\t\t*\t 5. insert record             *\n");
    printf("\t\t*\t 6. order                     *\n");
    printf("\t\t*\t 7. total students number     *\n");
    printf("\t\t***************************************\n");
    printf("\nPlease choose the operation<0-7>: ");
    return;
}
