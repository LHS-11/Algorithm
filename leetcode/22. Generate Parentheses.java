class Solution {

    List<String> ans=new ArrayList<>();

    public List<String> generateParenthesis(int n) {
        dfs(0,n*2,"");
        return ans;
    }

    void dfs(int cnt,int n,String str){

        if(cnt==n){
            System.out.println(str);
            if(isValid(str)){
                ans.add(str);
            }
            return;
        }

        dfs(cnt+1,n,str+'(');
        dfs(cnt+1,n,str+')');

        
    }

    Boolean isValid(String str){
        Stack<Character> stk=new Stack<>();
        boolean flag=true;
        for(char c : str.toCharArray()){
            if(c=='(') {
                stk.push('(');
            }else{
                if(c==')' && stk.size()>0 && stk.peek()=='(' ){
                    stk.pop();
                }else {
                    flag=false;
                    break;
                }
            }
        }

        if(!stk.isEmpty()) flag=false;
        return flag;
    }
}