#ifndef BOOKS_T
#define BOOKS_T
#include <vector>
#include <iostream>
#include <string>

using namespace std;

struct PikedStruct {
	string ReadersName;
	unsigned int Day; 
	unsigned int Month;
	unsigned int year;
};

class BOOKS {
public :
	string Title;
	vector <string> Authors;
	unsigned int Year;
	string Publisher;
	unsigned int NumberOfPages;
public :
	BOOKS(string myTitle, vector <string> & myAuthors , unsigned int myYear, string myPublisher, unsigned int myNumberOfPages);
};

class CATHALOG_BOOKS : public BOOKS {
public:
	unsigned int ID;
	unsigned int Quantity;
	unsigned int Instances;
	vector <PikedStruct> Piked;
public:
	CATHALOG_BOOKS(string myTitle, vector <string>& myAuthors, unsigned int myYear, string myPublisher, unsigned int myNumberOfPages, unsigned int ID, unsigned int Quantity, unsigned int Instances);
};

class ACTIONS_WITH_BOOKS {
private:
	vector <CATHALOG_BOOKS> Info;
	vector <string> Debtors;
public:
	void AddBook(string Title, vector <string> Authors, unsigned int myYear, string myPublisher, unsigned int myNumberOfPages, unsigned int ID, unsigned int Quantity, unsigned int Instances);
	void DeleteBook(string BookName);
	void TakenBooksInfo(unsigned int myID);
	void Searching(string myTitle, string Authors);
	void IssuanceOfBook(string IssuanseTitle, string myName, unsigned int myDay, unsigned int myMonth, unsigned int myYear); 
	void ReturnOfBook(string ReturnTitle, string myName);
	void DebtorsInfo(unsigned int TodDay, unsigned int TodMonth, unsigned int TodYear);
};

#endif
