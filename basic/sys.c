//School Information Management System
//Algorithm analysis course design
//ACM is really boring
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct student
{
	char name[50];
	int sex;
	int id;
	int class1;
	struct student* next;
}student;
student* head = NULL;
int length = 0;
int state[105]={0};
int cont = -1;
void create()
{
	student* p1, * p2;
	p1 = (student*)malloc(sizeof(student));
	p1->id = -1;
	if (head == NULL)
		head = p1;
	p2 = (student*)malloc(sizeof(student));
	scanf("%s %d %d %d", p2->name, &p2->sex, &p2->id, &p2->class1);
	for (int i = 0; i < cont; i++) {
		//printf("test%d\n",state[i]);
		if (state[i] == p2->id) {
			head = NULL;
			return;
		}
	}
	length++;
	p1->next = p2;
	p2->next = NULL;
	p1 = p1->next;
	return;
}
void insert()
{
	if (length == 0)
	{
		create();
		return;
	}
	int num, i;
	student* p, * q;
	p = head;
	num = length;
	{
		q = (student*)malloc(sizeof(student));
		scanf("%s %d %d %d", q->name, &q->sex, &q->id, &q->class1);
		for (int i = 0; i < cont; i++)
			if (state[i] == q->id)
				return;
		while (p != NULL)
		{
			if (p->id == q->id)
			{
				return;
			}
			p = p->next;
		}
		p = head;
		for (i = 0; i < num; i++)
			p = p->next;
		q->next = p->next;
		p->next = q;
		length++;
		return;
	}
}
void Delete()
{
	int num;
	student* p, * q;
	q = head, p = head->next;
	scanf("%d", &num);
	state[cont] = num;
	//	printf("deld%d\n",cont);
	while (p != NULL)
	{
		if (p->id == num)
		{
			q->next = p->next;
			free(p);
			length--;
			return;
		}
		p = p->next;
		q = q->next;
	}
	if (p == NULL)
	{
		return;
	}
}
void search()
{
	int num;
	student* p = head->next;
	scanf("%d", &num);
//	printf("hello");
	while (p != NULL)
	{

		if (p->id == num)
		{
			printf("%s %d %02d %03d\n", p->name, p->sex, p->id, p->class1);
			return;
		}

		p = p->next;
	}
	if (p == NULL)
		printf("-1\n");
	return;
}
void search1()
{
	int num, count;
	student* p = head->next;
	char  temp[50];
	char str[20][50];
	scanf("%d", &num);
	count = 0;
	while (p != NULL)
	{

		if (p->class1 == num)
		{
			strcpy(str[count], p->name);
			count++;
		}
		p = p->next;
	}

	printf("%d\n", count);
	if (count == 0)
		return;
	for (int i = 0; i < count; i++) {
		for (int j = 0; j < count - i; j++) {
			if (strcmp(str[j], str[j + 1]) > 0) {
				strcpy(temp, str[j]);
				strcpy(str[j], str[j + 1]);
				strcpy(str[j + 1], temp);
			}
		}
	}
	for (int i = 0; i < count; i++) {
		if (i == count - 1)
			printf("%s\n", str[i]);
		else
			printf("%s ", str[i]);
	}


	return;
}
void search2()
{
	int  num,count;
	student* p = head->next;
	char  temp[50];
	char str[20][50];
	scanf("%d", &num);
	count = 0;
	while (p != NULL)
	{

		if (p->sex == num)
		{
			strcpy(str[count], p->name);
			count++;
		}
		p = p->next;
	}

	printf("%d\n", count);
	if (count == 0)
		return;
	for (int i = 0; i < count; i++) {
		for (int j = 0; j < count - i; j++) {
			if (strcmp(str[j], str[j + 1]) > 0) {
				strcpy(temp, str[j]);
				strcpy(str[j], str[j + 1]);
				strcpy(str[j + 1], temp);
			}
		}
	}


	for (int i = 0; i < count; i++) {
		if (i == count - 1)
			printf("%s\n", str[i]);
		else
			printf("%s ", str[i]);
	}


	return;
}

void init()
{
	int  num;
	student* p = head->next;
	//	printf("sex");
	char  temp[50];
	char str[20][50];
	num = 0;
	int count = 0;
	while (p != NULL)
	{

		if (p->sex == num)
		{
			strcpy(str[count], p->name);
			count++;
			//			printf("%s\n",p->name);
		}
		p = p->next;
	}
	if (count == 0)
		return;
	//	printf("%d\n",count);

	for (int i = 0; i < count; i++) {
		for (int j = 0; j < count - i; j++) {
			if (strcmp(str[j], str[j + 1]) > 0) {
				strcpy(temp, str[j]);
				strcpy(str[j], str[j + 1]);
				strcpy(str[j + 1], temp);
			}
		}
	}



	return;
}

int main()
{
	int a;
	int j;
int num;
	scanf("%d", &j);
	while (j--)
	{
		cont++;
		scanf("%d", &a);
		switch (a)
		{
		case 0:
			return 0;
		case 1:
			insert();
			break;
		case 2:
			if (head)
			{
				Delete();
			}
			else
			{
				
				scanf("%d", &num);
				state[cont] = num;
			}
			break;
		case 3:
			if (head)
			{
				search();
			}
			else
			{//printf("shenm\n");
				 scanf("%d", &num);
				printf("-1\n");
			}
			break;
		case 4:
			if (head)
			{
				init();
				search1();
			}
			else
			{
				scanf("%d", &num);
				printf("0\n");
			}
			break;
		case 5:
			if (head)
			{
				init();
				search2();
			}
			else
			{
				 scanf("%d", &num);
				printf("0\n");
			}
			break;


		}


	}
}
