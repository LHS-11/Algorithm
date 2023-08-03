class Solution {
    List<String> ans = new ArrayList<>();
    Map<Character,List<Character>> mp=new HashMap<>();

    public List<String> letterCombinations(String digits) {
        mp.put('2',List.of('a','b','c'));
        mp.put('3',List.of('d','e','f'));
        mp.put('4',List.of('g','h','i'));
        mp.put('5',List.of('j','k','l'));
        mp.put('6',List.of('m','n','o'));
        mp.put('7',List.of('p','q','r','s'));
        mp.put('8',List.of('t','u','v'));
        mp.put('9',List.of('w','x','y','z'));

        dfs(0,digits,"");
        return digits.length()!=0 ? ans : List.of();

    }

    void dfs(int idx,String digits,String answer){

        if(idx==digits.length()){
            ans.add(answer);
            System.out.println(ans);
            return;
        }

        List<Character> ch=mp.get(digits.charAt(idx));
        for(Character c : ch){
            dfs(idx+1,digits,answer+c);
        }
    }
}