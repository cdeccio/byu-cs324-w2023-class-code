import os
import sys
import subprocess
import time

def main():
    time.sleep(1)
    p = subprocess.Popen(['/bin/cat', 'foo'])
    time.sleep(2)

if __name__ == '__main__':
    main()
