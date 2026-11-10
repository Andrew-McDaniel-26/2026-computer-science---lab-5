// Andrew McDaniel, Computer Science, NOV/10/26
/* this code purpouse is to genorate a randome number and allow the user to guess it within a selected number of trys, after they runout of guesses or guess correctly
they are given a ranbome messaeg out of ten for winning or lossing and are prompted if they whnat to try again, typing 1 will run the game again, typing 2 will end the program
and give a record of games lost, won, and total games played*/

#include <stdLib.h>
#include <time.h>
#include <iostream>

// my prototypes for the random number game
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
		// this function roll numbers for the switch statments of the random messeges in wins, lossses, and play Again.
		numRoll(a,b,c);
			
		// Rolls the random number for the game
		int ranNum = rand() % 100 + 1;

		// this is the main function that allows guessing and checks the guesses then displays wins, losses, and higher or lower
		guessingGame( a, b, ranNum, wins, losses);
		// this function will prompt the useer if they whant ot play again with one of ten messeges selected randomly
		playAgain(c);
		// this function is what actually allows them to play again
		confirmAgain(rep ,games);

	} while (rep == 1);
	// this function out puts the recorde of games won,lost,and total played
	record(games, wins, losses);
	return 0;
}
//this is the definiton for the function that outputs one of ten randomly selected victory messeges
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
// this definition outputs one of ten randomly selected defeat messeges
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
// this is the definition for the function that out puts one of ten randomly selected messeges for asking if the user whats to playagain
void playAgain(int c)
{
	switch (c)
	{
		case 1: std::cout << "whant to play again ?" << std::endl;
			break;
		case 2: std::cout << "another round ?" << std::endl;
			break;
		case 3: std::cout << "otra vez ?" << std::endl;
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
		case 10:std::cout << "just one more then you can do your homework" << std::endl;
			break;
	}
}
// the def for the function the outputs the recorded wins,losses, and total games played
void record(int games, int wins, int losses)
{

	std::cout << "the number of games played is :" << games << std::endl;
	std::cout << "the number of games won is :" << wins << std::endl;
	std::cout << "the number of games lost is :" << losses << std::endl;
}
// def fro the function that rolls the number to select the messages for wins,losses, and play again
void numRoll(int &a, int &b, int &c)
{
	c = rand() % 10 + 1;
	b = rand() % 10 + 1;
	a = rand() % 10 + 1;
}
// the function def that allows for guessinf then checks the guess and whether or not to continue or stop the current loop and output ether a victory messeg or a defeat message.
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
			//function that out put one ot ten victory messeges selected randomly
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
		// out puts one of ten deffeat messeges selected randomly
		lose(b);
		losses++;
	}

	std::cout << "the random number was " << ranNum << std::endl;
}
// the function def for the function that determins whether or not to run the loop again
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
