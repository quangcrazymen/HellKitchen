// heapMap.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
bool isPanlindrome(string s) {
	for (int i = 0; i < s.length() / 2; ++i) {
		if (s[i] != s[s.length() - i - 1])
			return false;
	}
	return true;
}
string longestPalindrome(string s) {
	int nlongestSub = 0;
	string longestSubStr;
	for (int i = 0; i < s.length(); ++i) {
		for (int j = i+1; j <= s.length(); ++j) {
			string currentString = s.substr(i, j - i);
			if (isPanlindrome(currentString) and currentString.length() > nlongestSub) {
				nlongestSub = currentString.length();
				longestSubStr = currentString;
			}
		}
	}
	return longestSubStr;
}
struct MyRectangle {
	int height;
	int width;
};
int main()
{
	MyRectangle myRec1{ 2,3 };
	MyRectangle myRec2{ 5,5 };
	// read about longest common substring
	string s = "cbbd";
	cout<<longestPalindrome(s);
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
