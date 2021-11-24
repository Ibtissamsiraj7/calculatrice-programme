#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void Menu_principal()  //fonction qui affiche le MENU
{

    printf("----------------menu principale---------------\n");
    printf(" 1. introduction d'un compte bancaire\n");
    printf(" 2. introduction de plusieur compte bancaire\n");
    printf(" 3. operations\n");
    printf(" 4. affichage\n");
    printf(" 5. fidelisation\n");
    printf(" 6. quitter l'application\n");

}
int ajouteClient(char CIN[100][10], char nom[100][15], char prenom[100][15],double montant[100],int nbrclient)
{


//        system("cls"); //entrer les infos du compte !
        printf("\n Introduire un compte");
        printf("\n entrer le nom svp : ");
        scanf("%s",nom[nbrclient]);
        printf("\n entrer le prenom svp : ");
        scanf("%s",prenom[nbrclient]);
        printf("\nEntrer vote CIN svp : ");
        scanf("%s",CIN[nbrclient]);
        printf("\nEntrer le montant que vous voulez :");
        scanf("%lf",&montant[nbrclient]);
       

        nbrclient++;
    return nbrclient;
}
    void depot(char CIN[][10], char nom[][15], char prenom[][15],double montant[],int nbrclient)
    {
        char cin[10];
        int i,somme;
        if(nbrclient<=0)
        {
            printf(" il y a pas de client");
        }
        else
        {
            printf(" veuillez enter le CIN du compte");
            scanf("%s", cin);
            for(i=0; i<nbrclient; i++)

                if(strcmp(CIN[i],cin)==0) // strcmp: string compare
                    printf(" veullez enter la somme a deposer");
            scanf("%d",&somme);
            if(somme<=0)
                printf(" operation invalid");
            else
            {
                printf(" montant ajouter avec succes");
                montant[i]= montant[i]+ somme;

            }
        }
    }
    void retrait(char CIN[][10], char nom[][15], char prenom[][15],double montant[],int nbrclient)
    {



        char cin[10];
        int i,somme;
        if(nbrclient<=0)
        {
            printf(" il y a pas de client");
        }
        else
        {
            printf(" veuillez enter le CIN du compte");
            scanf("%s", cin);
            for(i=0; i<nbrclient; i++)

                if(strcmp(CIN[i],cin)==0) // strcmp: string compare
                    printf(" veullez enter la somme a deposer");
            scanf("%d",&somme);
            if(somme<=0)
                printf(" operation invalid");
            else
            {
                printf(" montant ajouter avec succes");
                montant[i]= montant[i]-somme;

            }

        }
    }
    void recherche_cin(char CIN[][10], char nom[][15], char prenom[][15],double montant[],int nbrclient)
    {
        char cin[10];
        int i;
        if(nbrclient<=0)
        {
            printf(" il y a pas de client");
        }
        else
        {
            printf(" veuillez enter le numero CIN");
            scanf("%s", cin);
            for(i=0; i<nbrclient; i++)

                if(strcmp(CIN[i],cin)==0) // strcmp: string compare
                    printf("%s",nom[i]);
                printf("%s",prenom[i]);
                printf("%s",CIN[i]);
                printf("%f",montant[i]);

        }
    }

    void triAscendant(char CIN[][10], char nom[][15], char prenom[][15],double montant[],int nbrclient)
    {
        int i,j,z;
        double tmp;
        for (i=0 ; i < nbrclient-1; i++)
    {
        for (j=0 ; j < nbrclient-i-1; j++)
        {
            if (montant[j] > montant[j+1])
            {
                tmp = montant[j];
                montant[j] = montant[j+1];
                montant[j+1] = tmp;
            }
        }
    }
        for( i=1; i<nbrclient; i++)
                                {               
                                    printf("%s",nom[i]);
                                    printf("%s",prenom[i]);
                                    printf("%s",CIN[i]);
                                    printf("%f",montant[i]);
                                 }
        scanf("%d",&z);

    }
    void triDescendant(char CIN[][10], char nom[][15], char prenom[][15],double montant[],int nbrclient);

   
   
    int main()
    {
        int operation,nbrclient; // nbrclient: nombre de client
        double montant[100];
        char CIN[100][10], nom[100][15],prenom[100][15];
//
// goto
        int i;
        int choix;

        nbrclient=0;
        while(1)
        {
            Menu_principal();
            printf("\n\n Entrer votre choix : ");
            scanf("%d",&choix);
            switch(choix)
            {
            case 1:
                system("cls");
                // 1.introduction d'un seul compte bancaire
                printf("saisir les informations du compte");
                nbrclient = ajouteClient( CIN, nom, prenom, montant,nbrclient);
                printf(" felicitation votre compte est creer\n");

                break;
            case 2:
                system("csl");
                //2. introduction de plusieur compte bancaire

                //l'utilisateur veut creer plusieur comptes
                printf("\n veuilliez entrer un nombre des comptes :");
                scanf("%d",&nbrclient);
                if(nbrclient>0)  //si le nombres des comptes est egal oui inferieur a 1 l'utilisateur dois repeter le choix
                {
                    for(i=0; i<nbrclient; i++)
                    {
                        printf("\n enter votre nom : ");
                        scanf("%s", nom[i]);
                        printf("\n enter votre prenom : ");
                        scanf("%s", prenom[i]);
                        printf("\n entrer votre CIN : ");
                        scanf("%s", CIN[i]);
                        printf("\n Entrer le montant que vous voulez : ");
                        scanf("%lf",&montant[i]);
                    }

                }
                else
                    printf("operation invalid");
                break;
            // operations  1 depot 2 retrait
            case 3:
                system("csl");

                printf("\n\t entrer le type d'operation que vous voulez faire : \n\n");
                printf(" 1. depot \n 2.retrait");
                scanf("%d",&operation);
                switch(operation)
                {
                case 1:
                    depot(CIN, nom, prenom, montant, nbrclient);
                    break;
                case 2:
                    retrait(CIN, nom, prenom, montant, nbrclient);
                    break;
                }
            // affichage
                case 4:
                     // c=choix
                    system("csl");
                    printf("----------------menu  affichage ---------------\n");
                    printf("\t\t1-Par Ordre Ascendant");
                    printf("\n\t\t2-Par Ordre Descendant");
                    printf("\n\t\t3-Par Ordre Ascendant (les comptes bancaire ayant un montant supérieur a un chiffre introduit)");
                    printf("\n\t\t4-Par Ordre Descendant (les comptes bancaire ayant un montant supérieur a un chiffre introduit)");
                    int c;
                    printf("\n\n Entrer votre choix : ");
                    scanf("%d",&c);
                    switch(c){
                    case 1:
                    // ascendant
                        triAscendant(CIN, nom, prenom, montant, nbrclient);
                        break;
                    case 2:
                        break;
                    case 3:
                        break;
                    case 4:
                        break;
                    }
            }
        }

            return 0;

    }