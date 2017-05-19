#pragma once
#include <list>
#include <string>

using namespace std;

// CSettingData ÃüÁîÄ¿±ê

class CSettingData : public CObject
{
public:
	CSettingData();
	virtual ~CSettingData();


	// data
	list<string> m_list;
};


