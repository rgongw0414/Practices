class Solution {
public:
    string intToRoman(int num) {
        string ans = "";
        while (num - 1000 >= 0) {
            num -= 1000;
            ans += "M";
        }
        while (num - 900 >= 0) {
            num -= 900;
            ans += "CM";
        }
        while (num - 500 >= 0) {
            num -= 500;
            ans += "D";
        }
        while (num - 400 >= 0) {
            num -= 400;
            ans += "CD";
        }
        while (num - 100 >= 0) {
            num -= 100;
            ans += "C";
        }
        while (num - 90 >= 0) {
            num -= 90;
            ans += "XC";
        }
        while (num - 50 >= 0) {
            num -= 50;
            ans += "L";
        }
        while (num - 40 >= 0) {
            num -= 40;
            ans += "XL";
        }
        while (num - 10 >= 0) {
            num -= 10;
            ans += "X";
        }
        while (num - 9 >= 0) {
            num -= 9;
            ans += "IX";
        }
        while (num - 5 >= 0) {
            num -= 5;
            ans += "V";
        }
        while (num - 4 >= 0) {
            num -= 4;
            ans += "IV";
        }
        while (num - 1 >= 0) {
            num -= 1;
            ans += "I";
        }
        return ans;
    }
};