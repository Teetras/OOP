#pragma once

#include<iostream>

using namespace std;

class IOExeption : public exception {
public:
	IOExeption(){}
};

class ServiceUnavalibleExeption : public exception {
public:
	ServiceUnavalibleExeption(){}
};

class ConstructorException : public exception {
public:
	ConstructorException(){}
};