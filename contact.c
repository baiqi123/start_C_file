#define  _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"
int Find_byname(struct Contact* ps, char name[MAX_NAME])//遍历
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (strcmp(ps->date[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;
}//****若找到返回下标，若未找到返回 -1；****
int Find_byjob(struct Contact* ps, char job[MAX_JOB])
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (strcmp(ps->date[i].job, job) == 0)
		{
			printf("%-10s\t%-3s\t%-12s\t%-5s\n",
				ps->date[i].name,
				ps->date[i].sex,
				ps->date[i].tele,
				ps->date[i].job);
		}
	}
}
int Find_mohu(char* str, char* target) //str 为用户输入的要搜索的姓名
{
	int i, j, tag = 0;
	for (i = 0; i < strlen(str); i += 2)
	{
		for (j = 0; j < strlen(target); j += 2)
		{
			if (str[i] == target[j] && str[i + 1] == target[j + 1])
				tag++;
		}
		return tag == strlen(str) / 2 ? 1 : 0;
	}
}
void CheckCapacity(struct Contact* ps)//检查容量
{
	if (ps->size == ps->capacity)
	{
		struct Peoinfo* ptr = realloc(ps->date, (ps->capacity + 2) * sizeof(struct Peoinfo));//增容
		if (ptr != NULL)
		{
			ps->date = ptr;
			ps->capacity += 2;
		}
		else printf("增容失败！\n");
	}
}
void Load_contact(struct Contact* ps)//加载存储信息
{
	struct Peoinfo tmp = { 0 };
	FILE* pfRead = fopen("contact.date","rb");
	if (pfRead == NULL)
	{
		printf("Load_contact::%s\n", strerror(errno));//报错
		return;
	}
	//读取文件放到通讯录中：
	while (fread(&tmp, sizeof(struct Peoinfo), 1, pfRead))
	{
		CheckCapacity(ps);
		ps->date[ps->size] = tmp;
		ps->size++;
	}
	fclose(pfRead);
	pfRead = NULL;
}
void Load_group(struct Contact* ps)
{
	FILE* fp = fopen("date.txt", "w");
	if (fp == NULL)
	{
		printf("文件无法打开！\n");
		return;
	}

}
//主要函数功能：
void Initcontact(struct Contact* ps)//初始化
{
	ps->date = (struct Peoinfo*)malloc(DEFAULT_SZ * sizeof(struct Peoinfo));
	if (ps->date == NULL) {
		return;
	}
	ps->size = 0;
	ps->capacity = DEFAULT_SZ;
	Load_contact(ps);//实现信息的储存再现
}

void Add_contact(struct Contact* ps)//添加好友
{
	CheckCapacity(ps);//检测当前通讯录的容量，若满则增容。
	printf("请输入姓名：");
	scanf("%s", ps->date[ps->size].name);
	printf("请输入性别：");
	scanf("%s", ps->date[ps->size].sex);
	printf("请输入电话：");
	scanf("%s", ps->date[ps->size].tele);
	printf("请输入职位：");
	scanf("%s", ps->date[ps->size].job);

	ps->size++;
	printf("添加成功！\n");
}

void Show_contact(const struct Contact* ps)//好友列表
{
	if (ps->size == 0) {
		printf("通讯录为空。\n");
	}
	else {
		int i;
		printf("%-10s\t%-3s\t%-12s\t%-5s\n", "姓名", "性别", "电话", "职位");
		for (i = 0; i < ps->size; i++)
		{
			printf("%-10s\t%-3s\t%-12s\t%-5s\n",
				ps->date[i].name,
				ps->date[i].sex,
				ps->date[i].tele,
				ps->date[i].job);
		}

	}
}

