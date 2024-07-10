# Workshop #2: Dynamic Memory

- *Version 1.0*


In this workshop, you will use *references* to modify content of variables in other scopes, overload functions and allocate memory at run-time and deallocate that memory when it is no longer required. 


## Learning Outcomes

Upon successful completion of this workshop, you will have demonstrated the abilities to:

- allocate and deallocate dynamic memory for an array;
- overload functions;
- create and use references;


## Submission Policy


The workshop is divided into one coding part and one non-coding part:

- Part 1 (**LAB**): A step-by-step guided workshop, worth 100% of the workshop's total mark
> Please note that the part 1 section is **not to be started in your first session of the week**. You should start it on your own before the day of your class and join the first session of the week to ask for help and correct your mistakes (if there are any).
- Part 2 (reflection): non-coding part. The reflection doesn't have marks associated with it but can incur a **penalty of max 40% of the whole workshop's mark** if your professor deems it insufficient (you make your marks from the code, but you can lose some on the reflection).

## Due Dates
Part 1 (lab) is due 2 days after your lab day and Part 2 (Reflection) is due 4 days after your lab day.
 
The Due dates depend on your section. Please choose the "-due" option of the submitter program to see the exact due date of your section:

> Note that the submission usually opens by the end of Monday.
```bash
~profname.proflastname/submit 2??/wX/pY_sss -due<ENTER>
```
- Replace **??** with your subject code (`00 or 44`)
- Replace **X** with Workshop number: [`1 to 10`]
- Replace **Y** with the part number: [`1 or 2`]
- Replace **sss** with the section: [`naa, nbb, nra, zaa, etc...`]

## Late penalties
You are allowed to submit your work up to 2 days after the due date with a 50% penalty for each day. After that, the submission will be closed and the mark will be zero.

## Citation

Every file that you submit must contain (as a comment) at the top:<br />
**your name**, **your Seneca email**, **Seneca Student ID** and the **date** when you completed the work.

### For work that is done entirely by you (ONLY YOU)

If the file contains only your work or the work provided to you by your professor, add the following message as a comment at the top of the file:

> I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

### For work that is done partially by you.

If the file contains work that is not yours (you found it online or somebody provided it to you), **write exactly which part of the assignment is given to you as help, who gave it to you, or which source you received it from.**  By doing this you will only lose the mark for the parts you got help for, and the person helping you will be clear of any wrongdoing.

> - Add the citation to the file in which you have the borrowed code
> - In the 'reflect.txt` submission of part 2 (Reflection), add exactly what is added to which file and from where (or whom).

