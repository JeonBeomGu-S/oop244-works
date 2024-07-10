# Workshop #5: Member Operators, Helper functions
Version 1.0

In this workshop, you will implement different types of operator overload in a partially developed class.

## Learning Outcomes

Upon successful completion of this workshop, you will have demonstrated the abilities to:

- define and create  binary member operator
- define and create a type conversion operator
- define and create unary member operator 
- define and create helper binary operator between classes
- define and create a helper operator between a primitive type and a class.

## Submission Policy


The workshop is divided into one coding part and one non-coding part:

- Part 1 (**LAB**): A step-by-step guided workshop, worth 100% of the workshop's total mark
> Please note that the part 1 section is **not to be started in your first session of the week**. You should start it on your own before the day of your class and join the first session of the week to ask for help and correct your mistakes (if there are any).
- Part 2 (reflection): non-coding part. The reflection doesn't have marks associated with it but can incur a **penalty of max 40% of the whole workshop's mark** if your professor deems it insufficient (you make your marks from the code, but you can lose some on the reflection).

## Due Dates
Part 1 (lab) is due 2 days after your lab day and Part 2 (Reflection) is due 2 days after your lab day.
 
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


# Part 1 - LAB (100%) The Account module.

Your task for this part of the workshop is to complete the implementation of the **Account** module for holding a bank account number (an integer) and the balance of the account (a double value). 

# The Account class
The Account class has two attributes; one integer for an account number (**m_number**) and a double for the balance of the account (**m_balance**)

The **Account** class can be in three different states: 

* Invalid Empty State<br />
An account is in an **invalid** state if invalid information is fed into the account. In these types of situations the account number is set to **-1** and the balance is set to **0**. The Account object in this case is rendered inactive and can not be used anymore.
* New <br />
An account is considered **New** or **not set** when it is just created and the account number is not assigned yet. This state of the **Account** class is flagged by setting the account number (**m_number**) to **0**.
* Valid<br />
An **Account** is considered **valid** if the account number is a 5 digit integer with a zero or positive balance.

## Already implemented parts:
## Constructors
The **Account** can be created in two different ways:
- default constructor *(implemented)* 
```C++
  Account();
```
The default constructor sets the account as **new** with a balance of **0**. 
- Two argument constructor (and integer and a double) *(implemented)*
```C++
  Account(int number, double balance);
```
The two-argument constructor sets the account number and balance to incoming arguments only if both values are valid. If an invalid account number or a negative balance is passed to the constructor, the object will be set into an invalid empty state.

## display function. 
*(implemented)*
```C++
   ostream& display() const
```
Displays the account on the screen.<br />
If the account is invalid, it is going to print:  **Bad Account**. If the account is a new account, instead of the account number it will print **New**. <br />
At the end **display** will return the **cout** object.

## To be implemented:
### type conversion operators
- **operator bool**<br />
returns **true** if the account is **valid** and otherwise **false**. This operator can not modify the **account** object.
- **operator int**<br />
returns the **account number**. This operator can not modify the **account** object.
- **operator double**<br />
returns the **balance value**. This operator can not modify the **account** object.

### Unary member operator
- **bool operator ~()**<br />
This operator returns **true** is the account is **new** or **not set** (i.e. if the **account number** is **zero**), otherwise it will return **false**.  This operator can not modify the **account** object.

### Binary member operators
> Note: All the binary member operators **will not take any action** if the **account**  is in an **invalid** state.

