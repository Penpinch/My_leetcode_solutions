class Solution:
    def fizzBuzz(self, n: int):
        lista = []
        i = 1
        while i <= n:
            if i % 3 == 0 and i % 5 == 0:
                lista.append("FizzBuzz")
            elif i % 3 == 0:
                lista.append("Fizz")
            elif i % 5 == 0:
                lista.append("Buzz")
            else:
                lista.append(str(i))
            i += 1  
        return lista
n = 15
resultado = Solution()
print(resultado.fizzBuzz(n))
