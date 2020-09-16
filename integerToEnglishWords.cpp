//
// Created by Ankit Batra on 9/15/20.
//

/* Convert a non-negative integer to its english words representation.
 * Given input is guaranteed to be less than 231 - 1. */

#include <iostream>
#include <string>

using std::string;

class Solution {
public:
    static string one(int num) {
        switch(num) {
            case 1: return "One";
            case 2: return "Two";
            case 3: return "Three";
            case 4: return "Four";
            case 5: return "Five";
            case 6: return "Six";
            case 7: return "Seven";
            case 8: return "Eight";
            case 9: return "Nine";
        }
        return "";
    }

    static string twoLessThan20(int num) {
        switch(num) {
            case 10: return "Ten";
            case 11: return "Eleven";
            case 12: return "Twelve";
            case 13: return "Thirteen";
            case 14: return "Fourteen";
            case 15: return "Fifteen";
            case 16: return "Sixteen";
            case 17: return "Seventeen";
            case 18: return "Eighteen";
            case 19: return "Nineteen";
        }
        return "";
    }
    static string ten(int num) {
        switch(num) {
            case 2: return "Twenty";
            case 3: return "Thirty";
            case 4: return "Forty";
            case 5: return "Fifty";
            case 6: return "Sixty";
            case 7: return "Seventy";
            case 8: return "Eighty";
            case 9: return "Ninety";
        }
        return "";
    }
    static string two(int num) {
        if (num == 0) return "";
        else if (num < 10) return one(num);
        else if (num < 20) return twoLessThan20(num);
        else {
            int tensNum = num / 10;
            int rem = num - tensNum * 10;
            if (rem != 0)
                return ten(tensNum) + " " + one(rem);
            else
                return ten(tensNum);
        }
    }
    static string three(int num) {
        int hundredNums = num / 100;
        int rem = num - hundredNums * 100;
        string ans = "";
        if (hundredNums * rem != 0)
            ans = one(hundredNums) + " Hundred " + two(rem);
        else if ((hundredNums == 0) && (rem != 0))
            ans = two(rem);
        else if ((hundredNums != 0) && (rem == 0))
            ans = one(hundredNums) + " Hundred";
        return ans;
    }
    static string numberToWords(int num) {
        if (num == 0) return "Zero";

        string res = "";

        int billion = num / 1000000000;
        int million = (num - billion * 1000000000) / 1000000;
        int thousand = (num - billion * 1000000000 - million * 1000000) / 1000;
        int rem = num - billion * 1000000000 - million * 1000000 - thousand * 1000;

        if (billion != 0)
            res = three(billion) + " Billion";
        if (million != 0) {
            if (res != "")
                res += " ";
            res += three(million) + " Million";
        }
        if (thousand != 0) {
            if (res != "")
                res += " ";
            res += three(thousand) + " Thousand";
        }
        if (rem != 0) {
            if (res != "")
                res += " ";
            res += three(rem);
        }

        return res;
    }
};

int main() {
    string res = "";
    int num;

    std::cout << "Enter the number: " << std::endl;
    std::cin >> num;

    std::cout << Solution::numberToWords(num);

    return 0;
}