#### assignment operators
- overload the **assignment operator** so a **NEW account** can be set to an **integer**. Doing so should set the **account number** of the **account** to the **integer value**. <br />
If the **integer value** is an invalid account number, the object should be set to an **invalid empty state** instead. <br />
If the account is not new, then this operator should not perform any action.<br />
In any case, a reference of the **current object** (**account**) should be returned. 
```C++
Account A,B; 
   A = 55555;  // the account number of A will be set to 55555
   B = 555; // the account B will be set to invalid state
   B = 66666; // no action will be taken since the B is in not new
   A = 66666; // no action will be taken since the A is in not new
```
- overload the **assignment operator** so a **NEW account** can be set to another **Account** object. This action should **move** the balance and the account number from one account to another; therefore unlike the usual assignment operator that affects the left operand only, this operator will affect both operands; the balance of the left account will be set to the balance of the right account and then the balance of the right account will be set to zero. The same will happen to the account number<br />
If the left Account operand is not new or the right account operand is not valid, no action should be taken.<br />
In any case, a reference of the **current object** (**account**) should be returned. 
```C++
   Account A, B(66666, 400), Bad(555, -10);
   A = B;  // A will have the properties of B and B will become a NEW account
   B = Bad; // Nothing will happen since Bad is not new
   Bad = B; // Nothing will hapen since Bad is invalid
```
- overload the **+= operator** to add a double value to an account. This should act like depositing money into an account. (i.e. the value of the double should be added to the balance)<br />
if the account is in an invalid state or the double value is negative, no action should be taken.<br />
In any case, a reference of the **current object** (**account**) should be returned. 
```C++
Account A(55555, 400.0), Bad(555, -10);
   A += 200.0;  // A will have a balance of 600 
   Bad += 300.0; // Nothing will happen since Bad is invalid
   A += -20.0; // Nothing will happen since double value is negative
```
- overload the **-= operator** to reduce an account balance by a double value . This should act like withdrawing money from an account. (i.e. the value of the balance should be reduced by the double value)<br />
if the account is in an invalid state, the double value is negative or there is not enough money in the account no action should be taken.<br />
In any case, a reference of the **current object** (**account**) should be returned. 
```C++
Account A(55555, 400.0), Bad(555, -10);
   A -= 150.0;  // A will have a balance of 250 
   A -= 300.0; // Nothing will happen since there not enough money in A
   A -= -20.0; // Nothing will happen since double value is negative
   Bad -= 20.0 // Nothing will happen since Bad is invalid
```

- overload the **<< operator** (left shift operator) to move funds from the right account to the left. After this operation, the balance of the left account will be the sum of both and the balance of the right account will be zero.<br />
Funds of an account should not be able to be moved to itself and this operation does not affect the account.<br />
In any case, a reference of the **current object** (**account**) should be returned. 
```C++
Account A(55555, 400.0),B(66666, 500.0), Bad(555, -10);
   A << B;  // A will have a balance of 900.0, B will have a balance of zero
   A << A; // Nothing will happen 
   A << Bad; // Nothing will happen
   Bad << A; // Nothing will happen
```

- overload the **>> operator** (right shift operator) to move funds from the left account to the right. After this operation, the balance of the right account will be the sum of both and the balance of the left account will be zero.<br />
Funds of an account should not be able to be moved to itself and this operation does not affect the account.<br />
In any case, a reference of the **current object** (**account**) should be returned. 
```C++
Account A(55555, 400.0),B(66666, 500.0), Bad(555, -10);
   A >> B;  // B will have a balance of 900.0, A will have a balance of zero
   B >> B; // Nothing will happen 
   B >> Bad; // Nothing will happen
   Bad >> B; // Nothing will happen
```

### Binary helper operators

-- create a binary stand alone helper **+ operator** that accepts a **constant account reference** at left and another **constant account reference** at right and returns a **double** value. <br />
The **double** value should be the **sum** of the **balances** of the two accounts.<br />
If any of the two accounts is **invalid**, then **zero** is returned.<br />
```C++
   Account A(55555, 400.0), B(66666, 600.0), Bad(555, -10);
   double sum;
   sum = A + B; // sum should be 1000.0
   sum = A + Bad; // sum should be 0 since Bad is invalid
   sum = Bad + B; // sum should be 0 since Bad is invalid
```
-- create a binary stand alone helper **+= operator** that accepts a **double reference** at left and a **constant account reference** at right and returns a **double** value. <br />
The value of the balance of the right operand (account reference) should be added to the left operand (double reference) <br />
Then the value of the double reference is returned. 

```C++
   Account A(55555, 400.0), B(66666, 600.0), Bad(555, -10);
   double sum = 100, ret;
   ret = sum += A; // sum and ret should be 500.0
```

## The tester program.

[main.cpp](lab/main.cpp)

The tester program tests all the operator overloads and the output should be as follows:

## Correct output

[correct_output.txt](lab/correct_output.txt)

## PART 1 Submission (part 1)
### Files to submit:  
```Text
Account.cpp
Account.h
main.cpp
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
act a penalty
