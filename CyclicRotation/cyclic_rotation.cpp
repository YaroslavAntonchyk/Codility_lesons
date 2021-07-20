#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(vector<int> &A, int K)
{
    if(K <= 0 || A.size() <= 0)
        return A;

    vector<int> out_vec(A.size());

    if(K > A.size())
        K = K % A.size();

    for(int i = 0; i < A.size(); i++)
    {
        if(i + K < A.size())
            out_vec[K + i] = A[i];
        else
            out_vec[K + i - A.size()] = A[i];
    }

    return out_vec;
}

int main()
{
    vector<int> A {1, 2, 3, 4};
    for(int j = 1; j < 6; j++)
    {   
        cout << "rotate " << j << " times" << endl;
        vector<int> rot_vec = solution(A, j);
        for(int i : rot_vec)
            cout << i << ", ";
        cout << endl;
    }
    
    return 0;
}