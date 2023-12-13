#pragma once
#include <iostream>
#include <stdexcept>
#include <string.h>
#define MAX_STRING_LENGTH 80

class exception 
{
protected:
    int code;
    char msg[MAX_STRING_LENGTH];

public:
    exception() : code(0) 
    {
        strcpy_s(msg, "Undefined Error");
    }

    exception(int c, const char* m) : code(c) 
    {
        strncpy_s(msg, m, sizeof(msg));
        msg[sizeof(msg) - 1] = '\0';
    }

    void show() const 
    {
        std::cerr << "Error Code: " << code << "\nMessage: " << msg << std::endl;
    }
};

class NumberInputError : public exception
{
public:
    NumberInputError() : exception(1, "Invalid input for a number.") {}
};

class StringInputError : public exception 
{
public:
    StringInputError() : exception(2, "Invalid input for a string.") {}
};

class EmptyListError : public exception {
public:
    EmptyListError() : exception(3, "List is empty.") {}
};

template <typename T>
void validateNumberInput(T num) 
{
    if (num < 0) 
    {
        throw NumberInputError();
    }
}

void validateStringInput(const char* str) 
{
    for (size_t i = 0; i < strlen(str); ++i) 
    {
        if (isdigit(str[i])) 
        {
            throw StringInputError();
        }
    }
}