/*
 * @lc app=leetcode.cn id=5 lang=c
 *
 * [5] 最长回文子串
 */

// @lc code=start


char * longestPalindrome(char * s){
    char* s1,* s2,* tar;
    int i,j,length,slen;
    tar=s;
    length=1;
    slen=strlen(s);
    //暴力循环法，从两端往中间找
    for(i=0;i+length<slen;i++){//从前往后
        
        for(j=i+length;j<slen;j++){//从后往前
            s1=s+i;
            s2=s+j;
            while(s1<s2){
                
                if((*s1)!=(*s2))
                    break;//匹配失败的情况
                s1++;
                s2--;//匹配成功的时候一个进一个退
            }
            if(s1>=s2){//相遇的时候
                tar=s+i;
                length=j-i+1;//
            }
        }
    }
    tar[length]=0;
    return tar;
}

// @lc code=end

