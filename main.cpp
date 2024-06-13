#include "TwoSquareCipher.h"

int main() {
    int input;

    vector<std::string> dictionary = {
        "apple", "banana", "example", "keyword", "minh",
    };

    string KeyWord1, KeyWord2, Message,InputString;
    int choice;
    cout << "Choose an option:\n1. Encode\n2. Decode\n";
    cin >> choice;
    cin.ignore();
    
    cout << "Do you want turn suggestin on: \n 1.yes\n2.no \n ";
    cin >>input;
    if(input==0){
    cout << "Enter the first keyword: ";
    getline(cin, KeyWord1);
    cout << "Enter the second keyword: ";
    getline(cin, KeyWord2);
    cout << "Enter the message: ";
    getline(cin, Message);
    
    }


    if(input==1){
    cout << "Enter the first keyword: ";
    while(1){
    getline(cin, InputString);
    string suggestion = autocomplete(InputString , dictionary);
    cout << "suggestion :"<<suggestion;
    cout << "Do you want to use it as keyword: \n 1.yes\n2.no \n ";
    cin >>input;
    if(input==1) {KeyWord1=suggestion;break;}
    else{cout << "Nhap lai";}
    }
    while(1){
    cout << "Enter the second keyword: ";
    getline(cin, InputString);
    string suggestion = autocomplete(InputString , dictionary);
    cout << "suggestion :"<<suggestion;
    cout << "Do you want to use it as keyword: \n 1.yes\n2.no \n ";
    cin >>input;
    if(input==1) {KeyWord2=suggestion;break;}
    else{cout << "Nhap lai";}
    }
    cout << "Enter the message: ";
    getline(cin, Message);
    }
    if (choice == 1) {
        string encodedMessage = Encode(KeyWord1, KeyWord2, Message);
        cout << "Encoded Message: " << encodedMessage << endl;
    } else if (choice == 2) {
        string decodedMessage = Decode(KeyWord1, KeyWord2, Message);
        cout << "Decoded Message: " << decodedMessage << endl;
    } else {
        cout << "Invalid choice." << endl;
    }

    return 0;
}
