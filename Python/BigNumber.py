from util.CheckTime import TimeCheckUtil

def main():

    # Test Vector
    # line 1: 5 8 3
    # line 2: 2 4 5 4 6

    print('### BigNumber.py ###') # Chap3. Exercise 3-2.
    tc = TimeCheckUtil() # init start time

    line1 = '5 8 3'
    line2 = '2 4 5 4 6'

    #### Code ####

    try :
        result = find_result(line1, line2)
    except ValueError as e:
        print('잘못된 값이 입력되었습니다.', e)
        return 1

    print('Result : ', str(result))

    #### Code ####

    tc.print_exec_time() # print time duration

    return 0

def find_result(info, data):
    info = list(map(int, info.split())) # 입력 처리
    data = list(map(int, data.split())) # 입력 처리

    N = info[0] # data list 크기. (2 <= N <= 1,000)
    M = info[1] # 덧셈 연산 횟수. (1 <= M <= 10,000)
    K = info[2] # 최대 연속 덧셈 가능 횟수. 단, 값이 같아도 다른 인덱스에 있으면 다른 수로 간주. (1 <= K <= 10,000)

    # 입력값 검증
    if 2 > N or N > 1000:
        raise ValueError
    
    if 1 > M or 10000 < M:
        raise ValueError
    
    if 1 > K or 10000 < K:
        raise ValueError
    
    data.sort(reverse=True)

    biggest_number = data[0]
    second_biggest_number = data[1]

    k = 0
    sum = 0

    for m in range(M):
        if k < K:
            sum += biggest_number
            k += 1
        else :
            sum += second_biggest_number
            k = 0
    
    return sum

main()