#include <bits/stdc++.h>
using namespace std;
#define ll long long int


void FindAll(char filename[], set<char> timerange[], int time){
    ifstream file;
    file.open(filename);
    char readline[18];
    while(!file.eof()){
        file>>readline;

        int t = (int)readline[4] - 48;
        t = t*10;
        t = t + (int)readline[5] - 48;

        if(t<time){
            continue;
        }
        cout<<filename[0]<<"("<<t<<")"<<"->";
        if(timerange[t].count(readline[2])!=0){
            continue;
        }
        for(int i=t;i<24;i++){
            timerange[i].insert(readline[2]);
        }
        char temp;
        temp = filename[0];
        filename[0] = readline[2];
        FindAll(filename, timerange, t);
        filename[0]=temp;
        if(file.eof())
            break;
       
    }
    file.close();
    return;
}



int main(){

    freopen("input1.txt","r",stdin);
    freopen("output.txt","w",stdout);

    // time_t start, end; 
    // time(&start);
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    

    char infp[17];
    cout<<"Which Person Was Infected?\n";
    cin>>infp[0];
    infp[1]='-';
    char* c = new char[10];
    cout<<"date one day before he was tested?\t(format DD-MM-YYYY\n";
    cin>>c;
    for(int i=2;i<12;i++){
        infp[i] = c[i-2];
    }
    infp[12]='.';
    infp[13]='t';
    infp[14]='x';
    infp[15]='t';
    infp[16]='\0';

    delete c;

    set<char> timerange[48];
    cout<<infp<<"\n";
    ifstream file;
    file.open(infp);


    for(int i=0;i<24;i++){
            timerange[i].insert(infp[0]);
    }


    FindAll(infp,timerange,0);






    // time(&end);
    // double time_taken = double(end - start); 
    // cout << "\nTime taken by program is : " << fixed 
    //      << time_taken << setprecision(5); 
    // cout << " sec " << endl; 

    
    return 0;
}

