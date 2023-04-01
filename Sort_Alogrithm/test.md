<pre class="pseudocode">
% This inserttion sort algorithm is extracted from Chapter 2, Introduction to Algorithms (3rd edition)
\begin{algorithm}
\caption{QuickSort}
\begin{algorithmic}
\PROCEDURE{InsertionSort}{$A$}
    \STATE // Subscript starts at 1.
    \FOR{$j = 2$ \TO $A.length$}
        \STATE $key = A[j]$
        \STATE $i = j - 1$
        \WHILE{$i > 0$ \AND $A[i] > key$}
            \STATE $A[i+1] = A[i]$
            \STATE $i = i - 1$
        \ENDWHILE
        \STATE $A[i+1] = key$
    \ENDFOR
\ENDPROCEDURE
\end{algorithmic}
\end{algorithm}
</pre>