//https://leetcode.com/problems/course-schedule/description/

class Solution {
private:
    bool func(int course, unordered_map<int, vector<int>>&m, vector<int>v) {
        if (find(v.begin(), v.end(), course) == v.end()) {
            v.push_back(course);
            if (m[course].size() == 0) {
                return true; //because no prerequisites, so consider done
            }
            for(int i = 0; i<m[course].size(); i++){
                if (!func(m[course][i], m, v)) return false;
                else {
                    auto it = m[course].begin() + i;
                    m[course].erase(it);    
                }
            }
            return true; //all pre completed
        }
        else return false; //because cycle exists
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //map prep
        unordered_map<int, vector<int>>m;
        for (int i = 0; i<numCourses; i++) {
            vector<int>v;
            m[i] = v;
        }
        for (int i = 0; i<prerequisites.size(); i++) {
            int course = prerequisites[i][0];
            int pre = prerequisites[i][1];
            m[course].push_back(pre);
        }
        //check all nodes
        vector<int>visited;
        for (int i = 0; i<numCourses; i++) {
            if(!func(i, m, visited)) {
                return false;
            }
        }
        return true;
    }
};
