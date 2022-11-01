#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Prototyping
int getRandomBias();
void testing_getRandomBias();
string encrypt(string message, int bias);
void testing_encrypt();
string getRandomLetters(int length);
int getRandomNumberForDummy();

const string ALL_LETTERS = "1234567890-=!@#$%^&*()_+qwertyuiop[]QWERTYUIOP{}asdfghjkl;'ASDFGHJKL:\"zxcvbnm,./ZXCVBNM< >?";
const int ALL_LETTERS_LENGTH = ALL_LETTERS.length();

int main() {
    string message;
    getline(cin, message);

    srand(time(NULL));

    int bias = getRandomBias();
    string encryptedMessage = encrypt(message, bias);
    cout << message << endl;
    cout << encryptedMessage << endl;

    return 0;
}

/**
 * Changes the message by adding number of random letters to its front.
 *
 * @param message The message to add random letters to.
 */
void addFrontDummyText(string &message) {
    int dummyTextLength = getRandomNumberForDummy();
    string dummyText = getRandomLetters(dummyTextLength);
    message = dummyText + message;
    message = ((char) (toascii('a') + dummyTextLength)) + message;
}

/**
 * Changes the message by adding number of random letters to its back.
 *
 * @param message The message to add random letters to.
 */
void addBackDummyText(string &message) {
    int dummyTextLength = getRandomNumberForDummy();
    string dummyText = getRandomLetters(dummyTextLength);
    message += dummyText;
    message += (char) (toascii('a') + dummyTextLength);
}

/**
 * Testing encrypt function for all types of input.
 */
void testing_encrypt() {
    cout << ALL_LETTERS << endl;
    for(int bias = 0; bias < 26; bias++) {
        string encryptedMessage = encrypt(ALL_LETTERS, bias);
        cout << "bias: " << bias << endl;
        cout << "encryptedMessage: " << encryptedMessage << endl;
    }
}

/**
 * This function is responsible for encrypting the message being sent by shifting
 * each letter in it by the specified bias.
 *
 * @param message is the message we want to encrypt.
 * @param bias is the bias that letters will be shifted by.
 *
 * @return the encrypted message.
 */
string encrypt(string message, int bias) {
    // Add an 'a' at the end as a reference (key) to the bias of encryption.
    message.push_back('a');

    // shift all the letters by the specified bias.
    for (int i = 0; i < message.size(); i++) {
        char shiftedChar = toascii(message[i]) + bias;
        message[i] = shiftedChar;
    }
    addFrontDummyText(message);
    addBackDummyText(message);

    return message;

}

/**
 * This function is just used for testing the random bias generator function
 */
void testing_getRandomBias() {
    int errorsCounter = 0;
    for (int i = 0; i < 1000; ++i) {
        int bias = getRandomBias();
        if (bias < 1 || bias >= 26) {
            cout << bias << endl;
            errorsCounter++;
        }
        if(bias == 25){
            cout << "Getting 25" << endl;
        }
    }
    cout << errorsCounter;
}

/**
 * This function is used to generate a random bias for the encryption
 * each time a new message is sent.
 *
 * @return the bias that this message will be shifted with.
 */
int getRandomBias() {
    return 1 + (rand() % 25);
}

/**
 * This function is to get the number of letters to add to a side of the message.
 *
 * @return the number of letters to add to a side of the message.
 */
int getRandomNumberForDummy() {
    return 3 + (rand() % 12);
}

/**
 * This function is to get a certain number of random letters.
 *
 * @param length the number of random letters to get.
 * @return the string to be added to the message.
 */
string getRandomLetters(int length) {
    string randomLetters;
    for (int i = 0; i < length; i++) {
        randomLetters += ALL_LETTERS[rand() % ALL_LETTERS_LENGTH];
    }
    return randomLetters;
}