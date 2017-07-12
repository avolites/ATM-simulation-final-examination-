/////////////////////////////////////
//      ATM siumlation system      //
//    developed by Gaoxiang Liu    //
//        IDE: Dev-C++ 5.11        //
//            June 2017            //
/////////////////////////////////////
//       head file: User.h         //
/////////////////////////////////////

#ifndef _USER_HEAD_FILE_

#define _USER_HEAD_FILE_
#define _SERVER_HEAD_FILE_
#ifndef __cplusplus
#error The head file User.h is exclusive for C++.
#endif

#include <string>
#include "Card.h"

using namespace std;

class User{
	private:
		int m_id;					//user's id(primary key)
		string m_name;
		string m_password;
		Card card;					//user's card number
	public:
		User();
		User(int id,int card_id,string name,string password);
		//set data function prototype
		void setId(int id);
		void setName(string name);
		void setPassword(string password);
		void setCardid(int id);
		//get data function prototype
		int getId();
		string getName();
		string getPassword();
		int getCardid();
};

#endif
