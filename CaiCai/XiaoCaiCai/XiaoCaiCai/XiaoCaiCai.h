// XiaoCaiCai.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CXiaoCaiCaiApp:
// �йش����ʵ�֣������ XiaoCaiCai.cpp
//

class CXiaoCaiCaiApp : public CWinApp
{
public:
	CXiaoCaiCaiApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CXiaoCaiCaiApp theApp;