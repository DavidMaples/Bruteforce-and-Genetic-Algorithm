# Project-2-DSA<!DOCTYPE html PUBLIC "-//w3c//dtd html 4.0 transitional//en">
<html><head>









   

</style></head><body>
<center>
<p style="margin-top: 0pt; margin-bottom: 0pt;"><b><span size="4" style="font-size: large;">The University of West Florida <br> Department of Computer Science</span></b></p>
<p style="margin-top: 0pt; margin-bottom: 0pt;"><b><span size="4" style="font-size: large;">Data Structures and Algorithms II</span></b></p>
<p style="margin-top: 0pt; margin-bottom: 0pt;"><b><span size="4" style="font-size: large;">John W. Coffey</span></b></p>
</center>
<p style="margin-top: 0pt; margin-bottom: 0pt;">&nbsp;</p>
<p style="margin-top: 0pt; margin-bottom: 0pt;"><b>Background</b></p>
<p style="margin-top: 0pt; margin-bottom: 0pt;">A very famous
graph/permutation problem is the Traveling Salesman Problem: given n
cities with different distances among them and a designated first city,
what is the least cost to visit all cities and return to the first one?
Unfortunately, the brute-force method of solving this problem requires
that we assess (n - 1)! permutations of the cities. How feasible is
this?</p>
<p style="margin-top: 0pt; margin-bottom: 0pt;">&nbsp;</p>
<p style="margin-top: 0pt; margin-bottom: 0pt;">However, not all is
lost. For computationally "hard" problems such as this one, we may
employ any of several means to find good if not strictly optimal
solutions - say within 5-10%&nbsp; of optimal. (Note that
"computationally hard" problems are formalized as "np-complete" or
"np-hard."). One way to address this problem might be based upon a
simplified approach to the permutation form of genetic algorithms. As
always, <a href="http://en.wikipedia.org/wiki/Genetic_algorithms" target="_blank" rel="noopener noreferrer">Wikipedia </a>has some good information on this technique.</p>
<p style="margin-top: 0pt; margin-bottom: 0pt;">&nbsp;</p>
<p style="margin-top: 0pt; margin-bottom: 0pt;">Here is a basic approach (based upon an algorithm presented at Wikipedia) to solve our problem:</p>
<p style="margin-top: 0pt; margin-bottom: 0pt;"><br>
</p>

<div id="globalWrapper">
<div id="column-content">
<div id="content">
<div id="bodyContent">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
Choose the initial <a title="Population" href="http://en.wikipedia.org/wiki/Population" style="text-decoration: none;"> <span color="#000000" style="color: rgb(0, 0, 0);">population</span></a> of tours (generate a set of permutations of the orderings of the cities)<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Evaluate the <a title="Fitness (biology)" href="http://en.wikipedia.org/wiki/Fitness_%28biology%2529" style="text-decoration: none;"> <span color="#000000" style="color: rgb(0, 0, 0);">fitness</span></a> (cost) of each <a title="Individual" href="http://en.wikipedia.org/wiki/Individual" style="text-decoration: none;"> <span color="#000000" style="color: rgb(0, 0, 0);">individual</span></a> tour<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Repeat<br>


<p style="margin-top: 0pt; margin-bottom: 0pt;">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Select best-ranking individuals <a class="mw-redirect" title="Reproduce" href="http://en.wikipedia.org/wiki/Reproduce" style="text-decoration: none;"><span color="#000000" style="color: rgb(0, 0, 0);"></span></a>as elites (see below)</p>

<p style="margin-top: 0pt; margin-bottom: 0pt;">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; <a title="Breed" href="http://en.wikipedia.org/wiki/Breed" style="text-decoration: none;"><span color="#000000" style="color: rgb(0, 0, 0);">Create additional tours</span></a><a title="Generation" href="http://en.wikipedia.org/wiki/Generation" style="text-decoration: none;"><span color="#000000" style="color: rgb(0, 0, 0);"></span></a> through <a title="Crossover (genetic algorithm)" href="http://en.wikipedia.org/wiki/Crossover_%28genetic_algorithm%2529" style="text-decoration: none;"> <span color="#000000" style="color: rgb(0, 0, 0);">crossover</span></a>, <a title="Mutation (genetic algorithm)" href="http://en.wikipedia.org/wiki/Mutation_%28genetic_algorithm%2529" style="text-decoration: none;"> <span color="#000000" style="color: rgb(0, 0, 0);">mutation</span></a> or both (genetic operations) and give birth to <a title="Offspring" href="http://en.wikipedia.org/wiki/Offspring" style="text-decoration: none;"> <span color="#000000" style="color: rgb(0, 0, 0);">offspring</span></a></p>


