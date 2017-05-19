// XiaoCaiCaiDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "XiaoCaiCai.h"
#include "XiaoCaiCaiDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CXiaoCaiCaiDlg �Ի���




CXiaoCaiCaiDlg::CXiaoCaiCaiDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CXiaoCaiCaiDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CXiaoCaiCaiDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_tab);
}

BEGIN_MESSAGE_MAP(CXiaoCaiCaiDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &CXiaoCaiCaiDlg::OnTcnSelchangeTab1)
	ON_BN_CLICKED(IDOK, &CXiaoCaiCaiDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CXiaoCaiCaiDlg ��Ϣ�������

BOOL CXiaoCaiCaiDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	m_tab.InsertItem(0,_T("����"));    //��ɫ����Ϊÿһҳ��ʾ�ı���
	m_tab.InsertItem(1,_T("���"));    //��ɫ����Ϊÿһҳ��ʾ�ı���
	m_settingDlg.m_pDlgData = &m_dlgData;
	m_settingDlg.Create(IDD_DIALOG_SETTING,&m_tab);
	m_resultDlg.Create(IDD_DIALOG_SHOW_RESULT,&m_tab);
	CRect rc;
	m_tab.GetClientRect(rc);
	rc.top += 22;
	rc.bottom -= 2;
	rc.left += 1;
	rc.right -= 4;
	m_settingDlg.MoveWindow(rc);
	m_settingDlg.ShowWindow(SW_SHOW);
	m_resultDlg.MoveWindow(rc);
	m_resultDlg.ShowWindow(SW_HIDE);

	//GeneralData();
	//CString str;
	//str.Format(IDS_STRING_TOTAL, m_dlgData.m_listAllData.size());
	//this->SetDlgItemText(IDC_STATIC_TOTAL, str);
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CXiaoCaiCaiDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CXiaoCaiCaiDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CXiaoCaiCaiDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CXiaoCaiCaiDlg::OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	switch(m_tab.GetCurSel())
	{
	case 0:
		m_settingDlg.ShowWindow(SW_SHOW);
		m_resultDlg.ShowWindow(SW_HIDE);
		break;
	case 1:
		m_settingDlg.ShowWindow(SW_HIDE);
		m_resultDlg.ShowWindow(SW_SHOW);
		break;
	default:
		break;
	}
	*pResult = 0;
}

void CXiaoCaiCaiDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
//	m_settingDlg.UpdateData();
	OnOK();
}

void CXiaoCaiCaiDlg::GeneralData()
{

}

int CXiaoCaiCaiDlg::ChangedData(int data)
{
	if(data == 2)
		return 3;
	return data;
}
