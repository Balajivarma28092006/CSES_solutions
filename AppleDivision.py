n = int(input())
l = list(map(int, input().split()))

total = sum(l)
ans = float('inf')

def solve(i, current_sum):
    global ans

    if i == n:
        ans = min(ans, abs(total - 2 * current_sum))
        return

    solve(i+1, current_sum+l[i])
    solve(i+1, current_sum)

solve(0, 0)
print(ans)
