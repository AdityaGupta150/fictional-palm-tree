## Calculator

A simple calculator, that takes in an expression, as long as you may type, parses it, and gives the result.


### Building/Compiling
#### If you have `make`
* Run `make`, then the executable
    ```sh
    make
    ./calculator
    ```

#### Without `make`
* Simply compile the two .cpp files together, ie.
    ```sh
        g++ main.cpp util.cpp
    ```

### Future Work
* Applying BODMAS precedence too
    (The validate() function is such that only change is to be done there, for implementing this, you may give it a go :D )

#### Note - 
1. The same work can be done with lesser include statements, and smaller utility functions, that maybe simpler. I have tried to utilise whatever already exists
2. There's no real need for a makefile in such a small something.
