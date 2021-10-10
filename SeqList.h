#ifndef _SeqList_H
#define _SeqList_H
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

struct DATA
{
	char *name;
	int age;
	int number;
	float yuwen;
	float math;
	float english;
	float sum;
};

typedef struct Student
{
	struct DATA data;
	struct Student* next;
}Node, ListHeadNode;

ListHeadNode* CreateListHeadNode();
Node* CreateNode(void);
/*
	判断链表是否为空
 */
bool IsEmpty(ListHeadNode* list);
/*
	从链表头部插入数据
 */
void Front_Insert(ListHeadNode* list, struct DATA data);
/*
	打印链表
 */
void ShowList(ListHeadNode* list);
/*
	尾部插入学生信息
 */
void Last_Insert(ListHeadNode* list,struct DATA data);
/*
	查找按照学生姓名查找信息函数
 */
bool FindStudent(ListHeadNode* list, char name[20]);
/*
	按照学生姓名删除该名学生的信息
 */
void DelStudent(ListHeadNode* list, char name[20]);
/*
	修改学生的年龄、三科成绩
	按照学生姓名找到，
 */
bool ChangeStudent(ListHeadNode* list, char name[20]);
/*
	按照成绩排名
 */
void SortStudents(ListHeadNode* list);
/*
	统计链表长度
 */
int LengthList(ListHeadNode* list);
/*
	创建文本文件
 */
void CreateFile(int a, FILE* file);
/*
	将信息写入文件
 */
void WriteToTheFile(int a, ListHeadNode* list, FILE* file);

#endif //SeqList_H


