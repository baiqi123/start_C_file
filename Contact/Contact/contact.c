#define  _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"

static int Find_byname(struct Contact* ps, char name[MAX_NAME]);//遍历

void CheckCapacity(struct Contact* ps);//检查容量是否足够

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
	//这是废案 ：
	//memset(ps->date, 0, sizeof(ps->date));
	//ps->size = 0; //设置通讯录初始只有0个元素
}

void CheckCapacity(struct Contact* ps)
{
	if (ps->size == ps->capacity)
	{
		struct Peoinfo* ptr = realloc(ps->date, (ps->capacity + 2) * sizeof(struct Peoinfo));//增容
		if (ptr != NULL)
		{
			ps->date = ptr;
			ps->capacity += 2;
			printf("增容成功！\n");
		}
		else printf("增容失败！\n");
	}
}

void Add_contact(struct Contact* ps)//添加好友
{
	/*if (ps->size == MAX) {
		printf("通讯录已满！\n");
	}
	else {
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
	}*/

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

static int Find_byname(struct Contact* ps,char name[MAX_NAME])//遍历
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

void  Del_contact(struct Contact* ps)//删除好友
{
	char name[MAX_NAME];
	int pos = 0;
	printf("请输入要删除联系人的姓名：");
	scanf("%s", name);
	//1.查找要删除的人在什么位置
	//找到了返回名字所在元素下标，找不到返回-1
	pos = Find_byname(ps, name);
	
	if (pos == -1)
	{
		printf("联系人不存在！\n");
	}
	else
	{
		//删除数据
		int j = 0;
		for (j = pos; j < ps->size-1; j++)
		{
			ps->date[j] = ps->date[j+1];
		}
		ps->size--;
		printf("删除成功！\n");
	}
}

void Search_contact(struct Contact* ps)//搜索好友
{
	printf("请输入要查找联系人的姓名：");
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
		printf("%-10s\t%-3s\t%-12s\t%-5s\n", "姓名", "性别", "电话", "职位");
		printf("%-10s\t%-3s\t%-12s\t%-5s\n",
			ps->date[pos].name,
			ps->date[pos].sex,
			ps->date[pos].tele,
			ps->date[pos].job);
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
		printf("请输入姓名：");
		scanf("%s", ps->date[pos].name);
		printf("请输入性别：");
		scanf("%s", ps->date[pos].sex);
		printf("请输入电话：");
		scanf("%s", ps->date[pos].tele);
		printf("请输入职位：");
		scanf("%s", ps->date[pos].job);

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