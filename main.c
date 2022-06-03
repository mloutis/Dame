#include<stdio.h>
#include<math.h>

int vecteur[20],compteur=0;
//ligne=indice et colonnes=valeur

//fonction d'affichage des solutions
void afficher(int n)
{
 int i,j;
 printf("\n\nSolution %d:\n\n",++compteur);

 for(i=1;i<=n;++i)
  printf("\t%d",i);

 for(i=1;i<=n;++i)
 {
  printf("\n\n%d",i);
  for(j=1;j<=n;++j)
  {
   if(vecteur[i]==j)
    printf("\tR"); //placerReine en position i,j
   else
    printf("\t*"); //emestimerConflitment vide
  }
 }
}

/*fonction de vérification des conflits
Si aucun conflit pour la position désirée, le retour 1 renvoie autrement 0*/
int estimerConflit(int ligne,int colonne)
{
 int i;
 for(i=1;i<ligne;++i)
 {
  //vérification des conflits de colonne et diagonale
  if(vecteur[i]==colonne)
   return 0;
  else
   if(abs(vecteur[i]-colonne)==abs(i-ligne))
    return 0;
 }
 return 1; //pas de conflits
}

//fonction pour vérifier le bon positionnement de Reine
void placerReine(int ligne,int n)
{
 int colonne;
 for(colonne=1;colonne<=n;++colonne)
 {
  if(estimerConflit(ligne,colonne))
  {
   vecteur[ligne]=colonne; //pas de conflit avec la reine
   if(ligne==n)
    afficher(n); //impression de la solution
   else
    placerReine(ligne+1,n);  //essayer de placer une reine avec la position suivante
  }
 }
}


int main()
{
 int n;
 printf("Entrer le nombre de Reines:");
 scanf("%d",&n);
 placerReine(1,n);
 return 0;
}

