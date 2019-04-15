#include<iostream>
using std::cout; using std::cin; using std::endl;
#include<iomanip>
using std::setprecision;
#include<string>
using std::string;
// any other includes you think you might need here
#include <stdio.h>
#include <ctype.h>

// global variable for count -> char code
const string code = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

//
string encode_sequence(string letter_to_encode, char encode_symbol) { 
	//function 1 
	// passes two arguments : a string has thas all of the same characters, and a character (:) to indicate the encoding
	// return is a string 
	//encodes string to run-length encoding for string of same characters
	
	string result;
	int len = letter_to_encode.length(); // find how many letters in string and turn to an integer
	char input_str = letter_to_encode[0]; //takes the first letter

	//if (islower(input_str)) {

		result += encode_symbol;  
		result += code[len - 4]; 
		result += input_str; // last 3 lines concatenate the symbol, the encoded letter, and the original letter

		return result;
}


string encode(string letter_to_encode, char encode_symbol) {
	//function 2
	// pass two arguments - a string to encode and a symbol that indicates an encoding
	//returns a new string
	// does a run legth encoding for the entire string 
	//	encode_sequence i

	char first_letter;
	long count;
	long i = 0;
	string result;
	string encode_sequence;
	while (i < letter_to_encode.length()) { //runs until the loops runs through the last letter in the string
		first_letter = letter_to_encode[i];
		count = 0;
		while (first_letter == letter_to_encode[i]) {
			count++;
			i++;
		}

		if (count < 4) { // this will add all the letters that cannot be encoded together
			for (long j = 0; j < count; j++) {
				encode_sequence = encode_sequence + first_letter;
			}
		}

		if (count > 3) { //this will encode the letters that can be encoded
			encode_sequence += encode_symbol;
			encode_sequence += code[count - 4];
			encode_sequence += first_letter;
		}
	}

	return encode_sequence;

}

string decode_sequence(string letter_to_decode, char encode_symbol) { //function 3
	//pass two arguments - string that has 3 char encode sequence, a symbol that indicates encoding
	//returns a string
	//converts the encoded sequence into its orginal form
	
	string final_result;
	char first_char = letter_to_decode[0];
	char second_char = letter_to_decode[1];
	char third_char = letter_to_decode[2];

	if (islower(second_char)){
			
		int decode_length = (second_char - 'a') + 4; //finding integer value of g for lower case letters
		final_result = string(decode_length, third_char); // it'll repeat what you get from second characcter the amount of times that's needed
	}

	else {
		int decode_length = (second_char - 'A') + 30; //finding integer value of g for upper case letters
		final_result = string(decode_length, third_char);
	}
		
	return final_result;
}


string decode(string letter_to_decode, char encode_symbol) { //function 4
// passes two arguments - string to decode, char used to indicate encoding
//returns string
// does run length-decoding for the entire string
	
	string final_result = letter_to_decode;
	int count = letter_to_decode.size()-1; // returns the amount of characters in the input
	for (count; count >= 0, count--;) { //iterates through the string
			if (encode_symbol == letter_to_decode[count]) {
				string new_result = decode_sequence(letter_to_decode.substr(count,3), encode_symbol); //letter to decode argument takes only substrings of what you want to encode
				final_result.replace(count, 3, new_result);
			}
		}
	return final_result;
}

double reduction(string original_string, string encoded_string) { //function 5
// passes two arguments - orginal string, run length encoded string 
//returns the amount of reduction - ratio sizes	
	
	int original_elements = original_string.size(); //elements in the original string
	int encoded_elements = encoded_string.size();
	double final_result = (static_cast<double>(encoded_elements) / static_cast<double>(original_elements)); // divide encoded string by original string 
	return final_result; //returns final result as double

}


int main() {
	long test_num;
	cin >> test_num;

	switch (test_num) {

	case 1: {
		string input;
		char sep;
		cin >> input;
		cin >> sep;
		cout << encode_sequence(input, sep);
		break;
	}

	case 2: {
		string input;
		char sep;
		cin >> input;
		cin >> sep;
		cout << encode(input, sep);
		break;
	}

	case 3: {
		string input;
		char sep;
		cin >> input;
		cin >> sep;
		cout << decode_sequence(input, sep);
		break;
	}

	case 4: {
		string input;
		char sep;
		cin >> input;
		cin >> sep;
		cout << decode(input, sep);
		break;
	}

	case 5: {
		string s1, s2;
		cin >> s1;
		cin >> s2;
		cout << setprecision(2);
		cout << reduction(s1, s2);
		break;
	}

	} // of switch
}  // of main