<p style="margin-top: 0pt; margin-bottom: 0pt;">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Add new permutations to fill out the current generation</p>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Evaluate the fitness of each individual tour<br>
<p style="margin-top: 0pt; margin-bottom: 0pt;">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Until termination criteria are met</p>

</div>
</div>
</div>
</div>
<p style="margin-top: 0pt; margin-bottom: 0pt;"><b></b></p>
<p style="margin-top: 0pt; margin-bottom: 0pt;"><b><br>
</b></p>
<p style="margin-top: 0pt; margin-bottom: 0pt;"><b>Subsequent Generations </b><span style="font-style: italic;">might </span>be made up of:</p>

<p style="margin-top: 0pt; margin-bottom: 0pt;">&nbsp;</p>
<p style="margin-top: 0pt; margin-bottom: 0pt;">Mutations:</p>
<p style="margin-top: 0pt; margin-bottom: 0pt;">Make a minor change
(for instance, randomly swap two, three, or four cities) to make a different version of an already good order.</p>
<p style="margin-top: 0pt; margin-bottom: 0pt;">&nbsp;</p>
<p style="margin-top: 0pt; margin-bottom: 0pt;">Crossovers:</p>
<p style="margin-top: 0pt; margin-bottom: 0pt;">Splice the end of one ordering to the end of another. This is not simple to realize with permutation problems (why?)</p>
<p style="margin-top: 0pt; margin-bottom: 0pt;">&nbsp;</p>
<p style="margin-top: 0pt; margin-bottom: 0pt;">Elites</p>
<p style="margin-top: 0pt; margin-bottom: 0pt;">Keep the few best tours as-is.</p>
<p style="margin-top: 0pt; margin-bottom: 0pt;">Make copies of them and mutate the copies.</p>
<p style="margin-top: 0pt; margin-bottom: 0pt;">&nbsp;</p>
<p style="margin-top: 0pt; margin-bottom: 0pt;"><b>Termination of the Algorithm:</b></p>
<div id="globalWrapper0">
<div id="column-content0">
<div id="content0">
<div id="bodyContent0">You will repeat the process of creating a
generation of tours, checking for the best, determining elites and
creating mutations, until the program reaches a terminating condition.
Typical ways to terminate this type of algorithm include:
<ul>
<li>A solution is found that satisfies minimum criteria (found a tour that is less than some maximum acceptable cost)</li>
<li>A fixed number of generations is reached. We will use this approach for this project.<br>
</li>
<li>More iterations do not produce better results</li>
</ul>
</div>
</div>
</div>
</div>
<p style="margin-top: 0pt; margin-bottom: 0pt;">We will use the fixed number of generations approach.<b><br> </b></p>
<p style="margin-top: 0pt; margin-bottom: 0pt;"><b><br> </b></p>
<p style="margin-top: 0pt; margin-bottom: 0pt;"><b>Program Description</b></p>
<p style="margin-top: 0pt; margin-bottom: 0pt;">Your task in this assignment will be to write <i>two solutions </i>to the TSP problem, both of which will run in <span style="font-style: italic;">one program</span>:</p>
<ul>
<li>
<p style="margin-top: 0pt; margin-bottom: 0pt;">a brute-force permutation program that systematically tries all possible permutations, ultimately computing the optimal answer.</p>
</li>
<li>
<p style="margin-top: 0pt; margin-bottom: 0pt;">a genetic algorithm-inspired solution.</p>
</li>
</ul>
<p><span style="font-weight: bold;">Program Inputs</span></p>
<p style="margin-top: 0pt; margin-bottom: 0pt;">The program will utilize an input file named <span style="font-family: monospace;">distances.txt</span> which contains the weights of the edges between cities<span style="font-family: monospace;"></span>. You will read <span style="font-family: monospace;">distances.txt</span>.
For simplicity, we will deal with a problem in which all cities connect
to all other - in other words, with a complete graph. We will set up a
single graph that can be used for 20 cities, more than we will need for
this project. You will ALWAYS just read all values of the distances into a 20 X 20 adjacency matrix.<br>&nbsp;</p>
<p><span style="font-family: monospace;">distances</span><span style="font-family: monospace;">.txt</span>
will contain the appropriate number of distances between cities (380),
one per line. Note - the number of items in the file is 380 rather than
400 because no cities connect to themselves. Read them as doubles.</p>
<p style="margin-top: 0pt; margin-bottom: 0pt;"><br> <big><span style="font-family: monospace;"></span></big></p>
<p style="margin-top: 0pt; margin-bottom: 0pt;">When your program runs, it will interactively get the following information from the user:</p>
<ul>
<li>
<p style="margin-top: 0pt; margin-bottom: 0pt;">the number of cities to run</p>
</li>
<li>
<p style="margin-top: 0pt; margin-bottom: 0pt;">how many individual tours are in a given generation</p>
</li>
<li>how many generations to run</li>
<li>
<p style="margin-top: 0pt; margin-bottom: 0pt;">what percentage of a generation should be comprised of mutations</p>
</li>
</ul>
<p style="margin-top: 0pt; margin-bottom: 0pt;">Your program will always keep <span style="font-style: italic;">exactly two</span> elites. The program reads the <span style="font-family: monospace;">distances</span><span style="font-family: monospace;">.txt</span> file, gets the input from the user and then the two algorithms will grind away until output is produced.</p>
<br>
<p style="margin-top: 0pt; margin-bottom: 0pt;"><br>
</p>


