// Password_Application.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
 * Password_Application.cpp
 *
 *  Created on: Jul 5, 2023
 *      Author: The Tuan
 */
//
#include <iostream>
#include <cstdlib> //for rand() and srand()
#include <ctime> //for time()
#include <string>

using namespace std;
using std::system;

#define passwordSpecialCharacters pwSC

// Ham nhap Password
class Password
{
public:
    Password(int l, bool up = false, bool low = false, bool num = false, bool sc = false)
        : pwLenght(l), pwUppercase(up), pwLowercase(low), pwNumbers(num), pwSC(sc)
    {}

    int showMenu()
    {
        int chooseMenu;
        cout << "\n" << "==================== Password Application ====================" << endl;
        cout << "\n" << "Vui long lua chon do dai password dai hon 8 ki tu !" << endl;
        cout << "\n" << "Mat khau nen co chu IN HOA, chu thuong, chu so, ki tu dac biet !" << endl;
        cout << "\n" << "1. Do dai cua password ? -> " << pwLenght << endl;
        cout << "2. Ban co muon chu IN HOA khong ? -> ";  (pwUppercase == true) ? (cout << "Yes" << endl) : (cout << "No" << endl);
        cout << "3. Ban co muon chu chu thuong khong ? -> ";  (pwLowercase == true) ? (cout << "Yes" << endl) : (cout << "No" << endl);
        cout << "4. Ban co muon chu so khong ? -> ";  (pwNumbers == true) ? (cout << "Yes" << endl) : (cout << "No" << endl);
        cout << "5. Ban co muon ki tu dac biet khong ? -> ";  (pwSC == true) ? (cout << "Yes" << endl) : (cout << "No" << endl);
        cout << "6. In ra mat khau" << endl;
        cout << "\n" << "==============================================================" << endl;
        cout << "\n" << "Hay nhap lua chon cua ban: ";
        cin >> chooseMenu;
        return chooseMenu;
    }

    int nhapLenght()
    {
        cout << "\n1. Nhap do dai cua password: ";
        cin >> pwLenght;
        if (pwLenght < 8)
        {
            cout << "Vui long lua chon do dai password dai hon 8 ki tu !\n" <<
                    "\nNhan phim bat ki de tiep tuc!" << endl;
            return pwLenght = 0;
            system("pause");
        }
        else return pwLenght;
    }

    bool nhapUppercase()
    {
        int n; // Lua chon Yes or No
        cout << "\n" << "2. Ban co muon chu IN HOA khong?" << "\n" <<
        "1. Yes      2. No" << endl;
        cout << "Hay nhap lua chon cua ban: ";
        cin >> n;
        switch (n)
        {
        case 1:
            return pwUppercase = true;
            break;
        case 2:
            return pwUppercase = false;
            break;
        default:
            cout << "Xin hay chon lai!\n" <<
                    "\nNhan phim bat ki de tiep tuc!" << endl;
            system("pause");
            break;
        }
    }

    bool nhapLowercase()
    {
        int n; // Lua chon Yes or No
        cout << "\n" << "3. Ban co muon chu viet thuong khong?" << "\n" <<
        "1. Yes      2. No" << endl;
        cout << "Hay nhap lua chon cua ban: ";
        cin >> n;
        switch (n)
        {
        case 1:
            return pwLowercase = true;
            break;
        case 2:
            return pwLowercase = false;
            break;
        default:
            cout << "Xin hay chon lai!\n" <<
                    "\nNhan phim bat ki de tiep tuc!" << endl;
            system("pause");
            break;
        }
    }

    bool nhapNumbers()
    {
        int n; // Lua chon Yes or No
        cout << "\n" << "4. Ban co muon chu so khong?" << "\n" <<
        "1. Yes      2. No" << endl;
        cout << "Hay nhap lua chon cua ban: ";
        cin >> n;
        switch (n)
        {
        case 1:
            return pwNumbers = true;
            break;
        case 2:
            return pwNumbers = false;
            break;
        default:
            cout << "Xin hay chon lai!\n" <<
                    "\nNhan phim bat ki de tiep tuc!" << endl;
            system("pause");
            break;
        }
    }

    // Nhap Speacial Characters
    bool nhapSC()
    {
        int n; // Lua chon Yes or No
        cout << "\n" << "5. Ban co muon ki tu dac biet khong?" << "\n" <<
        "1. Yes      2. No" << endl;
        cout << "Hay nhap lua chon cua ban: ";
        cin >> n;
        switch (n)
        {
        case 1:
            return pwSC = true;
            break;
        case 2:
            return pwSC = false;
            break;
        default:
            cout << "Xin hay chon lai!\n" <<
                "\nNhan phim bat ki de tiep tuc!" << endl;
            system("pause");
            break;
        }
    }

private: // pw = password
    int pwLenght; // do dai password
    bool pwUppercase; // chu viet hoa
    bool pwLowercase; // chu viet thuong
    bool pwNumbers; // chu so
    bool pwSC; // ki tu dac biet
};

