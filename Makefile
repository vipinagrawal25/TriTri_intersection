lib:
	(cc -fPIC -shared -o _libttisect.so tri_tri_intersect.c)
cpp:
	(cd src; g++ -std=c++11 -o Performance.exe Performance.cpp; mv Performance.exe ../)	
python:
	(cd src; python Performance.py;)
data:
	(cd src; g++ -std=c++11 -o Generation.exe Generation.cpp; mv Generation.exe ../)	