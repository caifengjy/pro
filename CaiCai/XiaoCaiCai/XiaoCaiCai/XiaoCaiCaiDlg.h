// XiaoCaiCaiDlg.h : 头文件
//

#pragma once
#include "afxcmn.h"
#include "SettingDlg.h"
#include "ShowResultDlg.h"
#include "DialogData.h"

// CXiaoCaiCaiDlg 对话框
class CXiaoCaiCaiDlg : public CDialog
{
// 构造
public:
	CXiaoCaiCaiDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_XIAOCAICAI_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl m_tab;
	CSettingDlg m_settingDlg;
	CShowResultDlg m_resultDlg;
	afx_msg void OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedOk();

public:
	CDialogData m_dlgData;
	void GeneralData();
	int ChangedData(int data);
};
