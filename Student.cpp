#include "libraries.h"
#include "Student.h"

Student::Student()
{
    year_of_study = 0;
}
Student::Student(const Student& object)
{
    year_of_study = object.year_of_study;
}

void Student::showData()
{
    std::cout << "Имя ученика : " << name << std::endl;
    std::cout << "Возраст ученика:" << age << std::endl;
    std::cout << "Количество лет обучения ученика:" << year_of_study << std::endl;
}

