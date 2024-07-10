# Workshop #4: Constructors Destructors and Current object
* Version 1.0

In this workshop, you will use Constructors, a Destructor and a reference of the current object to simulate a Canister to hold liquid food products.

## Learning Outcomes

Upon successful completion of this workshop, you will have demonstrated the abilities to:

- define a default constructor
- define custom constructors with different number of arguments
- define a Destructor to prevent memory leaks.
- Use the reference of the current object 
- describe to your instructor what you have learned in completing this workshop

## Submission Policy


The workshop is divided into one coding part and one non-coding part:

- Part 1 (**LAB**): A step-by-step guided workshop, worth 100% of the workshop's total mark
> Please note that the part 1 section is **not to be started in your first session of the week**. You should start it on your own before the day of your class and join the first session of the week to ask for help and correct your mistakes (if there are any).
- Part 2 (reflection): non-coding part. The reflection doesn't have marks associated with it but can incur a **penalty of max 40% of the whole workshop's mark** if your professor deems it insufficient (you make your marks from the code, but you can lose some on the reflection).

## Due Dates
Part 1 (lab) is due 2 days after your lab day and Part 2 (Reflection) is due 6 days after your lab day.
 
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
You are allowed to submit your work up to 2 days after the due date with a 30% penalty for each day. After that, the submission will be closed and the mark will be zero.

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


# Part 1 - LAB (100%) The Canister Module

Your task for this part of the workshop is to create a **Canister** module for holding liquid edible products. 

A **Canister** is a cylindrical container that is created using its height and its diameter and is labeled by the name of its content with an unknown length(i.e. Milk, Orange juice, etc...)  that is dynamically held by a Canister. A Canister also holds the volume of the content it is holding making sure the liquid does not exceed its capacity. Any container that is filled higher than 0.267 centimetres from the top of the canister is considered unusable. 

The smallest Canister can have a height and diameter of 10.0 by 10.0 centimetres and the largest one can be 40 by 30 respectively. 

#### Calculating the capacity
A Canister's capacity (i.e. maximum amount of content it can hold) is calculated as follows:  
```Text
PI: 3.14159265  (a global constant double value created in Canister.cpp)
H: Height
D: Diameter
Capacity = PI x (H - 0.267) x (D/2) x (D/2)
```


The **Canister** can be created in three different ways; 
- By default a **Canister** is created with the following **height** and **diameter**: 13.0 x 10.0 with no name and content amount of 0 (empty)
- Also a Canister can be created with its **content name**. In this case, the dimensions will be set to default values like the previous case and it will be empty.
- Finally, a Canister can be created using its height, diameter and content name. 

> In any case, when a Canister is created using initial values and any of the values provided is invalid, the Canister is rendered unusable.  

#### Pouring contents of one canister into another
You can fill the Canisters with the content they are labelled for. If too much is poured into the Canister, it will overflow and be rendered unusable.


You can pour all or some of the content of one Canister into another. If this results in mixed content, the target will be rendered unusable.

For example, if you can fill an empty orange juice Canister with the contents of a Canister holding Olive oil. Since the Orange juice Canister was empty everything will be OK and the Canister will be re-labelled as Olive oil. But if the orange juice canister has some orange juice in it, then it would have been rendered unusable.

To reuse an unusable Canister it must be reset and cleared. 

You must design your code in a way that re-labelling and destruction of Canisters do not result in a memory leak.



## Implementation 

Create a class in a Module called Canister.

### Private attributes (member variables)

```C++
    char* m_contentName; // points to a dynamically allocated Cstring.
    double m_diameter; // in centimeters 
    double m_height;   // in centimeters
    double m_contentVolume;  // in CCs
    bool m_usable; // a flag to identify if the Canister is usable or unusable
```

### Private methods (member functions)

```C++
      void setToDefault();
```  
This function sets the attributes to their default values. It sets the content name pointer to null, height to 13.0, diameter to 10.0, content volume to 0.0 and usable flag to true.

