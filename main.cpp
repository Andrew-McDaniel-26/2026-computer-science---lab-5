#include <time.h>
#include <stdLib.h>
#include <iostream>


void winner(int a);
void lose(int b);
void playAgain(int c);
void record(int game, int losses, int wins);
void numRoll(int &a, int &b, int &c);
void guessingGame(int a, int b, int ranNum, int &wins, int &losses);
void confirmAgain( int &rep, int &games);


int main()
{
	int c = 0;
	int b = 0;
	int a = 0;
	int rep = 1;
	int games = 0;
	int wins = 0;
	int losses = 0;
	
	srand(time(NULL));
	do
	{
		
		a = 0;
		b = 0;
		c = 0;

		numRoll(a,b,c);
			
		
		int ranNum = rand() % 100 + 1;


		guessingGame( a, b, ranNum, wins, losses);

		playAgain(c);

		confirmAgain(rep ,games);

	} while (rep == 1);
	record(games, wins, losses);
	return 0;
}

void winner(int a)
{
	switch (a)
	{
		case 1: std::cout << "you win" << std::endl;
			break;
		case 2: std::cout << "nice job" << std::endl;
			break;
		case 3: std::cout << "well done" << std::endl;
			break;
		case 4: std::cout << "muy bien" << std::endl;
			break;
		case 5: std::cout << "perfect" << std::endl;
			break;
		case 6: std::cout << "nicely done" << std::endl;
			break;
		case 7: std::cout << "amazing" << std::endl;
			break;
		case 8: std::cout << "ding ding ding" << std::endl;
			break;
		case 9:std::cout << "winner winner" << std::endl;
			break;
		case 10:std::cout << "success" << std::endl;
			break;
	}
}

void lose(int b)
{
	switch (b)
	{
	case 1: std::cout << "you lose" << std::endl;
		break;
	case 2: std::cout << "not quite" << std::endl;
		break;
	case 3: std::cout << "no cigar" << std::endl;
		break;
	case 4: std::cout << "no bien" << std::endl;
		break;
	case 5: std::cout << "sorry you lose" << std::endl;
		break;
	case 6: std::cout << "WRONG!" << std::endl;
		break;
	case 7: std::cout << "so close yet so far" << std::endl;
		break;
	case 8: std::cout << "your good at losing" << std::endl;
		break;
	case 9:std::cout << "winner winner NOT" << std::endl;
		break;
	case 10:std::cout << "successfuly failed" << std::endl;
		break;
	}
}

void playAgain(int c)
{
	switch (c)
	{
		case 1: std::cout << "whant to play again ?" << std::endl;
			break;
		case 2: std::cout << "another round ?" << std::endl;
			break;
		case 3: std::cout << "otra vase ?" << std::endl;
			break;
		case 4: std::cout << "one more game ?" << std::endl;
			break;
		case 5: std::cout << "you can't stop now" << std::endl;
			break;
		case 6: std::cout << "mabe you should take a brake" << std::endl;
			break;
		case 7: std::cout << "you should give it another go" << std::endl;
			break;
		case 8: std::cout << "what do you say one more for old time sake" << std::endl;
			break;
		case 9:std::cout << "you can stop whenever you want" << std::endl;
			break;
		case 10:std::cout << "just one more then tou can do your work" << std::endl;
			break;
	}
}
void record(int games, int wins, int losses)
{

	std::cout << "the number of games played is :" << games << std::endl;
	std::cout << "the number of games won is :" << wins << std::endl;
	std::cout << "the number of games lost is :" << losses << std::endl;
}
void numRoll(int &a, int &b, int &c)
{
	c = rand() % 10 + 1;
	b = rand() % 10 + 1;
	a = rand() % 10 + 1;
}

void guessingGame(int a, int b, int ranNum, int &wins, int &losses)
{
	int trys;
	int max;
	trys = 1;
	std::cout << "set how many geusses do you whant to have out of 20" << std::endl;
	std::cin >> max;
	if (max > 20)
	{
		std::cout << "exceds the max guesses : No Cheating" << std::endl;
		return;
	}
	int x = -1;
	std::cout << "input your guess of a random number for 1 to 100" << std::endl;

	do
	{
		std::cin >> x;
		trys++;
		if (ranNum == x)
		{
			winner(a);
			wins++;
		}
		else
		{
			if (x > ranNum)
			{
				std::cout << "lower, try again" << std::endl;
			}
			else if (x < ranNum)
			{
				std::cout << "higher, try again" << std::endl;
			}


		}

	} while (trys <= max && ranNum != x);
	if (x != ranNum)
	{
		lose(b);
		losses++;
	}

	std::cout << "the random number was " << ranNum << std::endl;
}
void confirmAgain(int &rep, int &games)
{
	int v;
	std::cout << "for another game type 1 : to stop press 2" << std::endl;

	std::cin >> v;

	switch (v)
	{
	case 1: rep = 1;
		break;
	case 2: rep = 2;
		break;
	default: rep = 2;
		break;
	}
	games++;
	
}
