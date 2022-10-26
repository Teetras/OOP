#pragma once

template<class T>
class IObserver {
public:
	virtual void update(T p) = 0;
};

