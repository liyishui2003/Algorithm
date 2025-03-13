class Solution {
    char ordered[26];
public:
    bool cmp(string& a,string& b){
        vector<int>numA,numB;
        int la = a.length(),lb = b.length();
        for(int i = 0;i < la;i++){
            numA.push_back(ordered[a[i]-'a']);
        }
        for(int i = 0;i < lb;i++){
            numB.push_back(ordered[b[i]-'a']);
        }
        for(int i = 0;i < min(la,lb);i++){
            if(numA[i] > numB[i]) return false;
            if(numA[i] < numB[i]) return true;
        }
        if(la > lb) return false;
        return true;
    }
    bool isAlienSorted(vector<string>& words, string order) {
        int n = words.size();
        for(int i = 0;i < 26;i++){
            ordered[order[i]-'a']=i;
        }
        if(n == 1) return true;
        for(int i = 0;i < n-1;i++){
            if(cmp(words[i],words[i+1]) == false)
                return false;
        }
        return true;
    }
};
