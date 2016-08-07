#include <string.h>
#include "score.h"

void init()
{
    int scoreNum = 0;
	char ch[2] = { 0 };
	int i = 0;
    FILE *fp = fopen("data.txt", "rt");
    if(NULL == fp)
    {
        printf("Open the file data.txt failed! \n");
        return;
    }
    while(!feof(fp))
    {
        if(fread(&stu[scoreNum], LEN, 1, fp) == 1)
            ++scoreNum;
    }
    fclose(fp);
    if(0 == scoreNum)
        printf("No record!!!\n");
    else
    {
        system("cls");
        show();
    }

    if((fp = fopen("data.txt", "wt+")) == NULL)
    {
        printf("Open failed!!!\n");
        return;
    }

    for(i = 0; i < scoreNum; ++i)
		fwrite(&stu[i], LEN, 1, fp);
    printf("Please input(y/n): ");
    scanf("%s", ch);
	
	while (strcmp(ch, "Y") == 0 || strcmp(ch, "y") == 0)
	{
		printf("number: ");
		scanf("%d", &stu[scoreNum].num);
		for (i = 0; i < scoreNum; ++i)
		if (stu[i].num == stu[scoreNum].num)
		{
			printf("The number is already exist, press any to continue!");
			getchar();
			fclose(fp);
			return;
		}
		printf("name: ");
		scanf("%s", &stu[scoreNum].name);
		printf("elective: ");
		scanf("%lf", &stu[scoreNum].elec);
		printf("experiment: ");
		scanf("%lf", &stu[scoreNum].expe);
		printf("require course: ");
		scanf("%lf", &stu[scoreNum].requ);
		stu[scoreNum].sum = stu[scoreNum].elec + stu[scoreNum].expe + stu[scoreNum].requ;

		if ((fwrite(&stu[scoreNum], LEN, 1, fp)) != 1)
		{
			printf("Cannot save data.\n");
			getchar();
		}
		else
		{
			printf("%s's data is saved!\n", stu[scoreNum].name);
			++scoreNum;
		}

		printf("Continue?(Y/N): ");
		scanf("%s", ch);
	}

	fclose(fp);
	printf("OK!\n");
}
