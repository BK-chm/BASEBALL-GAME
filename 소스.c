#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void CMPSEL(int* arr); // ��ǻ�Ͱ� ������ 3���� ���� �ٸ� ���ڸ� �迭�� ����
void USERSEL(int* arr); // ����ڰ� 3���� ���� �ٸ� ���ڸ� ����
int CMPRESULT(int* str1, int* str2); // �� ���� �迭�� ����� ���ڸ� ���ϴ� �Լ�
int POSSEL(int* arr); // ����ڰ� ������ 3���� ���� �ٸ� ���ڰ� �ùٸ��� �Ǵ�
int main(void)
{
	int cmpstr[3];
	int userstr[3];
	int result;
	printf("Start Game!\n");
	CMPSEL(cmpstr);  // ��ǻ�Ͱ� 3���� ���� �ٸ� ���� ����
	while (1)
	{
		USERSEL(userstr); // ����ڰ� 3���� ���� �ٸ� ���� ����
		result = CMPRESULT(cmpstr, userstr); // �� ���� �迭�� ����� ���ڸ� ��
		if (result == 1)
			break;
		printf("\n");
	}
	printf("Game Over!\n");
	return 0;
}
void CMPSEL(int* arr)
{
	arr[0] = rand() % 10;
	do
	{
		arr[1] = rand() % 10;
	} while (arr[0] == arr[1]); // ���� �ٸ� ������ �����ϱ� ���� ����
	do
	{
		arr[2] = rand() % 10;
	} while (arr[2] == arr[0] || arr[2] == arr[1]); // ���� �ٸ� ������ �����ϱ� ���� ����
}
void USERSEL(int* arr)
{
	int i;
	printf("3���� ���� ����: ");
	while (1)
	{
		scanf("%d %d %d", &arr[0], &arr[1], &arr[2]);
		i = POSSEL(arr); // ����ڰ� ���� �ٸ� �ڿ����� �Է��Ͽ����� Ȯ���ϱ� ���� �ܰ� 
		if (i == 1)
			break;
		else
			printf("�߸��� ���ڸ� �Է��Ͽ����ϴ�. �ٽ� �Է��ϼ���\n");
	}
	return 0;
}
int POSSEL(int* arr)
{
	int i;
	if (arr[0] == arr[1] || arr[0] == arr[2] || arr[1] == arr[2])
		return 0;
	else
		return 1;
}
int CMPRESULT(int* str1, int* str2)
{
	int i, j;
	int strike=0, ball=0, count = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (str1[i] == str2[j])
			{
				i == j ? strike++ : ball++;  // strike �� ball�� �Ǵ�
				break;
			}
		}
	}
	count++;
	printf("%d��° ���� ���: %dstrike, %dball!!\n", count, strike, ball);
	if (strike == 3)
		return 1; // strike�� 3�� ��� 1�� ��ȯ�� main �Լ��� ���� ������ �ߴܽ�Ų��. 
	else
		return 0;
}