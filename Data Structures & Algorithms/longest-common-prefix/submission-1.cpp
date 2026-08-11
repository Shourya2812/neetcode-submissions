class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prifix = strs[0] ;
        for(int i = 0 ; i<strs.size() ; i++){
            int j = 0 ;
            while(j<prifix.length() && j<strs[i].length() && prifix[j]==strs[i][j]){
                j++ ;
            }
            prifix = prifix.substr(0,j) ;
            if(prifix == ""){
                return "" ;
            }
            
        }
        return prifix ;
    }
};