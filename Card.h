/////////////////////////////////////
//      ATM siumlation system      //
//    developed by Gaoxiang Liu    //
//        IDE: Dev-C++ 5.11        //
//            June 2017            //
/////////////////////////////////////
//     head file: card.h           //
/////////////////////////////////////

#ifndef _CARD_HEAD_FILE_

#define _CARD_HEAD_FILE_
#ifndef __cplusplus
#error The head file Card.h is exclusive for C++.
#endif

class Card{
	private:
		int m_id;							//card number of user
	public:
		int getId();						//obtain the card number
		void setId(int id);					//set the card number
};

#endif
