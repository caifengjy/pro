#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "ConfigData.h"

// CShowResultDlg 对话框

class CShowResultDlg : public CDialog
{
	DECLARE_DYNAMIC(CShowResultDlg)

public:
	CShowResultDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CShowResultDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG_SHOW_RESULT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CListCtrl m_listCtrl;
//	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton1();
	CConfigData m_config;
	int m_count;
	afx_msg void OnBnClickedButton2();
	void ShowList(list<ONE_DATA> &list);
	afx_msg void OnBnClickedButton3();
	CString m_give;
	afx_msg void OnBnClickedButton4();
	int m_giveNum;
	int DeleteReuse(list<ONE_DATA> &listRef);
	int m_cmpNum;
};
