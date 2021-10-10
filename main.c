#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "D:\\C_workplace\\STUDENTS_manage\\STUDENTS_manage\\SeqList.h"

struct DATA data;

void menu(void)
{
	printf("*******************************************************************\n");
	printf("*                                                                 *\n");
	printf("*                       学生信息管理系统                          *\n");
	printf("*                                                                 *\n");
	printf("*******************************************************************\n");
	printf("*      [1] 头部录入学生信息                 [2] 尾部录入学生信息  *\n");
	printf("*      [3] 修改学生信息                     [4] 删除学生信息      *\n");
	printf("*      [5] 成绩排名(可保存学生信息至文件)   [6]	查看学生人数      *\n");
	printf("*      [7] ********                         [8]	********          *\n");
	printf("*      [9] ********                        [10] ***************   *\n");
	printf("*     [11] 清屏                            [12] 退出系统          *\n");
	printf("*     [13] 显示信息                        [14] 查找学生信息      *\n");
	printf("*******************************************************************\n");
}

void scanf_student()
{
	char name[20];
	data.name = (char*)calloc(1,sizeof(char));
	printf("请输入学生的姓名：");
	scanf("%s", name);
	printf("name = %s\n", name);
	strcpy(data.name, name);
	printf("data.name = %s\n", data.name);
	printf("请输入学生的年龄：");
	scanf("%d", &(data.age));
	printf("请输入学生的学号：");
	scanf("%d", &(data.number));
	printf("请输入学生的语文成绩：");
	scanf("%f", &(data.yuwen));
	printf("请输入学生的数学成绩：");
	scanf("%f", &(data.math));
	printf("请输入学生的英语成绩：");
	scanf("%f", &(data.english));
}

int main()
{
	int NUM = 0;
	char name[20],after_name[20];
	ListHeadNode* list = CreateListHeadNode();

	while (1)
	{
		menu();
		printf("请输入要执行的操作序号：");
		fflush(stdin);
		scanf("%d", &NUM);
		switch (NUM)
		{
		    case 1:
				printf("请输入学生的信息：\n");
				scanf_student(data);
				Front_Insert(list, data);
				data.name = NULL;
				break;
			case 2:
				printf("请输入学生的信息：\n");
				scanf_student(data);
				Last_Insert(list, data);
				data.name = NULL;
				break;
			case 3:
				printf("请输入学生的姓名：");
				scanf("%s", name);
				if (ChangeStudent(list, name))
				{
					printf("修改成功！\n");
				}
				else
				{
					printf("未修改成功！\n");
				}
				break;
			case 4:
				printf("请输入学生的姓名：");
				scanf("%s", name);
			    DelStudent(list, name);
				break;
			case 5:
				SortStudents(list);
				break;
			case 6:
				printf("学生的人数是：%d\n",LengthList(list));
				break;
			case 10:

				break;
			case 11:
				system("cls");
				break;
			case 12:
				printf("正常退出系统\n");
				exit(0);
				break;
			case 13:
				printf("姓名\t年龄\t学号\t语文\t数学\t英语\t总分\t\n");
				ShowList(list);
				break;
			case 14:
				printf("请输入要查找的学生姓名：");
				scanf("%s", name);
				FindStudent(list,name);
				break;
		}
	}

	system("pause");
	return 0;
}






