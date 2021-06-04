import os
import sys

def listFile(workPath):
    for parent, dirnames, filenames in os.walk(workPath,  followlinks=True):
        for filename in filenames:
            filePath = os.path.join(parent, filename)
            fileType = filePath[-4:]
            if fileType == ".exe" :
                os.remove(filePath)
                print ("Delete " + filePath)
            # print (filePath)

def deleteExe():
    workPath = os.getcwd()
    listFile(workPath)

if __name__ == "__main__":
    deleteExe()