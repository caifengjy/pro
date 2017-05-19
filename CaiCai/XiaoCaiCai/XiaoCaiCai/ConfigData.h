#pragma once
#include <list>

using namespace std;

typedef struct _DATA
{
	int result; // ِ��
	int oddsresult; // ���r�ʵ�ِ��
	int rank; // ���
	char type[32]; // ��������
	char date[32]; // ��������
	char time[32]; // ����ʱ��
	char vs[32]; // ��������
	double odds[3]; // ��������
}DATA;

typedef struct _ONE_DATA
{
	int issue;		// �ں�
	int bonus;		// ����
	int afterSortSum[14]; // ���r��������ِ����
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
