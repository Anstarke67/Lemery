import os
import sys
import time
import serial

def main():
         if len(sysargv) != :
             print "Usage : python flashpy [port]"
             return
    
     port = sysargv[ ]
     ser = serialSerial(port,   , timeout= )
     timesleep()
    
     print "Erasing"
     serwrite("erase\r")
     timesleep()
    
     print "Programming"
     serwrite("prog flashbin\r")
     timesleep()
   
     print "Verifying"
    serwrite("verify flashbin\r")
    timesleep()
   
    print "Resetting"
    serwrite("reset\r")
    timesleep()
   
    serclose()
   
  if __name__ == "__main__":
     main()
