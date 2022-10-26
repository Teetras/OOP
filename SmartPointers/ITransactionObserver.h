#pragma once
#include"IObserver.h"

template<class T>
class ITransactionObserver: public IObserver<T>
{
	//virtual void beginTransactionIntent(string data) = 0;
	virtual void commitIntent()=0;
	virtual void showStateIntent() = 0;
	virtual void deleteTransactionIntent() = 0;

};
