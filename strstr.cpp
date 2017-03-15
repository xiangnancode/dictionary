
    /**
     * Returns a index to the first occurrence of target in source,
     * or -1  if target is not part of source.
     * @param source string to be scanned.
     * @param target string containing the sequence of characters to match.
     */


     #include <iostream>

using namespace std;

    int main () {
        // write your code here
        const char source[] = "abcdabcdefg";
        const char target[] = "bcd";
        
        if (sizeof(source) == 0 || sizeof(target) == 0) // == NULL
        {
            cout << "position is -1" << endl;
                        return -1;
        }
        int slen = strlen(source);
        int tlen = strlen(target);
        if(!tlen)
        {
            cout << "position is " << 0 << endl;
            return 0;
        }
        int j=0;
        int position = 0;
        bool found = 0;
        
        if (slen >= tlen)
        {
            for (int i = 0; i < slen; i++)
            {
                for (j = 0; j < tlen; j++)
                {
                    if (source[i+j] == target[j])
                    {
                        if(!found)
                        {
                            found = 1;
                            position = i;
                        }
                        
                    }
                    else
                    {
                        found = 0;
                        break;
                    }
                }
                if (j == tlen)
                {
                    cout << "position is " << position << endl;
                    return 0;
                }
            }
        }
        
        cout << "position is -1" << endl;
        return 0;
    }


