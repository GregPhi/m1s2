import sys
from ExpSetup import generatorCSV

def main(args):
    if(len(args)==7):
        generatorCSV(args[1],int(args[2]),int(args[3]),int(args[4]),int(args[5]),int(args[6]))
    else:
        print("FALSE")

if __name__ == "__main__":
    main(sys.argv)
