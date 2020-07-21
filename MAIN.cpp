#include <bits/stdc++.h>
using namespace std;

#define MAXID 25	//maximum no of people
#define MAXTIME 24	//maximum range of time

int width = 3;


void FindAll(string filename, string filepath, int infected_time[], int time){
    
    ifstream file;
    file.open(filepath + "/" + filename);
    
    if(!file.is_open()){
        cout<<"ERORR\nData is missing\n";
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
        if(t>=infected_time[int(readline[2])-65]){
            continue;
        }



        cout<<"->"<<"("<<setw(2)<<setfill('0')<<t<<setfill(' ')<<")"<<readline[2];
        width = width + 7;

        //updating infection time to the latest value
        infected_time[int(readline[2])-65] = t;

        //to store the file name
        char temp;
        temp = filename[0];

        //updating file name with the next infected person
        filename[0] = readline[2];
        filepath[8] = readline[2];

        //traversing the next infected person data
        FindAll(filename,filepath, infected_time, t);

        //re-assigning the original file name
        filename[0]=temp;
        filepath[8]=temp;
        cout<<"\n"<<setw(width);

        //in case of EOF is \n
        //in dataset generator the EOF is /n so be carefull
        //try working around this part for bug
        if(file.eof())
            break;       
    }

    //closing file to access it again in future(if needed)
    file.close();
    width = width-7;
    return;
}



int main(){

    //comment if using console for input and output
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    //for fast IO operation
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    //dataset file should be present in Dataset folder in same dir as code
   	string filepath = "Dataset/";

    /*input format
    Which person was infected?
    A
    date one day before he was tested?\t(format DD-MM-YYYY)
    30-06-2020
    */
    char person;
    cout<<"Which Person Was Infected?\n";
    cin>>person;

    //we can easily use while loop to increase interactivity
    //but to keep things simple we simply close the program
    if(person<65||person>89){
    	cout<<"\nWrong ID restart the program\n";
    	return 0;
    }
    filepath = filepath + person;
    string date;
    cout<<"\nDate one day before he was tested?\t(format DD-MM-YYYY)\n\n";
    cin>>date;

    //creating file name char array to access files
    string filename = "";
    filename = filename + person + "-" + date + ".txt";

    cout<<filepath + "/" + filename<<"\n\n";
    ifstream file;
    file.open(filepath + "/" + filename);

    //if Dataset file missing then show error and abort
    if(!file.is_open()){
        cout<<"\nERORR opening the file. Please check the input.\n";
        return 0;
    }

    //array to store when was the ID infected
    int infected_time[MAXID];

    for(int i=0;i<MAXID;i++)
    	infected_time[i] = MAXTIME;

    //starting search from 00 time with the infected person
    infected_time[int(person) - 65] = 0;

    cout<<person;

    FindAll(filename,filepath,infected_time,0);


    cout<<"\n\nList of all the person to quarantine with time of infection (possibility only)\n\n";
    // sort(inftime,inftime + MAXID);
    for(int i=0;i<MAXID;i++){
    	if(infected_time[i]==MAXTIME)
    		continue;
    	cout<<char(65+i)<<" was infected at "<<infected_time[i]<<"\n";
    }

    
    return 0;
}

