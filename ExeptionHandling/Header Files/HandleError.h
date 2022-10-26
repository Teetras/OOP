#pragma once
#include<string>
#include"Exception.h"

class HandleError
{
public:
	virtual void handle(exception* error) = 0;
};

class HandleShopError : public HandleError {
	string IOExceptionStr = "Ошибка открытия файла!";
	string ServiceUnavalibleExeptionStr = "Сервис недоступен";
	string UnidentifiedExceptionStr = "Неопознаная ошибка";
public:
	void handle(exception* error) override {
		if (typeid(*error) == typeid(IOExeption))
			cout << IOExceptionStr << endl;
		else if (typeid(*error) == typeid(ServiceUnavalibleExeption))
			cout << ServiceUnavalibleExeptionStr << endl;
		else  cout << UnidentifiedExceptionStr << endl;
	}

};