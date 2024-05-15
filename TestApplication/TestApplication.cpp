// TestApplication.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <forward_list>
#include <unordered_map>
#include<algorithm>
#include <numeric>
#include <utility>
#include <span>
#include <memory>
#include "MoveSem.cpp"
#include <thread>
//#include "stdafx.h"
#include <Windows.h>
#include < mmintrin.h>
#include <immintrin.h>
//extern "C" void some();
extern "C" void __fastcall asm_func(const char* lpText);
using namespace std;

void bucketSort(vector<int>& arr) {
	int max = *max_element(arr.begin(), arr.end());
	vector<forward_list<int>> bins(max+1);
	for (auto& i : arr) {
		bins[i].push_front(i);
	}
	int index = 0;
	for (auto& i : bins) {
		forward_list<int>::iterator ptr= i.begin();
		while (ptr!=i.end()) {
			arr[index] = *ptr;
			index++;
			ptr++;
		}
	}
}
int minSubArrayLen(int target, vector<int>& nums) {
	int windowStart = 0;
	int windowEnd = 0;
	int currentSum = 0;
	int minWindow = 1e9;
	for (windowEnd; windowEnd < nums.size(); ++windowEnd) {
		currentSum += nums[windowEnd];
		while (currentSum >=target) {
			// only overide if and only if curr < min
			minWindow = min(minWindow, windowEnd - windowStart + 1);
			currentSum -= nums[windowStart];
			windowStart += 1;
		}
	}
	return (minWindow == 1e9) ? 0 : minWindow;
}

// graph using adjacency list
void CreateGraph(vector<vector<int>>& edges, unordered_map<int, vector<int>> adjList) {
}
//
//vector<int> findRedundantConnection(vector<vector<int>>& edges) {
//	
//}

bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
	return true;
}
//void process(MyClass&& rvalueArgument);
 
// try return reference
//int* function(int f) {
//	int g = 90;
//	return &g;
//}
template<typename T, std::size_t length>
void print(std::span<T, length> span) {
	for (auto i : span) {
		std::cout << i << ' ';
	}
	std::cout << '\n';
}
void function(int* pointer, unsigned int size) {
	printf("> ");
	print(std::span{ pointer, size });
}

void hello() {
	std::cout << "Hello World\n" << std::endl;
}
// asm
int main()
{
	asm_func("Hello world!");
	vector<int> a{ 2, 6, 7, 2, 1,14, 6, 13 };
	bucketSort(a);
	forward_list<int> testList{ 1, 3, 6, 2, 3 };
	cout << "distance of the list: " << distance(testList.begin(), testList.end()) << endl;
	for (auto& i : a) {
		cout << i << ' ';
	}
	// contains duplicate
	//unordered_map<int, int> mp;
	//mp[2] = 1;
	//mp[4] = 8;
	//cout << mp.contains(4);
	//vector<int> arr{ 5,1,3,5,10,7,4,9,2,8 };
	//cout << "\nMin sub array:" << minSubArrayLen(15, arr);

	//// int graph
	//vector<vector<int>> edges{ {1,2 }, { 1,3 }, { 2,3 }};
	//unordered_map<int,vector<int>> adjList;
	//CreateGraph(edges,adjList);
	//Holder h(100000);
	//for (int i = 0; i < h.m_size; i++) {
	//	h.m_data[i] = i;
	//}
	//{
	//	Timer time;
	//	Holder copy(h);
	//}
	//cout << endl;
	////int *var = function(20);
	////cout << *var << endl;
	//std::thread myThread([] {hello(); });
	//myThread.join();
	//std::thread my_thread{ hello };
	//my_thread.detach();
	//std::thread t(hello);
	//t.join();

}

// source: https://dennisbabkin.com/blog/?t=cpp-and-assembly-coding-in-x86-x64-assembly-language-in-visual-studio
// https://docs.nvidia.com/hpc-sdk/pgi-compilers/18.4/pdf/pgi18ref-x86.pdf
//https://web.stanford.edu/class/cs107/guide/x86-64.html 

extern "C" UINT GetMsgBoxType()
{
	return MB_YESNOCANCEL | MB_ICONINFORMATION;
}
