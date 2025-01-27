#include<bits/stdc++.h>
using namespace std;

void ground(char *spaces);
void player(char *spaces);
void computer(char *spaces);
bool checkwin(char *spaces);
bool checkdraw(char *spaces);

bool running  = true;
signed main(){
    char spaces[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
    ground(spaces);
    while(running){
        player(spaces);
        checkwin(spaces);
        computer(spaces);
        checkwin(spaces);
        checkdraw(spaces);
    }
}

void ground(char *spaces){
cout<<"     |     |     "<<endl;
cout<<"  "<<spaces[0]<<"  |  "<<spaces[1]<<"  |  "<<spaces[2]<<"   "<<endl;
cout<<"_____|_____|_____"<<endl;
cout<<"     |     |     "<<endl;
cout<<"  "<<spaces[3]<<"  |  "<<spaces[4]<<"  |  "<<spaces[5]<<"   "<<endl;
cout<<"_____|_____|_____"<<endl;
cout<<"     |     |     "<<endl;
cout<<"  "<<spaces[6]<<"  |  "<<spaces[7]<<"  |  "<<spaces[8]<<"   "<<endl;
}
void player(char *spaces){
    int num;
    cout<<"Enter a number: ";
        cin>>num;
        while(num<=0 || num>=10){
            cout<<"Enter a number: ";
            cin>>num;
        }
        
        while(spaces[--num]!=' '){
            cout<<"Enter a number: ";
            cin>>num;
        }
        
        spaces[num] = 'X';
        ground(spaces);
}
void computer(char *spaces){
    cout<<"\n";
    srand(time(0));
    int c = rand()%9;
        --c;
        for(int i=0;i<9;i++){
        if(spaces[c] == ' '){
            spaces[c] = 'O';
            break;
        }
        else{
            c = rand()%9;
        }
        }
    ground(spaces);
    
}
bool checkwin(char *spaces){
    
    if(spaces[0]!= ' ' && spaces[0] == spaces[1] && spaces[1] == spaces[2]){
        running = false;
        return true;
        
    }
    else if(spaces[3]!= ' ' &&spaces[3] == spaces[4] && spaces[4] == spaces[5]){
        running = false;
        return true;
        
    }
    else if(spaces[6]!= ' ' &&spaces[6] == spaces[7] && spaces[7] == spaces[8]){
        running = false;
        return true;
    }
    else if(spaces[0]!= ' ' &&spaces[0] == spaces[3] && spaces[3] == spaces[6]){
        running = false;
    }
    else if(spaces[1]!= ' ' &&spaces[1] == spaces[4] && spaces[4] == spaces[7]){
        running = false;
        return true;
    }
    else if(spaces[2]!= ' ' &&spaces[2] == spaces[5] && spaces[5] == spaces[8]){
        running = false;
        return true;
    }
    else if(spaces[0]!= ' ' &&spaces[0] == spaces[4] && spaces[4] == spaces[8]){
        running = false;
        return true;
    }
    else if(spaces[2]!= ' ' &&spaces[2] == spaces[4] && spaces[4] == spaces[6]){
        running = false;
        return true;
    }
    return false;
}
bool checkdraw(char *spaces){
int i=0;
while(spaces[i]!=' ' && i!=9){
    i++;
}
if(i==9){
    cout<<"Match ends";
    running = false;
}

}