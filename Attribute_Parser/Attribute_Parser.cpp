//Atribute_Parser.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
 * Atribute_Parser.cpp
 * 
 *   Created on: Jul 7, 2023
 *     Author: The Tuan
 * 
 */
//
#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;

vector<string> g_tagStack; //tag1 tag2 tag 3 ...
map<string, string> g_Attr; //Attribute

/*
    Ham luu name va value cua no
*/
void insertAttr(string& name, string& val)
{
    string full;
    for (string& str : g_tagStack)
        full += str + ".";      //tag1.tag2. (Them dau . sau moi tag)
    full.pop_back();        //tag1.tag2 (xoa dau "." sau cung)
    full += "~" + name;     //tag.tag2~name
    g_Attr[full] = val;
}

int main() 
{
    /*
     n: specifies the number of lines in the HRML source program.  
     q: specifies the number of Queries.
    */
    cout << "===================== Atribute Parser =====================\n" << endl;
    cout << "n: Specifies the number of lines in the HRML source program" << endl;
    cout << "q: Specifies the number of Queries." << endl;
    cout << "===========================================================\n" << endl;
    cout << "\nNhap n va q: ";
    int n = 0, q = 0;
    cin >> n >> q;
    while (n < 1 || q < 1 || cin.fail())
    {
        cin.clear(); // Dat lai trang thai
        cout << "Vui long nhap lai!" << endl;
        cout << "\nNhap n va q: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // xoa tat ca cac ki tu khong hop le
        cin >> n >> q;
    }
    cout << "\nNhap "<< n <<" cu phap cua HRML: " << endl;
    // HRML listing
    for (int i = 0; i < n; i++) 
    {
        char c = 0;
        bool error = false;
        cout << i + 1 << "  ";
        cin >> c;  // Lay ki tu dau tien "<"
        if (c != '<')
        {   
            cin.clear();
            cout << "Ban da nhap sai cu phap. Vui long nhap lai!\n\n";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            i--;
            continue;
        }
        /*
        Kiem tra ki tu tiep theo co phai "/" hay khong
        Neu dung thi dua tag vao stack
        */
        if (cin.peek() == '/')
        {
            string cn;
            cin >> cn;
            g_tagStack.pop_back(); // Xoa ki tu cuoi ">" ( tag1> -> tag1 )
        }
        else
        {
            string name;
            cin >> name; //ten cua tag (VD: tag1, tag2, ...)
            // Check xem tag co value khong?
            if (name.back() == '>') // Check xem chuoi dau tien sau ki tu "<" co phai tag1 > khong ?
            {
                name.pop_back();              // Xoa ki tu cuoi ">" ( tag1> -> tag1 )
                g_tagStack.push_back(name);   // (tag -> stack)
            }
            else
            {
                g_tagStack.push_back(name);     
                while(1)
                {
                    string attr_name, attr_val, eq;
                    cin >> attr_name >> eq >> attr_val; //taking att value & att name
                    cin.ignore();
                    /*
                    "HelloWorld">
                    "HelloWorld"
                    "HelloWorld
                    HelloWorld
                    */
                    if (attr_val.back() == '>') { // Xoa ki tu ">"
                        attr_val.pop_back();
                        attr_val.pop_back();
                        attr_val = attr_val.substr(1);
                        insertAttr(attr_name, attr_val);
                        break;
                    }
                    else 
                    {
                        attr_val.pop_back();
                        attr_val = attr_val.substr(1);
                        insertAttr(attr_name, attr_val);
                    }
                }
            }
        }
    }

    // Queries
    cout << "\nNhap " << n << " cu phap cua Queries: " << endl;
    for (int i = 0; i < q; ++i) {
        string quer;
        cout << i+1 <<"  ";
        cin >> quer;
        if (g_Attr.find(quer) != g_Attr.end())
            cout << " -> " << g_Attr[quer] << endl;
        else
            cout << " -> Not Found!" << endl;
    }
    return 0;
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