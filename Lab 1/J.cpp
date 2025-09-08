#include <bits/stdc++.h>
using namespace std;
int main(){
    deque<int> dq;
    queue<string> qu;
    bool stop = true;
    while(stop){
        char sign;
        cin >> sign;
        if (sign == '!'){
            break;
        }
        else if(sign == '+'){
            int num;
            cin >> num;
            dq.push_front(num);
        }
        else if(sign == '-'){
            int num;
            cin >> num;
            dq.push_back(num);
        }
        else if(sign == '*'){
            if(dq.empty()){
                qu.push("error");
            } else if(dq.size() == 1){
                qu.push(to_string(dq.front() * 2));
                dq.pop_back();
            } else {
                qu.push(to_string(dq.front() + dq.back()));
                dq.pop_back();
                dq.pop_front();
            }
            
        }
    }
    while(!qu.empty()){
        cout << qu.front() << endl;
        qu.pop();
    }
}