<p style="margin-top: 0pt; margin-bottom: 0pt;">A graphical
representation of how the generations should work is available along
with this file and distances.txt on the assignment page. The following link MIGHT work:<br>
<a href="Project3TSPGraphic.pdf" target="_blank"><span style="text-decoration: underline;"><span style="font-weight: bold;"><br>
</span></span></a></p>
<p style="margin-top: 0pt; margin-bottom: 0pt;"><a href="Project3TSPGraphic.pdf" target="_blank"><b>Project3TSPGraphic.pdf</b></a></p>
<p style="margin-top: 0pt; margin-bottom: 0pt;"><b><a href="Project3TSPGraphic.pdf" target="_self"><br>
</a></b></p>

<p><span style="font-weight: bold;">Getting tours to try.<br></span><span style="font-weight: bold;"><br></span> You can generate permutations using an iterative permutation algorithm as follows:<span style="font-weight: bold;"><br> <br></span><span style="font-weight: bold;"></span></p>

<div><span style="font-family: 'courier new',courier,sans-serif;">&nbsp; void perm1(int </span><span style="font-family: 'courier new',courier,sans-serif;"></span><span style="font-family: 'courier new',courier,sans-serif;">permsThisCall</span><span style="font-family: 'courier new',courier,sans-serif;">)&nbsp;</span></div>
<div><span style="font-family: 'courier new',courier,sans-serif;">&nbsp; {</span></div>
<div><span style="font-family: 'courier new',courier,sans-serif;">&nbsp; &nbsp; &nbsp;int m, k, p , q, i;</span></div>
<div><span style="font-family: 'courier new',courier,sans-serif;">&nbsp; &nbsp; &nbsp;printS();</span></div>
<div></div>
<div><span style="font-family: 'courier new',courier,sans-serif;">&nbsp; &nbsp; &nbsp;for(i = 1; i &lt; </span><span style="font-family: 'courier new',courier,sans-serif;">permsThisCall</span><span style="font-family: 'courier new',courier,sans-serif;"></span><span style="font-family: 'courier new',courier,sans-serif;">; i++)</span></div>
<div><span style="font-family: 'courier new',courier,sans-serif;">&nbsp; &nbsp; &nbsp;{</span></div>
<div><span style="font-family: 'courier new',courier,sans-serif;">&nbsp; &nbsp; &nbsp; &nbsp;m = </span><span style="font-family: 'courier new',courier,sans-serif;">NUMELEMENTS</span><span style="font-family: 'courier new',courier,sans-serif;">-2;</span></div>
<div><span style="font-family: 'courier new',courier,sans-serif;">&nbsp; &nbsp; &nbsp; &nbsp;while(s[m]&gt;s[m+1])</span></div>
<div><span style="font-family: 'courier new',courier,sans-serif;">&nbsp; &nbsp; &nbsp; &nbsp;{</span></div>
<div><span style="font-family: 'courier new',courier,sans-serif;">&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; m = m - 1;</span></div>
<div><span style="font-family: 'courier new',courier,sans-serif;">&nbsp; &nbsp; &nbsp; &nbsp;}</span></div>
<div><span style="font-family: 'courier new',courier,sans-serif;">&nbsp; &nbsp; &nbsp; &nbsp;k = </span><span style="font-family: 'courier new',courier,sans-serif;">NUMELEMENTS</span><span style="font-family: 'courier new',courier,sans-serif;">-1;</span></div>
<div><span style="font-family: 'courier new',courier,sans-serif;">&nbsp; &nbsp; &nbsp; &nbsp;while(s[m] &gt; s[k])</span></div>
<div><span style="font-family: 'courier new',courier,sans-serif;">&nbsp; &nbsp; &nbsp; &nbsp;{</span></div>
<div><span style="font-family: 'courier new',courier,sans-serif;">&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; k = k - 1;</span></div>
<div><span style="font-family: 'courier new',courier,sans-serif;">&nbsp; &nbsp; &nbsp; &nbsp;}</span></div>
<div><span style="font-family: 'courier new',courier,sans-serif;">&nbsp; &nbsp; &nbsp; &nbsp;swap(m,k);</span></div>
<div><span style="font-family: 'courier new',courier,sans-serif;">&nbsp; &nbsp; &nbsp; &nbsp;p = m + 1;</span></div>
<div><span style="font-family: 'courier new',courier,sans-serif;">&nbsp; &nbsp; &nbsp; &nbsp;q = NUMELEMENTS-1;</span></div>
<div><span style="font-family: 'courier new',courier,sans-serif;">&nbsp; &nbsp; &nbsp; &nbsp;while( p &lt; q)</span></div>
<div><span style="font-family: 'courier new',courier,sans-serif;">&nbsp; &nbsp; &nbsp; &nbsp;{</span></div>
<div><span style="font-family: 'courier new',courier,sans-serif;">&nbsp; &nbsp; &nbsp; &nbsp; &nbsp;swap(p,q);</span></div>
<div><span style="font-family: 'courier new',courier,sans-serif;">&nbsp; &nbsp; &nbsp; &nbsp; &nbsp;p++;</span></div>
<div><span style="font-family: 'courier new',courier,sans-serif;">&nbsp; &nbsp; &nbsp; &nbsp; &nbsp;q--;</span></div>
<div><span style="font-family: 'courier new',courier,sans-serif;">&nbsp; &nbsp; &nbsp; &nbsp;}</span></div>
<div><span style="font-family: 'courier new',courier,sans-serif;">&nbsp; &nbsp; &nbsp; &nbsp;printS();</span></div>
<div><span style="font-family: 'courier new',courier,sans-serif;">&nbsp; &nbsp; &nbsp;}</span></div>
<div><span style="font-family: 'courier new',courier,sans-serif;">&nbsp; &nbsp;}&nbsp;</span></div>
<p><strong>Notes on the algorithm:</strong>
<br>
</p>
<p>The algorithm as presented will produce all permutations of <span style="font-family: 'courier new',courier,sans-serif;">NUMELEMENTS </span>ints in the s array if the following is met</p>

