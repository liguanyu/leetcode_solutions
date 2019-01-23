class Solution
{
   public:
    vector<string>
    letterCombinations(string digits)
    {
        vector<string> firstChar;
        if (digits.size() == 0) return firstChar;

        switch (digits[0]) {
            case '2':
                firstChar.push_back("a");
                firstChar.push_back("b");
                firstChar.push_back("c");
                break;
            case '3':
                firstChar.push_back("d");
                firstChar.push_back("e");
                firstChar.push_back("f");
                break;
            case '4':
                firstChar.push_back("g");
                firstChar.push_back("h");
                firstChar.push_back("i");
                break;
            case '5':
                firstChar.push_back("j");
                firstChar.push_back("k");
                firstChar.push_back("l");
                break;
            case '6':
                firstChar.push_back("m");
                firstChar.push_back("n");
                firstChar.push_back("o");
                break;
            case '7':
                firstChar.push_back("p");
                firstChar.push_back("q");
                firstChar.push_back("r");
                firstChar.push_back("s");
                break;
            case '8':
                firstChar.push_back("t");
                firstChar.push_back("u");
                firstChar.push_back("v");
                break;
            case '9':
                firstChar.push_back("w");
                firstChar.push_back("x");
                firstChar.push_back("y");
                firstChar.push_back("z");
                break;
            default:
                return firstChar;
        }

        vector<string> tail = letterCombinations(digits.substr(1));

        int fsize = firstChar.size();
        int tsize = tail.size();

        if (tsize == 0) return firstChar;

        vector<string> result;

        for (int i = 0; i < fsize; i++)
            for (int j = 0; j < tsize; j++) {
                result.push_back(firstChar[i] + tail[j]);
            }
        return result;
    }
};
