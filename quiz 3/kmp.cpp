/*
Time Complexity: O(n), each character in the pattern
is processed at most twice — once when moving forward (i++)
and possibly again when falling back using the len = lps[len - 1] step.

Auxiliary Space: O(n), an extra array lps[] of size equal to the pattern is used.
*/


#include <bits/stdc++.h>
using namespace std;


vector<int> computeLPS(const string &p){
    int m = p.size(), len = 0;
    vector<int> lps(m);

    for(int i = 1; i< m;){
        if(p[i] == p[len]) lps[i++] = ++len;
        else if(len > 0) len = lps[len - 1];
        else lps[i++] = 0;
    }

    return lps;
}

vector<int> KMP(const string &t, const string &p){
    vector<int> lps = computeLPS(p);
    vector<int> res;

    int i = 0, j = 0, tSize = t.size(), pSize = p.size();

    while(i < tSize){
        if(t[i] == p[j]) {i++; j++;}

        if(j == pSize){
            res.push_back(i - pSize);
            j = lps[j - 1];
        }

        else if(i < tSize && t[i] != p[j]){
            if(j != 0) j = lps[j - 1];
            else i++;
        }
    }
    return res;
}