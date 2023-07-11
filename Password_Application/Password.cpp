#include "Password.h"

// Ham nhap Password

Password::Password(int l, bool up, bool low, bool num, bool sc)
    : passwordLenght(l), passwordUppercase(up), passwordLowercase(low), passwordNumbers(num), passwordSC(sc) // passwordSC = passwordSpecialCharacters
{}

int Password::showMenu()
{
    int chooseMenu = 0;
    std::cout << "\n" << "==================== Password Application ====================" << endl;
    std::cout << "\n" << "Vui long lua chon do dai password dai hon 8 ki tu !" << endl;
    std::cout << "\n" << "Mat khau nen co chu IN HOA, chu thuong, chu so, ki tu dac biet !" << endl;
    std::cout << "\n" << "1. Do dai cua password ? -> " << passwordLenght << endl;
    std::cout << "2. Ban co muon chu IN HOA khong ? -> ";  (passwordUppercase == true) ? (std::cout << "Yes" << endl) : (std::cout << "No" << endl);
    std::cout << "3. Ban co muon chu chu thuong khong ? -> ";  (passwordLowercase == true) ? (std::cout << "Yes" << endl) : (std::cout << "No" << endl);
    std::cout << "4. Ban co muon chu so khong ? -> ";  (passwordNumbers == true) ? (std::cout << "Yes" << endl) : (std::cout << "No" << endl);
    std::cout << "5. Ban co muon ki tu dac biet khong ? -> ";  (passwordSC == true) ? (std::cout << "Yes" << endl) : (std::cout << "No" << endl);
    std::cout << "6. In ra mat khau" << endl;
    std::cout << "\n" << "==============================================================" << endl;
    std::cout << "\n" << "Hay nhap lua chon cua ban: ";
    std::cin >> chooseMenu;
    std::cin.ignore();
    while (std::cin.fail())
    {
        std::cin.clear(); // Dat lai trang thai
        std::cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Bo qua cac ky tu khong hop le

        std::cout << "\nBan da nhap khong phai so nguyen. Vui long thu lai!\n\nNhan Enter de tiep tuc!";
        getchar();
        return chooseMenu = 0;
    }
    return chooseMenu;
}

int Password::inputLenght()
{
    std::cout << "\n1. Nhap do dai cua password: ";
    std::cin >> passwordLenght;
    std::cin.ignore();
    if (std::cin.fail())
    {
        std::cin.clear(); // Dat lai trang thai
        std::cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Bo qua cac ky tu khong hop le
        std::cout << "\nBan da nhap khong phai so nguyen. Vui long thu lai!\n\nNhan Enter de tiep tuc!";
        getchar();
        return passwordLenght = 0;
    }
    else if ( passwordLenght < 8 )
    {
        std::cout << "Vui long nhap do dai password toi thieu 8 ki tu!\n\nNhan Enter de tiep tuc!";
            
        // Dung chuong trinh thay cho system("pause")
        getchar();
            
        return passwordLenght = 0;
    }
    else return passwordLenght;
}

bool Password::inputUppercase()
{
    int n; // Lua chon Yes or No
    std::cout << "\n" << "2. Ban co muon chu IN HOA khong?\n1. Yes      2. No" << endl;
    std::cout << "Hay nhap lua chon cua ban: ";
    std::cin >> n;
    std::cin.ignore();
    if (std::cin.fail())
    {
        std::cin.clear(); // Dat lai trang thai
        std::cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Bo qua cac ky tu khong hop le
        std::cout << "\nBan da nhap khong phai so nguyen. Vui long thu lai!\n\nNhan Enter de tiep tuc!";
        getchar();
        return passwordUppercase = false;
    }
    switch (n)
    {
    case 1:
        return passwordUppercase = true;
        break;
    case 2:
        return passwordUppercase = false;
        break;
    default:
        std::cout << "Xin hay chon lai!\n" <<
            "\nNhan Enter de tiep tuc!";
        getchar();
        break;
    }
}

bool Password::inputLowercase()
{
    int n; // Lua chon Yes or No
    std::cout << "\n" << "3. Ban co muon chu viet thuong khong?\n1. Yes      2. No" << endl;
    std::cout << "Hay nhap lua chon cua ban: ";
    std::cin >> n;
    std::cin.ignore();
    if (std::cin.fail())
    {
        std::cin.clear(); // Dat lai trang thai
        std::cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Bo qua cac ky tu khong hop le
        std::cout << "\nBan da nhap khong phai so nguyen. Vui long thu lai!\n\nNhan Enter de tiep tuc!";
        getchar();
        return passwordLowercase = false;
    }
    switch (n)
    {
    case 1:
        return passwordLowercase = true;
        break;
    case 2:
        return passwordLowercase = false;
        break;
    default:
        std::cout << "Xin hay chon lai!\n" <<
            "\nNhan Enter de tiep tuc!";
        getchar();
        break;
    }
}