<ul>
  <li><span style="font-family: 'courier new',courier,sans-serif;">int s[]</span> // an int array external to the function</li>
  <li><span style="font-family: 'courier new',courier,sans-serif;">NUMELEMENTS</span> is the number of ints in the <span style="font-family: 'courier new',courier,sans-serif;">s</span> array that you are permuting</li>

<li>the parameter <span style="font-family: 'courier new',courier,sans-serif;">permsThisCall</span><span style="font-family: 'courier new',courier,sans-serif;"></span> is <span style="font-family: 'courier new',courier,sans-serif;">NUMELEMENTS</span>!<span style="font-family: 'courier new',courier,sans-serif;"></span><br>
</li>
<li>you must implement swap so that the state of s is maintained</li>
<li>function <span style="font-family: 'courier new',courier,sans-serif;">printS()</span> prints the s array, thereby displaying the next permutation.<br>
</li>
</ul>
<p style="margin-top: 0pt; margin-bottom: 0pt;">If <span style="font-family: 'courier new',courier,sans-serif;">permsThisCall</span><span style="font-family: 'courier new',courier,sans-serif;"></span> is fewer that <span style="font-family: 'courier new',courier,sans-serif;">NUMELEMENTS</span>! you will get just that amount of permutations, for instance when you are filling out a generation in the GA.<br>
</p>
<p style="margin-top: 0pt; margin-bottom: 0pt;"><b><br>
</b></p>
<p style="margin-top: 0pt; margin-bottom: 0pt;"><b>Experiments:</b></p>

