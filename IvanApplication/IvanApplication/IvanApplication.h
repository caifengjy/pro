
// IvanApplication.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CIvanApplicationApp: 
// �йش����ʵ�֣������ IvanApplication.cpp
//

class CIvanApplicationApp : public CWinApp
{
public:
	CIvanApplicationApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CIvanApplicationApp theApp;