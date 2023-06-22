
// ServerDlg.h : header file
//

#pragma once

#include <Windows.h>
#include "ServerCon.h"

// CServerDlg dialog
class CServerDlg : public CDialogEx
{
// Construction
public:
	CServerDlg(CWnd* pParent = nullptr);	// standard constructor
	void ShowServerInfo(string sValue);

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SERVER_DIALOG };
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

private:
	HANDLE m_Thread_handle;
	CWinThread* cTh;
public:
	afx_msg void OnEnChangeEdit1();
	CString m_buffer;
	CEdit m_Textbox;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();

	ServerCon* m_pServer;
	static UINT __cdecl StaticThreadFunc(LPVOID pParam);
	UINT ThreadFunc();
	void AppendTextToEditCtrl(CEdit& edit, LPCTSTR pszText);
	CEdit m_Portbox;

};
