# Author: kamine
# Created: 2024-09-01 10:17:19

dp = [[0] * 51 for _ in range(51)]
dp[0][0] = 1

# Điền giá trị cho mảng dp theo công thức Stirling số thứ hai
for n in range(1, 51):
    for k in range(1, 51):
        dp[n][k] = k * dp[n - 1][k] + dp[n - 1][k - 1]
# Tính tổng kết quả cho mỗi giá trị n từ 1 đến 50
ans = [0] * 51
for i in range(1, 51):
    for j in range(1, i + 1):
        ans[i] += dp[i][j]

# Nhận số lượng test case
t = int(input())
for _ in range(t):
    n = int(input())
    print(ans[n])