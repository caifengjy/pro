
// IvanApplicationDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "IvanApplication.h"
#include "IvanApplicationDlg.h"
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
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CIvanApplicationDlg 对话框



CIvanApplicationDlg::CIvanApplicationDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_IVANAPPLICATION_DIALOG, pParent)
	, m_selFileName(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CIvanApplicationDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_wantEdit);
	DDX_Control(pDX, IDC_EDIT3, m_editTotal);
	DDX_Control(pDX, IDC_EDIT4, m_editAll);
	DDX_Control(pDX, IDC_EDIT5, m_editMiss1);
	DDX_Control(pDX, IDC_LIST1, m_list);
}

BEGIN_MESSAGE_MAP(CIvanApplicationDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CIvanApplicationDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &CIvanApplicationDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CIvanApplicationDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CIvanApplicationDlg 消息处理程序

BOOL CIvanApplicationDlg::OnInitDialog()
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

	// TODO: 在此添加额外的初始化代码

	CRect rect;
	m_list.GetWindowRect(&rect);
	m_list.InsertColumn(0, _T("编号"));//添加列
	m_list.InsertColumn(1, _T("号码"));
	m_list.SetColumnWidth(0, 40);//设置列宽
	m_list.SetColumnWidth(1, rect.Width() - 80);
	//m_list.SetRedraw(FALSE);//防止重绘
	((CButton *)GetDlgItem(IDC_RADIO1))->SetCheck(TRUE);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CIvanApplicationDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CIvanApplicationDlg::OnPaint()
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
HCURSOR CIvanApplicationDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CIvanApplicationDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CSingelDataManager::GetInstance()->Reload();

	Initial();
	m_selList.clear();
	m_vecList.clear();
	Build(m_vecList, CSingelDataManager::GetInstance()->m_ratio);
	random_shuffle(m_vecList.begin(), m_vecList.end());

	CString str;
	str.Format(_T("%d"), m_vecList.size());
	m_editTotal.SetWindowText(str);
	m_editAll.SetWindowText(_T(""));
	m_editMiss1.SetWindowText(_T(""));

	WriteToFile(FILE_NAME_ALL, m_vecList, m_vecList.size());
	WriteToFile(FILE_NAME_SEL, m_vecList, 1000);
	//CDialogEx::OnOK();

	MessageBox(_T("生成成功!"));
}

void CIvanApplicationDlg::Initial()
{
	SYSTEMTIME st;
	GetLocalTime(&st);
	srand(st.wMilliseconds * 416 * 1008);
}

void CIvanApplicationDlg::Build(vector<CNumber> &list, CNumber ratio)
{
	vector<CNumber> tList;
	//ReadFile(_T("data.dat"), tList);
	ReadEvery(tList);
	for each (CNumber var in tList)
	{
		if (var.CompareRatio(ratio)) {
			//printf(num.getString().c_str());
			//printf("\n");
			if (var.CompareVector(CSingelDataManager::GetInstance()->m_vecSelNum1) <= CSingelDataManager::GetInstance()->m_thresholdValue1)
			{
				if (var.CompareVector(CSingelDataManager::GetInstance()->m_vecSelNum2) <= CSingelDataManager::GetInstance()->m_thresholdValue2)
				{
					if (var.CompareVector(CSingelDataManager::GetInstance()->m_vecSelNum3) <= CSingelDataManager::GetInstance()->m_thresholdValue3)
					{
						list.push_back(var);
					}
				}
			}
		}
	}
}

void CIvanApplicationDlg::WriteToFile(char *fileName, vector<CNumber> &list, size_t printCount)
{
	FILE *fp;
	if ((fopen_s(&fp, fileName, "wt")) != NULL) {
		printf("Cannot open file strike any key exit!");
		return;
	}
	for each (CNumber var in list) {
		if (printCount-- == 0)
		{
			break;
		}
		string str = var.getString();
		str += "\n";
		fwrite(str.c_str(), 15, 1, fp);
	}
	fclose(fp);
}

