class Solution {
        public String reorganizeString(String S) {
        int[] charCount = new int[26];
        for ( char c : S.toCharArray() ) {
            ++charCount[c - 'a'];
        }

        int maxIndex = 0, countIndex = 0;
        for ( int i = 0 ; i < charCount.length ; ++i )
            if ( charCount[i] > charCount[maxIndex] )
                maxIndex = i;

        if ( S.length() == 0 || charCount[maxIndex] > (int)Math.ceil((float)S.length() / 2) )
            return "";

        StringBuilder ret = new StringBuilder(S);
        for ( int i = 0 ; ; i += 2 ) {
            if ( i >= ret.length() ) {
                if ( i % 2 == 0 ) i = 1;
                else break;
            }

            if ( charCount[maxIndex] > 0 ) {
                ret.setCharAt(i, (char) ('a' + maxIndex));
                --charCount[maxIndex];
            }
            else {
                while ( countIndex == maxIndex || charCount[countIndex] == 0 )
                    ++countIndex;

                ret.setCharAt(i, (char)('a' + countIndex));
                --charCount[countIndex];
            }
        }
        return ret.toString();
    }
}
