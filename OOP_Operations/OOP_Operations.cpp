// OOP_Operations.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "OOP_Operations.h"
Address::Address(const std::string& s, const std::string& ci, const std::string& co, const std::string& z)
    : m_street(s), m_city(ci), m_country(co), m_zipCode(z)
{}

void Address::updateAddress(const std::string& s, const std::string& ci, const std::string& co, const std::string& z)
{
    m_street = s;
    m_city = ci;
    m_country = co;
    m_zipCode = z;
}

void Address::printAddress(void)
{
    if (!m_street.empty()) std::cout << "Street: " << m_street << endl;
    if (!m_city.empty()) std::cout << "City: " << m_city << endl;
    if (!m_country.empty()) std::cout << "Country: " << m_country << endl;
    if (!m_zipCode.empty()) std::cout << "Zipcode: " << m_zipCode << endl;
}

Person::Person(const std::string& n ,const std::string& p ,const std::string& e, Address* addr)
    : m_name(n), m_phone(p), m_email(e), addresses(addr)
{}

void Person::printInfo(void)
{
    std::cout << "Name: " << m_name << endl;
    std::cout << "Phone: " << m_phone << endl;
    std::cout << "Email: " << m_email << endl;
}

void Person::updateInfo(const std::string& n, const std::string& p, const std::string& e)
{
    m_name = n;
    m_phone = p;
    m_email = e;
}

std::string Person::getJob(void)
{
    return "Person";
}

Doctor::Doctor(const std::string& n, const std::string& p, const std::string& e, Address* addr)
    : Person(n, p, e, addr)
{}

std::string Doctor::getJob(void)
{
    return "Doctor";
}

Student::Student(const std::string& n, const std::string& p, const std::string& e, Address* addr)
    : Person(n, p, e, addr)
{}

std::string Student::getJob(void)
{
    return "Student";
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
