#include "s.h"
/*
 * @lc app=leetcode.cn id=874 lang=cpp
 *
 * [874] 模拟行走机器人
 */

// @lc code=start
class Solution
{
public:
    int robotSim(const std::vector<int> &commands, const std::vector<std::vector<int>> &obstacles)
    {

        std::unordered_map<int, set<int>> x_obs, y_obs;

        for (const auto &obstacle : obstacles)
        {
            x_obs[obstacle[0]].insert(obstacle[1]);
            y_obs[obstacle[1]].insert(obstacle[0]);
        }

        int x = 0, y = 0;
        int dir = 0; // 0->north 1->east 2->south 3->west
        int ans = 0;

        for (int i = 0; i < commands.size(); i++)
        {
            int command = commands[i];
            if (command == -1)
            {
                dir = (dir + 1) % 4;
            }
            else if (command == -2)
            {
                dir = (dir + 3) % 4;
            }
            else
            {
                if (dir == 0 || dir == 2)
                {
                    if (x_obs.count(x))
                    {
                        auto &obs = x_obs[x];
                        if (dir == 0)
                        {
                            auto it_up = obs.upper_bound(y);

                            if (it_up != obs.end())
                            {
                                if (y + command >= *it_up)
                                {
                                    y = *it_up - 1;
                                }
                                else
                                {
                                    y += command;
                                }
                            }else{
                                y+=command;
                            }
                        }
                        else
                        {
                            auto it_low = --obs.lower_bound(y);
                            if (it_low != obs.end() && *it_low < y)
                            {

                                if (y - command <= *it_low)
                                {
                                    y = *it_low + 1;
                                }
                                else
                                {
                                    y -= command;
                                }
                            }else{
                                y-=command;
                            }
                        }
                    }
                    else
                    {
                        if (dir == 0)
                        {
                            y += command;
                        }
                        else
                        {
                            y -= command;
                        }
                    }
                }
                else
                {
                    if (y_obs.count(y))
                    {
                        auto &obs = y_obs[y];
                        if (dir == 1)
                        {
                            auto it_right = obs.upper_bound(x);

                            if (it_right != obs.end())
                            {
                                if (x + command >= *it_right)
                                {
                                    x = *it_right - 1;
                                }
                                else
                                {
                                    x += command;
                                }
                            }else{
                                x+=command;
                            }
                        }
                        else
                        {
                            auto it_left = --obs.lower_bound(y);
                            if (it_left != obs.end() && *it_left < x)
                            {

                                if (x - command <= *it_left)
                                {
                                    x = *it_left + 1;
                                }
                                else
                                {
                                    x -= command;
                                }
                            }else{
                                x-=command;
                            }
                        }
                    }
                    else
                    {
                        if (dir == 1)
                        {
                            x += command;
                        }
                        else
                        {
                            x -= command;
                        }
                    }
                }
            }
            ans = max(ans, x * x + y * y);
        }

        return ans;
    }
};

// @lc code=end
int main()
{

    Solution s;

    cout << s.robotSim({2, -1, 8, -1, 6}, {{1, 5}, {-5, -5}, {0, 4}, {-1, -1}, {4, 5}, {-5, -3}, {-2, 1}, {-2, -5}, {0, 5}, {0, -1}});
    cout << s.robotSim({6, -1, -1, 6}, {});

    return 0;
}