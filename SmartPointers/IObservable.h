#pragma once
#include"IObserver.h"

template<class T>
class IObservble {
public:
	virtual void addObserver(IObserver<T>* o) = 0;
	virtual void removeObserver(IObserver<T>* o) = 0;
     virtual void notify() = 0;
};