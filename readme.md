# Resolution d'une systeme d'equation d'ordre N en C++

##Recuperation des donnees a partir d'un fichier texte


##Diagonalisation de la Matrice,echellonnage par le pivot de GAUSS


##Affichage du resultat ou d'une erreur si la solution est vide
<kbd>Alt</kbd>

 
 $$ A(X)=B $$
 
 $$ 
\left(\begin{array}
a1  & ... & a3  & ... & an \\
... & ... & ... & ... & ...\\
... & ... & a3  & ... & an \\
... & ... & ... & ... & ...\\
an  & ... & ... & ... & an 
\end{array}\right\)  
. \left(\begin{array}
X1  \\
... \\
Xk  \\
... \\
Xn
\end{array}\right\) 
= \left(\begin{array}
B1  \\
... \\
Bk  \\
... \\
Bn
\end{array}\right\) $$

avec :
$$ 
A = \left(\begin{array}
a1  & ... & a3  & ... & an \\
... & ... & ... & ... & ...\\
... & ... & a3  & ... & an \\
... & ... & ... & ... & ...\\
an  & ... & ... & ... & an 
\end{array}\right\)       X = \left(\begin{array}
X1  \\
... \\
Xk  \\
... \\
Xn
\end{array}\right\)       B = \left(\begin{array}
B1  \\
... \\
Bk  \\
... \\
Bn
\end{array}\right\) $$



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
