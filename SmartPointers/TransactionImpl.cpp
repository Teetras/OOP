#include"Transaction.h"

template <class T>
Transaction<T>& Transaction<T>::operator=(const Transaction<T> &obj) {
	if (this != &obj) {//проверка на случай obj=obj
		delete currentState;
		currentState = new T(*(obj.currentState));
	}
	return *this;
}

template <class T>
void Transaction<T>::showState(State state) {
	cout << "Состояние объекта ";
	if (!state) cout << "до начала транзакции " << endl;
	else cout << "после выполнения транзакции " << endl;
	if (prevState) cout << "prevState = " << prevState->getData() << endl;
	else cout << "prevState = NULL" << endl;
	cout << "currentState = " << currentState->getData() << endl;
}

template <class T>
int Transaction<T>::beginTransactions(string data) {
	delete prevState;
	prevState = currentState;
	currentState = new T(*prevState);
	if (!currentState) return 0;
	currentState->setData(data);
	return 1;
}

template <class T>
void Transaction<T>::commit() {
	delete prevState;
	prevState = NULL;
}
template <class T>
void Transaction<T>::deleteTransactions() {
	if (prevState != NULL) {
		delete currentState;
		currentState = prevState;
		prevState = NULL;
		currentState->notify();
	}
}

template<class T>
void Transaction<T>::addObserverToCurrentState(IObserver<string>* observer)
{
	currentState->addObserver(observer);
}
