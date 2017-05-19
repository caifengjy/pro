
// MFCApplication3Dlg.cpp : À‘•ƒtƒ@ƒCƒ‹
//

#include "stdafx.h"
#include "MFCApplication3.h"
#include "MFCApplication3Dlg.h"
#include "afxdialogex.h"

#define HOME

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#ifdef HOME
#define RECITAL_TIME 17
#define FONT_SIZE 24
#define X_POSITION 150
#define Y_POSITION 200
#else
#define RECITAL_TIME 17
#define FONT_SIZE 18
#define X_POSITION 700
#define Y_POSITION 800
#endif

#define Write_File _T("Write_File.dat")
#define Write_File_bk _T("Write_File_bk.dat")
#define Write_File_Re _T("Write_File_Re.txt")
#define Write_File_To_Word_Book _T("Write_File_To_Word_Book.txt")

// ƒAƒvƒŠƒP[ƒVƒ‡ƒ“‚Ìƒo[ƒWƒ‡ƒ“î•ñ‚Ég‚í‚ê‚é CAboutDlg ƒ_ƒCƒAƒƒO

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ƒ_ƒCƒAƒƒO ƒf[ƒ^
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ƒTƒ|[ƒg

// À‘•
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCApplication3Dlg ƒ_ƒCƒAƒƒO



CMFCApplication3Dlg::CMFCApplication3Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCApplication3Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_bShowWord = TRUE;
}

void CMFCApplication3Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCApplication3Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREE1, &CMFCApplication3Dlg::OnTvnSelchangedTree1)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication3Dlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CMFCApplication3Dlg ƒƒbƒZ[ƒW ƒnƒ“ƒhƒ‰[

BOOL CMFCApplication3Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// "ƒo[ƒWƒ‡ƒ“î•ñ..." ƒƒjƒ…[‚ğƒVƒXƒeƒ€ ƒƒjƒ…[‚É’Ç‰Á‚µ‚Ü‚·B

	// IDM_ABOUTBOX ‚ÍAƒVƒXƒeƒ€ ƒRƒ}ƒ“ƒh‚Ì”ÍˆÍ“à‚É‚È‚¯‚ê‚Î‚È‚è‚Ü‚¹‚ñB
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ‚±‚Ìƒ_ƒCƒAƒƒO‚ÌƒAƒCƒRƒ“‚ğİ’è‚µ‚Ü‚·BƒAƒvƒŠƒP[ƒVƒ‡ƒ“‚ÌƒƒCƒ“ ƒEƒBƒ“ƒhƒE‚ªƒ_ƒCƒAƒƒO‚Å‚È‚¢ê‡A
	//  Framework ‚ÍA‚±‚Ìİ’è‚ğ©“®“I‚És‚¢‚Ü‚·B
	SetIcon(m_hIcon, TRUE);			// ‘å‚«‚¢ƒAƒCƒRƒ“‚Ìİ’è
	SetIcon(m_hIcon, FALSE);		// ¬‚³‚¢ƒAƒCƒRƒ“‚Ìİ’è

	// TODO: ‰Šú‰»‚ğ‚±‚±‚É’Ç‰Á‚µ‚Ü‚·B
	m_cx = GetSystemMetrics(SM_CXFULLSCREEN);
	m_cy = GetSystemMetrics(SM_CYFULLSCREEN);
	CRect rc;
	GetWindowRect(rc);
	MoveWindow(m_cx - rc.Width(), m_cy, rc.Width(), rc.Height());

	DeleteFile(Write_File_Re);
	DeleteFile(Write_File_To_Word_Book);
	CopyFile(Write_File, Write_File_bk, FALSE);
	CFile cfile;
	if (!cfile.Open(Write_File, CFile::modeReadWrite))
	{
		exit(0);
		return TRUE;
	}

	ULONGLONG filelen = cfile.GetLength();
	char *pbufWrite = new char[filelen + 1];
	memset(pbufWrite, 0, sizeof(filelen + 1));
	cfile.Read(pbufWrite, filelen);
	cfile.Close();
	


	TCHAR *pwText;
	DWORD dwUnicodeLen; 
	dwUnicodeLen = MultiByteToWideChar(CP_UTF8, 0, pbufWrite, -1, NULL, 0);
	pwText = new   WCHAR[dwUnicodeLen + 1];
	memset(pwText, 0, dwUnicodeLen + 1);
	MultiByteToWideChar(CP_UTF8, 0, pbufWrite, -1, pwText, dwUnicodeLen);
	CString m_str = pwText;
	delete[] pwText;

	while (m_str.GetLength() > 0)
	{
		CString str;
		STRING_DATA data;

		int nFind = m_str.Find(_T("\r\n"));
		if (nFind == -1)
			break;

		nFind += 2;
		str = m_str.Left(nFind - 2);
		m_str = m_str.Right(m_str.GetLength() - nFind);

		CString str1 = str;
		nFind = str1.Find(_T("\t"));
		if (nFind == -1)
			continue;

		nFind += 1;
		data.lString = str1.Left(nFind);

		str1 = str1.Right(str1.GetLength() - nFind);
		int nFind1 = str1.Find(_T("\t"));
		if (nFind1 == -1)
		{
			data.nTimes = RECITAL_TIME;
			data.rString = (str1 + _T("\t"));
		}
		else
		{
			nFind1 += 1;
			data.rString = str1.Left(nFind1);
			CString sNum = str1.Right(str1.GetLength() - nFind1);
			data.nTimes = _ttoi(sNum);
		}
		data.bAdded = FALSE;
		m_arr.Add(data);
	}
	m_lock = TRUE;
	srand((unsigned)time(NULL));
	pBrush = CBrush::FromHandle((HBRUSH)GetStockObject(BLACK_BRUSH));
	VERIFY(font.CreateFont(
		FONT_SIZE,                        // nHeight
		0,                         // nWidth
		0,                         // nEscapement
		0,                         // nOrientation
		FW_NORMAL,                 // nWeight
		FALSE,                     // bItalic
		FALSE,                     // bUnderline
		0,                         // cStrikeOut
		ANSI_CHARSET,              // nCharSet
		OUT_DEFAULT_PRECIS,        // nOutPrecision
		CLIP_DEFAULT_PRECIS,       // nClipPrecision
		DEFAULT_QUALITY,           // nQuality
		DEFAULT_PITCH | FF_SWISS,  // nPitchAndFamily
		_T("Î¢ÈíÑÅºÚ")));                 // lpszFacename
	return TRUE;  // ƒtƒH[ƒJƒX‚ğƒRƒ“ƒgƒ[ƒ‹‚Éİ’è‚µ‚½ê‡‚ğœ‚«ATRUE ‚ğ•Ô‚µ‚Ü‚·B
}

void CMFCApplication3Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// ƒ_ƒCƒAƒƒO‚ÉÅ¬‰»ƒ{ƒ^ƒ“‚ğ’Ç‰Á‚·‚éê‡AƒAƒCƒRƒ“‚ğ•`‰æ‚·‚é‚½‚ß‚Ì
//  ‰º‚ÌƒR[ƒh‚ª•K—v‚Å‚·BƒhƒLƒ…ƒƒ“ƒg/ƒrƒ…[ ƒ‚ƒfƒ‹‚ğg‚¤ MFC ƒAƒvƒŠƒP[ƒVƒ‡ƒ“‚Ìê‡A
//  ‚±‚ê‚ÍAFramework ‚É‚æ‚Á‚Ä©“®“I‚Éİ’è‚³‚ê‚Ü‚·B

void CMFCApplication3Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // •`‰æ‚ÌƒfƒoƒCƒX ƒRƒ“ƒeƒLƒXƒg

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ƒNƒ‰ƒCƒAƒ“ƒg‚ÌlŠpŒ`—Ìˆæ“à‚Ì’†‰›
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ƒAƒCƒRƒ“‚Ì•`‰æ
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ƒ†[ƒU[‚ªÅ¬‰»‚µ‚½ƒEƒBƒ“ƒhƒE‚ğƒhƒ‰ƒbƒO‚µ‚Ä‚¢‚é‚Æ‚«‚É•\¦‚·‚éƒJ[ƒ\ƒ‹‚ğæ“¾‚·‚é‚½‚ß‚ÉA
//  ƒVƒXƒeƒ€‚ª‚±‚ÌŠÖ”‚ğŒÄ‚Ño‚µ‚Ü‚·B
HCURSOR CMFCApplication3Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication3Dlg::OnTvnSelchangedTree1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: ‚±‚±‚ÉƒRƒ“ƒgƒ[ƒ‹’Ê’mƒnƒ“ƒhƒ‰[ ƒR[ƒh‚ğ’Ç‰Á‚µ‚Ü‚·B
	*pResult = 0;
}


void CMFCApplication3Dlg::OnBnClickedButton1()
{
	// TODO: ‚±‚±‚ÉƒRƒ“ƒgƒ[ƒ‹’Ê’mƒnƒ“ƒhƒ‰[ ƒR[ƒh‚ğ’Ç‰Á‚µ‚Ü‚·B

}


BOOL CMFCApplication3Dlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: ‚±‚±‚É“Á’è‚ÈƒR[ƒh‚ğ’Ç‰Á‚·‚é‚©A‚à‚µ‚­‚ÍŠî’êƒNƒ‰ƒX‚ğŒÄ‚Ño‚µ‚Ä‚­‚¾‚³‚¢B
	static BOOL bInvalid = FALSE;
	//		87	82				220
	//	65	83	68	70
	if (pMsg->message == WM_KEYDOWN && pMsg->wParam == 220)
	{
		m_lock = !m_lock;
	}
	else if (pMsg->message == WM_KEYDOWN && pMsg->wParam == 83 && !m_lock) // s
	{
		CWindowDC dc(GetDesktopWindow());
		dc.SelectObject(&font);
		dc.SelectObject(pBrush);

		CString str;
		str.Format(_T("%d "), m_arr.GetCount());
		str += m_data.lString;
#ifdef HOME
		str += _T("    ");
#else
		str += _T("  ");
#endif
#ifdef HOME
		dc.TextOut(X_POSITION, Y_POSITION, str + _T("                                       "));
		dc.TextOut(X_POSITION, Y_POSITION + FONT_SIZE, m_data.rString + _T("                                       "));
#else
		str += m_data.rString;
		str += _T("                          ");
		dc.TextOut(X_POSITION, Y_POSITION, str);
#endif
	}
	else if (pMsg->message == WM_KEYDOWN && pMsg->wParam == 87 && !m_lock) // w
	{
		if (m_bShowWord){
			if (m_arr.IsEmpty())
				return CDialogEx::PreTranslateMessage(pMsg);
			if (bInvalid)
			{
				m_arrDelete.Add(m_data);
				DeleteFile(Write_File);
#ifdef HOME
				DeleteFile(Write_File_To_Word_Book);
				CFile cfile1;
				cfile1.Open(Write_File_To_Word_Book, CFile::modeReadWrite | CFile::modeCreate);
#endif
				CFile cfile;
				cfile.Open(Write_File, CFile::modeReadWrite | CFile::modeCreate);
				for (int i = 0; i < m_arr.GetCount(); i++)
				{
					STRING_DATA data = m_arr.GetAt(i);

					CString str = data.lString + data.rString;
					CString s;
					s.Format(_T("%d\r\n"), data.nTimes);
					str += s;
					int nSize = WideCharToMultiByte(CP_UTF8, 0, str, -1, NULL, 0, NULL, NULL);
					char *pchCell = new char[nSize + 1];
					memset(pchCell, 0, nSize + 1);
					WideCharToMultiByte(CP_UTF8, 0, str, -1, pchCell, nSize, NULL, NULL);

#ifdef HOME
					if (data.nTimes <= 0)
						cfile1.Write(pchCell, nSize - 1);
					else
						cfile.Write(pchCell, nSize - 1);
#else
					cfile.Write(pchCell, nSize - 1);
#endif
				}

				for (int i = 0; i < m_arrDelete.GetCount(); i++)
				{
					STRING_DATA data = m_arrDelete.GetAt(i);

					CString str = data.lString + data.rString;
					CString s;
					s.Format(_T("%d\r\n"), data.nTimes);
					str += s;
					int nSize = WideCharToMultiByte(CP_UTF8, 0, str, -1, NULL, 0, NULL, NULL);
					char *pchCell = new char[nSize + 1];
					memset(pchCell, 0, nSize + 1);
					WideCharToMultiByte(CP_UTF8, 0, str, -1, pchCell, nSize, NULL, NULL);

#ifdef HOME
					if (data.nTimes <= 0)
						cfile1.Write(pchCell, nSize - 1);
					else
						cfile.Write(pchCell, nSize - 1);
#else
					cfile.Write(pchCell, nSize - 1);
#endif
				}

#ifdef HOME
				cfile1.Close();
#endif
				cfile.Close();
			}
			bInvalid = TRUE;


			while (TRUE)
			{
				int range_min = 0;
				int range_max = m_arr.GetCount();
				if (range_max > 0)
				{
					int u = range_min + rand() % (range_max - range_min + 1);
					//int u = (double)rand() / (RAND_MAX + 1) * (range_max - range_min)
					//	+ range_min;
					if (u >= m_arr.GetCount())
						continue;

					m_data = m_arr.GetAt(u);
					if (m_data.nTimes <= 0)
					{
						m_arr.RemoveAt(u);
						m_arrDelete.Add(m_data);
						continue;
					}

					m_data.nTimes--;
					m_arr.RemoveAt(u);
					CWindowDC dc(GetDesktopWindow());
					dc.SelectObject(&font);
					dc.SelectObject(pBrush);
					CString str;
					str.Format(_T("%d "), m_arr.GetCount());
					str += m_data.lString;
					str += _T("                                                                ");
					dc.TextOut(X_POSITION, Y_POSITION, str);
#ifdef HOME
					dc.TextOut(X_POSITION, Y_POSITION + FONT_SIZE, _T("                                                      "));
#endif
					break;
				}
				else
				{
					bInvalid = FALSE;
					break;
				}
			}
		}
		else
		{
			int range_min = 0;
			int range_max = m_arr1.GetCount();
			if (range_max > 0)
			{
				while (true)
				{
					int u = range_min + rand() % (range_max - range_min + 1);
					//int u = (double)rand() / (RAND_MAX + 1) * (range_max - range_min)
					//	+ range_min;
					if (u >= m_arr1.GetCount())
						continue;

					m_data = m_arr1.GetAt(u);
					m_arr1_c.Add(m_data);
					m_arr1.RemoveAt(u);
					CWindowDC dc(GetDesktopWindow());
					dc.SelectObject(&font);
					dc.SelectObject(pBrush);
					CString str = _T("  ");
					str += m_data.lString;
					str += _T("                                ");
					dc.TextOut(X_POSITION, Y_POSITION, str);
#ifdef HOME
						dc.TextOut(X_POSITION, Y_POSITION + FONT_SIZE, _T("                                                      "));
#endif
					break;
				}
			}
			else
			{
				m_arr1.Copy(m_arr1_c);
				m_arr1_c.RemoveAll();
			}
		}
	}
	else if (pMsg->message == WM_KEYDOWN && pMsg->wParam == 65 && !m_lock) // a
	{
		CWindowDC dc(GetDesktopWindow());
		dc.SelectObject(&font);
		dc.SelectObject(pBrush);
		dc.TextOut(X_POSITION, Y_POSITION, _T("                                                                                                                                                              "));
	}
	else if (pMsg->message == WM_KEYDOWN && pMsg->wParam == 68 && !m_lock) // d
	{
		CWindowDC dc(GetDesktopWindow());
		dc.SelectObject(&font);
		dc.SelectObject(pBrush);
		CString str;
		str.Format(_T("%d "), m_arr.GetCount());
		str += m_data.lString;
		str += _T("                                                                ");
		dc.TextOut(X_POSITION, Y_POSITION, str);
	}
	else if (pMsg->message == WM_KEYDOWN && pMsg->wParam == 70 && !m_lock) // f
	{
		m_bShowWord = !m_bShowWord;
	}
	else if (pMsg->message == WM_KEYDOWN && pMsg->wParam == 82 && !m_lock) // r
	{
		m_data.nTimes = RECITAL_TIME;
		CString m_str = m_data.lString + m_data.rString.Left(m_data.rString.GetLength() - 1);
		m_str += _T("\r\n");
		if (!m_data.bAdded)
		{
			int nSize = WideCharToMultiByte(CP_UTF8, 0, m_str, -1, NULL, 0, NULL, NULL);
			char *pchCell = new char[nSize + 1];
			memset(pchCell, 0, nSize + 1);
			WideCharToMultiByte(CP_UTF8, 0, m_str, -1, pchCell, nSize, NULL, NULL);

			CFile cfile;
			cfile.Open(Write_File_Re, CFile::modeReadWrite | CFile::modeCreate | CFile::modeNoTruncate);
			cfile.SeekToEnd();
			cfile.Write(pchCell, nSize - 1);
			cfile.Close();
			delete[]pchCell;
			m_data.bAdded = TRUE;
			m_arr1.Add(m_data);
		}

		CWindowDC dc(GetDesktopWindow());
		dc.SelectObject(&font);
		dc.SelectObject(pBrush);
		CString str; m_str = m_data.lString + _T("    ") + m_data.rString.Left(m_data.rString.GetLength() - 1);
		str.Format(_T("%d "), m_arr1.GetCount());
#ifdef HOME
		dc.TextOut(X_POSITION, Y_POSITION, str + m_data.lString + _T("                                       "));
		dc.TextOut(X_POSITION, Y_POSITION + FONT_SIZE, m_data.rString + _T("                                       "));
#else
		str += m_str;
		str += _T("    ");
		dc.TextOut(X_POSITION, Y_POSITION, str);
#endif
	}
	else if (pMsg->message == WM_LBUTTONDOWN)
	{
		if (bInvalid)
		{
			m_arrDelete.Add(m_data);
			DeleteFile(Write_File);
#ifdef HOME
			DeleteFile(Write_File_To_Word_Book);
			CFile cfile1;
			cfile1.Open(Write_File_To_Word_Book, CFile::modeReadWrite | CFile::modeCreate);
#endif
			CFile cfile;
			cfile.Open(Write_File, CFile::modeReadWrite | CFile::modeCreate);
			for (int i = 0; i < m_arr.GetCount(); i++)
			{
				STRING_DATA data = m_arr.GetAt(i);

				CString str = data.lString + data.rString;
				CString s;
				s.Format(_T("%d\r\n"), data.nTimes);
				str += s;
				int nSize = WideCharToMultiByte(CP_UTF8, 0, str, -1, NULL, 0, NULL, NULL);
				char *pchCell = new char[nSize + 1];
				memset(pchCell, 0, nSize + 1);
				WideCharToMultiByte(CP_UTF8, 0, str, -1, pchCell, nSize, NULL, NULL);

#ifdef HOME
				if (data.nTimes <= 0)
					cfile1.Write(pchCell, nSize - 1);
				else
					cfile.Write(pchCell, nSize - 1);
#else
				cfile.Write(pchCell, nSize - 1);
#endif
			}

			for (int i = 0; i < m_arrDelete.GetCount(); i++)
			{
				STRING_DATA data = m_arrDelete.GetAt(i);

				CString str = data.lString + data.rString;
				CString s;
				s.Format(_T("%d\r\n"), data.nTimes);
				str += s;
				int nSize = WideCharToMultiByte(CP_UTF8, 0, str, -1, NULL, 0, NULL, NULL);
				char *pchCell = new char[nSize + 1];
				memset(pchCell, 0, nSize + 1);
				WideCharToMultiByte(CP_UTF8, 0, str, -1, pchCell, nSize, NULL, NULL);

#ifdef HOME
				if (data.nTimes <= 0)
					cfile1.Write(pchCell, nSize - 1);
				else
					cfile.Write(pchCell, nSize - 1);
#else
				cfile.Write(pchCell, nSize - 1);
#endif
			}

#ifdef HOME
			cfile1.Close();
#endif
			cfile.Close();
		}
		exit(1);
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}
