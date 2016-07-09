#include <stdio.h>
#include <stdlib.h>
#define N 100

typedef struct
{
    float a;
    int n;
}NombreScientifique;

void afficher (NombreScientifique *ns)//affichage d'un nb scientifique, la fonction marche
{
    printf("%f*10^%d",ns->a,ns->n);
}

int nb_decimal_places (float inputValue)
{
    int count=0;
	inputValue=inputValue-(int)inputValue;
	while (inputValue >= 0.000000000000000000000000000000000000000000001)
    {
    	    inputValue = inputValue * 10;
    	    count++;
        	inputValue=inputValue-(int)inputValue;
    }
    return count;
}

NombreScientifique *saisir()//saisi un nb scientifique, IMPORTANT: TJS INITIALISER LE PTR CTD UTILISER MALLOC
{
    int exposant;
    float mantisse;
    NombreScientifique *ptr;
    ptr=(NombreScientifique*)malloc(sizeof(NombreScientifique));
    printf("Mantisse=");
    scanf(" %f",&mantisse);
    printf("Exposant=");
    scanf(" %d",&exposant);
    ptr->a=mantisse;
    ptr->n=exposant;
    printf("%d\n",ptr->n);
    printf("%f\n",ptr->a);
    return ptr;
}


NombreScientifique *multiplication(NombreScientifique *n1,NombreScientifique *n2)//multiplie 2 nb scientifiques sous le condition que le produit des mantisses ne depasse pas 10
{
    NombreScientifique *ptrMult;
    ptrMult=(NombreScientifique*)malloc(sizeof(NombreScientifique));
    float mantMult=(n1->a)*(n2->a);
    int exSum=(n1->n)+(n2->n);
    if(mantMult>=1 && mantMult<10)
    {
        ptrMult->a=mantMult;
        ptrMult->n=exSum;
    }
    else
    {
    	 do
    	        {
    		 	 mantMult=mantMult/10;
    		 	 exSum++;
    	        }while((int)mantMult>10);
    	 ptrMult->a=mantMult;
    	 ptrMult->n=exSum;
    }
    return ptrMult;
}//ne marche pas, program firstly crashes

float ns_vers_reel(NombreScientifique *ns)//convertie un nb scientifique en nb reel
{
    int i=0;
    int exposant=ns->n;
    float res=ns->a;
    if(exposant>0)//l'exposant positif
    {
        for(i=0; i<exposant; i++)
        {
            res=res*10;
        }

    }
    else
    {
        for(i=0; i<exposant; i++) //l'exposant negatif
        {
            res=res/10;
        }
    }
    return res;
}

NombreScientifique *reel_vers_ns (float f)
{
    float temp;
    NombreScientifique *ptr;
    ptr=(NombreScientifique*)malloc(sizeof(NombreScientifique));
    if((int)f==0)
    {
        f=f*10;
        ptr->a=f;
        ptr->n=-(nb_decimal_places(f));
    }
    else if(((int)f>=1 && (int)f<=9) || f==10)
    {
        ptr->a=f;
        ptr->n=0;
    }
    else
    {	temp=f;
        do
        {
            f=f/10;
        }
        while((int)f>10);
        ptr->a=f;
        ptr->n=(nb_decimal_places(f))-(nb_decimal_places(temp));

    }
    return ptr;
}

NombreScientifique *addition(NombreScientifique *n1,NombreScientifique *n2)//somme de 2 nb scientifiques
{
    NombreScientifique *ptr;
    ptr=(NombreScientifique*)malloc(sizeof(NombreScientifique));
    float somme;
    somme=ns_vers_reel(n1)+(ns_vers_reel(n2));//les additionne en forme reels
    ptr=reel_vers_ns(somme);//convertit la somme de reel en nombre scientifique
    return ptr;
}

int main()
{
    /*NombreScientifique *ns;
    NombreScientifique *ptr;
    NombreScientifique *n1;
    NombreScientifique *n2;
    NombreScientifique *n;
    NombreScientifique *MultN;*/
    float f;
    int count=0;
    printf("reel=");
    scanf("%f",&f);//saisie d'un nombre reel
    count=nb_decimal_places(f);
    printf("%d",count);
    /*ns=reel_vers_ns(f);//conversion de ce nombre reel en nb scientifique
    afficher(ns);//affichage de nombre scientifique
    ptr=saisir();//saisie d'un nb scientifique
    afficher(ptr);//affichage de ce nb scientifique
    n1=saisir();//saisie de ns 1
    n2=saisir();//saisie de ns 2
    n=addition(n1,n2);//addition de ns1 et ns2
    afficher(n);//affichage de somme de ns1 et ns2
    MultN=multiplication(n1,n2);//multiplication de ns1 et ns2
    afficher(MultN);//affichage de produit de ns1 et ns2*/
    return 0;
}
