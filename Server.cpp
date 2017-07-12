#include "Server.h"

Server::Server(){
	//initializing two users for experiment
	User *temp=new User(1001,123456,"Zhang San","123456");
	user.push_back(*temp);
	temp->setId(1002);
	temp->setName("Li Si");
	temp->setCardid(654321);
	user.push_back(*temp);
	delete temp;
	Balance *p=new Balance(1,1001,5000);
	balance.push_back(*p);
	p->setId(p->getId()+1);
	p->setUserid(1002);
	balance.push_back(*p);
	delete p;
}
int Server::retrieveuser(int cardid){
	/*
	int count=0;
	for(auto i:user){
		if(i.getCardid()==cardid){
			return count;
		}
		count++;
	}
	*/
	int count=0;
	int i=0;
	for(;i<user.size();i++){
		if(user.at(i).getCardid()==cardid){
			break;
		}
	}
	return i;
}
int Server::retrieveuserid(int cardid){
	/*
	for(auto i:user){
		if(i.getCardid()==cardid){
			return i.getId();
		}
	}
	*/
	int count=0;
	int i=0;
	for(;i<user.size();i++){
		if(user.at(i).getCardid()==cardid){
			return user.at(i).getId();
		}
	}
}
int Server::retrievebalance(int cardid){
	/*
	int count=0;
	for(auto i:balance){
		if(i.getUserid()==id){
			return count;
		}
		count++;
	}
	*/
	int count=0;
	int i=0;
	for(;i<balance.size();i++){
		if(balance.at(i).getUserid()==cardid){
			break;
		}
	}
	return i;
}
void Server::changebalance(int cardid,int newbalance){
	int id=retrieveuserid(cardid);
	int temp=retrievebalance(id);
	balance.at(temp).setBalance(newbalance);
}
bool Server::checkcardid(int cardid){
	/*
	for(auto i:user){
		if(cardid==i.getCardid()){
			return true;
		}
	}
	return false;
	*/
	for(int i=0;i<user.size();i++){
		if(cardid==user.at(i).getCardid()){
			return true;
		}
	}
	return false;
}
bool Server::checkpassword(int cardid,string password){
	int temp=retrieveuser(cardid);
	if(user.at(temp).getPassword()==password){
		return true;
	}
	return false;
}
void Server::changepassword(int cardid,string password){
	int temp=retrieveuser(cardid);
	user.at(temp).setPassword(password);
}
string Server::getusername(int cardid){
	int temp=retrieveuser(cardid);
	return user.at(temp).getName();
}
string Server::getpassword(int cardid){
	int temp=retrieveuser(cardid);
	return user.at(temp).getPassword();
}
int Server::getbalance(int cardid){
	int temp=retrievebalance(retrieveuserid(cardid));
	return balance.at(temp).getBalance();
}
