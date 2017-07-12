/////////////////////////////////////
//      ATM siumlation system      //
//    developed by Gaoxiang Liu    //
//        IDE: Dev-C++ 5.11        //
//            June 2017            //
/////////////////////////////////////
//       head file: Balance.h      //
/////////////////////////////////////

#ifndef _BALANCE_HEAD_FILE_

#define _BALANCE_HEAD_FILE_
#ifndef __cplusplus
#error The head file Balance.h is exclusive for C++.
#endif

class Balance{
	private:
		int m_id;						//primary key
		int m_userid;					//user's id(it matches the id in user class)
		int m_balance;					//user's balance
	public:
		Balance();
		Balance(int id,int userid,int balance);
		//set data function prototype
		void setId(int id);
		void setUserid(int userid);
		void setBalance(int balance);
		//get data function prototype
		int getId();
		int getUserid();
		int getBalance();
};

#endif
