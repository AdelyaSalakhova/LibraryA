#include "Books.h"

int main() {
	setlocale(LC_ALL, "ru");
	ACTIONS_WITH_BOOKS data;
	int Variant;
	unsigned int Day, Month, Year, ID, Pages, Quantity, Instances, Number;
	string Title, Name, Publisher;
	vector <string> Authors;
	do {
		system("cls");
		cout << "Âûáåðåòå ïóíêò ìåíþ :" << endl;
		cout << "1. Äîáàâèòü êíèãó." << endl;
		cout << "2. Óäàëèòü êíèãó." << endl;
		cout << "3. Âûâåñòè èíôîðìàöèþ î êíèãå ïî ID" << endl;
		cout << "4. Ïîèñê êíèãè è âûäà÷à åå ID" << endl;
		cout << "5. Âûäà÷à êíèãè." << endl;
		cout << "6. Âîçâðàò êíèãè." << endl;
		cout << "7. Âûâîä èíôîðìàöèè î äîëæíèêàõ." << endl;
		cout << "8. Âûõîä." << endl;
		cout << ">";

		cin >> Variant;

		system("cls");

		switch (Variant)
		{
		case 1 :
			cout << "Ââåäèòå íàçâàíèå êíèãè: \n";
			cin >> Title;
			cout << "\nÂâåäèòå ãîä èçäàòåëüñòâà êíèãè:\n";
			cin >> Year;
			cout << "\nÂâåäèòå èçäàòåëüñòâî êíèãè:\n";
			cin >> Publisher;
			cout << "\nÂâåäèòå êîëè÷åñòâî ñòðàíèö êíèãè:\n";
			cin >> Pages;
			cout << "\nÂâåäèòå ID êíèãè:\n";
			cin >> ID;
			cout << "\nÂâåäèòå îáùåå êîëè÷åñòâî êíèã:\n";
			cin >> Quantity;
			cout << "\nÂâåäèòå êîëè÷åñòâî ñâîáîäíûõ êíèã:\n";
			cin >> Instances;
			cout << "\nÂâåäèòå êîëè÷åñòâî àâòîðîâ êíèãè:\n";
			cin >> Number;
			cout << "\nÂâåäèòå àâòîðîâ êíèãè:\n";
			for (int i = 1; i <= Number; i++) {
				cin >> Name;
				Authors.push_back(Name);
			}
			cout << endl;
			data.AddBook(Title, Authors, Year, Publisher, Pages, ID, Quantity, Instances);
			Authors.clear();
			break;
		case 2 :
			cout << "Ââåäèòå íàçâàíèå óäàëÿåìîé êíèãè." << endl;
			cin >> Title;
			cout << endl;
			data.DeleteBook(Title);
			break;
		case 3 :
			cout << "Ââåäèòå ID êíèãè: " << endl;
			cin >> ID;
			cout << endl;
			data.TakenBooksInfo(ID);
			break;
		case 4 :
			cout << "Ââåäèòå íàçâàíèå êíèãè è àâòîðà." << endl;
			cout << "Ââåäèòå íàçâàíèå: ";
			cin >> Title;
			cout << endl << "Ââåäèòå èìÿ àâòîðà: ";
			cin >> Name;
			cout << endl;
			data.Searching(Title, Name);
			break;
		case 5 :
			cout << "Ââåäèòå èíôîðìàöèþ î âûäàâàåìîé êíèãå è êëèåíòå." << endl;
			cout << "Ââåäèòå íàçâàíèå: ";
			cin >> Title;
			cout << endl << "Ââåäèòå èìÿ: ";
			cin >> Name;
			cout << endl << "Ââåäèòå äåíü âûäà÷è: ";
			cin >> Day;
			cout << endl << "Ââåäèòå ìåñÿö âûäà÷è: ";
			cin >> Month;
			cout << endl << "Ââåäèòå ãîä âûäà÷è: ";
			cin >> Year;
			cout << endl;
			data.IssuanceOfBook(Title, Name, Day, Month, Year);
			break;
		case 6 :
			cout << "Ââåäèòå äàííûå î âîçâðàùàåìîé êíèãå." << endl;
			cout << "Ââåäèòå íàçâàíèå êíèãè: ";
			cin >> Title;
			cout << endl << "Ââåäèòå èìÿ âîçâðàùàþùåãî êíèãó: ";
			cin >> Name;
			cout << endl;
			data.ReturnOfBook (Title, Name);
			break;
		case 7 :
			cout << "Ââåäèòå ñåãîäíÿøíåå ÷èñëî." << endl;
			cout << "Ââåäèòå äàòó: ";
			cin >> Day;
			cout << endl << "Ââåäèòå ìåñÿö: ";
			cin >> Month;
			cout << endl << "Ââåäèòå ãîä: ";
			cin >> Year;
			cout << endl;
			data.DebtorsInfo(Day, Month, Year);
			break;
		}
		if (Variant != 8) { system("pause"); }
	} while (Variant != 8);
}
