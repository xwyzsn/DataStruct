
// classworkDlg.h: 头文件
//

#pragma once


// CclassworkDlg 对话框
class CclassworkDlg : public CDialogEx
{
// 构造
public:
	CclassworkDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CLASSWORK_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit2();
	CString user_name;
	CString user_pwd;
	CButton login;
	CButton remove;
	CButton insert;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton2();
	CStatic m_pic;
	CButton change_pwd;
	afx_msg void OnBnClickedButton4();
};
