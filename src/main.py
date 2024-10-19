def argParser():
    import sys
    try:
        file2parse=sys.argv[1]
        fileOut=sys.argv[2]
        return file2parse, fileOut, 0 # return filename and success code
    except:
        print("Filename not provided.")
        print("Syntax: main.py <inputfile> <outputfile>")
        return None , 1

fileIn, fileOut, code = argParser()

if code == 1:
    exit()

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
    File.close()

text,code1 = fileParser(fileIn)

if code1 == 1:
    exit()

def stringDetect(inputText):
    strings=[]
    for line in inputText:
        if 'print' in line:
            for index in range(len(line)):
                if line[index] == "'" or line[index] == '"':
                    defsymbol = line[index]
                    startIndex = index
                    break
            index = 0
            for index in range(startIndex+1, len(line)):
                if line[index] == defsymbol:
                    stopIndex = index
                    break
            strings.append(line[startIndex+1:stopIndex]) # Extract strings from all print commands
    return strings

strings = stringDetect(text)
print(strings)

def C_gen(strings,fileOut):
    writeFile = open(fileOut)