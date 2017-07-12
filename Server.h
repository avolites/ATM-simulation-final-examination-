/////////////////////////////////////
//      ATM siumlation system      //
//    developed by Gaoxiang Liu    //
//        IDE: Dev-C++ 5.11        //
//            June 2017            //
/////////////////////////////////////
//       head file: Server.h       //
/////////////////////////////////////

#ifndef _SERVER_HEAD_FILE_

#define _SERVER_HEAD_FILE_
#ifndef __cplusplus
#error The head file Server.h is exclusive for C++.
#endif

#include <vector>
#include <iostream>
#include <conio.h>
#include "User.h"
#include "Balance.h"

using namespace std;

class Server{
	private:
		vector <User> user;					//records of users
		vector <Balance> balance;			//records of balance
											//user and balance are connected by user's id
		//local functions prototype
		int retrieveuser(int cardid);		//to return the user's location in the user vector
											//the int prototype is the user's card id
		int retrievebalance(int cardid);	//to return the user's balance location in the balance vector
											//the int prototype is the card id
		int retrieveuserid(int cardid);		//to return the user's id based on the card id
	public:
		Server();
		void changebalance(int cardid,int newbalance);	//change user's balance(increase,decrease)
														//the first int arguement is card id
														//the second int arguement is new balance
		bool checkcardid(int cardid);					//to check whether the id passed by ATM is in the "data base"
														//the int arguement is the card id
		bool checkpassword(int cardid,string password);	//to check whether the password by ATM is correct
														//the int arguement is the correct card id
														//the string arguement is the password passed by ATM
		void changepassword(int cardid,string password);//change user's password
														//the int agruement is the card id
														//the string argument is the new password
		string getusername(int cardid);					//to obtain the user's name
														//the int agruement is the card id
		string getpassword(int cardid);					//to obtain the user's password
														//the int agruement is the card id
		int getbalance(int cardid);						//to obtain the user's balance
														//the int agruement is the card id
};

#endif
