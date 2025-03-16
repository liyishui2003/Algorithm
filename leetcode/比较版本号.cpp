class Solution {
public:
    int cmp(string s,string t){
        int a = stoi(s),b = stoi(t);
        if(a < b) return -1;
        else if(a > b) return 1;
        else return 0; 
    }
    int compareVersion(string version1, string version2) {
        int p1 = 0,p2 = 0,last1 = 0,last2 = 0;
        version1.push_back('.');
        version2.push_back('.');
        int l1 = version1.length(),l2 = version2.length();
        while( p1 < l1 || p2 < l2){
            if(p1 == l1){
                while(version2[p2] != '.') p2++;
                int ret = cmp("0",version2.substr(last2,p2 - last2));
                if(ret != 0)  return ret;
                p2++,last2 = p2;
            }
            else if(p2 == l2){
                while(version1[p1] != '.') p1++;
                int ret = cmp(version1.substr(last1,p1 - last1),"0");
                if(ret != 0)  return ret;
                p1++,last1 = p1;
            }
            else {
                while(version1[p1] != '.') p1++;
                while(version2[p2] != '.') p2++;
                int ret = cmp(version1.substr(last1,p1 - last1),version2.substr(last2,p2 - last2));
                if(ret != 0)  return ret;
                p1++,p2++;
                last1 = p1,last2 = p2;
            }
        }
        return 0;
    }
};
