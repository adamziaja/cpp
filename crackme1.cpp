// vim:ft=cpp

// simple crackme
// (C) 2014 Adam Ziaja <adam@adamziaja.com> http://adamziaja.com

#include <iostream>
#include <sstream>
using namespace std;

int main() {
    stringstream ss;
    string username;
    string serialstring;
    double sn;
    int serial;
start:
    cout << "username:" << endl;
    getline(cin, username);
    if (username.length() < 8 || username.length() > 12) {
        cout << "username must be between 8 and 12!" << endl;
        goto start;
    }
    cout << "serial number:" << endl;
    cin >> sn;
    for (int i = 0; i < username.length(); i++) {
        if (i % 2 == 0) {
            ss << (int) tolower(username[i]);
        } else {
            ss << (int) toupper(username[i]);
        }
    }
    ss >> serialstring;
    int usernamelength = username.length();
    usernamelength = (usernamelength - 8) * 2;
    serialstring = serialstring.substr(usernamelength);
    string serialstring2;
    for (int i = 0; i < 8; i++) {
        serialstring2 += serialstring[i];
    }
    istringstream iss(serialstring2);
    iss >> serial;
    if (sn == serial) {
        cout << "s/n OK!" << endl;
    } else {
        cout << "s/n WRONG!" << endl;
    }
}
