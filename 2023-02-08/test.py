import os
import sys
import subprocess
import time

def main():
    time.sleep(2)
    f = open('foo1.txt', 'w')
    p = subprocess.Popen(['/bin/cat', 'foo'], stdout=f)
    f.close()
    p.wait()

if __name__ == '__main__':
    main()
