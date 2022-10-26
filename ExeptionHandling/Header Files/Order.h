#pragma once
#include<iostream>
#include<vector>
#include<fstream>
#include<iomanip>
#include<string>


using namespace std;

class Order {
	int id;
	int productAmount;
	string name;

	int generateRandomId();
public:
	Order(int productAmount, string name);
	Order(int productAmount, string name, int id) {
		this->id = id;
		this->name = name;
		this->productAmount = productAmount; 
	}
	Order();
	int getId();
	int getProductAmount();

	void setName(string name);
	void setAmount(int amount);

	string getNmae();

	friend istream& operator>>(istream& s, Order& data);
	friend ostream& operator<<(ostream& s, Order& data);
};

