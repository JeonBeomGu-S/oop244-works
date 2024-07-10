# Workshop #3: Member Functions and Privacy
* Version 1.0

In this workshop, you will use member functions, privacy, safe empty state and formatting the output to complete your work.

## Learning Outcomes

Upon successful completion of this workshop, you will have demonstrated the abilities to:

- to define a class type
- to privatize data within the class type
- to instantiate an object of class type
- to access data within an object of class type through public member functions
- to use standard library facilities to format data inserted into the output stream
- to describe to your instructor what you have learned in completing this workshop

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


# Part 1 - LAB (100%) Shopping Bill

> Note: In this and future documents a **member function** may be referred to as a **method** and a **member variable** may be referred to as an **attribute**.

Your task for this part of the workshop is to create a program that provides a class called **Bill**. This class can be initiated using a Title name and number of shopping **Item**s.

Then the **Item**s will be added one at a time to the Bill by their name and the price and whether they are taxable or not.

The **Bill** then can be displayed, listing all the items, their prices and whether each item is taxed or not. At the end of the list the total price, tax and total price after tax should be listed as follows:


## Sample main program and execution sample

[main.cpp](lab/main.cpp)

## An example for a valid list:
```Text
+--------------------------------------+
| Quick Shopping                       |
+----------------------+---------+-----+
| Item Name            | Price   + Tax |
+----------------------+---------+-----+
| Milk 2%............. |    4.99 | No  |
| Spatula............. |   15.50 | Yes |
| Frying Pan.......... |   24.99 | Yes |
| Eggs................ |    5.99 | No  |
| Bug Spray........... |    9.99 | Yes |
+----------------------+---------+-----+
|                Total Tax:       6.56 |
|              Total Price:      61.46 |
|          Total After Tax:      68.02 |
+--------------------------------------+
```
## Examples of incomplete or lists with invalid items:  

```Text
+--------------------------------------+
| Invalid Bill                         |
+----------------------+---------+-----+
| Item Name            | Price   + Tax |
+----------------------+---------+-----+
| Milk 2%............. |    4.99 | No  |
| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |
| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |
| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |
| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |
+----------------------+---------+-----+
| Invalid Bill                         |
+--------------------------------------+
+--------------------------------------+
| Invalid Bill                         |
+----------------------+---------+-----+
| Item Name            | Price   + Tax |
+----------------------+---------+-----+
| Milk 2%............. |    4.99 | No  |
| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |
| Frying Pan.......... |   24.99 | Yes |
| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |
| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |
+----------------------+---------+-----+
| Invalid Bill                         |
+--------------------------------------+
```


## Implementation

Implement this program in two modules (ie. classes):  
**Item** and **Bill** 


### The Item Class
Develop this class in files **Item.h** and **Item.cpp**

#### Private Member Variables (attributes)
The class subject should have the following member variables:

```C++
   char m_itemName[21];  // holds the item name up to 20 chars
   double m_price;
   bool m_taxed;
```
#### Private Member functions (Methods)
```C++
     void setName(const char* name);
```
This function sets the **itemName** member Cstring variable to a the Cstring in the **name** argument up to 20 characters. 

#### Public Member functions (Methods)
```C++
void setEmpty();
```
Sets the **Item** to a recognizable safe Empty State. Do this by setting the price to an impossible value like **0.0** and setting the **m_itemName** to a blank string (first character set to null). 

```C++
      void set(const char* name, double price, bool taxed);
```
Sets the **m_itemName** attribute to the Cstring pointed by the **name** argument using the **setName** method and sets the **m_price** and **m_taxed** attributes to the corresponding arguments.

If price is less than **0** or name is **null**, then the Item is set to a recognizable invalid **empty state** (safe empty state). 

```C++
double price()const;
```
Returns the **m_price** attribute;


```C++
double tax()const;
```
Returns the product of m_price and 0.13(define a constant double value for this tax rate). Or it returns **0.0** if the m_taxed is false.

```C++
bool isValid()const;
```
Returns true if the **Item** is not set to the empty state (As done in setEmpty function) .<br />
This function can not modify its owner.

```C++
 void display()const;
```
Prints an item in the following format.<br />
**If the Item is valid:**<br />  
```Text
"| "
m_itemName; left-justified in 20 spaces, padded with '.' (dots)
" | "
m_price; right-justified in 7 spaces with two digits after the decimal point
" | "
if m_taxed is true prints "Yes" otherwise prints "No "
" |"
Newline
```
**If the Item is invalid**
```Text
| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |
Newline
```

### The Bill Class

#### Private Member Variables (attributes)
The class **Bill** should have the following private member variables and functions:

```C++
      char m_title[37];  // title of the shopping list
      Item* m_items;     // pointer to the dynamically allocated array of Items
      int m_noOfItems;   // size of the dynamically allocated array of Items
      int m_itemsAdded;  // number of the Items added by the add method
      double totalTax()const;   // returns the total tax applied to the Items
      double totalPrice()const;  // returns the sum of prices of Items
      void Title()const;       // Prints the title of the shopping list
            // prints the footer contaning total tax, price and total price after tax
      void footer()const;
      void setEmpty();     // sets the Bill to an emtpy state
      bool isValid()const;  // returns true is the Bill and all of its Items are valid
```