void Del_contact(struct Contact* ps)//删除好友
{
	char name[MAX_NAME];
	int pos = 0;
	printf("请输入要删除联系人的姓名：");
	scanf("%s", name);
	pos = Find_byname(ps, name);
	if (pos != -1)
	{
		int j = 0;
		for (j = pos; j < ps->size - 1; j++)
		{
			ps->date[j] = ps->date[j + 1];
		}
		ps->size--;
		printf("删除成功！\n");
	}
	else
	{
		int i = 0;
		for (i = 0; i < ps->size; i++)
		{
			if (Find_mohu(name, ps->date[i].name))
			{
				printf("%-10s\t%-3s\t%-12s\t%-5s\n",
					ps->date[i].name,
					ps->date[i].sex,
					ps->date[i].tele,
					ps->date[i].job);
			}
		}
		printf("请选择需要删除的联系人：");
		scanf("%s", name);
		pos = Find_byname(ps, name);
		if (pos != -1)
		{
			int j = 0;
				for (j = pos; j < ps->size - 1; j++)
			{
				ps->date[j] = ps->date[j + 1];
			}
			ps->size--;
			printf("删除成功！\n");
		}
	}
}

void Search_contact(struct Contact* ps, int* SECOND)//查找好友
{
	printf("请输入要查找联系人的姓名：");
	int pos = 0;
	char name[MAX_NAME];
	scanf("%s", name);
	pos = Find_byname(ps, name);
	if (pos != -1)
	{
		printf("%-10s\t%-3s\t%-12s\t%-5s\n", "姓名", "性别", "电话", "职位");
		printf("%-10s\t%-3s\t%-12s\t%-5s\n",
			ps->date[pos].name,
			ps->date[pos].sex,
			ps->date[pos].tele,
			ps->date[pos].job);
		TIMES[pos]++;
	}
	else
	{
		int i = 0;
		for (i = 0; i < ps->size; i++)
		{
			if (Find_mohu(name, ps->date[i].name))
			{
				printf("%-10s\t%-3s\t%-12s\t%-5s\n",
					ps->date[i].name,
					ps->date[i].sex,
					ps->date[i].tele,
					ps->date[i].job);
			}
		}
	}
}

void Modify_contact(struct Contact* ps)//修正信息
{
	printf("请输入要修改的联系人的姓名：");
	int pos = 0;
	char name[MAX_NAME];
	scanf("%s", name);
	pos = Find_byname(ps, name);
	if (pos == -1)
	{
		printf("联系人不存在！\n");

	}
	else
	{
		printf("请选择需要修改的信息：\n");
		printf("1.姓名	2.性别	3.电话	4.职位\n");
		int inp;
		scanf("%d", &inp);
		switch (inp) {
		case 1:
			printf("请输入姓名：");
			scanf("%s", ps->date[pos].name);
			break;
		case 2:
			printf("请输入性别：");
			scanf("%s", ps->date[pos].sex);
			break;
		case 3:
			printf("请输入电话：");
			scanf("%s", ps->date[pos].tele);
			break;
		case 4:
			printf("请输入职位：");
			scanf("%s", ps->date[pos].job);
			break;
		
		}
		printf("修改完成！\n");
	}
}

void Destroy_contact(struct Contact* ps)
{
	free(ps->date);
	ps->date = NULL;
}

void Save_contact(struct Contact* ps)
{
	FILE* pfWrite = fopen("contact.date ", "wb");
	if (pfWrite == NULL)
	{
		printf("Save_contact::%s\n", strerror(errno));
		return ;
	}
	//保存到文件中
	int i;
	for (i = 0; i < ps->size; i++)
	{
		fwrite(&(ps->date[i]),sizeof(struct Peoinfo),1,pfWrite);
	}
	fclose(pfWrite);
	pfWrite = NULL;
	printf("保存成功！\n");
}

