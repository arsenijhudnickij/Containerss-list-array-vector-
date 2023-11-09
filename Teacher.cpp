#include "libraries.h"
#include "Teacher.h"

Teacher::Teacher()
{
    work_experience = 0;
}
Teacher::Teacher(const Teacher& object)
{
    work_experience = object.work_experience;
}

void Teacher::showData()
{
    std::cout << "Имя преподавателя : " << this->name << std::endl;
    std::cout << "Возраст преподавателя:" << this->age << std::endl;
    std::cout << "Количество лет стажа преподавателя:" << this->work_experience << std::endl;
}