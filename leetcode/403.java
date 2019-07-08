import javafx.util.Pair;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Stack;
import java.util.Vector;

class Solution {
    public boolean canCross(int[] stones) {
        for(int i=3;i<stones.length;i++)
            if(stones[i]>stones[i-1]*2)
                return false;

        Stack<Pair<Integer,Integer>> stk=new Stack<>();
        stk.add(new Pair<>(0,0));

        HashSet<Integer> hashSet=new HashSet<>();
        for(int i=0;i<stones.length;i++)
            hashSet.add(stones[i]);

        int last=stones[stones.length-1];

        while(stk.size()!=0){
            Pair<Integer,Integer> pii=stk.pop();
            for(int i=pii.getValue()-1;i<=pii.getValue()+1;i++){
                if(i<=0)
                    continue;

                int to=pii.getKey()+i;
                if(to==last)
                    return true;
                else if(hashSet.contains(to))
                    stk.push(new Pair<>(to,i));
            }
        }

        return false;
    }
}
