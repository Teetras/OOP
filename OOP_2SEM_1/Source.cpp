#include<iostream>
#include<Windows.h>
#include<string>
#include<locale.h>

using namespace std;
bool isSymbolic(int varToCheck);

class Engine {
public:
	string fuelType;
	float volume;
	Engine(
		float volume,
		string fuelType
	) {
		this->fuelType = fuelType;
		this->volume = volume;
	}
	Engine() {
		fuelType = "gasoline",
			volume = 2;
	}
	Engine(const Engine &obj) {
		this->fuelType = obj.fuelType;
		this->volume = obj.volume;
	}
};

class Color {
public:
	Color(string color) {
		this->color = color;
	}
	Color() {
		color = "black";
	}
	Color(const Color &color) {
		this->color = color.color;
	}
	string color;
};

class BodyWork {
public:
	string bodyWorkType;
	int weight;
	BodyWork(
		string	bodyWorkType,
		int weight
	) {
		this->bodyWorkType = bodyWorkType;
		this->weight = weight;
	}
	BodyWork() {
		bodyWorkType = "sedan";
		weight = 1500;
	}
	BodyWork(const BodyWork& bodyWork) {
		this->bodyWorkType = bodyWork.bodyWorkType;
		this->weight = bodyWork.weight;
	}
};

class Automobile {
private:
	bool isCarBroken;
	int helthPoints;
    Engine engine;
	Color color;
	BodyWork bodyWork;

	protected:
	int distance;
	int fuelConsumption;

public:
	Automobile():engine(1, "gasoline"), color("black"), bodyWork("sedan", 1000) {
		isCarBroken = false;
		distance = 0;
		fuelConsumption = 0;
		helthPoints = 3;
	}
	Automobile(
		float volume,
		string fuelType,
		string color,
		string boduWorkType,
		int weight
		): engine(volume, fuelType), color(color), bodyWork(boduWorkType, weight) {
		isCarBroken = false;
		distance = 0;
		fuelConsumption = 0;
		helthPoints = 3;
	}

	virtual void drive() {
		checkHelthPoits();
		if (!IsCarBroken()) {
			cout << endl << "����..." << endl << endl;
			this->distance += 100;
			this->fuelConsumption += calculateFuelConsumption();
			this->helthPoints--;
		}
	}

	void crashVehicle()  {
		isCarBroken = true;
		cout << "�� �������" << endl << endl;
	}

	void repairVehicle()  {
		this->helthPoints = 3;
		this->isCarBroken = false;
		cout << "�� ��������" << endl << endl;
	}

	 int calculateFuelConsumption() {
		return this->engine.volume * 0.005 * this->bodyWork.weight;
	}
 
	  void showStats()  {
		cout << "��������� � ��: " << distance<<endl;
		cout << "������ ������� � �: " << fuelConsumption << endl;
		cout << "������� �� ������: ";
		if (isCarBroken)
			cout << "��" << endl;
		else
			cout << "���" << endl;
		cout <<"��� ��������: " << this->engine.fuelType << endl;
		cout <<"����� ��������� � �: " << this->engine.volume << endl;
		cout <<"����: " << this->color.color << endl;
		cout <<"��� ������: " << this->bodyWork.bodyWorkType << endl;
		cout <<"��� � ��: " << this->bodyWork.weight << endl<<endl;
	}

    bool IsCarBroken(){
		if (isCarBroken)
		{
			cout << "�� �� ������ ����� �� ������� �������" << endl;
		}
		return 	isCarBroken;
	}

	void checkHelthPoits() {
		if (helthPoints == 0) {
			isCarBroken = true;
			cout <<endl<< "����� ������ ������ � �������" << endl;
		}
	}
};

class MilitaryAuto: public virtual Automobile {
  int widthOfArmor;
public:
	MilitaryAuto() {
		widthOfArmor = 0;
	}
	MilitaryAuto(
		float volume,
		string fuelType,
		string color,
		string boduWorkType,
		int weight,
		int widthOfArmor
	) {
		this->widthOfArmor = widthOfArmor;
	}
	void drive() override {
		Automobile::drive();
	}
	void crashVehicle()  {
		Automobile::crashVehicle();
   }
	void repairVehicle()  {
		Automobile::repairVehicle();
	}
	void showStats()  {
		cout << endl << "������� ����� � ��: " << widthOfArmor<<endl;
	}
};

