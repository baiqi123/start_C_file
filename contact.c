#define  _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"
int Find_byname(struct Contact* ps, char name[MAX_NAME])//����
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
}//****���ҵ������±꣬��δ�ҵ����� -1��****
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
int Find_mohu(char* str, char* target) //str Ϊ�û������Ҫ����������
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
void CheckCapacity(struct Contact* ps)//�������
{
	if (ps->size == ps->capacity)
	{
		struct Peoinfo* ptr = realloc(ps->date, (ps->capacity + 2) * sizeof(struct Peoinfo));//����
		if (ptr != NULL)
		{
			ps->date = ptr;
			ps->capacity += 2;
		}
		else printf("����ʧ�ܣ�\n");
	}
}
void Load_contact(struct Contact* ps)//���ش洢��Ϣ
{
	struct Peoinfo tmp = { 0 };
	FILE* pfRead = fopen("contact.date","rb");
	if (pfRead == NULL)
	{
		printf("Load_contact::%s\n", strerror(errno));//����
		return;
	}
	//��ȡ�ļ��ŵ�ͨѶ¼�У�
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
		printf("�ļ��޷��򿪣�\n");
		return;
	}

}
//��Ҫ�������ܣ�
void Initcontact(struct Contact* ps)//��ʼ��
{
	ps->date = (struct Peoinfo*)malloc(DEFAULT_SZ * sizeof(struct Peoinfo));
	if (ps->date == NULL) {
		return;
	}
	ps->size = 0;
	ps->capacity = DEFAULT_SZ;
	Load_contact(ps);//ʵ����Ϣ�Ĵ�������
}

void Add_contact(struct Contact* ps)//��Ӻ���
{
	CheckCapacity(ps);//��⵱ǰͨѶ¼�����������������ݡ�
	printf("������������");
	scanf("%s", ps->date[ps->size].name);
	printf("�������Ա�");
	scanf("%s", ps->date[ps->size].sex);
	printf("������绰��");
	scanf("%s", ps->date[ps->size].tele);
	printf("������ְλ��");
	scanf("%s", ps->date[ps->size].job);

	ps->size++;
	printf("��ӳɹ���\n");
}

void Show_contact(const struct Contact* ps)//�����б�
{
	if (ps->size == 0) {
		printf("ͨѶ¼Ϊ�ա�\n");
	}
	else {
		int i;
		printf("%-10s\t%-3s\t%-12s\t%-5s\n", "����", "�Ա�", "�绰", "ְλ");
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

void Del_contact(struct Contact* ps)//ɾ������
{
	char name[MAX_NAME];
	int pos = 0;
	printf("������Ҫɾ����ϵ�˵�������");
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
		printf("ɾ���ɹ���\n");
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
		printf("��ѡ����Ҫɾ������ϵ�ˣ�");
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
			printf("ɾ���ɹ���\n");
		}
	}
}

void Search_contact(struct Contact* ps, int* SECOND)//���Һ���
{
	printf("������Ҫ������ϵ�˵�������");
	int pos = 0;
	char name[MAX_NAME];
	scanf("%s", name);
	pos = Find_byname(ps, name);
	if (pos != -1)
	{
		printf("%-10s\t%-3s\t%-12s\t%-5s\n", "����", "�Ա�", "�绰", "ְλ");
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

void Modify_contact(struct Contact* ps)//������Ϣ
{
	printf("������Ҫ�޸ĵ���ϵ�˵�������");
	int pos = 0;
	char name[MAX_NAME];
	scanf("%s", name);
	pos = Find_byname(ps, name);
	if (pos == -1)
	{
		printf("��ϵ�˲����ڣ�\n");

	}
	else
	{
		printf("��ѡ����Ҫ�޸ĵ���Ϣ��\n");
		printf("1.����	2.�Ա�	3.�绰	4.ְλ\n");
		int inp;
		scanf("%d", &inp);
		switch (inp) {
		case 1:
			printf("������������");
			scanf("%s", ps->date[pos].name);
			break;
		case 2:
			printf("�������Ա�");
			scanf("%s", ps->date[pos].sex);
			break;
		case 3:
			printf("������绰��");
			scanf("%s", ps->date[pos].tele);
			break;
		case 4:
			printf("������ְλ��");
			scanf("%s", ps->date[pos].job);
			break;
		
		}
		printf("�޸���ɣ�\n");
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
	//���浽�ļ���
	int i;
	for (i = 0; i < ps->size; i++)
	{
		fwrite(&(ps->date[i]),sizeof(struct Peoinfo),1,pfWrite);
	}
	fclose(pfWrite);
	pfWrite = NULL;
	printf("����ɹ���\n");
}

void Recent_contact(struct Contact* ps, int* SECOND)
{
	TIMES[0]++;
	if (ps->size == 0) {
		printf("ͨѶ¼Ϊ�ա�\n");
	}
	else {
		int i;
		printf("%-10s\t%-3s\t%-12s\t%-5s\n", "����", "�Ա�", "�绰", "ְλ");
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
		printf("\n\n0.������ҳ		1.��������ϵ��\n");
		printf("����������ѡ��\n");
		int inp;
		scanf("%d", &inp);
		if (inp == 1)
		{
			printf("������������");
			char name[MAX_NAME];
			scanf("%s", name);
			inp = Find_byname(ps, name);
			TIMES[inp] += 2;
			printf("����ɹ���\n");
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
	printf("1.�����µ�Ⱥ��	2.�޸�����Ⱥ��\n");
	printf("����������ѡ��\n");
	int input1;
	scanf("%d", &input1);
	if (input1 == 1)
	{
		NUMBERS++;
		printf("������Ⱥ�����ƣ�");
		scanf("%s", group_name[NUMBERS]);
		printf("������Ҫ�����ϵ�˵�������");
		scanf("%d", &add);
		count[NUMBERS] += add;
		for (int i = 0 ; i < add; i++)
		{
			printf("������������");
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
		printf("������Ҫ�޸ĵ�Ⱥ���ţ�\n");
		int fix_group = 0;
		scanf("%d", &fix_group);
		printf("������Ҫ�����ϵ�˵�������");
		scanf("%d", &add);
		for (int i = count[fix_group]; i < count[fix_group] + add; i++)
		{
			printf("������������");
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
	printf("����������ѡ��\n");
	int In;
	scanf("%d", &In);
	printf("%s:\n", group_name[In]);
	printf("%-10s\t%-3s\t%-12s\t%-5s\n", "����", "�Ա�", "�绰", "ְλ");
	for (int i = 0; i < count[In]; i++)
	{
		printf("%-10s\t%-3s\t%-12s\t%-5s\n",
			ps->date[member[In][i]].name,
			ps->date[member[In][i]].sex,
			ps->date[member[In][i]].tele,
			ps->date[member[In][i]].job);
	}
	printf("\n\n");
	printf("0.������ҳ	1.��ʦ	2.ͬѧ	3.ѧ��/ѧ��\n");
	printf("����������ѡ��\n");
	scanf("%d", &In);
	switch (In) {
	case 1:
		Find_byjob(ps, "��ʦ");
		break;
	case 2:
		Find_byjob(ps, "ͬѧ");
		break;
	case 3:
		Find_byjob(ps, "ѧ��");
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
