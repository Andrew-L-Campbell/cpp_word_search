//Andrew Campbell
//Project 6 * STL
// 4/24/21
//
//find all words that make up the input word
//

///////////////////////////////

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <ctime>
#include <random>
using namespace std;

void read_words(string text) {
	fstream file;
	int length_words = 3;
	string words;
	string break_down_word;
	vector<string> hold_words;
	vector<string> permutations;// vector to hold all permutations found
	vector<string> sorted;
	int NWORDS = 81483;

	default_random_engine dre(time(nullptr)); // Seed the engine
	uniform_int_distribution<int> di(0, NWORDS); // Use uniform distribution
	int n = di(dre); // Get a random int to get a word to breakdown

	file.open(text);//opening file
	if (!file) {
		cout << "cant open file" << endl;
	}
	while (getline(file, words)) {//making a loop to read each line
		if (words.length() > 2) {//not including anything that is 2 letters long
			hold_words.push_back(words);// adding word to vector
		}
	}
	break_down_word = hold_words.at(n);// selecting the word to break apart
	cout << "The word chosen is: " << break_down_word << endl;
	cout << endl;

	for (auto l : hold_words) {//looping through words
		string temp_letter1 = "";//temp string for mmatching
		string temp_letter2 = "";//temp string for matching
		int match = 0;//starting with zero matches
		int sec_match = 0;
		int thur_match = 0;
		string temp_word;
		for(int i = 0; i <= l.length(); i++) {//checking each letter in txt word
			//cout << break_down_word.find(l[i]) << " letter looking for" << endl;
			if (break_down_word.find(l[0]) == string::npos) {//skipping becuase fist letter does not equal any in word
				break;
			}
			if (break_down_word.find(l[i]) != string::npos){ //checking if same
				match++;
			}
			if (match == l.length()) {//if i gets to the same length of word then its a match
				temp_word = l;
				sort(l.begin(), l.end());//sorted letters
				for (int j = 0; j < l.length(); j++) {//looping through word text to find doubles
					if (l[j] == l[j + 1] ) {//checking if there are doubles
						sec_match++;//counting the double
						temp_letter1 = l[j];//saving the double letter
					}
				}
				for (int k = 0; k < break_down_word.length(); k++) {// looping through random word to find doubles
					sort(break_down_word.begin(), break_down_word.end());//sorting letters
					if (break_down_word[k] == break_down_word[k + 1]) {//checking if there are doubles
						thur_match++;//sounting the doubles
						temp_letter2 = break_down_word[k];//saving letter of the double
					}
				}
				if (sec_match == thur_match && temp_letter1 == temp_letter2) {//checking if double counts and letters match
					permutations.push_back(temp_word);//adding word to vector
					break;
				}
				if (sec_match == 0){// checking if there were no doubles
					permutations.push_back(temp_word);//adding word to vector
					break;
				}
			}
		}
	}
	cout << "Matched words are:\n" << endl; 
	for (auto k : permutations) { // sorting by size adding to new vector
		for (auto p : permutations) {//looping through permutations
			if (p.length() == length_words) {//checking if they are the correct length
				sorted.push_back(p);//if same as current length add to different vector
			}
			
		}
		length_words++;// increment length that is being checked
	}
	for (auto m : sorted) {//printing out sorted list
		cout << m << endl;
	}
}
int main() {//main
	read_words("words.txt");//calling function passing in file name
}