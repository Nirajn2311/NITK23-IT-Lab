
import sys,os,re,pathlib


def main():

    if len(sys.argv) != 2:
        return

    filename = sys.argv[1]

    basename = os.path.basename(sys.argv[1])
    (file, ext) = os.path.splitext(basename)

    if ext == '.cpp':
        os.system('g++ '+filename)
    elif ext == '.c':
        os.system('gcc '+filename)
    else:
        print('Unsupported file format.')
        return

    for i in range(1,11):
        print("\nRunning Test Case ",i)
        testfile = 'input'+str(i)+'.txt'
        os.system('./a.out '+testfile)

        # Output generated in output.txt file. Run decoder on this
        os.system('python3 decoder.py output.txt')
        
if __name__ == '__main__':
    main()