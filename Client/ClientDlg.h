
// ClientDlg.h : header file
//

#pragma once
#include "ClientCon.h"
#include <Windows.h>
#include "resource.h"

// CClientDlg dialog
class CClientDlg : public CDialogEx
{
// Construction
public:
	CClientDlg(CWnd* pParent = nullptr);	// standard constructor
	void ShowServerInfo(string sValue);

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CLIENT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton3();

	ClientCon* m_pClient;
	static UINT __cdecl StaticThreadFunc(LPVOID pParam);
	UINT ThreadFunc();
	void AppendTextToEditCtrl(CEdit& edit, LPCTSTR pszText);
	CEdit m_Portbox;

private:
	HANDLE m_Thread_handle;
	CWinThread* cTh;

public:
	CEdit m_Textbox;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnEnChangeEdit4();
	afx_msg void OnEnChangeEdit5();
};
