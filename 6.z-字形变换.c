/*
 * @lc app=leetcode.cn id=6 lang=c
 *
 * [6] Z 字形变换
 */

// @lc code=start

char * convert(char * s, int numRows){
    char *returnStr,*tempNode;
    int slen = 1,len = 0,space;
    if(*s == '\0') return 0;
    tempNode = s;
    while(*(++tempNode) != '\0') slen++;
    if(slen <= numRows || numRows==1) return s;
    //计算间隔并逐个加入返回串中
    space = 2*numRows-2;
    returnStr = (char*)malloc((slen+1)*sizeof(char));
    for(int i=0;i<numRows;i++){
        //第一行和最后一行每个间隔内只有一个字符
        if(i == 0 || i == numRows-1){
            for(int j=i;j<slen;j+=space){
                returnStr[len++] = s[j];
            }
        }
        //中间行每个间隔内有两个字符

        else{
            for(int j=i;j<slen;j+=space){
                returnStr[len++] = s[j];
                if((j+(numRows-1-i)*2) < slen)
                    returnStr[len++] = s[j+(numRows-1-i)*2];
            }
        }
    }
    returnStr[len] = '\0';
    return returnStr;
}

// @lc code=end

