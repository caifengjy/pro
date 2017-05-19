#pragma once
#include <list>

class CDataMgr
{
public:
	CDataMgr();
	~CDataMgr();

private:

	std::list<CString> m_dataLst;
public:
	void InitList();
	CString GetRandNumber();
};

