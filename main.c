#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "D:\\C_workplace\\STUDENTS_manage\\STUDENTS_manage\\SeqList.h"

struct DATA data;

void menu(void)
{
	printf("*******************************************************************\n");
	printf("*                                                                 *\n");
	printf("*                       ѧ����Ϣ����ϵͳ                          *\n");
	printf("*                                                                 *\n");
	printf("*******************************************************************\n");
	printf("*      [1] ͷ��¼��ѧ����Ϣ                 [2] β��¼��ѧ����Ϣ  *\n");
	printf("*      [3] �޸�ѧ����Ϣ                     [4] ɾ��ѧ����Ϣ      *\n");
	printf("*      [5] �ɼ�����(�ɱ���ѧ����Ϣ���ļ�)   [6]	�鿴ѧ������      *\n");
	printf("*      [7] ********                         [8]	********          *\n");
	printf("*      [9] ********                        [10] ***************   *\n");
	printf("*     [11] ����                            [12] �˳�ϵͳ          *\n");
	printf("*     [13] ��ʾ��Ϣ                        [14] ����ѧ����Ϣ      *\n");
	printf("*******************************************************************\n");
}

void scanf_student()
{
	char name[20];
	data.name = (char*)calloc(1,sizeof(char));
	printf("������ѧ����������");
	scanf("%s", name);
	printf("name = %s\n", name);
	strcpy(data.name, name);
	printf("data.name = %s\n", data.name);
	printf("������ѧ�������䣺");
	scanf("%d", &(data.age));
	printf("������ѧ����ѧ�ţ�");
	scanf("%d", &(data.number));
	printf("������ѧ�������ĳɼ���");
	scanf("%f", &(data.yuwen));
	printf("������ѧ������ѧ�ɼ���");
	scanf("%f", &(data.math));
	printf("������ѧ����Ӣ��ɼ���");
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
		printf("������Ҫִ�еĲ�����ţ�");
		fflush(stdin);
		scanf("%d", &NUM);
		switch (NUM)
		{
		    case 1:
				printf("������ѧ������Ϣ��\n");
				scanf_student(data);
				Front_Insert(list, data);
				data.name = NULL;
				break;
			case 2:
				printf("������ѧ������Ϣ��\n");
				scanf_student(data);
				Last_Insert(list, data);
				data.name = NULL;
				break;
			case 3:
				printf("������ѧ����������");
				scanf("%s", name);
				if (ChangeStudent(list, name))
				{
					printf("�޸ĳɹ���\n");
				}
				else
				{
					printf("δ�޸ĳɹ���\n");
				}
				break;
			case 4:
				printf("������ѧ����������");
				scanf("%s", name);
			    DelStudent(list, name);
				break;
			case 5:
				SortStudents(list);
				break;
			case 6:
				printf("ѧ���������ǣ�%d\n",LengthList(list));
				break;
			case 10:

				break;
			case 11:
				system("cls");
				break;
			case 12:
				printf("�����˳�ϵͳ\n");
				exit(0);
				break;
			case 13:
				printf("����\t����\tѧ��\t����\t��ѧ\tӢ��\t�ܷ�\t\n");
				ShowList(list);
				break;
			case 14:
				printf("������Ҫ���ҵ�ѧ��������");
				scanf("%s", name);
				FindStudent(list,name);
				break;
		}
	}

	system("pause");
	return 0;
}






