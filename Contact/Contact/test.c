#define  _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"

void menu()
{
	printf("---------У԰ͨѶ¼����ϵͳ------------\n");
	printf("-------------1.��Ӻ���----------------\n");
	printf("-------------2.ɾ������----------------\n");
	printf("-------------3.��������----------------\n");
	printf("-------------4.�޸���Ϣ----------------\n");
	printf("-------------5.�����б�----------------\n");
	printf("-------------6.����Ⱥ��----------------\n");
	printf("-------------7.������Ϣ----------------\n");
	printf("-------------0.�˳�ͨѶ¼--------------\n");
	printf("-----------------------------------------");
	printf("\n");
}
int main()
{
	int input = 0;
	//����ͨѶ¼
	struct Contact con;//con���Ǵ�����ͨѶ¼
	//��ʼ��ͨѶ¼
	Initcontact(&con);
	//
	do {
		printf("\n");
		printf("����������ѡ��:");
		menu();
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
				printf("�˳�ͨѶ¼��");
				Save_contact(&con);
				Destroy_contact(&con);
				break;
			default:
				printf("ѡ�����");
				break;
			}
	}while(input);

	return 0;
}