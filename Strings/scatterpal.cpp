#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    long long answer = 0;
    string s="ada";
    unordered_map<int, int> m;
    m[0] = 1;
    int x = 0;
    for (auto& c : s) {
        int d = c - 'a';
        x ^= 1 << d;
        answer += m[x];
        cout<<"x is:"<<x<<endl;
        for (int i = 0; i < 26; ++i) {
            cout<<"ans is:"<<answer<<endl;
            answer += m[x ^ (1 << i)];
        }
        m[x] += 1;
    }
    cout << answer << endl;
    return 0;
}
