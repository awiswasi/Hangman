#include <iostream>
#include <cstdlib>
#include<ctime>
#include <string>
using namespace std;

const int MAX_LIVES = 5;
void welcome();
int wordGuess(char guess, string secretword, string &guessword);

int main()
{
	char letter;
	int wrong_guesses = 0;
	string word;
	string words[10] = { "germany","france","austria","italy","switzerland","belgium","norway","iceland","finland","spain" };

	//choose and copy a word from array of words randomly
	srand(time(NULL));
	int n = rand() % 10;
	word = words[n];

	// This will show *'s in place of the secret word to hide it
	string unknown(word.length(), '*');

	welcome();

	// While loop to use up a life with each iteration
	while (wrong_guesses < MAX_LIVES)
	{
		cout << unknown << endl;
		cout << "Guess a letter:  ";
		cin >> letter;
		// Fill secret word with letter if the guess is correct,
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
			break;
		}
	}
	if (wrong_guesses == MAX_LIVES)
	{
		cout << "  _______ " << endl << "  |\t|" << endl;
		cout << "  O\t|" << endl << " /|\\\t|" << endl << "  | \t|" << endl << " / \\\t|" << endl << "________|" << endl << endl;
		cout << "...You have been HANGED." << endl;
		cout << "The word was : " << word << endl;
	}
	cin.ignore();
	cin.get();
	return 0;
}
// ----------
// Welcome the user.
void welcome()
{
	cout << "---- WELCOME TO THE HANGMAN GAME ----" << endl
		<< "Guess the European country!" << endl
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
