#include <bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){

    freopen("input1.txt","r",stdin);
    freopen("output.txt","w",stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char c;
    for(int i=0;i<4;i++){
        cin.get(c);
        if(c=='\n')
            continue;
        c = c-32;
        cin.ignore();
        cout<<"D-";
        cout<<c<<"-";
        cout<<setw(2)<<setfill('0')<<i<<"-30-06-2020\n";        
    }

    return 0;
}

