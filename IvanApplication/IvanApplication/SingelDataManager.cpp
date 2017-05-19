#include "stdafx.h"
#include "SingelDataManager.h"

static CSingelDataManager* m_pInstance = NULL;

CSingelDataManager::CSingelDataManager()
{

}


CSingelDataManager::~CSingelDataManager()
{

}

CSingelDataManager *CSingelDataManager::GetInstance()
{
	if (m_pInstance == NULL)
	{
		m_pInstance = new CSingelDataManager();
		m_pInstance->ReadINI();
	}
	return m_pInstance;
}


void CSingelDataManager::Reload()
{
	m_pInstance->m_vecSelNum1.clear();
	m_pInstance->m_vecSelNum2.clear();
	m_pInstance->m_vecSelNum3.clear();
	m_pInstance->ReadINI();
}

vector<vector<int>> CSingelDataManager::ReadToVector(LPCWSTR section, LPCWSTR node)
{
	vector<vector<int>> result;
	TCHAR strBuff[256];
	CString output, str;
	GetPrivateProfileString(section, node, NULL, strBuff, 80, PATHNAME_INI);
	str = strBuff;
	for (int i = 0; i < MATCH_COUNT; i++)
	{
		AfxExtractSubString(output, str, i, ',');

		vector<int> num;
		for (size_t j = 0; j < output.GetLength(); j++)
		{
			if (output.GetAt(j) != '3' && output.GetAt(j) != '1' && output.GetAt(j) != '0')
			{
				continue;
			}
			num.push_back(output.GetAt(j) - '0');
		}
		result.push_back(num);
	}

	return result;
}

CNumber CSingelDataManager::ReadToNumber(LPCWSTR section, LPCWSTR node)
{
	TCHAR strBuff[256];
	CString output, str;
	CNumber result;

	GetPrivateProfileString(SECTION_NAME_RATIO, NODE_NAME_RATIO, NULL, strBuff, 80, PATHNAME_INI);
	str = strBuff;
	for (int i = 0; i < MATCH_COUNT; i++)
	{
		AfxExtractSubString(output, str, i, ',');
		result.m_number[i] = _wtoi(output);
	}

	return result;
}

void CSingelDataManager::ReadINI()
{
	m_ratio = ReadToNumber(SECTION_NAME_RATIO, NODE_NAME_RATIO);
	m_vecSelNum1 = ReadToVector(SECTION_NAME_MY_SELECT, NODE_NAME_MY_SELECT1);
	m_vecSelNum2 = ReadToVector(SECTION_NAME_MY_SELECT, NODE_NAME_MY_SELECT2);
	m_vecSelNum3 = ReadToVector(SECTION_NAME_MY_SELECT, NODE_NAME_MY_SELECT3);
	m_thresholdValue1 = GetPrivateProfileInt(SECTION_NAME_MY_SELECT, NODE_NAME_THRESHOLD_VALUE1, -1, PATHNAME_INI);
	m_thresholdValue2 = GetPrivateProfileInt(SECTION_NAME_MY_SELECT, NODE_NAME_THRESHOLD_VALUE2, -1, PATHNAME_INI);
	m_thresholdValue3 = GetPrivateProfileInt(SECTION_NAME_MY_SELECT, NODE_NAME_THRESHOLD_VALUE3, -1, PATHNAME_INI);

	m_thresholdValueMin = GetPrivateProfileInt(SECTION_NAME_THRESHOLD, NODE_NAME_THRESHOLD_VALUE_MIN, -1, PATHNAME_INI);
	m_thresholdValueMax = GetPrivateProfileInt(SECTION_NAME_THRESHOLD, NODE_NAME_THRESHOLD_VALUE_MAX, -1, PATHNAME_INI);
}

