#include"Document.h"

void Document::setData(string data) {
	this->data += data;
	this->data += " ";
	notify();
}

void Document::notify() {
	for (auto o : observers) {
		o->update(data);
	}
}

void Document::addObserver(IObserver<string>* o) {
	observers.push_back(o);
}


string Document::getData() {
	return this->data;
}

void Document::removeObserver(IObserver<string>* o) {
	observers.erase(remove(observers.begin(), observers.end(), o), observers.end());
}