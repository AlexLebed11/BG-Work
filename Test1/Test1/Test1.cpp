#include <iostream>
#include <map>
#include <string>
#include <iterator>
#include <fstream>
#include <windows.h>
#include <sstream>
#include <vector>
#include <math.h>
using namespace std;


int main()
{
    vector<char> str1;
    vector<char> str2;
    char let[60];
    int num[60];
    string str;
    int calc, freq, pos, pos1, q = 0, tr[60], f = 0;

    cout << "Enter string: ";
    while (getline(cin, str) && !str.empty()) {
        for (char c : str) { str1.push_back(c); str2.push_back(c);
        }
    }


    while (f < 1)
    {
        str = "";
        cout << "Choose moreoften or lessoften letter: ";
        cin >> str;
        if (str == "moreoften") { freq = 0; f = 1; }
        else if (str == "lessoften") { freq = 1; f = 1; }
        else { cout << "Entered invalid value" << endl; f = 0; }
    }
    
    f = 0;

    while (f < 1)
    {
        str = "";
        cout << "Choose earlier or later letter: ";
        cin >> str;
        if (str == "earlier") { pos = 0; f = 1; }
        else if (str == "later") { pos = 1; f = 1; }
        else { cout << "Entered invalid value" << endl; f = 0; }
    }

    auto end = str2.end();
    for (auto it = str2.begin(); it != end; ++it) {
        end = remove(it + 1, end, *it);
    }
    str2.erase(end, str2.end());

    for (int i = 0; i < str2.size(); i++)
    {
        let[i] = str2.at(i);
    }
    
  
    for (int i = 0; i < str2.size(); i++)
    {       
        calc = 0;
        for (int j = 0; j < str1.size(); j++)
        {
            if (let[i] == str1.at(j))
            {
                calc++;
            }
        }
        num[i] = calc;
    }

    if (freq == 0)
    {    
        for (int i = 0; i < str2.size(); i++)
        {
            if (num[i] < num[i + 1])
            {
                freq = i + 1;
            }
        }      
        cout << let[freq] << " " << num[freq];
    }
    else
    {
        for (int i = 0; i < str2.size() - 1; i++)
        {
            if (num[i+1] <  num[i])
            {
                freq = i + 1;
            }
        }
        cout << let[freq] << " " << num[freq];
    }

    return 0;
}