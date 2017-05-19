//#define BASE {3,3,0,0,3,3,3,3,3,3,0,0,3,3}		// 按赔率得出的结果
#define BASE {3,3,3,3,3,3,3,3,3,3,3,3,3,3}
//#define SORT {0,1,1,2,2,2,3,3,3,4,5,5,6,6}
#define SORT {0,0,0,0,0,0,0,1,1,1,1,1,1,1}		// 异常结果个数
//#define RATE {0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1.0,1.1,1.2,1.3,1.4} // 赔率
#define RATE {1.4,1.3,1.2,1.1,1.0,0.9,0.8,0.7,0.6,0.5,0.4,0.3,0.2,0.1} // 赔率

#define ADJUST 0
#define SELECT_NUM 10			// 随即选取出的个数
#define NEED_PRINT_NUMBER 0

#include "stdio.h"
#include "stdlib.h"
#include <string.h>

#define ONE_MAX 14
#define NUM_MAX 4782969
//#define SEL_MAX 10

typedef struct _ONE{
	unsigned char n[ONE_MAX];
}ONE;

//int comp[14];
//int comp1[14];

typedef struct _RATE{
	float rate;
	int index;
}SRATE;

SRATE g_rate[ONE_MAX]; // 排序后的索引

// 初始化排序模块
void initRateSort()
{
	float comp[ONE_MAX] = RATE;
	int i = 0;
	int j = 0;
	
	for(i = 0; i < 14; i++)
	{
		g_rate[i].rate = comp[i];
		g_rate[i].index = i;
	}
	
	for(i = 0; i < 14; i++)
	{
		for(j = i + 1; j < 14; j++)
		{
			if(g_rate[i].rate > g_rate[j].rate)
			{
				SRATE temp;
				temp = g_rate[i];
				g_rate[i] = g_rate[j];
				g_rate[j] = temp;
			}
		}
	}
}

// 创建所有结果
void generateData(ONE * data)
{
	int n[ONE_MAX];
	int i = 0;
	int j = 0;
	for (n[0] = 0; n[0] < 3; n[0]++)
		for (n[1] = 0; n[1] < 3; n[1]++)
			for (n[2] = 0; n[2] < 3; n[2]++)
				for (n[3] = 0; n[3] < 3; n[3]++)
					for (n[4] = 0; n[4] < 3; n[4]++)
						for (n[5] = 0; n[5] < 3; n[5]++)
							for (n[6] = 0; n[6] < 3; n[6]++)
								for (n[7] = 0; n[7] < 3; n[7]++)
									for (n[8] = 0; n[8] < 3; n[8]++)
										for (n[9] = 0; n[9] < 3; n[9]++)
											for (n[10] = 0; n[10] < 3; n[10]++)
												for (n[11] = 0; n[11] < 3; n[11]++)
													for (n[12] = 0; n[12] < 3; n[12]++)
														for (n[13] = 0; n[13] < 3; n[13]++)
														{
		for (j = 0; j < ONE_MAX; j++)
		{
			data[i].n[j] = n[j];
			if (data[i].n[j] == 2)
				data[i].n[j] = 3;
		}
		i++;
														}
}

// 除去不合法的结果
int compare(int *co, int *co1, ONE *data)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < NUM_MAX; i++)
	{
		int result = 0;
		for (j = 0; j < ONE_MAX; j++)
		{
			if (data[i].n[j] != co[j])
			{
				result++;
			}
			if (result >(co1[j] + ADJUST))
			{
				data[i].n[0] = 2;
				break;
			}
		}
	}
}

// 对合法的结果，恢复正常顺序
void restore(ONE *data)
{
	int i = 0;
	int j = 0;
	ONE temp;
	for (i = 0; i < NUM_MAX; i++)
	{
		if(data[i].n[0] == 2)
			continue;
		
		temp = data[i];
		
		
		for (j = 0; j < ONE_MAX; j++)
		{
			data[i].n[g_rate[j].index] = temp.n[j];
		}
	}
}

// 选取号码
int select_num(ONE* data)
{
	srand48((int)time(0));
	srand48(lrand48());

	int sel = SELECT_NUM;
	int j = 0;
	int print = 1;

	printf("begin to select >>>>>>>>>>\n");
	while (sel > 0)
	{
		long lIndex = lrand48() % NUM_MAX;
		if (lIndex < 0 || lIndex >= NUM_MAX)
		{
			printf("error index: %ld\r\n", lIndex);
			continue;
		}
		if (data[lIndex].n[0] != 2)
		{
			for (j = 0; j < ONE_MAX; j++)
			{
				printf("%d\r\n", data[lIndex].n[j]);
			}

			printf("\r\n-----------\r\n");
			if (NEED_PRINT_NUMBER == 1)
				printf("\t-%ld\t-%d-\r\n", lIndex + 1, print++);
			else
				printf("\r\n");
			data[lIndex].n[0] = 2;
			sel--;
			if(sel <= 0)
				break;
		}
	}
}

int print_all(ONE* data)
{
	int print = 1;
	int i = 0;
	int j = 0;

	for (i = 0; i < NUM_MAX; i++)
	{
		if (data[i].n[0] != 2)
		{
			for (j = 0; j < ONE_MAX; j++)
			{
				printf("%d", data[i].n[j]);
			}
			if (NEED_PRINT_NUMBER == 1)
				printf("\t-%d\t-%d-\r\n", i + 1, print++);
			else
				printf("\r\n");
		}
	}
}

int main()
{
	int comp[ONE_MAX] = BASE;
	int comp1[ONE_MAX] = SORT;

	int i = 0;
	int j = 0;
	ONE *alldata = NULL;

	alldata = (ONE *)malloc(sizeof(ONE) * NUM_MAX);
	initRateSort();
	generateData(alldata);
	compare(comp, comp1, alldata);
	restore(alldata);
	print_all(alldata);
	select_num(alldata);

	free(alldata);
}



