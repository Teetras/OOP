#pragma once
#include<iostream>
#include<string>
#include"IObserver.h"
#include"IObservable.h"
#include<vector>

using namespace std;

class Document: public IObservble<string> {
	string data;
	vector<IObserver<string>*> observers;
public:
	Document() :data(""){}

	void setData(string data);
	void notify();
	void addObserver(IObserver<string>* o);
	void removeObserver(IObserver<string>* o);
	string getData();
};