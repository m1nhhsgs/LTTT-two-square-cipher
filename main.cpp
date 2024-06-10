#include "TwoSquareCipher.h"

int main() {
    int choice;
    cout << "Choose an option:\n1. Encode\n2. Decode\n";
    cin >> choice;
    cin.ignore();

    string KeyWord1, KeyWord2, Message;

    cout << "Enter the first keyword: ";
    getline(cin, KeyWord1);
    cout << "Enter the second keyword: ";
    getline(cin, KeyWord2);
    cout << "Enter the message: ";
    getline(cin, Message);

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
