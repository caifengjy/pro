#include "stdafx.h"
#include "Number.h"


CNumber::CNumber()
{
}

CNumber::CNumber(size_t a0, size_t a1, size_t a2, size_t a3, size_t a4, size_t a5, size_t a6, size_t a7, size_t a8, size_t a9, size_t a10, size_t a11, size_t a12, size_t a13)
{
	m_number[0] = a0 == 2 ? 3 : a0;
	m_number[1] = a1 == 2 ? 3 : a1;
	m_number[2] = a2 == 2 ? 3 : a2;
	m_number[3] = a3 == 2 ? 3 : a3;
	m_number[4] = a4 == 2 ? 3 : a4;
	m_number[5] = a5 == 2 ? 3 : a5;
	m_number[6] = a6 == 2 ? 3 : a6;
	m_number[7] = a7 == 2 ? 3 : a7;
	m_number[8] = a8 == 2 ? 3 : a8;
	m_number[9] = a9 == 2 ? 3 : a9;
	m_number[10] = a10 == 2 ? 3 : a10;
	m_number[11] = a11 == 2 ? 3 : a11;
	m_number[12] = a12 == 2 ? 3 : a12;
	m_number[13] = a13 == 2 ? 3 : a13;
}

CNumber::~CNumber()
{
}

string CNumber::getString()
{
	string str;
	for (size_t i = 0; i < MATCH_COUNT; i++)
	{
		char tmp[2];
		
		_itoa_s((int)m_number[i], tmp, 10);
		str.append(tmp);
		
	}
	return str;
}

CString CNumber::getCString()
{
	CString str;
	for (size_t i = 0; i < MATCH_COUNT; i++)
	{
		char tmp[2];

		_itoa_s((int)m_number[i], tmp, 10);
		str += tmp;

	}
	return str;
}

bool CNumber::CompareRatio(CNumber ratio)
{
	int difference = 0;
	int difference_0 = 0;
	int difference_1 = 0;
	for (size_t i = 0; i < MATCH_COUNT; i++){
		if (m_number[i] != ratio.m_number[i]){
			if (m_number[i] == 1) {
				difference_1++; // 平局增加
			}
			else {
				difference_0++; // 负局增加
			}
		}
	}

	difference = difference_0 + difference_1; // 总异常值

	// 总异常值在阈值之间
	if (difference > CSingelDataManager::GetInstance()->m_thresholdValueMax || 
		difference < CSingelDataManager::GetInstance()->m_thresholdValueMin){
		return false;
	}

	int tepDiff0 = difference / 2/* - 1*/; // 负值的数量在总异常值的一半-1
	tepDiff0 = tepDiff0 < 3 ? 3 : tepDiff0; // 保证负值的最小值为3
	if (difference_0 > tepDiff0) {
		return false;
	}
	return true;
}

int CNumber::Compare(CNumber ratio)
{
	int difference = 0;
	for (size_t i = 0; i < MATCH_COUNT; i++) {
		if (m_number[i] != ratio.m_number[i]) {
			difference++;
		}
	}
	return difference;
}

int CNumber::CompareVector(vector<vector<int>> &vecSelNum)
{
	int difference = 14;
	for (size_t i = 0; i < MATCH_COUNT; i++) {
		BOOL bHave = FALSE;
		for each (int var in vecSelNum[i])
		{
			if (var == m_number[i])
			{
				bHave = TRUE;
				break;
			}
		}
		if (bHave) {
			difference--;
		}
	}
	return difference;
}
