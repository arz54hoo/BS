//
// Created by seik on 2019-04-26.
//

#include "String.h"
String::String() :str(NULL), len(0) {}

String::String(const char *s) {

    len = strlen(s) +1;
    str = new char[len];
    strcpy(str, s);
}

String::String(const String &s) {

    len = s.len;
    str = new char[len];
    strcpy(str, s.str);
}

String& String::operator=(const String &s) {

    if (str != NULL)
        delete []str;
    len = s.len;
    str = new char[len];
    strcpy(str, s.str);
    return *this;
}

String String::operator+(const String &s) {

    char * tempstr = new char[len + s.len -1];
    strcpy(tempstr, str);
    strcat(tempstr, s.str);
    String temp(tempstr);
    delete []tempstr;

    return temp;
}

String& String::operator+=(const String &s) {

    *this = (*this + s);
    return *this;
}

bool String::operator==(const String &s) {

    return strcmp(str, s.str)==0 ? true: false;
}

String::~String() {

    if(str!=NULL)
        delete []str;
}

ostream& operator<<(ostream& os, const String &s){

    os << s.str;
    return os;
}


istream& operator>>(istream& is, String &s) {

    char temp[50];
    is >> temp;
    s = String(temp);
    return is;
}