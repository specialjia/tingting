#define _CRT_SECURE_NO_WARNINGS
#include "cmdline.h"
#include <stdlib.h>
#include <stdio.h>

int CmdLine()
{
	system("calc");
	system("mspaint");
	system("regedit");
	system("tasklist");


}

int CmdCalc()
{
	system("calc");
}

int CmdMspaint()
{
	system("mspaint");
}

int CmdRegedit()
{
	system("regedit");
}

int CmdTasklist()
{
	system("tasklist");

}

int CmdSelector()
{
	int cmd;
	printf("�������������� 1��2��3��4 ");

	scanf("%d", &cmd);

	if (1 == cmd)
	{
		CmdCalc();
	}
	else if (2 == cmd)
	{
		CmdMspaint();
	}
	else if (3 == cmd)
	{
		CmdRegedit();
	}
	else if (4 == cmd)
	{
		CmdTasklist();
	}
	else
	{
		printf("�������,�밴��Ҫ��������Ϣ ");
	}
}

int CmdSelectorOnSwitch()
{
	int cmd = 0;
	printf("�������������� 1��2��3��4\n");
	scanf("%d", &cmd);
	switch (cmd)
	{
	case 1:
		CmdCalc();
		break;
	case 2:
		CmdMspaint();
		break;
	case 3:
		CmdRegedit();
		break;
	case 4:
		CmdTasklist();
		break;
	default:
		printf("�������,�밴����ʾ��Ϣ����\n ");

	}

}

int CmdSelectorOnWhile()
{
	int cmd;
	char ch;

	do
	{
		printf("�������������� 1��2��3��4\n");
		scanf("%d", &cmd);

		/*
		switch (cmd)
		{
		case 1:
			CmdCalc();
			break;
		case 2:
			CmdMspaint();
			break;
		case 3:
			CmdRegedit();
			break;
		case 4:
			CmdTasklist();
			break;
		default:
			printf("�������,�밴����ʾ��Ϣ��ȷ����������\n");
		}
		*/
		if (1 == cmd)
		{
			CmdCalc();
		}
		else if (2 == cmd)
		{
			CmdMspaint();
		}
		else if (3 == cmd)
		{
			CmdRegedit();
		}
		else if (4 == cmd)
		{
			CmdTasklist();
		}
		else
		{
			printf("�������,�밴��Ҫ��������Ϣ ");
		}

		printf("����Ҫ������? (Y/N): ");
		scanf(" %c\n", &ch);
		printf("%c", ch);
	}
	while ('N' != ch);

}

int ScanfTest()
{
	char character1[12] = {0};
	char character2=0;
	
	scanf(" %s", &character1);
	printf("%s1", character1);

	scanf(" %c", &character2);
	printf("%c2", character2);
	return 0;
}