```C++
      bool isEmpty()const;
```
Returns true if the content volume is less than 0.00001 CCs.
```C++
      bool hasSameContent(const Canister& C)const;
```
Compares the content name of this Canister with the one received from the argument **C**.
Compare the two content names using strcmp from **<cstring>** so that it returns true if both names are not null and are identical. Otherwise, it returns false;
```C++
      void setName(const char* Cstr);
```
Sets the content name of the current Canister.<br />
If the incoming **Cstr** is not null and the Canister is usable, it will delete the current content name, allocate memory to the length of Cstr (+1 for null) and copies the Cstr into the newly allocated memory. Otherwise, it will silently do nothing.


### Constructors
#### No argument Constructor (defualt)
Sets the attributes to their default values
#### One argument Constructor:
```C++
Canister(const char* contentName);
```
- Sets the attributes to their default values (note: reuse code)
- Sets the name to the incoming **contentName** argument.
```C++
Canister(double height, double diameter, const char* contentName);
```
- Sets the attributes to their default values.

If the dimensions are within acceptable values:
- it will set the m_height and m_diameter to the corresponding argument values
- it will set the content volume to 0.
- it will set the content name to the corresponding argument value.

If any of the dimensions have invalid values, it will set the Canister as **unusable**

### The Destructor
Deallocates the dynamic memory pointed by the content name attribute.

### Public Methods (member variables)
```C++
      void clear();
```
Clears an unusable Canister back to an empty Canister by:  
- deallocating the memory pointed by the content name attribute
- sets the content name attribute to **nullptr**
- sets the content volume attribute to 0.0
- set the usable flag attribute to true
```C++
      double capacity()const;
```
returns the capacity as stated in [Calculating the capacity](#calculating-the-capacity)
```C++
      double volume()const;
```
returns the content volume attribute
```C++
      Canister& setContent(const char* contentName);
```
It will set the Content name of the canister using the following rule and then returns the reference of the current object (i.e. *this):

If the **contentName** argument is null it will render the Canister unusable<br />
else if the Canister is empty it will set the name to the value pointed by the argument<br />
else if the name of the Canister is not the same as the contentName argument it will render the Canister unusable.
```C++
      Canister& pour(double quantity);
```
Adds the **quantity** argument to the content volume of the Canister if the **quantity** fits in the Canister. Otherwise, it will render the Canister unusable and then returns the reference of the current object.<br />
Use this rule to accomplish the above:<br />
If the Canister is **usable** and the **quantity**  is more than zero and if the sum of the quantity and the **volume()** is less than or equal to the **capacity()**, add the  **quantity** to the content volume, otherwise set usable flag attribute to false.
```C++
      Canister& pour(Canister& C);
```
Pours the content of the Canister argument into the current Canister following the [Specs stated at the top](#pouring-contents-of-one-canister-into-another)

Set the content name to the Canister argument using **setContent()**.<br />
if the **volume()** of the argument is greater than the **capacity()** minus the **volume()**<br />
Reduce the **content volume** of the argument by **capacity()** minus **volume()** and then set the content volume to **capacity()**<br />
else pour the **content volume** of the argument using **pour()** method and set the **content volume** of the argument to 0.0.<br />
return the reference of the current object at the end.

```C++
      std::ostream& display()const;
```
> Prints all the number values with one digit after the decimal point.

Prints the Canister in the following format:
```Text
In 7 spaces prints the capacity
"cc ("
height
"x"
diameter
") Canister"
```
if unusable:
```Text
" of Unusable content, discard!"
```
otherwise, if the content name is not null
```Text
" of "
in 7 spaces prints the volume
"cc   "
content name
```
returns the cout object at the end.

## Tester program:

[main.cpp](lab/main.cpp)

## Execution sample:

[correct_output.txt](lab/correct_output.txt)

## PART 1 Submission (part 1)
### Files to submit:  
```Text
Canister.cpp
Canister.h
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
