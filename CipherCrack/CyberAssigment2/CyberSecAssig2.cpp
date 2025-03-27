// Jose Gonzales
//Cyber security assigment 2: ceaser cypher crack code
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

// Function to decrypt Caesar cipher
string decryptCipher(const string& cipherTxt, int shift)
{
    string decryptedText;
    for (char c : cipherTxt) 
    {
        if (isalpha(c)) 
        {
            if (islower(c))
            {
                char decryptedChar = 'a' + ((c - 'a' - shift + 26) % 26); // Ensure wrapping within lowercase range
                decryptedText += decryptedChar;
            }
            else 
            {
                char decryptedChar = 'A' + ((c - 'A' - shift + 26) % 26); // Ensure wrapping within uppercase range
                decryptedText += decryptedChar;
            }
        }
        else {
            decryptedText += c;
        }
    }
    return decryptedText;
}


// Function to find shift value 
int findShiftValue(const string& cipherText) 
{
    vector<int> frequency(26, 0);
    for (char c : cipherText) 
    {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) 
        {
            char lowercaseC = tolower(c);
            frequency[lowercaseC - 'a']++;
        }
    }

    int maxIndex = distance(frequency.begin(), max_element(frequency.begin(), frequency.end()));
    int shift = maxIndex - ('e' - 'a');// 'e' and 'a' are most common letters in ceasar cipher
    if (shift < 0) 
    {
        shift += 26; 
    }

    return shift;
}

int main() 
{
    // Open the input file containing the Caesar cipher text
    ifstream inputFile("cipher.txt");
    if (!inputFile) 
    {
        cerr << "Error: Unable to open input file." << endl;
        return 1;
    }

    // Read the file into a single string.
    string cipherText;
    string line;
    while (getline(inputFile, line)) // maakes it where can read text breaks. 
    {
        cipherText += line + "\n";
    }
    inputFile.close();

    // Find the shift value
    int shift = findShiftValue(cipherText);

    // Decrypt the cipher text and output the decrypted text to a file
    string decryptedText = decryptCipher(cipherText, shift);
    //offset value in terminal 
    cout << "offset value:  " << shift << endl;

    //output
    ofstream outputFile("output_cipher.txt");
    if (!outputFile) 
    {
        cerr << "Error: Unable to open output file." << endl;
        return 1;
    }
    //Display text 
    outputFile << "Decrypted text: \n" << decryptedText << endl;
    outputFile.close();
    cout << "Please check the output file 'output_cipher.txt' for the decrypted text." << endl;



    return 0;
}









/*
int main() 
{
    // user needs to provide the cipher text so that code is not hard coded. 
    cout << "Enter the cipher text: \n";
    string cipherText;
    getline(cin, cipherText);

    int shift = findShiftValue(cipherText);
    string decryptedText = decryptCipher(cipherText, shift);

    cout << "Shift value: \n" << shift << endl;
    cout << "Decrypted text: " << endl;
    cout << decryptedText << endl;

    return 0;
}

*/
