#include <iostream>
#include <map>
#include <string>
#include <iterator>
#include <fstream>
#include <windows.h>
#include <sstream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

map<char, int> groupemin;
map<char, int> groupemax;

void groupNumbers(map<char, int> str, int min, int max, vector<char> str1) {

    for (int i = 0; i < 26; i++)
    {
        if (str.at(str1.at(i))  == min)
        {
            groupemin.at(i) = str.at(str1.at(i));
        }
        if (str.at(str1.at(i)) == max)
        {
            groupemax.at(i) = str.at(str1.at(i));
        }
    }
}

int main(){
     
    string str;
    int  f = 0;

    vector<char> str1;
    vector<char> str2;
    cout << "Enter string: ";
    while (getline(cin, str) && !str.empty()) {
        for (char c : str) 
        {
            if (isupper(c))
            {
                c = tolower(c);
                str1.push_back(c); str2.push_back(c);
            }
            else
            {
                str1.push_back(c); str2.push_back(c);
            }
        }
    }

    int  freq;
    while (f < 1)
    {
        str = "";
        cout << "Choose moreoften or lessoften letter: ";
        cin >> str;
        if (str == "moreoften") { freq = 0; f = 1; }
        else if (str == "lessoften") { freq = 1; f = 1; }
        else { cout << "Entered invalid value" << endl; f = 0; }
    }


    int pos;
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

    sort(str2.begin(), str2.end());
   
    int* num = new int[26] {0};
    for (int i = 0; i < str2.size(); i++)
    {
        for (int j = 0; j < str1.size(); j++)
        {
            if (str2.at(i) == str1.at(j))
            {
                num[i]++;
            }
        }
    }

    map<char, int> let;
    for (int i = 0; i < str2.size(); i++)
    {
        let.insert({ str2.at(i), num[i] });
    }

    int min = 0, max = 0;
    for (int i = 0; i+1 < str2.size(); i++)
    {
        if (num[i] < num[i + 1])
        {
            min = num[i];
        }

        if (num[i] < num[i + 1])
        {
            max = num[i + 1];
        }
    }

    delete[] num;
    num = 0;
   
    groupNumbers(let, min, max, str2);

    if (freq == 0 && pos == 0)
    {
        cout << groupemax.at(0) << " " << max;
    }
    if (freq == 0 && pos == 1)
    {
        cout << groupemax.at(groupemax.at(groupemax.size() - 1)) << " " << max;
    }
    if (freq == 1 && pos == 0)
    {
        cout << groupemin.at(0) << " " << min;
    }
    if (freq == 1 && pos == 1)
    {
        cout << groupemax.at(groupemax.at(groupemax.size() - 1)) << " " << min;
    }

    return 0;
}