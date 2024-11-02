/**
 * Problem: Write a C++ program that reads client data from a text file and processes it into a structured format.
 * Each client's data is stored on a single line in the file with values separated by a specific delimiter ("#//#").
 * The program should read each line, split it into its components, and store each client's details in a structured format.
 * 
 * Example:
 * For a line in the file: "123#//#4567#//#John Doe#//#123-456-7890#//#5000.75"
 * The program should extract and store:
 * - Account Number: 123
 * - Pin Code: 4567
 * - Name: John Doe
 * - Phone: 123-456-7890
 * - Account Balance: 5000.75
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

const string ClientsFileName = "Clients.txt";

// Structure to store client information
struct sClient {
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
};

// Function to split a string based on a given delimiter
vector<string> SplitString(string S1, string Delim) {
    vector<string> vString;
    short pos = 0;
    string sWord; // Define a string variable

    // Use find() function to get the position of the delimiters
    while ((pos = S1.find(Delim)) != std::string::npos) {
        sWord = S1.substr(0, pos); // Store the word
        if (sWord != "") {
            vString.push_back(sWord);
        }
        S1.erase(0, pos + Delim.length());
    }
    if (S1 != "") {
        vString.push_back(S1); // Add the last word of the string
    }
    return vString;
}

// Function to convert a line from the file into a structured client record
sClient ConvertLinetoRecord(string Line, string Seperator = "#//#") {
    sClient Client;
    vector<string> vClientData;
    vClientData = SplitString(Line, Seperator);

    Client.AccountNumber = vClientData[0];
    Client.PinCode = vClientData[1];
    Client.Name = vClientData[2];
    Client.Phone = vClientData[3];
    Client.AccountBalance = stod(vClientData[4]); // Convert string to double

    return Client;
}

// Function to load client data from a file into a vector of sClient structures
vector<sClient> LoadCleintsDataFromFile(string FileName) {
    vector<sClient> vClients;
    fstream MyFile;
    MyFile.open(FileName, ios::in); // Open file in read mode

    if (MyFile.is_open()) {
        string Line;
        sClient Client;
        while (getline(MyFile, Line)) {
            Client = ConvertLinetoRecord(Line);
            vClients.push_back(Client);
        }
        MyFile.close();
    }
    return vClients;
}