bool Password::inputNumbers()
{
    int n; // Lua chon Yes or No
    std::cout << "\n" << "4. Ban co muon chu so khong?\n1. Yes      2. No" << endl;
    std::cout << "Hay nhap lua chon cua ban: ";
    std::cin >> n;
    std::cin.ignore();
    if (std::cin.fail())
    {
        std::cin.clear(); // Dat lai trang thai
        std::cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Bo qua cac ky tu khong hop le
        std::cout << "\nBan da nhap khong phai so nguyen. Vui long thu lai!\n\nNhan Enter de tiep tuc!";
        getchar();
        return passwordLowercase = false;
    }
    switch (n)
    {
    case 1:
        return passwordNumbers = true;
        break;
    case 2:
        return passwordNumbers = false;
        break;
    default:
        std::cout << "Xin hay chon lai!\nNhan Enter de tiep tuc!";
        getchar();
        break;
    }
}

// Nhap Speacial Characters
bool Password::inputSC()
{
    int n; // Lua chon Yes or No
    std::cout << "\n" << "5. Ban co muon ki tu dac biet khong?\n1. Yes      2. No" << endl;
    std::cout << "Hay nhap lua chon cua ban: ";
    std::cin >> n;
    std::cin.ignore();
    if (std::cin.fail())
    {
        std::cin.clear(); // Dat lai trang thai
        std::cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Bo qua cac ky tu khong hop le
        std::cout << "\nBan da nhap khong phai so nguyen. Vui long thu lai!\n\nNhan Enter de tiep tuc!";
        getchar();
        return passwordSC = false;
    }
    switch (n)
    {
    case 1:
        return passwordSC = true;
        break;
    case 2:
        return passwordSC = false;
        break;
    default:
        std::cout << "Xin hay chon lai!\n\nNhan Enter de tiep tuc!";
        getchar();
        break;
    }    
}

string Password::generateUppercase(std::mt19937& gen)
{
    uniform_int_distribution<int> uni(65, 91);
    return password += char(uni(gen));
}

string Password::generateLowercase(std::mt19937& gen)
{
    uniform_int_distribution<int> uni(97, 123);
    return password += char(uni(gen));
}

string Password::generateNumbers(std::mt19937& gen)
{
    uniform_int_distribution<int> uni(48, 58);
    return password += char(uni(gen));
}

string Password::generateSpecialCharacters(std::mt19937& gen)
{
    uniform_int_distribution<int> uni1(0, 1);
    uniform_int_distribution<int> uni2(58, 65);
    uniform_int_distribution<int> uni3(33, 48);
    return password += ( uni1(gen)==0 ? char(uni2(gen)) : char(uni3(gen)) ); // Bo ki tu dac biet trong ASCII co 2 bo
}

string Password::shufflePassword(std::mt19937& gen)
{
    uniform_int_distribution<int> uni(0, passwordLenght); // Khoang random tu 0 -> lenght

    // Xao tron mat khau
    for (int j = 0; j < passwordLenght; j++)
    {
        int r = uni(gen); // random
        if (password[j] != password[r])
        {
            int temp = password[j];
            password[j] = password[r];
            password[r] = temp;
        }
        else j--;
    }
    return password;
}

string Password::processPassword(std::mt19937& gen)
{
    int i = 0;
    int flag1 = 0, flag2 = 0, flag3 = 0, flag4 = 0; // Check xem mat khau da chua ki tu nay chua ?
    uniform_int_distribution<int> uni(0, 1);
    password.clear(); // xoa du lieu truoc do da nap vap password
    LOOP: while (i < passwordLenght)
    {
        if (passwordUppercase == true)
        {
            flag1 == 0 ? flag1 = 0 : flag1 = uni(gen);
            switch (flag1)
            {
            case 0:
                generateUppercase(gen);
                i++;
                flag1 = 1; // Da chua ki tu
                break;
            case 1: goto LOOP;
            }
        }
            
        if (passwordLowercase == true)
        {
            flag2 == 0 ? flag2 = 0 : flag2 = uni(gen);
            switch (flag2)
            {
            case 0:
                generateLowercase(gen);
                i++;
                flag2 = 1;
                break;
            case 1: goto LOOP;
            }
        }
            
        if (passwordNumbers == true)
        {
            flag3 == 0 ? flag3 = 0 : flag3 = uni(gen);
            switch (flag3)
            {
            case 0:
                generateNumbers(gen);
                i++;
                flag3 = 1;
                break;
            case 1: goto LOOP;
            }
        }

        if (passwordSC == true)
        {
            flag4 == 0 ? flag4 = 0 : flag4 = uni(gen);
            switch (flag4)
            {
            case 0:
                generateSpecialCharacters(gen);
                flag4 = 1;
                i++;
                break;
            case 1: goto LOOP;
            }
        }
    }
    return shufflePassword(gen);
}