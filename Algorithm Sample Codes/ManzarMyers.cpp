#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> buildSuffixArray(const string &s) {
    int n = s.size();
    vector<int> suffixArray(n), rank(n), tmpRank(n);

    // 초기 접미사 정렬: 한 글자만 보고 사전순 정렬
    for (int i = 0; i < n; i++) {
        suffixArray[i] = i;
        rank[i] = s[i];
    }

    // k는 비교할 접미사의 길이를 나타냄
    for (int k = 1; k < n; k *= 2) {
        // 두 부분을 비교하는 방식: k길이의 접미사를 비교하고 그 다음 k길이 접미사 비교
        auto comparator = [&rank, &k, &n](int i, int j) -> bool {
            if (rank[i] != rank[j]) return rank[i] < rank[j];
            int ri = (i + k < n) ? rank[i + k] : -1;
            int rj = (j + k < n) ? rank[j + k] : -1;
            return ri < rj;
        };

        // 접미사 배열을 현재의 랭크를 기준으로 정렬
        sort(suffixArray.begin(), suffixArray.end(), comparator);

        // 임시 랭크 계산
        tmpRank[suffixArray[0]] = 0;
        for (int i = 1; i < n; i++) {
            tmpRank[suffixArray[i]] = tmpRank[suffixArray[i - 1]] +
                                      (comparator(suffixArray[i - 1], suffixArray[i]) ? 1 : 0);
        }

        // 랭크 배열을 업데이트
        rank = tmpRank;
    }

    return suffixArray;
}

int main() {
    string s = "banana";
    vector<int> suffixArray = buildSuffixArray(s);

    // 출력
    cout << "Suffix Array of '" << s << "':\n";
    for (int i = 0; i < suffixArray.size(); i++) {
        cout << suffixArray[i] << " ";
    }
    cout << endl;

    return 0;
}
