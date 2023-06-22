#include "framework.h"
#include "pch.h"
#include <stdio.h>

#include <string.h>
#include "ClientDlg.h"

#pragma comment (lib, "ws2_32.lib") //winsock library
#pragma warning(disable : 4996)

ClientCon::ClientCon(CClientDlg* dlg)
{
	m_pClient = dlg;
}

//destroy function
ClientCon::~ClientCon(void)
{
	closesocket(s);
	WSACleanup();
}

void ClientCon::StartConnect(string sAddress, int iPort, string sUsername)
{
	struct sockaddr_in server;
	char* message, server_reply[2000];
	int recv_size;
	m_pUser = sUsername;

	printf("\nInitialising Winsock...");
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) //tra ve gia tri 0 neu khoi tao thanh cong, khong thi bao loi
	{
		printf("Failed. Error Code : %d", WSAGetLastError());
		return;
	}

	printf("Initialised \n");

	//Create socket
	if ((s = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
	{
		printf("Could not create socket : %d", WSAGetLastError());
	}
	printf("Socket created.\n");


	server.sin_addr.s_addr = inet_addr(sAddress.c_str()); //sAddress = ip may chu
	server.sin_family = AF_INET; // gan kieu IPv4
	server.sin_port = htons(iPort); 

	//Connect to remote server
	if (connect(s, (struct sockaddr*)&server, sizeof(server)) < 0)
	{
		puts("connect error");
		return;
	}

	puts("Connected");

	 //Receive a reply from the server
	while ((recv_size = recv(s, server_reply, 2000, 0)) != SOCKET_ERROR)
	{
		puts("Reply received\n");

		//Add a NULL terminating character to make it a proper string before printing
		server_reply[recv_size] = '\0';
		puts(server_reply);

		string sTempMsg = "\n" + string(server_reply) + "\n";
		m_pClient->ShowServerInfo(sTempMsg);
	}

}

void ClientCon::SendData(string sMessage)
{
	string sTemp = m_pUser + ">>" + sMessage + "\n";

	if (send(s, sTemp.c_str(), sTemp.size(), 0) < 0)
	{
		puts("Send failed");
		return;
	}
}




