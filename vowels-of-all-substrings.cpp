class Solution {
public:
    long long countVowels(string word) {
        long long sum = 0;
        for(int i=0;i<word.size();i++) {
            if(word[i] == 'a' || word[i] == 'e' || word[i] == 'o' || word[i] == 'u' || word[i] == 'i') sum += (word.size()-i)*(i+1);
        }
        return sum;
    }
};