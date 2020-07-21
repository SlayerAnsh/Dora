#include <bits/stdc++.h>
#include <sys/types.h>
#include <sys/stat.h>
using namespace std;




int main(){


    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    mkdir("Dataset",0777);
    
    
    int value;

    //matrix to store interactions
    //row denote time of day and column denote id of person
    char matrix[25][24];

    //initialising matrix with '0'
    //its used to determine a person is free or not when assigning
    for(int i=0;i<24;i++){
        for(int j=0;j<25;j++){
            matrix[j][i]='0';
        }
    }

    //randomising rand() function by giving time as seed
    srand(time(0));
    int garbage;

    //matric generator
    for(int i=0;i<24;i++){
        for(int j=0;j<25;j++){
            value = rand()%25;

            //decrease the modulo in garbage to increase interactions probability
            garbage = rand()%20;
            if(garbage)
                continue;

            //if both are free then only we can assign them
            //also a person cant meet himself
            if((matrix[j][i]=='0')&&(matrix[value][i]=='0')){
                if(value == j)
                    continue;
                matrix[j][i] = value + 65;
                matrix[value][i] = j + 65;
            }
        }
    }

    //file to store matrix
    //change date to ur choice
    string filepath = "Dataset/matrix";
    string date = "02-07-2020";
    string filename = "matrix-" + date + ".txt";
    mkdir(filepath.c_str(),0777);
    ofstream file;
    file.open(filepath + "/" + filename);

    for(int i=0;i<24;i++){
        for(int j=0;j<24;j++){
            file<<matrix[j][i]<<" ";
        }
        file<<matrix[24][i]<<"\n";
    }

    file.close();

    //change the path accordingly
    //dont cahnge the format of file name
    //you can change date accordind to you
    filepath.clear();
    filename.clear();
    filepath = "Dataset/A";
    filename = "A-" + date + ".txt";


   

    //creating separate files for each id
    //writing the corresponding matrix data in file
    for(int i=0;i<25;i++){
        filepath[8]=i+65;
        filename[0]=i+65;
        mkdir(filepath.c_str(),0777);
        file.open(filepath + "/" + filename);
        for(int j=0;j<24;j++){
            if(matrix[i][j]=='0')
                continue;
            file<<char(i+65)<<'-'<<matrix[i][j];

            //change the date according to the file name manually
            //automisation with minimum use of space will be added in future
            file<<'-'<<setw(2)<<setfill('0')<<j<<"-"<<date<<"\n";
        }
        
        file.close();
    }
    

    
    return 0;
}

