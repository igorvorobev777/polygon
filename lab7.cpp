#include<bits/stdc++.h>


using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        // +8 байт из-за копирования, + 2 байта из-за ссылок
        vector<pair<int, int>> cap_and_prof; // 24 + 8 * n байт
        // Создаем пары описывающие проекты
        for (int i=0; i < profits.size() ; i++) {
            // цикл за O(n)
            cap_and_prof.push_back(make_pair(capital[i], profits[i]));
        }
        // Сортируем по доступности
        sort(cap_and_prof.begin(), cap_and_prof.end()); // O(n*log n)
        // в possible_projects хранятся доступные в данный момент проекты
        priority_queue<pair<int, int>> possible_projects; // 24 + 16 * n байт
        // r указывает на первый проект который был недоступен на предыдущей итерации
        int r = 0; // + 4 байта
        k = min(k, (int)profits.size());
        for (int processed=1; processed <= k ; processed++) {
            // + 4 байта внутри цикла
            while ((r < (profits.size() - (k - processed))) && (cap_and_prof[r].first <= w)) {
                // + 4 байта внутри цикла
                // суммарно будет не более n итераций цикла
                // поэтому суммарно за все итерации не более O(n * log n) операций
                // добавляем проекты которые стали доступны
                possible_projects.push(make_pair(cap_and_prof[r].second, cap_and_prof[r].first)); // O(log n)
                r++;
                // здесь будет исользовано больше всего памяти, в худшем случаи 10 + 24 + 8 * n + 24 + 16 * n + 8 = 66 + 24 * n байт
            }

            if (possible_projects.empty()) {
                // если нет доступных
                return w;
            } else {
                // добавляем самый прибыльный из доступных
                w += possible_projects.top().first; // O(1)
                possible_projects.pop(); // O(log n)
            }
        }
        // Итоговая асимптотика O(n * log n)

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
