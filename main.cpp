#include <iomanip>
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int addCard();
int totalCards(const vector<int>&);
void printHand(const vector<int>&);
void startGame();

int main()
{
	std::cout << "Welcome to my shitty blackjack game.\nPlease press enter to begin!";
	std::cin.get();
	startGame();
	return 0;
}

void startGame()
{
	cout << endl <<"Dealing your hand now..." << endl;
	int total;
	vector<int> hand(2);
	hand[0] = addCard();
	hand[1] = addCard();
	
	printHand(hand);
	
}

int addCard()
{
	int card;
	srand(time(NULL));
	card = rand() % 13 + 1;
	return card;
}

int totalCards(const vector<int>& hand)
{
	int total;
	for(size_t i = 0; i < hand.size(); i++)
		total += hand[i];
	return total;
}

void printHand(const vector<int>& hand)
{
	std::cout << "Your hand is currently a";
	for(size_t i = 0; i < hand.size() - 1; i++)
		std::cout << " " << hand[i] << ", a";
	std::cout << "nd a " << hand[hand.size()] << ". Totaling " << totalCards(hand);
}