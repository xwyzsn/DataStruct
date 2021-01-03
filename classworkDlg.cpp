
// classworkDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "classwork.h"
#include "classworkDlg.h"
#include "afxdialogex.h"
#include"AVL.h"
#include"file.h"
#include<string>
 
AVL<string>t;//建立一颗string类型的树以用来存储用户名

file f;//用于读写操作



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


// CclassworkDlg 对话框



CclassworkDlg::CclassworkDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CLASSWORK_DIALOG, pParent)
	, user_name(_T(""))
	, user_pwd(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CclassworkDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, user_name);
	DDX_Text(pDX, IDC_EDIT2, user_pwd);
	DDX_Control(pDX, IDC_BUTTON1, login);
	DDX_Control(pDX, IDC_BUTTON2, remove);
	DDX_Control(pDX, IDC_BUTTON3, insert);
	DDX_Control(pDX, IDC_PIC, m_pic);
	DDX_Control(pDX, IDC_BUTTON4, change_pwd);
}

BEGIN_MESSAGE_MAP(CclassworkDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CclassworkDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &CclassworkDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON2, &CclassworkDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON4, &CclassworkDlg::OnBnClickedButton4)
END_MESSAGE_MAP()


// CclassworkDlg 消息处理程序

BOOL CclassworkDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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
	m_pic.ModifyStyle(0xf, SS_BITMAP | SS_CENTERIMAGE);
	#define HBMP(filepath, width, height)(HBITMAP)LoadImage(AfxGetInstanceHandle(), filepath, IMAGE_BITMAP, width, height, LR_LOADFROMFILE | LR_CREATEDIBSECTION)

	CRect rect;
	m_pic.GetWindowRect(rect);

	m_pic.SetBitmap(HBMP(TEXT("./1.bmp"), rect.Width(), rect.Height()));//初始化静态文本为图片。
	
	t.init_insert();//调用AVL树中的函数 init_insert(),根据文本中的数据建立一颗树；

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CclassworkDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CclassworkDlg::OnPaint()
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
HCURSOR CclassworkDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CclassworkDlg::OnBnClickedButton1()
{      //登陆按钮的实现。
		UpdateData(true);//获取最新的值

	if (user_name.IsEmpty()) {
		MessageBox(_T("用户名不能为空"));
		return;
	}

	string str2 = CW2A(user_name.GetString());//CSstring 转化为string类型。
    
	if (t.search(str2)) {
		//在树中查找给定的用户名
		string str1 = CW2A(user_pwd.GetString());
		if (f.search(str2)==str1) {
			//调用File类查找功能并且返回密码进行对比
			MessageBox(_T("登陆成功！欢迎你！"));
		
		}
		else {
			MessageBox(_T("密码错误"));
		}
	}
	else {
		MessageBox(_T("用户名不存在"));
	}
}


void CclassworkDlg::OnBnClickedButton3()
{//插入按钮实现
	UpdateData(true);
	string str1 = CW2A(user_name.GetString());
	string str2 = CW2A(user_pwd.GetString());
	if (user_name.IsEmpty()) {
		MessageBox(_T("用户名不能为空"));
		return;
	}
	if (t.search(str1)) {
		MessageBox(_T("用户已经存在！"));
	}
	else {

		t.insert(t.head, str1);
		//往树中插入用户名
		f.Insert(str1, str2);
		//将用户名和密码写入文本中
		MessageBox(_T("插入成功！"));
	}

}


void CclassworkDlg::OnBnClickedButton2()
{
	//删除按钮实现
	UpdateData(true);
	string str = CW2A(user_name.GetString());
	if (user_name.IsEmpty()) {
		MessageBox(_T("用户名不能为空"));
		return;
	}
	if (t.search(str)) {
		//在树中查询给定用户
		t.remove(t.head, str); 
		//调用树中的删除，删除树中的用户名
		MessageBox(_T("删除成功！"));
		f.remove(str);//删除文件中给定用户的用户名和密码；
	}
	else {

		MessageBox(_T("系统中没有这个用户，删除失败！"));

	}
	
}


void CclassworkDlg::OnBnClickedButton4()
{
	// 修改密码按钮实现
	UpdateData(true);

	string str = CW2A(user_name.GetString());

	string str2 = CW2A(user_pwd.GetString());
	if (user_name.IsEmpty()) {
		MessageBox(_T("用户名不能为空"));
		return;
	}
	if (!t.search(str)) {

		MessageBox((_T("用户不存在！")));
		return;
	}
	f.remove(str);
	//从文件中删除旧数据，将新的密码数据写入到文件中
	f.Insert(str, str2);
	MessageBox(_T("修改成功！"));
}
