// checkmateWaiting.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <cmath>

#ifdef _WIN32
#include <windows.h>
#endif

bool FixFlow()
{
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore();
        fflush(stdin);
        return true;
    }
    else
    {
        return false;
    }
}


template <typename T>
void Input(T& side1)
{
    do
    {
        std::cin >> side1;
    } while (FixFlow());
}

template <typename T>
void InputVectorValue(std::vector<T>& vectorValue )
{
    std::cout << "Сколько чисел будет в тестовой последовательности ";
    int number = 0;
    Input(number);
    for (int i = 0; i < number; ++i)
    {
        std::cout << "Введите " << i + 1 << " число ";
        vectorValue.push_back(0);
        Input(vectorValue[i]);
    }
}

double CheckmateWaiting(const std::vector<double>& vectorValue)
{
    double checkmateWaiting = 0;
    double summa = 0;
    for (auto& a: vectorValue)
    {
        summa += a;
    }
    checkmateWaiting = summa / vectorValue.size();
    return checkmateWaiting;
}

double CheckmateWaiting(const std::vector<int>& vectorValue)
{
    double checkmateWaiting = 0;
    double summa = 0;
    for (auto& a : vectorValue)
    {
        summa += a;
    }
    checkmateWaiting = summa / vectorValue.size();
    return checkmateWaiting;
}




template <typename T>
void PrintVector(const std::vector<T>& vectorValue)
{
    for (int i = 0; i < vectorValue.size(); ++i)
    {
        std::cout << vectorValue[i] << ' ';
    }
    std::cout << '\n';
}

double StandardDeviation(const std::vector<double>& vectorValue)
{
    double checkmateWaiting = CheckmateWaiting(vectorValue);
    double standardDeviation = 0;
    for (auto& a : vectorValue)
    {
        standardDeviation += pow((a - checkmateWaiting), 2);
    }
    standardDeviation = standardDeviation / vectorValue.size();
    standardDeviation = sqrt(standardDeviation);
    return standardDeviation;
}

double StandardDeviation(const std::vector<int>& vectorValue)
{
    double checkmateWaiting = CheckmateWaiting(vectorValue);
    double standardDeviation = 0;
    for (auto& a : vectorValue)
    {
        standardDeviation += pow((a - checkmateWaiting), 2);
    }
    standardDeviation = standardDeviation / vectorValue.size();
    standardDeviation = sqrt(standardDeviation);
    return standardDeviation;
}

void PrintMain()
{
    std::cout << "Эта программа предназначена для тестирования функций из " <<
        "заголовочного файлов functions.h. и inputOutput.h\n";
}

int main()
{
#ifdef _WIN32
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
#endif
    std::vector<double> vectorValue;
//   std::vector<int> vectorValue;
    PrintMain();
    InputVectorValue(vectorValue);
    std::cout << CheckmateWaiting(vectorValue) << '\n';
    std::cout << StandardDeviation(vectorValue) << '\n';
    PrintVector(vectorValue);
    std::cout << "Hello World!\n";
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
