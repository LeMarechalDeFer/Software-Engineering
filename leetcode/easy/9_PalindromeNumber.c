
//Premiere tentative 10%

//Comparer la moitié supérieur des digits à la moitié inférieur des digits

bool isPalindrome(int x) {
    
    if(x<0){
        return 0;
    }
    else if(x==0)
    {
        return 1;
    }
    else{
        int temp = x;
        int n = 0;
        int i;
    
        while (temp != 0) {
            temp /= 10;
            n++;
        }

        int *entier = (int*)malloc(n*sizeof(int));
        if (!entier) {
            return false; // Échec de l'allocation
        }
        temp = x ;

        for(i=0; i<n; i++){
            entier[i] = temp%10;
            temp /=10;         
        }
        for(i=0; i<n/2; i++)
        {
            if(entier[i]!= entier[n-i-1])
            {
                free(entier);
                return 0;
            }
            
        }
        free(entier);
        return 1 ;

    }
}


//Deuxieme tentative

//Objectif construite rev(iew) de dans le sens inverse afin de voir s'ils sont identiques.


bool isPalindrome(int x) {
    if(x<0){
        return false;
    }
    int num=x;
    double rev=0;
    int last_digit;
    while(x!=0){
        last_digit=x%10;
        rev=rev*10+last_digit;
        x=x/10;
    }
    return num==rev;
}

//Autre solution (A faire) avec pow et strling
