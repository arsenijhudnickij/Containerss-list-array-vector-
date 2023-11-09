#pragma once
#include "libraries.h"
#include "Person.h"

class Teacher : public Person{
private:
    int work_experience;
public:
    Teacher();
    Teacher(const std::string& name, const int& age, const int& work_experience) {
        this->age = age;
        this->name = name;
        this->work_experience = work_experience;
    };
    Teacher(const Teacher& object);
    ~Teacher() {};
    
    void showData() override;

    void setWork(int work)
    {
        this->work_experience = work;
    }
    int getWork() override
    {
        return this->work_experience;
    }
    int getYear() override { return 0; }
};