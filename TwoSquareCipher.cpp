#include "TwoSquareCipher.h"

void ConvertToASCII(string s, vector<int>& WordtoNum)
{
    for (char &c : s) { 
        c = std::tolower(c); 
    }
    for (int i = 0; i < s.length(); i++)
        if (static_cast<int>(s[i]) != 'q') {
            WordtoNum.emplace_back(static_cast<int>(s[i]));
        }
}

void ConvertToASCII_With_Class(string s, vector<Coordinates>& Result)
{
    for (char &c : s) { 
        c = std::tolower(c); 
    }
    for (int i = 0; i < s.length(); i++)
        if (static_cast<int>(s[i]) != 'q') {
            Result[i].ASCIIcode = static_cast<int>(s[i]);
        }
}

void Fill_Secondlayer_With_Alphabet(vector<vector<int>>& A) {
    for (int i = 0; i < 25; i++) {
        if (i < 16) {
            A[1][i] = i + 97;
        }
        else A[1][i] = i + 98;
    }
    for (int i = 0; i < 25; i++)
        A[0][i] = 25;
}

void Fill_Firstlayer_In_Order_Of_String(vector<vector<int>>& A, vector<int> String) {
    for (int leng = 0; leng < String.size(); leng++) {
        for (int i = 0; i < 25; i++) {
            if (String[leng] == A[1][i] && A[0][i] == 25) A[0][i] = leng + 1;
        }
    }
}

void BubbleSort_Firstlayer(vector<vector<int>>& A) {
    for (int j = 0; j < 24; j++)
        for (int i = 0; i < 24 - j; i++)
            if (A[0][i] > A[0][i + 1]) {
                swap(A[0][i], A[0][i + 1]);
                swap(A[1][i], A[1][i + 1]);
            }
}

void Alpahbet_To_AlphabetMatrix(vector<vector<vector<int>>>& AlphabetMatrix, vector<vector<int>>& Alphabet1, vector<vector<int>>& Alphabet2) {
    int k = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            AlphabetMatrix[0][i][j] = Alphabet1[1][k];
            AlphabetMatrix[1][i][j] = Alphabet2[1][k];
            k++;
        }
    }
}

string Encode(string KeyWord1, string KeyWord2, string Message) {
    vector<vector<vector<int>>> AlphabetMatrix(2, vector<vector<int>>(5, vector<int>(5)));
    vector<vector<int>> Alphabet1(2, vector<int>(25));
    vector<vector<int>> Alphabet2(2, vector<int>(25));
    Fill_Secondlayer_With_Alphabet(Alphabet1);
    Fill_Secondlayer_With_Alphabet(Alphabet2);

    Message.erase(remove(Message.begin(), Message.end(), ' '), Message.end());

    vector<int> WordtoNum1; ConvertToASCII(KeyWord1, WordtoNum1);
    vector<int> WordtoNum2; ConvertToASCII(KeyWord2, WordtoNum2);
    vector<Coordinates> RESULT(Message.size());
    ConvertToASCII_With_Class(Message, RESULT);

    Fill_Firstlayer_In_Order_Of_String(Alphabet1, WordtoNum1);
    BubbleSort_Firstlayer(Alphabet1);
    Fill_Firstlayer_In_Order_Of_String(Alphabet2, WordtoNum2);
    BubbleSort_Firstlayer(Alphabet2);

    Alpahbet_To_AlphabetMatrix(AlphabetMatrix, Alphabet1, Alphabet2);

    for (int i = 0; i < Message.size(); i++) {
        for (int row = 0; row < 5; row++) {
            for (int col = 0; col < 5; col++) {
                if (i % 2 == 0 && RESULT[i].ASCIIcode == AlphabetMatrix[0][row][col]) {
                    RESULT[i].x = col;
                    RESULT[i].y = row;
                }
                if (i % 2 == 1 && RESULT[i].ASCIIcode == AlphabetMatrix[1][row][col]) {
                    RESULT[i].x = col;
                    RESULT[i].y = row;
                }
            }
        }
    }

    int temp;
    for (int i = 0; i < Message.size(); i++) {
        if (i % 2 == 0) {
            temp = RESULT[i].x;
            RESULT[i].x = RESULT[i + 1].x;
        }
        if (i % 2 == 1) {
            RESULT[i].x = temp;
        }
    }

    string encodedMessage;
    for (int i = 0; i < Message.size(); i++) {
        if (i % 2 == 0) temp = 0;
        else temp = 1;
        encodedMessage += static_cast<char>(AlphabetMatrix[temp][RESULT[i].y][RESULT[i].x]);
    }

    return encodedMessage;
}

string Decode(string KeyWord1, string KeyWord2, string EncodedMessage) {
    
    return Encode(KeyWord1, KeyWord2, EncodedMessage);
}
