class Solution {
public:
    unordered_map<int, string> mp;
    int id=0;
    string encode(string longUrl) {
        id++;
        mp[id]=longUrl;
        return "http://tinyurl.com/"+to_string(id);
    }

    string decode(string shortUrl) {
        stringstream ss(shortUrl);
        string item="";
        while(getline(ss, item, '/'));
        return mp[stoi(item)];
    }
};
