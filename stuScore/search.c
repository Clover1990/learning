#include <string.h>
#include "score.h"


void search()
{
	int inNum = 0;
	int index = 0;
	int i = 0;
	char ch[2] = { 0 };
	FILE *fp;
	
	fp = fopen("data.txt", "rt");
	if (fp == NULL)
	{
		printf("Cannot open the file!\n");
		return;
	}
	while (!feof(fp))
	{
		if (fread(&stu[index], LEN, 1, fp) == 1)
			index++;
	}
	fclose(fp);

	printf("Do you want to searh?(Y/N)");
	scanf("%s", ch);
	
	while (strcmp(ch, "Y") == 0 || strcmp(ch, "y") == 0)
	{
		printf("Please enter a num: ");
		scanf("%d", &inNum);
		
		for (i = 0; i < index; ++i)
		{
			if (inNum == stu[i].num)
			{
				printf("\nFine the record, the result is following: \n");
				printf("number    name           eletive   experiment require  totalScore\n");
				printf("%-10d%-15s%-10.2f%-11.2f%-10.2f%-10.2f\n\n", stu[i].num, stu[i].name, stu[i].elec, stu[i].expe, stu[i].requ, stu[i].sum);
				printf("Do you want to continue?(Y/N)");
				break;
			}
		}
		if (index == i)
			printf("Cannot fine the record, try again?(Y/N)");
		scanf("%s", ch);
	}
	
    return;
}
