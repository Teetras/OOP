#pragma once
#include"State.h"
#include<iostream>
#include"IObserver.h"

using namespace std;

template <class T>
class Transaction{
	T* currentState;
	T* prevState;
public:
	Transaction() :prevState(NULL), currentState(new T){}
	Transaction(const Transaction& obj) : currentState(new
		T(*(obj.currentState))), prevState(NULL) {}
	~Transaction() {
		delete currentState; delete prevState;
	}
	Transaction& operator=(const Transaction& obj);
	void showState(State state);
	int beginTransactions(string data);
	void commit();
	void deleteTransactions(); 
	void addObserverToCurrentState(IObserver<string> *observer);

};