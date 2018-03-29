# gradescope-cpp-unit-test

A Gradescope compatible simple unit test framework for C++


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