class Solution {
public:
    string func(int num)
    {
        string str;
        while(num){
        if(num & 1) // 1
            str+='1';
        else // 0
            str+='0';
        num>>=1; // Right Shift by 1  
        }  
        reverse(str.begin(), str.end());  
        return str;
    }

    string convertDateToBinary(string d) {
        int year = 1000*(d[0]-'0') + 100*(d[1]-'0') + 10*(d[2]-'0') + d[3]-'0';
        int month = 10*(d[5]-'0') + d[6]-'0';
        int day = 10*(d[8]-'0') + d[9]-'0';

        string dyear = func(year);
        string dmonth = func(month);
        string dday = func(day);

        string ans = "";
        ans += dyear;
        ans += "-";
        ans += dmonth;
        ans += "-";
        ans += dday;
        return ans; 
    }
};