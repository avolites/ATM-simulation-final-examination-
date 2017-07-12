#include "Balance.h"

Balance::Balance(){
	m_id=0;
	m_userid=0;
	m_balance=0;
}
Balance::Balance(int id,int userid,int balance){
	m_id=id;
	m_userid=userid;
	m_balance=balance;
}
void Balance::setId(int id){
	m_id=id;
}
void Balance::setUserid(int userid){
	m_userid=userid;
}
void Balance::setBalance(int balance){
	m_balance=balance;
}
int Balance::getId(){
	return this->m_id;
}
int Balance::getUserid(){
	return this->m_userid;
}
int Balance::getBalance(){
	return this->m_balance;
}
