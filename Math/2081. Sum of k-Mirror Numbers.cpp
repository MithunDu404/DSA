// https://leetcode.com/problems/sum-of-k-mirror-numbers/description/

class Solution {
    public:
        bool isPalindrome(string& s){
            int l = 0;
            int r = s.size()-1;
            while(l <= r){
                if(s[l] != s[r]) return false;
                l++;
                r--;
            }
            return true;
        }
    
        string solve(long long n,int k){
            string t = "";
            while(n > 0){
                t += to_string(n%k);
                n /= k;
            }
            return t;
        }
        long long kMirror(int k, int n) {
            int l = 1;
            long long ans = 0;
    
            while(n > 0){
                int hl = (l+1)/2;
    
                long long mini = pow(10,hl-1);
                long long maxi = pow(10,hl)-1;
    
                for(int num=mini;num<=maxi;num++){
                    string v = to_string(num);
                    string rv = v;
                    reverse(rv.begin(),rv.end());
    
                    if(l&1) v += rv.substr(1);
                    else v += rv;
    
                    long long vn = stoll(v);
    
                    string kbasev = solve(vn,k);
                    if(isPalindrome(kbasev)){
                        ans += vn;
                        n--;
                    }
    
                    if(n == 0) return ans;
                }
                l++;
            }
    
            return ans;
        }
    };