void CIvanApplicationDlg::ReadFile(LPCWSTR fileName, vector<CNumber> &list)
{
	CFile cfile;
	cfile.Open(fileName, CFile::modeRead);
	char *pbufRead = new char[200 * 1024 * 1024];
	memset(pbufRead, 0, 200 * 1024 * 1024);
	cfile.Read(pbufRead, 200 * 1024 * 1024);
	cfile.Close();

	int i = 0;
	int len = strlen(pbufRead);
	while (len - i >= 14)
	{
		CNumber num(pbufRead[i + 0] - '0', pbufRead[i + 1] - '0', pbufRead[i + 2] - '0',
			pbufRead[i + 3] - '0', pbufRead[i + 4] - '0', pbufRead[i + 5] - '0',
			pbufRead[i + 6] - '0', pbufRead[i + 7] - '0', pbufRead[i + 8] - '0',
			pbufRead[i + 9] - '0', pbufRead[i + 10] - '0', pbufRead[i + 11] - '0',
			pbufRead[i + 12] - '0', pbufRead[i + 13] - '0');
		list.push_back(num);

		i += 16;
	}
}

void CIvanApplicationDlg::ReadEvery(vector<CNumber> &list)
{
	for (int n0 = 0; n0 < 3; n0++)
	for (int n1 = 0; n1 < 3; n1++)
	for (int n2 = 0; n2 < 3; n2++)
	for (int n3 = 0; n3 < 3; n3++)
	for (int n4 = 0; n4 < 3; n4++)
	for (int n5 = 0; n5 < 3; n5++)
	for (int n6 = 0; n6 < 3; n6++)
	for (int n7 = 0; n7 < 3; n7++)
	for (int n8 = 0; n8 < 3; n8++)
	for (int n9 = 0; n9 < 3; n9++)
	for (int n10 = 0; n10 < 3; n10++)
	for (int n11 = 0; n11 < 3; n11++)
	for (int n12 = 0; n12 < 3; n12++)
	for (int n13 = 0; n13 < 3; n13++)
	{
		CNumber num(n0, n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, n12, n13);
		list.push_back(num);
	}
}

void CIvanApplicationDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CString str;
	CNumber num; 
	UpdateData(FALSE);
	
	m_wantEdit.GetWindowText(str);
	if (str.GetLength() != MATCH_COUNT)
	{
		MessageBox(_T("输入错误!"));
		return;
	}
	for (int i = 0; i < MATCH_COUNT; i++)
	{
		num.m_number[i] = str.GetAt(i) - '0';
	}

	vector<CNumber> tList, sList;
	if(((CButton *)GetDlgItem(IDC_RADIO1))->GetCheck())
	{
		ReadFile(_T("all.txt"), tList);
	}
	else if (((CButton *)GetDlgItem(IDC_RADIO2))->GetCheck())
	{
		ReadFile(_T("sel.txt"), tList);
	}

	int all = 0;
	int miss1 = 0;
	for each (CNumber var in tList)
	{
		int diff = var.Compare(num);
		if (diff == 0)
		{
			all++;
			sList.push_back(var);
		}
		else if (diff == 1)
		{
			miss1++;
			sList.push_back(var);
		}
	}

	SetListControl(sList);

	str.Format(_T("%d"), tList.size());
	m_editTotal.SetWindowText(str);
	str.Format(_T("%d"), all);
	m_editAll.SetWindowText(str);
	str.Format(_T("%d"), miss1);
	m_editMiss1.SetWindowText(str);
}

void CIvanApplicationDlg::SetListControl(vector<CNumber> list)
{
	CString str;
	m_list.DeleteAllItems();//清空
	for (int i = 0; i < list.size(); i++)
	{
		str.Format(_T("%d"), i + 1);
		int nRow = m_list.InsertItem(i, str);//插入行
		m_list.SetItemText(nRow, 1, list.at(i).getCString());//设置数据
	}
}

void CIvanApplicationDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码

	SYSTEMTIME st;
	GetLocalTime(&st);

	int nSel = st.wMilliseconds;
	while (nSel >= m_vecList.size())
	{
		nSel -= m_vecList.size();
	}
	m_selList.push_back(m_vecList.at(nSel));
	WriteToFile(FILE_NAME_GO, m_selList, m_selList.size());
	//random_shuffle(m_vecList.begin(), m_vecList.end());
}
