#pragma once


// CDia 对话框

class CDia : public CDialogEx
{
	DECLARE_DYNAMIC(CDia)

public:
	CDia(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDia();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CLASSWORK_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