<p style="margin-top: 0pt; margin-bottom: 0pt;">You will experiment
with various values for these parameters to see which provide the best
results for a given number of generations. You will incorporate timer
capabilities into the programs so that you know how long runs with
various parameters took. You will compare performance of the two
approaches for different numbers of cities. <br>
</p>
<p style="margin-top: 0pt; margin-bottom: 0pt;"><br>
</p>
<p style="margin-top: 0pt; margin-bottom: 0pt;">Start at 10 cities and go
up by 1 from there until you see a runtime of greater than 5 minutes on
the brute force solution. You will not have to go far to get there.
Create a table that compares the time results from the approximation
compared to the brute force from 10 cities up until the brute force
method requires more than 5 minutes. Show what percentage of the
optimal solution (eg: 120% of optimal) your approximation solution
provides at each run.</p>

<p style="margin-top: 0pt; margin-bottom: 0pt;"></p>
<p style="margin-top: 0pt; margin-bottom: 0pt;"><strong><br>
</strong></p>
<p style="margin-top: 0pt; margin-bottom: 0pt;"><strong>A Timer:</strong></p>

<p style="margin-top: 0pt; margin-bottom: 0pt;">Click this link:&nbsp;<a href="time.c" target="_self">time.c</a></p>
<p style="margin-top: 0pt; margin-bottom: 0pt;"></p>
<p style="margin-top: 0pt; margin-bottom: 0pt; font-weight: bold;"><br>
</p>
<p style="margin-top: 0pt; margin-bottom: 0pt; font-weight: bold;">Output:</p>

<p style="margin-top: 0pt; margin-bottom: 0pt;">When the progam runs, it will display as output:</p>
<ul>
<li>The number of cities run</li>
<li>optimal cost from brute force</li>
<li>time the brute force algorithm took</li>
<li>cost from the ga</li>
<li>time the ga took to run</li>
<li>percent of optimal (eg: 120%) that the ga produced&nbsp;</li>
</ul>
<p style="margin-top: 0pt; margin-bottom: 0pt;"></p>
<p style="margin-top: 0pt; margin-bottom: 0pt;"><b>Deliverables</b></p>
<p style="margin-top: 0pt; margin-bottom: 0pt;">You will submit the following for this project: <br>
</p>
<p style="margin-top: 0pt; margin-bottom: 0pt;">1. A User's manual that describes how to set up and run your program.</p>
<p style="margin-top: 0pt; margin-bottom: 0pt;"> 2. A UML diagram reflecting the final layout of your program.</p>
<p style="margin-top: 0pt; margin-bottom: 0pt;">3. Your source code in C. <br>4.
Results table disk file: An Excel spreadsheet containing the results
from each run (for 10, 11, 12, etc cities) with one row for the 10
city, 11 city, 12 city, etc run. The column headers should be the 6
items output by a single run. This table is
a summary of the data for all the individual&nbsp; outputs from 10
cities, 11 cities, etc.<br>
</p>

<p style="margin-top: 0pt; margin-bottom: 0pt;">5. A makefile for the project</p>
<p style="margin-top: 0pt; margin-bottom: 0pt;"><br>
</p>

