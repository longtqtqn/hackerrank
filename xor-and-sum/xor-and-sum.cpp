/**
 * Code by longtqtqn
 */
#include <bits/stdc++.h>

using namespace std;
const int MMOD = 1e9 + 7;

int64_t powMod(int64_t base, int64_t exp, int64_t modulus = MMOD) {
    base %= modulus;
    int64_t result = 1;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % modulus;
        base = (base * base) % modulus;
        exp >>= 1;
    }
    return result;
}
int main() {
    string a, b;
    cin >> a >> b;

    int64_t rs = 0;
    int64_t curA = 0, curNotA = 0, curB = 0;
    int ia = 0;
    int ib = 0;
    int plusAllA = a.size();
    bool plusBGreaterASize = false;
    queue<char> quB;

    if (b.size() > a.size()) {
        while (ib < b.size() - a.size() - 1) {
            curB = (curB * 2 % MMOD + (b[ib] == '1') * powMod(2, a.size())) % MMOD;            
            ++ib;
        }
        quB.push(b[ib]);
        ++ib;
        plusBGreaterASize = true;
    } else if (a.size() > b.size()){
        while (ia < a.size() - b.size()) {
            curA = (curA + (a[ia] == '1') * powMod(2, a.size() - ia - 1)) % MMOD;
            curNotA = (curNotA + (a[ia] == '0') * powMod(2, a.size() - ia - 1)) % MMOD;
            ++ia;
        }      
    }
    
    int realLoop = 314160;
    for (int i = 0; i < realLoop; ++i) {
        char charB = '0';
        if (ib < b.size()) {
            quB.push(b[ib]);
            charB = b[ib];
            ++ib;
        }
        
        if (ia < a.size()) {
            curA = (curA + (a[ia] == '1') * powMod(2, a.size() - ia - 1)) % MMOD;
            curNotA = (curNotA + (a[ia] == '0') * powMod(2, a.size() - ia - 1)) % MMOD;
            ++ia;
        }
        
        if (i < plusAllA) {
            rs = (rs +((charB == '0') ? curA : curNotA)) % MMOD;    
        } else {
            rs = (rs + curA % MMOD) % MMOD;
        }

        if (plusBGreaterASize) {
            char tmp = '0';
            if (!quB.empty()) {
                tmp = quB.front();
                quB.pop();
            }          
            curB = (curB * 2 % MMOD + (tmp == '1') * powMod(2, a.size())) % MMOD;
            rs = (rs + curB) % MMOD;     
        } else {
            if (i + b.size() == a.size()) {
                plusBGreaterASize = true;
            }
        }   
    }
    
    int dup = 1;
    ia = 1;
    if (a.size() > b.size()) {
        ia = a.size() - b.size() + 1;
    }
    while( ia < a.size()) {
        rs = (rs + (a[ia] == '1') * powMod(2, a.size() - ia - 1) * dup % MMOD ) % MMOD;
        ++ia;
        ++dup;
    } 
    
    cout << rs;
}
