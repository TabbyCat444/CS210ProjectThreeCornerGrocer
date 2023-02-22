# 7-3ProjectThreeCornerGrocery
##### Summarize the project and what problem it was solving. <br>
This project was to create a program for a small grocery store to use with their produce sales to assist in relocating<br>
produce for customer convenience by popularity. The program allows them to input a file with all the produce items<br>
purchased on that day and has menu options available for using the information. The store can search for a single item<br>
and get back a result for how many times it was purchased on that day, they can also get a list and/or a histogram<br>
showing purchase quantities for everything from that day. Finally, the program will back up their sales information to<br>
a data file.
<br><br>

##### What did you do particularly well? <br>
Personally I think the map was the best part of this code, but the while loop for the menu is mostly likely what I would<br>
say that I did particularly well, including input validation.
<br><br>

##### Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on? <br>
I tried to get try/catch statements to work, but they kept creating an infinite loop. At some point I would like to return<br>
and possibly switch out the while true validation loop for try catch statements with specific errors.
<br><br>

##### Which pieces of the code did you find most challenging to write, and how did you overcome this? <br>
##### What tools or resources are you adding to your support network? <br>
The map was the most difficult thing to write, this was my first use of one and I had no experience, not even book<br>
experience when I started trying to implement it. Google is always my friend, and one of my favorite sites is<br>
https://geeksforgeeks.org. I find their explanations to be the easiest for me to understand, although stack<br>
overflow is often a good source as well.
<br><br>

##### What skills from this project will be particularly transferable to other projects or course work? <br>
This is mty third project in C++ and the practice I have receieved with the language will be helpful knowledge for<br>
future courses, although I would say that the most transferable to other projects is the ability to user pointers<br>
and maps.
<br><br>

##### How did you make this program maintainable, readable, and adaptable? <br>
Throughout the program are comments galore, they will help me in the future noting what I was doing should I come<br>
back to make any edits. The program currently uses standard best practices to my knowledge which helps it remain<br>
maintainable and adaptable in addition to the spacing and previously mentioned comments for readability.
<br><br>

### Scenario:
You are doing a fantastic job at Chada Tech in your new role as a junior developer, and you <br>
exceeded expectations in your last assignment for Airgead Banking. Since your team is impressed <br>
with your work, they have given you another, more complex assignment. Your task is to build an <br>
item-tracking program for the Corner Grocer, which should incorporate all of their requested functionality.
<br><br>
The Corner Grocer needs a program that analyzes the text records they generate throughout the day. <br>
These records list items purchased in chronological order from the time the store opens to the time it closes. <br>
They are interested in rearranging their produce section and need to know how often items are purchased so <br>
they can create the most effective layout for their customers.
<br><br>

## The program that the Corner Grocer is asking you to create should address the following functional requirements: <br>

### Menu Option One: <br>
Prompt a user to input the item, or word, they wish to look for. <br>
Return a numeric value for the frequency of the specific word.
<br><br>

### Menu Option Two: <br>
Print the list with numbers that represent the frequency of all items purchased. <br>
The screen output should include every item (represented by a word) paired with the number of <br>
times that item appears in the input file, CS210_Project_Three_Input_File.txt. For example, the file might read as follows: <br>
		Potatoes 4 <br>
		Pumpkins 5 <br>
		Onions 3
<br><br>

### Menu Option Three: <br>
Print the same frequency information for all the items in the form of a histogram. <br>
Then print the name, followed by asterisks or another special character to represent the numeric amount. <br>
The number of asterisks should equal the frequency read from the CS210_Project_Three_Input_File.txt file. <br>
For example, if the file includes 4 potatoes, 5 pumpkins, and 3 onions, then your text-based histogram may <br>
appear as represented below. However, you can alter the appearance or color of the histogram in any way you choose: <br>
		Potatoes **** <br>
		Pumpkins ***** <br>
		Onions *** <br>
<br><br>

### Menu Option Four: <br>
Exit the program.
<br><br>

### Data File Creation: <br>
Create a data file, with the naming convention frequency.dat, for backing up your accumulated data. <br>
The frequency.dat file should include every item (represented by a word) paired with the number of times <br>
that item appears in the input file.
