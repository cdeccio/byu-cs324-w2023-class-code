import os
import sys
import subprocess
import time

def main():
    p = subprocess.Popen(['/bin/cat', 'foo'],
            stdout=subprocess.PIPE)
    p.wait()
    print('received', p.stdout.read())

if __name__ == '__main__':
    main()
