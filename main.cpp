#include "libraries.h"
#include "Person.h"
#include "Student.h"
#include "Teacher.h"
#include "Test.h"

int check() {
    int number;
    std::cin >> number;
    while (std::cin.fail() || std::cin.get() != '\n' || number < 0) {
        {
            std::cout << "\nOшибка ввода.\nПовторите попытку:";
            std::cin.clear();
            std::cin.ignore(256, '\n');
            std::cin >> number;
        }
    }
    return number;
}

int main()
{
    system("chcp 1251");
    system("cls");
    Person* pers = NULL;

    std::vector<Person*> students;
    int current_students = 0;

    std::list<Person*> teachers;
    int current_teachers = 0;

    Test* test = NULL;

    std::array<Test*, 5> tests;
    int current_tests = 0;

    int choice{};
    do {
        std::cout << "1.Добавить!! ученика" << std::endl;
        std::cout << "2.Добавить!! учителя" << std::endl;
        std::cout << "3.Добавить !!тест" << std::endl;
        std::cout << "4.Просмотреть !!всех учеников" << std::endl;
        std::cout << "5.Просмотреть!! всех учителей" << std::endl;
        std::cout << "6.Посмотреть все !!тесты" << std::endl;
        std::cout << "7.Отсортировать всех!! учеников по имени" << std::endl;
        std::cout << "8.Отсортировать всех!! учителей по возрасту" << std::endl;
        std::cout << "9.Отсортировать все тесты по названию" << std::endl;
        std::cout << "10.Поиск учителя!! по имени" << std::endl;
        std::cout << "11.Поиск ученика !!по имени" << std::endl;
        std::cout << "12.Поиск теста по !!названию" << std::endl;
        std::cout << "13.Удаление !!ученика" << std::endl;
        std::cout << "14.Удаление !!учителя" << std::endl;
        std::cout << "15.Удаление !!теста" << std::endl;
        std::cout << "16.Изменение!! имени ученика" << std::endl;
        std::cout << "17.Изменение имени !!преподавателя" << std::endl;
        std::cout << "18.Изменение !!названия теста" << std::endl;
        std::cout << "19.Выход!!" << std::endl;

        std::cout << "\n\n";
        std::cout << "Ваш выбор?" << std::endl;

        try {
            if (!(std::cin >> choice))
                throw std::runtime_error("Неверный ввод данных");
        }
        catch (std::runtime_error errr) {

            std::cout << errr.what() << std::endl;
            system("pause");
            std::cin.clear();
            std::cin.ignore(1024, '\n');
            continue;
        }

        std::cin.clear();
        std::cin.ignore(1024, '\n');
        system("cls");
        switch (choice)
        {
        case 1:
        {
            std::string name_st;
            std::cout << "Введите имя ученика" << std::endl;
            std::getline(std::cin, name_st);
            int age_st;
            std::cout << "Введите возраст ученика" << std::endl;
            age_st = check();
            int year_of;
            std::cout << "Введите количество лет обучения ученика:" << std::endl;
            year_of = check();

            pers = new Student(name_st, age_st, year_of);
            students.push_back(pers);
            current_students++;
            std::cout << "Успешно добавлен" << std::endl;
            std::vector<Person*>::iterator i = students.begin();

            system("pause");
            system("cls");
            break;
        }
        case 2:
        {
            std::string name_tch;
            std::cout << "Введите имя преподавателя" << std::endl;
            std::getline(std::cin, name_tch);
            int age_tch;
            std::cout << "Введите возраст преподавателя" << std::endl;
            age_tch = check();
            int year_of;
            std::cout << "Введите стаж преподавателя:" << std::endl;
            year_of = check();

            pers = new Teacher(name_tch, age_tch, year_of);
            teachers.push_back(pers);
            std::cout << "Успешно добавлен" << std::endl;
            current_teachers++;

            system("pause");
            system("cls");
            break;
        }
        case 3:
        {
            if (current_tests < 6)
            {
                std::string name_test;
                std::cout << "Введите название теста:" << std::endl;
                std::getline(std::cin, name_test);
                std::vector<std::string> quest;
                std::string pointer = "y";
                do {
                    std::string question;
                    std::cout << "Введите ваш вопрос?" << std::endl;
                    std::getline(std::cin, question);
                    quest.push_back(question);
                    std::cout << "Хотите продолжить ввод?(если да - y)" << std::endl;
                    std::getline(std::cin, pointer);
                } while (pointer == "y");
                test = new Test(name_test, quest);
                tests[current_tests] = test;
                current_tests++;
            }
            std::cout << "\n";
            system("pause");
            system("cls");
            break;
        }
        case 4:
        {
            if (current_students > 0)
            {
                std::vector<Person*>::const_iterator p = students.cbegin();
                while (p != students.cend())
                {
                    (*p)->showData();
                    p++;
                }
            }
            else
            {
                std::cout << "Отсутствуют ученики" << std::endl;
            }
            std::cout << "\n";
            system("pause");
            system("cls");
            break;
        }
        case 5:
        {
            if (current_teachers > 0)
            {
                std::list<Person*>::const_iterator it = teachers.cbegin();
                while (it != teachers.cend())
                {
                    (*it)->showData();
                    it++;
                }
            }
            else
            {
                std::cout << "Преподаватели отсутствуют" << std::endl;
            }
            std::cout << "\n";
            system("pause");
            system("cls");
            break;
        }
        case 6:
        {
            for (int i = 0; i < current_tests; i++)
            {
                tests[i]->printQuestions();
            }
            std::cout << "\n";
            system("pause");
            system("cls");
            break;
        }
        case 7:
        {
            if (current_students > 0)
            {
                std::list<std::string> sort;
                for (std::vector<Person*>::iterator it = students.begin(); it != students.end(); it++)
                {
                    sort.push_back((*it)->getName());
                }
                sort.sort();
                std::cout << "Отсортированный список:" << std::endl;
                for (std::list<std::string>::iterator it = sort.begin(); it != sort.end(); it++)
                {
                    for (std::vector<Person*>::iterator i = students.begin(); i != students.end(); i++)
                    {
                        if ((*i)->getName() == *it)
                        {
                            (*i)->showData();
                        }
                    }
                }
            }
            else
            {
                std::cout << "Отсутствуют ученики" << std::endl;
            }
            std::cout << "\n";
            system("pause");
            system("cls");
            break;
        }
        case 8:
        {
            if (current_teachers > 0)
            {
                std::list<int> sort;
                for (std::list<Person*>::iterator it = teachers.begin(); it != teachers.end(); it++)
                {
                    sort.push_back((*it)->getAge());
                }

                sort.sort();

                std::cout << "Отсортированный список:" << std::endl;
                for (std::list<int>::iterator it = sort.begin(); it != sort.end(); it++)
                {
                    for (std::list<Person*>::iterator i = teachers.begin(); i != teachers.end(); i++)
                    {
                        if ((*i)->getAge() == *it)
                        {
                            (*i)->showData();
                        }
                    }
                }
            }
            else
            {
                std::cout << "Преподаватели отсутствуют" << std::endl;
            }
            std::cout << "\n";
            system("pause");
            system("cls");
            break;
        }
        case 9:
        {
            if (current_tests > 0)
            {
                std::string* temporary = new std::string[current_tests];
                for (int i = 0; i < current_tests; i++) {
                    temporary[i] = tests[i]->get_name();
                }
                for (int i = 0; i < current_tests; i++) {
                    for (int j = current_tests - 1; j > i; j--) {
                        if (temporary[j - 1] > temporary[j]) {
                            swap(temporary[j - 1], temporary[j]);
                        }
                    }
                }
                for (int i = 0; i < current_tests; i++) {
                    for (int j = 0; j < current_tests; j++)
                    {
                        if (temporary[i] == tests[j]->get_name())
                        {
                            tests[j]->printQuestions();
                        }
                    }
                }
            }
            else
            {
                std::cout << "Отсутствуют тесты" << std::endl;
            }
            std::cout << "\n";
            system("pause");
            system("cls");
            break;
        }
        case 10:
        {
            if (current_teachers > 0)
            {
                std::string name_poi;
                std::cout << "Введите искомое имя:" << std::endl;
                std::getline(std::cin, name_poi);
                for (std::list<Person*>::iterator i = teachers.begin(); i != teachers.end(); i++)
                {
                    if ((*i)->getName() == name_poi)
                    {
                        std::cout << "Учитель найден\n" << std::endl;
                        (*i)->showData();
                        break;
                    }
                }
            }
            else
            {
                std::cout << "Преподаватели отсутствуют" << std::endl;
            }
            std::cout << "\n";
            system("pause");
            system("cls");
            break;
        }
        case 11:
        {
            if (current_students > 0)
            {
                std::string name_poi;
                std::cout << "Введите искомое имя:" << std::endl;
                std::getline(std::cin, name_poi);
                for (std::vector<Person*>::iterator i = students.begin(); i != students.end(); i++)
                {
                    if ((*i)->getName() == name_poi)
                    {
                        std::cout << "Ученик найден\n" << std::endl;
                        (*i)->showData();
                        break;
                    }
                }
            }
            else
            {
                std::cout << "Отсутствуют ученики" << std::endl;
            }
            std::cout << "\n";
            system("pause");
            system("cls");
            break;
        }
        case 12:
        {
            if (current_tests > 0)
            {
                std::string name_poi;
                std::cout << "Введите искомый тест:" << std::endl;
                std::getline(std::cin, name_poi);
                for (std::array<Test*, 5>::iterator i = tests.begin(); i != tests.end(); i++)
                {
                    if ((*i)->get_name() == name_poi)
                    {
                        std::cout << "Тест найден\n" << std::endl;
                        (*i)->printQuestions();
                        break;
                    }
                }
            }
            else
            {
                std::cout << "Отсутствуют тесты" << std::endl;
            }
            std::cout << "\n";
            system("pause");
            system("cls");
            break;
        }
        case 13:
        {
            if (current_students > 0)
            {
                std::vector<Person*>::const_iterator p = students.cbegin();
                while (p != students.cend())
                {
                    (*p)->showData();
                    p++;
                }
                std::cout << "\n";
                system("pause");
                system("cls");
                std::string name_poi;
                std::cout << "Введите имя ученика, которого хотите удалить" << std::endl;
                std::getline(std::cin, name_poi);
                int x = 0;
                int flag = 0;
                for (std::vector<Person*>::iterator i = students.begin(); i != students.end(); i++)
                {
                    if ((*i)->getName() == name_poi)
                    {
                        flag = 1;
                        students.erase(students.begin() + x);
                        std::cout << "Ученик удален" << std::endl;
                        current_students;
                        break;
                    }
                    x++;
                }
                if (flag == 0)
                {
                    std::cout << "Такого ученика нет" << std::endl;
                }
                std::vector<Person*>::iterator i = students.begin();

            }
            else
            {
                std::cout << "Отсутствуют ученики" << std::endl;
            }
            std::cout << "\n";
            system("pause");
            system("cls");
            break;
        }
        case 14:
        {
            if (current_teachers > 0)
            {
                std::list<Person*>::const_iterator p = teachers.cbegin();
                while (p != teachers.cend())
                {
                    (*p)->showData();
                    p++;
                }
                std::cout << "\n";
                system("pause");
                system("cls");
                std::string name_poi;
                std::cout << "Введите имя учителя, которого хотите удалить" << std::endl;
                std::getline(std::cin, name_poi);
                int x = 0;
                int flag = 0;
                for (std::list<Person*>::iterator i = teachers.begin(); i != teachers.end(); i++)
                {
                    if ((*i)->getName() == name_poi)
                    {
                        flag = 1;
                        teachers.erase(i);
                        std::cout << "Преподаватель удален" << std::endl;
                        current_teachers--;
                        break;
                    }
                    x++;
                }
                if (flag == 0)
                {
                    std::cout << "Такого преподавателя нет" << std::endl;
                }
            }
            else
            {
                std::cout << "Преподаватели отсутствуют" << std::endl;
            }
            std::cout << "\n";
            system("pause");
            system("cls");
            break;
        }
        case 15:
        {
            if (current_tests > 0)
            {
                for (int i = 0; i < current_tests; i++)
                {
                    tests[i]->printQuestions();
                }
                std::cout << "\n";
                system("pause");
                system("cls");
                std::string name_poi;
                std::cout << "Введите название теста, который хотите удалить" << std::endl;
                std::getline(std::cin, name_poi);
                int x = 0;
                for (int i = 0; i < current_tests; i++)
                {
                    if (tests[i]->get_name() == name_poi)
                    {
                        for (int j = i; j < current_tests; j++)
                        {
                            tests[j] = tests[j + 1];
                        }
                        std::cout << "Тест удален" << std::endl;
                        current_tests--;
                        x++;
                        break;
                    }
                }
                if (x == 0)
                {
                    std::cout << "Такого теста нет" << std::endl;
                }
            }
            else
            {
                std::cout << "Отсутствуют тесты" << std::endl;
            }
            std::cout << "\n";
            system("pause");
            system("cls");
            break;
        }
        case 16:
        {
            if (current_students > 0)
            {
                std::vector<Person*>::const_iterator p = students.cbegin();
                while (p != students.cend())
                {
                    (*p)->showData();
                    p++;
                }
                system("pause");
                system("cls");
                std::string name_poi;
                std::cout << "Введите имя, которое хотите изменить:" << std::endl;
                std::getline(std::cin, name_poi);
                int poi = 0;
                for (std::vector<Person*>::iterator i = students.begin(); i != students.end(); i++)
                {
                    if ((*i)->getName() == name_poi)
                    {
                        poi = 1;
                        std::string name_new;
                        std::cout << "Введите новое имя, которое будет у ученика:" << std::endl;
                        std::getline(std::cin, name_new);
                        (*i)->setName(name_new);
                        std::cout << "Имя изменено" << std::endl;
                        break;
                    }
                }
                if (poi == 0)
                {
                    std::cout << "Такого ученика нет" << std::endl;
                }
                std::vector<Person*>::iterator i = students.begin();

            }
            else
            {
                std::cout << "Отсутствуют ученики" << std::endl;
            }
            std::cout << "\n";
            system("pause");
            system("cls");
            break;
        }
        case 17:
        {
            if (current_teachers > 0)
            {
                std::list<Person*>::const_iterator it = teachers.cbegin();
                while (it != teachers.cend())
                {
                    (*it)->showData();
                    it++;
                }
                std::cout << "\n";
                system("pause");
                system("cls");

                std::string name_poi;
                std::cout << "Введите имя, которое хотите изменить:" << std::endl;
                std::getline(std::cin, name_poi);
                int poi = 0;
                for (std::list<Person*>::iterator i = teachers.begin(); i != teachers.end(); i++)
                {
                    if ((*i)->getName() == name_poi)
                    {
                        std::string name_new;
                        poi = 1;
                        std::cout << "Введите новое имя, которое будет у преподавателя:" << std::endl;
                        std::getline(std::cin, name_new);
                        (*i)->setName(name_new);
                        std::cout << "Имя изменено" << std::endl;
                        break;
                    }
                }
                if (poi == 0)
                {
                    std::cout << "Такого преподавателя нет" << std::endl;
                }
            }
            else
            {
                std::cout << "Преподаватели отсутствуют" << std::endl;
            }
            std::cout << "\n";
            system("pause");
            system("cls");
            break;
        }
        case 18:
        {
            if (current_tests > 0)
            {
                for (int i = 0; i < current_tests; i++)
                {
                    tests[i]->printQuestions();
                }
                std::cout << "\n";
                system("pause");
                system("cls");
                std::string name_poi;
                std::cout << "Введите название, которое хотите изменить:" << std::endl;
                std::getline(std::cin, name_poi);
                int poi = 0;
                for (int i = 0; i < current_tests; i++)
                {
                    if (tests[i]->get_name() == name_poi)
                    {
                        std::string name_new;
                        poi = 1;
                        std::cout << "Введите новое название, которое будет у теста:" << std::endl;
                        std::getline(std::cin, name_new);
                        tests[i]->setName(name_new);
                        std::cout << "Имя изменено" << std::endl;
                        break;
                    }
                }
                if (poi == 0)
                {
                    std::cout << "Такого теста нет" << std::endl;
                }

            }
            else
            {
                std::cout << "Отсутствуют тесты" << std::endl;
            }
            std::cout << "\n";
            system("pause");
            system("cls");
            break;
        }
        case 19:
            break;
        default:
            std::cout << "Неверный ввод" << std::endl;
        }
    } while (choice != 19);

    std::ofstream File;
    File.open("Persons.txt", std::ios::binary);
    if (File.is_open())
    {
        File << "------------------------------------------------\n";
        File << "|                   УЧЕНИКИ                    |\n";
        File << "------------------------------------------------\n";
        File << '|' << std::setw(20) << std::left << "Имя " << '|' << std::setw(20) << "Должность " << '|' << std::setw(7) << "Лет обучения |\n";
        File << "-----------------------------------------------\n";
        for (int i = 0; i < students.size(); i++)
        {
            File << '|' << std::setw(20) << std::left << students[i]->getName() << '|' << std::setw(20)
                << students[i]->getAge() << '|' << std::setw(4) << students[i]->getYear() << "|" << std::endl;
            File << "------------------------------------------------\n";
        }
        File << "------------------------------------------------\n";
        File << "|                     ПРЕПОДАВАТЕЛИ            |\n";
        File << "------------------------------------------------\n";
        File << '|' << std::setw(20) << std::left << "Имя " << '|' << std::setw(20) << "Должность " << '|' << std::setw(7) << "Стаж работы |\n";
        File << "-----------------------------------------------\n";
        for (std::list<Person*>::iterator p = teachers.begin(); p != teachers.end(); ++p)
        {
            File << '|' << std::setw(20) << std::left << (*p)->getName() << '|' << std::setw(20)
                << (*p)->getAge() << '|' << std::setw(4) << (*p)->getWork() << "|" << std::endl;
            File << "------------------------------------------------\n";
        }
        std::cout << "Данные успешно записаны в файл\n";
    }
    else std::cout << "Ошибка открытия файла\n";
    File.close();

    std::ofstream File1;
    File1.open("Tests.txt", std::ios::binary);
    if (File1.is_open())
    {
        File1 << "------------------------------------------------\n";
        File1 << "|                   Тесты                      |\n";
        File1 << "------------------------------------------------\n";
        for (int i = 0; i < current_tests; i++)
        {
            File1 << tests[i]->get_name();
            File1 << "\n";
            for (int j = 0; j < tests[i]->get_col_que(); j++)
            {
                File1 << tests[i]->get_quest(j);
            }
            File1 << "\n\n";
        }
    }
    else std::cout << "Ошибка открытия файла\n";
    File1.close();
    return 0;
}