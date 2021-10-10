#define _CRT_SECURE_NO_WARNINGS
#include <malloc.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <D:\C_workplace\STUDENTS_manage\STUDENTS_manage\SeqList.h>

ListHeadNode* CreateListHeadNode()
{
	ListHeadNode* list = (ListHeadNode*)calloc(1, sizeof(list));
	assert(list != NULL);
	return list;
}

Node* CreateNode(void)
{
	Node* NewNode = (Node*)calloc(1, sizeof(Node));
	NewNode->data.name = (char*)calloc(1, sizeof(char));
	assert(NewNode != NULL);
	NewNode->data.age = NULL;
	NewNode->data.english = 0.0;
	NewNode->data.math = 0.0;
	NewNode->data.number = NULL;
	NewNode->data.yuwen = 0.0;
	NewNode->data.name = NULL;
	NewNode->data.sum = 0.0;
	NewNode->next = NULL;
	return NewNode;
}

void Front_Insert(ListHeadNode* list,struct DATA data)
{
	Node* NewNode = CreateNode();
	NewNode->data.name = (char*)calloc(1, sizeof(char));
	strcpy(NewNode->data.name, data.name);
	NewNode->data.age = data.age;
	NewNode->data.number = data.number;
	NewNode->data.yuwen = data.yuwen;
	NewNode->data.math = data.math;
	NewNode->data.english = data.english;
	NewNode->data.sum = NewNode->data.yuwen + NewNode->data.math + NewNode->data.english;
	NewNode->next = list->next;
	list->next = NewNode;
}

