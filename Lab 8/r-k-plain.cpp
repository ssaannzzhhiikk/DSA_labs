/*
think we are in situation where we have 
T = "ababcababc"
P = "abc"
And have to find where P is located in T


Основная идея — хэширование подстрок

Алгоритм Рабина–Карпа работает так:

Считаем хэш шаблона hash(P).

Считаем хэш первой подстроки текста той же длины, что и P.

Потом “скользим” по тексту — на каждом шаге обновляем хэш очень быстро (не пересчитывая всю подстроку заново).

Если хэши совпали — возможно, нашли совпадение.
Проверяем посимвольно (на случай коллизии).

*/

#include <bits/stdc++.h>
using namespace std;

const long long BASE = 31;
const long long MOD = 1E9 + 7;

long long computeHash(const string &s){
    long long h = 0;
    for(char c : s)
        h = (h * BASE + (c - 'a' + 1)) % MOD;
    return h;
}


int main(){
    string text = "ababcababc";
    string pattern = "abc";

    int n = text.size(), m = pattern.size();

    long long patternHash = computeHash(pattern);
    long long power = 1;
    for(int i = 0; i < m - 1; i++){
        power = (power * BASE) % MOD;
    }

    long long textHash = computeHash(text.substr(0, m));

    for(int i = 0; i < m - 1; i++){
        if(patternHash == textHash){
            if (text.substr(i, m) == pattern)
                cout << "Found at index " << i << endl;
        }

        if(i < n - m){
            textHash = (textHash - (text[i] - 'a' + 1) * power) % MOD;
            if (textHash < 0) textHash += MOD;
            textHash = (textHash * BASE + (text[i + m] - 'a' + 1)) % MOD;
        }
    }
}