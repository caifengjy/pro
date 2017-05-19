#pragma once

#include "Number.h"

#define FILE_NAME_GO			"./go.txt"
#define FILE_NAME_SEL			"./sel.txt"
#define FILE_NAME_ALL			"./all.txt"

#define PATHNAME_INI			_T("./DataManager.ini")
#define SECTION_NAME_RATIO		_T("SECTION_RATIO")
#define NODE_NAME_RATIO			_T("node_ratio")

#define SECTION_NAME_THRESHOLD					_T("SECTION_THRESHOLD")
#define NODE_NAME_THRESHOLD_VALUE_MIN		_T("node_threshold_value_min")
#define NODE_NAME_THRESHOLD_VALUE_MAX		_T("node_threshold_value_max")

#define SECTION_NAME_MY_SELECT		_T("SECTION_MY_SELECT")
#define NODE_NAME_MY_SELECT1			_T("node_my_select1")
#define NODE_NAME_THRESHOLD_VALUE1			_T("node_threshold_value1")
#define NODE_NAME_MY_SELECT2			_T("node_my_select2")
#define NODE_NAME_THRESHOLD_VALUE2			_T("node_threshold_value2")
#define NODE_NAME_MY_SELECT3			_T("node_my_select3")
#define NODE_NAME_THRESHOLD_VALUE3			_T("node_threshold_value3")

class CSingelDataManager
{
private:
	CSingelDataManager();

public:
	~CSingelDataManager();

public:
	CNumber m_ratio;
	int m_printCount;
	int m_thresholdValueMax;
	int m_thresholdValueMin;
	vector<vector<int>> m_vecSelNum1;
	vector<vector<int>> m_vecSelNum2;
	vector<vector<int>> m_vecSelNum3;
	int m_thresholdValue1;
	int m_thresholdValue2;
	int m_thresholdValue3;
	
public:
	static CSingelDataManager *GetInstance();
	void ReadINI();
	void Reload();
	vector<vector<int>> ReadToVector(LPCWSTR section, LPCWSTR node);
	CNumber ReadToNumber(LPCWSTR section, LPCWSTR node);
};

