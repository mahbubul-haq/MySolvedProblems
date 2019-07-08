class Solution {
    public boolean isNumber(String s) {

        int i=0,l=s.length()-1;
        while(i<s.length() && s.charAt(i)==' ')
            i++;
        while(l>=0 && s.charAt(l)==' ')
            l--;
        if(i>l)
            return false;
        
        boolean num=false,dot=false,e=false,minus=false;
        
        if((s.charAt(l)>='0' && s.charAt(l)<='9') || s.charAt(l)=='.'){
            for(int k=i;k<=l;k++){
                char ch=s.charAt(k);
                if(ch>='0'&&ch<='9')
                    num=true;
                else if(ch=='+' || ch=='-')
                {
                    if(e && s.charAt(k-1)=='e')
                        continue;
                    
                    if(dot || num || e|| minus)
                        return false;
                    minus=true;
                }
                else if(ch=='e'){
                    if(!num || e)
                        return false;
                    e=true;
                }
                else if(ch=='.'){
                    if(e || dot)
                        return false;
                    dot=true;
                }
                else return false;
            }
        }
        else return false;
        
        if(!num)
            return false;
        
        return true;
        
    }
}
