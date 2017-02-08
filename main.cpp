#include <iomanip>
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

vector<int> addCard(const vector<int>&);
int totalCards(const vector<int>&);
void printHand(const vector<int>&);
void runGame();
void hit(vector<int>);
void checkBust(const vector<int>&);
void bust();

int main()
{
	std::cout << "Welcome to my shitty blackjack game.\nPlease press enter to begin!";
	std::cin.get();
	runGame();
	return 0;
}

void runGame()
{
	cout << endl <<"Dealing your hand now..." << endl;
	
	vector<int> hand;
	hand = addCard(hand);
	hand = addCard(hand);
	printHand(hand);
	hit(hand);
	checkBust(hand);
	hit(hand);
	checkBust(hand);
	hit(hand);
	checkBust(hand);
	hit(hand);
	checkBust(hand);
}

vector<int> addCard(const vector<int>& hand)
{
	vector<int> newHand(hand.size() + 1);
	copy(hand.begin(), hand.end(), newHand.begin());
	//srand(time(NULL));
	newHand.back() = rand() % 13 + 1;
	return newHand;
}

int totalCards(const vector<int>& hand)
{
	int total = 0;
	size_t i = hand.size();

	while(i > 0)
	{
		total += hand[i-1];
		--i;
	}
	return total;
}

void printHand(const vector<int>& hand)
{
	std::cout << "Your hand is currently a";
	for(size_t i = 0; i < hand.size() - 1; i++)
		std::cout << " " << hand[i] << ", a";
	std::cout << "nd a " << hand[hand.size() - 1] << ". Totaling " << totalCards(hand);
}

void hit(vector<int> hand)
{
	cout << "\nWould you like to hit? (y/n)" << endl;
	char test;
	cin >> test;
	if(test == 'y'){
		hand = addCard(hand);
		printHand(hand);
	}
	else if(test == 'n')
	{}
	else
	{
		cout << "Invalid input. Please try again.";
		hit(hand);
	}
}

void checkBust(const vector<int>& hand)
{
		if(totalCards(hand) > 21)
			bust();
}

void bust()
{
	char c;
	cout << "You've busted! Would you like to play again? (y/n)";
	cin >> c;
	if(c == 'y'){
		runGame();
	}
	else
	{}
}