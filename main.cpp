#include <iostream>
#include <filesystem>
#include <fstream>

using namespace std;

int main() {
    ofstream writeFile;
    ifstream readFile;
    string ch;
    char text;
    cout << "enter the text you want to write" << endl;
    cin >> ch;
    writeFile.open("./lol.txt");
    if(writeFile) {
        writeFile << ch;
        cout<<"Data store Successfully: \n\n"<<endl;
    } else cout << "Error 1: Unknown error while trying to open file";
    writeFile.close();

    readFile.open("./lol.txt", ios::in);
    if(readFile) {
        readFile.seekg(7, ios::beg); //skip first 7 bytes from beginning:
        cout<<" The output( after skipping first 7 bytes) is: ";

        while(!readFile.eof()) //read data from file till end of file:
        {
            readFile.get(text); //read data:
            cout<<text;     //display data:
        }
    } else cout << "Error 1: Unknown error while trying to open file";
    readFile.close();
    return 0;
}
