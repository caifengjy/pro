
// CaiFengJY.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CCaiFengJYApp: 
// �йش����ʵ�֣������ CaiFengJY.cpp
//

class CCaiFengJYApp : public CWinApp
{
public:
	CCaiFengJYApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CCaiFengJYApp theApp;