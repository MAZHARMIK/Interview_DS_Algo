/*
    Company Tags  : Amazon
    Frequency     : 30%
    Leetcode Link : https://leetcode.com/problems/complex-number-multiplication/
*/

//Approach-1 (Simple and intuitive. Just do what you would do in maths)
/*
	Just do this :
	(a+ib)(c+id)
	ac + adi + bci - bd
*/
class Solution {
private:
    auto getReal(const string& num) {
        return stoi(num.substr(0, num.find('+')));
    }
    auto getComplex(const string& num) {
        return stoi(num.substr(num.find('+')+1, num.length()-3));
    }
public:
    string complexNumberMultiply(string num1, string num2) {
        auto a    = getReal(num1);
        auto ib   = getComplex(num1);
        
        auto c    = getReal(num2);
        auto id   = getComplex(num2);
        
        auto real     = a*c - ib*id;
        auto complex  = a*id + ib*c;
        
        return to_string(real) + "+" + to_string(complex) + "i";
    }
};


//Approach-2 (stringstream never fails to impress me)
class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        stringstream ss_1(num1);
        stringstream ss_2(num2);
        
        int a, ib;
        int c, id;
        char justToSkip;
        ss_1 >> a >> justToSkip >> ib >> justToSkip;
        ss_2 >> c >> justToSkip >> id >> justToSkip;
        
        auto real     = a*c - ib*id;
        auto complex  = a*id + ib*c;
        
        return to_string(real) + "+" + to_string(complex) + "i";
    }
};
