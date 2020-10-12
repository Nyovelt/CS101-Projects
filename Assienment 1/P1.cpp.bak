#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int num = 0;
    int ans = 0;
    cin >> num;
    stack<int> s;
    stack<int> s1;

    for(int i=0; i<num; i++){
        int input;
        cin >> input;
        int times=1;
        while(!s.empty() && s.top() <= input){
            ans += s1.top();
            if(s.top() == input) times+=s1.top();
            s1.pop();
            s.pop();
        }

        if(!s.empty()) ans++;

        s.push(input);
        s1.push(times);
    }
    cout << ans;
}