void Recent_contact(struct Contact* ps, int* SECOND)
{
	TIMES[0]++;
	if (ps->size == 0) {
		printf("通讯录为空。\n");
	}
	else {
		int i;
		printf("%-10s\t%-3s\t%-12s\t%-5s\n", "姓名", "性别", "电话", "职位");
		for (i = 0; i < ps->size; i++)
		{
			if (TIMES[i] >= 1)
			{
				printf("%-10s\t%-3s\t%-12s\t%-5s\n",
					ps->date[i].name,
					ps->date[i].sex,
					ps->date[i].tele,
					ps->date[i].job);
			}
		}
		printf("\n\n0.返回主页		1.添加最近联系人\n");
		printf("请输入您的选择：\n");
		int inp;
		scanf("%d", &inp);
		if (inp == 1)
		{
			printf("请输入姓名：");
			char name[MAX_NAME];
			scanf("%s", name);
			inp = Find_byname(ps, name);
			TIMES[inp] += 2;
			printf("保存成功！\n");
		}
		else
		{
			return;
		}
	}
}

void Create_group(struct Contact* ps, struct Groupinfo* qun)
{
	int add = 0;
	printf("1.创建新的群组	2.修改现有群组\n");
	printf("请输入您的选择：\n");
	int input1;
	scanf("%d", &input1);
	if (input1 == 1)
	{
		NUMBERS++;
		printf("请输入群组名称：");
		scanf("%s", group_name[NUMBERS]);
		printf("请输入要添加联系人的人数：");
		scanf("%d", &add);
		count[NUMBERS] += add;
		for (int i = 0 ; i < add; i++)
		{
			printf("请输入姓名：");
			char name[MAX_NAME] = { 0 };
			scanf("%s", name);
			int pos;
			pos = Find_byname(ps, name);
			member[NUMBERS][i] = pos;
		}
	}
	if (input1 == 2)
	{
		for (int i = 0; i < 3; i++)
		{
			printf("%s\n", group_name[i]);
		}
		printf("请输入要修改的群组编号：\n");
		int fix_group = 0;
		scanf("%d", &fix_group);
		printf("请输入要添加联系人的人数：");
		scanf("%d", &add);
		for (int i = count[fix_group]; i < count[fix_group] + add; i++)
		{
			printf("请输入姓名：");
			char name[MAX_NAME] = { 0 };
			scanf("%s", name);
			int pos;
			pos = Find_byname(ps, name);
			member[fix_group][i] = pos;
		}
		count[fix_group] += add;
	}
}

void View_group(struct Contact* ps, struct Groupinfo* qun)
{
	for (int i = 1; i <= NUMBERS; i++)
	{
		printf("%d.%s\n", i, group_name[i]);
	}
	printf("请输入您的选择：\n");
	int In;
	scanf("%d", &In);
	printf("%s:\n", group_name[In]);
	printf("%-10s\t%-3s\t%-12s\t%-5s\n", "姓名", "性别", "电话", "职位");
	for (int i = 0; i < count[In]; i++)
	{
		printf("%-10s\t%-3s\t%-12s\t%-5s\n",
			ps->date[member[In][i]].name,
			ps->date[member[In][i]].sex,
			ps->date[member[In][i]].tele,
			ps->date[member[In][i]].job);
	}
	printf("\n\n");
	printf("0.返回主页	1.老师	2.同学	3.学长/学姐\n");
	printf("请输入您的选择：\n");
	scanf("%d", &In);
	switch (In) {
	case 1:
		Find_byjob(ps, "老师");
		break;
	case 2:
		Find_byjob(ps, "同学");
		break;
	case 3:
		Find_byjob(ps, "学长");
		break;
	case 0:
		return;
	}
}

void Save_group(struct Contact* ps)
{
	FILE* fp;
	int i, d;
	fp = fopen("date.txt", "w");
	if (fp == NULL)
	{
		printf("File cannot open\n");
		exit(0);
	}
	fprintf(fp, "%d\t,", NUMBERS);
	for (i = 0; i < NUMBERS; i++)
	{
		fprintf(fp, "%s\t%d\t%d\t\n",*group_name[i],*member[i],count[i]);
	}
	for (i = 0; i < ps->size; i++)
	{
		fprintf(fp, "%d\t", TIMES[i]);
	}
	fclose(fp);
	return 0;
}
