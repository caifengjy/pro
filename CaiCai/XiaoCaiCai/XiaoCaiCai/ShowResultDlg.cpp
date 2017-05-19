// ShowResultDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "XiaoCaiCai.h"
#include "ShowResultDlg.h"


// CShowResultDlg 对话框

IMPLEMENT_DYNAMIC(CShowResultDlg, CDialog)

CShowResultDlg::CShowResultDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CShowResultDlg::IDD, pParent)
	, m_count(0)
	, m_give(_T(""))
	, m_giveNum(0)
	, m_cmpNum(0)
{

}

CShowResultDlg::~CShowResultDlg()
{
}

void CShowResultDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST2, m_listCtrl);
	DDX_Text(pDX, IDC_EDIT1, m_count);
	DDV_MinMaxInt(pDX, m_count, 0, 5);
	DDX_Text(pDX, IDC_EDIT2, m_give);
	DDX_Text(pDX, IDC_EDIT3, m_giveNum);
	DDX_Text(pDX, IDC_EDIT4, m_cmpNum);
}


BEGIN_MESSAGE_MAP(CShowResultDlg, CDialog)
//	ON_BN_CLICKED(IDC_BUTTON1, &CShowResultDlg::OnBnClickedButton1)
ON_BN_CLICKED(IDC_BUTTON1, &CShowResultDlg::OnBnClickedButton1)
ON_BN_CLICKED(IDC_BUTTON2, &CShowResultDlg::OnBnClickedButton2)
ON_BN_CLICKED(IDC_BUTTON3, &CShowResultDlg::OnBnClickedButton3)
ON_BN_CLICKED(IDC_BUTTON4, &CShowResultDlg::OnBnClickedButton4)
END_MESSAGE_MAP()


// CShowResultDlg 消息处理程序

BOOL CShowResultDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_listCtrl.InsertColumn(0, _T("号码"));
	m_listCtrl.InsertColumn(1, _T("期号"));
	m_listCtrl.InsertColumn(2, _T("奖金"));
	m_listCtrl.InsertColumn(3, _T("对赛性质"));

	LVCOLUMN lvcolumn;
	m_listCtrl.GetColumn(0,&lvcolumn);
	lvcolumn.mask=LVCF_WIDTH;
	lvcolumn.cx=120;
	m_listCtrl.SetColumn(0,&lvcolumn);

	m_listCtrl.GetColumn(1,&lvcolumn);
	lvcolumn.mask=LVCF_WIDTH;
	lvcolumn.cx=50;
	m_listCtrl.SetColumn(1,&lvcolumn);

	m_listCtrl.GetColumn(2,&lvcolumn);
	lvcolumn.mask=LVCF_WIDTH;
	lvcolumn.cx=70;
	m_listCtrl.SetColumn(2,&lvcolumn);
	
	m_listCtrl.GetColumn(3,&lvcolumn);
	lvcolumn.mask=LVCF_WIDTH;
	lvcolumn.cx=160;
	m_listCtrl.SetColumn(3,&lvcolumn);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void CShowResultDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	m_listCtrl.DeleteAllItems();
	m_config.ReadConfigFile();
	ShowList(m_config.m_listData);
}

void CShowResultDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	
	m_listCtrl.DeleteAllItems();
	list<ONE_DATA> m_list;
	list<int> m_listIssue;
	m_list.clear();
	m_listIssue.clear();

	list<ONE_DATA>::iterator iter = m_config.m_listData.begin();
	int index = 0;
	while(iter != m_config.m_listData.end())
	{
		list<ONE_DATA>::iterator iter2 = iter;
		iter2++;
		if(iter2 != m_config.m_listData.end())
		{
			for(int i = 0; i < 5; i++)
			{
				if(iter->afterSortSum[i] != iter2->afterSortSum[i])
				{
					index++;
				}
			}
			if(index <= m_count)
			{
				bool bHave1 = FALSE;
				bool bHave2 = FALSE;
				list<int>::iterator issueItor = m_listIssue.begin();
				while(issueItor != m_listIssue.end())
				{
					if(*issueItor == iter->issue)
					{
						bHave1 = true;
					}
					if(*issueItor == iter2->issue)
					{
						bHave2 = true;
					}
				}
				if(iter->issue != iter2->issue)
				{
				if(!bHave1)
					m_list.push_back(*iter);
				if(!bHave2)
					m_list.push_back(*iter2);
				}
			}
			index = 0;
		}
		iter++;
	}

	if(m_list.size() > 0)
	{
		DeleteReuse(m_list);
		ShowList(m_list);
	}
}

