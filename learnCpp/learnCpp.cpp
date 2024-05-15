// learnCpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <vector>
#include <iostream>
#include <string>
#include<unordered_map>
#include <algorithm>
#include <queue>;
#include <unordered_set>
#include <set>
const int INF = 1e8;
using namespace std;
//struct TreeNode {
//	int val;
//	TreeNode* left;
//	TreeNode* right;
//	TreeNode(): val(0),left(nullptr),right(nullptr){}
//	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
//};
//void insertElement(TreeNode* tree, vector<int>& a) {
//	for (auto& i : a) {
//		if (i == NULL) {
//			HelloWorld();
//		}
//	}
//}
int SmallestArraySize(vector<int> &arr,int target){
	int minWindowSize = INT_MAX;
	int currentSum = 0;
	int windowStart = 0;
	for (int windowEnd = 0; windowEnd < arr.size(); windowEnd++) {
		currentSum += arr[windowEnd];
		while (currentSum >= target) {
			minWindowSize = windowEnd - windowStart + 1;
			currentSum -= arr[windowStart];
			windowStart++; 
		}
	}

	return minWindowSize;
}
//int longestSubstringWithK(string a, int k) {
//	unordered_map<const char, int> frequency;
//	int windowStart = 0;
//	int maxWindowSize = INT_MIN;
//	int currentWindowSize = 0;
//	for (int windowEnd = 0; windowEnd < a.length(); ) {
//		while (frequency.size() <= k) {
//			frequency[a[windowEnd]] += 1;
//			currentWindowSize += 1;
//			windowEnd++;	
//		}
//		currentWindowSize--;
//		if(currentWindowSize>maxWindowSize){
//			maxWindowSize = currentWindowSize;
//		}
//		while (frequency.size() > k) {
//			frequency[a[windowStart]] -= 1;
//			windowStart++;
//			currentWindowSize--;
//			frequency.erase(remove_if(frequency.begin(), frequency.end(), [](auto pair) {
//				return pair.second == 0;
//			}),frequency.end());
//		}
//	}
//	return maxWindowSize;
//}
int jump(vector<int>& nums) {
	// using greedy method
	int jumps = 0;
	int curr_end = 0;
	int curr_farthest = 0;

	// loop through each element except for the last one
	for (int i = 0; i < nums.size() - 1; i++) {
		// update curr_farthest with max(curr_farthest, i + nums[i])
		curr_farthest = std::max(curr_farthest, i + nums[i]);

		// if i reaches curr_end (the end of current jump)
		if (i == curr_end) {
			// increment jumps by one (make a new jump)
			jumps++;

			// update curr_end with curr_farthest (the end of next jump)
			curr_end = curr_farthest;
		}
	}

	// return jumps
	return jumps;

}
// bfs k stops
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
	vector<vector<pair<int,int>>>adj(n);
	for (auto& i : flights) {
		adj[i[0]].emplace_back(make_pair(i[1], i[2]));
	}
	// to store a minimum price to reach a node from the src node

	vector<int> dist(n,INF);
	queue<pair<int, int>> qu;
	qu.push(make_pair(src, 0));
	int stops = 0;
	vector<bool> visited(n);
	visited[src] = 1;
	while (!qu.empty() and stops <= k) {
		auto [node,distance] = qu.front();
		qu.pop();
		for (auto& [neighbor,cost] : adj[node]) {
			if (dist[neighbor] > distance + cost and !visited[neighbor]) {
				dist[neighbor] = distance + cost;
				qu.push(make_pair(neighbor, dist[neighbor]));
				visited[neighbor] = 1;
			}
		}
		stops++;
	}
	return dist[dst]!=INF?dist[dst]:-1;
}

double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
	// run time error
	vector<vector<pair<int, double>>>adj(n);
	for (int i=0;i<n;++i) {
		adj[edges[i][0]].emplace_back(make_pair(edges[i][1], succProb[i]));
		adj[edges[i][1]].emplace_back(make_pair(edges[i][0], succProb[i]));
	}
	vector<bool> visited(n);
	queue<pair<int, double>> qu;
	vector<double>final_prob(n, 0);
	visited[start] = 1;
	qu.push(make_pair(start, 1));
	while (!qu.empty()) {
		auto [node, prob] = qu.front();
		qu.pop();
		for (auto& [neighbor, n_prob] : adj[node]) {
			if (!visited[neighbor] and final_prob[neighbor] < n_prob * prob) {
				final_prob[neighbor] = n_prob * prob;
				qu.push(make_pair(neighbor, final_prob[neighbor]));
				visited[neighbor] = 1;
			}
		}
	}
	return final_prob[end];
}

long long fibMemo(int n,vector<long long>& memo) {
	if (n == 1 or n == 2) {
		return 1;
	}
	if (memo[n] > 0) {
		return memo[n];
	}
	long long result = fibMemo(n - 1, memo) + fibMemo(n - 2, memo);
	memo[n] = result;
	return result;
}
// robber with memoization
int rob(int n, vector<int>& memo, vector<int>& nums) {
	if (n < 0) {
		return 0;
	}
	if (memo[n] >= 0) {
		return memo[n];
	}
	int result = max(rob(n - 2,memo,nums) + nums[n], rob(n - 1,memo,nums));
	memo[n] = result;
	return result;
}
int rob(vector<int>& nums) {
	int n = nums.size();
	vector<int> memo(n,-1);
	return rob(n-1,memo, nums);
}

