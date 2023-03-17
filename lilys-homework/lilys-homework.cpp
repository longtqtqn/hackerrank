#include <bits/stdc++.h>

/*
Code by longtqtqn
*/

using namespace std;

int solveASC(vector<int> arr, map<int, int> m) {
    int count = 0;
    int posOfArr = 0;
    for (map<int, int>::iterator it = m.begin(); it != m.end(); ++it) {
        int posOfNum = it-> second;
        int num = it->first;
        int numInArr = arr[posOfArr];
        if (numInArr != num) {
            m[numInArr] = posOfNum;
            arr[posOfNum] = numInArr;
            ++count;
        }
        ++posOfArr;
    }
    return count;
}

int solveDESC(vector<int> arr, map<int, int> m) {
    int count = 0;
    int posOfArr = arr.size() - 1;
    for (map<int, int>::iterator it = m.begin(); it != m.end(); ++it) {
        int posOfNum = it-> second;
        int num = it->first;
        int numInArr = arr[posOfArr];
        if (numInArr != num) {
            m[numInArr] = posOfNum;
            arr[posOfNum] = numInArr;
            ++count;
        }
        --posOfArr;    
    }
    return count;
}


int main() {
    
    int n;
    vector<int> arr;
    map<int, int> m;
    cin >> n;
    arr.resize(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        m[arr[i]] = i;       
    }
    
    int rsASC = solveASC(arr, m);
    int rsDESC = solveDESC(arr, m);
    
    cout << (rsASC < rsDESC ? rsASC : rsDESC);
}
