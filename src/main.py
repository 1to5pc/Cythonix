def argParser():
    import sys
    try:
        file2parse=sys.argv[1]
        return file2parse, 0 # return filename and success code
    except:
        print("Filename not provided.")
        print("Syntax: main.py <inputFile>")
        return None , 1

#file,code = argParser()

#if code == 1:
#    exit()

def fileParser(fileName):
    fileContents = []
    import os

    if os.path.isfile(fileName) == True and open(fileName, 'r').read(1) != '':
        File = open(fileName, 'r')
        fileContents = File.read().split('\n')
        return fileContents , 0
    else:
        print("File does not exist or is empty.")
        return None , 1

#text,code1 = fileParser(file)

#if code1 == 1:
#    exit()
