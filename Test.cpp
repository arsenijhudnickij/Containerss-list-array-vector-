#include "libraries.h"
#include "Test.h"

Test::Test()
{
    testName = "";
}
Test::Test(const Test& object)
{
    testName = object.testName;
}


void Test::printQuestions() {
    std::cout << "Название теста:" << this->testName << " \nВопросы:" << std::endl;
    for (std::vector<std::string>::iterator it = questions.begin(); it != questions.end();it++) {
        std::cout << "- " << (*it)<< std::endl;
    }
}

//void Test::addQuestion(Question* question) {
//    questions.push_back(question);
//}