<p style="margin-top: 0pt; margin-bottom: 0pt;"></p>
<div class="Section1">
<p class="MsoNormal" style="margin-top: 0pt; margin-bottom: 0pt;">&nbsp;<span><b>Submission Requirements</b></span><b>: </b><span style="font-weight: bold;">&nbsp;</span></p>
<p class="MsoNormal" style="margin-top: 0pt; margin-bottom: 0pt;"></p>
<p>Note: you will lose 10% if you do not follow these instructions <em>exactly</em>.
The reason for this policy is that eLearning puts zip files inside zip
files and it is a time-consuming, tedious, and error-prone policy to
unzip them all one-by-one. I have a utility I wrote that nicely unzips
all these into a usable folder structure. If you do not follow these
instructions, your files will get all mashed up together with others,
often with name collisions and it is an unusable mess.</p>
<p style="margin: 0pt 0in; font-size: medium; font-family: &quot;Times New Roman&quot;; color: rgb(0, 0, 0); font-style: normal; font-weight: 400; letter-spacing: normal; orphans: 2; text-align: start; text-indent: 0px; text-transform: none; white-space: normal; widows: 2; word-spacing: 0px;">1.
Compile and run your program one last time before submitting it. Your
program must run in Linux in the multiplatform lab.&nbsp;</p>
<p style="margin: 0pt 0in; font-size: medium; font-family: &quot;Times New Roman&quot;; color: rgb(0, 0, 0); font-style: normal; font-weight: 400; letter-spacing: normal; orphans: 2; text-align: start; text-indent: 0px; text-transform: none; white-space: normal; widows: 2; word-spacing: 0px;">2.
Place all deliverables in a single folder that is named with your last
name and first name initial. For example, if your name is John Coffey, the folder should be coffeyj. If you are a
MacOS user, delete the _MacOS_ folder before zipping up your submission.<br></p>
<p style="margin: 0pt 0in; font-size: medium; font-family: &quot;Times New Roman&quot;; color: rgb(0, 0, 0); font-style: normal; font-weight: 400; letter-spacing: normal; orphans: 2; text-align: start; text-indent: 0px; text-transform: none; white-space: normal; widows: 2; word-spacing: 0px;">3. Create a "zip"&nbsp; file using WinZip or similar program that creates .zip files, to hold your project files.</p>
<p style="margin: 0pt 0in; font-size: medium; font-family: &quot;Times New Roman&quot;; color: rgb(0, 0, 0); font-style: normal; font-weight: 400; letter-spacing: normal; orphans: 2; text-align: start; text-indent: 0px; text-transform: none; white-space: normal; widows: 2; word-spacing: 0px;">Your
zip file should be named exactly like the single folder inside it but
with the .zip extension. For instance:&nbsp; coffeyj.zip.</p>
<p style="margin: 0pt 0in; font-size: medium; font-family: &quot;Times New Roman&quot;; color: rgb(0, 0, 0); font-style: normal; font-weight: 400; letter-spacing: normal; orphans: 2; text-align: start; text-indent: 0px; text-transform: none; white-space: normal; widows: 2; word-spacing: 0px;">3. Login to Canvas and select our course from the dashboard.</p>
<p style="margin: 0pt 0in; font-size: medium; font-family: &quot;Times New Roman&quot;; color: rgb(0, 0, 0); font-style: normal; font-weight: 400; letter-spacing: normal; orphans: 2; text-align: start; text-indent: 0px; text-transform: none; white-space: normal; widows: 2; word-spacing: 0px;">4. Go to the Assignments page and choose the assignment for which you are submitting a project.</p>
<span style="color: rgb(0, 0, 0); font-family: &quot;Times New Roman&quot;; font-size: medium; font-style: normal; font-weight: 400; letter-spacing: normal; orphans: 2; text-align: start; text-indent: 0px; text-transform: none; white-space: normal; widows: 2; word-spacing: 0px; float: none; display: inline ! important;">5. Click the "Submit Assignment" button.</span><br style="color: rgb(0, 0, 0); font-family: &quot;Times New Roman&quot;; font-size: medium; font-style: normal; font-weight: 400; letter-spacing: normal; orphans: 2; text-align: start; text-indent: 0px; text-transform: none; white-space: normal; widows: 2; word-spacing: 0px;">
<span style="color: rgb(0, 0, 0); font-family: &quot;Times New Roman&quot;; font-size: medium; font-style: normal; font-weight: 400; letter-spacing: normal; orphans: 2; text-align: start; text-indent: 0px; text-transform: none; white-space: normal; widows: 2; word-spacing: 0px; float: none; display: inline ! important;">6. Use the "Choose File" capability to select and upload your .zip file.</span>
<p></p>

<p>Please review the policy on ACADEMIC MISCONDUCT. This is an&nbsp;<em>individual assignment.</em></p>
</div>
</body></html>
