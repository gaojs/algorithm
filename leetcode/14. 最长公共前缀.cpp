// https://leetcode-cn.com/problems/longest-common-prefix/

char * longestCommonPrefix(char ** strs, int strsSize){
    if (strs == NULL || strsSize == 0) {
	    printf("error param\n");
	    return "";
    } else {
        int mLen = INT_MAX;
        int mIndex = 0;
        for (int i = 0; i < strsSize; i++) {
            int tLen = strlen(strs[i]);
	        printf("tLen=%d\n", tLen);
            if (mLen > tLen) {
                mLen = tLen;
                mIndex = i;
            }
        }
	    printf("mLen=%d\n", mLen);
        int size = (int)(sizeof(char) * (mLen + 1));
        char *tStr = (char*)malloc(size);
        if (tStr == NULL) {
            return "";
        }
        for (int i = 0; i < mLen; i++) {
            int len = mLen - i;
            memset(tStr, 0, size);
            strncpy(tStr, strs[mIndex], len);
            printf("%s\n", tStr);
            bool ok = true;
            for (int k = 0; k < strsSize; k++) {
                if(strncmp(strs[k], tStr, len) != 0) {
                    printf("%s\n", strs[k]);
                    ok = false; 
                    break;
                }
            }
            if (ok) {
                return tStr;
            }
        }
        return "";
    }
}
