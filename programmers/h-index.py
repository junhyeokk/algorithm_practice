from bisect import bisect_left, bisect_right

def solution(citations):
    citations.sort()
    
    answer = 0
    for i in range(citations[-1]):
        h = bisect_left(citations, i) + 1
        x = len(citations) - bisect_right(citations, i)
        if i <= x:
            answer = i
    return answer

citations = [0, 1, 1, 4, 6, 7]
print(solution(citations))