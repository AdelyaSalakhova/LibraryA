#include "Books.h"


void ACTIONS_WITH_BOOKS :: AddBook (string Title, vector <string> Authors, unsigned int myYear, string myPublisher, unsigned int myNumberOfPages, unsigned int ID, unsigned int Quantity, unsigned int Instances) {
    CATHALOG_BOOKS NewBook(Title, Authors,  myYear, myPublisher,  myNumberOfPages, ID,  Quantity, Instances);
	Info.push_back(NewBook);
}

void ACTIONS_WITH_BOOKS::DeleteBook(string BookName) {
    int t = 0;
    for (int i = 0; i < Info.size(); i++) {
        if (Info[i].Title == BookName) {
            t = 1;
            Info.erase(Info.begin() + i);
            cout << "Книга " << BookName << " удалена." << endl;
        }
    }
    if (t == 0) { cout << "Нет запрашиваемой книги." << endl; }
}

void ACTIONS_WITH_BOOKS::TakenBooksInfo (unsigned int myID) {
    int t = 0;
    for (int i = 0; i < Info.size(); i++) {
        if (Info[i].ID == myID) {
            t = 1;
            cout << "Информация по книге с ID : " << myID << endl;
            cout << "Название : " << Info[i].Title << endl;
            cout << "Год выхода : " << Info[i].Year << endl;
            cout << "Издательство : " << Info[i].Publisher << endl;
            cout << "Количество страниц : " << Info[i].NumberOfPages << endl;
            cout << "Год выхода : " << Info[i].Year << endl;
            cout << "Авторы : " << endl;
            for (int k = 0; k < Info[i].Authors.size(); k++) {
                cout << "  " << k + 1 << ". " << Info[i].Authors[k] << endl;
            }
            cout << "Количество экземпляров : " << Info[i].Quantity << endl;
            cout << "Количество экземпляров в наличии : " << Info[i].Instances << endl;
            cout << "Информация по взявшим книгу : " << endl;
            for (int j = 0; j < Info[i].Piked.size(); j++) {
                cout << "  " << j + 1 << ". " << Info[i].Piked[j].ReadersName << "  " << Info[i].Piked[j].Day << "." << Info[i].Piked[j].Month << "." << Info[i].Piked[j].year << endl;
            }
        }
    }
    if (t == 0) { cout << "Нет запрашиваемой книги." << endl; }
}

void ACTIONS_WITH_BOOKS::Searching (string myTitle, string myAuthors) {
    bool Author = false;
    int t = 0;
    for (int i = 0; i < Info.size(); i++) {
        for (int j = 0; j < Info[i].Authors.size(); j++) {
            if (Info[i].Authors[j] == myAuthors) {
                Author = true;
            }
        }
        if ((Info[i].Title == myTitle) && Author) {
            t = 1;
            cout << "ID : " << Info[i].ID << endl;
        }
    }
    if (t == 0) { cout << "Нет запрашиваемой книги." << endl; }
}

void ACTIONS_WITH_BOOKS::IssuanceOfBook (string IssuanseTitle, string myName, unsigned int myDay, unsigned int myMonth, unsigned int myYear) {
    PikedStruct New;
    for (int i = 0; i < Info.size(); i++) {
        if (Info[i].Title == IssuanseTitle) {
            if (Info[i].Instances > 0) {
                Info[i].Instances--;
                New.ReadersName = myName;
                New.Day = myDay;
                New.Month = myMonth;
                New.year = myYear;
                Info[i].Piked.push_back(New);
            }
            else {
                cout << "Выбранной книги нет в наличии.";
            }
        }
    }
}

void ACTIONS_WITH_BOOKS::ReturnOfBook (string ReturnTitle, string myName) {
    for (int i = 0; i < Info.size(); i++) {
        if (Info[i].Title == ReturnTitle) {
            Info[i].Instances++;
            for (int m = 0; m < Info[i].Piked.size(); m++) {
                if (Info[i].Piked[m].ReadersName == myName) {
                    Info[i].Piked.erase(Info[i].Piked.begin() + m);
                }
            }
        }
        break;
    }
}

void ACTIONS_WITH_BOOKS::DebtorsInfo(unsigned int TodDay, unsigned int TodMonth, unsigned int TodYear) {
    for (int i = 0; i < Info.size(); i++) {
        cout << "Должники по книге :" << Info[i].Title << endl;
        for (int j = 0; j < Info[i].Piked.size(); j++) {
            if (TodYear - Info[i].Piked[j].year >= 2) {
                cout << j + 1 << ". " << Info[i].Piked[j].ReadersName << endl ;
            }
            else if (TodYear - Info[i].Piked[j].year == 1) {
                if (Info[i].Piked[j].Month < TodMonth) {
                    cout << j + 1 << ". " << Info[i].Piked[j].ReadersName << endl;
                }
                else if (Info[i].Piked[j].Month == TodMonth) {
                    if (Info[i].Piked[j].Day < TodDay) {
                        cout << j + 1 << ". " << Info[i].Piked[j].ReadersName << endl;
                    }
                }
            }
        }
    }
}

BOOKS::BOOKS (string myTitle, vector <string>& myAuthors, unsigned int myYear, string myPublisher, unsigned int myNumberOfPages) {
    Title = myTitle;
    Authors = myAuthors;
    Year = myYear;
    Publisher = myPublisher;
    NumberOfPages = myNumberOfPages;
}

CATHALOG_BOOKS::CATHALOG_BOOKS(string myTitle, vector <string>& myAuthors, unsigned int myYear, string myPublisher, unsigned int myNumberOfPages, unsigned int ID, unsigned int Quantity, unsigned int Instances) : BOOKS (myTitle, myAuthors, myYear, myPublisher, myNumberOfPages){
    this->ID = ID;
    this->Quantity = Quantity;
    this->Instances = Instances;
}
