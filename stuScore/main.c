#include <stdlib.h>
#include "score.h"

void main()
{
    int choice = 0;
    menu();
    scanf("%d", &choice);
    while(choice)
    {
        switch(choice)
        {
            case 1:
                init();
                break;
            case 2:
                search();
                break;
            case 3:
                del();
                break;
            case 4:
                modify();
                break;
            case 5:
                insert();
                break;
            case 6:
                order();
                break;
            case 7:
                total();
                break;
            default: break;
        }
        getchar();
        menu();
        scanf("%d", &choice);
    }
    getchar();
    return;
}
