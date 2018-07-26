#!/usr/bin/make

# D.S. Parker
# January 2013

INCL = -I /Developer-3.2.4/SDKs/MacOSX10.6.sdk/usr/include/
LIB  = -L /Developer-3.2.4/SDKs/MacOSX10.6.sdk/usr/lib/

GPP_INCL = -I /Developer-3.2.4/SDKs/MacOSX10.6.sdk/usr/include/c++/4.2.1/x86_64-apple-darwin10 -I /Developer-3.2.4/SDKs/MacOSX10.6.sdk/usr/include/c++/4.2.1 -I /Developer-3.2.4/SDKs/MacOSX10.6.sdk/usr/include/
GPP_LIB  = -L /Developer-3.2.4/SDKs/MacOSX10.6.sdk/usr/lib/

GCC = gcc $(INCL) $(LIB)
GPP = g++ $(GPP_INCL) $(GPP_LIB)

all:	timemod_output.txt  search_output.txt  maxsum_output.txt  rotate_output.txt  priqueue_output.txt  sets_output.txt  matching_output.txt  heapsort_output.txt


# Most of the programs are all from J.L. Bentley's Programming Pearls, Addison-Wesley, 1999.
# Source code for these and other programs in this great book is available at:
#    http://www.cs.bell-labs.com/cm/cs/pearls/code.html

# The program matching.c is by DSP, adapted from the Kleinberg/Tardos text.


timemod_output.txt:	timemod
	./timemod > timemod_output.txt

search_output.txt:	search search_input.txt
	cat search_input.txt | ./search > search_output.txt

search_bug_output.txt:	search search_bug_input.txt
	######   goes into an infinite loop:
	#   cat search_bug_input.txt | ./search > search_bug_output.txt

maxsum_output.txt:	maxsum maxsum_input.txt
	cat maxsum_input.txt | ./maxsum > maxsum_output.txt

rotate_output.txt:	rotate rotate_input.txt
	cat rotate_input.txt | ./rotate > rotate_output.txt

priqueue_output.txt:	priqueue priqueue_input.txt
	cat priqueue_input.txt | ./priqueue > priqueue_output.txt

sets_output.txt:	sets
	./sets 20 30 > sets_output.txt


assertions_output.txt:	assertions
	./assertions > assertions_output.txt 2> assertions_output.txt

matching_output.txt:	matching
	./matching > matching_output.txt

heapsort_output.txt:	heapsort
	./heapsort > heapsort_output.txt


timemod:	timemod.c
	$(GCC) $< -o $@

search:	search.c
	$(GCC) $< -o $@

maxsum:	maxsum.c
	$(GCC) $< -o $@

rotate:	rotate.c
	$(GCC) $< -o $@

assertions:	assertions.c
	$(GCC) $< -o $@

matching:	matching.c
	$(GCC) $< -o $@

heapsort:	heapsort.c
	$(GCC) $< -o $@


priqueue:	priqueue.cpp
	$(GPP) $< -o $@

sets:	sets.cpp
	$(GPP) $< -o $@

STL_sets:	STL_sets.cpp
	$(GPP) $< -o $@

clean:
	rm -f *_output.txt

progclean:
	rm -f matching  timemod  search  maxsum  rotate  priqueue  sets heapsort assertions

