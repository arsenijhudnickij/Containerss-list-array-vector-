#pragma once
#include "libraries.h"

class Person
{
protected:
	int age;
	std::string name;
public:
	Person();
	Person(const std::string& name,const int& age) { this->age = age; this->name = name; };
	Person(const Person& object);
	~Person() {};

	virtual void showData() = 0;

	void setAge(int age)
	{
		this->age = age;
	}
	int getAge()
	{
		return this->age;
	}
	void setName(std::string name)
	{
		this->name = name;
	}
	std::string getName()
	{
		return this->name;
	}
	virtual int getYear() = 0;
	virtual int getWork() = 0;
};