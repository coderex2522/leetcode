#if 0
string largestNumber(vector<int>& nums)
{
    vector<string> nums_string;
    for (auto i : nums) nums_string.push_back(to_string(i));
    sort(nums_string.begin(), nums_string.end(), CustomGreater);
    string result;
    for (const auto& s: nums_string) result += s;
    if (result.length() > 0 && result[0] == '0') return "0";
    return result;
}

static bool CustomGreater(const string& a, const string& b)
{
    const string ab = a + b;
    const string ba = b + a;
    return ab > ba;
}
#endif // 1
