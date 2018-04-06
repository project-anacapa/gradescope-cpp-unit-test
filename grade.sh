
#!/bin/sh

# Copy files you are expecting the student to submit into current directory

cp /autograder/submission/hello.cpp .

# Remove any old results.json
rm -f results.json

# Do whatever you need to do in order to generate and populate results.json
# Typically, this is compile (e.g. run make or ant or maven)
# and then run the program or the Python scripts, etc.
make clean
make tests

# Finally copy results.json to where Gradescope needs it to be
cp results.json /autograder/results/results.json