// perfect squares
string shortestPalindrome(string s);
bool isPanlindrome(string s);
bool check(unordered_map<char, int>& charMap);

string minWindow(string s, string t);
bool canFinish(int numCourses, vector<vector<int>>& prerequisites);
int main()
{
	//vector<int> a{ 4,2,1,7,8,1,2,8,1,0};
	////cout << SmallestArraySize(a, 8);
	//	// create an unordered map with some key-value pairs
	//vector<int> test{ 2,3,1,1,4 };
	//cout<<jump(test);
	int n = 4, src = 0, dst = 3, k = 1;
	vector<vector<int>> flights = { {0, 1, 100},{1, 2, 100},{2, 0, 100},{1, 3, 600},{2, 3, 200 }};
	flights = { {0, 1, 1}, {0, 2, 5}, {1, 2, 1}, {2, 3, 1} };
	cout<<findCheapestPrice(n, flights, src, dst, k)<<endl;

	// max prob
	vector<vector<int>> edges{ {0,1},{0,4},{1,2},{1,3},{1,4},{3,4} };
	vector<double> succProb{ 0.7,0.01,0.3,0.2,0.1,0.6 };
	edges = { {0, 1}, {1, 2}, {0, 2}};
	succProb = { 0.5, 0.5, 0.3 };
	cout<<maxProbability(3, edges, succProb, 0, 2);

	// fibonaci but memo
	//int numOfe = 60;
	//vector<long long> memo(numOfe+1, 0);
	//cout<<"\nFibonacci number: "<<fibMemo(numOfe, memo)<<endl;

	// robber
	vector<int>nums{ 2,7,9,3,1 };
	nums = { 1,2,3,1 };
	cout<<"max money: "<<rob(nums)<<endl;

	vector<vector<int>> graph{ {1,2},{2},{0,3},{} };
	//vector<vector<int>> graph{ {1},{} };
	if (canFinish(4, graph)) {
		cout << "TRUE" << endl;
	}
	// topological sort
	
}

void dfs(int currVer,vector<vector<int>>& graph
	,vector<bool>& visited, vector<bool> &stackRec
	,bool &hasCycle) {
	// choose? 
	stackRec[currVer] = 1;
	visited[currVer] = 1;
	for (auto& i : graph[currVer]) {
		if (hasCycle) return;
		else if (!visited[i]) {
			//cout << i << ' ';
			dfs(i, graph, visited, stackRec,hasCycle);
		}
		else if (stackRec[i]) hasCycle = true;
	}

	stackRec[currVer] = 0; // unchoose
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
	// detect cycle in directed graph
	int n = prerequisites.size();
	vector<bool> visited(n,0);
	vector<bool> stackRec(n, 0);
	//visited[0] = stackRec[0] = 1;
	bool hasCycle = 0;

	// check all the forest
	for(int i=0;i<numCourses;++i)
		dfs(0, prerequisites, visited,stackRec,hasCycle);
	if (hasCycle) return false;

	return true;
}

bool check(unordered_map<char,int> &requiredMap,unordered_map<char, int>& charMap) {
	for (auto& i : charMap) {
		if (i.second < requiredMap[i.first]) {
			return false;
		}
	}
	return true;
}

bool initial_check(unordered_map<char, int>& uniSet, unordered_map<char, int>& subset) {
	for(auto&i:subset){
		if (i.second > uniSet[i.first] or uniSet.find(i.first) == uniSet.end())
			return false;
	}
	return true;
}

string minWindow(string s, string t) {
	// check up here
	unordered_map<char,int> uniSet;
	unordered_map<char,int> subset;
	for (auto& i : s) uniSet[i] += 1;
	for (auto& i : t) subset[i] += 1;
	if (!initial_check(uniSet, subset)) return "";
	
	unordered_map<char,int> requiredMap;
	unordered_map<char,int> charMap;
	int currentMinWindow = INT_MAX;
	for (auto& i : t) {
		requiredMap[i] += 1;
	}
	for (auto& i : t) {
		charMap[i] = 0;
	}
	vector<char> container;
	container.reserve(s.length());
	string result;
	int chasingPtr=0;
	int low=0, high=0;
	for (int i = 0; i < s.length();++i) {
		// sliding window
		container.emplace_back(s[i]);
		if(!(charMap.find(s[i])==charMap.end()))
			++charMap[s[i]];
		while (check(requiredMap ,charMap)) {
			if (currentMinWindow > i - chasingPtr) {
				currentMinWindow = i - chasingPtr;
				low = chasingPtr;
				high = i;
			}
			if (!(charMap.find(container[chasingPtr]) == charMap.end()))
				charMap[container[chasingPtr]]--;
				++chasingPtr;
		}
	}
	for (int i = low; i <= high;++i) result += container[i];
	return result;
}

bool isPanlindrome(string s) {
	for (int i = 0; i < s.length()/2;++i) {
		if (s[i] != s[s.length() - i - 1])
			return false;
	}
	return true;
}

string shortestPalindrome(string s) {
	int longestPalindrome = 0;
	for (int i = 0; i < s.length(); ++i) {
		if (isPanlindrome(s.substr(0, i+1)))
			longestPalindrome = i+1;
	}
	string added;
	for (int i = s.length() - 1; i >= longestPalindrome; i--) {
		added += s[i];
	}
	return added + s;
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
