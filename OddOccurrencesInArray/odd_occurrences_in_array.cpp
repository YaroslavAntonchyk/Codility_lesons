#include <iostream>
#include <vector>

using namespace std;

struct dict
{
    int key{};
    int value{};
};

void print_dict(dict * dd, int len)
{
    cout << "len: " << len;
    for(int j = 0; j < len; j++)
        cout << " key: " << dd[j].key << " value: " << dd[j].value << endl;
    cout << endl << endl;
}

int find(dict * dd, int key, int len)
{
    for(int j = 0; j < len; j++)
        if(dd[j].key == key)
            return j;
    return -1;
}

int solution(vector<int> &A)
{
    dict * occurrences = new dict[A.size()];
    int len = 0;
    int even = -1;
    int idx = 0;
    for(auto i : A)
    {
        idx = find(occurrences, i, len);
        if(idx >= 0)
            occurrences[idx].value++;
        else
        {
            occurrences[len] = {i, 1};
            len++;
        }
        // print_dict(occurrences, len);
    }

    for(int i = 0; i < len; i++)
    {
        if(occurrences[i].value & (1 << 0))
        {
            even = occurrences[i].key;
            break;
        }
    }

    delete [] occurrences;
    return even;
}



int main()
{
    vector<int> vec {9, 3, 9, 3, 9, 7, 9};
    cout << solution(vec) << " test" << endl;
    return 0;
}