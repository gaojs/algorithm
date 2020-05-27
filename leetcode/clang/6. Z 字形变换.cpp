// https://leetcode-cn.com/problems/zigzag-conversion/
char *convert(char *s, int numRows){
    if (s == NULL || numRows == 0) {
        return "";        
    } 
    int len = strlen(s);
    int size =  len + 1;
    char *p = (char*)malloc(sizeof(char) * size);
    if (p == NULL) {
        return "";        
    }
    memset(p, 0, size);
    if (numRows == 1) {
        strncpy(p, s, len);
        return p;
    }
    
    int index = 0;    
    for (int i = 0; i < len; i += 2 * (numRows - 1)) {
        p[index++] = s[i];
    }    
    for (int r = 1; r < numRows - 1; r++) {
        // printf("\n"); 
        for (int i = r; i < len;) {
            // printf("a[%d]=%c ", i, s[i]);    
            p[index++] = s[i];
            i += 2 * (numRows - 1 - r );
            if (i < len) {
               // printf("a[%d]=%c ", i, s[i]);
               p[index++] = s[i];
               i += 2 * r;    
            }    
        }
        // printf("\n"); 
    }
    for (int i = numRows - 1; i < len; i += 2 * (numRows - 1)) {
        p[index++] = s[i];
    }
    return p;
}

