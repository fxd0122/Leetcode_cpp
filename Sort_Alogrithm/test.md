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


<pre class="pseudocode" lineNumber="true">
% This inserttion merge algorithm is extracted from Chapter 2, Introduction to Algorithms (3rd edition)
\begin{algorithm}
\caption{MergeSort}
\begin{algorithmic}
\PROCEDURE{Merge}{$A, p, q, r$}
    \STATE $n_1 = q - p + 1$
    \STATE $n_2 = r - q$
    \STATE let $L[1..n_1+1]$ \AND $R[1..n_2+1]$ be new arrays
    \FOR{$i = 1$ \TO $n_1$}
        \STATE $L[i] = A[p+i-1]$
    \ENDFOR
    \FOR{$j = 1$ \TO $n_2$}
        \STATE $R[j] = A[q+j]$
    \ENDFOR
    \STATE $L[n_1+1] = \infty$
    \STATE $R[n_2+1] = \infty$
    \STATE $i = 1$
    \STATE $j = 1$
    \FOR{$k = p$ \TO $r$}
        \IF{$L[i] \leq R[j]$}
            \STATE $A[k] = L[i]$
            \STATE $i = i + 1$
        \ELSE
            \STATE $A[k] = R[j]$
            \STATE $j = j + 1$
        \ENDIF
    \ENDFOR
\ENDPROCEDURE
\PROCEDURE{MergeSort}{$A, p, r$}
    \IF{$p < r$}
        \STATE $q = \lfloor (p+r)/2 \rfloor$ 
        \STATE \CALL{MergeSort}{$A, p, q$}
        \STATE \CALL{MergeSort}{$A, q, r$}
        \STATE \CALL{Merge}{$A, p, q, r$}
    \ENDIF
\ENDPROCEDURE
\end{algorithmic}
\end{algorithm}
</pre>