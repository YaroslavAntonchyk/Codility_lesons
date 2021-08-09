#include <iostream>
#include <math.h>
#include <chrono>

using namespace std;

int solution(int X, int Y, int D)
{
    return ((Y - X) + (D - 1)) / D;
}

int main()
{
    auto start = chrono::high_resolution_clock::now();
    for(int i = 0; i < 10000; i++)
        // cout << solution(0, 1000000, 1) << endl;
        solution(0, 1000000, 1);
    auto finish = std::chrono::high_resolution_clock::now();
    cout << (finish - start).count() << endl;
    return 0;
}