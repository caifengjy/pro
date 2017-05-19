
// MFCApplication3Dlg.h : ヘッダー ファイル
//

#pragma once

typedef struct _STRING_DATA
{
	CString lString;
	CString rString;
	int nTimes;
	BOOL bAdded;
}STRING_DATA;

// CMFCApplication3Dlg ダイアログ
class CMFCApplication3Dlg : public CDialogEx
{
private:

	STRING_DATA m_data;
	int m_cx;
	int m_cy;

	BOOL m_bShowWord;
// コンストラクション
public:
	CMFCApplication3Dlg(CWnd* pParent = NULL);	// 標準コンストラクター

// ダイアログ データ
	enum { IDD = IDD_MFCAPPLICATION3_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV サポート


	CArray<STRING_DATA, STRING_DATA> m_arr;
	CArray<STRING_DATA, STRING_DATA> m_arr1;
//	CStringArray m_arr;

	CArray<STRING_DATA, STRING_DATA>  m_arrDelete;
//	CStringArray m_arr1;


	CArray<STRING_DATA, STRING_DATA>  m_arr1_c;
	BOOL m_lock;
	CFont font;
	CBrush *pBrush;
// 実装
protected:
	HICON m_hIcon;

	// 生成された、メッセージ割り当て関数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTvnSelchangedTree1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButton1();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
