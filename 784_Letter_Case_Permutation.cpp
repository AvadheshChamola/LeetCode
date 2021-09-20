/*
784. Letter Case Permutation
Medium

Given a string s, we can transform every letter individually to be lowercase or uppercase to create another string.

Return a list of all possible strings we could create. You can return the output in any order.

 

Example 1:
Input: s = "a1b2"
Output: ["a1b2","a1B2","A1b2","A1B2"]

Example 2:
Input: s = "3z4"
Output: ["3z4","3Z4"]

Example 3:
Input: s = "12345"
Output: ["12345"]

Example 4:
Input: s = "0"
Output: ["0"]

Constraints:
    s will be a string with length between 1 and 12.
    s will consist only of letters or digits.
*/
class Solution {
public:
    vector<string> ans;
    void helper(string s,string a,int i){
        if(i==s.size()){
            ans.push_back(a);
            return;
        }
        if(isdigit(s[i])){
            a+=s[i];
            helper(s,a,i+1);
        }else{
            a+=tolower(s[i]);
            helper(s,a,i+1);
            a[i]=toupper(s[i]);
            helper(s,a,i+1);
        }
    }
    vector<string> letterCasePermutation(string s) {
        string a;
        helper(s,a,0);
        return ans;
    }
};
