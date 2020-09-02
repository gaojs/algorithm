    bool judgeCircle(string moves) {
        int uc, dc, lc, rc;

        uc = dc = lc = rc = 0;
        for(char c : moves) {
            switch(c) {
                case 'U':
                    uc++;
                    break;
                case 'D':
                    dc++;
                    break;
                case 'L':
                    lc++;
                    break;
                case 'R':
                    rc++;
                    break;
            }
        }
        return (uc == dc) && (lc == rc);
    }