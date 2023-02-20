#define  _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"

void menu()
{
	printf("---------校园通讯录管理系统------------\n");
	printf("-------------1.添加好友----------------\n");
	printf("-------------2.删除好友----------------\n");
	printf("-------------3.搜索好友----------------\n");
	printf("-------------4.修改信息----------------\n");
	printf("-------------5.好友列表----------------\n");
	printf("-------------6.创建群组----------------\n");
	printf("-------------7.保存信息----------------\n");
	printf("-------------0.退出通讯录--------------\n");
	printf("-----------------------------------------");
	printf("\n");
}
int main()
{
	int input = 0;
	//创建通讯录
	struct Contact con;//con就是创建的通讯录
	//初始化通讯录
	Initcontact(&con);
	//
	do {
		printf("\n");
		printf("请输入您的选择:");
		menu();
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
				Search_contact(&con);
				break;
			case MODIFY:
				Modify_contact(&con);
				break;
			case SHOW:
				Show_contact(&con);
				break;
			case SORT:
				break;
			case SAVE:
				Save_contact(&con);
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
	}while(input);

	return 0;
}