#include "../s.h"

class Solution {
private:
    int f1(int x, int y){
        return 8-x+y;
    }
    int f2(int x, int y ){
        return y+x;
    }

public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        
        int car = 0;
        if(a==c && c==e){
            if((b<d && d<f )||(f<d && d<b) )
                car = 2;
            else
                car = 1;
        }else if(b==f && d==f){
            if((a<c && c<e)||(e<c && c<a))
                car = 2;
            else
                car = 1;
        }else{
            if(a==e || b==f){
                car = 1;
            }else{
                car = 2;
            }
            
        }

        int ele=0;

        if(f1(a,b)==f1(c,d) && f1(c,d)==f1(e,f)){
            if((f2(c,d)<f2(a,b) && f2(a,b)<f2(e,f))||(f2(e,f)<f2(a,b)&&f2(a,b)<f2(c,d)))
                ele = 2;
            else
                ele=1;
        }else if(f2(a,b)==f2(c,d) && f2(c,d)==f2(e,f)){
            if((f1(c,d)<f1(a,b) && f1(a,b)<f1(e,f))||((f1(e,f)<f1(a,b))&&f1(a,b)<f1(c,d)))
                ele=2;
            else
                ele=1;
        }else{
            if(f1(c,d)==f1(e,f) || f2(c,d)==f2(e,f)){
                ele=1;
            }else{
                ele=2;
            }
        }
        return min(ele, car);

        


    }
};