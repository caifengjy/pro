
// IvanApplicationDlg.h : 头文件
//

#pragma once

#include "Number.h"
#include "afxwin.h"
#include "afxcmn.h"

// CIvanApplicationDlg 对话框
class CIvanApplicationDlg : public CDialogEx
{
// 构造
public:
	CIvanApplicationDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_IVANAPPLICATION_DIALOG };
#endif

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
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton1();

private:
	//CString m_wantValue;
	//CEdit m_showEdit;
	CEdit m_wantEdit;	// 中奖号码
	CEdit m_editTotal;	// 中奖个数
	CEdit m_editAll;	// 全中 edit 个数
	CEdit m_editMiss1;	// 错1 edit 个数
	CListCtrl m_list;	// list control

	vector<CNumber> m_vecList;
	vector<CNumber> m_selList;
public:
	void WriteToFile(char *fileName, vector<CNumber> &list, size_t printCount);
	void Build(vector<CNumber> &list, CNumber ratio);
	void Initial();
	void ReadFile(LPCWSTR fileName, vector<CNumber> &list);
	void ReadEvery(vector<CNumber> &list);
	void SetListControl(vector<CNumber> list);
	int m_selFileName;
	afx_msg void OnBnClickedButton2();
};
