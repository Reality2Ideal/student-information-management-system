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
	�ж������Ƿ�Ϊ��
 */
bool IsEmpty(ListHeadNode* list);
/*
	������ͷ����������
 */
void Front_Insert(ListHeadNode* list, struct DATA data);
/*
	��ӡ����
 */
void ShowList(ListHeadNode* list);
/*
	β������ѧ����Ϣ
 */
void Last_Insert(ListHeadNode* list,struct DATA data);
/*
	���Ұ���ѧ������������Ϣ����
 */
bool FindStudent(ListHeadNode* list, char name[20]);
/*
	����ѧ������ɾ������ѧ������Ϣ
 */
void DelStudent(ListHeadNode* list, char name[20]);
/*
	�޸�ѧ�������䡢���Ƴɼ�
	����ѧ�������ҵ���
 */
bool ChangeStudent(ListHeadNode* list, char name[20]);
/*
	���ճɼ�����
 */
void SortStudents(ListHeadNode* list);
/*
	ͳ��������
 */
int LengthList(ListHeadNode* list);
/*
	�����ı��ļ�
 */
void CreateFile(int a, FILE* file);
/*
	����Ϣд���ļ�
 */
void WriteToTheFile(int a, ListHeadNode* list, FILE* file);

#endif //SeqList_H


