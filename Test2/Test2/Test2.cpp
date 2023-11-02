#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> numbers; 
	string str;            
	int N,  num, q;

	cin >> N;
	cin.ignore();

	getline(cin, str); 
	istringstream ss(str);             
	while (ss >> num)
	{ 
		numbers.push_back(num); 
	}

	sort(numbers.begin(), numbers.end());	

	if (N % 2 == 0)
	{
		q = numbers.at(N / 2 - 1);
	}
	else 
	{
		q = numbers.at(N / 2) ;
	}

	cout << q;	
	return 0;
}