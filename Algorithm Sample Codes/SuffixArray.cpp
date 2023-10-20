#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 각 접미사들의 첫 t 글자를 기준으로 한 그룹 번호가 주어질 때
// 주어진 두 접미사를 첫 2*t 글자 기준으로 비교
// Note: group은 len=0인 접미사도 포함

struct Comp
{
    const vector<int>& group;
    int t;
    Comp(const vector<int>& _group, int _t) : group(_group), t(_t) {}

    // 오름차순
    bool operator() (const int a, const int b)
    {
        // t=0 부터 글자 비교
        if (group[a] != group[b]) return group[a] < group[b];
        // 첫번째 글자가 같으만 다음 비교대상 (+t)으로 비교
        else return group[a + t] < group[b + t];
    }
};

vector<int> getSuffixArray(const string& s)
{
    const int n = s.size();

    // group[i] = 접미사들을 첫 t글자를 기준으로 정렬했을 때, s[i, ..]가 들어가는 그룹 번호
    
    int t = 1;
    vector<int> group(n+1); // 길이가 0인 것까지 계산
    for(int i=0; i<n; ++i) group[i] = s[i]; // 값은 char 값
    group[n] = -1;

    // 직접적으로 정렬을 할 배열 생성 (가지고 있는 값은 index of s)
    // 이 값이 s에서 i로 시작되는 접미사
    vector<int> perm(n);
    for(int i=0; i<n; ++i) perm[i] = i;

    while (t < n) 
    {
        // 현재 group은 각 접미사의 t길이 만큼(앞 t글자만큼)으로 계산되어 있음
        // 첫 2t글자를 기준으로 perm 정렬 (사전순 대로 정렬, 기준은 group이고 이에 대해 이동은 perm에서 진행)

        Comp comparator(group, t); // comparator 생성 (t로 정렬할)

        // 정렬 (앞에서 부터 t만큼의 글자만 보고)
        sort(perm.begin(), perm.end(), comparator);

        // 만약 2t글자가 n보다 클 경우 더 이상 더 많은 글자를 확인하여 정렬 불가, perm이 접미사 배열
        t *= 2;
        if (t >= n) break;

        // 2t 글자를 기준으로 새로운 그룹을 생성
        vector<int> newGroup(n+1);
        // 동일하게 마지막은 -1로 하여 없는 글자 취급 (어떤 문자든 -1보다는 크겠죠~?)
        newGroup[n] = -1;
        // 현재 perm은 group에 기반하여 정렬되어 있는 상태
        // perm[0]의 값이 현재 만들려는 접미사 배열(perm)에서 사전 순으로 가장 앞에 있는 접미사에 대한 s에서의 시작 index
        // ex) s="piano"에서 현재 perm[0]의 값은 2 (ano)이 될 것이다. (ano가 사전순으로 가장 앞, 앞에서부터 t글자 확인했을 때)
        newGroup[perm[0]] = 0; // 가장 앞에 오므로 0
        for(int i=1; i<n; ++i)
        {
            // i에 대해 앞에서 부터 t를 글자를 확인 했을 때, 사전순으로 더 뒤에 오면 group 번호를 하나 올린다. 
            // i-1이랑 비교해서 현재 위치가 맞는 지 확인 (t가 증가하면서 처음은 같은 알파벳이어도 이후 사전 순으로 다시 정렬될 수 있음)
            newGroup[perm[i]] = newGroup[perm[i-1]] + (comparator(perm[i-1], perm[i]) == true ? 1 : 0);
        }
        group = newGroup;
    }

    return perm;
}

int main()
{
    string s = "kurunekururi";

    vector<int> a = getSuffixArray(s);

    for(int i=0; i<a.size(); ++i)
    {
        cout << "i: " << i << " A[i]: " << a[i] << " - ";
        for(int ii=a[i]; ii<a.size(); ++ii)
        {
            cout << s[ii];
        }
        cout << endl;
    }

    return 0;
    
}