class CivilianAuto:public virtual Automobile {
	bool isClimateControlExist;

public:
	CivilianAuto() {
		isClimateControlExist = true;
	}
	CivilianAuto(
		float volume,
		string fuelType,
		string color,
		string boduWorkType,
		int weight,
	    bool isClimateControlExist
	){
		this->isClimateControlExist = isClimateControlExist;
	}
	void drive() override {
		Automobile::drive();
	}
	void showStats()  {
		if (isClimateControlExist)
			cout << endl << "������� ������ ��������: ��";
		else
			cout << endl << "������� ������ ��������: ���";
	}
};

class CivilinaAutoWithArmor: public CivilianAuto, public MilitaryAuto  {
public:

	CivilinaAutoWithArmor() : CivilianAuto(), MilitaryAuto(){}

	CivilinaAutoWithArmor(
		float volume,
		string fuelType,
		string color,
		string boduWorkType,
		int weight,
		bool isClimateControlExist,
		int widthOfArmor
	) :
		CivilianAuto(volume, fuelType, color, boduWorkType, weight, isClimateControlExist),
		MilitaryAuto(volume, fuelType, color, boduWorkType, weight, widthOfArmor),
		Automobile(volume,fuelType,color,boduWorkType,weight)
	{}

	void drive() override{
		CivilianAuto::drive();
	}

	void showStats()  {
		CivilianAuto::showStats();
		MilitaryAuto::showStats();
		Automobile::showStats();
	}

};

template<class T>
class Vehicle {
private:
	T* ptr;
public:
	Vehicle(T* ptr) {
		this->ptr = ptr;
	}
	void setValue(T* ptr) {
		this->ptr = ptr;
	}
 	T* operator()(){
		return ptr;
	}
	~Vehicle() {
		delete ptr;
	}
};

int menu()
{
	int k;
	cout <<endl<< "1 �x���" << endl;
	cout << "2 ������� ������" << endl;
	cout << "3 �������� ������" << endl;
	cout << "4 ������� ������" << endl;
	cout << "5 ���������� ����������" << endl;
	cout << "6 ����� �� ���������" << endl;
	cin >> k;
	return k;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	
	CivilinaAutoWithArmor* vehicle;
	CivilinaAutoWithArmor vehicle_obj;
	vehicle = &vehicle_obj;
	Vehicle<CivilinaAutoWithArmor> getVehicle(vehicle);

		float volume;
		string fuelType;
		string color;
		string bodyWorkType;
		int weight;
		int armorWidth;
		bool isClimatControlExist;

		for (;;)
		{
					cout << "������� ����� ��������� � �: ";
					cin >> volume;
					cout << "������� ��� ��������: ";
					getchar();
					getline(cin, fuelType, '\n');
					cout << "������� ����: ";
					getline(cin, color, '\n');
					cout << "������� ��� ������ ";
					getline(cin, bodyWorkType, '\n');
					for (;;) {
						cout << "������� ��� � ��: ";
						cin >> weight;
						if (!isSymbolic(weight))
							break;
				}
					cout << "������� ������ ����� � ��: ";
					cin >> armorWidth;
					cout << "������� ���� �� � ������� ������ �������� (1- ��/ 0- ���): ";
					cin >> isClimatControlExist;
					CivilinaAutoWithArmor automobile(
							volume,
							fuelType,
							color,
							bodyWorkType,
							weight,
						    isClimatControlExist,
							armorWidth
						);
					vehicle = &automobile;
					getVehicle.setValue(vehicle);
						
				for (;;) {
					bool stepOut = false;
					switch(menu()) {
					case 1: {
						getVehicle()->drive();
						vehicle->showStats();
						break;
					}
					case 2: {
						getVehicle()->crashVehicle();
						break;
					}
					case 3: {
						getVehicle()->repairVehicle();
						break;
					}
					case 4: {
						stepOut = true;
						break;
					}
					case 5: {vehicle->showStats();
						break;
					}
					case 6: return 0;
					default: {cout << "ERROR!!!" << endl;
						break; }
					}
					if (stepOut) break;
				}
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
