#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int jour;
    int mois;      //LA PREMIERE STRUCTURE DATE
    int annee;
    }Date;

    typedef struct {
    int num;
    char ville[20];        //LA DEUXIEME STRUCTURE ADRESSE
    }Adresse;
       //*******la structure etudiant*******
    typedef struct {
    char nomprenom[50];
    long cne;     //peut etre declarer char
    Date birth;
    Adresse address;

    }Etudiant;
//*********la premiere fonction .*******
    Etudiant* saisie(int taille){
        int i;
        Etudiant *Letd;
        Letd=(Etudiant*)malloc(taille*sizeof(Etudiant));
        for(i=0;i<taille;i++) {
            printf("ENTRER LES INFORMATION DE L'ETUDIANT %d \n",i+1);
            printf("Veuillez entrez le nom complet de l'etudiant :");
            fflush(stdin);
            gets(Letd[i].nomprenom);
            printf("Veuillez entrez le cne  :");
            scanf("%ld",&Letd[i].cne);
            printf("Veuillez entrez la date de naissance de l'etudiant : \n");
            printf("Le jour :");
            fflush(stdin);
            scanf("%d",&Letd[i].birth.jour);
            printf("Le mois :");
             fflush(stdin);;
            scanf("%d",&Letd[i].birth.mois);
            printf("L'annee :");
             fflush(stdin);
            scanf("%d",&Letd[i].birth.annee);
            printf("Veuillez entrez l'adresse de l'etudiant : \n");
            printf("Le numero :");
             fflush(stdin);
            scanf("%d",&Letd[i].address.num);
            printf("La ville :");
            fflush(stdin);           //la fonction ffluch c pour LIBERER LESPACE
            gets(Letd[i].address.ville);
            }
            return Letd;
}

//*********la deuxieme fonction*******
           void  Afficher(Etudiant *Letd , int taille){
           int i ;
           for(i=0;i<taille;i++){
           printf("NOM:%s\tCNE:%ld \n DATE DE NAISSANCE: %d/%d/%d\t ADRESSE: %d %s \n",Letd[i].nomprenom,Letd[i].cne,Letd[i].birth.jour,Letd[i].birth.mois,Letd[i].birth.annee,Letd[i].address.num,Letd[i].address.ville);
}
}
int menu(){
    int choix;
    do{
    printf("veuillez entrer un choix : \n");
            printf("(POUR AFFICHER LA LISTE DES ETUDIANTS TAPER  1 \n");
            printf("POUR TRIER LA LISTE DES ETUDIANTS TAPER  2 \n");
             printf("POUR EFFECTUER UN RECHERCHE PAR DICHOTOMIE TAPER 3 \n");
            printf("POUR CHERCHER UN ETUDIANT PAR SON CNE TAPER  4 \n");
             printf("POUR CHERCHER UN ETUDIANT PAR SON NOM TAPER  5 \n");
              printf("POUR SUPPRIMER UN ETUDIANT PAR SON NOM TAPER  6 \n");
            printf("POUR QUITTER LE PROGRAMME TAPER 0 \n");
            scanf("%d",&choix);
            if( choix<0 || choix >6)
                printf("§§§§ CHOIX INVALIDE §§§§");
        }while( choix<0 || choix >6);
        return choix;

}
//*******FONCTION ECHANGE*******
void echange_Etd(int i, int j, Etudiant * Letd){
	Etudiant tmp;
	tmp= *(Letd+i);
	*(Letd+i)=*(Letd+j);
	*(Letd+j)=tmp;
}

//*****tri par selection*********
void Tri (Etudiant *Letd, int taille) {
	int i, j, imin ; /* i min est lindice de plus petit element */

	for (i = 0 ; i < taille-1 ; i++) {
		imin = i ;
		for ( j = i+1 ; j < taille ; j++ ){
			if ( strcmp(Letd[j].nomprenom , Letd[imin].nomprenom) < 0 )
			imin = j ;
		}
		if (imin != i)  {  /* pour effectuer lechange*/
			echange_Etd(i, imin, Letd);
		} //fin de if
	} // fin de for
}

//******recherche dichotomique*******//
/* Recherche dichotomique dans un tableau tri�  */
Etudiant * ChercherDich(Etudiant *Letd, int taille) {
	char aChercher[21] ;
	int  mini, maxi, milieu, trouve ;
	int  compare, longueur ;

	printf("\n\n>>>>>>>     RECHERCHE DICHOTOMIQUE     <<<<<<<<<\n");

	printf("\n\n>>>>>>>     Entrez le nom de l'etudiant recherche  >>\t");
	fflush(stdin);
	gets(aChercher); /* get string = lire une cha�ne */

	longueur = strlen(aChercher) ;

	mini = 0           ;
	maxi = taille - 1 ;
	trouve = 0 ; /* on ne trouve pas encore */
	while (!trouve && mini <= maxi) {
		milieu = (mini + maxi) / 2 ;
		compare = strnicmp(aChercher, Letd[milieu].nomprenom, longueur);
		if ( compare < 0 )
			maxi = milieu - 1 ;
		else  if (compare > 0)
			mini = milieu + 1 ;
		else trouve = 1 ;
	}
	if (!trouve)
		printf("Desole, on ne trouve pas %s\n", aChercher);

	else {
		return (Letd+milieu);
	}
}

