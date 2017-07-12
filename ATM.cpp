#include "ATM.h"

ATM::~ATM(){
	delete p;			//to relase the dynamic objcet p(class Server)
}
void ATM::printui(){
	while(1){			//for exit function(when ESC was pressed)
		system("cls");
		system("color 0a");
		cout<<"\t\t******************************************"<<endl;
		cout<<"\t\t*    Welcome to ATM siumlation system    *"<<endl;
		cout<<"\t\t******************************************"<<endl;
		cout<<"\t\t*                  NOTICE                *"<<endl;
		cout<<"\t\t*     This system is only a simulation,  *"<<endl;
		cout<<"\t\t*it can't' be used for practical purpose.*"<<endl;
		cout<<"\t\t*         Developed by Gaoxiang Liu      *"<<endl;
		cout<<"\t\t*                June  2017              *"<<endl;
		cout<<"\t\t******************************************"<<endl;
		cout<<"\t\t*       PRESS ANY KEY TO COUNTINUE       *"<<endl;
		cout<<"\t\t******************************************"<<endl;
		cout<<"\t\t*           PRESS ESC TO EXIT            *"<<endl;
		cout<<"\t\t******************************************"<<endl;
		char temp;
		if((temp=_getch())==27){					//if user presses ESC button
			system("cls");
			cout<<"\t=======Exit======"<<endl;
			cout<<"If you do, all the data will be cleaned."<<endl;
			cout<<"Are you sure that you want to exit?[y/n]"<<endl;
			char temp1;
			temp1=_getch();
			if(temp1=='y'||temp1=='Y')
				exit(1);
		}
		if(temp!=27)								//if user press other keys, coutinue
			break;
	}												//loop
}
void ATM::welcome(){
	printui();
	system("cls");
	cout<<"Please input your card number and press Enter."<<endl;
	int temp_cardid;
	cin>>temp_cardid;									//The input inspection hasn't been
														//used there, for if the input is
														//invalid, the system will exit
														//automatically.
	if(p->checkcardid(temp_cardid)){					//the card id is matched
		cout<<"Please input your password and press Enter."<<endl;
		cout<<"For security, it will display nothing."<<endl;
		int count=3;									//there are 3 chances to input password
		string temp_password(6,' ');					//the password is within 6 characters
		while(count>0){
			int i=0;									//current password character location
			char temp;									//temporary password character
			while((temp=_getch())!=13){					//to hide the password inputed by user
				if(i<6){
					if(temp==8&&i>0)					//if user presses Backspace
						i--;
					else{
						temp_password[i]=temp;
						i++;
					}
				}
			}
			while(i<6){									//if the password contains less than
				temp_password[i]=' ';					//6 characters, fill the rest character
				i++;
			}
			if(p->checkpassword(temp_cardid,temp_password)){
				UI(temp_cardid);
				break;
			}
			else
			{
				cerr<<"You are inputed a wrong password,please try again."<<endl;
				count--;
			}
		}
		if(count==0){
			cerr<<"There is no chance for you to input password, system will exit automatically."<<endl;
			_getch();
			exit(0);
		}
	}
	else
	{
		cerr<<"This card number has not been registed."<<endl;
		cout<<"Press any key to exit.";
		_getch();
		exit(0);
	}
}
void ATM::UI(int cardid){
	system("cls");
	system("color 0e");
	cout<<"\t\tWelcome "<<p->getusername(cardid)<<endl<<endl;
	cout<<"\t\t*************************"<<endl;
	cout<<"\t\t*        Main Menu      *"<<endl;
	cout<<"\t\t*************************"<<endl;
	cout<<"\t\t*   [1] Check Balance   *"<<endl;
	cout<<"\t\t*   [2] Withdrew        *"<<endl;
	cout<<"\t\t*   [3] Deposit         *"<<endl;
	cout<<"\t\t*   [4] Change Password *"<<endl;
	cout<<"\t\t*   [5] Exit            *"<<endl;
	cout<<"\t\t*************************"<<endl;
	cout<<"\t\t* Please make a choice. *"<<endl;
	cout<<"\t\t*************************"<<endl;
	char choice;
	bool judge=false;				//to decide whether user's input is right
	while(1){
		choice=_getch();
		switch(choice){
			case '1':
				judge=true;
				retrieve(cardid);
				break;
			case '2':
				judge=true;
				withdraw(cardid);
				break;
			case '3':
				judge=true;
				deposit(cardid);
				break;
			case '4':
				judge=true;
				changepassword(cardid);
				break;
			case '5':
				judge=true;
				welcome();
				break;
			default:
				judge=false;
		}
		if(judge){				//if the input is correct, coutinue
			break;
		}
	}
}
void ATM::retrieve(int cardid){
	system("cls");
	system("color 0b");
	cout<<"Your balance:"<<p->getbalance(cardid)<<endl;
	cout<<"Press any key to back to the previous menu."<<endl;
	_getch();
	UI(cardid);
}
void ATM::deposit(int cardid){
	system("cls");
	system("color 0b");
	cout<<"\t\t======Deposit======"<<endl;
	cout<<"Please input the amount of money you want to deposit."<<endl;
	cout<<"The value you input must be a multiple of 100."<<endl;
	cout<<"If you want to give up, type 0."<<endl;
	int temp;
	while(1){
		while(!(cin>>temp)){				//if the input is invalid
			cin.clear();					//reset the status
			cin.ignore();					//ignore the current character
		}
		if(temp<0){
			cout<<"Please try again, you must input a positive integer."<<endl;
		}
		else if(temp%100!=0){
			cout<<"Please try again, the value must be a multiple of 100!"<<endl;
		}
		else
			break;
	}
	p->changebalance(cardid,p->getbalance(cardid)+temp);
	system("cls");
	cout<<"Done!"<<endl<<endl;
	cout<<"You have just deposit "<<temp<<"."<<endl;
	cout<<"Now, your balance is "<<p->getbalance(cardid)<<endl<<endl;
	cout<<"Press any key to return."<<endl;
	_getch();
	UI(cardid);
}
void ATM::withdraw(int cardid){
	system("cls");
	system("color 0b");
	cout<<"\t\t======Withdraw======"<<endl;
	cout<<"Please input the amount of money you want to withdraw."<<endl;
	cout<<"The value you input must be a multiple of 100."<<endl;
	cout<<"If you want to give up, type 0."<<endl;
	int temp;
	int balance=p->getbalance(cardid);		//current balance
	while(1){
		while(!(cin>>temp)){		//if the input is invalid
			cin.clear();					//reset the status
			cin.ignore();					//ignore the current character
		}
		if(temp>balance){
			cout<<"You do not have enough money, please try again."<<endl;
		}
		else if(temp>5000){
			cout<<"You cannot withdraw more than 5000 once."<<endl;
		}
		else if(temp<0){
			cout<<"The value cannot be nagative."<<endl;
		}
		else{
			if(temp%100==0){
				break;
			}
			else{
				cout<<"Please try again."<<endl;
			}
		}
	}
	p->changebalance(cardid,p->getbalance(cardid)-temp);
	system("cls");
	cout<<"Done!"<<endl<<endl;
	cout<<"You have just withdraw "<<temp<<"."<<endl;
	cout<<"Now, your balance is "<<p->getbalance(cardid)<<endl<<endl;
	cout<<"Press any key to return."<<endl;
	_getch();
	UI(cardid);
}
void ATM::changepassword(int cardid){
	system("cls");
	system("color 0b");
	cout<<"Are you sure that you want to change your password?[y/n]"<<endl;
	char choice=_getch();
	if(choice=='y'||choice=='Y'){
		system("cls");
		cout<<"Please input your previous password:"<<endl;
		string temp_password(6,' ');				//the password is within 6 characters
		int i=0;									//current password character location
		char temp;									//temporary password character
		while((temp=_getch())!=13){					//to hide the password inputed by user
			if(i<6){
				if(temp==8&&i>0)					//if user presses Backspace
					i--;
				else{
					temp_password[i]=temp;
					i++;
				}
			}
		}
		while(i<6){											//if the password contains less than
			temp_password[i]=' ';							//6 characters, fill the rest character
			i++;
		}
		if(p->checkpassword(cardid,temp_password)){			//success
			cout<<"Please input your new password:"<<endl;
			i=0;											//reset current location to 0
			while((temp=_getch())!=13){						//to hide the password inputed by user
				if(i<6){
					if(temp==8&&i>0)						//if user presses Backspace
						i--;
					else{
						temp_password[i]=temp;
						i++;
					}
				}
			}
			while(i<6){										//if the password contains less than
				temp_password[i]=' ';						//6 characters, fill the rest character
				i++;
			}
			cout<<"Please input again:"<<endl;
			i=0;
			string temp_password_1(6,' ');
			while((temp=_getch())!=13){						//to hide the password inputed by user
				if(i<6){
					if(temp==8&&i>0)						//if user presses Backspace
						i--;
					else{
						temp_password_1[i]=temp;
						i++;
					}
				}
			}
			while(i<6){										//if the password contains less than
				temp_password_1[i]=' ';						//6 characters, fill the rest character
				i++;
			}
			if(temp_password==temp_password_1){
				p->changepassword(cardid,temp_password);
				cout<<"Done!"<<endl;
			}
			else{
				cout<<"Failed!"<<endl;
				cout<<"Error: The two passowrds you input is different."<<endl;
			}
		}
		else{
			cout<<"You have inputed a wrong password."<<endl;
		}
		cout<<"Press any key to return."<<endl;
		_getch();
	}
	UI(cardid);
}
