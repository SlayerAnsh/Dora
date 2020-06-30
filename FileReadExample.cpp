#include <bits/stdc++.h>
using namespace std;
#define ll long long int


struct node
{
    char person;
    int time;
    // int date;
    node* next;
};

class List
{
private:
    node *start, *cur;
public:
    List(){
        start = NULL;
        cur = NULL;
    }
    void PushNode(char p, int t){
        node *temp = new node;
        temp->person = p;
        temp->time = t;
        // temp->date = d;
        temp->next = NULL;
        if(start == NULL){
            start = temp;
            cur = temp;
            return;
        }
        cur->next = temp;
        cur = temp;
        return;
    }
    void PrintList(){
        cur = start;
        if(cur==NULL){
            cout<<"List is Empty\n";
            return;
        }
        cout<<cur->person<<"-";
            cout<<cur->time<<"-->";
            // cout<<cur->date<<"----->";
        while(cur->next!=NULL){
            cur=cur->next;
            cout<<cur->person<<"-";
            cout<<cur->time<<"-->";
            // cout<<cur->date<<"----->";
        }
        return;
    }
    
};

int main(){

    freopen("input1.txt","r",stdin);
    freopen("output.txt","w",stdout);

    time_t start, end; 
    time(&start);
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    List Infected[25];
    char infp[17];
    cin>>infp;
    int curid = int(infp[0]) - 65;
    // cout<<curid;
    ifstream file;
    file.open(infp);
    char str[20];
    while(!file.eof()){
        file>>str;
        char p = str[2];
        int t = (int)str[4] - 48;
        // cout<<p<<"\t"<<t<<"\n";
        t = t*10;
        t = t + (int)str[5] - 48;
        // cout<<p<<"\t"<<t<<"\n";

        Infected[curid].PushNode(p,t);
        if(file.eof())
            break;
    }
    Infected[curid].PrintList();



    time(&end);
    double time_taken = double(end - start); 
    cout << "\nTime taken by program is : " << fixed 
         << time_taken << setprecision(5); 
    cout << " sec " << endl; 

    
    return 0;
}

