#include <iostream>
#include <string>
#include <stack>
using namespace std;

string dec2some(uint32_t num, uint32_t notation)
{
    string res;
    if (notation >= 2 && notation <= 36)
    {
        const char digs[] = "0123";
        stack <uint32_t> st;
        int bin = 0, k = 1;
        while (num)
        {
            bin += (num % 2) * k;
            k *= 10;
            num /= 2;
        }
        while (!st.empty())
        {
            res += digs[st.top()];
            st.pop();
        }
    }
    return res;
}

int main()
{
    cout << dec2some(1234, 16);
}