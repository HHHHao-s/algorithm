#include <iostream>
#include <fstream>
#include <vector>
#include <random>

using namespace std;

int main() {
    // 随机生成地图元素
    vector<string> element_names = {"BRICK", "GRASS", "RIVER", "IRON"};
    vector<pair<int, int>> positions;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis_x(0, 680);
    uniform_int_distribution<> dis_y(0, 480);
    for (int i = 0; i < 100; i++) {
        positions.push_back(make_pair(dis_x(gen), dis_y(gen)));
    }

    // 将地图元素写入文件
    ofstream outfile("map.txt");
    for (auto& name : element_names) {
        outfile << name << "=";
        bool first = true;
        for (auto& pos : positions) {
            if (dis_x(gen) < 50) {  // 50% 的概率将该元素放入该位置
                if (!first) {
                    outfile << ";";
                }
                outfile << pos.first << "," << pos.second;
                first = false;
            }
        }
        outfile << endl;
    }
    outfile.close();

    return 0;
}