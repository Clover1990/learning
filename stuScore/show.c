#include "score.h"


void show()
{
	int numbers = 0;
    FILE *fp = fopen("data.txt","rt");
	if (fp == NULL)
	{
		printf("Open file failed!\n");
		return;
	}
	while (!feof(fp))
	{
		if(fread(&stu[numbers], LEN, 1, fp) == 1)
			numbers++;
	}
	fclose(fp);

	printf("number    name           eletive   experiment require  totalScore\n");
	for (int i = 0; i < numbers; ++i)
	{
		printf("%-10d%-15s%-10.2f%-11.2f%-10.2f%-10.2f\n", stu[i].num, stu[i].name, stu[i].elec, stu[i].expe, stu[i].requ, stu[i].sum);
	}
    return;
}
