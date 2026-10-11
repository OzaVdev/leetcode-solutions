class Solution {
public:

    string intToRoman(int num) {

        // Precomputed Roman values for thousands.
        static const string thousands[] = {
            "", "M", "MM", "MMM"
        };

        // Precomputed Roman values for hundreds.
        static const string hundreds[] = {
            "", "C", "CC", "CCC", "CD",
            "D", "DC", "DCC", "DCCC", "CM"
        };

        // Precomputed Roman values for tens.
        static const string tens[] = {
            "", "X", "XX", "XXX", "XL",
            "L", "LX", "LXX", "LXXX", "XC"
        };

        // Precomputed Roman values for ones.
        static const string ones[] = {
            "", "I", "II", "III", "IV",
            "V", "VI", "VII", "VIII", "IX"
        };

        // Directly construct the answer using
        // each decimal digit.
        return thousands[num / 1000]
             + hundreds[(num / 100) % 10]
             + tens[(num / 10) % 10]
             + ones[num % 10];
    }
};