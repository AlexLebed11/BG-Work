#include <iostream>
#include <map>
#include <string>
#include <iterator>
#include <fstream>
#include <windows.h>
#include <sstream>
#include <vector>

using namespace std;



struct Node1 {
    int value1;
    Node1* left1;
    Node1* right1;
};

struct Node2 {
    int value2;
    Node2* left2;
    Node2* right2;
};



int main()
{
    string str;
    vector<int> tree1;
    vector<int> tree2;
    int step[2];
    int count = 0;



    getline(cin, str); //считали строку из файла в str
    stringstream ss(str); //создали строковый поток, в который поместили str
    while (getline(ss, str, ' ')) //считываем в переменную str из потока символы разделенные пробелами
    {
        if (str != "null")
        {
            tree1.push_back(stoi(str)); //Добавляем в вектор число. Stoi(str) - преобразует строку в число.
        }
        else
        {
            tree1.push_back(NULL);
        }
    }

    getline(cin, str); //считали строку из файла в str
    stringstream sss(str); //создали строковый поток, в который поместили str
    while (getline(sss, str, ' ')) //считываем в переменную str из потока символы разделенные пробелами
    {
        if (str != "null")
        {
            tree2.push_back(stoi(str)); //Добавляем в вектор число. Stoi(str) - преобразует строку в число.
        }
        else
        {
            tree2.push_back(NULL);
        }
    }



    vector<Node1> TREE1;
    Node1 a;
    for (int i = 0, j = 0; i < tree1.size() / 2 && j < tree1.size(); i++, j++)
    {
        if (i == 0)
        {
            Node1* leftch1 = 0;
            Node1* rightcg1 = 0;
            a.value1 = tree1.at(i);
            leftch1->value1 = tree1.at(i + 1);
            a.left1 = leftch1;
            rightcg1->value1 = tree1.at(i + 2);
            a.right1 = rightcg1;

            TREE1.push_back(a);
        }
        else if (i > 0)
        {
            Node1* leftch1 = 0;
            Node1* rightcg1 = 0;
            a.value1 = tree1.at(i);
            leftch1->value1 = tree1.at(2*j + 1);
            a.left1 = leftch1;
            rightcg1->value1 = tree1.at(2 * j + 2);
            a.right1 = rightcg1;

            TREE1.push_back(a);
        }
    }

    vector<Node1> TREE2;
    Node2 b;
    for (int i = 0, j = 0; i < tree2.size() / 2 && j < tree2.size(); i++, j++)
    {
        if (i == 0)
        {
            Node2* leftch2 = 0;
            Node2* rightcg2 = 0;
            b.value2 = tree2.at(i);
            leftch2->value2 = tree2.at(i + 1);
            b.left2 = leftch2;
            rightcg2->value2 = tree2.at(i + 2);
            b.right2 = rightcg2;

            TREE2.push_back(a);
        }
        else if (i > 0)
        {
            Node2* leftch2 = 0;
            Node2* rightcg2 = 0;
            b.value2 = tree2.at(i);
            leftch2->value2 = tree2.at(2 * j + 1);
            b.left2 = leftch2;
            rightcg2->value2 = tree2.at(2 * j + 2);
            b.right2 = rightcg2;

            TREE2.push_back(a);
        }
    }

        if (a.value1 == b.value2)
        {
            cout << "YES";
        }
        else { cout << "NO"; }

 
    return 0;
}