import time

class TimeCheckUtil:

    def __init__(self):
        self.start_time = time.time()

    def print_exec_time(self):
        end_time = time.time()
        print('Exec Time : %s sec' %format(end_time-self.start_time,".6f"))
