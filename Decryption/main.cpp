#include <iostream>

using namespace std;

// Prototyping
void removeDummy(string &encryptedMessage);
void removeFrontDummy(string &encryptedMessage);
void removeBackDummy(string &encryptedMessage);
string decrypt(string encryptedMessage, int shiftingBias);
int getShiftingBias(string encryptedMessage);

int main() {
    string encryptedMessage;
    cin >> encryptedMessage;

    removeDummy(encryptedMessage);
    int shiftingBias = getShiftingBias(encryptedMessage);
    string decryptedMessage = decrypt(encryptedMessage, shiftingBias);

    cout << decryptedMessage << endl;
    return 0;
}

/**
 * Decrypts the message with the given key.
 *
 * @param encryptedMessage the message to be decrypted.
 * @return the decrypted message.
 */
string decrypt(string encryptedMessage, int shiftingBias) {
    string decryptedMessage;
    for (char i : encryptedMessage) {
        decryptedMessage += (char) (i - shiftingBias);
    }

    // remove the key
    decryptedMessage.pop_back();
    return decryptedMessage;
}

/**
 * gets the shifting bias from the encrypted message.
 *
 * @param encryptedMessage the message to be decrypted.
 */
int getShiftingBias(string encryptedMessage) {
    int shiftingBias = encryptedMessage[encryptedMessage.length() - 1] - 'a';
    return shiftingBias;
}

/**
 * Removes the dummy characters from the encrypted message.
 *
 * @param encryptedMessage the message to be decrypted.
 */
void removeDummy(string &encryptedMessage) {
    removeFrontDummy(encryptedMessage);
    removeBackDummy(encryptedMessage);
}

/**
 * Removes the dummy characters from the back of the encrypted message.
 *
 * @param encryptedMessage the message to be decrypted.
 */
void removeBackDummy(string &encryptedMessage) {
    int dummyLength = encryptedMessage[encryptedMessage.length()-1] - 'a';
    encryptedMessage = encryptedMessage.substr(0, encryptedMessage.length()-1-dummyLength);
}

/**
 * Removes the dummy characters from the front of the encrypted message.
 *
 * @param encryptedMessage the message to be decrypted.
 */
void removeFrontDummy(string &encryptedMessage) {
    int dummyLength = encryptedMessage[0] - 'a';
    encryptedMessage.erase(0, dummyLength+1);
}
