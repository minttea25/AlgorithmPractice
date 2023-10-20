// 확인 필요...
// 예제는 맞음

#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

vector<ll> getCount(int k, vector<int>& msum)
{
    vector<ll> cnt(k, 0);
    for(int i=0; i<msum.size(); ++i)
    {
        cnt[msum[i]] += 1;
    }
    return cnt;
}

int getAns1(int k, vector<ll>& cnt)
{
    int ans = 0;
    for(int i=0; i<k; ++i)
    {
        if (cnt[i] >= 2)
        {
            ans += cnt[i] * (cnt[i] - 1) / 2;
            ans %= 20091101;
        }
    }
    return ans;
}

int getAns2(int i, vector<int>& msum, vector<int>& cache)
{
    if (i==-1) return 0;

    int& ret = cache[i];
    if (ret != 0) return ret;

    ret = 0;

    int j = -1;
    for(int a=i; a>0; --a)
    {
        if (msum[a-1] == msum[i])
        {
            j = a;
            break;
        }
    }
    if (j >= 0) ret = getAns2(j-1, msum, cache) + 1;

    ret = max(ret, getAns2(i-1, msum, cache));

    return ret;
}

int main()
{
    cout.sync_with_stdio(false);
    cin.sync_with_stdio(false);

    vector<int> psum;
    vector<int> msum;
    int n, k;

    int tc;

    cin >> tc;
    for(int i=0; i<tc; ++i)
    {
        psum.clear();
        msum.clear();

        msum.push_back(0);

        cin >> n >> k;

        int t;
        cin >> t;
        psum.push_back(t);
        msum.push_back(t % k);
        for(int ii=1; ii<n; ++ii)
        {
            cin >> t;
            psum.push_back(t + psum[ii-1]);
            msum.push_back(psum[ii] % k);
        }

        // for(int ii=0; ii<n; ++ii) cout << psum[ii] << ' ';
        // cout << endl;
        // for(int ii=0; ii<n+1; ++ii) cout << msum[ii] << ' ';
        // cout << endl;

        vector<int> cache(n+1, 0);

        auto cnt = getCount(k, msum);
        cout << getAns1(k, cnt)  << ' ' << getAns2(n-1+1, msum, cache) << endl;
    }

    return 0;
}