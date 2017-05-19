
// CaiFengJYDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CaiFengJY.h"
#include "CaiFengJYDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CCaiFengJYDlg 对话框



CCaiFengJYDlg::CCaiFengJYDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCaiFengJYDlg::IDD, pParent)
	, m_randNum(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCaiFengJYDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_randNum);
	DDX_Text(pDX, IDC_EDIT2, m_value[0]);
	DDX_Text(pDX, IDC_EDIT3, m_value[1]);
	DDX_Text(pDX, IDC_EDIT4, m_value[2]);
	DDX_Text(pDX, IDC_EDIT5, m_value[3]);
	DDX_Text(pDX, IDC_EDIT6, m_value[4]);
	DDX_Text(pDX, IDC_EDIT7, m_value[5]);
	DDX_Text(pDX, IDC_EDIT8, m_value[6]);
	DDX_Text(pDX, IDC_EDIT9, m_value[7]);
	DDX_Text(pDX, IDC_EDIT10, m_value[8]);
	DDX_Text(pDX, IDC_EDIT11, m_value[9]);
	DDX_Text(pDX, IDC_EDIT12, m_value[10]);
	DDX_Text(pDX, IDC_EDIT13, m_value[11]);
	DDX_Text(pDX, IDC_EDIT14, m_value[12]);
	DDX_Text(pDX, IDC_EDIT15, m_value[13]);
}

BEGIN_MESSAGE_MAP(CCaiFengJYDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CCaiFengJYDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CCaiFengJYDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CCaiFengJYDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// CCaiFengJYDlg 消息处理程序

BOOL CCaiFengJYDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CCaiFengJYDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CCaiFengJYDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CCaiFengJYDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCaiFengJYDlg::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码
	m_dataMgr.InitList();
	this->SetWindowTextW(_T("OK"));
}


void CCaiFengJYDlg::OnBnClickedButton2()
{
	// TODO:  在此添加控件通知处理程序代码
	m_randNum = m_dataMgr.GetRandNumber();
	for (int i = 0; i < 14; i++)
	{
		m_value[i] = m_randNum.GetAt(i);
	}
	UpdateData(FALSE);
}


void CCaiFengJYDlg::OnBnClickedButton3()
{
	// TODO:  在此添加控件通知处理程序代码
	m_arrData.RemoveAll();
	UpdateData();
	for (int i1 = 0; i1 < m_value[0].GetLength(); i1++)
		for (int i2 = 0; i2 < m_value[1].GetLength(); i2++)
			for (int i3 = 0; i3 < m_value[2].GetLength(); i3++)
				for (int i4 = 0; i4 < m_value[3].GetLength(); i4++)
					for (int i5 = 0; i5 < m_value[4].GetLength(); i5++)
						for (int i6 = 0; i6 < m_value[5].GetLength(); i6++)
							for (int i7 = 0; i7 < m_value[6].GetLength(); i7++)
								for (int i8 = 0; i8 < m_value[7].GetLength(); i8++)
									for (int i9 = 0; i9 < m_value[8].GetLength(); i9++)
										for (int i10 = 0; i10 < m_value[9].GetLength(); i10++)
											for (int i11 = 0; i11 < m_value[10].GetLength(); i11++)
												for (int i12 = 0; i12 < m_value[11].GetLength(); i12++)
													for (int i13 = 0; i13 < m_value[12].GetLength(); i13++)
														for (int i14 = 0; i14 < m_value[13].GetLength(); i14++)
														{
															CString str;
															str.Format(_T("%c%c%c%c%c%c%c%c%c%c%c%c%c%c"), m_value[0].GetAt(i1), 
																m_value[1].GetAt(i2), 
																m_value[2].GetAt(i3), 
																m_value[3].GetAt(i4), 
																m_value[4].GetAt(i5), 
																m_value[5].GetAt(i6), 
																m_value[6].GetAt(i7), 
																m_value[7].GetAt(i8), 
																m_value[8].GetAt(i9), 
																m_value[9].GetAt(i10), 
																m_value[10].GetAt(i11), 
																m_value[11].GetAt(i12), 
																m_value[12].GetAt(i13), 
																m_value[13].GetAt(i14));
															m_arrData.Add(str);
														}


	srand((unsigned)time(NULL));
	CString strShow;
	if (m_arrData.GetCount() < 10)
		return;

	for (int i = 0; i < 10; i++)
	{
		int n = rand() % m_arrData.GetCount();
		strShow += m_arrData.GetAt(n);
		strShow += _T("\r\n");
		m_arrData.RemoveAt(n);
	}

	SetDlgItemText(IDC_EDIT16, strShow);
}
