#pragma once
#include <list>

using namespace std;

typedef struct _DATA
{
	int result; // 賽果
	int oddsresult; // 按賠率的賽果
	int rank; // 序号
	char type[32]; // 比赛类型
	char date[32]; // 比赛日期
	char time[32]; // 比赛时间
	char vs[32]; // 比赛对阵
	double odds[3]; // 两队赔率
}DATA;

typedef struct _ONE_DATA
{
	int issue;		// 期号
	int bonus;		// 奖金
	int afterSortSum[14]; // 按賠率排序后的賽果差
	DATA data[14];
	DATA *pSort[14];
}ONE_DATA;

class CConfigData
{
public:
	CConfigData(void);
	~CConfigData(void);

	list<ONE_DATA> m_listData;
	void ReadConfigFile(void);
	void MakeLineData(DATA &data, char* buf);
	char* GetData(char* pBuf, char* gBuf, char* format = " ");
	void SortData(void);
	void GeneralAfterSort(void);
};
