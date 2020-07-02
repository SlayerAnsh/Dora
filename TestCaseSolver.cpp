#include <bits/stdc++.h>
using namespace std;



int main(){

    //comment if using console for input output
    freopen("input1.txt","r",stdin);
    freopen("output.txt","w",stdout);

    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    //opening matrix file present in database
    ifstream file;
    file.open("matrix-02-07-2020.txt");


    // for(int i=0;i<25;i++)
    //     cout<<char(i+65)<<" ";
    // cout<<"\n\n";

    char matrix[24][25];
    for(int i=0;i<24;i++){
        for(int j=0;j<25;j++){
            file>>matrix[i][j];
        }
    }

    //change value according to test case
    char name = 'W';
    int time = 10;

    set<char> infected;
    infected.insert(name);
    for(int i = time;i<24;i++){
        for(int j=0;j<25;j++){
            if(infected.count(matrix[i][j])){
                if(!infected.count(j+65))
                    cout<<char(j+65)<<" ";
                infected.insert(char(j+65));
            }
        }
        cout<<"\n";
    }

    cout<<"\n\n\nList of infected person :\n";
    set<char> :: iterator itr;
    for(itr = infected.begin();itr!=infected.end();++itr)
        cout<<*itr<<" ";    
    return 0;
}

