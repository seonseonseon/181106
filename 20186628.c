#include <stdio.h>
#include <string.h>	//strcmp 쓰기



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
		printf("최소 5명, 최대 10명의 인적 사항을 입력할 수 있습니다. 몇 명의 인적 사항을 인력하시겠습니까? (0을 입력하면 종료) :");
		scanf_s("%d", &index, 1);

		if (5 <= index && index <= 10)
		{
			for (int i = 0; i < index; i++)
			{
				printf("%d번째 입력을 시작합니다.\n", i + 1);

				printf("이름(20자 이하의 문자열):");
				scanf_s("%s", &ary[i].name, 20);
				scanf_s("%*c");

				printf("생년월일(xxxx-xx-xx의 형식):");
				scanf_s("%d-%d-%d", &ary[i].bday.year, &ary[i].bday.month, &ary[i].bday.day, 3);
				scanf_s("%*c");
				printf("%d-%02d-%02d", ary[i].bday.year, ary[i].bday.month, ary[i].bday.day);

				while (1)
				{
					printf("성별(남성은 m 또는 M, 여성은 w 또는 W):");
					scanf_s("%c", &ary[i].gender, 1);
					scanf_s("%*c");
					if (ary[i].gender != 'w' && ary[i].gender != 'W' && ary[i].gender != 'm' && ary[i].gender != 'M')
					{
						printf("잘못입력하셨습니다. 다시 입력해주세요.\n");
						continue;
					}
					else
						break;
				}


				printf("주소(30자 이하의 문자열):");
				gets(ary[i].address);

				printf("번호(구분자 없이 연속된 11자리 정수):");
				char num_tmp[11];
				gets(num_tmp);

				for (int j = 0; j < 11; j++)
				{
					ary[i].number[j] = (int)*(num_tmp + j);
				}

				printf("\n");
			}



			info *ptr = ary;

			printf("입력된 순서 그대로 출력합니다.\n");
			struct_print(ptr, index);

			sort_name(ptr, index);
			printf("이름 내림차순으로 정렬하여 출력합니다.\n");
			struct_print(ptr, index);

			sort_bday_higher(ptr, index);
			printf("생년월일 오름차순으로 정렬하여 출력합니다.\n");
			struct_print(ptr, index);



			break;
		}
		if (index == 0)
		{
			printf("0을 입력하여 종료합니다.\n");
			break;
		}
		else
		{
			printf("범위를 벗어난 수를 입력하셨습니다. 5과 10사이의 정수를 입력해주세요.\n");
			continue;
		}

	}



	return;
}

void struct_print(info *ary[], int index)
{
	printf("%-10s %-16s %-5s %-30s %-13s\n", "이름", "생년월일", "성별", "주소", "번호");



	for (int k = 0; k < index; k++)
	{
		printf("%-10s %d년 %02d월 %02d일 %-5c %-30s %d%d%d-%d%d%d%d-%d%d%d%d\n", ary[k]->name, ary[k]->bday.year, ary[k]->bday.month, ary[k]->bday.day, ary[k]->gender, ary[k]->address, ary[k]->number[0], ary[k]->number[1], ary[k]->number[2], ary[k]->number[3], ary[k]->number[4], ary[k]->number[5], ary[k]->number[6], ary[k]->number[7], ary[k]->number[8], ary[k]->number[9], ary[k]->number[10]);


	}

	printf("\n\n");

	return;
}


void sort_name(info *ary[], int index)	// 이름 순서 정렬
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

void sort_bday_higher(info *ary[], int index)	// 생일 오름차순
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

void sort_bday_lower(info *ary[], int index)	// 생일 내림차순
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