#ifndef UNIQUE_PTR_H
#define UNIQUE_PTR_H

#include <iostream>
#include <fstream>

struct  DefaultDeleter {
    /*template<typename T>*/
};

template<typename T, typename D = DefaultDeleter()>
class UniquePtr {
private:
    T* m_ptr;
    D m_deleter;

public:

    UniquePtr()
        :m_ptr{nullptr}
    {}          //Конструктор для пустого указателя

    UniquePtr(T *pointer, D deleter)           //Конструктор для указателя на динамиески выделенную переменную и одномерный массив
        :m_ptr{pointer}, m_deleter{deleter}
    {}

    explicit UniquePtr(const std::string& filename, D deleter)            //Конструктор для указателя на файл (с проверкой его открытия)
        :m_ptr {new std::ifstream(filename)}, m_deleter{deleter}                    //explicit предотвращает неявное преобразовние типов
    {
        if (!m_ptr->is_open()) {
            delete m_ptr;
            std::cout <<"Unable to open file" << std::endl;
        }
    }

    UniquePtr(UniquePtr<T, D> const &up_ptr) = default;             //Конструктор для запрета копирования значения одного указателя другому

    ~UniquePtr() { delete m_ptr; }            //Деструктор

    UniquePtr& operator=(UniquePtr<T, D> const &pointer_) = default;           // Перегрузка опреатора присваивания, чтобы запретить присваивание одного указателя другому

    T &operator*() { return *m_ptr; }             //Перегрузка оператора разименования

    T& operator[](int ind) { return *(m_ptr + ind); };            //Перегрузка оператора [] для вывода елементов массива

};

#endif //UNIQUE_PTR_H
