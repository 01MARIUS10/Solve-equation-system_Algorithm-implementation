# Resolution d'une systeme d'equation d'ordre N en C++
 
 le programme consiste a trouver la solution d'une systeme d'equation donne par l'utlisateur 
 
 ##comment l'employer
 et bien ,il suffit de mettre les coefficient de chaque equation du systeme avec le bon ordre dans un fichier texte,que l'on peut facilement cree dans notre dossier sur ordinateur ,
 puis de glisser le programme sur le meme dossier que ce dernier
 et ensuite on execute le programme
 
 ##comment interagit le programme
 lors de l'execution du programme , il vous demandera la dimension ;c'est a dire le nombre d'equation dans le systeme a resoudre
 puis ensuite le nom du fichier texte contenant les  coefficients 
 et le procesus continuera et affichera la solution $$ x = [X~1~,X~2~,...,X~n~] $$
 



##Recuperation des donnees a partir d'un fichier texte

En utilisant la bibliotheque $$ fstream $$ de C++


##Diagonalisation de la Matrice,echellonnage par le pivot de GAUSS

 
 $$ A(X)=B $$
 
 $$ 
\left(\begin{array}
A~1~1~  & ... & A~1~j~  & ... & A~1~n~ \\
...     & ... & ...     & ... & ...    \\
...     & ... & A~i~j~  & ... & A~i~n~ \\
...     & ... & ...     & ... & ...    \\
A~n~1~  & ... & ...     & ... & A~n~n~ 
\end{array}\right\)  
. \left(\begin{array}
X~1~  \\
... \\
X~k~  \\
... \\
X~n~
\end{array}\right\) 
= \left(\begin{array}
B~1~  \\
... \\
B~k~  \\
... \\
B~n~
\end{array}\right\) $$

avec : 

$$ 
A =\left(\begin{array}
A~1~1~  & ... & A~1~j~  & ... & A~1~n~ \\
...     & ... & ...     & ... & ...    \\
...     & ... & A~i~j~  & ... & A~i~n~ \\
...     & ... & ...     & ... & ...    \\
A~n~1~  & ... & ...     & ... & A~n~n~ 
\end{array}\right\)  
X = \left(\begin{array}
X~1~  \\
... \\
X~k~  \\
... \\
X~n~
\end{array}\right\) 
B = \left(\begin{array}
B~1~  \\
... \\
B~k~  \\
... \\
B~n~
\end{array}\right\) 
$$

##Affichage du resultat ou d'une erreur si la solution est vide
<kbd>Alt</kbd>

voici un programme concu pour pouvoir resoudre une systeme d'equation d'ordre n(reel) en c plus plus

le projet contient tout d'abord aux entete,les directives de precompilation ;
toutes les bibliotheques ,dependances du programme

et ensuite on y trouve des fonctions pour des test unitaires ,notament les display fonction pour afficher nos matrice et vecteur tout au long de notre script en cas de necessite


rentrons au programme lui meme.Comment fonctionne le programme!
le programme se divise en 3etapes :
1)receuil des donne brute sur .txt 
2)diagonalisation de la matrice
3)resolution et Affichage du resultat ou de l'echec en cas ou la solution est vide(matrice non diagonalisable)

il vous suffit donc de rentrer dans le fichier .txt dans l'ordre respective les valeur de la matrice et du vecteur de second membre

le programme demandera a l'utilisateur le nom du fichier et la taile de la matrice a traiter
il receuillera lui meme ses donne et affiche les demarche de diagonalisation ainsi que le resultat s'il existe
elle affichera une message d'erreur au cas ou la matrice n'est pas inversible
