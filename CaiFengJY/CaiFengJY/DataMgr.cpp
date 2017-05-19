#include "stdafx.h"
#include "DataMgr.h"


CDataMgr::CDataMgr()
{
}


CDataMgr::~CDataMgr()
{
}


void CDataMgr::InitList()
{
	for (int i1 = 0; i1 < 3; i1++)
		for (int i2 = 0; i2 < 3; i2++)
			for (int i3 = 0; i3 < 3; i3++)
				for (int i4 = 0; i4 < 3; i4++)
					for (int i5 = 0; i5 < 3; i5++)
						for (int i6 = 0; i6 < 3; i6++)
							for (int i7 = 0; i7 < 3; i7++)
								for (int i8 = 0; i8 < 3; i8++)
									for (int i9 = 0; i9 < 3; i9++)
										for (int i10 = 0; i10 < 3; i10++)
											for (int i11 = 0; i11 < 3; i11++)
												for (int i12 = 0; i12 < 3; i12++)
													for (int i13 = 0; i13 < 3; i13++)
														for (int i14 = 0; i14 < 3; i14++)
														{
															CString str;
															str.Format(_T("%d%d%d%d%d%d%d%d%d%d%d%d%d%d"), i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14);
															m_dataLst.push_back(str);
														}
}


CString CDataMgr::GetRandNumber()
{
	CString str;
	srand((unsigned)time(NULL));
	long nRand = 0;
	
	while (nRand < m_dataLst.size())
	{
		nRand = rand() * rand();
	}

	while (nRand > m_dataLst.size())
	{
		nRand -= m_dataLst.size();
	}

	for (std::list<CString>::iterator itor = m_dataLst.begin(); itor != m_dataLst.end(); itor++)
	{
		str = *itor;
		if (nRand-- == 0)
			break;
	}

	str.Replace('2', '3');
	return str;
}
