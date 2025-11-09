#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

class Game{
    public:
        void drawBoard(char* spaces){
            cout<<'\n';
            cout<<"     |     |     "<<'\n';
            cout<<"  "<<spaces[0]<<"  ""|""  "<<spaces[1]<<"  ""|""  "<<spaces[2]<<"  "<<'\n';
            cout<<"_____|_____|_____"<<'\n';
            cout<<"     |     |     "<<'\n';
            cout<<"  "<<spaces[3]<<"  ""|""  "<<spaces[4]<<"  ""|""  "<<spaces[5]<<"  "<<'\n';
            cout<<"_____|_____|_____"<<'\n';
            cout<<"     |     |     "<<'\n';
            cout<<"  "<<spaces[6]<<"  ""|""  "<<spaces[7]<<"  ""|""  "<<spaces[8]<<"  "<<'\n';
            cout<<"     |     |     "<<'\n';
            cout<<'\n';
        }

        void playermove(char* spaces, char player){
            int number;
                cout<<"Enter a valid empty space you want to fill(0-8):  "<<'\n';
                cin>>number;
                spaces[number] = player;
        }

        void computermove(char* spaces, char computer){
            int num;
            do{
                srand(time(0));
                num = rand()%9;                  //generates a random number between 0 and 8
                if(spaces[num] == ' ' ){
                    spaces[num] = computer;
                    break;
                }
            }while(spaces[num]!= ' ' );
        }

        int checkwinner(char* spaces){
            if(spaces[0]==spaces[1] && spaces[1]==spaces[2]){
                if(spaces[2]=='X') return 1;
                else if(spaces[2]=='O') return -1;
            }
            else if(spaces[3]==spaces[4] && spaces[4]==spaces[5] ){
                if(spaces[3]=='X') return 1;
                else if(spaces[3]=='O') return -1; 
            }
            else if(spaces[6]==spaces[7] && spaces[7]==spaces[8] ){
                if(spaces[6]=='X') return 1;
                else if(spaces[6]=='O') return -1;
            }
            else if(spaces[0]==spaces[4] && spaces[4]==spaces[8] ){
               if(spaces[0]=='X') return 1;
                else if(spaces[0]=='O') return -1; 
            }
            else if(spaces[2]==spaces[4] && spaces[4]==spaces[6] ){
                if(spaces[2]=='X') return 1;
                else if(spaces[2]=='O') return -1;
            }
            else if(spaces[0]==spaces[3] && spaces[3]==spaces[6] ){
                if(spaces[0]=='X') return 1;
                else if(spaces[0]=='O') return -1;
            }
            else if(spaces[1]==spaces[4] && spaces[4]==spaces[7] ){
                if(spaces[1]=='X') return 1;
                else if(spaces[1]=='O') return -1;
            }
            else if(spaces[2]==spaces[5] && spaces[5]==spaces[8] ){
                if(spaces[2]=='X') return 1;
                else if(spaces[2]=='O') return -1;
            }
            else return 0;
        }   
};

int main(){
    Game tictactoe;
    char player = 'X';
    char computer = 'O';
    char spaces[9]= {' ',' ',' ',' ',' ',' ',' ',' ',' '};
    cout<<"******** WELCOME TO THE TIC TAC TOE GAME ********"<<endl;
    cout<<"******** YOU'RE 'X' & THE SYSTEM IS 'O' *********"<<endl;
    for(int i = 0; i<=2; i++){
        tictactoe.drawBoard(spaces);
        tictactoe.playermove(spaces,player);
        tictactoe.computermove(spaces, computer);
    }
    tictactoe.drawBoard(spaces);
    int result = tictactoe.checkwinner(spaces);
    if(result == 1){
        cout<<"YOU WIN!";
    }
    else if(result == -1){
        cout<<"BETTER LUCK NEXT TIME!";
    }
    else{
        tictactoe.playermove(spaces,player);
        tictactoe.computermove(spaces,computer);
        tictactoe.drawBoard(spaces);
    
        int result2 = tictactoe.checkwinner(spaces);
        if(result2 == 1){
            cout<<"YOU WIN!";
        }
        else if(result2 == -1){
            cout<<"BETTER LUCK NEXT TIME!";
        }
        else cout<<"RETRY THE GAME!";
    }
    return 0;
}