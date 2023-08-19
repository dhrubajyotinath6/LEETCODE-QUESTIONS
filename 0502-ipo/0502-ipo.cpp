class Solution {
    
public:
    
  struct capitalCompare {
    bool operator()(const pair<int, int> &x, const pair<int, int> &y) { 
      return x.first > y.first; }
  };

  struct profitCompare {
    bool operator()(const pair<int, int> &x, const pair<int, int> &y) { 
      return y.first > x.first; }
  };
    
    
public:
    int findMaximizedCapital(int numberOfProjects, int initialCapital, vector<int>& profits, vector<int>& capital) {
        
    int n = profits.size();
        
    priority_queue<pair<int, int>, vector<pair<int, int>>, capitalCompare> minCapitalHeap;
        
    priority_queue<pair<int, int>, vector<pair<int, int>>, profitCompare> maxProfitHeap;

    // insert all project capitals to a min-heap
    for (int i = 0; i < n; i++) {
      minCapitalHeap.push(make_pair(capital[i], i));
    }

    // let's try to find a total of 'numberOfProjects' best projects
    int availableCapital = initialCapital;
        
    for (int i = 0; i < numberOfProjects; i++) {
      // find all projects that can be selected within the available capital and insert 
      // them in a max-heap
      while (!minCapitalHeap.empty() && minCapitalHeap.top().first <= availableCapital) {
        auto capitalIndex = minCapitalHeap.top().second;
        minCapitalHeap.pop();
        maxProfitHeap.push(make_pair(profits[capitalIndex], capitalIndex));
      }

      // terminate if we are not able to find any project that can be completed within 
      // the available capital
      if (maxProfitHeap.empty()) {
        break;
      }

      // select the project with the maximum profit
      availableCapital += maxProfitHeap.top().first;
      maxProfitHeap.pop();
    }

    return availableCapital;
    }
};