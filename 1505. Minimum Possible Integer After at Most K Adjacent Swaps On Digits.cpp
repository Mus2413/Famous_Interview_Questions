class Solution {
public:
    string minInteger(string num, int k) {
        int n = num.length();
        string ans(n,'-');
        int i = 0;
        int first = '0';
        int start = 0;
        int end   = n-1;
        bool found = true;
        while (found == true)
        {
            found = false;
            for (char d = first; d<='9' && k>0 && !found; d++)
            {
                int j, l;
                for (j = start, l=0; j<=end && k>=l; j++)
                {
                    if (num[j] == d)
                    {
                        found = true;
                        // cout << d << endl;
                        ans[i++] = d;
                        num[j] = '-';
                        k -= l;
                        if (d != first)
                            break;
                    }
                    else if (num[j] != '-') l++;
                }
                if (j>end && d== first) first++;
                while (end  >= start && num[end] == '-') end--;
                while (start <= end && num[start] == '-') start++;
            }
        }
        int j=start;
        while (i<n)
        {
            if (num[j] == '-')
            {
                j++;
                continue;
            }
            ans[i++] = num[j++];
        }
        return ans;
    }
};