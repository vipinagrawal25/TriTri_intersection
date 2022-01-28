The code computes intersection of two triangles embeded in 3 dimensional space. It is an update of the original code at [JGT-code,Volume_08,Number_1](https://github.com/erich666/jgt-code/tree/master/Volume_08/Number_1/Guigue2003).

### Changes:
	* The code return 0 if the triangles are sharing an edge.
	* The code do not compute the line of intersection, which makes it faster (5%) 
	  than the existing code. It also implies that this is the fastest code for computing 
	  the triangle-triangle intersection for double precision.
	* The code fixes a small bug in the existing code. While comparing two double value, 
	  we add a small tolerance (1e=14) to take care of the small floating point errors that the code builds.

### About:
	* In addition to the C code, the code also includes python wrappers to the exisitng C functions.
	* make cpp compiles the cpp files and generated the executable in the main directory.
	* make python runs the python code.
	* make generate_data generates the data using algorithm described by [Moller]{https://github.com/erich666/jgt-code/tree/master/Volume_02/Number_2/Moller1997b}
	* Fore more details, visit the repository:https://web.archive.org/web/20120118225810/http://jgt.akpeters.com/papers/GuigueDevillers03/.

The code is based on:

Fast and Robust Triangle-Triangle Overlap Test using Orientation Predicates

Philippe Guigue and Olivier Devillers
INRIA Sophia-Antipolis

Paper DOI: 10.1080/10867651.2003.10487580

Abstract:

This paper presents an algorithm for determining whether two triangles in three dimensions intersect. The general scheme is identical to the one proposed by Möller. The main difference is that our algorithm relies exclusively on the sign of 4 x 4 determinants and does not need any intermediate explicit constructions which are source of numerical errors. Besides the fact that the resulting code is more reliable than existing methods, it is also more efficient. The source code is available online.

Author Information

Philippe Guigue, INRIA Sophia-Antipolis, BP 93, 2004 Route des Lucioles06902 Sophia-Antipolis Cedex, France Philippe.Guigue@sophia.inria.fr

Olivier Devillers, INRIA Sophia-Antipolis, BP 93, 2004 Route des Lucioles06902 Sophia-Antipolis Cedex, France Olivier.Devillers@sophia.inria.fr
