
// IvanApplicationDlg.h : ͷ�ļ�
//

#pragma once

#include "Number.h"
#include "afxwin.h"
#include "afxcmn.h"

// CIvanApplicationDlg �Ի���
class CIvanApplicationDlg : public CDialogEx
{
// ����
public:
	CIvanApplicationDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_IVANAPPLICATION_DIALOG };
#endif

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
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton1();

private:
	//CString m_wantValue;
	//CEdit m_showEdit;
	CEdit m_wantEdit;	// �н�����
	CEdit m_editTotal;	// �н�����
	CEdit m_editAll;	// ȫ�� edit ����
	CEdit m_editMiss1;	// ��1 edit ����
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
