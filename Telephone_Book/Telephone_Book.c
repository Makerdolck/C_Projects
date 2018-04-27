#include <stdio.h>
#include <stdlib.h>
#include <string.h>
# define chislo 257
# define numconst 12
int vsekont();
int dobkont(int firstrpr);
int sortirovka();
int ydalenie(int firstpr);
int otvetpol(int ch);
int poisk (int flag);
int schit (char str[], int flag);
int main()
{
    FILE *file=NULL;
    int bye=0, otvet, tot;
    printf ("                                 TELEPHONE BOOK\n\n\n");
    for(;;)
    {
        printf ("\nPodskazka: Dlja vybora togo ili inogo punkta vvedite ego nomer.\n\n");
        printf ("1. Dobavit' kontakt\n");        
        printf ("2. Poisk kontakta \n");
        printf ("3. Pokazat' vse kontakty\n");
        printf ("4. Udalit' kontakt\n");
        printf ("5. Sortirovat' kontakty po imeni\n");
        printf ("6. Vyjti iz programmy\n");
        otvet=9;
        while (otvet==9)
            otvet=otvetpol(0);
        switch (otvet)
        {
            case 1:
                printf ("Podskazka: dlina imeni (i familii) ne dolzhna prevyshat' 256 simvolov, a dlina  telefonnogo nomera ne dolzhna prevyshat' 13 simvolov.\n\n");
                otvet=9;
                while ((otvet==9)||(otvet==1)||(otvet==2))
                    otvet=dobkont(otvet);
                otvet=9;
                break;
            case 2:
                file = fopen ("T_B.txt", "r");
                if (file == NULL)
                {
                    printf ("\nFajl s kontaktami ne byl najden, vozmozhno on povrezhdjon.\n");
                    break;
                }
                printf ("Dlya poiska po imeni vvedite 1, a dlya poiska po familii vvedite 2: ");
                otvet=9;
                while (otvet==9)
                    otvet=otvetpol(2);
                tot=otvet;
                otvet=9;
                while (otvet==9)
                    otvet=poisk(tot);
                otvet=0;
                break;
            case 3:
                vsekont();
                break;
            case 4:
                otvet=8;
                while ((otvet==9)||(otvet==1)||(otvet==2)||(otvet==8))
                    otvet=ydalenie(otvet);
                otvet=0;
                break;
            case 5:
                sortirovka();
                break;
            case 6:
                printf ("\n\n                                    Goodbye!\n\n");
                bye=1;
                break;
            case 8:
                file = fopen ("T_B.txt", "w");
                printf ("                                    %c%c%c%c%c\n", 1, 2, 3, 2, 1);
                break;
            fclose (file);
        }
        if (bye==1)
            break;
    }
    system ("PAUSE");
    return 0;
}
int schit (char str [chislo], int flag)
{
    char c;
    int i=0, prov=0, osh=0, prob=0;
    str [0]='\r';
    while ((c=getchar())!='\n')
    {
        if (i>(chislo-2))
            continue;
        str[i]=c;
        if ((str[i]!=' ')&&(str[i]!='\t'))
            prob=1;
        if ((str[0]==' ')||(str[0]=='\t'))
            i=0;
        else
            i++;
    }
    if (((str[0]=='\r')&&(c=='\n'))||(i>(chislo-2))||(((str[0]==' ')||(str[0]=='\t'))&&(prob==0)))
    {
        osh=1;
        return osh;
    }
    for (;;)
    {
        if ((str[i-1]==' ')||(str[i-1]=='\t'))
            i=i-1;
        else
            break;
    }
    if (flag==0)
    {
        str[i]='0';
        i++;
        str[i]='\0';
    }
    else
        str [i]='\0';
    return osh;
}
int otvetpol(int ch)
{
    char str [chislo]={'\r'}, c;
    int i=0, prov=0, i2=0;
    if (ch==0)
    {
        while ((c=getchar())!='\n')
        {
            if (i>1)
                continue;
            str [i]=c;
            if ((str[i]<'1')||((str[i]>'6')&&(str[i]!='8')))
                prov=1;
            i++;
        }
    }
    if (ch==1)
    {
        while (((c=getchar())!='\n'))
        {
            if (i>1)
                continue;
            str [i]=c;
            if ((str[i]<'1')||(str[i]>'2'))
                prov=1;
            i++;
        }
    }
    if (ch==2)
    {
        while ((c=getchar())!='\n')
        {
            if (i>1)
                continue;
            str [i]=c;
            if ((str[i]<'1')||(str[i]>'2'))
                prov=1;
            i++;
        }
    }
    if ((prov==1)||(i!=1)||((str[0]=='\r')&&(c=='\n')))
    {
        printf ("Vvedeny ne korrektnye dannye, pozhalujsta, povtorite:");
        return 9;
    }
    str[i]='\0';
    prov=atoi(str);
    return prov;
}
int  dobkont (int firstpr)
{
    char name[chislo]={'\r'}, surname[chislo]={'\r'}, namber[chislo]={'\r'}, c, fstr[chislo], prov='\r';
    int i=0, i2=0, inam=0, isur=0, inom=0, nesush=0, nepod=0, flag=0, ciki, fi=0, vyvodli=0, chkont=0;
    FILE *file=fopen ("T_B.txt", "a");
    if (file==NULL)
    {
        printf ("\nFajl s kontaktami ne byl najden, vozmozhno on povrezhdjon.\n");
        return 0;
    }
    fclose (file);
    file=fopen ("T_B.txt", "r");
    if (file==NULL)
    {
        printf ("\nFajl s kontaktami ne byl najden, vozmozhno on povrezhdjon.\n");
        return 0;
    }                                            /*NAME*/
    printf ("Name: ");
    for(;;)
    {
        if ((schit (name, 0))==0)
            break;
        printf ("Vvedeny ne korrektnye dannye, pozhalujsta, povtorite:");
    }
    inam=strlen(name);
    firstpr=1; 
    printf ("Surname: ");                                              /*SURNAME*/
    for(;;)
    {                                       
        if ((schit (surname, 0))==0)
            break;
        printf ("Vvedeny ne korrektnye dannye, pozhalujsta, povtorite:");
    }
    isur=strlen (surname);
    firstpr=2;
    printf ("Namber: ");                                     /*NAMBER*/
    for(;;)
    {
        inom=0;
        prov=0;
        namber[0]='\r';
        while ((c=getchar())!='\n')
        {
            if (inom>numconst)
                continue;
            namber [inom]=c;
            if ((namber[inom]<'0')||(namber[inom]>'9'))
                prov=1;
            if ((inom==0)&&(namber[0]=='+'))
                prov=0;
            inom++;
        }
        if ((prov==1)||(inom>numconst)||((namber[0]=='\r')&&(c=='\n')))
            printf ("Vvedeny ne korrektnye dannye, pozhalujsta, povtorite:");
        else
            break;
    }
    namber[inom]='0';
    inom++;
    namber[inom]='\0';
    for(ciki=-1;;)
    {
        nepod=0;                                                                     /*ИЗ основного файла*/
        fgets (fstr, chislo, file);
        if (feof (file))
        {
            flag=1;
            nesush=1;
            break;
        }
        fi=strlen (fstr)-1;
        fstr[fi]='\0';
        ciki++;
        if(((ciki==0)||((ciki%3)==0))&&(fi==inam))                                            /*проверяем имя*/
        {
            for (fi=0;fi<=inam;fi++)
            {
                if (fstr[fi]!=name[fi])
                {
                    nepod=1;
                    break;
                }
            }
            if (nepod==0)
            {
                fgets (fstr, chislo, file);
                if (feof (file))
                {
                    flag=1;
                    nesush=1;
                    break;
                }
                fi=strlen (fstr)-1;
                fstr[fi]='\0';
                ciki++;
                if (fi==isur)                                                                          /*проверяем фамилию*/
                {
                    for (fi=0;fi<=isur;fi++)
                    {
                        if (fstr[fi]!=surname[fi])
                        {
                            nepod=1;
                            break;
                        }
                    }
                }
                else
                    nepod=1;
                if (nepod==0)
                {
                    fgets (fstr, chislo, file);
                    if (feof (file))
                    {
                        flag=1;
                        nesush=1;
                        break;
                    }
                    fi=strlen (fstr)-1;
                    fstr[fi]='\0';
                    ciki++;
                    if (fi==inom)                                                                               /*проверяем номер*/
                    {
                        for (fi=0;fi<=inom;fi++)
                        {
                            if (fstr[fi]!=namber[fi])
                            {
                                nepod=1;
                                break;
                            }
                        }
                    }
                    else
                        nepod=1;
                    if (nepod==0)
                    {
                        vyvodli=1;
                        break;
                    }
                }
            }
        }
        if (c==EOF)
            break;
        i=0;
    }
    if (vyvodli==0)
    {
        fclose (file);
        file=fopen ("T_B.txt", "a");
        if (file==NULL)
        {
            printf ("\nFajl s kontaktami ne byl najden, vozmozhno on povrezhdjon.\n");
            return 0;
        }
        fprintf (file, "%s\n", name);
        fprintf (file, "%s\n", surname);
        fprintf (file, "%s\n", namber);
        flag=1;
    }
    if (flag==0)
        printf ("\nTakoy kontakt uge sush'estvyet\n");
    else
        printf ("\nKontakt uspeshno sozdan.\n");
    fclose (file);
    return 0;
}
int vsekont()
{
    FILE *file=NULL;
    int i, i2=1, i3=0, fi;
    char str [chislo]={'\r'};
    char c;
    file = fopen ("T_B.txt", "r");
    if (file == NULL)
    {
        printf ("\nFajl s kontaktami ne byl najden, vozmozhno on povrezhdjon.\n");
        return 0;
    }
    else
    {
        c=fgetc (file);
        if (c==EOF)
        {
            printf ("\nSpisok kontaktov pust.\n");
            return 0;
        }
        fseek (file, -1, SEEK_CUR);
        for (i=1;;i++)
        {
            fgets (str, chislo, file);
            if (feof (file))
                break;
            fi=strlen (str)-2;
            str[fi]='\0';
            if (i==3)
                i2++;
            if (i==1)
            {
                printf ("      %d\n%s\n", i2, str);
            }
            else
                printf ("%s\n", str);
            if (i==3)
            {
                i=0;
                printf ("\n");
            }
            i3=0;
        }
    }
    fclose (file);
    return 0;
}
int poisk (int flag)
{
    char str [chislo]={'\r'}, fstr2 [chislo], fstr [chislo], c;
    int i=0, prob=0, fi=0, ciki=0, nepod=0, schkont=0, vyvodli=0, nesush=0;
    FILE *file=NULL;
    file = fopen ("T_B.txt", "r");
    if (file == NULL)
        printf ("\nFajl s kontaktami ne byl najden, vozmozhno on povrezhdjon.\n");
    else
    {
        if (flag==1)
        {
            c=fgetc(file);
            if (c==EOF)
            {
                printf ("\nSpisok kontaktov pust.\n");
                return 0;
            }
            fseek (file, 0, SEEK_SET);
            printf ("Vvedite imja kontakta: ");
            for(;;)
            {
                if ((schit (str, 1))==0)
                    break;
                printf ("Vvedeny ne korrektnye dannye, pozhalujsta, povtorite:");
            }
            i=strlen(str);
            for(ciki=0; ;ciki++)
            {
                nepod=0;
                fgets (fstr, chislo, file);
                if (feof (file))
                    break;
                fi=strlen (fstr)-2;
                fstr[fi]='\0';
                if (schkont==0)
                {
                    if(((ciki==0)||((ciki%3)==0))&&(fi==i))
                    {
                        for (fi=0;fi<=i;fi++)
                        {
                            if (fstr[fi]!=str[fi])
                            {
                                nepod=1;
                                break;
                            }
                        }
                        if (nepod==0)
                        {
                            vyvodli++;
                            printf ("\n      %d\n%s\n", vyvodli, fstr);
                            schkont=1;
                        }
                    }
                }
                else
                {
                    printf ("%s\n", fstr);
                    if (schkont==1)
                        schkont=2;
                    else
                        schkont=0;
                }
                if (c==EOF)
                    break;
                fi=0;
            }
            if ((vyvodli==0)&&(nesush==0))
                printf ("\nKontakta s takim imenem ne sushhestvuet.\n");
        }
        else
        {
            c=fgetc(file);
            if (c==EOF)
            {
                printf ("\nSpisok kontaktov pust.\n");
                return 0;
            }
            fseek (file, 0, SEEK_SET);
            printf ("Vvedite familiy kontakta: ");
            for(;;)
            {
                if ((schit (str, 1))==0)
                    break;
                printf ("Vvedeny ne korrektnye dannye, pozhalujsta, povtorite:");
            }
            i=strlen(str);
            fgets (fstr, chislo, file);
            fi=strlen (fstr)-2;
                fstr[fi]='\0';
            for(ciki=0; ;ciki++)
            {
                nepod=0;
                if ((ciki==0)||((ciki%3)==0))
                {
                    fgets (fstr2, chislo, file);
                    if (feof (file))
                        break;
                    fi=strlen (fstr2)-2;
                    fstr2[fi]='\0';
                }
                else
                {
                    fgets (fstr, chislo, file);
                    if (feof (file))
                        break;
                    fi=strlen (fstr)-2;
                    fstr[fi]='\0';
                }
                if (schkont==0)
                {
                    if(((ciki==0)||((ciki%3)==0))&&(fi==i))
                    {
                        for (fi=0;fi<=i;fi++)
                        {
                            if (fstr2[fi]!=str[fi])
                            {
                                nepod=1;
                                break;
                            }
                        }
                        if (nepod==0)
                        {
                            vyvodli++;
                            printf ("\n      %d\n%s\n", vyvodli, fstr);
                            schkont=1;
                        }
                    }
                }
                else
                {
                    
                    if (schkont==1)
                    {
                        printf ("%s\n", fstr2);
                        printf ("%s\n", fstr);
                        schkont=2;
                    }
                    else
                        schkont=0;
                }
                if (c==EOF)
                    break;
                fi=0;
            }
            if ((vyvodli==0)&&(nesush==0))
                printf ("\nKontakta s takoy familiey ne sushhestvuet.\n");
            
            
        }
    }
    fclose (file);
    return 0;
}
int ydalenie(int firstpr)
{
    char name[chislo]={'\r'}, surname[chislo]={'\r'}, namber[chislo]={'\r'}, c, fstr[chislo], prov='\r';
    int i=0, inam=0, isur=0, inom=0, prob=0, nesush=0, nepod=0, flag=0, ciki, fi=0, vyvodli=0, chkont=0;
    FILE *file=fopen ("T_B.txt", "r");
    if (file==NULL)
    {
        printf ("\nFajl s kontaktami ne byl najden, vozmozhno on povrezhdjon.\n");
        return 0;
    }
    else
    {
        c=fgetc(file);
        if (c==EOF)
        {
            printf ("\nSpisok kontaktov pust.\n");
            return 0;
        }
        fseek (file, 0, SEEK_SET); 
        printf ("Name: ");                                   /*NAME*/
        for(;;) 
        {
            if ((schit (name, 1))==0)
                break;
            printf ("Vvedeny ne korrektnye dannye, pozhalujsta, povtorite:");
        }
        inam=strlen(name);
        firstpr=1; 
        printf ("Surname: ");                                                           /*SURNAME*/
        for(;;)
        {                                       
            if ((schit (surname, 1))==0)
                break;
            printf ("Vvedeny ne korrektnye dannye, pozhalujsta, povtorite:");
        }
        isur=strlen (surname);
        firstpr=2;
        printf ("Namber: ");                                     /*NAMBER*/
        for (;;)
        {
            prov=0;
            namber[0]=='\r';
            inom=0;
            while ((c=getchar())!='\n')
            {
                if (inom>numconst)
                    continue;
                namber [inom]=c;
                if ((namber[inom]<'0')||(namber[inom]>'9'))
                    prov=1;
                if ((inom==0)&&(namber[0]=='+'))
                    prov=0;
                inom++;
            }
            if ((prov==1)||(inom>numconst)||((namber[0]=='\r')&&(c=='\n')))
                printf ("Vvedeny ne korrektnye dannye, pozhalujsta, povtorite:");
            else
                break;
        namber[inom]='\0';
        }                                                     /*Имя, фамилия и номер успешно считаны, поиску подходящего контакта*/
        for(ciki=-1;;)
        {
            nepod=0;                                                                       /*ИЗ основного файла*/
            fgets (fstr, chislo, file);
            if (feof (file))
                break;
            fi=strlen (fstr)-2;
            fstr[fi]='\0';
            ciki++;
            if(((ciki==0)||((ciki%3)==0))&&(fi==inam))                                            /*проверяем имя*/
            {
                for (fi=0;fi<=inam;fi++)
                {
                    if (fstr[fi]!=name[fi])
                    {
                        nepod=1;
                        break;
                    }
                }
                if (nepod==0)
                {
                    fgets (fstr, chislo, file);
                    if (feof (file))
                        break;
                    fi=strlen (fstr)-2;
                    fstr[fi]='\0';
                    ciki++;
                    if (fi==isur)                                                                          /*проверяем фамилию*/
                    {
                        for (fi=0;fi<=isur;fi++)
                        {
                            if (fstr[fi]!=surname[fi])
                            {
                                nepod=1;
                                break;
                            }
                        }
                    }
                    else
                        nepod=1;
                    if (nepod==0)
                    {
                        fgets (fstr, chislo, file);
                        if (feof (file))
                            break;
                        fi=strlen (fstr)-2;
                        fstr[fi]='\0';
                        ciki++;
                        if (fi==inom)                                                                               /*проверяем номер*/
                        {
                            for (fi=0;fi<=inom;fi++)
                            {
                                if (fstr[fi]!=namber[fi])
                                {
                                    nepod=1;
                                    break;
                                }
                            }
                        }
                        else
                            nepod=1;
                        if (nepod==0)
                        {
                            vyvodli=1;
                            break;
                        }
                    }
                }
            }
            if (feof(file))
                break;
        }
        if ((vyvodli==0)&&(nesush!=1))
        {
            printf ("\nKontakt ne sushhestvuet.\n");
            flag=1;
        }
        if (flag==0)
        {
            fclose (file);
            FILE * file = fopen("T_B.txt", "r");
            if (file==NULL)
            {
                printf ("\nFajl s kontaktami ne byl najden, vozmozhno on povrezhdjon.\n");
                return 0;
            }
            else
            {                                                                                          /*манипуляции с контактом, который надо удалить */
                FILE *filec=fopen ("T_Bc.txt", "w");
                if (filec==NULL)
                {
                    printf ("\nFajl s kontaktami ne byl najden, vozmozhno on povrezhdjon.\n");
                    return 0;
                }
                for(i=0;;i++)
                {
                    fgets (fstr, chislo, file);
                    if (feof (file))
                        break;
                    fi=strlen (fstr)-1;
                    fstr[fi]='\0';
                    if ((fi!=0)&&(i!=(ciki-2))&&(i!=(ciki-1))&&(i!=ciki))
                        fprintf (filec, "%s\n", fstr);
                }
                fclose (file);
                fclose (filec);
                file = fopen ("T_B.txt", "w");
                if (file==NULL)
                {
                    printf ("\nFajl s kontaktami ne byl najden, vozmozhno on povrezhdjon.\n");
                    return 0;
                }
                filec = fopen ("T_Bc.txt", "r");
                if (filec==NULL)
                {
                    printf ("\nFajl s kontaktami ne byl najden, vozmozhno on povrezhdjon.\n");
                    return 0;
                }
                for(;;)
                {
                    fgets (fstr, chislo, filec);
                    if (feof (filec))
                        break;
                    fi=strlen (fstr)-1;
                    fstr[fi]='\0';
                    if (fi!=0)
                        fprintf (file, "%s\n", fstr);
                    if (c==EOF)
                        break;
                }
                fclose (filec);
                filec = fopen ("T_Bc.txt", "w");
                if (filec==NULL)
                {
                    printf ("\nFajl s kontaktami ne byl najden, vozmozhno on povrezhdjon.\n");
                    return 0;
                }
                printf ("\nKontakt uspeshno udaljon.\n");
                fclose (filec);
            }
        }
    }
    fclose (file);
    return 0;
}
int sortirovka()
{
    char knamep [chislo], knamenep [chislo], c, t='t';
    int fp=0, fnep=0, ciki, fi, prov, flag=1, i=0, i2=1;
    FILE * file = fopen ("T_B.txt", "r+");
    if (file==NULL)
    {
        printf ("\nFajl s kontaktami ne byl najden, vozmozhno on povrezhdjon.\n");
        return 0;
    }
    FILE * filec = fopen ("T_Bc.txt", "w");
    if (filec==NULL)
    {
        printf ("\nFajl s kontaktami ne byl najden, vozmozhno on povrezhdjon.\n");
        return 0;
    }
    c=fgetc(file);
    if (c==EOF)
    {
        printf ("\nSpisok kontaktov pust.\n");
        return 0;
    }
    fseek (file, 0, SEEK_SET);
    fgets (knamep, chislo, file);
    fp=strlen (knamep)-1;
    knamep[fp]='\0';
    for(;;)
    {
        flag=0;
        fclose (file);
        file = fopen ("T_B.txt", "r+");
        if (file==NULL)
        {
            printf ("\nFajl s kontaktami ne byl najden, vozmozhno on povrezhdjon.\n");
            return 0;
        }
        for (ciki=0;;ciki++)
        {
            fgets (knamep, chislo, file);
            fp=strlen (knamep)-1;
            knamep[fp]='\0';
            if ((knamep[fp-1]=='0')&&((ciki==0)||((ciki%3)==0)))
            {
                flag=1;
                break;
            }
            if (feof(file))
            {
                i=1;
                break;
            }
        }
        for (ciki=1;i==0;ciki++)
        {
            fgets (knamenep, chislo, file);
            if (feof (file))
                break;
            fnep=strlen (knamenep)-1;
            if ((knamenep[fnep-1]=='1')&&((ciki==0)||((ciki%3)==0)))
                continue;
            if ((knamenep[fnep-1]=='0')&&((ciki==0)||((ciki%3)==0)))
                flag=1;
            knamenep [fnep]='\0';
            prov=0;
            if ((ciki==0)||((ciki%3)==0))
            {
                if ((fp<fnep)||(fp==fnep))
                {
                    for (fi=0;fi<fp;fi++)
                    {
                        if (knamep[fi]>knamenep[fi])
                        {
                            for (fi=0;fi<=fnep;fi++)                                           /*меняем подходящий и не подходящий местами*/
                                knamep[fi]=knamenep[fi];
                            prov=-1;
                            break;
                        }
                        if (knamep[fi]<knamenep[fi])
                        {
                            prov=1;
                            break;
                        }
                    }
                }
                if (fp>fnep)
                {
                    for (fi=0;fi<fnep;fi++)
                    {
                        if (knamep[fi]>knamenep[fi])
                        {
                            for (fi=0;fi<=fp;fi++)                                           /*меняем подходящий и не подходящий местами*/
                                knamep[fi]=knamenep[fi];
                            prov=-1;
                            break;
                        }
                        if (knamep[fi]<knamenep[fi])
                        {
                            prov=1;
                            break;
                        }
                    }
                    if (prov==0)
                    {
                        for (fi=0;fi<=fp;fi++)                                           /*меняем подходящий и не подходящий местами*/
                            knamep[fi]=knamenep[fi];
                    }
                }
            }
        }
        fseek (file, 0, SEEK_SET);
        for(;flag==1;)
        {
            prov=0;
            fgets (knamenep, chislo, file);
            if (feof (file))
                break;
            fnep=strlen (knamenep)-1;
            knamenep[fnep]='\0';
            for (ciki=0;ciki<=fnep;ciki++)
            {
                if (knamep[ciki]!=knamenep[ciki])
                {
                    prov=1;
                    break;
                }
            }
            if (prov==0)
            {
                fseek (file, -3, SEEK_CUR);
                fprintf (file, "1\n");
                fseek (file, 0, SEEK_CUR);
                fprintf (filec, "%s\n", knamep);
                for (ciki=0;ciki<=1;ciki++)
                {
                    fgets (knamenep, chislo, file);
                    fnep=strlen (knamenep)-1;
                    knamenep[fnep]='\0';
                    fprintf (filec, "%s\n", knamenep);
                }
                break;
            }
        }
        if (flag==0)
            break;
    }
    fclose (file);
    fclose (filec);
    filec=fopen ("T_Bc.txt", "r");
    if (filec==NULL)
    {
        printf ("\nFajl s kontaktami ne byl najden, vozmozhno on povrezhdjon.\n");
        return 0;
    }
    fp=0;
    for (i=1;;i++)
    {
        fgets (knamenep, chislo, filec);
        if (feof (filec))
            break;
        fp=strlen (knamenep)-2;
        knamenep[fp]='\0';
        if (i==3)
            i2++;
        if (i==1)
            printf ("      %d\n%s\n", i2, knamenep);
        else
            printf ("%s\n", knamenep);
        if (i==3)
        {
            i=0;
            printf ("\n");
        }
        fp=0;
    }
    fclose (filec);
    filec =fopen ("T_Bc.txt", "w");
    if (filec==NULL)
    {
        printf ("\nFajl s kontaktami ne byl najden, vozmozhno on povrezhdjon.\n");
        return 0;
    }
    fclose (filec);
    file = fopen ("T_B.txt", "r+");
    if (file==NULL)
    {
        printf ("\nFajl s kontaktami ne byl najden, vozmozhno on povrezhdjon.\n");
        return 0;
    }
    for (ciki=3; ; ciki++)
    {
        fgets (knamep, chislo, file);
        if (feof (file))
            break;
        fp=strlen (knamep)-1;
        knamep[fp]='\0';
        if ((ciki%3)==0)
        {
            fseek (file, -3, SEEK_CUR);
            fprintf (file, "0\n");
            fseek (file, 0, SEEK_CUR);
        }
    }
    fclose (file);
    return 0;
}
                                                                           /*          DDS - MEN         */
