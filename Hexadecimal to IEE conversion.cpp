
#include <iostream>
#include <string>
#include <unordered_map>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <cstring>
using namespace std;
string hextoBinary(const string& hex) {
    unordered_map<char, string> hexToBinMap = {
      {'0', "0000"}, {'1', "0001"}, {'2', "0010"}, {'3', "0011"},
      {'4', "0100"}, {'5', "0101"}, {'6', "0110"}, {'7', "0111"},
      {'8', "1000"}, {'9', "1001"}, {'A', "1010"}, {'B', "1011"},
      {'C', "1100"}, {'D', "1101"}, {'E', "1110"}, {'F', "1111"},
      {'a', "1010"}, {'b', "1011"}, {'c', "1100"}, {'d', "1101"},
      {'e', "1110"}, {'f', "1111"}
    };
    string binary = "";
    for (char digit : hex) {
        if (hexToBinMap.find(digit) != hexToBinMap.end()) {
            binary += hexToBinMap[digit];

        }
        else {
            cerr << "Error: Invalid hexadecimal digit '" << digit << "'\n";
            return "";
        }
    }
    return binary;
}
int BinarytoDecimal(const string& binary) {
    int n = 0;
    for (char bit : binary) {
        n = (n << 1) | (bit - '0');
        return n;
    }
}
void decode(string& binary) {
    int sign = (binary[0] == '1') ? 1 : 0;
    string exponentBits = binary.substr(1, 8);
    string mantissaBits = binary.substr(9);
    int exponent = 0;
    for (char bit : exponentBits) {
        exponent = (exponent << 1) | (bit - '0');
    }
    int trueExponent = exponent - 127;
    float fractionalMantissa = 1.0;
    for (int i = 0; i < mantissaBits.size(); i++) {
        if (mantissaBits[i] == '1') {
            fractionalMantissa += pow(2, -(i + 1));
        }
    }
    float value = pow(-1, sign) * fractionalMantissa * pow(2, trueExponent);
    cout << "Sign: " << sign << endl;
    cout << "Exponent: " << exponentBits << " (Decimal: " << exponent << ")" << endl;
    cout << "Mantissa: " << mantissaBits << endl;
    cout << fixed << setprecision(6);
    cout << "Final Floating-Point Value: " << value << endl;
    if (binary.length() != 32) {
        cerr << "Error: input must be 32 bits long!" << endl;
        return;
    }
}

int main()
{
    string hexadecimal;
    std::cout << "Insert Hexadeciaml: ";
    cin >> hexadecimal;
    string Binary = hextoBinary(hexadecimal);
    decode(Binary);
    
}