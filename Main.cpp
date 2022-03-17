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
		cout << "�������� ����� ���� :" << endl;
		cout << "1. �������� �����." << endl;
		cout << "2. ������� �����." << endl;
		cout << "3. ������� ���������� � ����� �� ID" << endl;
		cout << "4. ����� ����� � ������ �� ID" << endl;
		cout << "5. ������ �����." << endl;
		cout << "6. ������� �����." << endl;
		cout << "7. ����� ���������� � ���������." << endl;
		cout << "8. �����." << endl;
		cout << ">";

		cin >> Variant;

		system("cls");

		switch (Variant)
		{
		case 1 :
			cout << "������� �������� �����: \n";
			cin >> Title;
			cout << "\n������� ��� ������������ �����:\n";
			cin >> Year;
			cout << "\n������� ������������ �����:\n";
			cin >> Publisher;
			cout << "\n������� ���������� ������� �����:\n";
			cin >> Pages;
			cout << "\n������� ID �����:\n";
			cin >> ID;
			cout << "\n������� ����� ���������� ����:\n";
			cin >> Quantity;
			cout << "\n������� ���������� ��������� ����:\n";
			cin >> Instances;
			cout << "\n������� ���������� ������� �����:\n";
			cin >> Number;
			cout << "\n������� ������� �����:\n";
			for (int i = 1; i <= Number; i++) {
				cin >> Name;
				Authors.push_back(Name);
			}
			cout << endl;
			data.AddBook(Title, Authors, Year, Publisher, Pages, ID, Quantity, Instances);
			break;
		case 2 :
			cout << "������� �������� ��������� �����." << endl;
			cin >> Title;
			cout << endl;
			data.DeleteBook(Title);
			break;
		case 3 :
			cout << "������� ID �����: " << endl;
			cin >> ID;
			cout << endl;
			data.TakenBooksInfo(ID);
			break;
		case 4 :
			cout << "������� �������� ����� � ������." << endl;
			cout << "������� ��������: ";
			cin >> Title;
			cout << endl << "������� ��� ������: ";
			cin >> Name;
			cout << endl;
			data.Searching(Title, Name);
			break;
		case 5 :
			cout << "������� ���������� � ���������� ����� � �������." << endl;
			cout << "������� ��������: ";
			cin >> Title;
			cout << endl << "������� ���: ";
			cin >> Name;
			cout << endl << "������� ���� ������: ";
			cin >> Day;
			cout << endl << "������� ����� ������: ";
			cin >> Month;
			cout << endl << "������� ��� ������: ";
			cin >> Year;
			cout << endl;
			data.IssuanceOfBook(Title, Name, Day, Month, Year);
			break;
		case 6 :
			cout << "������� ������ � ������������ �����." << endl;
			cout << "������� �������� �����: ";
			cin >> Title;
			cout << endl << "������� ��� ������������� �����: ";
			cin >> Name;
			cout << endl;
			data.ReturnOfBook (Title, Name);
			break;
		case 7 :
			cout << "������� ����������� �����." << endl;
			cout << "������� ����: ";
			cin >> Day;
			cout << endl << "������� �����: ";
			cin >> Month;
			cout << endl << "������� ���: ";
			cin >> Year;
			cout << endl;
			data.DebtorsInfo(Day, Month, Year);
			break;
		}
		if (Variant != 8) { system("pause"); }
	} while (Variant != 8);
}