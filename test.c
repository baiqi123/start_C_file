#define  _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"
void menu()
{
	printf("					---------校园通讯录管理系统------------\n");
	printf("					-------------1.添加好友----------------\n");
	printf("					-------------2.删除好友----------------\n");
	printf("					-------------3.搜索好友----------------\n");
	printf("					-------------4.修改信息----------------\n");
	printf("					-------------5.好友列表----------------\n");
	printf("					-------------6.查看群组----------------\n");
	printf("					-------------7.创建群组----------------\n");
	printf("					-------------8.保存信息----------------\n");
	printf("					-------------9.最近联系人--------------\n");
	printf("					-------------0.退出通讯录--------------\n");
	printf("					---------------------------------------\n");
	printf("\n");
}
int main()
{
	int input = 0;
	struct Contact con;//创建通讯录
	struct Groupinfo Sort;
	Initcontact(&con);	//初始化通讯录
	do {
		printf("\n");
		menu();
		printf("请输入您的选择:");
		scanf("%d", &input);	//获取用户输入
		switch (input)
		{
		case ADD:
			Add_contact(&con);
			break;
		case DEL:
			Del_contact(&con);
			break;
		case SEARCH:
			Search_contact(&con, TIMES);
			break;
		case MODIFY:
			Modify_contact(&con);
			break;
		case SHOW:
			Show_contact(&con);
			break;
		case VIEW:
			View_group(&con, &Sort);
			break;
		case CREATE:
			Create_group(&con, &Sort);
			break;
		case SAVE:
			Save_contact(&con);
			Save_group(&con);
			break;
		case RECENT:
			Recent_contact(&con, TIMES);
			break;
		case EXIT:
			printf("退出通讯录。");
			Save_contact(&con);
			Destroy_contact(&con);
			break;
		default:
			printf("选择错误！");
			break;
		}
	} while (input);

	return 0;
}
