#include"Order.h"

Order::Order(int productAmount, string name) {
	this->productAmount = productAmount;
	this->id = generateRandomId();
	this->name = name;
}

Order::Order() {
	this->productAmount = 0;
	this->id = generateRandomId();
}

int Order::generateRandomId() {return rand();}

int Order::getId() {return id;}

int Order::getProductAmount() {return productAmount;}

ostream& operator<<(ostream& file, Order& data) {
	file.write((char*)(&data), sizeof(Order));
	return file;
}

istream& operator>>(istream& file, Order& data) {
	file.read((char*)(&data), sizeof(Order));
	return file;
}

void Order::setAmount(int amount) {this->productAmount = amount;}

void Order::setName(string name) {this->name = name;}

string Order::getNmae(){return name;}