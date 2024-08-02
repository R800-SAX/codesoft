#include<iostream>
#include<stdlib.h>
#include<ctime>

using namespace std;

int main() {

srand(static_cast<unsigned int>(time(nullptr)));

int numbertoGuess = rand() % 100+1;
int guess;
int attempts = 0;
bool guessedCorrectly = false;

cout<<"Welcome to Guess the number game"<<endl;
cin>>guess;

while(!guessedCorrectly){
    cout<<"Enter your guess: ";
    cin>>guess;
    attempts++;

    if(guess < numbertoGuess){
        cout<<"Too Low! Try Again\n";
        }else if (guess > numbertoGuess){
         cout<<"Too High! Try Again\n";
         }else{
         cout<<"Congratulations!  You have gueesed the number"<<numbertoGuess<<"correctly in"<< attempts<<"attempts\n"<<endl;
         guessedCorrectly = true;
        }
}
return 0;

}

