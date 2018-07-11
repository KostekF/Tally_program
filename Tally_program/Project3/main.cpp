/*
[2018 - 05 - 14] Challenge #361[Easy] Tally Program 
from https://www.reddit.com/r/dailyprogrammer/comments/8jcffg/20180514_challenge_361_easy_tally_program/

Description:
5 Friends (let's call them a, b, c, d and e) are playing a game and need to keep track of the scores.
Each time someone scores a point, the letter of his name is typed in lowercase. 
If someone loses a point, the letter of his name is typed in uppercase. 
Give the resulting score from highest to lowest.

Input Description - A series of characters indicating who scored a point. Examples:
abcde
dbbaCEDbdAacCEAadcB

Output Description - The score of every player, sorted from highest to lowest. Examples:
a:1, b:1, c:1, d:1, e:1
b:2, d:2, a:1, c:0, e:-2

Challenge Input:
EbAAdbBEaBaaBBdAccbeebaec
*/
#include<iostream>
#include<utility>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

vector<pair<string, int>> vScore;
string input = "aAAAABBBBccde";

void addOrDeletePoints(char miminum, char maximum, int mathOperation) //mathOperation=-1 for deleting points and =+1 for adding points
{
	string lowerInput(input); 
	transform(input.begin(), input.end(), lowerInput.begin(), ::tolower); //create a string with lower letters for comparing 'if'
	for (int i = 0; i < input.length(); ++i)
	{
		if (input[i] <= maximum && input[i] >= miminum) //if input letter is between our letters(ex.'a','e' or'A','E');
		{
			for (int j = 0; j < vScore.size(); ++j) //Iterate over every element in vector vScore
			{
				if (vScore[j].first == string(1, lowerInput[i])) //Compare if letter in string in vector<string,..> is equal to input letter
				{
					vScore[j].second= vScore[j].second+mathOperation; //add or delete point to/from person with letter a-e
				}
			}
		}
	}
}


bool myOwnSorting(const pair<string, int> &a, const pair<string, int> &b) //Sorting function of int's in vector
{
	return (a.second>b.second); 
}
int main()
{
	//Initalize vector vScore with names(letter from "a" to "e") and their points(everyone starts at 0)
	for (int i = 0; i < 5; ++i)
	{
		vScore.push_back(make_pair(string(1, char(int('a') + i)),0));
	}
	addOrDeletePoints('a','e',1);
	addOrDeletePoints('A', 'E', -1);
	
	sort(vScore.begin(), vScore.end(), myOwnSorting); 

	//Display points of every player(HIGH to LOW)
	for (auto itr = vScore.begin(); itr < vScore.end(); itr++)
	{
		cout << itr->first << " "<<itr->second << endl;
	}

	
	system("pause");
	return 0;
}