class XuLi_Pass : public Password
{
public:
    XuLi_Pass(int l, bool up, bool low, bool num, bool sc)
        :Password(l)
    {
        srand(time(NULL));
        string showPass;
        int i = 0; 
        int flag1 = 0, flag2 = 0, flag3 = 0, flag4 = 0; // Check xem mat khau da chua ki tu nay chua ?
        LOOP: while (i < l)
        {
        if (up == true)
        {
            flag1 == 0 ? flag1 = 0 : flag1 = rand() % 2;
            switch (flag1)
            {
            case 0:
                showPass += char(rand() % 26 + 65);
                i++;
                flag1 = 1; // Da chua ki tu
                break;
            case 1: goto LOOP;
            }
        }

        if (low == true)
        {
            flag2 == 0 ? flag2 = 0 : flag2 = rand() % 2;
            switch (flag2)
            {
            case 0:
                showPass += char(rand() % 26 + 97);
                i++;
                flag2 = 1;
                break;
            case 1: goto LOOP;
            }
        }

        if (num == true)
        {
            flag3 == 0 ? flag3 = 0 : flag3 = rand() % 2;
            switch (flag3)
            {
            case 0:
                showPass += char(rand() % 10 + 48);
                i++;
                flag3 = 1;
                break;
            case 1: goto LOOP;
            }
        }

        if (sc == true)
        {
            flag4 == 0 ? flag4 = 0 : flag4 = rand() % 2;
            switch (flag4)
            {
            case 0:
                showPass += ( (rand() % 2) == 0 ? char(rand() % 15 + 33) : char(rand() % 7 + 58) ); // Bo ki tu dac biet trong ASCII co 2 bo
                flag4 = 1;
                i++;
                break;
            case 1: goto LOOP;
            }
        }
    }
    // Xao tron mat khau
    int r; // rand
    for (int j = 0; j < l; j++)
    {
        r = rand() % l;
        if (showPass[j] != showPass[r])
        {
            int temp = showPass[j];
            showPass[j] = showPass[r];
            showPass[r] = temp;
        }
        else j--;
    }
    cout << "\nGenerated password: " << showPass << "\n" << endl;
    }
};

int main()
{
    int l = 0; 
    bool up = false, low = false, num = false, sc = false;
    Password* pw = new Password(0);
    XuLi_Pass* xl_pw = nullptr;
    while (true)
    {
        switch (pw->showMenu())
        {
        case 1:
            l = pw->nhapLenght();
            system("cls");
            break;
        case 2:
            up = pw->nhapUppercase();
            system("cls");
            break;
        case 3:
            low = pw->nhapLowercase();
            system("cls");
            break;
        case 4:
            num = pw->nhapNumbers();
            system("cls");
            break;
        case 5:
            sc = pw->nhapSC();
            system("cls");
            break;
        case 6:
            if (l < 8 && up == false && low == false && num == false && sc == false)
            {
                cout << "\nVui long lua chon do dai password dai hon 8 ki tu !\n" <<
                        "Mat khau nen co chu IN HOA, chu thuong, chu so, ki tu dac biet !\n" <<
                        "\nNhan phim bat ki de tiep tuc!" << endl;
                system("pause");
                system("cls");
                break;
            }
            else if (up == false && low == false && num == false && sc == false)
            {
                cout << "Vui long chon mat khau co cac dieu kien sau day: \n" <<
                        "chu IN HOA, chu thuong, chu so, ki tu dac biet ! \n" <<
                        "\nNhan phim bat ki de tiep tuc!" << endl;
                system("pause");
                system("cls");
                break;
            }
            else if (l < 8)
            {
                cout << "Vui long lua chon do dai password dai hon 8 ki tu !\n" <<
                    "\nNhan phim bat ki de tiep tuc!" << endl;
                system("pause");
                system("cls");
                break;
            }
            else
            {
                xl_pw = new XuLi_Pass(l,up,low,num,sc);
                system("pause");
                system("cls");
                break;
            }
        default:
            cout << "Hay chon menu tu 1 -> 6 !\n" <<
                    "\nNhan phim bat ki de tiep tuc!" << endl;
            system("pause");
            system("cls");
            break;
        }
    }
    return 0;
}