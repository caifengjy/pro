// XiaoCaiCaiDlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"
#include "SettingDlg.h"
#include "ShowResultDlg.h"
#include "DialogData.h"

// CXiaoCaiCaiDlg �Ի���
class CXiaoCaiCaiDlg : public CDialog
{
// ����
public:
	CXiaoCaiCaiDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_XIAOCAICAI_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
