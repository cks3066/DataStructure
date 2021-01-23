#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main()
{
	int N, max = 0;
	string str;

	unordered_map<string, int> wordFreq;
	cin >> N;
	cin >> str;

	string word;
	for (int i = 0; i < (int)str.length() - N; i++)
	{
		word = str.substr(i, N);
		wordFreq[word]++;
	}
	unordered_map<string, int>::iterator p;
	for (p = wordFreq.begin(); p != wordFreq.end(); p++)
	{
		if (p->second >= max) {
			max = p->second;
			word = p->first;
		}
	}
	cout << word << endl;

	return 0;
}
