#include<iostream>
#include<string>
#include<locale.h>
#include <windows.h>


bool isSymbolic(int varToCheck);

using namespace std;
class Human {
private:
	string fullName;
	int yearOfBirth;
	string passportID;
public:
    void getData() {
		cout << "������� ���: ";
		getchar();
		getline(cin, fullName, '\n');
		cout << "������� ��� ��������: ";
		cin >> yearOfBirth;
		cout << "����� ��������: "; 
		cin >> passportID;
		cin.ignore(32767, '\n');
	}
	virtual void putData() const {
		cout << "\n���: " << fullName;
		cout << "\n��� ��������: " << yearOfBirth;
		cout << "\n����� ��������: " << passportID;		
	}
	virtual void change()
	{
		cout << "������� ���: ";
		getchar();
		getline(cin, fullName, '\n');
		cout << "������� ��� ��������: ";
		cin >> yearOfBirth;
		cout << "����� ��������: ";
		cin >> passportID;
		cin.ignore(32767, '\n');
	}
};

class Enterprenuer :public Human {
private:
	int licenceNumber;
	string registrationAdress;
	int taxpayerRegistrationNumber;
	int lastPaymentValue;
public:
	void getData() {
		Human::getData();
		cout << "������� ����� ��������: ";
		cin >> licenceNumber;
		cout << "������� ����� �����������: ";
		getchar();
		getline(cin, registrationAdress, '\n');
		cout<<"������� ��������������� ����� �����������������: ";
		cin >> taxpayerRegistrationNumber;
		cout << "������� ����� ��������� ������: ";
		cin >> lastPaymentValue;
		cout << endl;
		cin.ignore(32767, '\n');
	}
	void putData() const {
		Human::putData();
		cout << "\n����� ��������: "<<licenceNumber;
		cout << "\n����� �����������: "<<registrationAdress;
		cout << "\n��������������� ����� �����������������:" << taxpayerRegistrationNumber;
		cout << "\n����� ��������� ������:" << lastPaymentValue;
		cout << endl;
	}
	void change()
	{
		Human::change();
		cout << "������� ����� ��������: ";
		cin >> licenceNumber;
		cout << "������� ����� �����������: ";
		getchar();
		getline(cin, registrationAdress, '\n');
		cout << "������� ��������������� ����� �����������������: ";
		cin >> taxpayerRegistrationNumber;
		cout << "������� ����� ��������� ������: ";
		cin >> lastPaymentValue;
		cout << endl;
		cin.ignore(32767, '\n');
	}
};

class Tourist :public Human {
private:
	string PCRTest;
	string destinationCountry;
public:
	void getData() {
		Human::getData();
		cout << "������� ��������� ��� �����: ";
		cin >> PCRTest;
		cout << "������� ������ �����������: ";
		cin >> destinationCountry;
		cout << endl;
		cin.ignore(32767, '\n');
	}
	void putData() const {
		Human::putData();
		cout << "\n��������� ��� �����: " << PCRTest;
		cout << "\n������ ����������: " << destinationCountry;
		cout << endl;
	}
};

class Solder :public Human
{
private:
	int yearsOfService;
	string rank;
public:
	void getData()
	{
		Human::getData();
		cout << "������� ���-�� ��� ������: ";
		cin >> yearsOfService;
		cout << "������� ������: ";
		cin >> rank;
		cout << endl;
		cin.ignore(32767, '\n');
	}
	void putData() const{
		Human::putData();
		cout << "\n���-�� ��� ������: " << yearsOfService;
		cout << "\n������: " << rank;
		cout << endl;
	}
};
int menu()
{
	int k;
	cout << "1 �������� ���������������" << endl;
	cout << "2 �������� �������" << endl;
	cout << "3 �������� �������" << endl;
	cout << "4 ������� ������ ����������������" << endl;
	cout << "5 ������� ������ ��������" << endl;
	cout << "6 ������� ������ ������" << endl;
	cout << "7 �������� ������ ���������������" << endl;
	cin >> k;
	return k;
}
int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	Human* humanPtr[100];
	Enterprenuer ent[10];
	Tourist tur[10];
	Solder sol[10];
	
	int i = 0,j=0;
	int a = 1, s = 0;
	int b = 2, n = 0;

	for (;;)
	{
		if (i < 100 && a < 100 && b < 100) {
			switch (menu())
			{
			case 1:
			{
				if (i < 10) {
					ent[j].getData();
					humanPtr[i] = &ent[j];
					i = i + 3;
					j++;
				}
				else cout << "not more than 10 elements" << endl;
				break;
			}
			case 2:
			{
				if (s < 10) {
					tur[s].getData();
					humanPtr[a] = &tur[s];
					a = a + 3;
					s++;
				}
				else cout << "not more than 10 elements" << endl;
				break;
			}
			case 3:
			{
				if (n < 10) {
					sol[n].getData();
					humanPtr[b] = &sol[n];
					b = b + 3;
					n++;
				}
				else cout << "not more than 10 elements" << endl;
				break;
			}
			case 4:
			{
				for (int r = 0; r < i; r = r + 3)
				{
					humanPtr[r]->putData();
					cout << endl;
				}

				break;
			}
			case 5:
			{
				for (int f = 1; f < a; f = f + 3)
				{
					humanPtr[f]->putData();
					cout << endl;
				}
				break;
			}
			case 6:
			{
				for (int m = 2; m < b; m = m + 3)
				{
					humanPtr[m]->putData();
					cout << endl;
				}
				break;
			}

			case 7:
			{
				cout << "������� ����� ������ ��������������� ";
				int q;
				cin >> q;
				if (isSymbolic(q) != true) {
					q = (q - 1) * 3;
					if (i <= q) cout << "\n����� ������ ���\n" << endl;
					else humanPtr[q]->change();
				} 
				break;
			}
			default: cout << "ERROR!!!" << endl;
				break;
			}
		}
		else { cout << "not enought memory" << endl; break; }
	}
}

bool isSymbolic(int varToCheck) // �������� �� ������
{
	bool returnVar = false;
	if (!cin) {
		cout << "\n������� ������ �����!\n" << endl;
		cin.clear(); //���������� ����� ������,
		while (cin.get() != '\n'); //���������� ��������� ������ �� ������.
		returnVar = true;
	}
	return returnVar;
}