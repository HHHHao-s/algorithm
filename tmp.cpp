#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <set>
#include <algorithm>
#include <future>
#include <thread> // 包含sleep_for
#include <chrono> // 包含chrono_literals
#include <stack>
#include <stdio.h>
using namespace std;

int precedence(char op) {
    if (op == '&') return 2;
    if (op == '|') return 1;
    return 0;
}

bool get(const vector<string>& infix) {
    stack<string> operators;
    vector<string> postfix;

    for (const string& token : infix) {
        if (token == "true" || token == "false") {
            postfix.push_back(token);
        } else if (token == "(") {
            operators.push(token);
        } else if (token == ")") {
            while (!operators.empty() && operators.top() != "(") {
                postfix.push_back(operators.top());
                operators.pop();
            }
            operators.pop(); // pop the '('
        } else {
            while (!operators.empty() && precedence(operators.top()[0]) >= precedence(token[0])) {
                postfix.push_back(operators.top());
                operators.pop();
            }
            operators.push(token);
        }
    }

    while (!operators.empty()) {
        postfix.push_back(operators.top());
        operators.pop();
    }

    stack<bool> s;

    for (const string& token : postfix) {
        if (token == "true") {
            s.push(true);
        } else if (token == "false") {
            s.push(false);
        } else {
            bool val2 = s.top(); s.pop();
            bool val1 = s.top(); s.pop();
            if (token == "&") {
                s.push(val1 && val2);
            } else if (token == "|") {
                s.push(val1 || val2);
            }
        }
    }

    return s.top();
}



int main(){

    int N, m;
    cin >> N >> m;
    string buf;
    getline(cin,buf);
    
    vector<string> exs;
    unordered_map<string ,string> kv;
    for(int i=0;i<N;i++){

        getline(cin ,buf);
        exs.emplace_back(string(buf));
    }
    for(int i=0;i<m;i++){
        string k, v;
        cin >> k >> v;
        kv[k]=v;
    }
    
    for(int l=0;l<N;l++){
        
        vector<string> eval;
        string str= exs[l];
        int n = str.size();
        for(int i=0;i<n;){
            if( str.substr(i, 3)=="AND"){
                eval.emplace_back("&");
                i+=3;
            }else if(str.substr(i, 2)=="OR"){
                eval.emplace_back("|");
                i+=2;
            }else if(str[i]==' '){
                i++;
            }else if(str[i]=='('){
                i++;
                eval.push_back("(");

            }else if(str[i]==')'){
                i++;
                eval.push_back(")");
            }else{
                string k, v;
                for(int j=i;j<n;j++){
                    if(str[j]==' '){
                        k = str.substr(i, j-i);
                        break;
                    }
                }
                for(int j=i;j<n;j++){
                    if(str[j]=='\''){
                        for(int k=j+1;k<n;k++){
                            if(str[k]=='\''){
                                v = str.substr(j+1, k-j-1);
                                i= k+1;
                                break;
                            }
                        }
                        break;
                    }
                
                }
                if(kv.count(k) && (kv[k]==v)){
                    eval.emplace_back("true");
                }else{
                    eval.emplace_back("false");
                }
            }
        }
        bool res = get(eval);
        if(res){
            cout << 0;
        }else{
            cout << 1;
        }
        cout << endl;
    }
}



// 3 2
// error = '1' AND (name = 'NE40' OR name = 'NE20')
// error = '2' AND (name = 'NE40' OR name = 'NE20')
// error = '3' AND (name = 'NE40' OR name = 'NE20')
// name NE40
// error 3
