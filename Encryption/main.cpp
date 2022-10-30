#include <iostream>
#include <cstdlib>

int getRandomBias();

void testing_getRandomBias();

string encrypt(string basicString, int bias);

using namespace std;

int main() {
    string message;
    cin >> message;
    // add an 'a' at the end as a reference (key) to the bias of encryption.
    message.push_back('a');

    return 0;
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
