#ifndef TWOSQUARECIPHER_H
#define TWOSQUARECIPHER_H

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

class Coordinates {
public:
    int ASCIIcode;
    int x;
    int y;
};

void ConvertToASCII(string s, vector<int>& WordtoNum);
void ConvertToASCII_With_Class(string s, vector<Coordinates>& Result);
void Fill_Secondlayer_With_Alphabet(vector<vector<int>>& A);
void Fill_Firstlayer_In_Order_Of_String(vector<vector<int>>& A, vector<int> String);
void BubbleSort_Firstlayer(vector<vector<int>>& A);
void Alpahbet_To_AlphabetMatrix(vector<vector<vector<int>>>& AlphabetMatrix, vector<vector<int>>& Alphabet1, vector<vector<int>>& Alphabet2);
string Encode(string KeyWord1, string KeyWord2, string Message);
string Decode(string KeyWord1, string KeyWord2, string EncodedMessage);
vector<int> stringToAscii (const string& str) ;
string asciiToString(vector<int>& asciiValues);
bool asciiCompare(string& a, string& b);
int binarySearch(const vector<string>& sortedDict, string& input);
string autocomplete(string& input,vector<string>& dictionary);

#endif // TWOSQUARECIPHER_H
