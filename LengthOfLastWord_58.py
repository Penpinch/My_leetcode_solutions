class Solution:
    def lengthOfLastWord(self, s):
        words_list = s.split()
        length = len(words_list[-1])
        return length
    
s = " fly me  to  the moon "

last_word = Solution()
print(last_word.lengthOfLastWord(s))
