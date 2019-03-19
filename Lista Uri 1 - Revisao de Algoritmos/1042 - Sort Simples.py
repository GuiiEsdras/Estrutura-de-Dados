# -*- coding: utf-8 -*-

nums = [int(x) for x in input().split()]
unsorted = nums[:]
nums.sort()
for i, v in enumerate(nums):
    print(v)
print("")
for i, v in enumerate(unsorted):
    print(v)
