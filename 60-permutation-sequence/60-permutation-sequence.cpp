//STRIVER_SDE_SHEET

class Solution
{
public:
	std::string getPermutation(const int n, const int k)
	{
		std::string ans(n, 0);
		std::iota(ans.begin(), ans.end(), '1');
		for(int i = 1 ; i < k ; i++)
			nextPermutation(ans);
		return ans;
	}
private:
	void nextPermutation(std::string& s) //just change from vector to string.
	{
		int idecr = s.size() - 1;
		while(idecr > 0 && s[idecr - 1] >= s[idecr]) // This is O(n), because at most idecr traverses from n-1 to 0
			idecr--;
		if(idecr > 0)
			std::swap(s[idecr - 1], *std::upper_bound(s.rbegin(), s.rend() - idecr, s[idecr - 1])); // O(logn) for std::upper_bound
		std::reverse(s.begin() + idecr, s.end()); // O(n) for std::reverse
		return;
	} // Final Time Complexity O(n)
};