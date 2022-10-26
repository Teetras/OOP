#pragma once
#include<iostream>
#include<string>
#include"Document.h"
#include"IObservable.h"
#include"Transaction.h"
#include"SmartPointer.h"

using namespace std;

class Worker :public IObserver<string> {
	SmartPointer<Transaction<Document>> doc;
	string data;
	int accountNumber;
public:
	Worker(string initialValue, SmartPointer<Transaction<Document>> obj, int numb) :
		data(initialValue),
		doc(obj),
		accountNumber(numb) {
		obj->addObserverToCurrentState(this);
	}

	Worker(): data(""), accountNumber(0), doc(new Transaction<Document>) {}

	void writeDataInDocument() {
		cout << "������� ������ � ��������: " << endl;
		getchar();
		getline(cin, data);
		doc->beginTransactions(data);
	}

	void back() {
		doc->deleteTransactions();
	}

	void clearBuffer() {
		doc->showState(State::begin);
		doc->commit();
		doc->showState(State::middle);
	}

	void update(string data) override {
		this->data = data;
	}

	void printData() {
		cout << "������� " << accountNumber << endl;
		cout << "---------------------��� ���� ��������----------------------------" << endl;
		if (data.empty()) {
			cout << "���, ������ ��� :(" << endl;
		}
		cout << data << endl;
	}

};