// SettingDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "XiaoCaiCai.h"
#include "SettingDlg.h"


// CSettingDlg 对话框

IMPLEMENT_DYNAMIC(CSettingDlg, CDialog)

CSettingDlg::CSettingDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSettingDlg::IDD, pParent)
{
}

CSettingDlg::~CSettingDlg()
{
}

void CSettingDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	for(int i = 0; i < 14; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			DDX_Check(pDX, IDC_CHECK1 + i * 3 + j, m_pDlgData->m_select[i][j]);
		}
	}
}


BEGIN_MESSAGE_MAP(CSettingDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &CSettingDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CSettingDlg 消息处理程序

BOOL CSettingDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化

	memset(m_pDlgData->m_select, 0, 42);
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void CSettingDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码

}
