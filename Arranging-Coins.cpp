class Solution {
public:
    int arrangeCoins(int n) {
        
          int result=0;
          
          for(int i=1 ;i<=n;i++){
            if(n>=i){
                result++ ;
                n-=i ;
            }
            else
              break ;
          }
        return result ;
    }
};