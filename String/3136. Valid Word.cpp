// https://leetcode.com/problems/valid-word/

// Without any built-in functions
class Solution {
public:
    bool isVowel(char& c){
        return (c=='a' || c=='e'|| c=='i' || c=='o' || c=='u' ||
                c=='A' || c=='E'|| c=='I' || c=='O' || c=='U');
    }
    bool isConsonant(char& c){
        if(('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'))
            return true;
        return false;
    }
    bool isNumber(char& c){
        if('0' <= c && c <= '9')
            return true;
        return false;
    }
    bool isValid(string word) {
        int v = 0, c = 0, l = 0;
        for(char& ch : word){
            if(isVowel(ch)) v++;
            else if(isConsonant(ch)) c++;
            else if(isNumber(ch)) l++;
            else return false;
        }
        
        if(v > 0 && c > 0 && (v+c+l) >= 3)
            return true;
        return false;
    }
};


// With built-in functions
class Solution {
public:
    bool isValid(string word) {
        int n = word.size();
        if(n < 3) return false;
        bool v = false, c = false;
        for(auto ch : word){
            if(!isalnum(ch)) return false;
            
            if(!isalpha(ch)) continue;

            ch = tolower(ch);
            if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
                v = true;
            else c = true;
        }
        return (v & c);
    }
};