void CShowResultDlg::ShowList(list<ONE_DATA> &listRef)
{
	list<ONE_DATA>::iterator iter = listRef.begin();
	int index = 0;
	while(iter != listRef.end())
	{
		CString str, strT;
		for(int i = 0; i < 14; i++)
		{
			strT.Format(_T("%d"), iter->afterSortSum[i]);
			str += strT;
		}
		
		int nRow = m_listCtrl.InsertItem(index ,str);
		str.Format(_T("%d"), iter->issue);
		m_listCtrl.SetItemText(nRow, 1, str);
		str.Format(_T("%d"), iter->bonus);
		m_listCtrl.SetItemText(nRow, 2, str);
		str.Empty();
		for(int i = 0; i < 14; i++)
		{
			CString strT;
			strT = iter->data[i].type;
			if(str.Find(strT) == -1)
			{
				str += strT;
			}
		}
		m_listCtrl.SetItemText(nRow, 3, str);
		iter++;
	}
}

void CShowResultDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
		UpdateData();
	
	m_listCtrl.DeleteAllItems();
	list<ONE_DATA> m_list;
	list<int> m_listIssue;
	m_list.clear();
	m_listIssue.clear();

	list<ONE_DATA>::iterator iter = m_config.m_listData.begin();
	int index = 0;
	while(iter != m_config.m_listData.end())
	{
		list<ONE_DATA>::iterator iter2 = iter;
		iter2++;
		if(iter2 != m_config.m_listData.end())
		{
			for(int i = 0; i < 14; i++)
			{
				if(iter->pSort[i]->result != iter2->pSort[i]->result)
				{
					index++;
				}
			}
			if(index <= m_count)
			{
				bool bHave1 = FALSE;
				bool bHave2 = FALSE;
				list<int>::iterator issueItor = m_listIssue.begin();
				while(issueItor != m_listIssue.end())
				{
					if(*issueItor == iter->issue)
					{
						bHave1 = true;
					}
					if(*issueItor == iter2->issue)
					{
						bHave2 = true;
					}
				}
				if(iter->issue != iter2->issue)
				{
				if(!bHave1)
					m_list.push_back(*iter);
				if(!bHave2)
					m_list.push_back(*iter2);
				}
			}
			index = 0;
		}
		iter++;
	}

	if(m_list.size() > 0)
	{
		DeleteReuse(m_list);
		ShowList(m_list);
	}
}

void CShowResultDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
			UpdateData();
	
	m_listCtrl.DeleteAllItems();
	list<ONE_DATA> m_list;
	list<int> m_listIssue;
	m_list.clear();
	m_listIssue.clear();

	list<ONE_DATA>::iterator iter = m_config.m_listData.begin();
	int index = 0;
	while(iter != m_config.m_listData.end())
	{
		CString strT;
			for(int i = 0; i < m_cmpNum; i++)
			{
				strT = m_give.Right(m_cmpNum - i);
				CString str;
				str.Format(_T("%d"), iter->afterSortSum[i]);
				if(str != _T("0") && str != strT.Left(1))
				{
					index++;
				}
			}
			if(index <= m_giveNum)
			{
				m_list.push_back(*iter);
			}
			index = 0;
		iter++;
	}

	if(m_list.size() > 0)
	{
		DeleteReuse(m_list);
		ShowList(m_list);
	}
}

int CShowResultDlg::DeleteReuse(list<ONE_DATA> &listRef)
{
	for(list<ONE_DATA>::iterator iter = listRef.begin(); iter != listRef.end(); )
	{
		int have = 0;
		list<ONE_DATA>::iterator iter2 = iter;
		iter2++;
		while(iter2 != listRef.end())
		{
			if(iter->issue == iter2->issue)
			{
				have++;
				break;
			}
			iter2++;
		}

		if(have > 0)
		{
			listRef.erase(iter++);
		}
		else
		{
			++iter;
		}
	}
	return 0;
}
