
// CaiFengJYDlg.h : 头文件
//
#include "DataMgr.h"

#pragma once


// CCaiFengJYDlg 对话框
class CCaiFengJYDlg : public CDialogEx
{
// 构造
public:
	CCaiFengJYDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_CAIFENGJY_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

private:
	CDataMgr m_dataMgr;

// 实现
protected:
	HICON m_hIcon;
	CStringArray m_arrData;
	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	CString m_randNum;
	CString m_value[14];
	afx_msg void OnBnClickedButton3();
};
