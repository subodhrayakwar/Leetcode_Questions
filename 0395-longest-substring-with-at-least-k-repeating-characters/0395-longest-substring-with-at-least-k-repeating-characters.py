class Solution(object):
    def longestSubstring(self, s, k):
        from collections import Counter

        def helper(substring):
            c = Counter(substring)
            bad_indices = [i for i in range(len(substring)) if c[substring[i]] < k]
            
            if not bad_indices:
                return len(substring)
            
            bad_indices = [-1] + bad_indices + [len(substring)]
            max_length = 0
            
            for i in range(len(bad_indices) - 1):
                max_length = max(max_length, helper(substring[bad_indices[i] + 1:bad_indices[i + 1]]))
            
            return max_length

        return helper(s)