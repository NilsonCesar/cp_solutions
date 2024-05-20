import sys
def getfile(x = ''):
	if x != '':
		sys.stdin = open(x+".in", "r")
		sys.stdout = open(x+".out", "w")

getfile()