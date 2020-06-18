//
// Created by Ankit Batra on 6/17/20.
//

/* Write a function to check whether an input string is a valid IPv4 address or IPv6 address or neither.
 * IPv4 addresses are canonically represented in dot-decimal notation, which consists of four decimal numbers,
 * each ranging from 0 to 255, separated by dots ("."), e.g.,172.16.254.1;
 * Besides, leading zeros in the IPv4 is invalid. For example, the address 172.16.254.01 is invalid.
 * IPv6 addresses are represented as eight groups of four hexadecimal digits, each group representing 16 bits.
 * The groups are separated by colons (":"). For example, the address 2001:0db8:85a3:0000:0000:8a2e:0370:7334 is a valid one.
 * Also, we could omit some leading zeros among four hexadecimal digits and some low-case characters in the address to upper-case ones,
 * so 2001:db8:85a3:0:0:8A2E:0370:7334 is also a valid IPv6 address(Omit leading zeros and using upper cases).
 * However, we don't replace a consecutive group of zero value with a single empty group using two consecutive colons (::) to pursue simplicity. For example, 2001:0db8:85a3::8A2E:0370:7334 is an invalid IPv6 address.
 * Besides, extra leading zeros in the IPv6 is also invalid. For example, the address 02001:0db8:85a3:0000:0000:8a2e:0370:7334 is invalid.
 *
 * Note: You may assume there is no extra space or special characters in the input string. */

#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    static vector<string> splitIP(string IP, char delimiter) {
        vector<string> nums;
        string str = "";
        int len = IP.length();

        for (int i = 0; i < len; ++i) {
            if (IP[i] != delimiter) str +=  IP[i];
            else {
                nums.push_back(str);
                str = "";
            }
        }
        nums.push_back(str);

        return nums;
    }
    static bool checkIfDigit(string str) {
        for  (int i = 0; i < str.length(); ++i) {
            if (!isdigit(str[i])) return false;
        }
        return true;
    }
    static string validateIPv4(string IP) {
        vector<string> nums = splitIP(IP, '.');
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            if (!checkIfDigit(nums[i])) return "Neither";
            int len = nums[i].length();
            if (len == 0 || len > 3) return "Neither";
            int number = std::stoi(nums[i]);
            if (number < 0 || number > 255) return "Neither";
            if (nums[i][0] == '0' && len != 1) return "Neither";
        }
        return "IPv4";
    }
    static bool findChar(string str, char c) {
        if (str.find(c) != string::npos) return true;
        return false;
    }
    static string validateIPv6(string IP) {
        vector<string> nums = splitIP(IP, ':');
        int n = nums.size();
        string hexdigits = "0123456789abcdefABCDEF";

        for (int i = 0; i < n; ++i) {
            int len = nums[i].length();
            if (len == 0 || len > 4) return "Neither";
            for (int j = 0; j < len; ++j) {
                if (!findChar(hexdigits, nums[i][j])) return "Neither";
            }
        }
        return "IPv6";
    }
    static string validIPAddress(string IP) {
        int countDots = 0;
        int countColons = 0;
        int len = IP.length();

        for (int i = 0; i < len; ++i) {
            if (IP[i] == '.') countDots++;
            else if(IP[i] == ':')  countColons++;
            else continue;
        }

        if (countDots == 3) return validateIPv4(IP);
        else if (countColons == 7) return validateIPv6(IP);

        return "Neither";
    }
};

int main() {
    string IP;

    std::cout << "Enter the input string. " << std::endl;
    std::cin >> IP;

    std::cout << Solution::validIPAddress(IP);

    return 0;
}