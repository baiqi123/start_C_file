#define  _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"

static int Find_byname(struct Contact* ps, char name[MAX_NAME]);//����

void CheckCapacity(struct Contact* ps);//��������Ƿ��㹻

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
	//���Ƿϰ� ��
	//memset(ps->date, 0, sizeof(ps->date));
	//ps->size = 0; //����ͨѶ¼��ʼֻ��0��Ԫ��
}

void CheckCapacity(struct Contact* ps)
{
	if (ps->size == ps->capacity)
	{
		struct Peoinfo* ptr = realloc(ps->date, (ps->capacity + 2) * sizeof(struct Peoinfo));//����
		if (ptr != NULL)
		{
			ps->date = ptr;
			ps->capacity += 2;
			printf("���ݳɹ���\n");
		}
		else printf("����ʧ�ܣ�\n");
	}
}

void Add_contact(struct Contact* ps)//��Ӻ���
{
	/*if (ps->size == MAX) {
		printf("ͨѶ¼������\n");
	}
	else {
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
	}*/

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

static int Find_byname(struct Contact* ps,char name[MAX_NAME])//����
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

void  Del_contact(struct Contact* ps)//ɾ������
{
	char name[MAX_NAME];
	int pos = 0;
	printf("������Ҫɾ����ϵ�˵�������");
	scanf("%s", name);
	//1.����Ҫɾ��������ʲôλ��
	//�ҵ��˷�����������Ԫ���±꣬�Ҳ�������-1
	pos = Find_byname(ps, name);
	
	if (pos == -1)
	{
		printf("��ϵ�˲����ڣ�\n");
	}
	else
	{
		//ɾ������
		int j = 0;
		for (j = pos; j < ps->size-1; j++)
		{
			ps->date[j] = ps->date[j+1];
		}
		ps->size--;
		printf("ɾ���ɹ���\n");
	}
}

void Search_contact(struct Contact* ps)//��������
{
	printf("������Ҫ������ϵ�˵�������");
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
		printf("%-10s\t%-3s\t%-12s\t%-5s\n", "����", "�Ա�", "�绰", "ְλ");
		printf("%-10s\t%-3s\t%-12s\t%-5s\n",
			ps->date[pos].name,
			ps->date[pos].sex,
			ps->date[pos].tele,
			ps->date[pos].job);
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
		printf("������������");
		scanf("%s", ps->date[pos].name);
		printf("�������Ա�");
		scanf("%s", ps->date[pos].sex);
		printf("������绰��");
		scanf("%s", ps->date[pos].tele);
		printf("������ְλ��");
		scanf("%s", ps->date[pos].job);

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