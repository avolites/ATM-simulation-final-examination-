/////////////////////////////////////
//      ATM siumlation system      //
//    developed by Gaoxiang Liu    //
//        IDE: Dev-C++ 5.11        //
//            June 2017            //
/////////////////////////////////////
//       head file: ATM.h          //
/////////////////////////////////////

#ifndef _ATM_HEAD_FILE_

#define _ATM_HEAD_FILE_
#ifndef __cplusplus
#error The head file ATM.h is exclusive for C++.
#endif

#include <windows.h>
#include <conio.h>
#include <iostream>
#include "Server.h"

using namespace std;

class ATM{
	private:
		Server *p=new Server();
	public:
		~ATM();
		void printui();						//print welcome screen's UI
		void welcome();						//welcome screen, including user log in.
		void UI(int cardid);				//the function menu of ATM
		void retrieve(int cardid);			//check balance
		void deposit(int cardid);
		void withdraw(int cardid);
		void changepassword(int cardid);
};

#endif
