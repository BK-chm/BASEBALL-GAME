#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void CMPSEL(int* arr); // 컴퓨터가 랜덤한 3개의 서로 다른 숫자를 배열에 저장
void USERSEL(int* arr); // 사용자가 3개의 서로 다른 숫자를 저장
int CMPRESULT(int* str1, int* str2); // 두 개의 배열에 저장된 숫자를 비교하는 함수
int POSSEL(int* arr); // 사용자가 저장한 3개의 서로 다른 숫자가 올바른지 판단
int main(void)
{
	int cmpstr[3];
	int userstr[3];
	int result;
	printf("Start Game!\n");
	CMPSEL(cmpstr);  // 컴퓨터가 3개의 서로 다른 난수 생성
	while (1)
	{
		USERSEL(userstr); // 사용자가 3개의 서로 다른 난수 생성
		result = CMPRESULT(cmpstr, userstr); // 두 개의 배열에 저장된 숫자를 비교
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
	} while (arr[0] == arr[1]); // 서로 다른 난수를 생성하기 위한 조건
	do
	{
		arr[2] = rand() % 10;
	} while (arr[2] == arr[0] || arr[2] == arr[1]); // 서로 다른 난수를 생성하기 위한 조건
}
void USERSEL(int* arr)
{
	int i;
	printf("3개의 숫자 선택: ");
	while (1)
	{
		scanf("%d %d %d", &arr[0], &arr[1], &arr[2]);
		i = POSSEL(arr); // 사용자가 서로 다른 자연수를 입력하였는지 확인하기 위한 단계 
		if (i == 1)
			break;
		else
			printf("잘못된 숫자를 입력하였습니다. 다시 입력하세요\n");
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
	int strike=0, ball=0, static count = 0; // CMPRESULT 함수가 main 함수내의 무한루프에서 계속 호출되므로 count 값을 static 처리함으로서 계속해서 증가할 수 있도록 해야한다.  
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (str1[i] == str2[j])
			{
				i == j ? strike++ : ball++;  // strike 와 ball을 판단
				break;
			}
		}
	}
	count++;
	printf("%d번째 도전 결과: %dstrike, %dball!!\n", count, strike, ball);
	if (strike == 3)
		return 1; // strike가 3일 경우 1을 반환해 main 함수의 무한 루프를 중단시킨다. 
	else
		return 0;
}
