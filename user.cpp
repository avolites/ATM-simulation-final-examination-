#include "User.h"

User::User(){
	m_id=0;
	m_name="";
	m_password="";
}
User::User(int id,int card_id,string name,string password){
	m_id=id;
	card.setId(card_id);
	m_name=name;
	m_password=password;
}
void User::setId(int id){
	m_id=id;
}
void User::setName(string name){
	m_name=name;
}
void User::setPassword(string password){
	m_password=password;
}
void User::setCardid(int id){
	card.setId(id);
}
int User::getId(){
	return m_id;
}
string User::getName(){
	return m_name;
}
string User::getPassword(){
	return m_password;
}
int User::getCardid(){
	return card.getId();
}
