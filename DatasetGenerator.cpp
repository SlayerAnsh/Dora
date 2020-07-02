#include <bits/stdc++.h>
using namespace std;




int main(){

    /*freopen("input1.txt","r",stdin);
    freopen("output.txt","w",stdout);*/

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    
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

            //decrease the modulo to increase interactions probability
            garbage = rand()%10;
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
    char mfilename[] = "C:/Users/Anshu/Desktop/CP/DATASET/matrix-02-07-2020.txt";
    ofstream matfile(mfilename);

    for(int i=0;i<24;i++){
        for(int j=0;j<24;j++){
            matfile<<matrix[j][i]<<" ";
        }
        matfile<<matrix[24][i]<<"\n";
    }

    matfile.close();

    //change the path accordingly
    //dont cahnge the format of file name
    //you can change date accordind to you
    char filename[51] = "C:/Users/Anshu/Desktop/CP/DATASET/A-02-07-2020.txt";
    filename[50] = '\0';

    //creating separate files for each id
    //writing the corresponding matrix data in file
    for(int i=0;i<25;i++){
        filename[34]=i+65;
        ofstream createfile(filename);
        for(int j=0;j<24;j++){
            if(matrix[i][j]=='0')
                continue;
            createfile<<char(i+65)<<'-'<<matrix[i][j];

            //change the date according to the file name manually
            //automisation with minimum use of space will be added in future
            createfile<<'-'<<setw(2)<<setfill('0')<<j<<"-02-07-2020\n";
        }
        
        createfile.close();
    }
    

    
    return 0;
}

