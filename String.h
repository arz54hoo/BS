//
// Created by seik on 2019-04-26.
//

#ifndef BS_STRING_H
#define BS_STRING_H

#include "BankingCommonDecl.h"
class String
{
    char *str;
    int len;

public:
    String();
    String(const char *s);
    String(const String &s);
    String & operator=(const String &s);
    String operator+(const String &s);
    String&operator+=(const String &s);
    bool operator==(const String &s);
    ~String();
    friend ostream& operator<<(ostream& os, const String &s);
    friend istream& operator>>(istream& is, String &s);
};

#endif //BS_STRING_H
