<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
</head>
<body>

<h1>Numerical Integration</h1>

<p>
This program computes the definite integral of the function f(x) = x<sup>7</sup> on the interval [0, 1] using five composite quadrature formulas:
</p>
<ul>
  <li>Rectangle rule (midpoint)</li>
  <li>Trapezoidal rule</li>
  <li>Simpson's rule</li>
  <li>Newton–Cotes (5‑point)</li>
  <li>Gauss–Legendre (3‑point)</li>
</ul>
<p>
The calculations are performed for two partitions: with K intervals and with 2K intervals. Relative errors are computed and displayed in a table.
</p>

<h2>Requirements</h2>
<ul>
  <li>C++ compiler with C++17 support (e.g., g++, clang++)</li>
  <li>GNU Make</li>
</ul>

<h2>Quick Start</h2>
<pre><code>
git clone &lt;your-repo-url&gt;
cd &lt;project-folder&gt;
make          # compile the program
make run      # compile and run
</code></pre>
<p>Alternatively:</p>
<pre><code>
make
./num_integ
</code></pre>
<p>To clean up:</p>
<pre><code>
make clean
</code></pre>

<h2>Example Output</h2>
<p>After running <code>./num_integ</code>, the console shows:</p>

<pre>
       Table of relative errors
––––––––––––––––––––––––––––––––––––––––––––
|               |     K     |   2 * K   |
––––––––––––––––––––––––––––––––––––––––––––
|  Rectangle    | 1.234e-03 | 3.086e-04 |
––––––––––––––––––––––––––––––––––––––––––––
|  Trapezoid    | 2.468e-03 | 6.172e-04 |
––––––––––––––––––––––––––––––––––––––––––––
|   Simpson     | 1.524e-06 | 9.527e-08 |
––––––––––––––––––––––––––––––––––––––––––––
| Newton-Kotes  | 1.234e-08 | 1.929e-10 |
––––––––––––––––––––––––––––––––––––––––––––
|    Gauss      | 1.234e-08 | 1.929e-10 |
––––––––––––––––––––––––––––––––––––––––––––
</pre>
<p><em>(The exact values depend on the chosen function f(x) and the integration limits.)</em></p>

<h2>Project Structure</h2>
<pre>
.
├── Makefile
├── README.md
├── .gitignore
├── LICENSE
├── src/
│   ├── main.cpp
│   ├── functions.cpp
│   └── functions.h
└── build/                  # object files (ignored)
</pre>

<h2>Author</h2>
<p><strong>Name:</strong> Philip Karev @g30613740</p>
<p><strong>Year:</strong> 2024</p>

<h2>License</h2>
<p>This project is distributed under the MIT License.</p>

</body>
</html>
