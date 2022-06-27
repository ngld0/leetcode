class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
         // [[100,200],[200,1300],[1000,1250],[2000,3200]]
        // sorting ascending courses by lastDay =>
        // [[100,200],[1000,1250],[200,1300],[2000,3200]]
        sort(courses.begin(), courses.end(),[](vector<int> a,vector<int> b){
           return a[1] < b[1]; 
            
        });
        //using priority queue to save the course duration,
        priority_queue<int> qq;
        int sum = 0;
        
        for(auto course: courses){
            sum += course[0];
            qq.push(course[0]);
            //if sum duration of the taken courses greater than lastday, then we shouldnot take this course. 
            if(sum > course[1]){
                sum -= qq.top();
                qq.pop();
            }
        }
        return qq.size(); 
    }
};
