#define  _CRT_SECURE_NO_WARNINGS 1

//#define MAX 1000
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_JOB 10 
#define DEFAULT_SZ 3 //通讯录初始容量

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>  //报错头文件

enum Option {
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT,
	SAVE
};//菜单的使用目录

struct Peoinfo {		//联系人信息
	char name[MAX_NAME];
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char job[MAX_JOB];
};

struct Contact{			 //通讯录类型
	struct Peoinfo *date;//存放联系人信息
	int size;			 //记录当前已有的元素数量
	int capacity;		 //当前通讯录的最大容量
};

//声明函数：
void Initcontact(struct Contact* ps);//初始化通讯录
void Add_contact(struct Contact* ps);//添加好友
void Show_contact(const struct Contact* ps);//好友列表
void Del_contact(struct Contact* ps);//删除好友
void Search_contact(struct Contact* ps);//查找好友
void Modify_contact(struct Contact* ps);//修改信息
void Destroy_contact(struct Contact* ps);//
void Save_contact(struct Contact* ps);//保存文件
void Load_contact(struct Contact* ps);//加载保存信息