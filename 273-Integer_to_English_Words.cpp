class Solution {
public:
    string numberToWords(int num) {
        if ( !num ) return "Zero";
        string result, ns = to_string(num), s, hundred = "Hundred",
               first20[20] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", 
                              "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen",
                              "Eighteen", "Nineteen"},
               tys[9] = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"},
               w1000[4] = {"", "Thousand", "Million", "Billion"};
        for ( int i=ns.size()/3; i>=0; --i ) {
            s = ns.substr(0, ns.size()-i*3);
            ns = ns.substr(ns.size()-i*3, i*3);
            if ( s.empty() || !stoi(s) ) continue;
            num = stoi(s);
            if ( num / 100 ) {
                result += (' ' + first20[num/100] + ' ' + hundred);
                num %= 100;
            }
            if ( num >= 20 ) {
                result += (' ' + tys[num/10 - 2]);
                num %= 10;
            }
            if ( num ) result += (' ' + first20[num]);
            if ( i ) result += (' ' + w1000[i]);
        }
        return result.substr(1, result.size()-1);
    }
};
