// CDia.cpp: 实现文件
//

#include "stdafx.h"
#include "classwork.h"
#include "CDia.h"
#include "afxdialogex.h"


// CDia 对话框

IMPLEMENT_DYNAMIC(CDia, CDialogEx)

CDia::CDia(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CLASSWORK_DIALOG, pParent)
{

}

CDia::~CDia()
{
}

void CDia::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDia, CDialogEx)
END_MESSAGE_MAP()


// CDia 消息处理程序
