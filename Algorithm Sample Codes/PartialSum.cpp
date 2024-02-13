// not tested

#include <iostream>
#include <vector>

using namespace std;

vector<int> accSum(const vector<int>& arr)
{
    vector<int> ret(arr.size());
    ret[0] = arr[0];
    for(int i=1; i<arr.size(); ++i)
    {
        ret[i] = ret[i-1] + arr[i];
    }
    return ret;
}

int partialSum(const vector<int>& aSum, const int a, const int b)
{
    if (a==0) return aSum[b];
    else return aSum[b] - aSum[a-1];
}

vector<int> sqAccSum(const vector<int>& arr)
{
    vector<int> ret(arr.size());
    ret[0] = arr[0] * arr[0];
    for(int i=1; i<arr.size(); ++i)
    {
        ret[i] = ret[i-1] + (arr[i] * arr[i]);
    }
    return ret;
}

double partialVariance(const vector<int>& aSum, const vector<int>& sqASum, const int a, const int b)
{
    // calc avg
    double mean = partialSum(aSum, a, b) / static_cast<double>(b - a + 1);
    double ret = partialSum(sqASum, a, b) - 2 * mean * partialSum(aSum, a, b) + (b - a + 1) * mean * mean;
    return ret / (b - a + 1);
}

