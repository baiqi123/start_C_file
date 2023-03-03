#define  _CRT_SECURE_NO_WARNINGS 1
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_JOB 10 
#define MAX_GROUP 5
#define MAX_MEMBER 100
#define DEFAULT_SZ 3 //ͨѶ¼��ʼ����

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>  //����ͷ�ļ�
char group_name[MAX_GROUP][MAX_NAME];
int member[MAX_GROUP][MAX_MEMBER];
int count[MAX_GROUP];
int NUMBERS;
enum Option {
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	VIEW,
	CREATE,
	SAVE,
	RECENT
};//�˵���ʹ��Ŀ¼

struct Peoinfo {			//��ϵ����Ϣ
	char name[MAX_NAME];	//����
	char sex[MAX_SEX];		//�Ա�
	char tele[MAX_TELE];	//�绰
	char job[MAX_JOB];		//ְλ
};

struct Groupinfo {
	char Group_name[MAX_GROUP][MAX_NAME];	//Ⱥ������
	int Member[MAX_GROUP][MAX_MEMBER];		//Ⱥ���Ա
	int Count;					//��Ա����
};
int TIMES[MAX_MEMBER];

struct Contact{			 //ͨѶ¼����
	struct Peoinfo *date;//�����ϵ����Ϣ
	int size;			 //��¼��ǰ���е�Ԫ������
	int capacity;		 //��ǰͨѶ¼���������
};

//����������
void Initcontact(struct Contact* ps);//��ʼ��ͨѶ¼
void Add_contact(struct Contact* ps);//���Ӻ���
void Show_contact(const struct Contact* ps);//�����б�
void Del_contact(struct Contact* ps);//ɾ������
void Search_contact(struct Contact* ps, int* SECOND);//���Һ���
void Modify_contact(struct Contact* ps);//�޸���Ϣ
void Destroy_contact(struct Contact* ps);//
void Save_contact(struct Contact* ps);//�����ļ�
void Load_contact(struct Contact* ps);//���ر�����Ϣ
void Recent_contact(struct Contact* ps, int* SECOND);//�����ϵ��
void Create_group(struct Contact* ps, struct Groupinfo* qun);//����Ⱥ��
void View_group(struct Contact* ps, struct Groupinfo* qun);//�鿴Ⱥ��
void Save_group(struct Contact* ps);