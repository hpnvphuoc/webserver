#pragma once

#include <WS2tcpip.h>

#pragma comment (lib, "ws2_32.lib")

class WebServer
{
private:

	const char* m_ipAddress="127.0.0.1";	// IP Address server will run on
	int				m_port=8080;			// Port # for the web service
	int				m_socket;		// Internal FD for the listening socket
	fd_set			m_master;		// Master file descriptor set

protected:

	// Handler for client connections
	virtual void onClientConnected(int clientSocket);

	// Handler for client disconnections
	virtual void onClientDisconnected(int clientSocket);

	// Handler for when a message is received from the client
	virtual void onMessageReceived(int clientSocket, const char* msg, int length);
public:
	int init();
	WebServer(const char* ipAddress, int port) :
		m_ipAddress(ipAddress), m_port(port) { }
	void sendToClient(int clientSocket, const char* msg, int length);
	int run();

};