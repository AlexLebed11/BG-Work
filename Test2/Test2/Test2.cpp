#include <iostream>
#include <map>
#include <string>
#include <iterator>
#include <fstream>
#include <windows.h>
#include <sstream>
#include <vector>
using namespace std;

int main()
{
	vector<int> numbers; 
	string str;            
	int N, max, min, num, maxin, minin;

	cin >> N;
	cin.ignore();

	getline(cin, str); 
	istringstream ss(str);             
	while (ss >> num) { numbers.push_back(num); }

	for (int j = 0; j < N / 2 ; j++)
	{
		minin = 0;
		maxin = 0;
		for (int i = 0; i < numbers.size(); i++)
		{	
			if (numbers.size() > 1)
			{
			max = *max_element(numbers.begin(), numbers.end());
			min = *min_element(numbers.begin(), numbers.end());
			if (numbers.at(i) == max)
			{
				maxin = i;	
			}
			else if (numbers.at(i) == min)
			{
				minin = i;
			}
		}
	}
	if (numbers.size() == 2)
	{
		numbers.erase(numbers.begin() + maxin);		
	}	
	else if(maxin < minin)
	{
		numbers.erase(numbers.begin() + minin);
		numbers.erase(numbers.begin() + maxin);
	}
	else if(maxin > minin)
	{
		numbers.erase(numbers.begin() + maxin);
		numbers.erase(numbers.begin() + minin);
	}
	else if (numbers.size() == 1) {}	
	}

	copy(numbers.begin(), numbers.end(),ostream_iterator<int>(cout, " "));
	
	return 0;
}