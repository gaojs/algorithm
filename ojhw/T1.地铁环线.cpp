#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

bool SetContainItem(set<int> cnt, int item)
{
    return (cnt.find(item) != cnt.end());
}

int MinLineNums(vector<set<int>> &lines, map<int, set<int>> stationLines,
                const int &startStationId, const int &endStationId)
{
    set<int> startLines, endLines;
    int lineNum = lines.size();
    for (int lineId = 0; lineId < lineNum; lineId++) {
        if (SetContainItem(lines[lineId], startStationId)) {
            startLines.insert(lineId);
        }
        if (SetContainItem(lines[lineId], endStationId)) {
            endLines.insert(lineId);
        }
    }

    // 广度优先遍历
    int minLineNum = 1;
    set<int> visitedLineIds;
    while (!startLines.empty()) {
        set<int> nextLines; // 换成下一条线路
        for (auto it = startLines.begin(); it != startLines.end();) {
            int lineId = *it; // 当前线路ID
            if (SetContainItem(endLines, lineId)) {
                return minLineNum; // 能到终点
            }
            visitedLineIds.insert(lineId);
            for (int stationId: lines[lineId]) { // 每个站点
                set<int> lines = stationLines[stationId];
                for (int line:lines) { // 每个站点的每调线路
                    if (SetContainItem(visitedLineIds, line)) {
                        continue; // 已访问，略过
                    } else {
                        nextLines.insert(line);
                    }
                }
            }
            it = startLines.erase(it); // 删除该线路
        }
        startLines = nextLines;
        nextLines.clear();
        minLineNum++;
    }
    return -1; // 无法到达
}

int main()
{
    int lineNum;
    while (cin >> lineNum) {
        vector<int> lineStationNums(lineNum, 0);
        vector<set<int>> lines;
        for (int i = 0; i < lineNum; i++) {
            cin >> lineStationNums[i];
            set<int> line;
            lines.push_back(line);
        }
        int stationId; // 站点编号
        map<int, set<int>> stationLines; // 站点所在线路
        for (int i = 0; i < lineNum; i++) {
            for (int j = 0; j < lineStationNums[i]; j++) {
                cin >> stationId; // 输入站点编号
                lines[i].insert(stationId);
                stationLines[stationId].insert(i);
            }
        }

        int startStationId, endStationId;
        cin >> startStationId >> endStationId;
        cout << MinLineNums(lines, stationLines, startStationId, endStationId) << endl;
    }
    return 0;
}
