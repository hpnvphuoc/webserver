#include "WebServer.h"
#include<iostream>
using namespace std;

void main()
{
	WebServer webServer("127.0.0.1",8080);
	if (webServer.init() != 0){
		cout << "Co loi xay ra khi khoi server";
		return;
	}

	webServer.run();

	system("pause");
}