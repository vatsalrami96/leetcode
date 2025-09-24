// Last updated: 9/24/2025, 2:16:44 AM
class Solution {
    public String[] divideString(String s, int k, char fill) {
        
        int size;
        if(s.length()%k==0)
        {
            size=s.length()/k;
        }
        else
        {
             size= s.length()/k+1;
        }
        String[] output = new String[size];
        int idx=0;
        String result ="";
        
        for(int i=0;i<s.length();i++)
            
        {
           result = result+s.charAt(i); 
           if(result.length()==k)
           {
               output[idx] = result;
               idx++;
               result="";
           }
        }
       if(result=="")
        {
            return(output);
        }
        else
        {

            while(result.length()!=k)
            {
                result=result+fill;


            }
            output[idx] = result;


            return(output);
        }
            
        
    }
}