> :warning: This [Submission Policy](#submission-policy) only applies to the workshops. All other assessments in this subject have their own submission policies.

### If you have helped someone with your code

If you have helped someone with your code. Let them know of these regulations and in your 'reflect.txt' of part 2 (Reflection), write exactly which part of your code was copied and who was the recipient of this code.<br />By doing this you will be clear of any wrongdoing if the recipient of the code does not honour these regulations.

## Compiling and Testing Your Program

All your code should be compiled using this command on `matrix`:

```bash
g++ -Wall -std=c++11 -g -o ws file1.cpp file2.cpp ...
```

- `-Wall`: the compiler will report all warnings
- `-std=c++11`: the code will be compiled using the C++11 standard
- `-g`: the executable file will contain debugging symbols, allowing *valgrind* to create better reports
- `-o ws`: the compiled application will be named `ws`

After compiling and testing your code, run your program as follows to check for possible memory leaks (assuming your executable name is `ws`):

```bash
valgrind --show-error-list=yes --leak-check=full --show-leak-kinds=all --track-origins=yes ws
```

- `--show-error-list=yes`: show the list of detected errors
- `--leak-check=full`: check for all types of memory problems
- `--show-leak-kinds=all`: show all types of memory leaks identified (enabled by the previous flag)
- `--track-origins=yes`: tracks the origin of uninitialized values (`g++` must use `-g` flag for compilation, so the information displayed here is meaningful).

To check the output, use a program that can compare text files.  Search online for such a program for your platform, or use *diff* available on `matrix`.

> Note: All the code written in workshops and the project must be implemented in the **seneca** namespace, unless instructed otherwise.

### Custom code submission

If you have any additional custom code, (i.e. functions, classes etc) that you want to reuse in the workshop save them under a module called Utils (`Utils.cpp and Utils.h`) and submit them with your workshop using the instructions in the "[Submitting Utils Module](#submitting-utils-module)" section.


# Part 1 - LAB (100%) Employees Salary Report

***Employees Salary Report*** is a program that reads an unknown number of Employee records from a file and holds these records of Employees in a dynamically allocated array of **Employee**s. (Each record holds the Employee's name, Employee number and Salary of the Employees in a comma separated value format.)

After loading all the information into a dynamic array of **Employee**s, the program will sort the records based on the Employee number of the Employee in an ascending order and prints them on the screen.

## Execution example

[correct_output.txt](lab/correct_output.txt)

This program is partially developed; you can find all the files in the lab directory. Your responsibility is to complete the code as stated in the comments in the source code.

## The Code

The structure holding the Employee record is designed as follows:

```C++
struct Employee {
  char* m_name;
  int m_empNo;
  double m_salary;
};
```

In addition to holding the employee records in an dynamically allocated array of `Employee`s, each employee's name is also held in a dynamically allocated C-style string in the **Employee** structure. Consider the following visual and note that every circle with an arrow in this diagram shows dynamic memory in use.

![DMA](images/mem.png)
  

## Data file  

The data in the file has the following format:

```Text
EMPLOYEE NUMBER,SALARY,NAME<NEWLINE>
```

and this is a sample file:

```Text
529967,80084.40,Abraham Simpson
737371,32943.14,Agnes Skinner
760089,55772.04,Akira Kurosawa
238023,15310.58,Alice Glick
463877,93971.86,Allison Taylor
836915,63415.69,Apu Nahasapeemapetilon
261382,44801.13,Artie Ziff
811518,90670.05,Baby Gerald
543817,54858.69,Barney Gumble
881837,47608.23,Bart Simpson
268411,27776.91,Bernice Hibbert
954291,51499.66,Brandine Spuckler
117493,43554.12,Bumblebee Man
928072,23678.38,Carl Carlson
```


### The Modules

There are three modules in the program: `File`, `Employee` and `salReport`.


#### `File` Module

This modules contains functions that facilitate working with files to read data. The module has one global variable called `fptr`. This File pointer is used to point to the datafile for the application.

The following functions are already implemented in the `File` module:

- `openFile`: Opens the data file for reading  
- `closeFile`: Closes the data file
- `noOfRecords`: Returns an integer that is the number of records in the file; use this function in the `Employee` module to determine the size of the dynamic array of employees.



***Your coding responsibility in the `File` module:***

Implement 3 **overloads** of a function called `read`:

1. `read`: accepts as a parameter the **address** of an array of characters. Reads from the file the name of the employee and stores it in the parameter.
    
    Returns `true` if the read was successful, `false` otherwise.

    Use the following `fscanf` function to read the name of the employee from the file and return true if `fscanf` returns 1. See more information [here](https://en.cppreference.com/w/cpp/io/c/fscanf).

    ```C
    fscanf(fptr, "%[^\n]\n"......
    ```

2. `read`: accepts as a parameter a **reference** to an integer representing the employee number. Reads from the file the employee number and stores it in the parameter.

    Returns `true` if the read was successful, `false` otherwise.

    Use the following `fscanf` function to read the number from the file and return true if `fscanf` returns 1. See more information [here](https://en.cppreference.com/w/cpp/io/c/fscanf).

    ```C
    fscanf(fptr, "%d,".......
    ```

3. `read`: accepts as a parameter a **reference** to an floating point number in double precision representing the employee's salary. Reads from the file the employee salary and stores it in the parameter.

    Returns `true` if the read was successful, `false` otherwise.

    Use the following `fscanf` function to read the salary from the file and return true if `fscanf` returns 1. See more information [here](https://en.cppreference.com/w/cpp/io/c/fscanf).

    ```C
    fscanf(fptr, "%lf,",......
    ```


#### `Employee` Module


The `Employee` module has two global variables:
  ```cpp
  // Holds the number of records (employees) in the file.
  // Should be used (after setting) to allocate the dynamic array of Employees.
  int noOfEmployees;
  
  // Stores the address of a dynamically-allocated array of employees.
  //   The size of the array is "noOfEmployees".
  Employee* employees;
  ```


The function `sort` has been already implemented. This function sorts the array of employees based on the employee number.


***Your coding responsibility in the `Employee` module.***

Implement following functions:

- `load`: receives as parameter a reference to an object of type `Employee`, loads from the file the information about the employee and returns `true` if it was successful (`false` otherwise).

    - First it will read the employee number, then salary and finally in a **local** array of 128 characters, it will read the employee name from the file.

    - If all reads are successful:
        - find the actual length of the employee name using the `strlen` function in `<cstring>` and then add one to the length (for null termination)
        - allocate the same amount of characters in the name of the `Employee` parameter
        - copy the read name (from the local character array) into the newly allocated name of the `Employee` parameter using `strcpy` function implemented `<cstring>`.
        - store the employee number and salary read into the attributes of the parameter.
        - return `true`.
    - If at least one read failed, do not change the parameter and return `false`.

- `load`: an overload of the `load` function that receives no parameters. This function should:
    - open the file (use function(s) from `File` module)
    - get the number of records (employees) from the file (use function(s) from `File` module) and store it into the global variable
    - create a dynamically allocated array of `Employee`; store its address into the global variable.
    - load each record from the file and store it into the array.
    - if everything is loaded correctly, return `true`.
    - if something goes wrong during data loading, display the following error message and return `false`.
    ```text
    Error: incorrect number of records read; the data is possibly corrupted.
    ```


- `display`: receives as a parameter a constant reference to an Employee object and prints it in the following format:
    ```text
    NUMBER: NAME, SALARY<NEWLINE>
    ```

- `display`: an overload of the `display` function that receives no parameters and returns nothing. This function should:
    - print to screen
    ```txt
    Employee Salary report, sorted by employee number
    no- Empno, Name, Salary
    ------------------------------------------------
    ```
    - sort the array
    - iterate over the sorted array an print each employee in th format:
    ```txt
    IDX- NUMBER: NAME, SALARY<NEWLINE>
    ```
    - see [sample output](#part-1-execution-example) for more details.

- `deallocateMemory`: deallocate **all** the memory used by the the dynamic array of employees (make sure to also deallocate the names).



### `main` Module.

This module is already provided. Look at it, make sure you understand it, but do not change it.

[main.cpp](lab/main.cpp)

### Files to submit:  

```Text
main.cpp <--- contains the main function, do not modify this.
File.cpp
File.h
Employee.cpp
Employee.h
```

### Submission Process:

Upload the files listed above to your `matrix` account. Compile and run your code using the `g++` compiler as shown in [Compiling and Testing Your Program](#compiling-and-testing-your-program) and make sure that everything works properly.

Then, run the following command from your matrix account

```bash
~profname.proflastname/submit 2??/wX/pY_sss  <ENTER>
```
- Replace **??** with your subject code (`00 or 44`)
- Replace **X** with Workshop number: [`1 to 10`]
- Replace **Y** with the part number: [`1 or 2`]
- Replace **sss** with the section: [`naa, nbb, nra, zaa, etc...`]

and follow the instructions.


#### Submitting Utils Module
To have your custom Utils module compiled with your workshop and submitted, add a **u** to the part number of your workshop (i.e **u**p1 for part one and **u**p2 for part two) and issue the following submission command instead of the above:
```text
~profname.proflastname/submit 2??/wX/upY_sss  <ENTER>
```
See [Custom Code Submission](#custom-code-submission) section for more detail

> :warning:**Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Re-submissions will attract a penalty




# Part 2: Reflection

Study your final solutions for each deliverable of the workshop **and the most recent milestones of the project if applicable**, reread the related parts of the course notes, and make sure that you have understood the concepts covered by this workshop.  **This should take no less than 30 minutes of your time and the result is suggested to be between 150 to 300 words in length.**

Create a file named `reflect.txt` that contains your detailed description of the topics that you have learned in completing this workshop and **the project milestones if applicable** and mention any issues that caused you difficulty.


### Reflection Submission Process:

Upload `reflect.txt` to matrix containing the reflection

Then, run the following command from your matrix account

```bash
~profname.proflastname/submit 2??/wX/pY_sss  <ENTER>
```
- Replace **??** with your subject code (`00 or 44`)
- Replace **X** with Workshop number: [`1 to 10`]
- Replace **Y** with the part number: [`1 or 2`]
- Replace **sss** with the section: [`naa, nbb, nra, zaa, etc...`]

and follow the instructions.

> :warning:**Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Re-submissions will attract a penalty.
