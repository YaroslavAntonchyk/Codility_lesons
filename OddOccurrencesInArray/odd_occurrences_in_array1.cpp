#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

//fast but working only if A includes integers within range [1..1 000 000]
int solution(vector<int> &A)
{
    unsigned int len = 1000000;
    int occurrences[len];
    memset(occurrences, 0, len);

    for(auto i : A)
    {
        if(i > len)
            return -1;
        occurrences[i] += 1;
    }

    for(int i = 0; i < len; i++)
        if(occurrences[i] & (1 << 0))
            return i;
    return -1;
}

int main()
{
    vector<int> vec {9, 3, 9, 3, 9, 7, 9};
    cout << solution(vec) << endl;
    return 0;
}