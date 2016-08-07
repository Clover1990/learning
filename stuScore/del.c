#include <string.h>
#include "score.h"

void del()
{
	FILE* fp;
	int index = 0;
	int delNum = 0;
	int findFlag = 1;
	char ch[2] = { 0 };
	char delCh[2] = { 0 };
	int i = 0;
	int j = 0;

	fp = fopen("data.txt", "rt");
	if (fp == NULL)
	{
		printf("Open failed!\n");
		return;
	}
	while (!feof(fp))
	{
		if (fread(&stu[index], LEN, 1, fp) == 1)
			++index;
	}
	fclose(fp);

	if (0 == index)
	{
		printf("There is no record!\n");
		return;
	}

	printf("Do you want to delete a record?(Y/N)");
	scanf("%s", ch);

	while (strcmp(ch, "Y") == 0 || strcmp(ch, "y") == 0)
	{
		printf("Please enter the number you want to delete: ");
		scanf("%d", &delNum);
		findFlag = 0;
		for (i = 0; i < index; ++i)
		{
			if (stu[i].num == delNum)
			{
			    findFlag = 1;
				printf("Are you sure to delete this record?(Y/N)");
				scanf("%s", delCh);
				if (strcmp(delCh, "Y") != 0 && strcmp(delCh, "y") != 0)
					return;
				for (j = i; j < index - 1; ++j)
				{
					stu[j].num = stu[j + 1].num;
					strcpy(stu[j].name, stu[j + 1].name);
					stu[j].elec = stu[j + 1].elec;
					stu[j].expe = stu[j + 1].expe;
					stu[j].requ = stu[j + 1].requ;
					stu[j].sum = stu[j + 1].sum;
				}
				index--;
				printf("Sucess! Do you want to delete more?(Y/N)");
				break;
			}
		}
		if (findFlag == 0)
			printf("The number is not exist, do you want to try again?(Y/N)");
		scanf("%s", ch);
	}

	if ((fp = fopen("data.txt", "wt+")) == NULL)
	{
		printf("Open the file failed!\n");
		return;
	}

	for (i = 0; i < index; ++i)
	if (fwrite(&stu[i], LEN, 1, fp) != 1)
	{
		printf("Write the data to file fail!\n");
		return;
	}
	fclose(fp);
	printf("Delete the record successfully!\n");
    return;
}
