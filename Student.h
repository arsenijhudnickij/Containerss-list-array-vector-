#pragma once
#include "libraries.h"
#include "Person.h"

class Student : public Person {
private:
	int year_of_study;
public:
    Student();
    Student(const std::string& name, const int& age,const int& year_of_study) { 
        this->age = age;
        this->name = name;
        this->year_of_study = year_of_study; };
    Student(const Student& object);
    ~Student() {};

    void showData() override;

    void setYear(int year)
    {
        this->year_of_study = year;
    }
    int getYear() override
    {
        return this->year_of_study;
    }
    int getWork() override { return 0;}
};