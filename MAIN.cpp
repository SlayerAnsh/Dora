#include <bits/stdc++.h>
using namespace std;


void FindAll(char filename[], set<char> timerange[], int time){
    
    ifstream file;
    file.open(filename);
    
    if(!file.is_open()){
        cout<<"ERORR\n";
        return;
    }
    
    //readline var to read line to line from file
    char readline[18];
    
    while(!file.eof()){

        file>>readline;

        //convertiing two digit char time to int time
        int t = (int)readline[4] - 48;
        t = t*10;
        t = t + (int)readline[5] - 48;

        //if person is not infected at the time contact
        if(t<time){
            continue;
        }
        
        //if we have traced the contacted person already
        if(timerange[t].count(readline[2])!=0){
            continue;
        }

        cout<<"->"<<"("<<t<<")"<<readline[2];

        //updating the timerange from when the person was infected
        for(int i=t;i<24;i++){
            timerange[i].insert(readline[2]);
        }

        //to store the file name
        char temp;
        temp = filename[0];

        //updating file name with the next infected person
        filename[0] = readline[2];

        //traversing the next infected person data
        FindAll(filename, timerange, t);

        //re-assigning the original file name
        filename[0]=temp;
        cout<<"\n";
        cout<<filename[0];

        //in case of EOF is \n
        //in dataset generator the EOF is /n so be carefull
        //try working around this part for bug
        if(file.eof())
            break;       
    }

    //closing file to access it again in future(if needed)
    file.close();
    return;
}



int main(){

    //comment if using console for input and output
    freopen("input1.txt","r",stdin);
    freopen("output.txt","w",stdout);

    //for fast IO operation
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    //dataset file should be present in same dir where this code is
    char infp[17];

    /*input format
    Which person was infected?
    A
    date one day before he was tested?\t(format DD-MM-YYYY)
    30-06-2020
    */
    cout<<"Which Person Was Infected?\n";
    cin>>infp[0];
    infp[1]='-';
    char* c = new char[10];
    cout<<"date one day before he was tested?\t(format DD-MM-YYYY)\n";
    cin>>c;

    //creating file name char array to access files
    for(int i=2;i<12;i++){
        infp[i] = c[i-2];
    }
    infp[12]='.';
    infp[13]='t';
    infp[14]='x';
    infp[15]='t';
    infp[16]='\0';

    delete c;

    //timerange for one day ie 24 hour
    set<char> timerange[24];
    cout<<infp<<"\n";
    ifstream file;
    file.open(infp);

    if(!file.is_open()){
        cout<<"ERORR\n";
        return 0;
    }


    for(int i=0;i<24;i++){
            timerange[i].insert(infp[0]);
    }

    cout<<infp[0];

    FindAll(infp,timerange,0);

    
    return 0;
}