//__Affiche par CNE______
void AfficheParCNE(Etudiant *Letd, int netd, int taille){
	int i=0,k=-1;
	for(i=0;i<taille;i++){
		if(Letd[i].cne==netd){
			k=i;
			break;
		}
	}
	if(k!=-1){
		printf("\n\n\tNom\t:%s",Letd[k].nomprenom);
			printf("\n\tCNE\t:%d",Letd[k].cne);
			printf("\n\tdate\t%d/%d/%d:",Letd[i].birth.jour,Letd[i].birth.mois,Letd[i].birth.annee);
			printf("\n\tAdresse -> num : %d,\tVille : %s",Letd[i].address.num,Letd[i].address.ville);
	}else
		printf("\n\n\n\n____L'etudiant %s n existe pas dans la liste");


}

//__Affiche par Nom______
void AfficheParNom(Etudiant *Letd, char nomATrouver, int taille ){
	int i=0;
	while(strcmp(Letd[i].nomprenom,nomATrouver)!=0) i++;
	if(i>taille) printf("\n\n\n\n____L'etudiant %s n existe pas dans la liste");
	else{
            printf("\n\n\tNom\t:%s",Letd[i].nomprenom);
			printf("\n\tCNE\t:%d",Letd[i].cne);
			printf("\n\tdate\t%d/%d/%d:",Letd[i].birth.jour,Letd[i].birth.mois,Letd[i].birth.annee);
			printf("\n\tAdresse -> num : %d,\tVille : %s",Letd[i].address.num,Letd[i].address.ville);

	}
}
//fonction de supression
void SupprimerEtdParCNE(Etudiant *Letd, int cne, int *taille){
	int  i=0,j;

	while(Letd[i].cne!=cne) i++;
	for(j=i; j<*taille-1; j++){
		Letd[j]=Letd[j+1];
	}
	(*taille)--;
	Afficher(Letd,*taille);
}

    int main()
{
    int nbEtd, choix, cne;
	char nomCherche[20], c;
	printf("\n-Entrez la taille de la liste des etdudiants : \t" ) ;
	scanf( "%d" , &nbEtd) ;
	Etudiant *ListeEtd, *pRech;
	ListeEtd = saisie(nbEtd);
	do{
		choix=menu();
		switch(choix) {
			//case 1 :saisie(nbEtd); break;

			case 1 :Afficher(ListeEtd, nbEtd); break;

			case 2 :Tri(ListeEtd, nbEtd);Afficher(ListeEtd, nbEtd); break;

			case 3 :
				do{
					pRech = ChercherDich(ListeEtd, nbEtd);
					printf(">>>> Voici ses informations :\n\n");
					printf("\n\n\tNom\t:%s",pRech->nomprenom);
					printf("\n\tCNE\t:%d",pRech->cne);
					printf("\n\tdate\t%d/%d/%d:",pRech->birth.jour,pRech->birth.mois,pRech->birth.annee);
					printf("\n\tAdresse -> num : %d,\tVille : %s",pRech->address.num, pRech->address.ville);
					printf("\n\n>>>> Recherche d'un autre etudiant o/n:\n\n");
				}while ( c=getchar()== 'o'); break;


			case 4 : printf("ENTRER LE CNE DE LETUDIANT QUE VOUS VOULEZ AFFICHER ?\t");
				scanf("%d",&cne);
				AfficheParCNE(ListeEtd,cne, nbEtd);
				break;

				break;

			case 5 : printf("ENTRER LE NOM DE LETUDIANT QUE VOUS VOULEZ AFFICHER ?\t");
				scanf("%s",nomCherche);
				AfficheParNom(ListeEtd, nomCherche, nbEtd);
			case 6 : printf("ENTRER LE CNE DE LETUDIANT QUE VOUS VOULEZ SUPPRIMER ?\t");
				scanf("%d",&cne);
				SupprimerEtdParCNE(ListeEtd,cne, &nbEtd);
				break;
		}
	}while(choix!=0);

	printf("\n\n\n\n>>>>>>>>>  Merci pour la visite <<<<<<<<<<<<");
	free(ListeEtd);
	ListeEtd=0;
	getch();
            return 0;
}
