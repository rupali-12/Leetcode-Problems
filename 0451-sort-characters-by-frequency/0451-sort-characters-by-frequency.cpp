class Solution {
public:
    string frequencySort(string s) {
          unordered_map<char, int> freq_map;
    for (char c : s) {
        freq_map[c]++;
    }
    
    // Step 2: Create buckets where index represents frequency
    int n = s.size();
    vector<vector<char>> buckets(n + 1);
    
    for (auto& pair : freq_map) {
        char character = pair.first;
        int freq = pair.second;
        buckets[freq].push_back(character);
    }
    
    // Step 3: Build the result string by going through the buckets
    string result = "";
    for (int i = n; i > 0; --i) {
        if (!buckets[i].empty()) {
            for (char c : buckets[i]) {
                result.append(i, c);  // Append the character 'i' times
            }
        }
    }
    
    return result;
    }
};