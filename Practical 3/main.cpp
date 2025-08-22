class Solution {
  public:
    vector<vector<int>> countFreq(vector<int>& arr) {
       std::unordered_map<int, int> freq;
       
       for(int i : arr)
       {
           freq[i] += 1;
       }
       
       vector<vector<int>> res(freq.size());
       
       int i = 0;
       
       for(auto it = freq.begin(); it != freq.end(); ++it){
           res[i].push_back(it->first);
           res[i].push_back(it->second);
           i++;
       }
       
       return res;
        
    }
};
