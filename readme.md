# Resolution d'une systeme d'equation d'ordre N en C++
 
 le programme consiste a trouver la solution d'une systeme d'equation donne par l'utlisateur 
 
 comment l'employer
 -------------------
 et bien ,il suffit de mettre les coefficient de chaque equation du systeme avec le bon ordre dans un fichier texte,
 que l'on peut facilement cree dans notre dossier sur ordinateur ,<br>
 puis de glisser le programme sur le meme dossier que ce dernier
 et ensuite on execute le programme.
 
 comment interagit le programme
----------------------------------
 lors de l'execution du programme , il vous demandera la dimension ;c'est a dire le nombre d'equation dans le systeme a resoudre
 puis ensuite le nom du fichier texte contenant les  coefficients 
 et le ***procesus*** continuera et affichera la solution $$ x = (X~1~,X~2~,...,X~n~) $$
 

Entrons plutot dans le detail de ce ***processus***
------------------------------------------------------
ce processus contient 3etapes : <br>

***1.Recuperation des donnees a partir d'un fichier texte***<br>
Apres avoir entrer le nom du fichier et le nombre d'equation (Mathematiquement la dimension de la Matrice),<br>
le  programme va inserer chaque valeur du fichier dans l'ordre respective dans une matrice (Manipulable) en utilisant la bibliotheque ** fstream ** de C++.

```
void getvalueTotxt(string filename ,vector<vector<double> >&Mat,vector<double> &a ,int dim){
    double b;
    vector<double> tmp;
    ifstream f (filename);
    if (!f.is_open())
        cout << "Impossible d'ouvrir le fichier en lecture !" << endl;
    else
    {
        for (int i = 0; i < dim; i++){
            for(int j=0;j<dim;j++){
                f >> b;
                tmp.push_back(b);
                b=0;
            }
            Mat.push_back(tmp);
            tmp.clear();
        }
        for(int i = 0; i < dim; i++){
            f >> b;
            a.push_back(b);
            b=0;
        }
    }
    f.close();
}
```

***2.Diagonalisation de la Matrice,echellonnage par le pivot de GAUSS***<br>

 
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

puis on procede a l'algorithme de gauss comme ci dessous a la matrice **A** et aussi **B** en parallele<br>

<img src="https://s3-eu-west-1.amazonaws.com/sdz-upload/prod/upload/tri.PNG"
     alt="Algorithme de Gauss"
     style=" margin:auto;height:300px;width:80%;" />

afin de verifier le cas ou une colonne n'est lineairement independant , on choisira comme pivot le max de chaque colonne<br>

dans la partie code ,on a ajouter le boolean isInversible pour arreter au cas ou une colonne n'est lineairement independant,c'est a dire si les valeurs en dessous du pivot valent tous zero .

```
while(i<dim && isInversible){
        cout<<endl<<endl<<"----------------"<<i<<"eme colonne----------------";
        
        //on cherche le max pour chaque colonne et on le prend comme pivot
        indexPivot=indexMaxOfColumn(Matrice,i,isInversible);

        //on le fait monter au {colonne}ieme ligne, cad a la diagonale
        swapLineMatrice(i,indexPivot,Matrice,b);
        
        //on le pivote ,cad rendre les elements de la ligne zero 
        pivoter(i,Matrice,b);

        //et on incremente
        i++;
    }
```

***3.Resultat finale***<br>
Deux cas peuvent se produire lors de la diagonalisation :<br>
    soit l'echelonnage s'est terminer jusque a la fin,c'est a dire **n**ieme colonne<br>
    soit on a pu trouver lors du parcours de chaque colonne une colonne lie au autre,c'est a dire qu'il peuvent s'exprimer comme combinaison lineaire des colonnes deja parcouru par la boucle<br>et par le theoreme de l' __Algebre__ ,la matrice compose de vecteur colonne lie n'est pas inversible ,donc pas de solution pour notre systeme

    c'est l'importance du booleen **isInversible** <br>
    comme son nom l'indique , si isInversible est false ; alors on affichera que l'on aurait pas de solution <br>
    il precisera en plus quel colonne etait le probleme(le fameux combinaison des autres colonnes)
    
 
    ```
    if(!isInversible){
        cout<<"la matrice n'est pas inversible , la colonne "<<indexPivot+1<<" est une combinaison des autres colonnes"<<endl<<endl;
    }
    ```
    
    <br>

    si parcontre isInversible est true , alors on procede a l'algorithme ci dessous et obtenir la solution du systeme.<br>
    
    
    ```
    else{
        cout<<endl<<endl<<"Echellonage fini ;"<<endl;
        cout<<"go resolve the value"<<endl;
        vector<double> X;

        //on itere du bas vers le haut
        for(int i=dim-1;i>=0;i--){
            int j=dim-1;
            int k=0;
            double scalaire=0;
            //et de la fin vers le debut
            while(j>i){
                //la variable scalaire est une produit scalaire du resultat deja trouve X[k] 
                //et des element non vide de la matrice a la ligne iterer
                scalaire+=Matrice[i][j]*X[k];
                j--;
                k++;
            }
            //on obtient le resultat inversement, cad pas (x1,x2,...xN) mais (xN,....,x2,x1)
            //on l'obtient et le stock a chaque iteration de ligne 
            X.push_back((b[i]-scalaire)/Matrice[i][i]);
        }
        //on inverse pour obtenir le resultat dans le bon ordre 
        X=inverserVector(X);

        //affichage du resultat
        cout<< "le resultat est :" <<endl;
        displayVector(X);
    }
    ```


