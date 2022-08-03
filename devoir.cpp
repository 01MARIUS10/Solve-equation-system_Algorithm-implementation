#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <stdlib.h>
#define E 0.00001

using namespace std;

void displayVector(vector<double> t){
    int dim =(int)t.size();
    for(int i=0;i<dim;i++){
        cout<< t[i]<<" ";
    }
    cout<<endl;
}
vector<double> inverserVector(vector<double> t){
    vector<double> inverse;
    int dim =(int)t.size();
    for(int i=dim-1;i>=0;i--){
        inverse.push_back(t[i]);
    }
    cout<<endl;
    return inverse;
}
void displayMatrice(vector<vector<double>> t){
    int dim =(int)t[0].size();
    cout<<endl<<"-------AFFICHAGE DE LA MATRICE----------"<<endl;
    for(int i=0;i<dim;i++){
        for(int j=0;j<dim;j++){
            cout<< t[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<"----------------------------------------"<<endl;
}
void displayEquation(vector<vector<double>> t,vector<double> b){
    int dim =(int)t[0].size();
    cout<<endl<<"-------AFFICHAGE DE L' EQUATION'----------"<<endl;
    for(int i=0;i<dim;i++){
        for(int j=0;j<dim;j++){
            cout<< t[i][j]<<"\t";
        }
        cout<<"\t\t"<<b[i]<<endl;
    }
    cout<<"----------------------------------------"<<endl;
}

void askDimention(int &dim){
    cout<<"quel est la dimention du matrice : ";
    cin>>dim;
}
void askFilename(string &filename){
    cout<<"entrer le nom du fichier : ";
    cin>>filename;
}
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

//recherche l'index de la ligne dans la Matrice dont la valeur est maximal 
//      dans les plage de valeur :
//                      colonne=indeColumn && ligne>=indexColumn
//si le maximal vaut zero ,cad inferieur a epsilon alors la booleen devient false et la matrice n'est pas inversible
int indexMaxOfColumn(vector<vector<double>> tab, int indexColumn,bool &isInversible){
    cout<<endl<<"---------le Max dans la column "<<indexColumn<<" est : -----------------"<<endl;
    int dim = ((int)tab[0].size()); 

    int max =tab[indexColumn][indexColumn];
    int index = indexColumn;

    for(int i=indexColumn;i<dim;i++){
        if(max<tab[i][indexColumn]){
            max = tab[i][indexColumn];
            index=i;
        }  
    }

    cout<<"max  = "<<max<<endl;
    cout<<"indexMax  = "<<index;

    if(abs(max)<E){
        isInversible=false;
    }
    return index;
}

//swaper le vecteur b
void swapLineVector(int p,int q , vector<double> &b){
    double tmp;
    tmp=b[p];
    b[p]=b[q];
    b[q]=tmp;
}
//permuter les ligne p et q de la matrice
//utile apres avoir pris comme pivot l'element d'une ligne 
void swapLineMatrice(int p , int q , vector<vector<double>> &Matrice ,vector<double> &b){
    double myDouble;
    cout<<endl<<"---------SWAPer les  lines "<<p<<" et "<<q<<"-----------------";
    int dim = (int)Matrice[0].size();
    for(int i=0;i<dim;i++){
        myDouble=Matrice[p][i];
        Matrice[p][i]=Matrice[q][i];
        Matrice[q][i]=myDouble;
    }

    swapLineVector(p,q,b);
}

//transforme les ligne apres le pivot
//li = li *(coef) -lp
//transforme en zero les valeurs en dessous du pivot choisi
void pivoter(int indexPivot,vector<vector<double>> &Matrice ,vector<double> &b){
    int dim = (int)Matrice[0].size();
    double coef;
    cout<<" pivoter ligne par ligne avec le pivot du  "<<indexPivot<<"e colonne";
    //on parcous toutes les valeurs en dessous du pivot
    for(int i=indexPivot+1;i<dim;i++){
        //on effectue l'echellonage 
        //rendre les valeurs en dessous du pivot null
        //si c'est deja le cas ,on passe au suivant 

        //verifier que la valeur different de zero
        if(abs(Matrice[i][indexPivot])>E){
            //faire l'echellonnage
            coef=Matrice[indexPivot][indexPivot]/Matrice[i][indexPivot];
            for(int j=indexPivot;j<dim;j++){
                Matrice[i][j] = (Matrice[i][j] * coef) -Matrice[indexPivot][j];

                //une petite arrondissement pour eviter les approximations scientifiques 
                if(abs(Matrice[i][j])<E){
                    Matrice[i][j]=0;
                }
            }
            b[i]=b[i]*coef -b[indexPivot];
        }
    }
}

int main()
{   
    vector<vector<double>> Matrice;//la matrice 
    vector<double> b;           //le vecteur colonne du second membre

    bool isInversible = true;      //verifier si la matrice n'est pas inversible
    string filename;            //le nom du fichier texte
    int dim;                 //la dimention de la matrtice

    askDimention(dim);
    askFilename(filename);
    getvalueTotxt(filename+".txt",Matrice,b,dim);
    displayEquation(Matrice,b);

    //diagonalisation de la matrice
    //le programme s'arretera si dans les iterations une ligne devient vide 
    //ou aussi que deux column soit liee grace au booleen "isInversible"
    int i=0;
    int indexPivot;
    //on parcours le colonne de la matrice
    while(i<dim && isInversible){
        cout<<endl<<endl<<"----------------"<<i<<"eme colonne----------------";
        //on cherche le max pour chaque colonne et on le prend comme pivot
        indexPivot=indexMaxOfColumn(Matrice,i,isInversible);

        //on le fait monter au {colonne}ieme ligne, cad a la diagonale
        swapLineMatrice(i,indexPivot,Matrice,b);
        displayEquation(Matrice,b);
        //on le pivote ,cad rendre les elements de la ligne zero 
        pivoter(i,Matrice,b);
        displayEquation(Matrice,b);
        cout<<endl<<endl;
        //et on incremente
        i++;
    }

    //dans le cas ou l'iteration etait interrompu par le booleen
    //cad que la matrice ne soit pas inversible
    if(!isInversible){
        cout<<"la matrice n'est pas inversible , la colonne "<<indexPivot+1<<" est une combinaison des autres colonnes"<<endl<<endl;
    }

    //l'iteration s'est bien terminer et la matrice est inversible
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
    return 0;
}