from util.CheckTime import TimeCheckUtil

def calc_min_coins(coins, N) :

    coins.sort(reverse=True) # 내림차순 정렬

    count_coins = 0
    
    for coin in coins:
        count_coins += N // coin # 몫(quotient) 구해서 더하기
        N %= coin

    return count_coins


print('### Mincoins.py ###') # Chap3. Exercise 3-1.
tc = TimeCheckUtil() # init start time

coins = [10, 50, 100, 500]
N = 1260

### Code ###

print('Input : %s' %N)
print('Answer : %s coins.' %calc_min_coins(coins, N))

### Code ###

tc.print_exec_time() # print time duration