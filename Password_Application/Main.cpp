// Main.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
 *  Password_Application
 *
 *  Created on: Jul 5, 2023
 *      Author: The Tuan
 */
 //
#include "Header.h"
#include "Password.h"
std::mt19937 gen;
int main()
{
    int l = 0;
    bool up = false, low = false, num = false, sc = false;
    Password* pw = new Password();
    while (true)
    {
        switch (pw->showMenu())
        {
        case 0:
            system("cls");
            break;
        case 1:
            l = pw->inputLenght();
            system("cls");
            break;
        case 2:
            up = pw->inputUppercase();
            system("cls");
            break;
        case 3:
            low = pw->inputLowercase();
            system("cls");
            break;
        case 4:
            num = pw->inputNumbers();
            system("cls");
            break;
        case 5:
            sc = pw->inputSC();
            system("cls");
            break;
        case 6:
            if (l < 8 || up == false && low == false && num == false && sc == false)
            {
                cout << "\nVui long lua chon do dai password dai hon 8 ki tu !" <<
                    "\nMat khau nen co chu IN HOA, chu thuong, chu so, ki tu dac biet !\n" <<
                    "\nNhan Enter de tiep tuc!";
                getchar();
                system("cls");
                break;
            }
            else
            {
                cout << "\nGenerated password: " << pw->processPassword(gen) << "\n\nNhan Enter de tiep tuc!";
                getchar();
                system("cls");
                break;
            }

        default:
            cout << "Hay chon menu tu 1 -> 6 !\n\nNhan Enter de tiep tuc!";
            getchar();
            system("cls");
            break;
        }
    }
    return 0;
}