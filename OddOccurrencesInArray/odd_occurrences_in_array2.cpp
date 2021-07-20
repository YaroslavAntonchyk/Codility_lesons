#include <iostream>
#include <vector>
#include <map>
#include <cstring>

using namespace std;

// much optimal for A with big amount of elements, because of the hash function calculation
int solution(vector<int> &A)
{
    std::map<int, int> occurrences{};

    for(auto i : A)
        occurrences[i] += 1;

    for(int i = 0; i < occurrences.size(); i++)
        if(occurrences[i] & (1 << 0))
            return i;

    return -1;
}

int main()
{
    vector<int> vec {9, 3, 9, 3, 9, 7, 9, 4, 1, 1};
    cout << solution(vec) << endl;
    return 0;
}