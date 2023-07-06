// LOC_Counter.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
 * Password_Application.cpp
 *
 *  Created on: Jul 5, 2023
 *      Author: The Tuan
 */
//

#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

string g_filePath, g_folderPath;

string GetFileExtension(const string& filename) {
    size_t dotPos = filename.rfind(".");
    if (dotPos != string::npos && dotPos < filename.length() - 1) {
        return filename.substr(dotPos + 1);
    }
    return "";
}

// Ham xoa khoang trang khi tab
string removeLeadingWhitespace(const string& line) {
    string trimmedLine = line;

    // Xoa cac khoang trang den ki tu dau tien
    auto firstNonWhitespace = find_if(trimmedLine.begin(), trimmedLine.end(), [](unsigned char c) {
        return !isspace(c);
        });

    trimmedLine.erase(trimmedLine.begin(), firstNonWhitespace);

    return trimmedLine;
}

int readFile()
{
    int lineCount = 0;
    string line; //dong trong file

    for (const auto& entry : fs::directory_iterator(g_folderPath)) {
        if (entry.is_regular_file())
        {
            string pathFile = entry.path().string();
            fs::path pathF(pathFile);
            string nameFile = pathF.filename().string();
            string extension = GetFileExtension(nameFile);
            
            // Thuc hien dem dong trong file
            ifstream inputFile(pathFile);
            if (!inputFile.is_open())
            {
                cout << "Error opening input!" << endl;
                return -1;
            }
            if (extension == "c" || extension == "cpp" || extension == "java" || extension == "js")
            {
                while (getline(inputFile, line))
                {
                    // Bo qua cac dong trong
                    if (line.empty())
                    {
                        continue;
                    }
                    // Xoa khoang trang khi tab
                    line = removeLeadingWhitespace(line);
                    // Bo qua cac dong comment /**/
                    if (line[0] == '/' && line[1] == '*')
                    {
                        if ( line[line.length() - 2] == '*' && line[line.length() - 1] == '/')
                        {
                            continue;
                        }
                        else
                        {
                            while(getline(inputFile, line))
                            {
                                line = removeLeadingWhitespace(line);
                                if (line[0] == '*' && line[1] == '/') break;
                                else continue;
                            }
                            continue;
                        }
                    }
                    // Bo qua cac dong comment //
                    if (line[0] == '/')
                    {
                        continue;
                    }
                    // Dem dong
                    lineCount++;
                }
                inputFile.close();
            }
            else if (extension == "html")
            {
                while (getline(inputFile, line))
                {
                    // Bo qua cac dong trong
                    if (line.empty())
                    {
                        continue;
                    }
                    // Xoa khoang trang khi tab
                    line = removeLeadingWhitespace(line);
                    // Bo qua cac dong comment /**/
                    if (line[0] == '<' && line[1] == '!')
                    {
                        if (line[line.length() - 2] == '-' && line[line.length() - 1] == '>')
                        {
                            continue;
                        }
                        else
                        {
                            while (getline(inputFile, line))
                            {
                                line = removeLeadingWhitespace(line);
                                if (line[0] == '-' && line[1] == '-' && line[3] == '>') break;
                                else continue;
                            }
                            continue;
                        }
                    }
                    // Dem dong
                    lineCount++;
                }
                inputFile.close();
            }
            else if (extension == "py")
            {
                while (getline(inputFile, line))
                {
                    // Bo qua cac dong trong
                    if (line.empty())
                    {
                        continue;
                    }
                    // Xoa khoang trang khi tab
                    line = removeLeadingWhitespace(line);
                    // Bo qua cac dong comment /**/
                    if (line[0] == ' " ' && line[1] == ' " ' && line[2] == ' " ')
                    {
                        if (line[line.length() - 1] == ' " ' && line[line.length() - 2] == ' " ' && line[line.length() - 3] == ' " ')
                        {
                            continue;
                        }
                        else
                        {
                            while (getline(inputFile, line))
                            {
                                line = removeLeadingWhitespace(line);
                                if (line[0] == ' " ' && line[1] == ' " ' && line[2] == ' " ') break;
                                else continue;
                            }
                            continue;
                        }
                    }
                    // Bo qua cac dong comment //
                    if (line[0] == '#')
                    {
                        continue;
                    }
                    // Dem dong
                    lineCount++;
                }
                inputFile.close();
            }
            else
            {
                while (getline(inputFile, line))
                {
                    // Bo qua cac dong trong
                    if (line.empty())
                    {
                        continue;
                    }
                    // Xoa khoang trang khi tab
                    line = removeLeadingWhitespace(line);
                    // Bo qua cac dong comment
                    if (line[0] == '#' || line[0] == '/')
                    {
                        continue;
                    }
                    // Dem dong
                    lineCount++;
                }
                inputFile.close();
            }
        }
    }
    cout << "========== TOTAL LINES OF CODE: " << lineCount << " ==========\n" << endl;
    return 0;
}

int main()
{
    while (true)
    {
        cout << "\n========== Line of Code (LOC) Counter ==========\n" << endl;

        cout << "Input path of folder: ";
        cin >> g_folderPath;
        
        fs::current_path(g_folderPath);
        cout << "\n";
        system("dir");
        cout << "\n";
        readFile();
        system("pause");
        return 0;
    }
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