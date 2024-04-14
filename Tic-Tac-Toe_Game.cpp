#include <iostream>
#include <limits> // for numeric_limits
#include <cstdlib> // for system("clear") or system("cls")
using namespace std;

const int BOARD_SIZE = 3;
char arr[BOARD_SIZE][BOARD_SIZE] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

int row;
int col;
char currentPlayer = 'X';
bool tie = false;
string u1 = "";
string u2 = "";
void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else9
        system("clear");
    #endif
}
void functionOne() {
     clearScreen();
  
  cout << "   |   |      \n";
  cout << " " << arr[0][0] << " | " << arr[0][1] << " | " << arr[0][2] << " \n";


  cout << "--- --- ---\n";
  
 
  cout << "   |   |      \n";
  cout << " " << arr[1][0] << " | " << arr[1][1] << " | " << arr[1][2] << " \n";
  cout << "--- --- ---\n";
 
  
  cout << "   |   |      \n";
  cout << " " << arr[2][0] << " | " << arr[2][1] << " | " << arr[2][2] << " \n";
}

void functionTwo() {
  int digit;
  bool validInput = false;

    while(!validInput){
        if(currentPlayer == 'X'){
            cout<< u1 <<" please enter(1-9): ";
         }
          else{
              cout<< u2 <<" please enter(1-9): ";
          }
           cin >> digit;
           if(cin.fail() || digit < 1 || digit > 9){
               cout<<"Invalid input. Please enter a number between 1 and 9." << endl;
                cin.clear();
                 cin.ignore(numeric_limits<streamsize>::max(), '\n');
           } else{
               validInput = true;
           }
    }
  
     row = (digit - 1) / BOARD_SIZE; 
      // For row:digit - 1: In this case, 3 - 1 = 2.2 / BOARD_SIZE: Since BOARD_SIZE is 3, 2 / 3 is integer division, which results in 0.
    // So, row will be assigned the value 0.For col:digit - 1: In this case, 3 - 1 = 2.2 % BOARD_SIZE: Since BOARD_SIZE is 3, 2 % 3 results in 2.So, col will be assigned the value 2.

    
    col = (digit - 1) % BOARD_SIZE;
  
  
     if (arr[row][col] != 'X' && arr[row][col] != '0') {
        arr[row][col] = currentPlayer;
        currentPlayer = (currentPlayer == 'X') ? '0' : 'X';
    } else {
        cout << "This space is already taken. Please choose another." << endl;
        functionTwo();
  }
 
}

bool functionThree() {
  for (int i = 0; i < 3; i++) {
    if (arr[i][0] == arr[i][1] && arr[i][0] == arr[i][2] ||
        arr[0][i] == arr[1][i] && arr[0][i] == arr[2][i])
      return true;
  }
  if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] ||
      arr[0][2] == arr[1][1] && arr[0][2] == arr[2][0]) {
    return true;
  }
tie = true;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (arr[i][j] != 'X' && arr[i][j] != '0') {
          tie = false;
        return false;
      }
    }
  }

 
  return true;
}

int main() {

  cout << "                             welcome to Game Tic-Tac-Toe          ";
  cout << endl;
  cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * "
          "* * * * * * * * * * *";
  cout << endl;
  // void function1(){

  cout << "Enter the name of first player: \n";
  getline(cin, u1);
  cout << "Enter the name of second player: \n";
  getline(cin, u2);
  cout << u1 << " is player1 so he/she will play first \n";
  cout << u2 << " is player2 so he/she will play second \n";

  while (!functionThree()) {
    functionOne();
    functionTwo();
    functionThree();
  }

  if (currentPlayer == 'X' && tie == false) {
    cout << u2 << " wins 🎉 "<<endl;
  } else if (currentPlayer == '0' && tie == false) {
    cout << u1 << " wins 🎉 "<<endl;
  } else {
    cout << "Match tied 😅 "<<endl;
  }
}
