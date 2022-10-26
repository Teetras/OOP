#include<iostream>
#include<cstdlib>
#include"Exception.h"
#include"Shop.h"
#include<Windows.h>
#include<fstream>


using namespace std;

int menu()
{
	int k;
	cout << endl << "1 Добавить заказ машины" << endl;
	cout << "2 Просмотреть заказы" << endl;
	cout << "3 Удалить заказ" << endl;
	cout << "4 Извлечь из файла конкретный заказ" << endl;
	cout << "5 Изменить данные" << endl;
	cout << "6 Выйти" << endl;
	cin >> k;
	return k;
}



int main() {


	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

   	int amountOfCars;
	string name;
	
	HandleError *handler = new HandleShopError();
	Shop* shop = new CarShop(handler);

	Order* order = new Order(0,"");
	vector<Order> vec = shop->read();



	while (true) {
		switch (menu())
		{
		case 1: {
			system("cls");
			cout << "Введите колличесво машин для покупки: ";
			cin >> amountOfCars;
			cout << "Введите название: ";
			getchar();
			getline(cin, name);
			vec.push_back(Order(amountOfCars, name));
			shop->save(vec);
			break;
		}
		case 2: {
			shop->read();
			break;
		}
		case 3: {
			int n;
			cout << "Введите номер удаляемого товара: " << endl;
			cin >> n;
			if (n > vec.size()) {
				cout << "Неправильное число" << endl;
					system("pause");
					break;
			}
			shop->deleteFromFile(n);
			break;
		}
		case 4: {
			shop->readOneItem();
			break;
		}
		case 5: {
			int selectedItem;
			cout << "Введите номер изменяемой записи: ";
			cin >> selectedItem;
			cout << "Введите новое колличесво машин для покупки: ";
			cin >> amountOfCars;
			cout << "Введите новое название: ";
			getchar();
			getline(cin, name);
			vec[selectedItem - 1].setAmount(amountOfCars);
			vec[selectedItem - 1].setName(name);
			shop->save(vec);
			break;
		}
		case 6: {
			return 0;
		}
		default:
			break;
		}
	}

}

