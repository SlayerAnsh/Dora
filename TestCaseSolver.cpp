#include <bits/stdc++.h>
using namespace std;



int main(){

    //comment if using console for input output
    freopen("output.txt","w",stdout);

    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    //opening matrix file present in database
    ifstream file;
    file.open("Dataset/matrix/matrix-02-07-2020.txt");


    

    char matrix[24][25];
    for(int i=0;i<24;i++){
        for(int j=0;j<25;j++){
            file>>matrix[i][j];
        }
    }

    // for(int i = 0;i<24;i++){
    // 	for(int j=0;j<25;j++)
    // 		cout<<matrix[i][j]<<" ";
    // 	cout<<"\n";
    // }

    // cout<<"\n\n";

    cout<<"  |";

    for(int i=0;i<25;i++)
        cout<<char(i+65)<<"|";
    cout<<"\n";

    //change value according to test case
    char name = 'C';
    int time = 0;

    set<char> infected;
    infected.insert(name);
    for(int i = time;i<24;i++){
    	cout<<setw(2)<<setfill('0')<<i<<"|";
        for(int j=0;j<25;j++){
            if(infected.count(char(j+65))){
                if(!infected.count(matrix[i][j])&&(matrix[i][j]!='0')){
                    cout<<matrix[i][j];
                	infected.insert(matrix[i][j]);
                }
                else
            		cout<<"_";
                
            }
            else
            	cout<<"_";
            
            cout<<"|";
        }
        cout<<"\n";
    }

    cout<<"\n\n\nList of infected person :\n";
    set<char> :: iterator itr;
    for(itr = infected.begin();itr!=infected.end();++itr)
        cout<<*itr<<" ";    
    return 0;
}

