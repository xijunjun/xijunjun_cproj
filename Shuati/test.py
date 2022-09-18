def FirstNotRepeatingChar( s):
	# write code here
	mhash=[0 for i in xrange(256)]
	for item in s:
	    mhash[ord(item)]+=1
	    if mhash[ord(item)]>2:
		mhash[ord(item)]=2
	for i,item in enumerate(s):
	    if mhash[ord(item)]==1:
		return i
	return -1

