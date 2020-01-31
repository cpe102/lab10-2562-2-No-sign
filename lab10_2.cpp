#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;

string cardNames[] = {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
int cardScores[] = {1,2,3,4,5,6,7,8,9,10,10,10,10};
int d;
int drawCard(void){

	return rand()%13;
}

int calScore(int x,int y,int z=0){
	
	return (x+y+z)%10;
	
}
int findYugiAction(int s){	
	if(s == 9) return 2; 
	else if(s < 6) return 1; 
	else{
		srand(time(0));
		d=rand()%100+1;
		if(d<=69){
			return 1;
		}
		else{
			return 2;
		}
	}
}

void checkWinner(int p, int y){
	
	cout << "\n---------------------------------\n";
	if(p>y){
			cout <<   "|         Player wins!!!        |"; 
	}
	else if(p<y){
		cout <<   "|          Yugi wins!!!         |"; 
	}
	else{
		cout <<   "|             Draw!!!           |"; 
	}
	

	
	cout << "\n---------------------------------\n";
}

int main(){	
	srand(time(0));
	int playerScore, yugiScore, playerAction, yugiAction;
	int playerCards[3] = {drawCard(), drawCard(), 0};
	int yugiCards[3]={drawCard(), drawCard(), 0};
	
	
	cout << "---------ORE NO TURN, DRAW!!!------------\n";
	cout << "Your cards: " << cardNames[playerCards[0]] << " " << cardNames[playerCards[1]] << "\n";
	playerScore = calScore(cardScores[playerCards[0]],cardScores[playerCards[1]],0);
	cout << "Your score: " << playerScore << "\n";
	do{
		cout << "(1) Destiny draw (2) Stay, SELECT: ";
		cin >> playerAction;
	}while(playerAction != 1 && playerAction != 2);
	if(playerAction == 1){
		playerCards[2]=drawCard();
		cout << "Player draws the 3rd card!!!" << "\n";
		cout << "Your 3rd card: " <<cardNames[playerCards[2]]<< "\n";
		playerScore = calScore(cardScores[playerCards[0]],cardScores[playerCards[1]],cardScores[playerCards[2]]);
		cout << "Your new score: " <<playerScore<< "\n";
		
	}
	else if(playerAction == 2){
		;
	}
	
	cout << "------------ Turn end -------------------\n\n";
	


	cout << "---------YUGI'S TURN, DRAW!!!------------\n";
	
	cout << "Yugi's cards: " <<cardNames[yugiCards[0]]<<" "<<cardNames[yugiCards[1]]<< "\n";
	yugiScore = calScore(cardScores[yugiCards[0]],cardScores[yugiCards[1]],0);
	cout << "Yugi's score: " << yugiScore << "\n";
	yugiAction = findYugiAction(yugiScore);
	if(yugiAction == 1){
		yugiCards[2]=drawCard();
		cout << "Yugi draws the 3rd card!!!\n";
		cout << "Yugi's 3rd card: " <<cardNames[yugiCards[2]]<<"\n";
		yugiScore = calScore(cardScores[yugiCards[0]],cardScores[yugiCards[1]],cardScores[yugiCards[2]]);
		cout << "Yugi's new score: " <<yugiScore<< "\n";
	}
	cout << "------------ Turn end -------------------\n";

	
	checkWinner(playerScore,yugiScore);
	return 0;
}
