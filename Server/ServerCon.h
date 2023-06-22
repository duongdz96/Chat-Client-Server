#pragma once
#include<winSock2.h>
#include <afxwin.h>

class CServerDlg;

#pragma comment (lib, "ws2_32.lib")

class ServerCon
{
public: 
	ServerCon(CServerDlg* dialog);
	~ServerCon(void);

	void StartListening(int iPort);

	static UINT __cdecl DataThreadFunc(LPVOID pParam);
	UINT SendReceiveData(SOCKET cSocket);
	void ClearServer();
	WSADATA wsa;
	SOCKET s, new_socket;

	struct sockaddr_in server, client;
	int c;

	int iTempCount;
	CServerDlg* m_pDialog;
	HANDLE m_Thread_handle[100];
	CWinThread* cpTh[100];
	static void SetStaticVariable(int ic, SOCKET cS);
};
