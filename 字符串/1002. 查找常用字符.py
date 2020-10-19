class Solution:
    def commonChars(self, A: List[str]) -> List[str]:
        from functools import reduce
        return list(reduce(lambda x, y: x & y, map(collections.Counter, A)).elements())

    def commonChars2(self, A: List[str]) -> List[str]:
        from collections import Counter
        ans = Counter(A[0])
        for i in A[1:]:
            ans &= Counter(i)
        return list(ans.elements())
