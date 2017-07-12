#include "ATM.h"

int main(int argc, char** argv) {
	ATM *p=new ATM();
	p->welcome();
	delete p;
	return 0;
}