bool IsEmpty(ListHeadNode* list)
{
	if (list->next == NULL)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

void ShowList(ListHeadNode* list)
{
	if (!IsEmpty(list))
	{
		printf("学生信息表格为空！请填充后重新尝试！\n");
		exit(0);
	}
	Node* curNode = list->next;
	while (curNode)
	{
		printf("%s\t%d\t%d\t%.1f\t%.1f\t%.1f\t%.1f\n", curNode->data.name, curNode->data.age, curNode->data.number, curNode->data.yuwen, curNode->data.math, curNode->data.english,curNode->data.sum);
		curNode = curNode->next;
	}
	printf("\n");
}

void Last_Insert(ListHeadNode* list, struct DATA data)
{
	Node* curNode = list;
	while (curNode->next != NULL)
	{
		curNode = curNode->next;
	}
	Node* newNode = CreateNode();
	newNode->data.name = (char*)calloc(1, sizeof(char));
	strcpy(newNode->data.name, data.name);
	newNode->data.age = data.age;
	newNode->data.number = data.number;
	newNode->data.yuwen = data.yuwen;
	newNode->data.math = data.math;
	newNode->data.english = data.english;
	newNode->data.sum = newNode->data.yuwen + newNode->data.math + newNode->data.english;
	curNode->next = newNode;
}

bool FindStudent(ListHeadNode* list, char name[20])
{
	if (!IsEmpty(list))
	{
		exit(0);
	}
	Node* CurNode = list->next;
	while (CurNode)
	{
		if (!strcmp(CurNode->data.name, name))
		{
			printf("找到了！\n");
			printf("姓名\t年龄\t学号\t语文\t数学\t英语\t总分\t\n");
			printf("%s\t%d\t%d\t%.1f\t%.1f\t%.1f\t%.1f\n", CurNode->data.name, CurNode->data.age, CurNode->data.number, CurNode->data.yuwen, CurNode->data.math, CurNode->data.english, CurNode->data.sum);
			printf("\n");
			return 1;
		}
		CurNode = CurNode->next;
	}
	printf("查无此人！请确认无误后在输入！！！\n");
	return 0;
}

void DelStudent(ListHeadNode* list, char name[20])
{
	Node* CurNode = CreateNode();
	Node* NewNode = CreateNode();
	CurNode = list;
	if (!IsEmpty(list))
	{
		printf("链表为空！\n");
		exit(0);
	}
	if (FindStudent(list, name))
	{
		while (CurNode->next->next != NULL)
		{
			if (!strcmp(CurNode->next->data.name, name))
			{
				Node* NewNode = CurNode;
				CurNode = CurNode->next;
				Node* NodeDel = CurNode->next;
				free(CurNode);
				NewNode->next = NodeDel;
				return;
			}
			CurNode = CurNode->next;
		}
		if (CurNode->next->next == NULL)
		{
			if (!strcmp(CurNode->next->data.name,name))
			{
				Node* TemptNode = CurNode;
				Node* DelNode = CurNode->next;
				Node* lastNode = CurNode->next->next;
				free(CurNode->next);
				TemptNode->next = lastNode;
			}
		}
		return;
	}
}

bool ChangeStudent(ListHeadNode* list, char name[20])
{
	int a = 0,b = 0;
	if (!IsEmpty(list))
	{
		printf("链表为空！\n");
		exit(0);
	}
	Node* NewNode = CreateNode();
	Node* CurNode = list->next;
	if (FindStudent(list,name))
	{
		while (CurNode)
		{
			if (!strcmp(CurNode->data.name,name))
			{
				printf("******输入：1 -----> 修改学生的年龄********\n");
				printf("******输入：2 -----> 修改学生的学号********\n");
				printf("******输入：3 -----> 修改学生的语文成绩****\n");
				printf("******输入：4 -----> 修改学生的数学成绩****\n");
				printf("******输入：5 -----> 修改学生的英语成绩****\n");
				printf("DATA -> ");
				scanf("%d", &a);
				if (a == 1)
				{
					printf("请输入年龄：");
					scanf("%d", &CurNode->data.age);
				}
				if (a == 2)
				{
					printf("请输入学号：");
					scanf("%d", &CurNode->data.number);
				}
				if (a == 3)
				{
					printf("请输入语文：");
					scanf("%f", &CurNode->data.yuwen);
				}
				if (a == 4)
				{
					printf("请输入数学：");
					scanf("%f", &CurNode->data.math);
				}
				if (a == 5)
				{
					printf("请输入英语：");
					scanf("%f", &CurNode->data.english);
				}
				printf("%s\t%d\t%d\t%.1f\t%.1f\t%.1f\t%.1f\n", CurNode->data.name, CurNode->data.age, CurNode->data.number, CurNode->data.yuwen, CurNode->data.math, CurNode->data.english, CurNode->data.sum);
				return 1;
			}
			CurNode = CurNode->next;
		}
	}
	else
	{
		printf("未找到该学生，请确认输入无误！\n");
		return 0;
	}
}

int LengthList(ListHeadNode* list)
{
	int length = 0;
	if (!IsEmpty(list))
	{
		printf("链表为空！请输入学生信息\n");
		exit(0);
	}
	Node* CurNode = CreateNode();
	CurNode = list->next;
	while (CurNode != NULL)
	{
		length++;
		CurNode = CurNode->next;
	}
	return length;
}


void CreateFile(int a,FILE* file)
{
	if (a == 1)
	{
		file = fopen("D:\\C_workplace\\STUDENTS_manage\\STUDENTS_manage\\final\\yuwen.txt", "w");
		if (!file)
		{
			printf("打开文件失败！\n");
			exit(0);
		}
		fprintf(file, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t\n", "姓名", "年龄", "学号", "语文", "数学", "英语", "总分");
		fclose(file);
		printf("创建文件成功！\n");
	}
	if (a == 2)
	{
		file = fopen("D:\\C_workplace\\STUDENTS_manage\\STUDENTS_manage\\final\\math.txt", "w");
		if (!file)
		{
			printf("打开文件失败！\n");
			exit(0);
		}
		fprintf(file, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t\n", "姓名", "年龄", "学号", "语文", "数学", "英语", "总分");
		fclose(file);
		printf("创建文件成功！\n");
	}
	if (a == 3)
	{
		file = fopen("D:\\C_workplace\\STUDENTS_manage\\STUDENTS_manage\\final\\english.txt", "w");
		if (!file)
		{
			printf("打开文件失败！\n");
			exit(0);
		}
		fprintf(file, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t\n", "姓名", "年龄", "学号", "语文", "数学", "英语", "总分");
		fclose(file);
		printf("创建文件成功！\n");
	}
	if (a == 4)
	{
		file = fopen("D:\\C_workplace\\STUDENTS_manage\\STUDENTS_manage\\final\\all.txt", "w");
		if (!file)
		{
			printf("打开文件失败！\n");
			exit(0);
		}
		fprintf(file, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t\n", "姓名", "年龄", "学号", "语文", "数学", "英语", "总分");
		fclose(file);
		printf("创建文件成功！\n");
	}
}

void WriteToTheFile(int a, ListHeadNode* list, FILE* file)
{
	if (a == 1)
	{
		file = fopen("D:\\C_workplace\\STUDENTS_manage\\STUDENTS_manage\\final\\yuwen.txt", "w");
		if (!file)
		{
			printf("打开文件失败！\n");
			exit(0);
		}
		Node* CurNode = list->next;
		while (CurNode)
		{
			fprintf(file, "%s\t%d\t%d\t%.1f\t%.1f\t%.1f\t%.1f\t\n", CurNode->data.name, CurNode->data.age, CurNode->data.number, CurNode->data.yuwen, CurNode->data.math, CurNode->data.english, CurNode->data.sum);
			CurNode = CurNode->next;
		}
		fclose(file);
		printf("write successful!\n");
	}
	if (a == 2)
	{
		file = fopen("D:\\C_workplace\\STUDENTS_manage\\STUDENTS_manage\\final\\math.txt", "w");
		if (!file)
		{
			printf("打开文件失败！\n");
			exit(0);
		}
		Node* CurNode = list->next;
		while (CurNode)
		{
			fprintf(file, "%s\t%d\t%d\t%.1f\t%.1f\t%.1f\t%.1f\t\n", CurNode->data.name, CurNode->data.age, CurNode->data.number, CurNode->data.yuwen, CurNode->data.math, CurNode->data.english, CurNode->data.sum);
			CurNode = CurNode->next;
		}
		fclose(file);
		printf("write successful!\n");
	}
	if (a == 3)
	{
		file = fopen("D:\\C_workplace\\STUDENTS_manage\\STUDENTS_manage\\final\\english.txt", "w");
		if (!file)
		{
			printf("打开文件失败！\n");
			exit(0);
		}
		Node* CurNode = list->next;
		while (CurNode)
		{
			fprintf(file, "%s\t%d\t%d\t%.1f\t%.1f\t%.1f\t%.1f\t\n", CurNode->data.name, CurNode->data.age, CurNode->data.number, CurNode->data.yuwen, CurNode->data.math, CurNode->data.english, CurNode->data.sum);
			CurNode = CurNode->next;
		}
		fclose(file);
		printf("write successful!\n");
	}
	if (a == 4)
	{
		file = fopen("D:\\C_workplace\\STUDENTS_manage\\STUDENTS_manage\\final\\all.txt", "w");
		if (!file)
		{
			printf("打开文件失败！\n");
			exit(0);
		}
		Node* CurNode = list->next;
		while (CurNode)
		{
			fprintf(file, "%s\t%d\t%d\t%.1f\t%.1f\t%.1f\t%.1f\t\n", CurNode->data.name, CurNode->data.age, CurNode->data.number, CurNode->data.yuwen, CurNode->data.math, CurNode->data.english, CurNode->data.sum);
			CurNode = CurNode->next;
		}
		fclose(file);
		printf("write successful!\n");
	}

}

void SortStudents(ListHeadNode* list)
{
	FILE* file = NULL;
	int YESorNO = 0;
	if (!IsEmpty(list))
	{
		printf("链表为空！请输入学生信息！\n");
		exit(0);
	}
	int a = 0;                                        // 选择的排名操作数
	printf("*******输入-> 1  :    按照语文成绩排名    ***************\n");
	printf("*******输入-> 2  :    按照数学成绩排名    ***************\n");
	printf("*******输入-> 3  :    按照英语成绩排名    ***************\n");
	printf("*******输入-> 4  :    按照总分成绩排名    ***************\n");
	printf("选择成绩排名方式 DATA-> ");
	scanf("%d", &a);
	if (a == 1)
	{
		// 采用冒泡排序方式
		for (Node* i = list->next; i->next != NULL; i = i->next)
		{
			for (Node* CurNode = list->next; CurNode->next != NULL; CurNode = CurNode->next)
			{
				if (CurNode->data.yuwen > CurNode->next->data.yuwen)
				{
					Node* NewNode = CreateNode();
					NewNode->data = CurNode->data;
					CurNode->data = CurNode->next->data;
					CurNode->next->data = NewNode->data;
					free(NewNode);
				}
			}
		}
		printf("请选择是否将语文成绩排名保存至文件：\n");
		printf("\t3  ----->   保存至文件\n");
		printf("\t4  ----->   不保存至文件\n");
		printf("请输入3or4:");
		// 刷新一下输入缓冲区
		fflush(stdin);
		scanf("%d", &YESorNO);
		if (YESorNO == 3)
		{
			CreateFile(1, file);
			WriteToTheFile(1, list, file);
		}
	}
	if (a == 2)
	{
		// 采用冒泡排序方式
		for (Node* i = list->next; i->next != NULL; i = i->next)
		{
			for (Node* CurNode = list->next; CurNode->next != NULL; CurNode = CurNode->next)
			{
				if (CurNode->data.math > CurNode->next->data.math)
				{
					Node* NewNode = CreateNode();
					NewNode->data = CurNode->data;
					CurNode->data = CurNode->next->data;
					CurNode->next->data = NewNode->data;
					free(NewNode);
				}
			}
		}
		printf("------>请选择是否将数学成绩排名保存至文件：\n");
		printf("\t3  ----->   保存至文件\n");
		printf("\t4  ----->   不保存至文件\n");
		// 刷新一下输入缓冲区
		fflush(stdin);
		printf("请输入3or4:");
		scanf("%d", &YESorNO);
		if (YESorNO == 3)
		{
			CreateFile(2, file);
			WriteToTheFile(2, list, file);
		}
	}
	if(a == 3)
	{
		// 采用冒泡排序方式
		for (Node* i = list->next; i->next != NULL; i = i->next)
		{
			for (Node* CurNode = list->next; CurNode->next != NULL; CurNode = CurNode->next)
			{
				if (CurNode->data.english > CurNode->next->data.english)
				{
					Node* NewNode = CreateNode();
					NewNode->data = CurNode->data;
					CurNode->data = CurNode->next->data;
					CurNode->next->data = NewNode->data;
					free(NewNode);
				}
			}
		}
		printf("------>请选择是否将英语成绩排名保存至文件：\n");
		printf("\t3  ----->   保存至文件\n");
		printf("\t4  ----->   不保存至文件\n");
		// 刷新一下输入缓冲区
		fflush(stdin);
		printf("请输入3or4:");
		scanf("%d", &YESorNO);
		if (YESorNO == 3)
		{
			CreateFile(3, file);
			WriteToTheFile(3, list, file);
		}
	}
	if(a == 4)
	{
		// 采用冒泡排序方式
		for (Node* i = list->next; i->next != NULL; i = i->next)
		{
			for (Node* CurNode = list->next; CurNode->next != NULL; CurNode = CurNode->next)
			{
				if (CurNode->data.sum > CurNode->next->data.sum)
				{
					Node* NewNode = CreateNode();
					NewNode->data = CurNode->data;
					CurNode->data = CurNode->next->data;
					CurNode->next->data = NewNode->data;
					free(NewNode);
				}
			}
		}
		printf("------>请选择是否将英语成绩排名保存至文件：\n");
		printf("\t3  ----->   保存至文件\n");
		printf("\t4  ----->   不保存至文件\n");
		// 刷新一下输入缓冲区
		fflush(stdin);
		printf("请输入3or4:");
		scanf("%d", &YESorNO);
		if (YESorNO == 3)
		{
			CreateFile(4, file);
			WriteToTheFile(4, list, file);
		}
	}
	printf("姓名\t年龄\t学号\t语文\t数学\t英语\t总分\t\n");
	ShowList(list);
}



