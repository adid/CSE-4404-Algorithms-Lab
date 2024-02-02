#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {

    string s;
    int n;
    cin >> s;
    n= s.size();
    char carray[n];
    
    for (int j = 0; j < n; j++) 
    {
        int value;
        cin >> value;
        array[j] = value;
    }

    sort(array, array+n);

    for(int i=0; i<n;i+=2)
    {
        count+= (array[i+1]-array[i]);
    }
    
    cout << count << endl;
    delete[] array; // free the dynamically allocated array

    return 0;
}
