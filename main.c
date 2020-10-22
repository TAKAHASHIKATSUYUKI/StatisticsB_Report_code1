#include <stdio.h>
#include <math.h>

#define SIZE 24

// プロトタイプ宣言
int getsum(int[]);
double getave(int);
double getdist1(int[], double);
double getdist2(int[], double);

// グローバル変数で配列を定義
data[] = {
	6, 9, 10, 11, 14, 15, 16, 18,
	20, 20, 22, 23, 24, 29, 31, 32,
	39, 42, 43, 45, 47, 49, 50, 50};

int main(void)
{

	int sum;
	double ave, dist1, dist2;
	double standard_deviation1, standard_deviation2;

	sum = getsum(data);				   // 合計値
	ave = getave(sum);				   // 平均値
	dist1 = getdist1(data, ave);	   // 分散1
	standard_deviation1 = sqrt(dist1); // 標準偏差1
	dist2 = getdist2(data, ave);	   // 分散2
	standard_deviation2 = sqrt(dist2); // 標準偏差2

	printf("合計値   : %d\n", sum);
	printf("平均値   : %2f\n", ave);
	printf("分散1    : %2f\n", dist1);
	printf("標準偏差1: %2f\n", standard_deviation1);
	printf("分散2    : %2f\n", dist2);
	printf("標準偏差2: %2f\n", standard_deviation2);

	return 0;
}

int getsum(int data[])
{
	int sum = 0;

	for (int i = 0; i < SIZE; i++)
		sum += data[i];

	return sum;
}

double getave(int sum)
{
	// 精度を保つためにdouble型でキャスト
	return sum / (double)SIZE;
}

double getdist1(int data[], double ave)
{
	int sum = 0;
	double result = 0;

	for (int i = 0; i < SIZE; i++)
	{
		sum += (data[i] - ave) * (data[i] - ave);
	}
	// 精度を保つためにdouble型でキャスト
	result = sum / (double)SIZE;

	return result;
}

double getdist2(int data[], double ave)
{
	int sum = 0;
	double result = 0;

	for (int i = 0; i < SIZE; i++)
	{
		sum += data[i] * data[i];
	}
	// 精度を保つためにdouble型でキャスト
	result = sum / (double)SIZE - ave * ave;

	return result;
}