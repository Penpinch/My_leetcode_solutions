class Solution:
    def plusOne(self, digits):
       number = int("".join(map(str, digits))) + 1
       final_list = [int(x) for x in str(number)]
       return final_list
    
digits = [9, 9, 9, 9]
result = Solution()
print(result.plusOne(digits))
