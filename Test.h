#pragma once
#include "libraries.h"

class Test {
private:
    std::string testName;
    std::vector<std::string> questions;
public:
    Test();
    Test(const std::string& testName, std::vector<std::string> quest) { this->testName = testName; this->questions = quest;};
    Test(const Test& object);
    ~Test() {};

    void setName(std::string name)
    {
        this->testName= name;
    }

    std::string get_name()
    {
        return this->testName;
    }
    void printQuestions();
    std::string get_quest(int i)
    {
        return questions[i];
    }
    int get_col_que()
    {
        return questions.size();
    }
    /*void printQuestions();*/

};