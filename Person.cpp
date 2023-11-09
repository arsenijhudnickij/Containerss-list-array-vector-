#include "libraries.h"
#include "Person.h"
#include "Student.h"

Person::Person()
{
    name = "";
    age = 0;
}
Person::Person(const Person& object)
{
    name = object.name;
    age = object.age;
}
