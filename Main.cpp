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
		cout << "Выберете пункт меню :" << endl;
		cout << "1. Добавить книгу." << endl;
		cout << "2. Удалить книгу." << endl;
		cout << "3. Вывести информацию о книге по ID" << endl;
		cout << "4. Поиск книги и выдача ее ID" << endl;
		cout << "5. Выдача книги." << endl;
		cout << "6. Возврат книги." << endl;
		cout << "7. Вывод информации о должниках." << endl;
		cout << "8. Выход." << endl;
		cout << ">";

		cin >> Variant;

		system("cls");

		switch (Variant)
		{
		case 1 :
			cout << "Введите название книги: \n";
			cin >> Title;
			cout << "\nВведите год издательства книги:\n";
			cin >> Year;
			cout << "\nВведите издательство книги:\n";
			cin >> Publisher;
			cout << "\nВведите количество страниц книги:\n";
			cin >> Pages;
			cout << "\nВведите ID книги:\n";
			cin >> ID;
			cout << "\nВведите общее количество книг:\n";
			cin >> Quantity;
			cout << "\nВведите количество свободных книг:\n";
			cin >> Instances;
			cout << "\nВведите количество авторов книги:\n";
			cin >> Number;
			cout << "\nВведите авторов книги:\n";
			for (int i = 1; i <= Number; i++) {
				cin >> Name;
				Authors.push_back(Name);
			}
			cout << endl;
			data.AddBook(Title, Authors, Year, Publisher, Pages, ID, Quantity, Instances);
			Authors.clear();
			break;
		case 2 :
			cout << "Введите название удаляемой книги." << endl;
			cin >> Title;
			cout << endl;
			data.DeleteBook(Title);
			break;
		case 3 :
			cout << "Введите ID книги: " << endl;
			cin >> ID;
			cout << endl;
			data.TakenBooksInfo(ID);
			break;
		case 4 :
			cout << "Введите название книги и автора." << endl;
			cout << "Введите название: ";
			cin >> Title;
			cout << endl << "Введите имя автора: ";
			cin >> Name;
			cout << endl;
			data.Searching(Title, Name);
			break;
		case 5 :
			cout << "Введите информацию о выдаваемой книге и клиенте." << endl;
			cout << "Введите название: ";
			cin >> Title;
			cout << endl << "Введите имя: ";
			cin >> Name;
			cout << endl << "Введите день выдачи: ";
			cin >> Day;
			cout << endl << "Введите месяц выдачи: ";
			cin >> Month;
			cout << endl << "Введите год выдачи: ";
			cin >> Year;
			cout << endl;
			data.IssuanceOfBook(Title, Name, Day, Month, Year);
			break;
		case 6 :
			cout << "Введите данные о возвращаемой книге." << endl;
			cout << "Введите название книги: ";
			cin >> Title;
			cout << endl << "Введите имя возвращающего книгу: ";
			cin >> Name;
			cout << endl;
			data.ReturnOfBook (Title, Name);
			break;
		case 7 :
			cout << "Введите сегодняшнее число." << endl;
			cout << "Введите дату: ";
			cin >> Day;
			cout << endl << "Введите месяц: ";
			cin >> Month;
			cout << endl << "Введите год: ";
			cin >> Year;
			cout << endl;
			data.DebtorsInfo(Day, Month, Year);
			break;
		}
		if (Variant != 8) { system("pause"); }
	} while (Variant != 8);
}
