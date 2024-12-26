#include<bits/stdc++.h>


using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        // +8 ���� ��-�� �����������, + 2 ����� ��-�� ������
        vector<pair<int, int>> cap_and_prof; // 24 + 8 * n ����
        // ������� ���� ����������� �������
        for (int i=0; i < profits.size() ; i++) {
            // ���� �� O(n)
            cap_and_prof.push_back(make_pair(capital[i], profits[i]));
        }
        // ��������� �� �����������
        sort(cap_and_prof.begin(), cap_and_prof.end()); // O(n*log n)
        // � possible_projects �������� ��������� � ������ ������ �������
        priority_queue<pair<int, int>> possible_projects; // 24 + 16 * n ����
        // r ��������� �� ������ ������ ������� ��� ���������� �� ���������� ��������
        int r = 0; // + 4 �����
        k = min(k, (int)profits.size());
        for (int processed=1; processed <= k ; processed++) {
            // + 4 ����� ������ �����
            while ((r < (profits.size() - (k - processed))) && (cap_and_prof[r].first <= w)) {
                // + 4 ����� ������ �����
                // �������� ����� �� ����� n �������� �����
                // ������� �������� �� ��� �������� �� ����� O(n * log n) ��������
                // ��������� ������� ������� ����� ��������
                possible_projects.push(make_pair(cap_and_prof[r].second, cap_and_prof[r].first)); // O(log n)
                r++;
                // ����� ����� ����������� ������ ����� ������, � ������ ������ 10 + 24 + 8 * n + 24 + 16 * n + 8 = 66 + 24 * n ����
            }

            if (possible_projects.empty()) {
                // ���� ��� ���������
                return w;
            } else {
                // ��������� ����� ���������� �� ���������
                w += possible_projects.top().first; // O(1)
                possible_projects.pop(); // O(log n)
            }
        }
        // �������� ����������� O(n * log n)

        return w;
    }
};


int main() {
    Solution sol1;
    int k, w;
    vector<int> profits, capital;
    cin >> k >> w;
    int n;
    cin >> n;
    for (int i=0; i < n ; i++) {
        int inp_val;
        cin >> inp_val;
        profits.push_back(inp_val);
    }
    for (int i=0; i < n ; i++) {
        int inp_val;
        cin >> inp_val;
        capital.push_back(inp_val);
    }
    cout << sol1.findMaximizedCapital(k, w, profits, capital);
}
