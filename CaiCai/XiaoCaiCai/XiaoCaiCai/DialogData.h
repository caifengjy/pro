#pragma once
#include <list>
#include <string>
// CDialogData ÃüÁîÄ¿±ê
using namespace std;

class CDialogData : public CObject
{
public:
	CDialogData();
	virtual ~CDialogData();
	// dialog data
	BOOL m_select[14][3];
	list<string> m_listAllData;
	list<string> m_listFillterData;
};


