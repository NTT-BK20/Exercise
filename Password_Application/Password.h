#pragma once

#ifndef PASSWORD_H
#define PASSWORD_H

#include "Header.h"
// Khai bao ham
class Password
{
public:
	Password(int l = 0, bool up = false, bool low = false, bool num = false, bool sc = false);
	int showMenu();
	int inputLenght();
	bool inputUppercase();
	bool inputLowercase();
	bool inputNumbers();
	bool inputSC();
	string generateUppercase(std::mt19937& gen);
	string generateLowercase(std::mt19937& gen);
	string generateNumbers(std::mt19937& gen);
	string generateSpecialCharacters(std::mt19937& gen);
	string shufflePassword(std::mt19937& gen);
	string processPassword(std::mt19937& gen);
private: // password = password
	int passwordLenght; // do dai password
	bool passwordUppercase; // chu viet hoa
	bool passwordLowercase; // chu viet thuong
	bool passwordNumbers; // chu so
	bool passwordSC; // ki tu dac biet ( passwordSC = passwordSpecialCharacters )
	string password;
};

#endif 