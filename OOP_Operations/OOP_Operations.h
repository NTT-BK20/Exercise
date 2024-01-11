#pragma once
#ifndef OOP_OPERATION_H
#define OOP_OPERATION_H

#include "Header.h"

class Address
{
public:
    Address() = default;
    Address(const std::string& s, const std::string& ci, const std::string& co, const std::string& z);
    void updateAddress(const std::string& s, const std::string& ci, const std::string& co, const std::string& z);
    void printAddress(void);
private:
    std::string m_street;
    std::string m_city;
    std::string m_country;
    std::string m_zipCode;
};

class Person
{
public:
    Address* addresses;
    Person(const std::string& n, const std::string& p, const std::string& e, Address* addr);
	void printInfo(void);
	void updateInfo(const std::string& n, const std::string& p, const std::string& e);
	virtual std::string getJob(void);
protected:
	std::string m_name;
	std::string m_phone;
	std::string m_email;
};

class Student : public Person
{
public:
    Student(const std::string& n, const std::string& p, const std::string& e, Address* addr);
    std::string getJob(void);
private:
    uint32_t m_studentId;
    uint32_t m_grade;
};

class Doctor : public Person
{
public:
    Doctor(const std::string& n, const std::string& p, const std::string& e, Address* addr);
    std::string getJob(void);
private:
    std::string m_major;
    uint32_t m_experience;
};

#endif // OOP_OPERATION_H
