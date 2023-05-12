import java.util.*;
import java.io.*;


public class Main
{
    static int[][] cnt=new int[10][7];

    public static void main(String args[]) throws IOException
    {
        
        makeCnt();

        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        int t=Integer.parseInt(br.readLine());

        while(t>0){
            t--;
            String[] str=br.readLine().split(" ");
            // int a=Integer.parseInt(str[0]);
            // int b=Integer.parseInt(str[1]);
            String a=str[0];
            String b=str[1];
            
            int sum=0;

            if(a.length()>b.length()){

                StringBuilder sb=new StringBuilder(b);

                int cc=0;
                while(a.length()!=b.length()+cc){
                    sb.insert(0,'x');
                    cc++;
                }
                b=sb.toString();

            }else if(a.length()<b.length()){
                StringBuilder sb=new StringBuilder(a);

                int cc=0;
                while(a.length()+cc!=b.length()){
                    sb.insert(0,'x');
                    cc++;
                }
                a=sb.toString();
            }

             for(int i=0;i<a.length();i++){
                    
                    
                    int aa=a.charAt(i)-'0';
                    int bb=b.charAt(i)-'0';

                    if(a.charAt(i)=='x'){
                        for(int j=0;j<=6;j++){
                            if(cnt[bb][j]>0) sum++;
                        }
                    }else if(b.charAt(i)=='x'){
                        for(int j=0;j<=6;j++){
                            if(cnt[aa][j]>0) sum++;
                        }
                    }else{

                        for(int j=0;j<=6;j++){

                            if(cnt[bb][j]>0){ // b를 기준으로 
                                if(cnt[aa][j]>0) continue; // a도 켜져있다면 패스
                                sum++; // 아니라면 켜야됨
                            }else if(cnt[aa][j]>0 && cnt[bb][j]==0){
                                sum++; // 꺼야됨됨
                            }
                            // System.out.println(aa+" "+bb+" "+sum);
                        }
                    }
                   
                }   
            System.out.println(sum);
        }



            
    }




    public static void makeCnt(){
        make(0);
        make1(1);
        make2(2);
        make3(3);
        make4(4);
        make5(5);
        make6(6);
        make7(7);
        make8(8);
        make9(9);


    }
    public static void make(int i){
        cnt[i][0]=1;
        cnt[i][1]=1;
        cnt[i][2]=1;
        cnt[i][3]=1;
        cnt[i][4]=1;
        cnt[i][5]=1;
    }
    public static void make1(int i){
        cnt[i][1]=1;
        cnt[i][2]=1;
    }
    public static void make2(int i){
        cnt[i][0]=1;
        cnt[i][1]=1;
        cnt[i][3]=1;
        cnt[i][4]=1;
        cnt[i][6]=1;
    }
    public static void make3(int i){
        cnt[i][0]=1;
        cnt[i][1]=1;
        cnt[i][2]=1;
        cnt[i][3]=1;
        cnt[i][6]=1;
    }
    public static void make4(int i){
        cnt[i][1]=1;
        cnt[i][2]=1;
        cnt[i][5]=1;
        cnt[i][6]=1;

    }
    public static void make5(int i){
        cnt[i][0]=1;
        cnt[i][2]=1;
        cnt[i][3]=1;
        cnt[i][6]=1;
        cnt[i][5]=1;
    }
    public static void make6(int i){
        cnt[i][0]=1;
        cnt[i][6]=1;
        cnt[i][2]=1;
        cnt[i][3]=1;
        cnt[i][4]=1;
        cnt[i][5]=1;
    }
    public static void make7(int i){
        cnt[i][0]=1;
        cnt[i][1]=1;
        cnt[i][2]=1;
        cnt[i][5]=1;
    }
    public static void make8(int i){
        cnt[i][0]=1;
        cnt[i][1]=1;
        cnt[i][2]=1;
        cnt[i][3]=1;
        cnt[i][4]=1;
        cnt[i][5]=1;
        cnt[i][6]=1;
    }
    public static void make9(int i){
        cnt[i][0]=1;
        cnt[i][1]=1;
        cnt[i][2]=1;
        cnt[i][3]=1;
        cnt[i][5]=1;
        cnt[i][6]=1;
    }
}