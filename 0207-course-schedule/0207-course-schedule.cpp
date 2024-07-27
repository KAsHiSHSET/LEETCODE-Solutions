class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if (numCourses <= 1 || prerequisites.empty()) {
            return true;
        }
        vector<vector<int>> matrix(numCourses, vector<int>(numCourses, 0));
        vector<int> requirements(numCourses, 0);

        for (const auto& each : prerequisites) {
            int course = each[0];
            int pre = each[1];
            if (matrix[pre][course] == 0) {
                requirements[course]++;
            }
            matrix[pre][course] = 1;
        }
        queue<int> stack;
        for (int i = 0; i < numCourses; ++i) {
            if (requirements[i] == 0) {
                stack.push(i);
            }
        }
        int counter = 0;
        while (!stack.empty()) {
            int course = stack.front();
            stack.pop();
            counter++;
            for (int i = 0; i < numCourses; ++i) {
                if (matrix[course][i] != 0) {
                    requirements[i]--;
                    if (requirements[i] == 0) {
                        stack.push(i);
                    }
                }
            }
        }
        return counter == numCourses;
    }
};