#### Private Member functions (Methods)
```C++
      void setEmpty();
```
Sets the **Bill** object to an empty state by setting **m_title** to an Empty Cstring and **m_items** to **nullptr**

```C++
      bool isValid()const;
```
Returns true if **m_title** is not empty and **m_items** is not null and all the **Items** in the **m_items** array are valid.

> hint: First check and make sure m_title and m_items are valid. Then loop through all the Items in the m_items array and make sure they are all valid.

```C++
      double totalTax()const;
```

Adds all the taxes of the items using a loop and returns the sum. 

```C++
      double totalPrice()const;
```

Adds all the prices of the items using a loop and returns the sum;


```C++
      void Title()const;
```
Prints the title in the following format:  

Prints: ```"+--------------------------------------+"<NEWLINE>```
 
**If the Bill is valid**<br />
```Text
"| "  
m_title; left-justified in 36 spaces
" |"  
Newline
```
**If the Bill is invalid**  
```
"| Invalid Bill                         |"<NEWLINE>
```
Then in both cases (valid or invalid), it will print:  

```
"+----------------------+---------+-----+"<NEWLIN>
"| Item Name            | Price   + Tax |"<NEWLIN>
"+----------------------+---------+-----+"<NEWLIN>
```


```C++
      void footer()const;
```
Prints the footer in the following format:  


Prints: ```"+----------------------+---------+-----+"<NEWLINE>```
 
**If the Bill is valid**<br />
```Text
"|                Total Tax: "  
totalTax(); right justified in 10 spaces with two digits after the decimal point
" |"  
Newline
"|              Total Price: "  
totalPrice(); right justified in 10 spaces with two digits after the decimal point
" |"  
Newline
"|          Total After Tax: " 
totalTax()+totalPrice(); right justified in 10 spaces with two digits after the decimal point
" |"  
Newline
```
**If the Bill is invalid**  
```
"| Invalid Bill                         |"<NEWLINE>
```
Then in both cases (valid or invalid), it will print:  

```
"+--------------------------------------+"<NEWLINE>
```


#### Public Member functions (Methods)

```C++
       void init(const char* title, int noOfItems);
```

If any of the arguments are invalid, it will set the Bill to an empty state (ie. **title** is null or **noOfItems** is zero or less)

Otherwise, if the incoming arguments are valid:

- **init()** function will first set the **m_noOfItems** member variable to the incoming corresponding argument and sets **m_itemsAdded** to zero.
- Next, it will copy the Cstring pointed by the **title** argument into **m_title** attribute up to 36 characters
- Then it will dynamically allocate an array of **Item**s pointed by **m_items** member variable. The length of this array will be  **m_noOfItems**.
> Make sure all the dynamically allocated **Item**s are set to empty


```C++
       bool add(const char* item_name, double price, bool taxed);
```

If the number of added **Item**s (**m_itemsAdded**) is less than the length of the **m_items** array, this function will set the next available subject to the incoming argument values. Then it will add one to the **m_itemsAdded** and return true;

Otherwise, this function will do nothing, returning false;

```C++
      void display()const;
```

This function will first print the **title()**, then it will loop through the **m_items** elements, printing every one of them, and finally prints the **footer()**. This function can not modify the Bill. 

```C++
     void deallocate();
```
Deallocates the **m_items** arrays and sets the pointers to null.


## The tester program

[main.cpp](lab/main.cpp) is the tester program that provides the following output

[main_prof.cpp](lab/main_prof.cpp) is a comprehensive tester program that tests your program during submissiont. 


### The tester program output:  
```Text
+--------------------------------------+
| Invalid Bill                         |
+----------------------+---------+-----+
| Item Name            | Price   + Tax |
+----------------------+---------+-----+
| Milk 2%............. |    4.99 | No  |
| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |
| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |
| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |
| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |
+----------------------+---------+-----+
| Invalid Bill                         |
+--------------------------------------+
+--------------------------------------+
| Invalid Bill                         |
+----------------------+---------+-----+
| Item Name            | Price   + Tax |
+----------------------+---------+-----+
| Milk 2%............. |    4.99 | No  |
| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |
| Frying Pan.......... |   24.99 | Yes |
| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |
| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |
+----------------------+---------+-----+
| Invalid Bill                         |
+--------------------------------------+
+--------------------------------------+
| Quick Shopping                       |
+----------------------+---------+-----+
| Item Name            | Price   + Tax |
+----------------------+---------+-----+
| Milk 2%............. |    4.99 | No  |
| Spatula............. |   15.50 | Yes |
| Frying Pan.......... |   24.99 | Yes |
| Eggs................ |    5.99 | No  |
| Bug Spray........... |    9.99 | Yes |
+----------------------+---------+-----+
|                Total Tax:       6.56 |
|              Total Price:      61.46 |
|          Total After Tax:      68.02 |
+--------------------------------------+
```

### main_prof.cpp execution output

[correct_output.txt](lab/correct_output.txt)


## PART 1 Submission 
### Files to submit
```Text
main.cpp
Item.cpp
Item.h
Bill.cpp
Bill.h
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
