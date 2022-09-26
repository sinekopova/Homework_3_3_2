#include <windows.h>

#include <iostream>


class Counter {
public:
    Counter() {
        m_value = 0;
    };
    Counter(int m_value) {
        this->m_value = m_value;
    };
    void setCounter(int m_value) {
        this->m_value = m_value;
    };
    int getCounter() {
        return m_value;
    };
    void increaseCounter() {
        ++m_value;
    };
    void decreaseCounter() {
        --m_value;
    };
private:
    int m_value;
};

Counter createCounter(int init) {
    if (init != 0)
        return Counter(init);
    else
        return Counter();
};

int getInit() {
    std::string isInit;
    bool answer = false;
    int init = 0;

    while (!answer)
    {
        std::cout << "Вы хотите указать начальное значение счётчика ? Введите да или нет : ";
        std::cin >> isInit;

        if (isInit == "да") {
            answer = true;
            std::cout << "Введите начальное значение счётчика : ";
            std::cin >> init;
        }
        else if (isInit == "нет") {
            answer = true;
        }
        else {
            answer = false;
        }
    }

    return init;
};

void processing(Counter& count) {
    bool exit = false;
    while (!exit)
    {
        char com = 0;
        std::cout << "Введите команду('+', '-', '=' или 'x') : ";
        std::cin >> com;
        switch (com)
        {   
            case '+':
                count.increaseCounter();
                break;
             case '-':
                count.decreaseCounter();
                break;
            case '=':
                std::cout << count.getCounter() << std::endl;
                break;
            case 'x': case 'х':
                exit = true;
                std::cout << "До свидания!" << std::endl;
                break;
            default:
                break;
        }
    }
};

int main()
{

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int init = getInit();

    Counter count = createCounter(init);
        
    processing(count);

    return 0;
}
