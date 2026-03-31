#include<stdio.h>
#include<string.h>
#include<stdlib.h>
double balance=10000.00;
struct send{
    char account_no[20];
    char reference_no[20];
    double amount;
    char pin[20];
}s;
void sendmoney()                                                     //sendMoney option.
{
    FILE *file;
    file=fopen("money.txt","a");
    if(file==NULL)
    {
        printf("File doesn't exist\n");
        exit(1);
    }
    printf("Enter Receiver bKash Account No: \n");
    scanf("%s",s.account_no);
    system("cls");
    int length=strlen(s.account_no);
    if(length==11)
    {
        fprintf(file,"Send Money.\nTo: %s\n",s.account_no);
        printf("Enter Amount: \n");
        scanf("%lf",&s.amount);
        system("cls");
        fprintf(file,"Amount: Tk %.2lf\n",s.amount);
        printf("Enter Reference: \n");
        scanf("%s",s.reference_no);
        system("cls");
        fprintf(file,"Reference: %s\n",s.reference_no);
        printf("Enter Menu PIN to confirm: ");
        scanf("%s",s.pin);
        system("cls");
        balance=balance-s.amount;
        if(strcmp(s.pin,"12345")==0)
        {
            if(balance>=0)
             {
               printf("\n\nSend Money TK %.2lf to %s successful. \nRef %s.\nBalance TK %.2lf. \nTrxID %s\n",s.amount,s.account_no,s.reference_no,balance,s.reference_no+1);
             }
            else
            printf("\n\nInsufficient funds\n");
        }
        else
            {
              printf("\n\nIncorrect PIN!\n");
            }
    }
    else
    {
        printf("Invalid Phone Number\n");
    }

    fclose(file);
}
struct sendnonbkash{
    char account_no[20];
    char reference_no[20];
    double amount;
    char pin[20];
}s1;
void sendmoney_nonbKash()                                               //sendMoney to non-bKash user.
{
    FILE *file;
    file=fopen("sendnon.txt","w");
    if(file==NULL)
    {
        printf("File doesn't exist\n");
        exit(1);
    }
    printf("Enter Receiver bKash Account No: \n");
    scanf("%s",s1.account_no);
    system("cls");
    int length=strlen(s1.account_no);
    if(length==11)
    {
        fprintf(file,"Send Money.\nTo: %s\n",s1.account_no);
        printf("Enter Amount: \n");
        scanf("%lf",&s1.amount);
        system("cls");
        fprintf(file,"Amount: Tk %.2lf\n",s1.amount);
        printf("Enter Reference: \n");
        scanf("%s",s1.reference_no);
        system("cls");
        fprintf(file,"Reference: %s\n",s1.reference_no);
        printf("Enter Menu PIN to confirm: ");
        scanf("%s",s1.pin);
        system("cls");
        balance=balance-s1.amount;
        if(strcmp(s1.pin,"12345")==0)
        {
            if(balance>=0)
            {
               printf("\n\nSend Money TK %.2lf to %s successful. \nRef %s.\nBalance TK %.2lf. \nTrxID %s\n",s1.amount,s1.account_no,s1.reference_no,balance,s1.reference_no+1);
            }
            else
            printf("\n\nInsufficient funds\n");
        }
        else
            {
              printf("\n\nIncorrect PIN!\n");
            }
    }
    else
    {
        printf("Invalid Phone Number\n");
    }
    fclose(file);
}
void mobile_recharge()                                                  //Mobile recharge option.
{
    printf("\nbKash\n1 Robi\n2 Airtel\n3 Banglalink\n4 Grameenphone\n5 Teletalk\n6 Get instant cashback on bKash recharge\n0 Main Menu\n");
    char account_no[20];
    double amount;
    char pin[20];
    FILE *file;
    file=fopen("mobileRecharge.txt","w");
    if(file==NULL)
    {
        printf("File doesn't exist\n");
        exit(1);
    }
    int n;
    scanf("%d",&n);
    system("cls");
    for(int i=1;i<=5;i++)
    {
        if(i==n)
        {
            printf("\n1 Prepaid\n2 Postpaid\n3 Auto-Recharge\n4 Best Offers\n5 Internet packs\n6 Voice packs\n7 Bundle packs\n0 Main Menu\n");
            int m;
            scanf("%d",&m);
            system("cls");
            if(m==1 || m==2)
            {
              printf("\nEnter Mobile No: \n");
              scanf("%s",account_no);
              system("cls");
              int length=strlen(account_no);
              if(length==11)
              {
                fprintf(file,"Mobile Recharge\nTo: %s\n",account_no);
                printf("Enter Recharge Amount: \n");
                scanf("%lf",&amount);
                system("cls");
                fprintf(file,"Amount: Tk %.2lf\n",amount);
                printf("Enter Menu PIN to confirm: \n");
                scanf("%s",pin);
                system("cls");
                if(strcmp(pin,"12345")==0)
                {
                    printf("\nYou have successfully recharged\n");
                }
                else
                {
                    printf("\n\nIncorrect PIN!\n");
                }
              }
            else
             {
                printf("Invalid Phone Number\n");
             }
            }
            else if(m==3)
             {
                 char pin[20];
                 printf("\n1 Activate Auto-Recharge\n2 Change Auto-Recharge Amount\n3 Deactivate Auto-Recharge\n0 Main Menu\n");
                 int k;
                 scanf("%d",&k);
                 system("cls");
                 if(k==1)
                    {
                        printf("\nSet Auto-Recharge amount\n1 20 TK\n2 50 TK\n3 100 TK\n4 Enter other Amount\n0 Main Menu\n");
                        int b;
                        scanf("%d",&b);
                        system("cls");
                        if(b==1 || b==2 || b==3)
                        {
                            printf("Confirm with bkash PIN:");
                            scanf("%s",pin);
                            system("cls");
                            if(strcmp(pin,"12345")==0)
                                printf("\n\nActivate Auto-Recharge is Successful\n");
                            else
                                printf("\n\nInvalid PIN\n");
                        }
                        if(b==4)
                        {
                            printf("\nEnter any amount:");
                            scanf("%lf",&amount);
                            system("cls");
                            if(strcmp(pin,"12345")==0)
                                printf("\n\nActivate Auto-Recharge is Successful\n");
                            else
                                printf("\n\nInvalid PIN\n");
                        }
                        if(b==0)
                            menu();

                    }
                if(k==2)
                {
                    printf("\nSet New Auto-Recharge amount\n1 20 TK\n2 50 TK\n3 100 TK\n4 Enter other Amount\n0 Main Menu\n");
                        int b;
                        scanf("%d",&b);
                        system("cls");
                        if(b==1 || b==2 || b==3)
                        {
                            printf("Confirm with bkash PIN:");
                            scanf("%s",pin);
                            system("cls");
                            if(strcmp(pin,"12345")==0)
                                printf("\n\nActivate Auto-Recharge is Successful\n");
                            else
                                printf("\n\nInvalid PIN\n");
                        }
                        if(b==4)
                        {
                            printf("\nEnter any amount:");
                            scanf("%lf",&amount);
                            system("cls");
                            if(strcmp(pin,"12345")==0)
                                printf("\n\nActivate Auto-Recharge is Successful\n");
                            else
                                printf("\n\nInvalid PIN\n");
                        }
                        if(b==0)
                            menu();

                }
                if(k==3)
                {
                    printf("Are you sure you want to deactivate Auto-Recharge?\nConfirm with bkash PIN:");
                    scanf("%s",pin);
                    system("cls");
                    if(strcmp(pin,"12345")==0)
                        printf("\n\nDeactivate Auto-Recharge is Successful\n");
                    else
                        printf("\n\nInvalid PIN\n");
                }
                if(k==0)
                    menu();


             }
             else if(m==4)
             {
                 char number[20],pin[20];
                 printf("\n1 200mins-15DDays-159TK\n2 26GB-7Days-208TK\n3 10GB+150mins-7Days-219TK\n0 Main Menu\n");
                 int a;
                 scanf("%d",&a);
                 system("cls");
                 if(a==1 || a==2 ||a==3)
                 {
                     printf("\nEnter number:");
                     scanf("%s",number);
                     system("cls");
                     int len=strlen(number);
                     if(len==11)
                    {
                        printf("\nEnter bkash PIN:");
                       scanf("%s",pin);
                       system("cls");
                         if(strcmp(pin,"12345")==0)
                          printf("\nRecharge Successful\n");
                        else
                         printf("\nInvalid PIN\n");
                    }
                    else
                        printf("\nInvalid number\n");
                 }
                 if(a==0)
                    menu();
             }
             else if(m==5)
             {
                 char number[20],pin[20];
                 printf("\n1 1GB-3Days-46TK\n2 14GB-3Days-114TK\n3 20GB-7Days-194TK\n4 45GB-30Days-598TK\n0 Main Menu\n");
                 int a;
                 scanf("%d",&a);
                 system("cls");
                 if(a==1 || a==2 ||a==3 || a==4)
                 {
                     printf("\nEnter number:");
                     scanf("%s",number);
                     system("cls");
                     int len=strlen(number);
                     if(len==11)
                    {
                        printf("\nEnter bkash PIN:");
                       scanf("%s",pin);
                       system("cls");
                         if(strcmp(pin,"12345")==0)
                          printf("\nRecharge Successful\n");
                        else
                         printf("\nInvalid PIN\n");
                    }
                    else
                        printf("\nInvalid number\n");
                 }
                 if(a==0)
                    menu();
             }
             else if(m==6)
             {
                 char number[20],pin[20];
                 printf("\n1 45Mins-2Days-29TK\n2 180Mins-7Days-108TK\n3 210Mins-30Days-169TK\n0 Main Menu\n");
                 int a;
                 scanf("%d",&a);
                 system("cls");
                 if(a==1 || a==2 ||a==3)
                 {
                     printf("\nEnter number:");
                     scanf("%s",number);
                     system("cls");
                     int len=strlen(number);
                     if(len==11)
                    {
                        printf("\nEnter bkash PIN:");
                        scanf("%s",pin);
                        system("cls");
                         if(strcmp(pin,"12345")==0)
                          printf("\nRecharge Successful\n");
                        else
                         printf("\nInvalid PIN\n");
                    }
                    else
                        printf("\nInvalid number\n");
                 }
                 if(a==0)
                    menu();
             }
             else if(m==7)
             {
                 char number[20],pin[20];
                 printf("\n1 50min+5GB-3Days-107TK\n2 35GB+800min-30Days-799TK\n3 50GB+1000min-30Days-899TK\n0 Main Menu\n");
                 int a;
                 scanf("%d",&a);
                 system("cls");
                 if(a==1 || a==2 ||a==3)
                 {
                     printf("\nEnter number:");
                     scanf("%s",number);
                     system("cls");
                     int len=strlen(number);
                     if(len==11)
                    {
                        printf("\nEnter bkash PIN:");
                        scanf("%s",pin);
                        system("cls");
                         if(strcmp(pin,"12345")==0)
                          printf("\nRecharge Successful\n");
                        else
                         printf("\nInvalid PIN\n");
                    }
                    else
                        printf("\nInvalid number\n");
                 }
                 if(a==0)
                    menu();
             }
             if(m==0)
                menu();

           }
        }

    if(n==6)
        printf("\n\nRecharge from bKash and get instant cashback on selected packs!\n");
    if(n==0)
        menu();
    fclose(file);
}
void payment()                                                      //payment option.
{
    char account_no[20];
    double amount;
    char reference_no[20];
    char pin[20];
    FILE *file;
    file=fopen("paymentMerz.txt","w");
    if(file==NULL)
    {
        printf("File doesn't exist\n");
        exit(1);
    }
    printf("\nEnter Merchant bKash Account No: \n");
    scanf("%s",account_no);
    system("cls");
    int length=strlen(account_no);
    if(length==11)
    {
        fprintf(file,"Payment.\nTo: %s\n",account_no);
        printf("Enter Amount: \n");
        scanf("%lf",&amount);
        system("cls");
        fprintf(file,"Amount: Tk %.2lf\n",amount);
        printf("Enter Reference: \n");
        scanf("%s",reference_no);
        system("cls");
        fprintf(file,"Reference: %s\n",reference_no);
        printf("Enter Menu PIN to confirm: \n");
        scanf("%s",pin);
        system("cls");
        balance=balance-amount;
        if(strcmp(pin,"12345")==0)
        {
            if(balance>=0)
               printf("\n\nMoney has been paid successfully\n");
            else
                printf("\n\nInsufficient funds\n");
        }
        else
        {
            printf("\n\nIncorrect PIN!\n");
        }
    }
    else
    {
        printf("Invalid Phone Number\n");
    }
    fclose(file);
}
void cashout()                                                           //cash out option.
{
    char account_no[20];
    double amount;
    char pin[20];
    FILE *file;
    file=fopen("money.txt","a");
    if(file==NULL)
    {
        printf("File doesn't exist\n");
        exit(1);
    }
    printf("\nEnter Agent bKash Account No: \n");
    scanf("%s",account_no);
    system("cls");
    int length=strlen(account_no);
    if(length==11)
    {
        fprintf(file,"\nCash Out\nTo: %s\n",account_no);
        printf("Enter Amount: \n");
        scanf("%lf",&amount);
        system("cls");
        fprintf(file,"Amount: Tk %.2lf\n",amount);
        printf("Enter Menu PIN to confirm: \n");
        scanf("%s",pin);
        system("cls");
        balance=balance-amount;
        if(strcmp(pin,"12345")==0)
        {
            if(balance>=0)
            printf("\n\nCash out has been successfully done\n");
            else
              printf("\n\nInsufficient funds\n");
        }
        else
        {
            printf("\n\nIncorrect PIN!\n");
        }
    }
    else
    {
        printf("Invalid Phone Number\n");
    }

    fclose(file);
}
void billpay()                                                          //pay bill option
{
    printf("\nPay Bill\n1 Electricity\n2 Gas\n3 Water\n4 Internet and Phone\n5 TV\n6 City Services\n7 Education\n8 Financial Services\n");
    FILE *file;
    file=fopen("billpay.txt","w");
    if(file==NULL)
    {
        printf("\nFile doesn't exist\n");
        exit(1);
    }
    int bill_no;
    scanf("%d",&bill_no);
    system("cls");
    if(bill_no==1)                                                       //Electricity bill
    {
        printf("\nElectricity\n1 Palli Bidyut\n2 DESCO\n3 DPDC\n4 BPDB\n5 Sylhet BPDB\n6 Westzone\n7 NESCO\n");
        int n;
        scanf("%d",&n);
        system("cls");
        for(int i=1;i<=7;i++)
        {
            if(i==n)
            {
                char meter_no[20];
                char contact_no[20];
                char pin[10];
                double amount;

                printf("\nEnter Meter Number:\n");
                scanf("%s",meter_no);
                system("cls");
                fprintf(file,"\nElectricity Bill\nMeter No %s\n",meter_no);
                printf("Enter Contact Number:\n");
                scanf("%s",contact_no);
                system("cls");
                fprintf(file,"Contact no:%s\n",contact_no);
                printf("Enter Amount:\n");
                scanf("%lf",&amount);
                system("cls");
                fprintf(file,"Amount:%.2lf\n",amount);
                printf("Enter menu PIN to confirm:\n");
                scanf("%s",pin);
                system("cls");
                balance=balance-amount;
                if(strcmp(pin,"12345")==0)
                {
                    if(balance>=0)
                     printf("\n\nBill has been paid successfully\n");
                     else
                        printf("\n\nInsufficient funds\n");
                }
                else
                {
                    printf("\n\nIncorrect PIN!\n");
                }
            }
        }
    }
    else if(bill_no==2)                                                 //Gas bill
    {
        printf("\nGas\n1 Jalalabad Gas\n2 Sundarban Gas\n3 Paschimanchal Gas\n4 Karnaphuli Gas\n");
        int n;
        scanf("%d",&n);
        system("cls");
        for(int i=1;i<=4;i++)
        {
            if(i==n)
            {
                char shonket[20];
                char date[10];
                double amount;
                char pin[10];
                printf("\nEnter Grahok Shonket No.\n");
                scanf("%s",shonket);
                system("cls");
                fprintf(file,"\nGas bill\nGrahok Shonket:%s\n",shonket);
                printf("Enter Billing Month and Year(MMYYYY):\n");
                scanf("%s",date);
                system("cls");
                fprintf(file,"Billing Date:%s\n",date);
                printf("Enter Amount:\n");
                scanf("%lf",&amount);
                system("cls");
                fprintf(file,"Amount:%.2lf\n",amount);
                printf("Enter menu PIN to confirm:\n");
                scanf("%s",pin);
                system("cls");
                balance=balance-amount;
                if(strcmp(pin,"12345")==0)
                {
                    if(balance>=0)
                     printf("\n\nBill has been paid successfully\n");
                     else
                        printf("\n\nInsufficient funds\n");
                }
                else
                {
                    printf("\n\nIncorrect PIN!\n");
                }
            }
        }
    }
    else if(bill_no==3)                                                     //Water bill
    {
        printf("\nWater\n1 Dhaka WASA\n2 Chattogram WASA\n3 Rajshahi WASA\n4 Khulna WASA\n");
        int n;
        scanf("%d",&n);
        system("cls");
        for(int i=1;i<=n;i++)
        {
            if(i==n)
            {
                char bill_no[20];
                char date[10];
                double amount;
                char pin[10];
                printf("\nEnter Bill Number:\n");
                scanf("%s",bill_no);
                system("cls");
                fprintf(file,"\nWater\nBill Number:%s\n",bill_no);
                printf("Enter Billing Month and Year(MMYYYY):\n");
                scanf("%s",date);
                system("cls");
                fprintf(file,"Billing Date:%s\n",date);
                printf("Enter Amount:\n");
                scanf("%lf",&amount);
                system("cls");
                fprintf(file,"Amount:%.2lf\n",amount);
                printf("Enter menu PIN to confirm:\n");
                scanf("%s",pin);
                system("cls");
                balance=balance-amount;
                if(strcmp(pin,"12345")==0)
                {
                    if(balance>=0)
                     printf("\n\nBill has been paid successfully\n");
                     else
                        printf("\n\nInsufficient funds\n");
                }
                else
                {
                    printf("\n\nIncorrect PIN!\n");
                }
            }
        }
    }
    else if(bill_no==4)                                         //Internet and Phone bill
    {
        printf("\nInternet and Phone\n1 BTCL\n2 Link3\n3 AmberIT\n4 Carnival\n5 Sam Online\n6 Triangle\n7 KS Network\n8 Dot Internet\n");
        int n;
        scanf("%d",&n);
        system("cls");
        for(int i=1;i<=8;i++)
        {
            if(i==n)
            {
                char code[30];
                char date[10];
                double amount;
                char pin[10];
                printf("\nEnter RYYMM Area code + Phone Number:\n");
                scanf("%s",code);
                system("cls");
                fprintf(file,"\nInternet and Phone\nArea code + Phone number:%s\n",code);
                printf("Enter Billing Month and Year:\n");
                scanf("%s",date);
                system("cls");
                fprintf(file,"Billing Date:%s\n",date);
                printf("Enter Amount:\n");
                scanf("%lf",&amount);
                system("cls");
                fprintf(file,"Amount:%.2lf\n",amount);
                printf("Enter menu PIN to confirm:\n");
                scanf("%s",pin);
                system("cls");
                balance=balance-amount;
                if(strcmp(pin,"12345")==0)
                {
                    if(balance>=0)
                        printf("\n\nBill has been paid successfully\n");
                     else
                        printf("\n\nInsufficient funds\n");
                }
                else
                {
                    printf("\n\nIncorrect PIN!\n");
                }
            }
        }
    }
    else if(bill_no==5)                                                     //TV bill
    {
        printf("\nTV\n1 AKASH DTH\n2 JCCL\n3 Jadoo Digital\n");
        int n;
        scanf("%d",&n);
        system("cls");
        for(int i=1;i<=3;i++)
        {
            if(i==n)
            {
                char id[20];
                char contact_no[20];
                double amount;
                char pin[10];
                printf("\nEnter AKASH DTH Subscriber ID:\n");
                scanf("%s",id);
                system("cls");
                fprintf(file,"\nnTV\nSuscriber ID:%s\n",id);
                printf("Enter contact Number:\n");
                scanf("%s",contact_no);
                system("cls");
                fprintf(file,"Contact No:%s\n",contact_no);
                printf("Enter Amount:\n");
                scanf("%lf",&amount);
                system("cls");
                fprintf(file,"Amount:%.2lf\n",amount);
                printf("Enter menu PIN to confirm:\n");
                scanf("%s",pin);
                system("cls");
                balance=balance-amount;
                if(strcmp(pin,"12345")==0)
                {
                    if(balance>=0)
                       printf("\n\nBill has been paid successfully\n");
                     else
                        printf("\n\nInsufficient funds\n");
                }
                else
                {
                    printf("\n\nIncorrect PIN!\n");
                }
            }
        }
    }
    else if(bill_no==6)                                                      //City services
    {
        printf("\nCity Services\n1 Dhaka South City Corporation\n2 Sylhet City Corporation\n");
        int n;
        scanf("%d",&n);
        system("cls");
        for(int i=1;i<=2;i++)
        {
            if(i==n)
            {
                char ac_no[20];
                char date[10];
                double amount;
                char pin[10];
                printf("\nEnter Customer Bill A/C Number:\n");
                scanf("%s",ac_no);
                system("cls");
                fprintf(file,"\nCity Services\nCustomer Account Number:%s\n",ac_no);
                printf("Enter Billing Month and Year(MMYYYY):\n");
                scanf("%s",date);
                system("cls");
                fprintf(file,"Billing Date:%s\n",date);
                printf("Enter Amount:\n");
                scanf("%lf",&amount);
                system("cls");
                fprintf(file,"Amount:%.2lf\n",amount);
                printf("Enter menu PIN to confirm:\n");
                scanf("%s",pin);
                system("cls");
                balance=balance-amount;
                if(strcmp(pin,"12345")==0)
                {
                    if(balance>=0)
                     printf("\n\nBill has been paid successfully\n");
                     else
                        printf("\n\nInsufficient funds\n");
                }
                else
                {
                    printf("\n\nIncorrect PIN!\n");
                }
            }
        }
    }
    else if(bill_no==7)                                                                 //Education Fee
    {
        printf("\nEducation\n1 GPCPSC\n2 RCPSC\n3 MUBC\n4 VNSC\n5 MCPSC\n6 Eduman\n7 KPBSC\n8 Pay2Fee\n9 Uttara University\n");
        int n;
        scanf("%d",&n);
        system("cls");
        for(int i=1;i<=9;i++)
        {
            if(i==n)
            {
                char bill_no[20];
                char date[10];
                double amount;
                char pin[10];
                printf("\nEnter Bill Number:\n");
                scanf("%s",bill_no);
                system("cls");
                fprintf(file,"\nEducation\nBill No:%s\n",bill_no);
                printf("Enter Billing Month and Year(MMYYYY):\n");
                scanf("%s",date);
                system("cls");
                fprintf(file,"Billing Date:%s\n",date);
                printf("Enter Amount:\n");
                scanf("%lf",&amount);
                system("cls");
                fprintf(file,"Amount:%.2lf\n",amount);
                printf("Enter menu PIN to confirm:\n");
                scanf("%s",pin);
                system("cls");
                balance=balance-amount;
                if(strcmp(pin,"12345")==0)
                {
                    if(balance>=0)
                      printf("\n\nBill has been paid successfully\n");
                     else
                        printf("\n\nInsufficient funds\n");
                }
                else
                {
                    printf("\n\nIncorrect PIN!\n");
                }
            }
        }
    }
    else if(bill_no==8)                                                         //Financial Services
    {
        printf("\nFinancial Services\n1 IPDC Finance\n2 MetLife\n3 Prime Islami Life\n4 Pragati Life\n5 Guardian Life\n6 Delta Life\n7 Chartered Life\n8 Alpha Islami Life\n");
        int n;
        scanf("%d",&n);
        system("cls");
        for(int i=1;i<=8;i++)
        {
            if(i==n)
            {
                char bill_no[20];
                char date[10];
                double amount;
                char pin[10];
                printf("\nEnter Account Number:\n");
                scanf("%s",bill_no);
                system("cls");
                fprintf(file,"\nFinancial Services\nAccount Number:%s\n",bill_no);
                printf("Enter Billing Month and Year(MMYYYY):\n");
                scanf("%s",date);
                system("cls");
                fprintf(file,"Billing Date:%s\n",date);
                printf("Enter Amount:\n");
                scanf("%lf",&amount);
                system("cls");
                fprintf(file,"Amount:%.2lf\n",amount);
                printf("Enter menu PIN to confirm:\n");
                scanf("%s",pin);
                system("cls");
                balance=balance-amount;
                if(strcmp(pin,"12345")==0)
                {
                    if(balance>=0)
                      printf("\n\nBill has been paid successfully\n");
                     else
                        printf("\n\nInsufficient funds\n");
                }
                else
                {
                    printf("\n\nIncorrect PIN!\n");
                }
            }
        }
    }
    fclose(file);
}
void microfinance()                                                                         //Microfinance
{
    printf("\nMicrofinance\n1. BRAC\n2. UDDIPAN\n3. SHAKTI\n4. Manage Saved Accounts\n");

}
void download()                                                                                //Download bKash App
{
    printf("\nGet the bKash App from Play Store.\n\n");
}
void my_bKash(double *balance)                                                                         //my bKash
{
    printf("\nbKash\n1 Check Balance\n2 Request Statement\n3 Change PIN\n4 Priyo Numbers\n5 Save Bill\n6 Update MNP\n7 Confirm iPhone Login\n8 iPhone PIN Reset\n9 Helpline\n");
    int n;
    scanf("%d",&n);
    system("cls");
    if(n==1)                                                                                    //Check Balance
    {
        char pin[10];
        FILE *file;
        file=fopen("Check_Balance.txt","w");
        if(file==NULL)
        {
            printf("File doesn't exist!\n");
            exit(1);
        }
        printf("Enter menu PIN:\n");
        scanf("%s",pin);
        system("cls");
        if(strcmp(pin,"12345")==0)
        {
            printf("\nYour Current Balance is %.2lf\n",*balance);
            fprintf(file,"Your Current Balance is %.2lf\n",*balance);
        }
        else
        {
            printf("\nIncorrect PIN!\n");
        }
        fclose(file);
    }
    else if(n==2)                                                                          //Request Statement
    {
        char pin[10];
        char store[100];
        FILE *file;
        file=fopen("money.txt","r");
        if(file==NULL)
        {
            printf("File doesn't exist!\n");
            exit(1);
        }
        printf("Enter menu PIN to confirm:\n");
        scanf("%s",pin);
        system("cls");
        if(strcmp(pin,"12345")==0)
        {
          while(!feof(file))
          {
            fgets(store,99,file);
            printf("\n%s",store);
          }
        }
        else
        {
            printf("\nIncorrect PIN!\n");
        }
        fclose(file);
    }
    else if(n==3)                                                                       //Change PIN
    {
        char pin_old[10];
        char pin_new[10];
        printf("\nEnter Old PIN:\n");
        scanf("%s",pin_old);
        system("cls");
        if(strcmp(pin_old,"12345")==0)
        {
            printf("Enter a 5 digit New PIN:\n");
            scanf("%s",pin_new);
            system("cls");
            int length=strlen(pin_new);
            if(length==5)
            {
                printf("\nPIN has been successfully changed.\n");
            }
            else
            {
                printf("\nPlease Enter a 5 digit PIN!\n");
            }
        }
        else
        {
            printf("\nIncorrect PIN\n");
        }
    }
    else if(n==7)                                                                                       //iPhone log in
    {
        printf("\nEnter PIN only if you want to log in to bKash App from your iPhone.\nIf you are asked to do this by someone,DO NOT proceed\n");
    }
    else if(n==9)                                                                                        //Helpline
    {
        printf("\nCall 16247 or visit www.bkash.com for more info.\n");
    }
}
void reset_pin()                                                                                            //Reset PIN
{
    char num[20];
    char year[5];
    char pin[10];
    printf("\nEnter your bKash registered NID/Passport/Driving License Number:\n");
    scanf("%s",num);
    system("cls");
    printf("Enter 4 digit of your birth year:\n");
    scanf("%s",year);
    system("cls");
    printf("Enter menu PIN to confirm:\n");
    scanf("%s",pin);
    system("cls");
    if(strcmp(pin,"12345")==0)
    {
        printf("\n\nPIN has been reset successfully\n");
    }
    else
    {
        printf("\n\nIncorrect PIN!\n");
    }
}
void menu()
{
     printf("\nbKash\n1 Send Money\n2 Send Money to Non-bKash User\n3 Mobile Recharge\n4 Payment\n5 Cash Out\n6 Pay Bill\n7 Microfinance\n8 Download App\n9 My bKash\n10 Reset PIN\n");
    int num;
    scanf("%d",&num);
    system("cls");
    switch(num)
    {
    case 1:
        sendmoney();
        break;
    case 2:
        sendmoney_nonbKash();
        break;
    case 3:
        mobile_recharge();
        break;
    case 4:
        payment();
        break;
    case 5:
        cashout();
        break;
    case 6:
        billpay();
        break;
    case 7:
        microfinance();
        break;
    case 8:
        download();
        break;
    case 9:
        my_bKash(&balance);
        break;
    case 10:
        reset_pin();
        break;
    }
}
int main()
{
    printf("Enter bkash code:\n");
    char string1[10]="*247#";
    char string2[10];
    gets(string2);
    int d=strcmp(string1,string2);
    if(d==0)
    {
       menu();
    }
    else
    {
        printf("WRONG CODE");
    }

}


