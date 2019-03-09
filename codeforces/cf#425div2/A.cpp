    #include <iostream>
    #include <cstdio>
    #include <cstdlib>
    #include <cstring>
    #include <string>
    #include <algorithm>
    using namespace std;

    const int MAXN = 410;

    struct bign
    {
        int len, s[MAXN];
        bign ()
        {
            memset(s, 0, sizeof(s));
            len = 1;
        }
        bign (int num) { *this = num; }
        bign (const char *num) { *this = num; }
        bign operator = (const int num)
        {
            char s[MAXN];
            sprintf(s, "%d", num);
            *this = s;
            return *this;
        }
        bign operator = (const char *num)
        {
            for(int i = 0; num[i] == '0'; num++) ;  //去前导0
            len = strlen(num);
            for(int i = 0; i < len; i++) s[i] = num[len-i-1] - '0';
            return *this;
        }
        bign operator + (const bign &b) const //+
        {
            bign c;
            c.len = 0;
            for(int i = 0, g = 0; g || i < max(len, b.len); i++)
            {
                int x = g;
                if(i < len) x += s[i];
                if(i < b.len) x += b.s[i];
                c.s[c.len++] = x % 10;
                g = x / 10;
            }
            return c;
        }

        void clean()
        {
            while(len > 1 && !s[len-1]) len--;
        }

        bign operator - (const bign &b)
        {
            bign c;
            c.len = 0;
            for(int i = 0, g = 0; i < len; i++)
            {
                int x = s[i] - g;
                if(i < b.len) x -= b.s[i];
                if(x >= 0) g = 0;
                else
                {
                    g = 1;
                    x += 10;
                }
                c.s[c.len++] = x;
            }
            c.clean();
            return c;
        }



        string str() const
        {
            string res = "";
            for(int i = 0; i < len; i++) res = char(s[i]+'0') + res;
            return res;
        }
    };

    istream& operator >> (istream &in, bign &x)
    {
        string s;
        in >> s;
        x = s.c_str();
        return in;
    }

    ostream& operator << (ostream &out, const bign &x)
    {
        out << x.str();
        return out;
    }

    int main()
    {
        bign a, b, c;
        while(cin>>a>>b)
        {
            a.clean(), b.clean();
            c = a+b;


            cout<<"a+b"<<"="<<c<<endl; // a += b

        }
        return 0;
    }
