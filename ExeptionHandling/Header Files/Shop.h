#pragma once
#include<iostream>
#include"Exception.h"
#include<string>
#include<functional>
#include"Order.h"
#include"HandleError.h"


using namespace std;

class Shop {
	HandleError* handler;
public:

	Shop(HandleError *handler) {
		this->handler = handler;
	}

	virtual void save(vector<Order> data) = 0;
	virtual vector<Order> read() = 0;
	virtual void deleteFromFile(int number) = 0;
	virtual void readOneItem() = 0;

protected:
	void handle(function<void()> block)  {
		try {
			block();
		}
		catch (exception* error) {
			handler->handle(error);
		}
	}

};

class CarShop :public  Shop {
	Order* order;
	void showOrderInfo() {
		cout << "Идентификатор заказа: " << order->getId() << endl;
		cout << "Колличество машин: " << order->getProductAmount() << endl;
	}
public:
	CarShop(HandleError*handler): Shop(handler),order(NULL) {}
	CarShop(HandleError* handler, int a) : Shop(handler), order(NULL) {
		handle([] {
			cout << "Вызов конструктора" << endl;
			throw new ConstructorException;
			});
	}
	
public:


	void save(vector<Order> data) override {
		handle([&data] {
			ofstream file;
			file.open("myFile.dat", ios::binary);
			if (!file.is_open() || !file.good() || file.bad()) throw new IOExeption();
			for (auto item : data) {
				file << item;
			}
			file.close();
			});
	}


	vector<Order> read() override {
		vector<Order> data;
		handle([&data] {
			Order item;
			ifstream file;
			file.open("myFile.dat", ios::binary);
			if (!file.is_open() || !file.good() || file.bad()) throw new IOExeption();
			cout << "-------------------------------------------------------------------\n";
			cout << "        Название                     Кол-во           Идентификатор   \n";
			cout << "--------------------------------------------------------------------" << endl;
			while (file >> item)
			{
				cout << "\t" << item.getNmae() << "\t\t\t" << item.getProductAmount() << "\t\t" << item.getId() << "\n";
				cout << "--------------------------------------------------------------------" << endl;
				data.push_back(item);
			}
			file.close();
			});
		return data;
	}

	void deleteFromFile(int number) {
		vector<Order> items;
		handle([&items, &number] {
			Order item;
			ifstream file;
			file.open("myFile.dat", ios::in | ios::binary);
			if (!file.is_open() || !file.good() || file.bad()) throw new IOExeption();

			while (file >> item)
			{
				items.push_back(item);
			}
			items.erase(items.begin() + (number - 1));

			file.close();
			});
		save(items);
	}

	void readOneItem() {
		Order order;
		ifstream infile;
		handle([&order, &infile] {
			infile.open("myFile.dat", ios::in | ios::binary);
			if (!infile.is_open() || !infile.good() || infile.bad()) throw new IOExeption();
			infile.seekg(0, ios::end);
			int endposition = infile.tellg();
			int n = endposition / sizeof(Order);
			cout << "\nВ файле " << n << " заказов";
			cout << "\nВведите номер заказа: ";
			cin >> n;
			int position = (n - 1) * sizeof(Order);
			infile.seekg(position);
			infile >> order;
			cout << "-------------------------------------------------------------------\n";
			cout << "        Название              Кол-во           Идентификатор   \n";
			cout << "--------------------------------------------------------------------" << endl;
			cout << "\t" << order.getNmae() << "\t\t\t" << order.getProductAmount() << "\t\t" << order.getId() << "\n";
			cout << "--------------------------------------------------------------------" << endl;
			cout << endl;
			});
	}

};

