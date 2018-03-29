#include "tddFuncs.h"
#include <iostream>
#include <fstream>
#include <sstream>
using std::cout;
using std::endl;
using std::cerr;
using std::ifstream;
using std::ofstream;
using std::ostringstream;

#include <json/json.h> // from jsoncpp library (https://github.com/open-source-parsers/jsoncpp)

#define FILENAME "results.json"

class GradescopeReporter {

private:
  ifstream resultsIn;
  ofstream resultsOut;
  Json::Value root;
  
public:
  GradescopeReporter() {
    resultsIn.open(FILENAME);
    if (resultsIn.fail()) {
      makeEmptyTestsArray();
    } else {
      resultsIn >> root; // read results.json into root
    }
  }
  
  ~GradescopeReporter() {
    resultsOut.open(FILENAME);
    resultsOut << root << endl;
    resultsOut.close();    
  }

  void makeEmptyTestsArray() {
    Json::Value emptyArray;
    emptyArray.append(Json::Value::null);
    emptyArray.clear();
    root["tests"] = emptyArray;
  }
  
  void addTest(int score,
			    int max_score,
			    std::string name,
			    std::string output) {
    Json::Value newTest;
    newTest["score"] = score;
    newTest["max_score"] = max_score;
    newTest["name"] = name;
    newTest["output"] = output;
    root["tests"].append(newTest);
  }
  
};

static GradescopeReporter gsr; // constructor executes before main, destructor after


void assertEquals(std::string expected, 
                  std::string actual, 
                  std::string message) {
  std::ostringstream ea;
  ea << "Expected: " << expected << " Actual: " << actual; 
    
  if (expected==actual) {
    cout << "PASSED: " << message << endl;
    gsr.addTest(1,1,message,ea.str());
  } else {
    cout << "   FAILED: " << message << endl
         << "     " << ea.str() << endl;
    gsr.addTest(0,1,message,ea.str());
  }
}

void assertEquals(int expected, 
                  int actual, 
                  std::string message) {
  std::ostringstream ea;
  ea << "Expected: " << expected << " Actual: " << actual; 
    
  if (expected==actual) {
    cout << "PASSED: " << message << endl;
    gsr.addTest(1,1,message,ea.str());
  } else {
    cout << "   FAILED: " << message << endl
         << "     " << ea.str() << endl;
    gsr.addTest(0,1,message,ea.str());
  }
}

void assertTrue(bool expression,
                  std::string message) {

  std::ostringstream ea;
  ea << "Expected expression to be true but it was false "; 
    
  if (expression) {
    cout << "PASSED: " << message << endl;
    gsr.addTest(1,1,message,ea.str());
  } else {
    cout << "   FAILED: " << message << endl
         << "     " << ea.str() << endl;
    gsr.addTest(0,1,message,ea.str());
  }


}
