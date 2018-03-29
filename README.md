# gradescope-cpp-unit-test

A Gradescope compatible simple unit test framework for C++


# TO USE

* Replace the old implementation of `tddFuncs.cpp` with the one in this repo
* In the Makefile, add `-I/usr/include/jsoncpp -std=c++11` to the compile command
* In the Makefile, add `-ljsoncpp` to the link commands

# ANOTHER WAY TO CHANGE THE MAKEFILE

```diff
diff --git a/Makefile b/Makefile
index 948b9cc..6fd3495 100755
--- a/Makefile
+++ b/Makefile
@@ -1,7 +1,9 @@
-CXX = g++
+CXX = g++ 
 # CXX = clang++
 
-CXXFLAGS = -Wall -Wno-uninitialized
+CXXFLAGS = -Wall -Wno-uninitialized -I/usr/include/jsoncpp
+
+LDFLAGS = -ljsoncpp
 
 BINARIES=arrayToStringTest arrayBoundsDemo countEvensTest \
        minOfArrayTest minOfArrayErrorTest countPrimesTest \
169-231-169-84:PRIVATE-w18-lab04-gradescope-try pconrad$ 
```


# Sample `result.json`

```json
{
	"tests" : 
	[
		{
			"max_score" : 1,
			"name" : "sum(1,2)",
			"output" : "Expected: 3 Actual: 3",
			"score" : 1
		},
		{
			"max_score" : 1,
			"name" : "prod(7,2)",
			"output" : "Expected: 14 Actual: 14",
			"score" : 1
		},
		{
			"max_score" : 1,
			"name" : "pow(2,7)",
			"output" : "Expected: 128 Actual: 5",
			"score" : 0
		}
	]
}



```


