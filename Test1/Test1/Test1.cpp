#include <iostream>
#include <cctype> 
#include <map>
using namespace std;

int main(){

    string str;
    string mod1, mod2;

    cin >> str >> mod1 >> mod2;
    
    for (char& c : str) 
    {
        c = tolower(c);
    }
    
    map<char, int> countCh;
    for (int i = 0; i < str.size(); i++)
    {
        countCh[str[i]]++;
    }

    char earlier = ' ', later = ' ';
    int max = 0, min = INT_MAX;

    for (const auto& curr : countCh)
    {
        if (mod2 == "earlier")
        {
            if (curr.second > max || (curr.second == max && curr.first < earlier))
            {
                max = curr.second;
                earlier = curr.first;
            }
            if (curr.second < min || (curr.second == min && curr.first < later))
            {
                min = curr.second;
                later = curr.first;
            }
        }
        
        if (mod2 == "later")
        {
            if (curr.second > max || (curr.second == max && curr.first > earlier))
            {
                max = curr.second;
                earlier = curr.first;
            }
            if (curr.second < min || (curr.second == min && curr.first > later))
            {
                min = curr.second;
                later = curr.first;
            }
        }
    }

    if (mod1 == "moreoften")
    {
        cout << max << ' ' << earlier;
    }
    if (mod1 == "lessoften")
    {
        cout << min << ' ' << later;
    }

    return 0;
}