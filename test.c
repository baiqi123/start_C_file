#define  _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"
void menu()
{
	printf("					---------У԰ͨѶ¼����ϵͳ------------\n");
	printf("					-------------1.��Ӻ���----------------\n");
	printf("					-------------2.ɾ������----------------\n");
	printf("					-------------3.��������----------------\n");
	printf("					-------------4.�޸���Ϣ----------------\n");
	printf("					-------------5.�����б�----------------\n");
	printf("					-------------6.�鿴Ⱥ��----------------\n");
	printf("					-------------7.����Ⱥ��----------------\n");
	printf("					-------------8.������Ϣ----------------\n");
	printf("					-------------9.�����ϵ��--------------\n");
	printf("					-------------0.�˳�ͨѶ¼--------------\n");
	printf("					---------------------------------------\n");
	printf("\n");
}
int main()
{
	int input = 0;
	struct Contact con;//����ͨѶ¼
	struct Groupinfo Sort;
	Initcontact(&con);	//��ʼ��ͨѶ¼
	do {
		printf("\n");
		menu();
		printf("����������ѡ��:");
		scanf("%d", &input);	//��ȡ�û�����
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
			printf("�˳�ͨѶ¼��");
			Save_contact(&con);
			Destroy_contact(&con);
			break;
		default:
			printf("ѡ�����");
			break;
		}
	} while (input);

	return 0;
}
