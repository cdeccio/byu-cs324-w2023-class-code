import os
import sys
import subprocess
import time

def main():
    p = subprocess.Popen(['/bin/sleep', '5'])
    p.wait()

if __name__ == '__main__':
    main()
