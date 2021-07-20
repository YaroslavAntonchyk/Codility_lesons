#include <iostream>

void dec2bin(int *arr, int N)
{
    int i = 0;
    uint mask = 0;
    while(N >= mask)
    {
        mask = (1 << i);
        arr[i] = N & mask ? true : false;
        i++;
    }
}

int solution(int N)
{
    int arr[31] = {};
    dec2bin(arr, N);
    int start = -1;
    int len = 0;
    int max_len = 0;

    for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
    {
        if(arr[i] && start < 0)
            start = i;
        else if(arr[i])
        {
            len = i - start - 1;
            start = i;
            if(len > max_len)
                max_len = len;
        }
    }
    return max_len;
}


int main()
{
    std::cout << "max len is: " << solution(247483647) <<  std::endl;
    return 0;
}