/*
 * @lc app=leetcode.cn id=3 lang=c
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start

int lengthOfLongestSubstring(char * s){
    int i=0;
    int count = 0;//子串当前长度
    int max = 0;//最大长度
    int index[128] = {0};//用字符ASCII做下标，索引是否出现过，和出现的位置
    int start = 0;//字串起始位置
    for(i=0;s[i]!='\0';i++)     
    {
        if(index[s[i]]>start)//如果字符出现过
        {                       
            count = i-start;//当前长度
            if(count>max)//取最长
            {
                max = count;
            }
            start = index[s[i]];
        }
        index[s[i]] = i+1;//标识字符出现的位置
    }
    count = i-start;
    return count>max?count:max;
}

// @lc code=end

