#include <iostream>
#include <cstdlib>
#include<ctime>
#include <string>
using namespace std;

const int MAX_LIVES = 5;
void welcome();
void choices();
int wordGuess(char guess, string secretword, string &guessword);

int main()
{
	char choice = 'Y';
	int category = 0;

	// While loop to prompt the user if they want to play again.
	while (toupper(choice) != 'N')
	{
		// Welcome the user to the game and prompts user to enter a number to choose a category of words
		welcome();
		choices();
		char letter;
		int wrong_guesses = 0;
		string word;
		string europe[10] = { "germany","france","austria","italy","switzerland","belgium","norway","iceland","finland","spain" };
		string arab[10] = { "iraq","jordan","syria","palestine","kuwait","oman","bahrain","qatar","lebanon","egypt" };
		string states[10] = { "california","florida","washington","texas","oregon","alabama","missouri","tennessee","idaho" };
		string cars[10] = { "audi","hyundai","chevrolet","ford","ferrari","lamborghini","toyota","honda","volkswagen","porsche" };
		string luxury[10] = { "gucci","versace","balenciaga","fendi","balmain","chanel","hermes","givenchy","burberry","prada" };
		string languages[10] = { "arabic","english","german","french","spanish","japanese","swedish","mandarin","korean","italian" };
		string pets[10] = { "cat","dog","parrot","tortoise","hamster","goldfish","snake","monkey","bunny","squirrel" };

		// Generate a random word from the words array and copy it to word.
		srand(time(NULL));
		int n = rand() % 10;

		cin >> category;
		switch (category)
		{
		case 1:
			system("CLS");
			word = europe[n];
			break;
		case 2:
			system("CLS");
			word = arab[n];
			break;
		case 3:
			system("CLS");
			word = states[n];
			break;
		case 4:
			system("CLS");
			word = cars[n];
			break;
		case 5:
			system("CLS");
			word = luxury[n];
			break;
		case 6:
			system("CLS");
			word = languages[n];
			break;
		case 7:
			system("CLS");
			word = pets[n];
			break;
		default:
			exit;
		}
	
		// This will show *'s in place of the secret word to hide it.
		string unknown(word.length(), '*');

		// While loop to use up a life with each iteration.
		while (wrong_guesses < MAX_LIVES)
		{
			cout << unknown << endl;
			cout << "Guess a letter:  ";
			cin >> letter;
			// Fill secret word with letter if the guess is correct.
			if (wordGuess(letter, word, unknown) == 0)
			{
				cout << endl << "Sorry! Wrong letter. Try again!" << endl;
				wrong_guesses++;
			}
			else
			{
				cout << endl << "Correct letter! Keep going!" << endl;
			}
			// Tell user how many guesses has left.
			cout << "You have " << MAX_LIVES - wrong_guesses;
			cout << " guesses left." << endl << endl;
			// Check if user guessed the word.
			if (word == unknown)
			{
				cout << "The word was " << word << endl << endl;
				cout << "Congratulations!" << endl
					<< "You won. Good job." << endl << endl;
				cout << "Play again? (Y/N)  ";
				cin >> choice;
				system("CLS");
				choices();
				break;
			}
		}
		// When all lives have been used up, the user loses.
		if (wrong_guesses == MAX_LIVES)
		{
			cout << "  _______ " << endl << "  |\t|" << endl;
			cout << "  O\t|" << endl << " /|\\\t|" << endl << "  | \t|" << endl << " / \\\t|" << endl << "________|" << endl << endl;
			cout << "...You have been HANGED." << endl;
			cout << "The word was : " << word << endl;
			cout << "Play again? (Y/N)  ";
			cin >> choice;
			system("CLS");
			//choices();
		}
		cin.ignore();
		
	}
	
	return 0;
}
// ----------
void choices()
{
	cout << "Pick a word category:" << endl
		<< "1) European countries" << endl
		<< "2) Arab countries" << endl
		<< "3) US states" << endl
		<< "4) Car brands" << endl
		<< "5) Luxury clothing brands" << endl
		<< "6) Languages" << endl
		<< "7) Pets" << endl;
}
// Welcome the user.
void welcome()
{
	cout << "---- WELCOME TO THE HANGMAN GAME ----" << endl
		<< "You have " << MAX_LIVES << " tries to guess... or you will be HANGED."
		<< endl << endl;
}
// ----------
// Fills in the unfinished guessword with the letters and returns number of characters matched.
// Returns zero if the character is already guessed.
int wordGuess(char guess, string secretword, string& guessword)
{
	int matches = 0;
	int len = secretword.length();
	for (int i = 0; i < len; i++)
	{
		// Checks to see if the letter was already matched in a previous guess.
		if (guess == guessword[i])
			return 0;
		// Check to see if the letter is in the secret word.
		if (guess == secretword[i])
		{
			guessword[i] = guess;
			matches++;
		}
	}
	return matches;
}
// ----------
