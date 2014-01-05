3.10.Se dau două mulţimi de numere întregi A şi B. Să se genereze toate funcţiile f:A -> B.

Functia AwithB primeste ca si parametrii :
- int a[] -> un vector care contine elementele multimii A;
- int b[] -> un vector care contine elementele multimii B;
- int m   -> pozitia curenta din multimea A;
- int n	  -> pozitia curenta din multimea B;

Prima data se verifica ca nici unul vectori sa nu fie nuli, daca unul din ei este nul, se intrerupe operatia.

Functia AwithB parcurge multimile recursiv in modul urmator :
- verifica daca s-au parcurs toate elementele din multimea A prin conditia m < 0, daca conditia se indeplineste, se intrerupe operatia;
- verifica daca s-au parcurs toate elementele din multimea B concomitent cu al m-lea elemet din multimea A prin conditia n < 0, daca conditia se indeplineste,
se apeleaza functia pe ea insasi, cu parametrul m fiind egal cu urmatoarea pozitie(m-1) din multimea A si n fiind egal cu ultima pozitie din multimea B (sizeB-1), 
parametrii a si b raman aceeasi;
- daca nici una din conditiile anterioare nu se indeplinesc, functia afiseaza functia "f(a[m]) = b[n]", pe urma se apeleaza pe ea insasi cu parametrul m ramanand
pozitia curenta din multimea A, iar parametrul n fiind egal cu urmatoarea pozitie din multimea B, parametrii a si b raman aceeasi.   