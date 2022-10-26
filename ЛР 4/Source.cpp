//�������� ��������� ����� ������� ��������� ������������
//������� � ���������.����������� ����������� ������� ����� � �����
//�������� ������� ���������� ���� � ����������� � ������������
//���������.������ ������ ��������� ��������� ���� : ��� �������������
//��������, ���������� ���� ��� ���������� � ������ � ��������.�� �������
//�������� ����������� ���������� � ������������ ���������.
//������������ ����������� � �����������, ����������� ��� ����������,
//����������� �����������.� ����� �������� ����������� ����� ����� �
//�������(������� ��� ���� � ��� ������) �� ���� ����������.
//������������� ����� ��� ������ ���������� ������ � ����.

#define _USE_MATH_DEFINES
#include<iostream>
#include<string>
#include<locale.h>
#include <windows.h>
#include<fstream>

using namespace std;

bool isSymbolic(int varToCheck);

class foreWeels;
class twoWeels;

class vehicle
{
public:
	virtual void print()=0;
	virtual void file_write()=0;
};

class autoParkVehicle :public vehicle
{
protected:
     string type;
	int amountOfSits;
	string driverLicence;
	int engineVolume;
public:
	autoParkVehicle()
	{
		type = "no information";
		amountOfSits = NULL;
		driverLicence = "no information";
	}
	autoParkVehicle(string type, int amountOfSits, string driverLicence, int engineVolume) 
	{
		this->type = type;
		this->amountOfSits = amountOfSits;
		this->driverLicence = driverLicence;
		this->engineVolume = engineVolume;
	}
	void print()
	{		
		cout << "���: " << type << endl;
		cout << "���-�� �������: "<<amountOfSits << endl;
		cout << "��������� ����: " << driverLicence << endl;
		cout << "����� ���������: " << engineVolume << endl;
	}

	void file_write()
	{
		ofstream file;
		file.open("test.txt", ios::app);
		if (file.is_open())
		{
			file << type << endl << amountOfSits << endl << driverLicence << endl << engineVolume << endl;
		}
		file.close();
	}
};

class twoWeels : public autoParkVehicle
{
protected:
	 string weelsAmount;
public:
	void print() 
	{
		autoParkVehicle::print();
		cout << weelsAmount << endl;
	}
	twoWeels(string type, int amountOfSits, string driverLicence, int engineVolume) :autoParkVehicle(type, amountOfSits, driverLicence, engineVolume){
		this->weelsAmount = "������������ ��";
	}
	void compareAmountOfSits(foreWeels& other);
	void compareEngineVolume(foreWeels& other);

	void file_write()
	{
		autoParkVehicle::file_write();
		ofstream file;
		file.open("test.txt", ios::app);
		if (file.is_open())
		{
			file << weelsAmount << endl;
		}
		file.close();
	}
};

class foreWeels : public autoParkVehicle
{
protected:
	string weelsAmount;
public:
	void print() { 
		autoParkVehicle::print();
		cout << weelsAmount << endl;
	}
	foreWeels(string type, int amountOfSits, string driverLicence,int engineVolume) :autoParkVehicle(type, amountOfSits, driverLicence,engineVolume) {
		this->weelsAmount = "��������������� ��";
	}
	friend void twoWeels::compareAmountOfSits( foreWeels& other);
	friend void twoWeels:: compareEngineVolume(foreWeels&other);

	void file_write()
	{
		autoParkVehicle::file_write();
		ofstream file;
		file.open("test.txt", ios::app);
		if (file.is_open())
		{
			file << weelsAmount << endl;
		}
		file.close();
	}
};

int main()
{
	SetConsoleCP(1251);
	setlocale(LC_ALL, "rus");
	string type;
	int amountOfSits, engineVolume;
	string driverLicence;

	vehicle* mashine[2];

	cout << "������� ��� ���������������� ��: "<<endl;
	cin >> type;
	for (;;) {
		cout << "�������  ���-�� �������: " << endl;
		cin >> amountOfSits;
		if (isSymbolic(amountOfSits) == false) break;}
	cout << "�������  ��������� ����: " << endl;
	cin >> driverLicence;
	for (;;) {
		cout << "������� ����� ���������: " << endl;
		cin >> engineVolume;
		if (isSymbolic(amountOfSits) == false) break;
	}
	twoWeels moto(type, amountOfSits, driverLicence, engineVolume);

	cout << "������� ��� ������������� ��: " << endl;
	cin >> type;
	for (;;) {
		cout << "�������  ���-�� �������: " << endl;
		cin >> amountOfSits;
		if (isSymbolic(amountOfSits) == false) break;
	}
	cout << "�������  ��������� ����: " << endl;
	cin >> driverLicence;
	for (;;) {
		cout << "������� ����� ���������: " << endl;
		cin >> engineVolume;
		if (isSymbolic(amountOfSits) == false) break;
	}
	foreWeels cars(type, amountOfSits, driverLicence, engineVolume);

	mashine[0] = &moto;
	mashine[1]=&cars;

	for (int i = 0; i < 2; i++)
	{
		mashine[i]->print();
		cout << endl;
	}
	
	moto.compareAmountOfSits(cars);
	moto.compareEngineVolume(cars);
	for (int i = 0; i < 2; i++)
	{
		mashine[i]->file_write();
	}
}

void twoWeels::compareAmountOfSits(foreWeels& other)
{
	if (this->amountOfSits == other.amountOfSits) cout << "���-�� ������� �����" << endl;
	else if (this->amountOfSits > other.amountOfSits) cout << "���-�� ������� ������� " << this->type << " ������" << endl;
	else cout << "���-�� ������� ������� " << other.type << " ������" << endl;
}

void twoWeels::compareEngineVolume(foreWeels& other)
{
	if (this->engineVolume == other.engineVolume) cout << "������ ���������� �����" << endl;
	else if (this->engineVolume > other.engineVolume) cout << "����� ��������� ������� " << this->type << " ������" << endl;
	else cout << "����� ��������� ������� " << other.type << " ������" << endl;
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

