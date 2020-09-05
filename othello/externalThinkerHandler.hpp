#pragma once
#include "externalThinkerMessages.hpp"

// Class
class ExternalThinkerHandler {
private:
	PROTOCOLSTATES state;
	char hostname[256];
	int port;
	WSAData wsaData;
	SOCKET sock;
	struct addrinfo hints, *res0, *res;
	DISKCOLORS board[8][8];
	int turn;
	int currentReqId;
	HWND hWnd;
	UINT_PTR TimerIdWaitThinkAccept;

public:
	ExternalThinkerHandler();
	~ExternalThinkerHandler();
	int init(char* _hostname, int _port, HWND _hWnd);
	int setWindowHandle(HWND _hwnd);
	int sendInformationRequest();
	int sendThinkRequest(int turn, DISKCOLORS board[8][8], HWND _hWnd);
	int receiveMessages();
};