#pragma once
#include "DialogData.h"

// CSettingDlg �Ի���

class CSettingDlg : public CDialog
{
	DECLARE_DYNAMIC(CSettingDlg)

public:
	CSettingDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSettingDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_SETTING };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CDialogData *m_pDlgData;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();
};
