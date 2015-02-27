# PI CALCULATION

**pi1**, **pi2** and **pi3** are different ways of calculating PI using a C++ random-number generator.
The results obtained by the three of them are compared in a spreadsheet.

## pi1

The value of PI is obtained by generating random numbers up to a maximum of **1e+8** points.

### Results of pi1:

* 1e+1 :: 3.2
* 1e+2 :: 2.88
* 1e+3 :: 3.088
* 1e+4 :: 3.120
* 1e+5 :: 3.14376
* 1e+6 :: 3.142876
* 1e+7 :: 3.142256
* 1e+8 :: 3.141745

## pi2

Same as **pi1**, but changing the maximum number of points generated, starting with **1000** points up to a maximum of **1e+10**. The maximum is increased in steps of 10 times the maximum.

### Results of pi2:

* 1e+3 :: 3.088
* 1e+4 :: 3.128
* 1e+5 :: 3.14288
* 1e+6 :: 3.143052
* 1e+7 :: 3.142194
* 1e+8 :: 3.141625
* 1e+9 :: 3.141588
* 1e+10 :: :zzz:

## pi3

Same as **pi2**, starting with a maximum of **1e+4** up to a maximum of **2e+5**, in steps of **1e+4**. The program also writes the results to an output file.

### Results of pi3:

Check pi3 output file: **pi3-results.txt**
* 1e+4: 3.12
* 2e+4: 3.1504
* 3e+4: 3.138533
* 4e+4: 3.150500
* 5e+4: 3.142560
* 6e+4: 3.144733
* 7e+4: 3.144229
* 8e+4: 3.143300
* 9e+4: 3.134489
* 1e+5: 3.145640
* 1.1e+5: 3.151818
* 1.2e+5: 3.140400
* 1.3e+5: 3.144308
* 1.4e+5: 3.138886
* 1.5e+5: 3.137093
* 1.6e+5: 3.143950
* 1.7e+5: 3.140141
* 1.8e+5: 3.142800
* 1.9e+5: 3.140632
* 2e+5: 3.143660

## pi3-results.xls

Spreadsheet with the plot of pi3-results.txt
