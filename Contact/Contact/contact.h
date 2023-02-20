#define  _CRT_SECURE_NO_WARNINGS 1

//#define MAX 1000
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_JOB 10 
#define DEFAULT_SZ 3 //ͨѶ¼��ʼ����

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>  //����ͷ�ļ�

enum Option {
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT,
	SAVE
};//�˵���ʹ��Ŀ¼

struct Peoinfo {		//��ϵ����Ϣ
	char name[MAX_NAME];
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char job[MAX_JOB];
};

struct Contact{			 //ͨѶ¼����
	struct Peoinfo *date;//�����ϵ����Ϣ
	int size;			 //��¼��ǰ���е�Ԫ������
	int capacity;		 //��ǰͨѶ¼���������
};

//����������
void Initcontact(struct Contact* ps);//��ʼ��ͨѶ¼
void Add_contact(struct Contact* ps);//��Ӻ���
void Show_contact(const struct Contact* ps);//�����б�
void Del_contact(struct Contact* ps);//ɾ������
void Search_contact(struct Contact* ps);//���Һ���
void Modify_contact(struct Contact* ps);//�޸���Ϣ
void Destroy_contact(struct Contact* ps);//
void Save_contact(struct Contact* ps);//�����ļ�
void Load_contact(struct Contact* ps);//���ر�����Ϣ