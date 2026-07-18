class Solution:
    def twoSum(self, nums, target):
        used = dict()
        for index, num in enumerate(nums):
            suma = target - num
            if suma in used:
                return [index, used[suma]]
            used[num] = index
        return []
            

nums = [3, 3]
target = 6

solucion = Solution()

print(solucion.twoSum(nums, target))
