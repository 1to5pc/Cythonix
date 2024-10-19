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