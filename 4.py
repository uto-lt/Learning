def max_xor_sum(n, k, nums):
    # 计算数组中每个元素与前缀异或的结果
    prefix_xor = [0]
    for num in nums:
        prefix_xor.append(prefix_xor[-1] ^ num)
    
    # dp[i][j] 表示将前 i 个数分割成 j 段所能得到的最大和
    dp = [[0] * (k + 1) for _ in range(n + 1)]
    
    for i in range(1, n + 1):
        for j in range(1, min(i, k) + 1):
            # 分割段数与数组下标相等时，结果即为当前位置的前缀异或和
            if j == i:
                dp[i][j] = prefix_xor[i]
            else:
                # 遍历所有可能的分割位置
                for split in range(j - 1, i):
                    dp[i][j] = max(dp[i][j], dp[split][j - 1] + (prefix_xor[i] ^ prefix_xor[split]))
    
    return dp[n][k]

# 读取输入
n, k = map(int, input().split())
nums = list(map(int, input().split()))

# 输出结果
print(max_xor_sum(n, k, nums))
