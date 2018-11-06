#include <stdio.h>
#include <string.h>	//strcmp ����



typedef struct date
{
	int year;
	int month;
	int day;
} date;

typedef struct inform
{
	char name[20];
	date bday;
	char gender;
	char address[30];
	int number[11];
} info;

void struct_print(info *ary[], int index);
void sort_name(info *ary[], int index);
void sort_bday_higher(info *ary[], int index);
void sort_bday_lower(info *ary[], int index);

int main()
{
	info ary[10];
	int index;


	while (1)
	{
		printf("�ּ� 5��, �ִ� 10���� ���� ������ �Է��� �� �ֽ��ϴ�. �� ���� ���� ������ �η��Ͻðڽ��ϱ�? (0�� �Է��ϸ� ����) :");
		scanf_s("%d", &index, 1);

		if (5 <= index && index <= 10)
		{
			for (int i = 0; i < index; i++)
			{
				printf("%d��° �Է��� �����մϴ�.\n", i + 1);

				printf("�̸�(20�� ������ ���ڿ�):");
				scanf_s("%s", &ary[i].name, 20);
				scanf_s("%*c");

				printf("�������(xxxx-xx-xx�� ����):");
				scanf_s("%d-%d-%d", &ary[i].bday.year, &ary[i].bday.month, &ary[i].bday.day, 3);
				scanf_s("%*c");
				printf("%d-%02d-%02d", ary[i].bday.year, ary[i].bday.month, ary[i].bday.day);

				while (1)
				{
					printf("����(������ m �Ǵ� M, ������ w �Ǵ� W):");
					scanf_s("%c", &ary[i].gender, 1);
					scanf_s("%*c");
					if (ary[i].gender != 'w' && ary[i].gender != 'W' && ary[i].gender != 'm' && ary[i].gender != 'M')
					{
						printf("�߸��Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���.\n");
						continue;
					}
					else
						break;
				}


				printf("�ּ�(30�� ������ ���ڿ�):");
				gets(ary[i].address);

				printf("��ȣ(������ ���� ���ӵ� 11�ڸ� ����):");
				char num_tmp[11];
				gets(num_tmp);

				for (int j = 0; j < 11; j++)
				{
					ary[i].number[j] = (int)*(num_tmp + j);
				}

				printf("\n");
			}



			info *ptr = ary;

			printf("�Էµ� ���� �״�� ����մϴ�.\n");
			struct_print(ptr, index);

			sort_name(ptr, index);
			printf("�̸� ������������ �����Ͽ� ����մϴ�.\n");
			struct_print(ptr, index);

			sort_bday_higher(ptr, index);
			printf("������� ������������ �����Ͽ� ����մϴ�.\n");
			struct_print(ptr, index);



			break;
		}
		if (index == 0)
		{
			printf("0�� �Է��Ͽ� �����մϴ�.\n");
			break;
		}
		else
		{
			printf("������ ��� ���� �Է��ϼ̽��ϴ�. 5�� 10������ ������ �Է����ּ���.\n");
			continue;
		}

	}



	return;
}

void struct_print(info *ary[], int index)
{
	printf("%-10s %-16s %-5s %-30s %-13s\n", "�̸�", "�������", "����", "�ּ�", "��ȣ");



	for (int k = 0; k < index; k++)
	{
		printf("%-10s %d�� %02d�� %02d�� %-5c %-30s %d%d%d-%d%d%d%d-%d%d%d%d\n", ary[k]->name, ary[k]->bday.year, ary[k]->bday.month, ary[k]->bday.day, ary[k]->gender, ary[k]->address, ary[k]->number[0], ary[k]->number[1], ary[k]->number[2], ary[k]->number[3], ary[k]->number[4], ary[k]->number[5], ary[k]->number[6], ary[k]->number[7], ary[k]->number[8], ary[k]->number[9], ary[k]->number[10]);


	}

	printf("\n\n");

	return;
}


void sort_name(info *ary[], int index)	// �̸� ���� ����
{
	info *tmp;
	for (int m = 0; m < index - 1; m++)
	{
		for (int n = 0; n < index - m; n++)
		{
			if (strcmp((ary[n - 1]->name), (ary[n]->name)))
			{
				tmp = ary[n - 1];
				ary[n - 1] = ary[n];
				ary[n] = tmp;
			}
		}
	}

	return;
}

void sort_bday_higher(info *ary[], int index)	// ���� ��������
{
	info *tmp;

	for (int i = 0; i < index - 1; i++)
	{
		for (int j = i; i > 0; j--)
		{
			if (ary[i]->bday.year < ary[i]->bday.year)
			{
				tmp = ary[j - 1];
				ary[j - 1] = ary[j];
				ary[j] = tmp;
			}

			else if (ary[i]->bday.year == ary[i]->bday.year)
			{
				if (ary[i]->bday.month < ary[i]->bday.month)
				{
					tmp = ary[j - 1];
					ary[j - 1] = ary[j];
					ary[j] = tmp;
				}

				else if (ary[i]->bday.month == ary[i]->bday.month)
				{
					if (ary[i]->bday.day < ary[i]->bday.day)
					{
						tmp = ary[j - 1];
						ary[j - 1] = ary[j];
						ary[j] = tmp;
					}
				}

			}
		}
	}

	return;
}

void sort_bday_lower(info *ary[], int index)	// ���� ��������
{
	info *tmp;

	for (int i = 0; i < index - 1; i++)
	{
		for (int j = i; i > 0; j--)
		{
			if (ary[i]->bday.year > ary[i]->bday.year)
			{
				tmp = ary[j - 1];
				ary[j - 1] = ary[j];
				ary[j] = tmp;
			}

			else if (ary[i]->bday.year == ary[i]->bday.year)
			{
				if (ary[i]->bday.month > ary[i]->bday.month)
				{
					tmp = ary[j - 1];
					ary[j - 1] = ary[j];
					ary[j] = tmp;
				}

				else if (ary[i]->bday.month == ary[i]->bday.month)
				{
					if (ary[i]->bday.day > ary[i]->bday.day)
					{
						tmp = ary[j - 1];
						ary[j - 1] = ary[j];
						ary[j] = tmp;
					}
				}

			}
		}
	}


	return;
}