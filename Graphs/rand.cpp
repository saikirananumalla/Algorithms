#include<bits/stdc++.h> 
using namespace std; 
int longestSubstring(string s, int n) 
{ 
	unordered_map<int, int> index; 
	int answer = 0; 

	int mask = 0; 
	index[mask] = -1; 

	for(int i = 0; i < n; i++) 
	{ 
		int temp = (int)s[i] - 97; 
		mask ^= (1 << temp); 
		if (index[mask]) 
		{ 
			answer = max(answer, 
						i - index[mask]); 
		} 
		else
			index[mask] = i; 
		for(int j = 0; j < 26; j++) {
			int mask2 = mask ^ (1 << j); 
			if (index[mask2]) 
			{ 
				answer =max(answer, 
							i - index[mask2]); 
			} 
		} 
	} 
	return answer; 
} 
int main () 
{ 
	string s = "aabb";  
	int n = s.size(); 
	cout << (longestSubstring(s, n)); 
} 
