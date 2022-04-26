#include <bits/stdc++.h>

using namespace std;

map<string, string> dict;

void solve(int &n, string prefix){
    if (n == 0) return;
    string hrml, tag, attr, value, text;
    getline(cin, hrml);
    if (hrml.find("/") != string::npos){
        int tagLen = hrml.length() - 3;
        string tmp = hrml.substr(hrml.find("/")+1, tagLen);
        int i = prefix.find(tmp);
        if (i+tagLen > prefix.length()-1)
            tag = prefix.substr(0, i);
        else
            tag = prefix.substr(0, i) + prefix.substr(i+tagLen+1);
        if (tag[tag.length()-1] == '.')
            tag = tag.substr(0, tag.length()-1);
        n--;
        solve(n, tag);
    }
    else{
        stringstream ss(hrml);
        while (getline(ss, text, ' ')){
            if (text == "=") continue;
            if (text.find("<") != string::npos){
                if (prefix == ""){ // todo: custom tag name
                    tag = text.substr(1);
                }
                else {
                    tag = prefix + "." + text.substr(1); // tag1.tag2
                }
                if (tag[tag.length()-1] == '>')
                    tag = tag.substr(0, tag.length()-1);
            }
            else if (text.find("\"") != string::npos){
                value = text.substr(text.find("\"")+1, text.rfind("\"")-text.find("\"")-1); // value of attr
                dict[tag + "~" + attr] = value;
            }
            else{
                attr = text;
            }
        }
        n--;
        solve(n, tag);
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, q;
    cin >> n >> q;
    cin.ignore();
    
    solve(n, "");
    
    for (int i = 0; i < q; i++){
        string query;
        getline(cin, query);
        if (dict.count(query)){
            cout << dict[query] << "\n";
        }
        else{
            cout << "Not Found!\n";
        }
    }
    /*
    for (auto m: dict){
        cout << m.first << " " << m.second << "\n";
    }*/
    return 0;
}
