#include "StdAfx.h"
#include "ConfigData.h"

CConfigData::CConfigData(void)
{
}

CConfigData::~CConfigData(void)
{
}

void CConfigData::ReadConfigFile(void)
{
	char buffer[128];
	memset(buffer, 0, 128);
	char buffer1[128];
	memset(buffer1, 0, 128);
	FILE *fr = fopen("config.txt","r");
	if(fr == NULL)
	{
		AfxMessageBox(_T("打开配置文件失败！"));
		return;
	}
	m_listData.clear();
	ONE_DATA data;

	while(true)
	{
		// 读取期号
		if(fgets(buffer, 128, fr) == NULL)
		{
			break;
		}
		data.issue = atoi(buffer);
		memset(buffer, 0, 128);

		// 读取中奖号码
		int winning[14];
		fgets(buffer, 128, fr);
		for(int i = 0; i < 14; i++)
		{
			winning[i] = buffer[i * 2] - 48;
		}
		memset(buffer, 0, 128);

		// 读取奖金
		fgets(buffer, 128, fr);
		data.bonus = atoi(buffer);
		memset(buffer, 0, 128);

		// 读取每场详细
		for(int i = 0; i < 14; i++)
		{
			fgets(buffer, 128, fr);
			MakeLineData(data.data[i], buffer);
			memset(buffer, 0, 128);
		}
		for(int i = 0; i < 14; i++)
		{
			data.data[i].result = winning[i];
		}
		m_listData.push_front(data);
		list<ONE_DATA>::iterator itor = m_listData.begin();
		
		for(int i = 0; i < 14; i++)
		{
			itor->pSort[i] = &itor->data[i];
		}
	}
	fclose(fr);

	this->SortData();
	this->GeneralAfterSort();
}

// 1 欧联 10-23 23:59 [03]克拉斯2:4沃尔夫[04] 析 亚 欧 2.66 3.33 2.52
void CConfigData::MakeLineData(DATA &data, char* buf)
{
	char gBuf[32];
	memset(gBuf, 0, 32);
	char *p = GetData(buf, gBuf);
	data.rank = atoi(gBuf);

	memset(gBuf, 0, 32);
	p = GetData(p, gBuf);
	memcpy(data.type, gBuf, 32);

	memset(gBuf, 0, 32);
	p = GetData(p, gBuf);
	memcpy(data.date, gBuf, 32);

	memset(gBuf, 0, 32);
	p = GetData(p, gBuf);
	memcpy(data.time, gBuf, 32);

	memset(gBuf, 0, 32);
	p = GetData(p, gBuf, "析 亚 欧 ");
	memcpy(data.vs, gBuf, 32);

	memset(gBuf, 0, 32);
	p = GetData(p, gBuf);
	data.odds[0] = atof(gBuf);
	memset(gBuf, 0, 32);
	p = GetData(p, gBuf);
	data.odds[1] = atof(gBuf);
	memset(gBuf, 0, 32);
	p = GetData(p, gBuf);
	data.odds[2] = atof(gBuf);
}

char* CConfigData::GetData(char* pBuf, char* gBuf, char *format)
{
	char *p = pBuf;
	int size = 0;
	while(strncmp (pBuf, format, strlen(format)) != 0)
	{
		pBuf++;
		size++;
	}
	memcpy(gBuf, p, size);
	size += strlen(format);
	pBuf += strlen(format);
	return pBuf;
}

void CConfigData::SortData(void)
{
	list<ONE_DATA>::iterator iter = m_listData.begin();
	while(iter != m_listData.end())
	{
		for(int i = 0; i < 14; i++)
		{
			for(int j = i + 1; j < 14; j++)
			{
				double min1 = iter->pSort[i]->odds[0];
				double max1 = iter->pSort[i]->odds[2];
				double min2 = iter->pSort[j]->odds[0];
				double max2 = iter->pSort[j]->odds[2];
				iter->pSort[i]->oddsresult = 3;
				iter->pSort[j]->oddsresult = 3;
				double temp = 0;
				if(min1 > max1)
				{
					iter->pSort[i]->oddsresult = 0;
					temp = min1;
					min1 = max1;
					max1 = temp;
				}
				if(min2 > max2)
				{
					iter->pSort[j]->oddsresult = 0;
					temp = min2;
					min2 = max2;
					max2 = temp;
				}

				double v1 = min1 / max1;
				double v2 = min2 / max2;

				if((min1 > min2) || (min1 == min2 && v1 > v2))
				{
					DATA *p = iter->pSort[i];
					iter->pSort[i] = iter->pSort[j];
					iter->pSort[j] = p;
				}
			}
		}
		iter++;
	}
}

void CConfigData::GeneralAfterSort(void)
{
	list<ONE_DATA>::iterator iter = m_listData.begin();
	while(iter != m_listData.end())
	{
		memset(iter->afterSortSum, 0, 14 * sizeof(int));
		for(int i = 0; i < 14; i++)
		{
			if(iter->pSort[i]->result == 1)
			{
				iter->afterSortSum[i] = 1;
			}
			else if(iter->pSort[i]->oddsresult != iter->pSort[i]->result)
			{
				iter->afterSortSum[i] = 2;
			}
		}
		iter++;
	}
}
