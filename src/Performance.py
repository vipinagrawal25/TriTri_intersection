import numpy as np
import os
import ttisect as T
import timeit
#
loop_number=100
pair_number=5000
intersection_ratio=0.1
#-------------------------------#
def read_triangles(file,i):
	t1=np.zeros([3,3])
	t2=np.zeros([3,3])
	t1[0]=file[6*i]
	t1[1]=file[6*i+1]
	t1[2]=file[6*i+2]
	t2[0]=file[6*i+3]
	t2[1]=file[6*i+4]
	t2[2]=file[6*i+5]
	return t1,t2
lf1=np.loadtxt("../data/intersected.txt")
lf2=np.loadtxt("../data/separated.txt")
#
u0=np.zeros([pair_number,3])
u1=np.zeros([pair_number,3])
u2=np.zeros([pair_number,3])
#
v0=np.zeros([pair_number,3])
v1=np.zeros([pair_number,3])
v2=np.zeros([pair_number,3])
#
nNumber=pair_number*intersection_ratio
for i in range(pair_number):
	if i<nNumber:
		t1,t2=read_triangles(lf1,i)
	else:
		t1,t2=read_triangles(lf2,i)
	#
	u0[i]=t1[0]
	u1[i]=t1[1]
	u2[i]=t1[2]
	v0[i]=t2[0]
	v1[i]=t2[1]
	v2[i]=t2[2]
#
start = timeit.default_timer()
#Your statements here
ncount=0
for j in range(loop_number):
	for i in range(pair_number):
		nresult = T.tri_tri_intersect(u0[i],u1[i],u2[i],v0[i],v1[i],v2[i]);
		ncount=ncount+nresult
stop = timeit.default_timer()
print('Time:', stop - start, "seconds")