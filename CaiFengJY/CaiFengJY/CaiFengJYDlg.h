
// CaiFengJYDlg.h : ͷ�ļ�
//
#include "DataMgr.h"

#pragma once


// CCaiFengJYDlg �Ի���
class CCaiFengJYDlg : public CDialogEx
{
// ����
public:
	CCaiFengJYDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_CAIFENGJY_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

private:
	CDataMgr m_dataMgr;

// ʵ��
protected:
	HICON m_hIcon;
	CStringArray m_arrData;
	// ���ɵ���Ϣӳ�亯��
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
